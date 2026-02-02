`timescale 1ns / 1ps

module tb_stopwatch;

// Testbench signals
reg clk;
reg rst_n;
reg start;
reg stop;
reg reset;
wire [7:0] minutes;
wire [5:0] seconds;
wire [1:0] status;

// Instantiate the DUT
stopwatch_top dut (
    .clk(clk),
    .rst_n(rst_n),
    .start(start),
    .stop(stop),
    .reset(reset),
    .minutes(minutes),
    .seconds(seconds),
    .status(status)
);

// Clock generation (assume 1Hz for simplicity, 1 second per cycle)
initial begin
    clk = 0;
    forever #500000000 clk = ~clk;  // 1 Hz clock (500ms high, 500ms low)
end

// Test sequence
initial begin
    // Initialize
    rst_n = 0;
    start = 0;
    stop = 0;
    reset = 0;
    #1000000000;  // Wait 1 second
    rst_n = 1;
    #1000000000;  // Wait 1 second

    // Start the stopwatch
    start = 1;
    #1000000000;  // Wait 1 second
    start = 0;

    // Let it run for a few seconds
    #5000000000;  // Wait 5 seconds

    // Stop
    stop = 1;
    #1000000000;  // Wait 1 second
    stop = 0;

    // Wait
    #2000000000;  // Wait 2 seconds

    // Start again
    start = 1;
    #1000000000;  // Wait 1 second
    start = 0;

    // Let it run to rollover
    #60000000000;  // Wait 60 seconds

    // Reset
    reset = 1;
    #1000000000;  // Wait 1 second
    reset = 0;

    // Finish simulation
    #1000000000;
    $finish;
end

// Monitor outputs
initial begin
    $monitor("Time: %t, Status: %b, Minutes: %d, Seconds: %d", $time, status, minutes, seconds);
end

endmodule