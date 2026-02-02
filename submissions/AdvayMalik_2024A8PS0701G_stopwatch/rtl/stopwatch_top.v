module stopwatch_top (
    input  wire clk,
    input  wire rst_n,
    input  wire start,
    input  wire stop,
    input  wire reset,
    output wire [6:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] current_state
);

    wire enable_count;
    wire min_increment;

    control_fsm u_fsm (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .enable_count(enable_count),
        .current_state(current_state)
    );

    seconds_counter u_sec (
        .clk(clk),
        .rst_n(rst_n),
        .enable(enable_count),
        .seconds(seconds),
        .increment(min_increment)
    );

    minutes_counter u_min (
        .clk(clk),
        .rst_n(rst_n),
        .enable(min_increment),
        .minutes(minutes)
    );

endmodule
