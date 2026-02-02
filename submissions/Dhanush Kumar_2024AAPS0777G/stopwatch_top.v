module stopwatch_top (
    input  wire clk,
    input  wire rst_n,
    input  wire start,
    input  wire stop,
    input  wire reset,
    output wire [5:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status
);
wire enable_count;
    wire sec_rollover;

    // Control FSM
    control_fsm u_control_fsm (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .enable_count(enable_count),
        .status(status)
    );

    // Seconds counter
    seconds_counter u_seconds (
        .clk(clk),
        .rst_n(rst_n),
        .enable(enable_count),
        .seconds(seconds),
        .rollover(sec_rollover)
    );

    // Minutes counter
    minutes_counter u_minutes (
        .clk(clk),
        .rst_n(rst_n),
        .sec_rollover(sec_rollover),
        .minutes(minutes)
    );

endmodule
