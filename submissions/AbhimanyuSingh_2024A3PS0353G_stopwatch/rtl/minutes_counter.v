module minutes_counter(
    input wire clk,
    input wire rst_n,
    input wire enable,
    input wire rollover,
    output reg [7:0] minutes
);

always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        minutes <= 0;
    end
    else if (enable && rollover) begin
        if (minutes == 8'd99)
            minutes <= 0;
        else
            minutes <= minutes + 1;
    end
    else begin
        minutes <= minutes;   // hold
    end
end

endmodule
