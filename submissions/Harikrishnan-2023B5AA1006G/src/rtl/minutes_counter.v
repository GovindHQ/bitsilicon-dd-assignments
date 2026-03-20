// minutes_counter.v
module minutes_counter (
    input wire clk,
    input wire rst_n,       // active-low reset async
    input wire o_enable,      // count o_enable (triggered by seconds overflow)
    input wire clear,       // synchronous clear
    output reg [7:0] count  // 0-99 minutes (can represent up to 255)
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            count <= 8'd0;
        end else if (clear) begin
            count <= 8'd0;
        end else if (o_enable) begin
            if (count == 8'd99) begin
                count <= 8'd0;  // roll over at 99
            end else begin
                count <= count + 1'b1;
            end
        end
    end

endmodule
