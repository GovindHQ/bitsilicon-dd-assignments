module seconds_counter (
    input wire clk, rst_n, enable, clear,
    output reg [5:0] seconds,
    output wire done
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            seconds <= 0;
        end
        else if(clear)begin
            seconds <=0 ;
        end 
        else if (enable) begin
            if (seconds == 59) begin
                seconds <= 0;
            end else begin
                seconds <= seconds + 1;
            end
        end
    end

    assign done = (seconds == 59 && enable);

endmodule