// tb_stopwatch.v
// Testbench for digital stopwatch controller
`timescale 1ns/1ps

module tb_stopwatch;

    // Clock period - 1 second represented as 20ns for simulation speed
    parameter CLK_PERIOD = 20;

    // DUT signals
    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;
    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    // Instantiate 
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

    // Clock generation
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    

    // Monitor
    initial begin
        $monitor("Time=%0t | Status=%s | Time=%02d:%02d", 
                 $time, status, minutes, seconds);
    end

    // Test stimulus
    initial begin
        $display(" Stopwatch Testbench Starting ");
        
        // Initialize inputs
        rst_n = 0;
        start = 0;
        stop = 0;
        reset = 0;

        // Apply reset
        #(CLK_PERIOD*2);
        rst_n = 1;
        #(CLK_PERIOD*2);

        $display("\n Test 1: Start and count for 5 seconds ");
        start = 1;
        #CLK_PERIOD;
        start = 0;
        #(CLK_PERIOD*5);

        $display("\n Test 2: Pause the stopwatch ");
        stop = 1;
        #CLK_PERIOD;
        stop = 0;
        #(CLK_PERIOD*3);

        $display("\n Test 3: Resume counting ");
        start = 1;
        #CLK_PERIOD;
        start = 0;
        #(CLK_PERIOD*5);

        $display("\n Test 4: Reset the stopwatch ");
        reset = 1;
        #CLK_PERIOD;
        reset = 0;
        #(CLK_PERIOD*2);

        $display("\n Test 5: Count to verify seconds rollover (to 1 minute) ");
        start = 1;
        #CLK_PERIOD;
        start = 0;
        #(CLK_PERIOD*70); // Count past 59 seconds to see rollover

        $display("\n Test 6: Final reset ");
        reset = 1;
        #CLK_PERIOD;
        reset = 0;
        #(CLK_PERIOD*2);

        $display("\n Testbench Complete ");
        $finish;
    end

    // Waveform dump (for GTKWave)
    initial begin
        $dumpfile("stopwatch.vcd");
        $dumpvars(0, tb_stopwatch);
    end

endmodule
