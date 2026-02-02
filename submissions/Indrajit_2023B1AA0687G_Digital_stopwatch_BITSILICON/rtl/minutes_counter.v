module minutes_counter #(
	parameter MAX = 99
)(
	input wire	clk,
	input wire	rst_n,
	input wire	enable,
	input wire	reset,
	output reg [7:0]	minutes
);

	always @(posedge clk or negedge rst_n) begin
		if (!rst_n) begin 
			minutes <= 8'd0;
		end else if (reset) begin
			minutes <= 8'd0;
		end else if (enable) begin
			if (minutes == MAX)
				minutes <= 8'd0;
			else
				minutes <= minutes + 1'b1;
		end
	end
endmodule	
