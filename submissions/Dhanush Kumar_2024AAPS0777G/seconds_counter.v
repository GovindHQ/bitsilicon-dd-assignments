module seconds_counter (
    input  wire clk,
    input  wire rst_n,
    input  wire enable,
    output reg  [5:0] seconds,
    output reg  rollover
);
always@(posedge clk) begin
   if(!rst_n)begin
   seconds<=6'd0;
   rollover<=1'd0;
   end
  else if(enable) begin
    if(seconds==6'd59)begin
    seconds<=6'd0;
    rollover<=1'd1;

  end
  else begin
    seconds<=seconds+6'd1;
    rollover<=1'd0;
  end
end
 else begin
        rollover <= 1'b0;
 end
end
endmodule

