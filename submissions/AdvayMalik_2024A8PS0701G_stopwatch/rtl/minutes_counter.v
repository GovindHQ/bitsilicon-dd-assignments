module minutes_counter (
    input wire clk,
    input wire rst_n,
    input wire enable,
    output reg [6:0] minutes
);

    always @(posedge clk) begin
        if (!rst_n) begin
            minutes <= 7'd0;
        end else if (enable) begin
            if (minutes == 7'd99) begin
                minutes <= 7'd0;
            end else if (enable) begin
                minutes <= minutes + 7'd1;
            end
        end
    end

endmodule
