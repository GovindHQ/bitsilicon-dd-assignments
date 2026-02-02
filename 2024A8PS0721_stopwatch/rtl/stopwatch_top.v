module stopwatch_top (
    input  wire clk,
    input  wire rst_n,   
    input  wire start,
    input  wire stop,
    input  wire reset,
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status  // 00=IDLE, 01=RUNNING, 10=PAUSED
);

    wire enable_count;
    wire sec_rollover;

    control_fsm u_fsm (
        .clk          (clk),
        .rst_n        (rst_n),
        .start        (start),
        .stop         (stop),
        .reset        (reset),
        .enable_count (enable_count),
        .status       (status)
    );

    seconds_counter u_sec (
        .clk         (clk),
        .rst_n       (rst_n),
        .reset       (reset),
        .enable      (enable_count),
        .seconds     (seconds),
        .sec_rollover(sec_rollover)
    );

    minutes_counter u_min (
        .clk        (clk),
        .rst_n      (rst_n),
        .reset      (reset),
        .enable_min (sec_rollover),
        .minutes    (minutes)
    );

endmodule
