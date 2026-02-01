
module stopwatch_top (
    input  wire       clk,
    input  wire       rst_n,   // active-low reset
    input  wire       start,
    input  wire       stop,
    input  wire       reset,
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status   // 00=IDLE, 01=RUNNING, 10=PAUSED
);

    // Internal connections
    wire fsm_count_en;
    wire fsm_clear;
    wire sec_overflow_tick;

    // ------------------------------------------------------------
    // 1. Control FSM
    // ------------------------------------------------------------
    control_fsm u_control_fsm (
        .clk        (clk),
        .rst_n      (rst_n),
        .start      (start),
        .stop       (stop),
        .reset      (reset),
        .count_en   (fsm_count_en),
        .clear      (fsm_clear),
        .status     (status)
    );

    // ------------------------------------------------------------
    // 2. Seconds Counter (0-59)
    // ------------------------------------------------------------
    seconds_counter u_seconds_counter (
        .clk        (clk),
        .rst_n      (rst_n),
        .enable     (fsm_count_en),
        .clear      (fsm_clear),
        .seconds    (seconds),
        .sec_tick   (sec_overflow_tick) // Connects to Minutes enable
    );

    // ------------------------------------------------------------
    // 3. Minutes Counter (0-99)
    // ------------------------------------------------------------
    minutes_counter u_minutes_counter (
        .clk        (clk),
        .rst_n      (rst_n),
        .enable     (sec_overflow_tick), // Only counts when seconds overflow
        .clear      (fsm_clear),
        .minutes    (minutes)
    );

endmodule
