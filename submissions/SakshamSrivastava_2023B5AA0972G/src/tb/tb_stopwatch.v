module tb_stopwatch;

    reg clk = 0;
    reg rst_n = 0;
    reg start = 0;
    reg stop  = 0;
    reg reset = 0;

    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    always #5 clk = ~clk;

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

    initial begin
        #10 rst_n = 1;
        #10 start = 1; #10 start = 0;
        #200 stop = 1; #10 stop = 0;
        #50 start = 1; #10 start = 0;
        #100 reset = 1; #10 reset = 0;
        #100 $finish;
    end

endmodule
