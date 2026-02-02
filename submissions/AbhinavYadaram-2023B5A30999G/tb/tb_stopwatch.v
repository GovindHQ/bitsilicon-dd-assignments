`timescale 1ns / 1ps


module tb_stopwatch();
    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;
    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    // Instantiate Top Level
    stopwatch_top uut (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .minutes(minutes),
        .seconds(seconds),
        .status(status)
    );

    // Clock Generation (100MHz equivalent)
    always #5 clk = ~clk;

    initial begin
        // Initialize Inputs
        clk = 0;
        rst_n = 0; // Assert System Reset
        start = 0;
        stop = 0;
        reset = 0;

        // Wait 20ns and release system reset
        #20;
        rst_n = 1; 

        // 1. Test Start
        #10 start = 1; // Press start
        #10 start = 0; // Release start button
        
        // Wait for some time to see counting
        #500; 

        // 2. Test Stop (Pause)
        #10 stop = 1;
        #10 stop = 0;
        
        #100; // Observe that values don't change

        // 3. Test Resume
        #10 start = 1;
        #10 start = 0;
        
        #200;

        // 4. Test Reset Logic
        #10 reset = 1; // Press reset
        #10 reset = 0;

        #100;
        //5.Back on
        #10 start=1;
        #10 start=0;
        
        #200;
        //5.testing global reset
        #10 rst_n=0;
        #10 rst_n=1;
        #200;
        start=1;
        #10 start=0;
        #100;
        $finish;
    end
endmodule

