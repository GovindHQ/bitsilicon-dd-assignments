module seconds_counter (
    input  wire       clk,
    input  wire       rst_n,
    input  wire       en,
    input  wire       clr,
    output reg  [5:0] count,
    output wire       rollover
);

    wire [5:0] t;
    assign t[0] = en;
    assign t[1] = count[0] & t[0];
    assign t[2] = count[1] & t[1];
    assign t[3] = count[2] & t[2];
    assign t[4] = count[3] & t[3];
    assign t[5] = count[4] & t[4];

    wire is_59;
    assign is_59 = (count[5] & count[4] & count[3] & ~count[2] & count[1] & count[0]);

    assign rollover = is_59 & en;

    wire internal_clear;
    assign internal_clear = clr | rollover;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            count <= 6'b000000;
        end else if (internal_clear) begin
            count <= 6'b000000;
        end else begin
            count[0] <= count[0] ^ t[0];
            count[1] <= count[1] ^ t[1];
            count[2] <= count[2] ^ t[2];
            count[3] <= count[3] ^ t[3];
            count[4] <= count[4] ^ t[4];
            count[5] <= count[5] ^ t[5];
        end
    end

endmodule