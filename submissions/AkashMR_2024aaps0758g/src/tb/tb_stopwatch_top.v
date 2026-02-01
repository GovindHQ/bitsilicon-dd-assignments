module tb_stopwatch_top;

reg clk = 0;
reg rst_n = 0;
reg start = 0;
reg stop = 0;
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
    rst_n = 0;
    #20 rst_n = 1;

    start = 1; #10 start = 0;
    #100;

    stop = 1; #10 stop = 0;
    #200;

    start = 1; #10 start = 0;
    #300;

    reset = 1; #10 reset = 0;
    #500;

    $finish;
end

endmodule
