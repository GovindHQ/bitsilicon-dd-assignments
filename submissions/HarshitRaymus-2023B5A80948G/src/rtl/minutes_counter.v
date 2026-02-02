module minutes_counter (
    input  wire clk,
    input  wire rst_n,
    input  wire reset,
    input  wire inc,      // combinational increment request

    output reg  [7:0] minutes
);

    always @(posedge clk) begin
        if (!rst_n || reset) begin
            minutes <= 8'd0;
        end else if (inc) begin
            if (minutes == 8'd99)
                minutes <= 8'd0;
            else
                minutes <= minutes + 8'd1;
        end
    end

endmodule
