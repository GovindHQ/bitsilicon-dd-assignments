`timescale 1ns/1ps

module tb_stopwatch;

    reg clk = 0;
    reg rst_n = 0;
    reg start = 0;
    reg stop = 0;
    reg reset = 0;

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

    always #5 clk = ~clk;

    initial begin
        #10 rst_n = 1;
        #10 start = 1;
        #10 start = 0;

        repeat (70) begin
            @(posedge clk);
            $display("TIME = %0d:%0d STATUS=%b", minutes, seconds, status);
        end

        stop = 1; #10 stop = 0;
        #50;

        start = 1; #10 start = 0;
        repeat (20) @(posedge clk);

        reset = 1; #10 reset = 0;
        #20 $finish;
    end

endmodule
