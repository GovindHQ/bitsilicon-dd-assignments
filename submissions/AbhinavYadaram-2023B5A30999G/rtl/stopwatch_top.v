`timescale 1ns / 1ps


module stopwatch_top (
    input wire clk,
    input wire rst_n,    // active-low system reset
    input wire start,
    input wire stop,
    input wire reset,    // stopwatch reset button
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status // 00-IDLE, 01-RUNNING, 10-PAUSED
);

    // Internal Signals
    wire enable_counting; // From FSM to Seconds
    wire clear_counters;  // From FSM to both counters
    wire seconds_overflow;// From Seconds to Minutes

    // 1. Control FSM Instance
    control_fsm fsm_inst (
        .clk(clk),.rst_n(rst_n),.start(start),.stop(stop),.reset_btn(reset),.count_enable(enable_counting),.clear_time(clear_counters),.status(status));
        
        
     // 2. Seconds Counter Instance
    seconds_counter sec_inst (
        .clk(clk),.rst_n(rst_n),.clear(clear_counters),.enable(enable_counting), .sec_count(seconds),.sec_ovf(seconds_overflow));
    
    // 3. Minutes Counter Instance (  Enabled only when global enable is ON AND seconds overflowed)
   
    minutes_counter min_inst (
        .clk(clk),.rst_n(rst_n), .clear(clear_counters),.enable(seconds_overflow),.min_count(minutes));

endmodule