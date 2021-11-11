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
	input		[7:0]	spritecollisionram_data_in,
	input		[15:0]	palrom_data_out,
	input		[15:0]	spritelbram_data_out,

	output reg 	[6:0]	spriteram_addr,
	output reg 	[6:0]	spritecollisionram_addr,
	output reg	[11:0]	sprom_addr,
	output reg 	[4:0]	palrom_addr,
	output 		[9:0]	spritelbram_rd_addr,
	output reg	[9:0]	spritelbram_wr_addr,

	output reg			spritelbram_wr,
	output reg	[15:0]	spritelbram_data_in,

	output reg			spritecollisionram_wr,

	output		[7:0]	spr_r,
	output		[7:0]	spr_g,
	output		[7:0]	spr_b,
	output				spr_a
);

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

// Sprite line buffer has two slots - read and write.  They alternate when hsync goes high.
reg					spritelb_slot_rd = 1'b0;
reg					spritelb_slot_wr = 1'b1;

// Track last hsync value
reg					hsync_last;

// Sprite state machine control
reg			[3:0]	spr_state;
reg			[3:0]	spr_state_next;
// Sprite index counter and maximum sprite limit
reg			[4:0]	spr_index;
localparam			spr_index_max = 5'd31;
// Sprite maximum sizes
localparam [15:0]	spr_size_x = 16'd15;
localparam [15:0]	spr_size_y = 16'd15;
localparam	[6:0]	spr_ram_item_width = 4;
localparam			spr_line_max = 352;
reg			[15:0]	spr_y;
reg			[15:0]	spr_x;
reg					spr_enable;
reg			[3:0]	spr_image_index;
reg			[15:0]	spr_active_y;
reg			[4:0]	spr_pixel_index;
reg			[10:0]	spr_rom_offset;

//`define CASVAL_DEBUG
`ifdef CASVAL_DEBUG
parameter SPR_TIMER_WIDTH = 11;
reg [SPR_TIMER_WIDTH-1:0] spr_timer_idle;
reg [SPR_TIMER_WIDTH-1:0] spr_linetime_max;
reg [SPR_TIMER_WIDTH-1:0] spr_timer_line;
`endif


always @(posedge clk)
begin

`ifdef CASVAL_DEBUG
	spr_timer_line <= spr_timer_line + 1'b1;
`endif

	hsync_last <= hsync;
	case (spr_state)
		SE_INIT:
		begin
`ifdef CASVAL_DEBUG
			// Reset line timer maximum
			spr_linetime_max <= {{SPR_TIMER_WIDTH-1{1'b0}},1'b1};
`endif
			spr_state <= SE_IDLE;
		end

		SE_IDLE:
		begin
			// Wait for hsync to go high outside of reset
			if(reset == 1'b0 && hsync == 1'b1 && hsync_last == 1'b0)
			begin
				// Rotate line buffer slots
				spritelb_slot_rd <= spritelb_slot_rd + 1'b1;
				spritelb_slot_wr <= spritelb_slot_wr + 1'b1;
				// Calculate active Y line
				spr_active_y <= ({6'b0,vcnt} + spr_size_y) + 16'd1;
`ifdef CASVAL_DEBUG
					$display("CASVAL->LEAVING SE_IDLE: spr_timer_idle = %d, spr_linetime_max=%d", spr_timer_idle, spr_linetime_max);
					spr_timer_line <= {SPR_TIMER_WIDTH{1'b0}};
`endif
				spr_state <= SE_RESET;
			end
`ifdef CASVAL_DEBUG
			else
			begin
				spr_timer_idle <= spr_timer_idle + 1'b1;
			end
`endif
		end

		SE_WAIT:
		begin
			spr_state <= spr_state_next;
		end

		SE_RESET:
		begin
`ifdef CASVAL_DEBUG
				$display("CASVAL->RESET");	
`endif

			// Reset sprite index
			spr_index <= 5'd0;
			
			// Setup line buffer RAM for clear operation
			spritelbram_wr_addr <= {spritelb_slot_wr, 9'b0};
			spritelbram_wr <= 1'b1;
			spritelbram_data_in <= 16'b0;

			spr_state <= SE_CLEAR_BUFFER;
		end

		SE_CLEAR_BUFFER:
		begin
			if(spritelbram_wr_addr[8:0] < spr_line_max[8:0])
			begin
				spritelbram_wr_addr <= spritelbram_wr_addr + 1'b1;
			end
			else
			begin
				// Disable line buffer write
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
`ifdef CASVAL_DEBUG
			$display("CASVAL->SE_READ_Y_UPPER: spr: %d  addr=%x  dout=%x", spr_index, spriteram_addr, spriteram_data_out);
`endif
			// Read enable bit from sprite RAM
			spr_enable <= spriteram_data_out[7];
			// Read Y upper 4 bits from sprite RAM
			spr_y[11:8] <= spriteram_data_out[3:0];
			// Increment sprite RAM address
			spriteram_addr <= spriteram_addr + 1'b1;

			spr_state <= SE_WAIT;
			spr_state_next <= SE_READ_Y_LOWER;
		end
		SE_READ_Y_LOWER:
		begin
`ifdef CASVAL_DEBUG
			$display("CASVAL->SE_READ_Y_LOWER:  spr: %d  addr=%x dout=%x", spr_index, spriteram_addr, spriteram_data_out);
`endif
			// Read Y lower 8 bits from sprite RAM
			spr_y[7:0] <= spriteram_data_out;
			// Increment sprite RAM address
			spriteram_addr <= spriteram_addr + 1'b1;

			spr_state <= SE_CHECK_Y;
		end

		SE_CHECK_Y:
		begin
`ifdef CASVAL_DEBUG
			$display("CASVAL->SE_CHECK_Y: spr_index=%d  y: %d", spr_index, spr_y);
`endif
			//// If this sprite is enabled and current line is within sprite Y area
			if(spr_enable==1'b1 && spr_active_y >= spr_y && spr_active_y <= spr_y + spr_size_y)
			begin
`ifdef CASVAL_DEBUG
				$display("SE_CHECK_Y PASSED: spr_index=%d", spr_index);
`endif
				spr_state <= SE_READ_X_UPPER;
			end
			else
			begin
				// If no then move to next sprite or finish
				if(spr_index == spr_index_max)
				begin
					spr_state <= SE_LINE_COMPLETE;
				end
				else
				begin
					// Increment sprite index
					spr_index <= spr_index + 1'd1;

					spr_state <= SE_SETUP_READ_Y;
				end
			end
		end

		SE_READ_X_UPPER:
		begin
`ifdef CASVAL_DEBUG
			$display("CASVAL->SE_READ_X_UPPER:  addr=%x dout=%x", spriteram_addr, spriteram_data_out);
`endif
			// Read image index 4 bits from sprite RAM
			spr_image_index <= spriteram_data_out[7:4];
			// Read Y upper 4 bits from sprite RAM
			spr_x[11:8] <= spriteram_data_out[3:0];
			// Increment sprite RAM address
			spriteram_addr <= spriteram_addr + 1'b1;

			spr_state <= SE_WAIT;
			spr_state_next <= SE_READ_X_LOWER;
		end
		SE_READ_X_LOWER:
		begin
`ifdef CASVAL_DEBUG
			$display("CASVAL->SE_READ_X_LOWER:  addr=%x dout=%x", spriteram_addr, spriteram_data_out);
`endif
			// Read X lower 8 bits from sprite RAM
			spr_x[7:0] <= spriteram_data_out;
			// Set up offset for sprite ROM read
			spr_rom_offset <= spr_active_y[10:0] - spr_y[10:0];

			spr_state <= SE_SETUP_WRITE;
		end

		SE_SETUP_WRITE:
		begin
`ifdef CASVAL_DEBUG
			$display("CASVAL->SE_SETUP_WRITE: AY: %d   Y: %d   X: %d   I: %d   O: %d", spr_active_y, spr_y, spr_x, spr_image_index, spr_rom_offset);
`endif
			// Enable line buffer write
			spritelbram_wr <= 1'b0;
			// Setup line buffer write address
		 	spritelbram_wr_addr <= {spritelb_slot_wr, spr_x[8:0]};
			// Set sprite rom read address
		 	sprom_addr <= { spr_image_index[3:0], 8'b0} + {spr_rom_offset[6:0], 4'b0};
			// Reset sprite pixel index and count
		 	spr_pixel_index <= 5'b0;

			spr_state <= SE_WAIT;
			spr_state_next <= SE_GET_PIXEL;
		end

		SE_GET_PIXEL:
		begin
			if(spr_pixel_index > spr_size_x[4:0])
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
`ifdef CASVAL_DEBUG
				$display("CASVAL->SE_GET_PIXEL: y: %d, x: %d i: %d, sprom_addr < %x, palrom_addr < %x", spr_y, spr_pixel_index, spr_image_index, sprom_addr, {spriterom_data_out[4:0],1'b0});
`endif
				// Setup palette address to read pixel colour
				palrom_addr <= {spriterom_data_out[3:0],1'b0};
				// Increment sprite ROM address
				sprom_addr <= sprom_addr + 1'b1;
				// Disable line buffer write
				spritelbram_wr <= 1'b0;

				spr_state <= SE_WAIT;
				spr_state_next <= SE_STAGE_PIXEL;
			end
		end

		SE_STAGE_PIXEL:
		begin
			// Get pixel colour from palette rom
			if(palrom_data_out[15])
			begin
				// If palette colour alpha is high, stage input to line buffer
`ifdef CASVAL_DEBUG
				$display("CASVAL->SE_STAGE_PIXEL: y: %d, x: %d i: %d, spritelbram_data_in < %x", spr_y,spr_pixel_index, spr_image_index, palrom_data_out);
`endif
				// Enable line buffer write
				spritelbram_wr <= 1'b1;
				// Fill line buffer data in with palette ROM data out
				spritelbram_data_in <= palrom_data_out;
				
				spr_state <= SE_WRITE_PIXEL;
			end
			else
			begin
				// Pixel is transparent so move to next
`ifdef CASVAL_DEBUG
				$display("CASVAL->SE_STAGE_PIXEL: y: %d, x: %d i: %d, spritelbram_data_in < %x - FAIL ALPHA  CHECK", spr_y,spr_pixel_index, spr_image_index, palrom_data_out);
`endif
				// Increment line buffer write address
				spritelbram_wr_addr <= spritelbram_wr_addr + 1'b1;
				// Increment sprite pixel index
				spr_pixel_index <= spr_pixel_index + 1'b1;

				spr_state <= SE_GET_PIXEL;
			end
		end

		SE_WRITE_PIXEL:
		begin
			// Get pixel colour from palette rom and stage input to line buffer
`ifdef CASVAL_DEBUG
			$display("CASVAL->SE_WRITE_PIXEL: y: %d, x: %d i: %d, spritelbram_wr_addr < %x, spritelbram_data_in=%b", spr_y, spr_pixel_index, spr_image_index, spritelbram_wr_addr, spritelbram_data_in);
`endif
			// Disable line buffer write
			spritelbram_wr <= 1'b0;
			// Increment line buffer write address
			spritelbram_wr_addr <= spritelbram_wr_addr + 1'b1;
			// Increment sprite pixel index
			spr_pixel_index <= spr_pixel_index + 1'b1;

			spr_state <= SE_GET_PIXEL;
		end

		SE_LINE_COMPLETE:
		begin
			// Once all sprites have been processed for each pixel return to idle
`ifdef CASVAL_DEBUG
			$display("CASVAL->SE_LINE_COMPLETE: counter=%d", spr_timer_line);
			// Update slowest line counter
			if(spr_timer_line > spr_linetime_max)
			begin
				spr_linetime_max <= spr_timer_line;
			end
			// Reset idle timer
			spr_timer_idle <= {SPR_TIMER_WIDTH{1'b0}};
`endif
			spr_state <= SE_IDLE;
		end
	endcase
end

assign spritelbram_rd_addr = ({spritelb_slot_rd, (hcnt + 1'b1) + spr_size_x[8:0]}) + 10'd2;
assign spr_r = {spritelbram_data_out[4:0],spritelbram_data_out[4:2]};
assign spr_g = {spritelbram_data_out[9:5],spritelbram_data_out[9:7]};
assign spr_b = {spritelbram_data_out[14:10],spritelbram_data_out[14:12]};
assign spr_a = spritelbram_data_out[15];

endmodule