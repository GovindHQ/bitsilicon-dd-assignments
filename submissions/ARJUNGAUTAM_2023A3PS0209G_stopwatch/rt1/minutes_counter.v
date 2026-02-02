module minutes_counter (
    input wire clk,
    input wire rst_n,   // Active-low reset
    input wire reset,
    input wire enable,  // Enable increment when seconds rollover
    output reg [7:0] minutes  // 0-255 minutes
);

// Counter logic
always @(posedge clk or negedge rst_n) begin
    if (!rst_n || reset) begin
        minutes <= 8'd0;
    end else if (enable) begin
        minutes <= minutes + 1'b1;
    end
end

endmodule