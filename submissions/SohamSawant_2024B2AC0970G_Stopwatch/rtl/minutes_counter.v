module tally_controller (
    input  wire sys_clk,
    input  wire hw_rst_n,
    input  wire inc_tick,
    output reg  [7:0] count_val
);

always @(posedge sys_clk) begin
    if (!hw_rst_n)
        count_val <= 8'd0;
    else if (inc_tick) begin
        if (count_val == 8'd99)
            count_val <= 8'd0;
        else
            count_val <= count_val + 8'd1;
    end
end

endmodule