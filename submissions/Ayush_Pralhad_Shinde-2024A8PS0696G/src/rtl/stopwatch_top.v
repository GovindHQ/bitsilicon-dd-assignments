module stopwatch_top (
input wire clk, rst_n, start, stop, reset,
output wire [6:0] minutes,
output wire [5:0] seconds,
output wire [1:0] status
);

wire stopwatch_start;
wire minute_completed;

    control_fsm fsm_inst (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .status(status),
        .c_enable(stopwatch_start)
    );

    seconds_counter sec_inst (
        .clk(clk),
        .rst_n(rst_n),
        .enable(stopwatch_start),
        .seconds(seconds),
        .done(minute_completed),
        .clear(reset)
    );

    minutes_counter min_inst (
        .clk(clk),
        .rst_n(rst_n),
        .enable(minute_completed),
        .minutes(minutes),
        // .done(),
        .clear(reset)
    );

endmodule