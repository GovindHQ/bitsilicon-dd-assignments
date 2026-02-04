module minutes_counter (
    input  wire       clk,
    input  wire       rst_n,
    input  wire       en,
    input  wire       clr,
    input  wire       incr,
    output reg  [7:0] count
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            count <= 8'd0;
        end 
	else if (clr) begin
            count <= 8'd0;
        end 
	else if (en && incr) begin
            if (count == 8'd99)
                count <= 8'd0;
            else
                count <= count + 1'b1;
        end
    end

endmodule
