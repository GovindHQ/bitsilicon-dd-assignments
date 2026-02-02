module test_bench_main;

reg tb_clk = 0;
reg tb_rst_n = 0;
reg tb_run = 0;
reg tb_halt = 0;
reg tb_soft_rst = 0;

wire [7:0] tb_min_out;
wire [5:0] tb_sec_out;
wire [1:0] tb_fsm_status;

always #5 tb_clk = ~tb_clk;

chronometer_main u_system_under_test (
    .i_sys_clk(tb_clk),
    .i_hw_reset_n(tb_rst_n),
    .i_cmd_start(tb_run),
    .i_cmd_stop(tb_halt),
    .i_cmd_reset(tb_soft_rst),
    .o_val_min(tb_min_out),
    .o_val_sec(tb_sec_out),
    .o_fsm_state(tb_fsm_status)
);

initial begin
    tb_rst_n = 0;
    #20 tb_rst_n = 1;

    tb_run = 1; #10 tb_run = 0;
    #300;

    tb_halt = 1; #10 tb_halt = 0;
    #100;

    tb_run = 1; #10 tb_run = 0;
    #100;

    tb_soft_rst = 1; #10 tb_soft_rst = 0;
    #50;

    $finish;
end

endmodule