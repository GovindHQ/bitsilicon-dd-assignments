//The comments have been made after understanding the whole code although it is written with the help of artificial intelligence
// and the comments are solely made by the user and not artificial intelligence

`timescale 1ns/1ps //simulation time is set to 1 nanosecond and precision is set to 1 (1ps)
//every delay is multiplied by the timescale (here 1 nanosecond)
module tb_stopwatch();
    reg clk, rst_n, start, stop, reset;
    wire [7:0] mins;
    wire [5:0] secs;
    wire [1:0] stat;

    stopwatch_top dut (clk, rst_n, start, stop, reset, mins, secs, stat); //dut is the device under test to connect our modules to signals in testbench

    always #5 clk = ~clk; //creates a delay of 5 nanoseconds every cycle...so timeperiod is 10ns

    initial begin
        clk = 0; rst_n = 0; start = 0; stop = 0; reset = 0;//instantiate everything to 0 at the beginning
        #20 rst_n = 1;    //hardware reset after 20ns
        #10 start = 1; #10 start = 0;     // Start
        # 200 stop = 1; #10 stop = 0;     // Pause
        #50 reset = 1; #10 reset = 0;     // Reset
        #50 $finish;
    end
endmodule