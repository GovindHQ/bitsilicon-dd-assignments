
module seconds_counter(
  	input wire clk,
	input wire rst_n,
	input wire reset,
  input wire [1:0] state,
  	output reg [5:0] seconds,
	output reg overflow);
  
  always @ (posedge clk) begin 
    if (!rst_n) seconds <= 6'd0;
    if (reset) seconds <= 6'd0;
    else if (state == 2'b01) begin 
      	if (seconds == 6'd59) begin 
        	seconds <= 0; 
          	overflow <= 1'b1;
      	end
      	else begin 
          seconds <= seconds + 1'b1; 
          overflow <= 1'b0;
        end
    end
  end
  
endmodule
