module stopwatch_top (
input wire clk,
input wire rst_n, // active-low reset
input wire start,
input wire stop,
input wire reset,
output wire [7:0] minutes,
output wire [5:0] seconds,
output wire [1:0] status // 00=IDLE, 01=RUNNING, 10=PAUSED
);

wire count, sec_en;
control_fsm c1 (
    .clk(clk),
    .rst(rst_n),
    .start(start),
    .stop(stop),
    .reset(reset),
    .status(status),
	.sec_en(sec_en)
);
seconds_counter s1(
	.clk(clk),
	.rst(rst_n), 
	.en(sec_en),
	.reset(reset||(status == 2'b00)),
	.seconds(seconds),
	.count(count)
);

minutes_counter m1(
	.clk(clk),
	.rst(rst_n),
	.count(count),
	.reset(reset||(status == 2'b00)),
	.minutes(minutes)
);
endmodule
