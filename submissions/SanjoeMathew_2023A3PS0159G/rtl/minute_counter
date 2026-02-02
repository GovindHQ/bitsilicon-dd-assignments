module minute_counter(
input rollover,clk,reset,
output reg [7:0] minute
    );
always@(posedge clk) begin
    if (reset) begin
    minute <= 8'b0;
    end
    else if (rollover) begin
        if(minute == 8'd99) begin
        minute<=8'b0;
        end
        else  minute<= minute+8'd1;
    end    
end            
endmodule
