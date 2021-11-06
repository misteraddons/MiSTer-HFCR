/*============================================================================
	Aznable (custom 8-bit computer system) - Moroboshi (starfield)

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.0
	Date: 2021-11-06

    Based on Project F: Ad Astra - Starfield
    (C)2021 Will Green, open source hardware released under the MIT License
    Learn more at https://projectf.io

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

`default_nettype none
`timescale 1ns / 1ps

module starfield #(
    parameter H=800,
    parameter V=525,
    parameter SEED=21'h1FFFFF,
    parameter MASK=21'hFFF
    ) (
    input  wire clk,           // clock
    input  wire en,            // enable
    input  wire rst,           // reset
    input  wire [3:0] speed,   // speed
    output wire sf_on,         // star on
    output wire [7:0] sf_star  // star brightness
    );

    reg  [20:0] RST_CNT;  // counter starts at zero, so sub 1
    wire [20:0] sf_reg;
    reg  [20:0] sf_cnt;
    wire  [9:0] sf_inc;

    always @(posedge clk) begin
        if (en) begin
            sf_cnt <= sf_cnt + 1;
            /* verilator lint_off WIDTH */
            if (sf_cnt == RST_CNT) 
            begin
                sf_cnt <= 0;
                RST_CNT = (H * V) + (speed * H) - 1;
            end
            /* verilator lint_on WIDTH */
        end
        if (rst) sf_cnt <= 0;
    end

    assign sf_on = &{sf_reg | MASK};
    assign sf_star = sf_reg[7:0];

    lfsr #(
        .LEN(21),
        .TAPS(21'b101000000000000000000),
        .SEED(SEED)
        ) lsfr_sf (
        .clk(clk),
        .rst(sf_cnt == 21'b0),
        .en(en),
        .sreg(sf_reg)
    );
endmodule