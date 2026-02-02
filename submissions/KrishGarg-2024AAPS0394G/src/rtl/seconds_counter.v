module seconds_counter( 
input clk, rst, en, reset,
output reg [5:0] seconds,
output reg count
); 
always@(posedge clk, negedge rst) 
begin 
  if(!rst || reset)
    seconds <= 6'd0;
  else if(en) 
  begin
    if(seconds == 6'd59)
      seconds <= 6'd0; 
    else 
      seconds <= seconds + 1;
  end
end 

always @(*) begin
        count = (seconds == 6'd59) && en;
    end
endmodule
