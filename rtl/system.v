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
	input 			ce_2,
	input			reset,
	input			pause,
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

	// 6 devices, 16 bits each spinner [7:0] -128..+127, [8] - toggle with every update, [9-15] padding
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
	output			VGA_VB,
	output	[15:0]	AUDIO_L,
	output	[15:0]	AUDIO_R
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
	.reset(reset || (timer_cs && !cpu_wr_n)),
	.counter(timer)
);

// CPU control signals
wire [15:0] cpu_addr;
wire [7:0] cpu_din;
wire [7:0] cpu_dout;
wire cpu_wr_n;

// include Z80 CPU
tv80s #(
	.Mode(1),
	.IOWait(0)
) T80x  (
	.reset_n   ( !reset ),
	.clk       ( clk_24 ),
	.wait_n    ( !pause_system ),
	.int_n     ( 1'b1 ),
	.nmi_n     ( 1'b1 ),
	.busrq_n   ( 1'b1 ),
	.mreq_n    (),
	.rd_n      (),
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
`ifdef DEBUG_SIMULATION
	wire debug = 1'b1;
`else
	wire debug = 1'b0;
`endif
wire [7:0] in0_data_out = {VGA_HS, VGA_VS,VGA_HB, VGA_VB, 3'b100, debug};
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
wire system_pause_cs = cpu_addr[15:4] == 12'b100010100011;
wire sound_cs = cpu_addr[15:4] == 12'b100010110000;
wire music_cs = cpu_addr[15:4] == 12'b100010110001;

// - Casval (character map)
wire chram_cs = cpu_addr[15:11] == 5'b10011;
wire fgcolram_cs = cpu_addr[15:11] == 5'b10100;
wire bgcolram_cs = cpu_addr[15:11] == 5'b10101;
// - Comet (sprite engine)
wire spriteram_cs = cpu_addr[15:11] == 5'b10110 && !spritecollisionram_cs;
wire spritecollisionram_cs = memory_map_addr == 8'b10110100;
// - CPU working RAM
wire wkram_cs = cpu_addr[15:14] == 2'b11;

// System pause trigger
reg pause_trigger = 0;
wire pause_system = pause || pause_trigger;
always @(posedge clk_24) begin
	if(system_pause_cs && !cpu_wr_n) pause_trigger <= 1'b1;
	if(pause) pause_trigger<=1'b0;
end

reg vblank_last;
reg [15:0] vblank_start;

always @(posedge clk_24) begin
	vblank_last <= VGA_VB;
	//if(pgrom_cs) $display("%x pgrom o %x", cpu_addr, pgrom_data_out);
	//if(wkram_cs) $display("%x wkram i %x o %x w %b", cpu_addr, cpu_dout, wkram_data_out, wkram_wr);
	//if(chram_cs) $display("%x chram i %x o %x w %b", cpu_addr, cpu_dout, chram_data_out, chram_wr);
	//if(fgcolram_cs) $display("%x fgcolram i %x o %x w %b", cpu_addr, cpu_dout, fgcolram_data_out, fgcolram_wr);
	//if(in0_cs) $display("%x in0 i %x o %x", cpu_addr, cpu_dout, in0_data_out);
 	//if(joystick_cs) $display("joystick %b  %b", joystick_bit, joystick_data_out);
 	//if(analog_l_cs) $display("analog_l %b  %b", analog_l_bit, analog_l_data_out);
 	//if(analog_r_cs) $display("analog_r %b  %b", analog_r_bit, analog_r_data_out);
	//if(paddle_cs) $display("paddle %b", paddle_data_out);
	//if(ps2_key_cs) $display("ps2_key %b %x", ps2_key_data_out, cpu_addr[3:0]);
 	//$display("dn_addr: %x  dn_index: %x", dn_addr, dn_index);
	//if(starfield1_cs) $display("starfield1 %b %b", cpu_addr, cpu_dout);
	//if(starfield2_cs) $display("starfield2 %b %b", cpu_addr, cpu_dout);
	//if(starfield3_cs) $display("starfield3 %b %b", cpu_addr, cpu_dout);
	//if(!cpu_wr_n) $display("cpu_write %x %b",cpu_addr, cpu_dout);
	//if(spritecollisionram_cs && !cpu_wr_n) $display("spritecollisionram %b %b %b", cpu_wr_n, cpu_addr, cpu_dout);
	//if(sound_cs && !cpu_wr_n) $display("sound_cs %b %b", cpu_addr, cpu_dout);
	//if(music_cs && !cpu_wr_n) $display("music_cs %b %b", cpu_addr, cpu_dout);
end

// CPU data mux
assign cpu_din = pgrom_cs ? pgrom_data_out :
				 wkram_cs ? wkram_data_out :
				 chram_cs ? chram_data_out :
				 fgcolram_cs ? fgcolram_data_out :
				 bgcolram_cs ? bgcolram_data_out :
				 spritecollisionram_cs ? {8{spritecollisionram_data_out_cpu}} :
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
wire musicrom_wr = dn_wr && dn_index == 8'd4;
wire soundrom_wr = dn_wr && dn_index == 8'd5;

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
wire [7:0]	charmap_r;
wire [7:0]	charmap_g;
wire [7:0]	charmap_b;
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
wire [13:0]	sprom_addr;
wire [7:0]	spriterom_data_out;
wire [7:0]	palrom_addr;
wire [15:0]	palrom_data_out;
wire [6:0]	spriteram_addr;
wire [7:0]	spriteram_data_out;
wire [4:0]	spritecollisionram_addr;
wire		spritecollisionram_data_out_cpu;
wire		spritecollisionram_data_out;
wire		spritecollisionram_data_in;
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
	.pause(pause_system),
	.hsync(VGA_HS),
	.vsync(VGA_VS),
	.vblank(VGA_VB),
	.hcnt(hcnt),
	.vcnt(vcnt),
	.spriterom_data_out(spriterom_data_out),
	.spriteram_data_out(spriteram_data_out),
	.palrom_data_out(palrom_data_out),
	.spritelbram_data_out(spritelbram_data_out),
	.spritecollisionram_data_in(spritecollisionram_data_in),
	.spritecollisionram_data_out(spritecollisionram_data_out),
	.spriteram_addr(spriteram_addr),
	.spritecollisionram_addr(spritecollisionram_addr),
	.sprom_addr(sprom_addr),
	.palrom_addr(palrom_addr),
	.spritelbram_rd_addr(spritelbram_rd_addr),
	.spritelbram_wr_addr(spritelbram_wr_addr),
	.spritelbram_wr(spritelbram_wr),
	.spritecollisionram_wr(spritecollisionram_wr),
	.spritelbram_data_in(spritelbram_data_in),
`ifdef DEBUG_SPRITE_COLLISION
	.spritedebugram_addr_b(spritedebugram_addr_b),
	.spritedebugram_wr_b(spritedebugram_wr_b),
	.spritedebugram_data_in_b(spritedebugram_data_in_b),
	.spritedebugram_data_out_b(spritedebugram_data_out_b),
`endif
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
	.pause(pause_system),
	.addr(cpu_addr[0]),
	.data_in(cpu_dout),
	.write(starfield1_cs && !cpu_wr_n),
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
	.pause(pause_system),
	.addr(cpu_addr[0]),
	.data_in(cpu_dout),
	.write(starfield2_cs && !cpu_wr_n),
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
	.pause(pause_system),
	.addr(cpu_addr[0]),
	.data_in(cpu_dout),
	.write(starfield3_cs && !cpu_wr_n),
	.sf_on(sf_on3),
	.sf_star(sf_star3)
);

wire sf_on = sf_on1 || sf_on2 || sf_on3;
wire [7:0] sf_star_colour = sf_on1 ? sf_star1[7:0] : sf_on2 ? {1'b0,sf_star2[6:0]} : sf_on3 ? {2'b0,sf_star3[5:0]} : 8'b0;

// Sprite collision debug
`ifdef DEBUG_SPRITE_COLLISION
localparam SD_WAIT = 0;
localparam SD_CLEAR_BEGIN = 1;
localparam SD_CLEAR = 2;
reg [2:0] sd_state;
always @(posedge clk_24) 
begin
	case(sd_state)
		SD_WAIT:
		begin
			spritedebugram_wr_a <= 1'b0;
			spritedebugram_addr_a <= (({8'b0,vcnt} + 17'd16) * 17'd320) + {8'b0,hcnt} + 17'd19;

			if(!pause_system)
			begin
					if(VGA_VB && !vblank_last)
					begin
						sd_state <= SD_CLEAR_BEGIN;
					end
			end
		end

		SD_CLEAR_BEGIN:
		begin
			//$display("SD_CLEAR_BEGIN: %d %d", hcnt, vcnt);
			spritedebugram_addr_a <= 17'b0;
			spritedebugram_data_in_a <= 8'd0;
			spritedebugram_wr_a <= 1'b1;
			sd_state <= SD_CLEAR;
		end

		SD_CLEAR:
		begin
			
			if(pause_system)
			begin
				sd_state <= SD_WAIT;
			end
			else
			begin
				if(spritedebugram_addr_a > 17'd79000)
				begin
					spritedebugram_addr_a <= 17'b0;
					sd_state <= SD_WAIT;
					//$display("SD_CLEAR_END: %d %d", hcnt, vcnt);
					spritedebugram_wr_a <= 1'b0;
				end
				else
				begin
					spritedebugram_addr_a <= spritedebugram_addr_a + 17'b1;
				end
			end
		end
	endcase
end
`endif

// RGB mixer
`ifdef DEBUG_SPRITE_COLLISION
assign VGA_R = charmap_a ? charmap_r : spritedebugram_data_out_a > 8'b0 ? spritedebugram_data_out_a : spr_a ? spr_r : sf_on ? sf_star_colour : 8'b0; 
assign VGA_G = charmap_a ? charmap_g : spr_a ? spr_g : sf_on ? sf_star_colour : 8'b0;
assign VGA_B = charmap_a ? charmap_b : spritedebugram_data_out_a > 8'b0 ? spritedebugram_data_out_a : spr_a ? spr_b : sf_on ? sf_star_colour : 8'b0;
`endif
`ifndef DEBUG_SPRITE_COLLISION
assign VGA_R = charmap_a ? charmap_r : spr_a ? spr_r : sf_on ? sf_star_colour : 8'b0; 
assign VGA_G = charmap_a ? charmap_g : spr_a ? spr_g : sf_on ? sf_star_colour : 8'b0;
assign VGA_B = charmap_a ? charmap_b : spr_a ? spr_b : sf_on ? sf_star_colour : 8'b0;
`endif

// Music player
wire [9:0] music_audio_out;
`ifndef DISABLE_MUSIC
localparam MUSIC_ROM_WIDTH = 17;
wire [MUSIC_ROM_WIDTH-1:0] musicrom_addr;
wire  [7:0] musicrom_data_out;

music #(.ROM_WIDTH(MUSIC_ROM_WIDTH)) music (
	.clk(clk_24),
	.ce_2(ce_2),
	.reset(reset),
	.addr(cpu_addr[1:0]),
	.data_in(cpu_dout),
	.write(music_cs && ~cpu_wr_n),
	.vblank(VGA_VB),
	.musicrom_addr(musicrom_addr),
	.musicrom_data_out(musicrom_data_out),
	.audio_out(music_audio_out)
);
`endif


// M5205 sound player
wire signed [11:0] snd_audio_out;
`ifndef DISABLE_SOUND
localparam SOUND_ROM_WIDTH = 16;
reg [SOUND_ROM_WIDTH-1:0] soundrom_addr;
wire [7:0] soundrom_data_out;

sound #(.ROM_WIDTH(SOUND_ROM_WIDTH)) sound (
	.clk(clk_24),
	.reset(reset),
	.addr(cpu_addr[3:0]),
	.data_in(cpu_dout),
	.write(sound_cs && ~cpu_wr_n),
	.soundrom_addr(soundrom_addr),
	.soundrom_data_out(soundrom_data_out),
	.audio_out(snd_audio_out)
);
`endif 

// Mix audio (badly)
wire signed [15:0] music_signed = { 2'b0, music_audio_out, 4'b0 };
wire signed [15:0] audio_signed = { snd_audio_out[11], snd_audio_out[10:0], 4'b0 };

assign AUDIO_L =  audio_signed + music_signed;
assign AUDIO_R = AUDIO_L;


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
dpram #(5,1) spritecollisionram
(
	.clock_a(clk_24),
	.address_a(cpu_addr[4:0]),
	.wren_a(spritecollisionram_cs && ~cpu_wr_n),
	.data_a(cpu_dout[0]),
	.q_a(spritecollisionram_data_out_cpu),

	.clock_b(clk_24),
	.address_b(spritecollisionram_addr),
	.wren_b(spritecollisionram_wr),
	.data_b(spritecollisionram_data_in),
	.q_b(spritecollisionram_data_out)
);

`ifdef DEBUG_SPRITE_COLLISION
reg 	[16:0]	spritedebugram_addr_a;
wire 	[16:0]	spritedebugram_addr_b;
reg		 [7:0]	spritedebugram_data_in_a;
wire	 [7:0]	spritedebugram_data_in_b;
wire	 [7:0]	spritedebugram_data_out_a;
wire	 [7:0]	spritedebugram_data_out_b;
reg				spritedebugram_wr_a;
wire			spritedebugram_wr_b;

// Sprite Debug Frame Buffer 
dpram #(17,8) spritedebugram
(
	.clock_a(clk_24),
	.address_a(spritedebugram_addr_a),
	.wren_a(spritedebugram_wr_a),
	.data_a(spritedebugram_data_in_a),
	.q_a(spritedebugram_data_out_a),

	.clock_b(clk_24),
	.address_b(spritedebugram_addr_b),
	.wren_b(spritedebugram_wr_b),
	.data_b(spritedebugram_data_in_b),
	.q_b(spritedebugram_data_out_b)
);
`endif

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

// Palette ROM - 0x10000 - 0x10040 (0x0100 / 256 bytes)
dpram_w1r2 #(8,8, "palette.hex") palrom
(
	.clock_a(clk_24),
	.address_a(dn_addr[7:0]),
	.wren_a(palrom_wr),
	.data_a(dn_data),

	.clock_b(clk_24),
	.address_b(palrom_addr),
	.q_b(palrom_data_out)
);

// Sprite ROM - 0x11000 - 0x11800 (0x1000 / 4096 bytes)
dpram #(14,8, "sprite.hex") spriterom
(
	.clock_a(clk_24),
	.address_a(sprom_addr),
	.wren_a(1'b0),
	.data_a(),
	.q_a(spriterom_data_out),

	.clock_b(clk_24),
	.address_b(dn_addr[13:0]),
	.wren_b(spriterom_wr),
	.data_b(dn_data),
	.q_b()
);

`ifndef DISABLE_MUSIC
// Music ROM - 128kB
dpram #(MUSIC_ROM_WIDTH,8, "music.hex") musicrom
(
	.clock_a(clk_24),
	.address_a(musicrom_addr),
	.wren_a(1'b0),
	.data_a(),
	.q_a(musicrom_data_out),

	.clock_b(clk_24),
	.address_b(dn_addr[MUSIC_ROM_WIDTH-1:0]),
	.wren_b(musicrom_wr),
	.data_b(dn_data),
	.q_b()
);
`endif

`ifndef DISABLE_SOUND
// Sound ROM - 64kB
dpram #(SOUND_ROM_WIDTH,8, "sound.hex") soundrom
(
	.clock_a(clk_24),
	.address_a(soundrom_addr),
	.wren_a(1'b0),
	.data_a(),
	.q_a(soundrom_data_out),

	.clock_b(clk_24),
	.address_b(dn_addr[SOUND_ROM_WIDTH-1:0]),
	.wren_b(soundrom_wr),
	.data_b(dn_data),
	.q_b()
);
`endif


endmodule
