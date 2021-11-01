`timescale 1ns / 1ps
/*============================================================================
	Aznable (custom 8-bit computer system) - Comet (sprite engine)

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 0.1
	Date: 2021-10-31

	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the Free
	Software Foundation; either version 3 of the License, or (at your option)
	any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program. If not, see <http://www.gnu.org/licenses/>.
===========================================================================*/

module sprite_engine (
	input				clk,
	input				reset,
	input				hsync,
	input		[8:0]	hcnt,
	input		[8:0]	vcnt,
	
	input		[7:0]	spriterom_data_out,
	input		[7:0]	spriteram_data_out,
	input		[15:0]	palrom_data_out,
	input		[15:0]	spritelbram_data_out,

	output reg 	[6:0]	spriteram_addr,
	output reg	[10:0]	sprom_addr,
	output reg 	[4:0]	palrom_addr,
	output 		[9:0]	spritelbram_rd_addr,
	output reg	[9:0]	spritelbram_wr_addr,

	output reg			spritelbram_wr,
	output reg	[15:0]	spritelbram_data_in,

	output		[7:0]	spr_r,
	output		[7:0]	spr_g,
	output		[7:0]	spr_b,
	output				spr_a
);

// Sprite line buffer has two slots - read and write.  They alternate when hsync goes high.
reg spritelb_slot_rd;
reg spritelb_slot_wr = 1'b1;

// State machine constants
localparam SE_INIT = 0;
localparam SE_IDLE = 1;
localparam SE_WAIT = 2;
localparam SE_RESET = 3;
localparam SE_CLEAR_BUFFER = 4;
localparam SE_SETUP_READ_Y = 5;
localparam SE_READ_Y_UPPER = 6;
localparam SE_READ_Y_LOWER = 7;
localparam SE_CHECK_Y = 8;
localparam SE_READ_X_UPPER = 9;
localparam SE_READ_X_LOWER = 10;
localparam SE_SETUP_WRITE = 11;
localparam SE_GET_PIXEL = 12;
localparam SE_STAGE_PIXEL = 13;
localparam SE_WRITE_PIXEL = 14;
localparam SE_LINE_COMPLETE = 15;

reg hsync_last;
reg [3:0] spr_state;
reg [3:0] spr_state_next;
reg [3:0] spr_index;
localparam spr_index_max = 4'd15;
localparam spr_size_x = 16'd15;
localparam spr_size_y = 16'd15;
localparam bit [6:0] spr_ram_item_width = 4;
localparam spr_line_max = 352;
reg [15:0] spr_y;
reg [15:0] spr_x;
reg spr_enable;
reg [3:0] spr_image_index;
reg [15:0] spr_active_y;
reg [4:0] spr_pixel_index;
reg [4:0] spr_pixel_count;
reg [10:0] spr_rom_offset;

reg [16:0] idle_timer;
reg [16:0] spr_linetime_max;
reg [16:0] spr_counter;
reg [16:0] spr_counter2;

always @(posedge clk)
begin

	spr_counter <= spr_counter + 1'b1;
	spr_counter2 <= spr_counter2 + 1'b1;

	hsync_last <= hsync;
	case (spr_state)
		SE_INIT:
		begin
			spr_linetime_max <= 17'd1;
			spr_state <= SE_IDLE;
		end

		SE_IDLE:
		begin
			// Wait for hsync to go high outside of reset
			if(reset == 1'b0 && hsync == 1'b1 && hsync_last == 1'b0)
			begin
				spritelb_slot_rd <= spritelb_slot_rd + 1'b1;
				spritelb_slot_wr <= spritelb_slot_wr + 1'b1;
				spr_active_y <= ({6'b0,vcnt} + spr_size_y) + 16'd1;
				spr_state <= SE_RESET;
				//$display("LEAVING SE_IDLE: idle_timer = %d, spr_linetime_max=%d", idle_timer, spr_linetime_max);
				idle_timer <= 17'b0;
				spr_counter2 <= 17'b0;
			end
			else
			begin
				idle_timer <= idle_timer + 1'b1;
			end
		end
		SE_WAIT:
		begin
			spr_state <= spr_state_next;
		end
		SE_RESET:
		begin
			// Reset sprite index
			spr_index <= 4'd0;
			//$display("STARTING RESET: %d", spr_counter);
			spr_state <= SE_CLEAR_BUFFER;
			spritelbram_wr_addr <= {spritelb_slot_wr, 9'b0};
			spritelbram_wr <= 1'b1;
		end
		SE_CLEAR_BUFFER:
		begin
			if(spritelbram_wr_addr[8:0] < spr_line_max[8:0])
			begin
				spr_pixel_index <= spr_pixel_index + 1'b1;
				spritelbram_wr_addr <= spritelbram_wr_addr + 1'b1;
				spritelbram_data_in <= 16'b0;
			end
			else
			begin
				spritelbram_wr <= 1'b0;
				spr_state <= SE_SETUP_READ_Y;
			end
		end
		SE_SETUP_READ_Y:
		begin
			// Setup address to read Y from sprite RAM
			spriteram_addr <= spr_index * spr_ram_item_width;
			spr_state <= SE_WAIT;
			spr_state_next <= SE_READ_Y_UPPER;
		end
		SE_READ_Y_UPPER:
		begin
			// Read enable bit from sprite RAM
			spr_enable <= spriteram_data_out[7];
			// Read Y upper 4 bits from sprite RAM
			spr_y[11:8] <= spriteram_data_out[3:0];
			//$display("SE_READ_Y_UPPER: spr: %d  addr=%x  dout=%x", spr_index, spriteram_addr, spriteram_data_out);
			spriteram_addr <= spriteram_addr + 1'b1;
			spr_state <= SE_WAIT;
			spr_state_next <= SE_READ_Y_LOWER;
		end
		SE_READ_Y_LOWER:
		begin
			// Read Y lower 8 bits from sprite RAM
			spr_y[7:0] <= spriteram_data_out;
			//$display("SE_READ_Y_LOWER:  spr: %d  addr=%x dout=%x", spr_index, spriteram_addr, spriteram_data_out);
			spriteram_addr <= spriteram_addr + 1'b1;
			spr_state <= SE_CHECK_Y;
		end
		SE_CHECK_Y:
		begin
			//$display("SE_CHECK_Y: spr_index=%d  y: %d", spr_index, spr_y);
			// If this sprite is enabled and current line is within sprite Y area
			if(spr_enable==1'b1 && spr_active_y >= spr_y && spr_active_y <= spr_y + spr_size_y)
			begin
				//$display("SE_CHECK_Y PASSED: spr_index=%d", spr_index);
				spr_state <= SE_READ_X_UPPER;
			end
			else
			begin
				// If no then move to next sprite or finish
				if(spr_index == spr_index_max)
				begin
					//$display("MOVING TO SE_LINE_COMPLETE FROM CHECK_Y: %d", spr_counter);
					spr_state <= SE_LINE_COMPLETE;
				end
				else
				begin
					//$display("MOVING TO NEXT SPRITE FROM CHECK_Y: %d", spr_counter);
					spr_index <= spr_index + 1'd1;
					spr_state <= SE_SETUP_READ_Y;
				end
			end
		end

		SE_READ_X_UPPER:
		begin
			// Read image index 4 bits from sprite RAM
			spr_image_index <= spriteram_data_out[7:4];
			// Read Y upper 4 bits from sprite RAM
			spr_x[11:8] <= spriteram_data_out[3:0];
			//$display("SE_READ_X_UPPER:  addr=%x dout=%x", spriteram_addr, spriteram_data_out);
			spriteram_addr <= spriteram_addr + 1'b1;
			spr_state <= SE_WAIT;
			spr_state_next <= SE_READ_X_LOWER;
		end
		SE_READ_X_LOWER:
		begin
			// Read Y lower 8 bits from sprite RAM
			spr_x[7:0] <= spriteram_data_out;
			//$display("SE_READ_X_LOWER:  addr=%x dout=%x", spriteram_addr, spriteram_data_out);
			spr_state <= SE_SETUP_WRITE;
			// Setup sprom_address
			spr_rom_offset <= spr_active_y[10:0] - spr_y[10:0];
		end

		SE_SETUP_WRITE:
		begin
			//$display("SE_SETUP_WRITE: AY: %d   Y: %d   X: %d   I: %d   O: %d", spr_active_y, spr_y, spr_x, spr_image_index, spr_rom_offset);
			// Begin to write sprite line from ROM to linebuffer
			// - Setup initial address
			spritelbram_wr <= 1'b0;
		 	spritelbram_wr_addr <= {spritelb_slot_wr, spr_x[8:0]};
		 	sprom_addr <= { spr_image_index[2:0], 8'b0} + {spr_rom_offset[6:0], 4'b0};
		 	spr_pixel_index <= 5'b0;
		 	spr_pixel_count <= spr_size_x[4:0];
			spr_state <= SE_WAIT;
			spr_state_next <= SE_GET_PIXEL;
		end
		SE_GET_PIXEL:
		begin
			if(spr_pixel_index > spr_pixel_count)
		 	begin
		 		// Move to next sprite or finish
		 		if(spr_index == spr_index_max)
		 		begin
		 			spr_state <= SE_LINE_COMPLETE;
		 		end
		 		else
		 		begin
		 			spr_index <= spr_index + 1'd1;
		 			spr_state <= SE_SETUP_READ_Y;
		 		end
		 	end
			else
			begin
				spritelbram_wr <= 1'b0;
				// Get pixel colour from Palette read
				//$display("SE_GET_PIXEL: y: %d, x: %d/%d i: %d, sprom_addr < %x, palrom_addr < %x", spr_y, spr_pixel_index, spr_pixel_count, spr_image_index, sprom_addr, {spriterom_data_out[4:0],1'b0});
				palrom_addr <= {spriterom_data_out[3:0],1'b0};
				sprom_addr <= sprom_addr + 1'b1;
				spr_state <= SE_WAIT;
				spr_state_next <= SE_STAGE_PIXEL;
				// spr_state <= SE_STAGE_PIXEL;
			end
		end

		SE_STAGE_PIXEL:
		begin
			// Get pixel colour from palette rom
			if(palrom_data_out[15])
			begin
				//$display("SE_STAGE_PIXEL: y: %d, x: %d/%d i: %d, spritelbram_data_in < %x", spr_y,spr_pixel_index, spr_pixel_count, spr_image_index, palrom_data_out);
				// If palette colour alpha is high, stage input to line buffer
				spritelbram_wr <= 1'b1;
				spritelbram_data_in <= palrom_data_out;
				spr_state <= SE_WRITE_PIXEL;
			end
			else
			begin		
				//$display("SE_STAGE_PIXEL: y: %d, x: %d/%d i: %d, spritelbram_data_in < %x - FAIL ALPHA  CHECK", spr_y,spr_pixel_index, spr_pixel_count, spr_image_index, palrom_data_out);
				// Pixel is transparent so move to next
				spr_state <= SE_GET_PIXEL;
				spritelbram_wr_addr <= spritelbram_wr_addr + 1'b1;
				spr_pixel_index <= spr_pixel_index + 1'b1;
			end
			//$display("pixel: %d/%d index: %d  sprom_addr: %x  spriterom_data_out: %x", spr_pixel_index, spr_pixel_count, spr_image_index, sprom_addr, spriterom_data_out);
		end

		SE_WRITE_PIXEL:
		begin
			// Get pixel colour from palette rom and stage input to line buffer
			//$display("SE_WRITE_PIXEL: y: %d, x: %d/%d i: %d, spritelbram_wr_addr < %x, spritelbram_data_in=%b", spr_y, spr_pixel_index, spr_pixel_count, spr_image_index, spritelbram_wr_addr, spritelbram_data_in);
			spr_pixel_index <= spr_pixel_index + 1'b1;
			spritelbram_wr_addr <= spritelbram_wr_addr + 1'b1;
			spritelbram_wr <= 1'b0;
			spr_state <= SE_GET_PIXEL;
			//$display("pixel: %d/%d index: %d  sprom_addr: %x  spriterom_data_out: %x", spr_pixel_index, spr_pixel_count, spr_image_index, sprom_addr, spriterom_data_out);
		end

		SE_LINE_COMPLETE:
		begin
			//$display("SE_LINE_COMPLETE: counter=%d", spr_counter2);
			if(spr_counter2 > spr_linetime_max)
			begin
				spr_linetime_max <= spr_counter2;
			end
			spr_state <= SE_IDLE;
		end
	endcase

	// if(spritelbram_data_out>16'b0)
	// begin
	// 	$display("%d %d - %x - %b", hcnt, vcnt, spritelbram_rd_addr, spritelbram_data_out);
	// end
end

assign spritelbram_rd_addr = ({spritelb_slot_rd, (hcnt + 1'b1) + spr_size_x[8:0]}) + 10'd2;
assign spr_r = {spritelbram_data_out[4:0],spritelbram_data_out[4:2]};
assign spr_g = {spritelbram_data_out[9:5],spritelbram_data_out[9:7]};
assign spr_b = {spritelbram_data_out[14:10],spritelbram_data_out[14:12]};
assign spr_a = spritelbram_data_out[15];

endmodule