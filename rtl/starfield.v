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
    parameter [LEN-1:0] H=800,
    parameter [LEN-1:0] V=525,
    parameter LEN=25,
    parameter TAPS=25'b1010000000000000000000000,
    parameter SEED=25'b1111111111111110000000000,
    parameter MASK=25'b1111111111111111111111111
    ) (
    input  wire         clk,
    input  wire         en,
    input  wire         pause,
    input  wire         rst,
    input  wire         vblank,
    input  wire         addr,   // Write address - 0 = speed, 1 = enable
    input  wire [7:0]   data_in,
    input  wire         write,
    output wire         sf_on,  // star on (alpha)
    output wire [7:0]   sf_star // star brightness
    );

    reg  [LEN-1:0] RST_CNT;  // counter starts at zero, so sub 1
    reg  [LEN-1:0] seed;
    reg   [7:0]    speed_set;
    reg   [4:0]    increment;    
    reg   [7:0]    timer;
    wire [LEN-1:0] sf_reg;
    reg  [LEN-1:0] sf_cnt;
    reg            enabled;
    wire [7:0]     speed_actual = pause ? 8'b0 : speed_set;

    always @(posedge clk) 
    begin

        // Reset seed
        if(rst)
        begin
            seed <= SEED;
        end

        // CPU write
        if(write)
        begin
            case(addr)
                1'b0:
                begin
                    speed_set <= data_in[7:0];
                end
                1'b1:
                begin
                    enabled <= data_in[0];
                end
            endcase
        end

        if (en)
        begin
            sf_cnt <= sf_cnt + 1'b1;
            /* verilator lint_off WIDTH */
            if (sf_cnt == RST_CNT) 
            begin
                if(speed_actual >= 8'd8)
                begin
                    // If speed_actual is 8 or above, use the speed_actual directly as an increment multiplier
                    increment = speed_actual[7:3];
                end
                else
                begin
                    // If speed_actual is less than 8, increment a timer by that speed_actual
                    timer <= timer + speed_actual;
                    if (timer == 0)
                    begin
                        // If timer is zero then increment is low
                        increment = 0;
                    end
                    else
                    begin
                        if (timer >= 8'd8)
                        begin
                            // If timer is 8 or over then set increment high (lasts for 1 cycle)
                            increment = 1;
                            timer <= 0;
                        end
                    end
                end
                sf_cnt <= 0;
                RST_CNT <= (H * V) + ((pause ? 5'b0 : increment) * H) - 1'b1;
            end
            /* verilator lint_on WIDTH */
        end
        if (rst) sf_cnt <= 0;
    end

    assign sf_on = &{sf_reg | MASK} & enabled;
    assign sf_star = sf_reg[7:0];

    lfsr #(
        .LEN(LEN),
        .TAPS(TAPS)
        ) lsfr_sf (
        .clk(clk),
        .rst(sf_cnt == {LEN{1'b0}} ),
        .en(en),
        .seed(seed),
        .sreg(sf_reg)
    );
endmodule