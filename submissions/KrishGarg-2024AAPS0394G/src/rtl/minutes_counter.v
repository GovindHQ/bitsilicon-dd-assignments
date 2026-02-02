module minutes_counter(
input clk, rst, count, reset,
output reg [7:0] minutes
);
always@(posedge clk, negedge rst) 
begin
  if(!rst || reset)    
    minutes <= 8'd0;
  else if(count) 
  begin
    if(minutes == 8'd99)
      minutes <= 8'd0;
    else
      minutes <= minutes + 1;
  end
end
endmodule
