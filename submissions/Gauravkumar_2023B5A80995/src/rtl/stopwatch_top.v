module stopwatch_top (
    input  wire clk,
    input  wire rst_n,
    input  wire start,
    input  wire stop,
    input  wire reset,
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status
);

wire count_en;
wire sec_rollover;

control_fsm u_fsm (
    .clk(clk),
    .rst_n(rst_n),
    .start(start),
    .stop(stop),
    .reset(reset),
    .state(status),
    .count_en(count_en)
);

seconds_counter u_sec (
    .clk(clk),
    .rst_n(rst_n),
    .enable(count_en),
    .seconds(seconds),
    .rollover(sec_rollover)
);

minutes_counter u_min (
    .clk(clk),
    .rst_n(rst_n),
    .enable(sec_rollover),
    .minutes(minutes)
);

endmodule
