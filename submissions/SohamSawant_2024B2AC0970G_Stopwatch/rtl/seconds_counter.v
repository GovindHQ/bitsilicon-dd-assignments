module time_unit_logic (
    input  wire m_clk,
    input  wire a_rst_n,
    input  wire pulse_en,
    output reg  [5:0] q_val,
    output wire overflow_flag
);

assign overflow_flag = (pulse_en && q_val == 6'd59);

always @(posedge m_clk) begin
    if (!a_rst_n)
        q_val <= 6'd0;
    else if (pulse_en) begin
        if (q_val == 6'd59)
            q_val <= 6'd0;
        else
            q_val <= q_val + 6'd1;
    end
end

endmodule