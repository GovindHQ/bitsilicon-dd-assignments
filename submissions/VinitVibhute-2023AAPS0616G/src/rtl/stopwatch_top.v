// stopwatch_top.v
// Top-level digital stopwatch controller
// Integrates FSM and counters to implement complete stopwatch functionality
// 
// Reset handling:
//   rst_n: Global asynchronous reset for hardware initialization (active-low)
//   reset: Functional reset - clears time to 00:00 and returns FSM to IDLE

module stopwatch_top (
    input wire clk,
    input wire rst_n,           // active-low asynchronous reset (global, for hardware init)
    input wire start,           // start/resume signal
    input wire stop,            // stop/pause signal
    input wire reset,           // functional reset to 00:00 and IDLE state
    output wire [7:0] minutes,  // minutes output (0-99)
    output wire [5:0] seconds,  // seconds output (0-59)
    output wire [1:0] status    // 00=IDLE, 01=RUNNING, 10=PAUSED
);

    // Internal signals
    wire count_enable;          // Enable signal from FSM to counters
    wire seconds_carry;         // Carry signal from seconds to minutes
    wire clear_counters;        // Clear signal for counters

    // Clear counters when functional reset is asserted
    // This happens when user presses reset button to clear stopwatch
    assign clear_counters = reset;

    // Instantiate control FSM
    control_fsm fsm_inst (
        .clk(clk),
        .rst_n(rst_n),          // Global reset
        .start(start),
        .stop(stop),
        .reset(reset),          // Functional reset
        .count_enable(count_enable),
        .status(status)
    );

    // Instantiate seconds counter
    seconds_counter sec_counter (
        .clk(clk),
        .rst_n(rst_n),          // Global reset
        .enable(count_enable),
        .clear(clear_counters), // Functional clear
        .seconds(seconds),
        .carry_out(seconds_carry)
    );

    // Instantiate minutes counter
    minutes_counter min_counter (
        .clk(clk),
        .rst_n(rst_n),          // Global reset
        .enable(count_enable),
        .clear(clear_counters), // Functional clear
        .carry_in(seconds_carry),
        .minutes(minutes)
    );

endmodule