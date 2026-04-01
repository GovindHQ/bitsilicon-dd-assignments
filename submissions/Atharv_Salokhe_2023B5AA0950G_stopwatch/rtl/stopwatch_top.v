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
 
  wire overflow;
  control_fsm fsm(
    .clk(clk),
    .rst_n(rst_n),
    .start(start),
    .stop(stop),
    .reset(reset),
    .status(status)
  );
  
  seconds_counter s_counter(
    .clk(clk),
    .rst_n(rst_n),
    .reset(reset),
    .state(status),
    .seconds(seconds),
    .overflow(overflow)
  );
  
  minutes_counter m_counter(
    .clk(clk),
    .rst_n(rst_n),
    .reset(reset),
    .state(status),
    .overflow(overflow),
    .minutes(minutes)
  );
endmodule

