module second_counter(
input reset,clk,enable,
output reg [5:0] seconds,
output reg rollover
    );

always @(posedge clk) begin
    if (reset) begin
    seconds <=6'd0;
    rollover <=1'b0;
    end
    else if (enable) begin
        if (seconds == 6'd59) begin
        seconds <= 6'd0;
        rollover <= 1'd1;
        end
        else begin
        seconds <= seconds+1'd1;
        rollover <= 1'b0;
        end
    end
    else rollover<=1'b0;  
end      
endmodule
