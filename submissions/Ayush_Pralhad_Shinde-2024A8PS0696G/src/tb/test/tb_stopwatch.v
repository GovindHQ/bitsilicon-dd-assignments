`timescale 1ns / 1ps

module tb_stopwatch;

    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;

    wire [6:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

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

    initial begin
        clk = 0;
        forever #10 clk = ~clk;
    end

    initial begin
        $display("Time\t\t Reset Start Stop | Status | Time Output");
        $display("---------------------------------------------------------");
        $monitor("%0t\t %b     %b     %b    |   %b   | %0d:%02d", 
                 $time, rst_n, start, stop, status, minutes, seconds);
    end

    initial begin
        rst_n = 0; start = 0; stop = 0; reset = 0;
        #20;
        rst_n = 1; 
        #10;

        start = 1; #20; start = 0;
        #69; 

        stop = 1; #20; stop = 0;
        #17;

        start = 1; #20; start = 0;
        #31;

        stop = 1; #20; stop = 0;
        #67;
        //just becoz 67 meme

        stop = 1; #20; stop = 0; 
        reset = 1; 
        #18; 
        reset = 0;
        #10;

/*
        start = 1; #20; start = 0;
        //This is max. time test
        //Run this case if you have free time to check max time of this stopwatch :)
        // 99 minutes = 99 * 60 seconds = 5940 seconds.
        // Total delay needed = 5940 * 10,000 = 59,400,000ns soo I am using delay of 60 million.

        #60000000; 

        stop = 1; #20; stop = 0;
*/
        $finish;
    end

endmodule