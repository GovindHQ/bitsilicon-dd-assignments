//PSEUDOCODE
//if state == IDLE:
//	if start:
//		next_state = RUNNING
//else if state==RUNNING:
//	if pause:
//		next_state = PAUSED
//	else if reset:
//		next_state = IDLE
//else state == PAUSED:
	//if start:
	//	next_state = RUNNING
	//else if reset:
		//next_state = IDLE

module control_fsm(
    input  wire clk,
    input  wire rst_n,
    input  wire start,
    input  wire stop,
    input  wire reset,
    output reg  enable,
    output reg [1:0] status
);

    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] state, next_state;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= IDLE;
        else
            state <= next_state;
    end

    always @(*) begin
        case (state)

            IDLE: begin
                if (reset)
                    next_state = IDLE;
                else if (start)
                    next_state = RUNNING;
                else
                    next_state = IDLE;
            end

            RUNNING: begin
                if (reset)
                    next_state = IDLE;
                else if (stop)
                    next_state = PAUSED;
                else
                    next_state = RUNNING;
            end

            PAUSED: begin
                if (reset)
                    next_state = IDLE;
                else if (start)
                    next_state = RUNNING;
                else
                    next_state = PAUSED;
            end

            default: next_state = IDLE;
        endcase
    end

    always @(*) begin
        status = state;

        if (state == RUNNING)
            enable = 1'b1;
        else
            enable = 1'b0;
    end

endmodule
