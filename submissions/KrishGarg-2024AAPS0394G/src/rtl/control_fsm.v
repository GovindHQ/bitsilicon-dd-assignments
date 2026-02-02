module control_fsm(
input clk,rst,start,stop,reset, 
output reg [1:0] status,
output reg sec_en
);
localparam IDLE = 2'b00, RUNNING = 2'b01, PAUSED = 2'b10;
reg[1:0] next_state;
always@(posedge clk, negedge rst)
begin
  if(!rst || reset) status <= IDLE;
  else status <= next_state;
end

always @(*) 
begin
    next_state = status;
    case(status)
	IDLE: begin
	  if(start)
	    next_state = RUNNING;
	end
	RUNNING: begin
	  if(stop)
	    next_state = PAUSED;
	end
	PAUSED: begin
	  if(start)
	    next_state = RUNNING;
	end
	default:
	  next_state = IDLE;
    endcase
  end

always @(*)
begin
  if(status == RUNNING || start)
    sec_en = 1'b1;
  else 
    sec_en = 1'b0;
end
endmodule
