
module control_fsm(
  	input wire clk,
	input wire rst_n, // active-low reset
	input wire start,
	input wire stop,
	input wire reset,
	output reg [1:0] status 
);
  
  parameter idle = 2'b00;
  parameter running = 2'b01;
  parameter paused = 2'b10;
  
  reg [1:0] next_state;
  
  always @ (posedge clk) begin 
    if (!rst_n) status <= idle;
    else status <= next_state;
  end
  
  always @ (*) begin 
    next_state = status;
    case(status)
      idle: begin 
        		if (start) next_state = running;
      		end
      
      running: begin 
        if (stop) next_state = paused; 
        else if (reset) next_state = idle;
      		end
      
      paused: begin 
        if(start) next_state = running;
        else if (reset) next_state = idle;
      end
      
      default: next_state = idle;
      
    endcase
    
  end
  
endmodule
