module chronometer_main (
    input  wire i_sys_clk,
    input  wire i_hw_reset_n,
    input  wire i_cmd_start,
    input  wire i_cmd_stop,
    input  wire i_cmd_reset,
    output wire [7:0] o_val_min,
    output wire [5:0] o_val_sec,
    output wire [1:0] o_fsm_state
);

wire w_run_gate;
wire w_tick_overflow;

process_manager inst_fsm_ctrl (
    .i_clock(i_sys_clk),
    .i_async_rst_n(i_hw_reset_n),
    .i_trigger_run(i_cmd_start),
    .i_trigger_halt(i_cmd_stop),
    .i_soft_reset(i_cmd_reset),
    .o_enable_sig(w_run_gate),
    .r_current_state(o_fsm_state)
);

time_unit_logic inst_sec_timer (
    .m_clk(i_sys_clk),
    .a_rst_n(i_hw_reset_n && !i_cmd_reset),
    .pulse_en(w_run_gate),
    .q_val(o_val_sec),
    .overflow_flag(w_tick_overflow)
);

tally_controller inst_min_timer (
    .sys_clk(i_sys_clk),
    .hw_rst_n(i_hw_reset_n && !i_cmd_reset),
    .inc_tick(w_tick_overflow),
    .count_val(o_val_min)
);

endmodule