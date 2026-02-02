module minutes_counter (
    input  wire clk,
    input  wire rst_n,
    input  wire sec_rollover,
    output reg  [5:0] minutes
);

always @(posedge clk) begin
    if (!rst_n) begin
        minutes <= 6'd0;
    end
    else if (sec_rollover) begin
        if (minutes == 6'd59)
            minutes <= 6'd0;
        else
            minutes <= minutes + 6'd1;
    end
end

endmodule
