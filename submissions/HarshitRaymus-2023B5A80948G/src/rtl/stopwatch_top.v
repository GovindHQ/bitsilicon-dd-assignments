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

        wire min_inc;
        assign min_inc = count_en && (seconds == 6'd59);

        control_fsm u_fsm (
            .clk(clk),
            .rst_n(rst_n),
            .start(start),
            .stop(stop),
            .reset(reset),
            .count_en(count_en),
            .status(status)
        );

        seconds_counter u_sec (
        .clk(clk),
        .rst_n(rst_n),
        .reset(reset),
        .enable(count_en),
        .seconds(seconds)
    );

    minutes_counter u_min (
        .clk(clk),
        .rst_n(rst_n),
        .reset(reset),
        .inc(min_inc),
        .minutes(minutes)
    );


    endmodule
