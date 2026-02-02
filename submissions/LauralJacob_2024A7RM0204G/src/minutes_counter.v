module minutes_counter (
    input  wire clk,
    input  wire rst_n,
    input  wire enable,
    input  wire sec_tick,
    output reg  [7:0] minutes
);

    always @(posedge clk) begin
        if (!rst_n)
            minutes <= 8'd0;
        else if (enable && sec_tick) begin
            if (minutes == 8'd99)
                minutes <= 8'd0;
            else
                minutes <= minutes + 8'd1;
        end
    end

endmodule
