module stopwatch_top (
	input wire clk,
	input wire rst_n,
	input wire start,
	input wire stop,
	input wire reset,
	output wire [7:0] minutes,
	output wire [5:0] seconds,
	output wire [1:0] status
);

	wire run_en;
	wire sec_min;

	control_fsm u_fsm (
		.clk	(clk),
		.rst_n	(rst_n),
		.start	(start),
		.stop	(stop),
		.reset	(reset),
        	.run_enable (run_en),
        	.status     (status)
	);

	seconds_counter u_sec (
        	.clk     (clk),
        	.rst_n   (rst_n),
        	.enable  (run_en),
        	.reset   (reset),
        	.seconds (seconds),
        	.tick    (sec_min)
	);

	minutes_counter u_min (
        	.clk     (clk),
        	.rst_n   (rst_n),
        	.enable  (sec_min),
        	.reset   (reset),
        	.minutes (minutes)
	);

endmodule
