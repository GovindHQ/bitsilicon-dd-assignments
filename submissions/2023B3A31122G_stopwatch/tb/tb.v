`timescale 1ns/1ps

module tb_stopwatch();
    // Inputs 
    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;

    // Outputs 
    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    // Instantiate the Top Level Module
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

    // Generate clock, toggles every 5 units
    always #5 clk = ~clk;

    initial begin
        // Setup for GTKWave
        $dumpfile("stopwatch_sim.vcd");
        $dumpvars(0, tb_stopwatch);

        // Initialising inputs
        clk = 0;
        rst_n = 0;   // Hardware reset active
        start = 0;
        stop = 0;
        reset = 0;

        //Release hardware reset
        #20 rst_n = 1;
        
        // Testing the START button (Pulse for 1 cycle)
        #20 start = 1; #10 start = 0;
        $display("Status: RUNNING. Waiting for seconds to count...");

        // Wait to see several seconds 
        #1000; 

        //Testing the STOP/PAUSE button
        #20 stop = 1; #10 stop = 0;
        $display("Status: PAUSED. Checking if time is retained...");
        #100;

        // Testing the RESUME button
        #20 start = 1; #10 start = 0;
        #100;

        // Testing the RESET Button
        #20 reset = 1; #10 reset = 0;
        $display("Status: IDLE. Time should be 00:00.");

        #100;
        $finish;
    end
endmodule