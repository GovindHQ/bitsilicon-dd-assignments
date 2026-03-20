module minutes_counter (
    input  wire clk,
    input  wire rst_n,
    input  wire enable,
    output reg  [7:0] minutes
);

always @(posedge clk) begin
    if (!rst_n) begin
        minutes <= 8'd0;
    end else if (enable) begin
        if (minutes == 8'd99)
            minutes <= 8'd0;
        else
            minutes <= minutes + 8'd1;
    end
end

endmodule
