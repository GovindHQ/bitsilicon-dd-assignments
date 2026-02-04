`timescale 1ns/1ps
module tb_stopwatch();
    reg clk=0, rst_n=0, start=0, stop=0, reset=0;
    wire [7:0] mins; wire [5:0] secs; wire [1:0] stat;

    stopwatch_top uut (clk, rst_n, start, stop, reset, mins, secs, stat);

    always #5 clk = ~clk;

    initial begin
        $dumpfile("stopwatch.vcd");
        $dumpvars(0, tb_stopwatch);
        
        #20 rst_n = 1;
        #20 start = 1; #10 start = 0;
        #1000 stop = 1; #10 stop = 0;
        #100 $finish;
    end
endmodule