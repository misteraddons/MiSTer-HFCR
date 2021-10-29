`timescale 1ns / 1ps
/*============================================================================
	Aznable (custom 8-bit computer system) - System module

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.0
	Date: 2021-07-03

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

module system (
	input			clk_sys,
	input 			ce_pix,
	input			reset,
	input [16:0]	dn_addr,
	input			dn_wr,
	input [7:0]		dn_data,
	input [7:0]		dn_index,

	// 6 devices, 32 buttons each
	input [191:0]	joystick,

	// 6 devices, 16 bits each - -127..+127, Y: [15:8], X: [7:0]
	input [95:0]	analog_l,

	// 6 devices, 16 bits each - -127..+127, Y: [15:8], X: [7:0]
	input [95:0]	analog_r,
	
	// 6 devices, 8 bits each - paddle 0..255
	input [47:0]	paddle,

	// 6 devices, 16 bits eachspinner [7:0] -128..+127, [8] - toggle with every update, [9-15] padding
	input [95:0]	spinner,

	// ps2 alternative interface.
	// [8] - extended, [9] - pressed, [10] - toggles with every press/release
	input [10:0]	ps2_key,

	// [0-23] mouse data, [24] - toggles with every event, [25-31] - padding,
	// [32-39] - wheel movements, [40-47] - reserved(additional buttons)
	input [47:0]	ps2_mouse,

	// [31:0] - seconds since 1970-01-01 00:00:00, [32] - toggle with every change
	input [32:0]	timestamp,
	
	output			VGA_HS,
	output			VGA_VS,
	output [7:0]	VGA_R,
	output [7:0]	VGA_G,
	output [7:0]	VGA_B,
	output			VGA_HB,
	output			VGA_VB
);

localparam [8:0] VGA_WIDTH = 9'd320;
localparam [8:0] VGA_HEIGHT = 9'd240;

wire _hb;
wire _vb;
assign VGA_HB = ~_hb;
assign VGA_VB = ~_vb;

wire [8:0] hcnt;
wire [8:0] vcnt;

// Display timing module from JTFRAME
jtframe_vtimer #(
	.HB_START(VGA_WIDTH - 1'b1),
	.VB_START(VGA_HEIGHT- 1'b1)
) vtimer 
(
	.clk(clk_sys),
	.pxl_cen(ce_pix),
	.V(vcnt),
	.H(hcnt),
	.Hinit(),
	.Vinit(),
	.LHBL(_hb),
	.LVBL(_vb),
	.HS(VGA_HS),
	.VS(VGA_VS)
);

// Millisecond timer
wire  [15:0]	timer;
generic_timer #(16,15,24) ms_timer
(
	.clk(clk_sys),
	.reset(reset || (timer_cs == 1'b1 && cpu_wr_n == 1'b0)),
	.counter(timer)
);

// CPU control signals
wire [15:0] cpu_addr;
wire [7:0] cpu_din;
wire [7:0] cpu_dout;
wire cpu_rd_n;
wire cpu_wr_n;
wire cpu_mreq_n;

// include Z80 CPU
tv80s T80x  (
	.reset_n   ( !reset ),
	.clk       ( clk_sys ),
	.wait_n    ( 1'b1 ),
	.int_n     ( 1'b1 ),
	.nmi_n     ( 1'b1 ),
	.busrq_n   ( 1'b1 ),
	.mreq_n    ( cpu_mreq_n ),
	.rd_n      ( cpu_rd_n ), 
	.wr_n      ( cpu_wr_n ),
	.A         ( cpu_addr ),
	.di        ( cpu_din ),
	.dout      ( cpu_dout ),
	.m1_n      (),
	.iorq_n    (),
	.rfsh_n    (),
	.halt_n    (),
	.busak_n   ()
  );

// Hardware inputs
wire [7:0] in0_data_out = {VGA_HS, VGA_VS,VGA_HB, VGA_VB, 4'b1000};
wire [7:0] joystick_data_out = joystick[{cpu_addr[4:0],3'd0} +: 8];
wire [7:0] analog_l_data_out = analog_l[{cpu_addr[3:0],3'd0} +: 8];
wire [7:0] analog_r_data_out = analog_r[{cpu_addr[3:0],3'd0} +: 8];
wire [7:0] paddle_data_out = paddle[{cpu_addr[2:0],3'd0} +: 8];
wire [7:0] spinner_data_out = spinner[{cpu_addr[3:0],3'd0} +: 8];
wire [7:0] ps2_key_data_out = ps2_key[{cpu_addr[0],3'd0} +: 8];
wire [7:0] ps2_mouse_data_out = ps2_mouse[{cpu_addr[2:0],3'd0} +: 8];
wire [7:0] timestamp_data_out = timestamp[{cpu_addr[2:0],3'd0} +: 8];
wire [7:0] timer_data_out = timer[{cpu_addr[0],3'd0} +: 8];

// CPU address decodes
// - Program ROM
wire pgrom_cs = cpu_addr[15] == 1'b0;
// - Memory mapped inputs
wire [7:0] memory_map_addr = cpu_addr[15:8];
wire in0_cs = memory_map_addr == 8'b10000000;
wire joystick_cs = memory_map_addr == 8'b10000001;
wire analog_l_cs = memory_map_addr == 8'b10000010;
wire analog_r_cs = memory_map_addr == 8'b10000011;
wire paddle_cs = memory_map_addr == 8'b1000100;
wire spinner_cs = memory_map_addr == 8'b10000101;
wire ps2_key_cs = memory_map_addr == 8'b10000110;
wire ps2_mouse_cs = memory_map_addr == 8'b10000111;
wire timestamp_cs = memory_map_addr == 8'b10001000;
wire timer_cs = memory_map_addr == 8'b10001001;
// - Casval (character map)
wire chram_cs = cpu_addr[15:11] == 5'b10011;
wire fgcolram_cs = cpu_addr[15:11] == 5'b10100;
wire bgcolram_cs = cpu_addr[15:11] == 5'b10101;
// - Comet (sprite engine)
wire spriteram_cs = cpu_addr[15:11] == 5'b10110;
// - CPU working RAM
wire wkram_cs = cpu_addr[15:14] == 2'b11;

always @(posedge clk_sys) begin
	// if(pgrom_cs) $display("%x pgrom o %x", cpu_addr, pgrom_data_out);
	// if(wkram_cs) $display("%x wkram i %x o %x w %b", cpu_addr, cpu_dout, wkram_data_out, wkram_wr);
	// if(chram_cs) $display("%x chram i %x o %x w %b", cpu_addr, cpu_dout, chram_data_out, chram_wr);
	// if(fgcolram_cs) $display("%x fgcolram i %x o %x w %b", cpu_addr, cpu_dout, fgcolram_data_out, fgcolram_wr);
	// if(in0_cs) $display("%x in0 i %x o %x", cpu_addr, cpu_dout, in0_data_out);
 	// if(joystick_cs) $display("joystick %b  %b", joystick_bit, joystick_data_out);
 	// if(analog_l_cs) $display("analog_l %b  %b", analog_l_bit, analog_l_data_out);
 	// if(analog_r_cs) $display("analog_r %b  %b", analog_r_bit, analog_r_data_out);
	// if(paddle_cs) $display("paddle %b", paddle_data_out);
	// if(ps2_key_cs) $display("ps2_key %b %x", ps2_key_data_out, cpu_addr[3:0]);
 	// $display("dn_addr: %x  dn_index: %x", dn_addr, dn_index);
	//if(timer_cs) $display("timer %b", timer_data_out);
end
// always @(posedge ps2_mouse[24]) begin
// 	$display("%b", ps2_mouse);
// end

// CPU data mux
assign cpu_din = pgrom_cs ? pgrom_data_out :
				 wkram_cs ? wkram_data_out :
				 chram_cs ? chram_data_out :
				 fgcolram_cs ? fgcolram_data_out :
				 bgcolram_cs ? bgcolram_data_out :
				 spriteram_cs ? spriteram_data_out :
				 in0_cs ? in0_data_out :
				 joystick_cs ? joystick_data_out :
				 analog_l_cs ? analog_l_data_out :
				 analog_r_cs ? analog_r_data_out :
				 paddle_cs ? paddle_data_out :
				 spinner_cs ? spinner_data_out :
				 ps2_key_cs ? ps2_key_data_out :
				 ps2_mouse_cs ? ps2_mouse_data_out :
				 timestamp_cs ? timestamp_data_out :
				 timer_cs ? timer_data_out :
				 8'b00000000;

// ROM data available to CPU
wire [7:0] pgrom_data_out;
wire [7:0] chrom_data_out;

// ROM data not available to CPU
wire [15:0] palrom_data_out;
wire [7:0] spriterom_data_out;

// RAM data available to CPU
wire [7:0] wkram_data_out;
wire [7:0] chram_data_out;
wire [7:0] fgcolram_data_out;
wire [7:0] bgcolram_data_out;

// RAM data not available to CPU
wire [7:0] chmap_data_out;

// Rom upload write enables
wire pgrom_wr = dn_wr && dn_index == 8'd0;
wire chrom_wr = dn_wr && dn_index == 8'd1;
wire palrom_wr = dn_wr && dn_index == 8'd2;
wire spriterom_wr = dn_wr && dn_index == 8'd3;

// Ram write enables
wire wkram_wr = !cpu_wr_n && wkram_cs;
wire chram_wr = !cpu_wr_n && chram_cs;
wire fgcolram_wr = !cpu_wr_n && fgcolram_cs;
wire bgcolram_wr = !cpu_wr_n && bgcolram_cs;
wire spriteram_wr = !cpu_wr_n && spriteram_cs;

// Casval - character map
wire [11:0] chram_addr;
wire [11:0] chrom_addr;
wire [2:0]	charmap_r;
wire [2:0]	charmap_g;
wire [1:0]	charmap_b;
wire		charmap_a;
charmap casval
(
	.clk(clk_sys),
	.reset(reset),
	.hcnt(hcnt),
	.vcnt(vcnt),
	.chrom_data_out(chrom_data_out),
	.fgcolram_data_out(fgcolram_data_out),
	.bgcolram_data_out(bgcolram_data_out),
	.chmap_data_out(chmap_data_out),
	.chram_addr(chram_addr),
	.chrom_addr(chrom_addr),
	.r(charmap_r),
	.g(charmap_g),
	.b(charmap_b),
	.a(charmap_a)
);

// Comet - sprite engine
reg [6:0] spriteram_addr;
wire [7:0] spriteram_data_out;
reg [10:0] sprom_addr;
wire [9:0] spritelbram_rd_addr;
reg [9:0] spritelbram_wr_addr;
reg spritelbram_wr;
reg spritelb_slot_rd;
reg spritelb_slot_wr = 1'b1;
reg [3:0] spritelbram_data_in;
wire [3:0] spritelbram_data_out;
reg [4:0] palrom_addr;

parameter SE_IDLE = 0;
parameter SE_WAIT = 1;
parameter SE_RESET = 2;
parameter SE_CLEAR_BUFFER = 3;
parameter SE_SETUP_READ_Y = 5;
parameter SE_READ_Y_UPPER = 6;
parameter SE_READ_Y_LOWER = 7;
parameter SE_CHECK_Y = 8;
parameter SE_READ_X_UPPER = 9;
parameter SE_READ_X_LOWER = 10;
parameter SE_SETUP_WRITE = 11;
parameter SE_GET_PIXEL = 12;
parameter SE_STAGE_PIXEL = 13;
parameter SE_WRITE_PIXEL = 14;


reg vsync_last;
reg hsync_last;
reg [3:0] spr_state;
reg [3:0] spr_state_next;
reg [3:0] spr_index;
localparam spr_index_max = 4'd15;
localparam spr_bytes_per_image = 128;
localparam spr_size_x = 16'd15;
localparam spr_size_y = 16'd15;
localparam spr_ram_item_width = 4;
localparam spr_line_max = 352;
reg [15:0] spr_y;
reg [15:0] spr_x;
reg spr_enable;
reg [3:0] spr_image_index;
reg [6:0] spr_address_base;
reg [15:0] spr_active_y;
reg [4:0] spr_pixel_index;
reg [4:0] spr_pixel_count;
reg [10:0] spr_rom_offset;

reg [16:0] idle_timer;
reg [16:0] spr_counter;
reg [16:0] spr_counter2;

always @(posedge clk_sys)
begin

	spr_counter <= spr_counter + 1'b1;
	spr_counter2 <= spr_counter2 + 1'b1;

	hsync_last <= VGA_HS;
	case (spr_state)
		SE_IDLE:
		begin
			// Wait for hsync to go high outside of reset
			if(reset == 1'b0 && VGA_HS == 1'b1 && hsync_last == 1'b0)
			begin
				spritelb_slot_rd <= spritelb_slot_rd + 1'b1;
				spritelb_slot_wr <= spritelb_slot_wr + 1'b1;
				spr_active_y <= ({6'b0,vcnt} + spr_size_y) + 16'd1;
				spr_state <= SE_RESET;
				//$display("LEAVING SE_IDLE: %d %d", idle_timer, spr_counter, spr_counter2);
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
				spritelbram_data_in <= 4'b0;
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
			spr_address_base = spr_index * spr_ram_item_width;
			spriteram_addr <= spr_address_base;
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
					//$display("MOVING TO IDLE FROM CHECK_Y: %d", spr_counter);
					spr_state <= SE_IDLE;
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
			//$display("STARTING SPRITE WRITE: %d", spr_counter);
			$display("SE_SETUP_WRITE: AY: %d   Y: %d   X: %d   I: %d   O: %d", spr_active_y, spr_y, spr_x, spr_image_index, spr_rom_offset);
			// Begin to write sprite line from ROM to linebuffer
			// - Setup initial address
			spritelbram_wr <= 1'b0;
		 	spritelbram_wr_addr <= {spritelb_slot_wr, spr_x[8:0]};
		 	sprom_addr <= { spr_image_index[2:0], 8'b0} + {spr_rom_offset[6:0], 4'b0};
		 	spr_pixel_index <= 5'b0;
		 	spr_pixel_count <= spr_size_x[4:0];
		 	spr_state <= SE_GET_PIXEL;
		end
		SE_GET_PIXEL:
		begin
			if(spr_pixel_index > spr_pixel_count)
		 	begin
		 		// Move to next sprite or finish
		 		if(spr_index == spr_index_max)
		 		begin
		 			spr_state <= SE_IDLE;
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
				$display("SE_GET_PIXEL: p: %d/%d i: %d, sprom_addr < %x, palrom_addr < %x", spr_pixel_index, spr_pixel_count, spr_image_index, sprom_addr, spriterom_data_out);
				palrom_addr <= spriterom_data_out[4:0];	
				sprom_addr <= sprom_addr + 1'b1;
				spr_state <= SE_WAIT;
				spr_state_next <= SE_STAGE_PIXEL;
				// spr_state <= SE_STAGE_PIXEL;
			end
		end

		SE_STAGE_PIXEL:
		begin
			// Get pixel colour from palette rom and stage input to line buffer
			$display("SE_STAGE_PIXEL: p: %d/%d i: %d, spritelbram_data_in < %x", spr_pixel_index, spr_pixel_count, spr_image_index, palrom_data_out);
			spritelbram_wr <= 1'b1;
			spritelbram_data_in <= palrom_data_out[3:0];
			spr_state <= SE_WRITE_PIXEL;
			//$display("pixel: %d/%d index: %d  sprom_addr: %x  spriterom_data_out: %x", spr_pixel_index, spr_pixel_count, spr_image_index, sprom_addr, spriterom_data_out);
		end

		SE_WRITE_PIXEL:
		begin
			// Get pixel colour from palette rom and stage input to line buffer
			$display("SE_WRITE_PIXEL: p: %d/%d i: %d, spritelbram_wr_addr < %x, spritelbram_data_in=%x", spr_pixel_index, spr_pixel_count, spr_image_index, spritelbram_wr_addr, spritelbram_data_in);
			spr_pixel_index <= spr_pixel_index + 1'b1;
			spritelbram_wr_addr <= spritelbram_wr_addr + 1'b1;
			spritelbram_wr <= 1'b0;
			spr_state <= SE_GET_PIXEL;
			//$display("pixel: %d/%d index: %d  sprom_addr: %x  spriterom_data_out: %x", spr_pixel_index, spr_pixel_count, spr_image_index, sprom_addr, spriterom_data_out);
		end
	endcase
end

assign spritelbram_rd_addr = ({spritelb_slot_rd, hcnt + spr_size_x[8:0]}) + 10'd2;

// RGB mixer
assign VGA_R = {{2{charmap_r}},2'b0};
//assign VGA_G = {{2{charmap_g}},2'b0};
assign VGA_G = spritelbram_data_out > 0 ? {spritelbram_data_out[3:0],4'b0} : 8'h0;
//assign VGA_B = {{3{charmap_b}},2'b0};
assign VGA_B = spritelbram_data_out > 0 ? 8'hFF : 8'h0;


// MEMORY
// ------

// Program ROM - 0x0000 - 0x7FFF (0x6000 / 32768 bytes)
dpram #(15,8, "rom.hex") pgrom
(
	.clock_a(clk_sys),
	.address_a(cpu_addr[14:0]),
	.wren_a(1'b0),
	.data_a(),
	.q_a(pgrom_data_out),

	.clock_b(clk_sys),
	.address_b(dn_addr[14:0]),
	.wren_b(pgrom_wr),
	.data_b(dn_data),
	.q_b()
);

// Char ROM - 0x9000 - 0x97FF (0x0800 / 2048 bytes)
dpram #(11,8, "font.hex") chrom
(
	.clock_a(clk_sys),
	.address_a(chrom_addr[10:0]),
	.wren_a(1'b0),
	.data_a(),
	.q_a(chrom_data_out),

	.clock_b(clk_sys),
	.address_b(dn_addr[10:0]),
	.wren_b(chrom_wr),
	.data_b(dn_data),
	.q_b()
);

// Char index RAM - 0x9800 - 0xA000 (0x0800 / 2048 bytes)
dpram #(11,8) chram
(
	.clock_a(clk_sys),
	.address_a(cpu_addr[10:0]),
	.wren_a(chram_wr),
	.data_a(cpu_dout),
	.q_a(chram_data_out),

	.clock_b(clk_sys),
	.address_b(chram_addr[10:0]),
	.wren_b(1'b0),
	.data_b(),
	.q_b(chmap_data_out)
);

// Char foreground color RAM - 0xA000 - 0xA800 (0x0800 / 2048 bytes)
dpram #(11,8) fgcolram
(
	.clock_a(clk_sys),
	.address_a(cpu_addr[10:0]),
	.wren_a(fgcolram_wr),
	.data_a(cpu_dout),
	.q_a(),

	.clock_b(clk_sys),
	.address_b(chram_addr[10:0]),
	.wren_b(1'b0),
	.data_b(),
	.q_b(fgcolram_data_out)
);

// Char background color RAM - 0xA800 - 0xB000 (0x0800 / 2048 bytes)
dpram #(11,8) bgcolram
(
	.clock_a(clk_sys),
	.address_a(cpu_addr[10:0]),
	.wren_a(bgcolram_wr),
	.data_a(cpu_dout),
	.q_a(),

	.clock_b(clk_sys),
	.address_b(chram_addr[10:0]),
	.wren_b(1'b0),
	.data_b(),
	.q_b(bgcolram_data_out)
);

// Sprite RAM - 0xB000 - 0xB080 (0x0080 / 128 bytes)
dpram #(7,8) spriteram
(
	.clock_a(clk_sys),
	.address_a(cpu_addr[6:0]),
	.wren_a(spriteram_wr),
	.data_a(cpu_dout),
	.q_a(),

	.clock_b(clk_sys),
	.address_b(spriteram_addr[6:0]),
	.wren_b(1'b0),
	.data_b(),
	.q_b(spriteram_data_out)
);

// Sprite linebuffer RAM - 0xB800 - 0xB900 (0x0100 / 256 bytes)
dpram #(10,4) spritelbram
(
	.clock_a(clk_sys),
	.address_a(spritelbram_wr_addr),
	.wren_a(spritelbram_wr),
	.data_a(spritelbram_data_in),
	.q_a(),

	.clock_b(clk_sys),
	.address_b(spritelbram_rd_addr),
	.wren_b(1'b0),
	.data_b(),
	.q_b(spritelbram_data_out)
);

// Work RAM - 0xC000 - 0xFFFF (0x4000 / 16384 bytes)
spram #(14,8) wkram
(
	.clock(clk_sys),
	.address(cpu_addr[13:0]),
	.wren(wkram_wr),
	.data(cpu_dout),
	.q(wkram_data_out)
);

// Palette ROM - 0x10000 - 0x10020 (0x0020 / 32 bytes)
dpram_w1r2 #(5,8, "palette.hex") palrom
(
	.clock_a(clk_sys),
	.address_a(dn_addr[4:0]),
	.wren_a(palrom_wr),
	.data_a(dn_data),

	.clock_b(clk_sys),
	.address_b(palrom_addr[3:0]),
	.q_b(palrom_data_out)
);

// Sprite ROM - 0x11000 - 0x11800 (0x0800 / 2048 bytes)
dpram #(11,8, "sprite.hex") spriterom
(
	.clock_a(clk_sys),
	.address_a(sprom_addr[10:0]),
	.wren_a(1'b0),
	.data_a(),
	.q_a(spriterom_data_out),

	.clock_b(clk_sys),
	.address_b(dn_addr[10:0]),
	.wren_b(spriterom_wr),
	.data_b(dn_data),
	.q_b()
);

endmodule
