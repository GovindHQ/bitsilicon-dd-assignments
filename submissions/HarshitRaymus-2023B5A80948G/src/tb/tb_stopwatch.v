`timescale 1ns/1ps

module tb_stopwatch;

    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;

    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

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

    // clock: 10 ns period
    always #5 clk = ~clk;

    initial begin
        clk   = 0;
        rst_n = 0;
        start = 0;
        stop  = 0;
        reset = 0;

        // power-up reset
        #20;
        rst_n = 1;

        // start
        #10 start = 1;
        #10 start = 0;

        // run

        // pause
        #10 stop = 1;
        #10 stop = 0;

        // resume
        #10 start = 1;
        #10 start = 0;

        // user reset
        #10 reset = 1;
        #10 reset = 0;

        #50;
        $finish;
    end

endmodule
