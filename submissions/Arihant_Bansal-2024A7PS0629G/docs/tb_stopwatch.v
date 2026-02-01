`timescale 1ns / 1ps

module tb_stopwatch();
    // Inputs
    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg rst;

    // Outputs
    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    // Instantiate UUT
    stopwatch_top uut (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .rst(rst),
        .minutes(minutes),
        .seconds(seconds),
        .status(status)
    );

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk;

    // Main Test Sequence
    initial begin
        // Initialize
        rst_n = 0;
        start = 0;
        stop = 0;
        rst = 0;

        // Reset Sequence
        #20 rst_n = 1;
        
        // 1. Start Stopwatch
        #20 start = 1;
        #10 start = 0;
        
        // 2. Wait to see counter movement 
        // We'll wait 120 cycles to ensure we see seconds incrementing
        repeat (120) @(posedge clk);
        
        // 3. Pause
        #20 stop = 1;
        #10 stop = 0;
        
        // 4. Synchronous Reset
        #50 rst = 1;
        #10 rst = 0;

        #100 $display("Test Complete");
        $finish;
    end

    // Waveform Generation
    initial begin
        $dumpfile("stopwatch_sim.vcd");
        $dumpvars(0, tb_stopwatch);
    end

endmodule