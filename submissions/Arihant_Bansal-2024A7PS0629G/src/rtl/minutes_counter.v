module minutes_counter(input wire clk,
input wire rst,
input wire[1:0] status,
input wire tick_in,
output reg [7:0] minutes);

always @(posedge clk or negedge rst)begin
    if (!rst) begin
        minutes<={8{1'b0}};
    end
    else begin
        if(status==2'b00)begin //reset
        minutes<={8{1'b0}};
    end
    else if(status==2'b01) begin //stop
        minutes<=minutes;
    end
    else if(status==2'b10)begin //running
        if(minutes<8'b01100011)begin
            if(tick_in) begin
                minutes<=minutes+8'b00000001;
            end
        end
    end
    end
end

endmodule

