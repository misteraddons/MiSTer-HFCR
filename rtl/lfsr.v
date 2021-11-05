module lfsr #(
    parameter LEN=8,                  // shift register length
    parameter TAPS=8'b10111000,       // XOR taps
    parameter SEED={LEN{1'b1}}        // initial seed value
    ) (
    input  wire clk,            // clock
    input  wire rst,            // reset
    input  wire en,             // enable
    output reg  [LEN-1:0] sreg  // lfsr output
    );

    always @(posedge clk) begin
        if (en) sreg <= {1'b0, sreg[LEN-1:1]} ^ (sreg[0] ? TAPS : {LEN{1'b0}});
        if (rst) sreg <= SEED;
    end
endmodule