module seconds_counter (
    input wire clk,
    input wire rst_n,   // Active-low reset
    input wire reset,
    input wire enable,  // Enable counting when running
    output reg [5:0] seconds,  // 0-59
    output reg rollover  // Signal to increment minutes
);

// Counter logic
always @(posedge clk or negedge rst_n) begin
    if (!rst_n || reset) begin
        seconds <= 6'd0;
        rollover <= 1'b0;
    end else if (enable) begin
        if (seconds == 6'd59) begin
            seconds <= 6'd0;
            rollover <= 1'b1;
        end else begin
            seconds <= seconds + 1'b1;
            rollover <= 1'b0;
        end
    end else begin
        rollover <= 1'b0;
    end
end

endmodule