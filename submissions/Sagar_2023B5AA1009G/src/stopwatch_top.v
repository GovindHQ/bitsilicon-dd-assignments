module stopwatch_top (
    input  wire       clk,
    input  wire       rst_n,
    input  wire       start,
    input  wire       stop,
    input  wire       reset,
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status
);

    wire count_en_sig;
    wire clear_sig;
    wire sec_rollover_sig;

    control_fsm fsm_inst (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .status(status),
        .count_en(count_en_sig),
        .clear_counters(clear_sig)
    );

    seconds_counter sec_inst (
        .clk(clk),
        .rst_n(rst_n),
        .en(count_en_sig),
        .clr(clear_sig),
        .count(seconds),
        .rollover(sec_rollover_sig)
    );

    minutes_counter min_inst (
        .clk(clk),
        .rst_n(rst_n),
        .en(sec_rollover_sig),
        .clr(clear_sig),
        .count(minutes)
    );

endmodule