module stopwatch_top (
    input  wire clk,
    input  wire rst_n,      // active-low reset
    input  wire start,
    input  wire stop,
    input  wire reset,     // stopwatch reset
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status
);

    wire enable;
    wire sec_overflow;
    wire global_rst_n = rst_n & ~reset;

    // Control FSM
    control_fsm u_fsm (
        .clk    (clk),
        .rst_n  (rst_n),
        .start  (start),
        .stop   (stop),
        .reset  (reset),
        .enable (enable),
        .status (status)
    );

    // Seconds counter
    seconds_counter u_sec (
        .clk         (clk),
        .rst_n       (global_rst_n),
        .enable      (enable),
        .seconds     (seconds),
        .sec_overflow(sec_overflow)
    );

    // Minutes counter
    minutes_counter u_min (
        .clk         (clk),
        .rst_n       (global_rst_n),
        .enable      (enable),
        .sec_overflow(sec_overflow),
        .minutes     (minutes)
    );

endmodule
