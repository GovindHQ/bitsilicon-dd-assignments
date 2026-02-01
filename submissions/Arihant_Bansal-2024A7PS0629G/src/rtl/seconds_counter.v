module seconds_counter(input wire clk,
input wire rst,
input wire[1:0] status,
output wire tick_out,
output reg [5:0] seconds);

assign tick_out = (status == 2'b10 && seconds == 6'd59);
always @(posedge clk or negedge rst)begin
    if(!rst) begin
        seconds<={6{1'b0}};
    end
    else begin
        if(status==2'b00)begin //reset
        seconds<={6{1'b0}};
    end
    else if(status==2'b01) begin //stop
        seconds<=seconds;
    end
    else if(status==2'b10)begin //running
        if(seconds<6'd59)begin
            seconds<=seconds+6'b000001;
        end
        else begin
            seconds<=6'b000000;
        end
    end
    end
end

endmodule
