module control_fsm (
	input  wire	clk,
    	input  wire	rst_n,
    	input  wire	start,
    	input  wire	stop,
    	input  wire	reset,
    	output reg 	run_enable,
    	output reg  [1:0] status
);

	localparam IDLE    = 2'b00;
	localparam RUNNING = 2'b01;
	localparam PAUSED  = 2'b10;

	reg [1:0] state, next_st;

	always @(posedge clk or negedge rst_n) begin
		if (!rst_n)
			state <= IDLE;
		else 
			state <= next_st;
	end

	always @(*) begin
		next_st = state;

		case (state)
			IDLE: begin
				if (start)
					next_st = RUNNING;
			end

			RUNNING: begin
				if (stop)
					next_st = PAUSED;
				else if (reset)
					next_st = IDLE;
			end
	
			PAUSED: begin 
				if (start)
					next_st = RUNNING;
				else if (reset)
					next_st = IDLE;
			end

            		default: begin  
				next_st = IDLE;
            		end
		endcase
	end

	always @(*) begin
		run_enable = (state == RUNNING);
		status = state;
	end
endmodule
