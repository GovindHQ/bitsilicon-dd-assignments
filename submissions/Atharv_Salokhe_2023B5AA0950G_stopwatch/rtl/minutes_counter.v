
module minutes_counter(
	input wire clk,
	input wire reset,
	input wire rst_n,
  input wire [1:0] state,
  	input wire overflow,
  output reg [7:0] minutes);
  
  always @(posedge clk) begin
    if (!rst_n) minutes <= 8'd0;
    if (reset) minutes <= 8'd0;
    else if (state == 2'b01) begin
      if (overflow) minutes <= minutes + 1'b1;
    end
  end
endmodule
