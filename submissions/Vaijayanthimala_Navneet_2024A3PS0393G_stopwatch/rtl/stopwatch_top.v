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

    wire count_en;
    wire sec_done;

    // FSM instance
    control_fsm fsm (
        .clk(clk), .rst_n(rst_n), .start(start), 
        .stop(stop), .reset(reset), .state_out(status), .count_en(count_en)
    );

    // Seconds counter
    seconds_counter sec_cnt (
        .clk(clk), .rst_n(rst_n), .reset(reset), 
        .en(count_en), .count(seconds), .rollover(sec_done)
    );

    // Minutes counter
    minutes_counter min_cnt (
        .clk(clk), .rst_n(rst_n), .reset(reset), 
        .en(sec_done), .count(minutes)
    );

endmodule