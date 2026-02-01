// seconds_counter.v
// Synchronous up-counter for seconds (0-59)
module seconds_counter (
    input wire clk,
    input wire rst_n,       // active-low reset
    input wire enable,      // count enable
    input wire clear,       // synchronous clear
    output reg [5:0] count, // 0-59 seconds
    output reg overflow     // pulse when rolling over from 59 to 0
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            count <= 6'd0;
        end else if (clear) begin
            count <= 6'd0;
        end else if (enable) begin
            if (count == 6'd59) begin
                count <= 6'd0;
            end else begin
                count <= count + 1'b1;
            end
        end
    end

    // Overflow is combinational - asserted when at 59 and enabled
    always @(*) begin
        overflow = (count == 6'd59) && enable;
    end
endmodule
