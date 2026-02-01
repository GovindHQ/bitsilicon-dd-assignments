// stopwatch_top.v
// Top-level module for digital stopwatch controller
module stopwatch_top (
    input wire clk,
    input wire rst_n,       // active-low reset
    input wire start,       // start signal
    input wire stop,        // stop/pause signal
    input wire reset,       // reset signal
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status // 00=IDLE, 01=RUNNING, 10=PAUSED
);

    // Internal signals
    wire enable;            // enable signal from FSM
    wire sec_overflow;      // overflow from seconds counter
    wire clear_counters;    // clear signal for counters

    // Clear counters when reset is asserted
    assign clear_counters = reset;

    // Instantiate control FSM
    control_fsm fsm (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .enable(enable),
        .status(status)
    );

    // Instantiate seconds counter
    seconds_counter sec_cnt (
        .clk(clk),
        .rst_n(rst_n),
        .enable(enable),
        .clear(clear_counters),
        .count(seconds),
        .overflow(sec_overflow)
    );

    // Instantiate minutes counter
    // Minutes increment only when seconds overflow AND counting is enabled
    minutes_counter min_cnt (
        .clk(clk),
        .rst_n(rst_n),
        .o_enable(sec_overflow & enable),
        .clear(clear_counters),
        .count(minutes)
    );

endmodule
