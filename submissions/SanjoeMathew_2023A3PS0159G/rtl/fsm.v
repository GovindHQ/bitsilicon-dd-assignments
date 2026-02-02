module fsm(
input start,stop,clk,reset,
output reg [1:0] state,
output reg enable
    );
always @(posedge clk) begin        // 00 idle 01 running 10 paused
    if (reset) begin
    state <= 2'b00;
    enable<= 1'b0;
    end
    else begin
        case (state)
            2'b00: begin
                enable<= 1'b0;
                if (start) state<=2'b01;
                end
            2'b01: begin
                enable<=1'b1;
                if (stop) state<=2'b10;
                end
            2'b10: begin
                enable<=1'b0;
                if(start) state<=2'b01;
                end
            default: begin
                enable<=1'b0;
                state<=2'b00;
                end
       endcase
end 
end                   
endmodule
