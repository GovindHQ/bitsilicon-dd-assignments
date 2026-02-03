module stopwatch_top (
    input wire clk,
    input wire rst_n,    
    input wire start,
    input wire stop,
    input wire reset,
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status
);

    wire w_en;
    wire w_clr;
    wire w_sec_incr;

    
    control_fsm u_fsm (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .state(status),
        .count_en(w_en),
        .clear_counters(w_clr)
    );

    
    seconds_counter u_sec (
        .clk(clk),
        .rst_n(rst_n),
        .en(w_en),
        .clr(w_clr),
        .count(seconds),
        .next(w_sec_incr)
    );

    
    minutes_counter u_min (
        .clk(clk),
        .rst_n(rst_n),
        .en(w_en),
        .clr(w_clr),
        .incr(w_sec_incr),
        .count(minutes)
    );

endmodule
