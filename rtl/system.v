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
	input			clk_24,
	input 			ce_6,
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
	.VB_START(VGA_HEIGHT - 1'b1)
) vtimer 
(
	.clk(clk_24),
	.pxl_cen(ce_6),
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
	.clk(clk_24),
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
	.clk       ( clk_24 ),
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
wire starfield1_cs = memory_map_addr == 8'b10001010 && cpu_addr[2:1] == 2'b00;
wire starfield2_cs = memory_map_addr == 8'b10001010 && cpu_addr[2:1] == 2'b01;
wire starfield3_cs = memory_map_addr == 8'b10001010 && cpu_addr[2:1] == 2'b10;
// - Casval (character map)
wire chram_cs = cpu_addr[15:11] == 5'b10011;
wire fgcolram_cs = cpu_addr[15:11] == 5'b10100;
wire bgcolram_cs = cpu_addr[15:11] == 5'b10101;
// - Comet (sprite engine)
wire spriteram_cs = cpu_addr[15:11] == 5'b10110;
wire spritecollisionram_cs = memory_map_addr == 8'b10110100;
// -  (starfield)
// - CPU working RAM
wire wkram_cs = cpu_addr[15:14] == 2'b11;

always @(posedge clk_24) begin
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
	//if(starfield1_cs) $display("starfield1 %b %b", cpu_addr, cpu_dout);
	//if(starfield2_cs) $display("starfield2 %b %b", cpu_addr, cpu_dout);
	//if(starfield3_cs) $display("starfield3 %b %b", cpu_addr, cpu_dout);
end

// CPU data mux
assign cpu_din = pgrom_cs ? pgrom_data_out :
				 wkram_cs ? wkram_data_out :
				 chram_cs ? chram_data_out :
				 fgcolram_cs ? fgcolram_data_out :
				 bgcolram_cs ? bgcolram_data_out :
				 spritecollisionram_cs ? spritecollisionram_data_out :
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
wire spritecollisionram_wr;

// Casval - character map
wire [11:0] chram_addr;
wire [11:0] chrom_addr;
wire [2:0]	charmap_r;
wire [2:0]	charmap_g;
wire [1:0]	charmap_b;
wire		charmap_a;
charmap casval
(
	.clk(clk_24),
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
wire [11:0]	sprom_addr;
wire [7:0]	spriterom_data_out;
wire [4:0]	palrom_addr;
wire [15:0]	palrom_data_out;
wire [6:0]	spriteram_addr;
wire [7:0]	spriteram_data_out;
wire [6:0]	spritecollisionram_addr;
wire [7:0]	spritecollisionram_data_out;
wire [7:0]	spritecollisionram_data_in;
wire [9:0]	spritelbram_rd_addr;
wire [9:0]	spritelbram_wr_addr;
wire 		spritelbram_wr;
wire [15:0]	spritelbram_data_in;
wire [15:0]	spritelbram_data_out;
wire [7:0]	spr_r;
wire [7:0]	spr_g;
wire [7:0]	spr_b;
wire 		spr_a;
sprite_engine comet
(
	.clk(clk_24),
	.reset(reset),
	.hsync(VGA_HS),
	.hcnt(hcnt),
	.vcnt(vcnt),
	.spriterom_data_out(spriterom_data_out),
	.spriteram_data_out(spriteram_data_out),
	.palrom_data_out(palrom_data_out),
	.spritelbram_data_out(spritelbram_data_out),
	.spritecollisionram_data_in(spritecollisionram_data_in),
	.spriteram_addr(spriteram_addr),
	.spritecollisionram_addr(spritecollisionram_addr),
	.sprom_addr(sprom_addr),
	.palrom_addr(palrom_addr),
	.spritelbram_rd_addr(spritelbram_rd_addr),
	.spritelbram_wr_addr(spritelbram_wr_addr),
	.spritelbram_wr(spritelbram_wr),
	.spritecollisionram_wr(spritecollisionram_wr),
	.spritelbram_data_in(spritelbram_data_in),
	.spr_r(spr_r),
	.spr_g(spr_g),
	.spr_b(spr_b),
	.spr_a(spr_a)
);

// Moroboshi (starfield)

wire 		sf_on1;
wire [7:0]	sf_star1;
starfield #(
	.H(396),
	.V(256),
	.LEN(22),
	.SEED(22'h1FFFFF),
	.MASK(22'b0000111100001111000011),
	.TAPS(22'b1100000000000000000000)
) stars1
(
	.clk(clk_24),
	.rst(reset),
	.vblank(VGA_VB),
	.en(ce_6),
	.data_in(cpu_dout),
	.write(starfield1_cs == 1'b1 && cpu_wr_n == 1'b0),
	.sf_on(sf_on1),
	.sf_star(sf_star1)
);
wire 		sf_on2;
wire [7:0]	sf_star2;
starfield #(
	.H(396),
	.V(256),
	.LEN(21),
	.SEED(21'h1FFFF0),
	.MASK(21'b000011110000111100001),
	.TAPS(21'b101010000000000000000)
) stars2
(
	.clk(clk_24),
	.rst(reset),
	.vblank(VGA_VB),	
	.en(ce_6),
	.data_in(cpu_dout),
	.write(starfield2_cs == 1'b1 && cpu_wr_n == 1'b0),
	.sf_on(sf_on2),
	.sf_star(sf_star2)
);
wire 		sf_on3;
wire [7:0]	sf_star3;
starfield #(
	.H(396),
	.V(256),
	.LEN(21),
	.SEED(21'h1FFF00),
	.MASK(21'b000011110000111100001),
	.TAPS(21'b101000000000000000000)
) stars3
(
	.clk(clk_24),
	.rst(reset),
	.vblank(VGA_VB),	
	.en(ce_6),
	.data_in(cpu_dout),
	.write(starfield3_cs == 1'b1 && cpu_wr_n == 1'b0),
	.sf_on(sf_on3),
	.sf_star(sf_star3)
);

wire sf_on = sf_on1 || sf_on2 || sf_on3;
wire [7:0] sf_star_colour = sf_on1 ? sf_star1[7:0] : sf_on2 ? {1'b0,sf_star2[6:0]} : sf_on3 ? {2'b0,sf_star3[5:0]} : 8'b0;

// RGB mixer
assign VGA_R = spr_a ? spr_r : sf_on ? sf_star_colour : {{2{charmap_r}},2'b0}; 
assign VGA_G = spr_a ? spr_g : sf_on ? sf_star_colour : {{2{charmap_g}},2'b0};
assign VGA_B = spr_a ? spr_b : sf_on ? sf_star_colour : {{3{charmap_b}},2'b0};

// MEMORY
// ------

// Program ROM - 0x0000 - 0x7FFF (0x6000 / 32768 bytes)
dpram #(15,8, "rom.hex") pgrom
(
	.clock_a(clk_24),
	.address_a(cpu_addr[14:0]),
	.wren_a(1'b0),
	.data_a(),
	.q_a(pgrom_data_out),

	.clock_b(clk_24),
	.address_b(dn_addr[14:0]),
	.wren_b(pgrom_wr),
	.data_b(dn_data),
	.q_b()
);

// Char ROM - 0x9000 - 0x97FF (0x0800 / 2048 bytes)
dpram #(11,8, "font.hex") chrom
(
	.clock_a(clk_24),
	.address_a(chrom_addr[10:0]),
	.wren_a(1'b0),
	.data_a(),
	.q_a(chrom_data_out),

	.clock_b(clk_24),
	.address_b(dn_addr[10:0]),
	.wren_b(chrom_wr),
	.data_b(dn_data),
	.q_b()
);

// Char index RAM - 0x9800 - 0x9FFF (0x0800 / 2048 bytes)
dpram #(11,8) chram
(
	.clock_a(clk_24),
	.address_a(cpu_addr[10:0]),
	.wren_a(chram_wr),
	.data_a(cpu_dout),
	.q_a(chram_data_out),

	.clock_b(clk_24),
	.address_b(chram_addr[10:0]),
	.wren_b(1'b0),
	.data_b(),
	.q_b(chmap_data_out)
);

// Char foreground color RAM - 0xA000 - 0xA7FF (0x0800 / 2048 bytes)
dpram #(11,8) fgcolram
(
	.clock_a(clk_24),
	.address_a(cpu_addr[10:0]),
	.wren_a(fgcolram_wr),
	.data_a(cpu_dout),
	.q_a(),

	.clock_b(clk_24),
	.address_b(chram_addr[10:0]),
	.wren_b(1'b0),
	.data_b(),
	.q_b(fgcolram_data_out)
);

// Char background color RAM - 0xA800 - 0xAFFF (0x0800 / 2048 bytes)
dpram #(11,8) bgcolram
(
	.clock_a(clk_24),
	.address_a(cpu_addr[10:0]),
	.wren_a(bgcolram_wr),
	.data_a(cpu_dout),
	.q_a(),

	.clock_b(clk_24),
	.address_b(chram_addr[10:0]),
	.wren_b(1'b0),
	.data_b(),
	.q_b(bgcolram_data_out)
);

// Sprite RAM - 0xB000 - 0xB07F (0x0080 / 128 bytes)
dpram #(7,8) spriteram
(
	.clock_a(clk_24),
	.address_a(cpu_addr[6:0]),
	.wren_a(spriteram_wr),
	.data_a(cpu_dout),
	.q_a(),

	.clock_b(clk_24),
	.address_b(spriteram_addr[6:0]),
	.wren_b(1'b0),
	.data_b(),
	.q_b(spriteram_data_out)
);

// Sprite Collision RAM - 0xB400 - 0xB47F (0x0080 / 128 bytes)
dpram #(7,8) spritecollisionram
(
	.clock_a(clk_24),
	.address_a(cpu_addr[6:0]),
	.wren_a(1'b0),
	.data_a(),
	.q_a(spritecollisionram_data_out),

	.clock_b(clk_24),
	.address_b(spritecollisionram_addr),
	.wren_b(spritecollisionram_wr),
	.data_b(spritecollisionram_data_in),
	.q_b()
);

// Sprite linebuffer RAM - 0xB800 - 0xBFFF (0x0800 / 2048 bytes)
dpram #(10,16) spritelbram
(
	.clock_a(clk_24),
	.address_a(spritelbram_wr_addr),
	.wren_a(spritelbram_wr),
	.data_a(spritelbram_data_in),
	.q_a(),

	.clock_b(clk_24),
	.address_b(spritelbram_rd_addr),
	.wren_b(1'b0),
	.data_b(),
	.q_b(spritelbram_data_out)
);

// Work RAM - 0xC000 - 0xFFFF (0x4000 / 16384 bytes)
spram #(14,8) wkram
(
	.clock(clk_24),
	.address(cpu_addr[13:0]),
	.wren(wkram_wr),
	.data(cpu_dout),
	.q(wkram_data_out)
);

// Palette ROM - 0x10000 - 0x1001F (0x0020 / 32 bytes)
dpram_w1r2 #(5,8, "palette.hex") palrom
(
	.clock_a(clk_24),
	.address_a(dn_addr[4:0]),
	.wren_a(palrom_wr),
	.data_a(dn_data),

	.clock_b(clk_24),
	.address_b(palrom_addr),
	.q_b(palrom_data_out)
);

// Sprite ROM - 0x11000 - 0x11800 (0x0800 / 2048 bytes)
dpram #(12,8, "sprite.hex") spriterom
(
	.clock_a(clk_24),
	.address_a(sprom_addr[11:0]),
	.wren_a(1'b0),
	.data_a(),
	.q_a(spriterom_data_out),

	.clock_b(clk_24),
	.address_b(dn_addr[11:0]),
	.wren_b(spriterom_wr),
	.data_b(dn_data),
	.q_b()
);

endmodule
