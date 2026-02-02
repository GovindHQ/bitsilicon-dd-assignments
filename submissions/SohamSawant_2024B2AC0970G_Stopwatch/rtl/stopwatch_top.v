module stopwatch_top (
    input  wire clk,
    input  wire rst_n,     // active-low reset
    input  wire start,
    input  wire stop,
    input  wire reset,
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status // 00=IDLE, 01=RUNNING, 10=PAUSED
);

wire count_enable;
wire sec_rollover;

control_fsm u_control_fsm (
    .clk(clk),
    .rst_n(rst_n),
    .start(start),
    .stop(stop),
    .reset(reset),
    .count_enable(count_enable),
    .state(status)
);

seconds_counter u_seconds_counter (
    .clk(clk),
    .rst_n(rst_n),
    .enable(count_enable),
    .seconds(seconds),
    .rollover(sec_rollover)
);

minutes_counter u_minutes_counter (
    .clk(clk),
    .rst_n(rst_n),
    .enable(sec_rollover),
    .minutes(minutes)
);

endmodule
