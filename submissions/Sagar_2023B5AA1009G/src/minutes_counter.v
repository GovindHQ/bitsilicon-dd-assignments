module minutes_counter (
    input  wire       clk,
    input  wire       rst_n,
    input  wire       en,
    input  wire       clr,
    output reg  [7:0] count
);

    wire [7:0] t;
    assign t[0] = en;
    assign t[1] = count[0] & t[0];
    assign t[2] = count[1] & t[1];
    assign t[3] = count[2] & t[2];
    assign t[4] = count[3] & t[3];
    assign t[5] = count[4] & t[4];
    assign t[6] = count[5] & t[5];
    assign t[7] = count[6] & t[6];

    wire is_199;
    assign is_199 = (count[7] & count[6] & ~count[5] & ~count[4] & ~count[3] & count[2] & count[1] & count[0]);

    wire internal_clear;
    assign internal_clear = clr | (is_199 & en);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            count <= 8'b00000000;
        end else if (internal_clear) begin
            count <= 8'b00000000;
        end else begin
            count[0] <= count[0] ^ t[0];
            count[1] <= count[1] ^ t[1];
            count[2] <= count[2] ^ t[2];
            count[3] <= count[3] ^ t[3];
            count[4] <= count[4] ^ t[4];
            count[5] <= count[5] ^ t[5];
            count[6] <= count[6] ^ t[6];
            count[7] <= count[7] ^ t[7];
        end
    end

endmodule