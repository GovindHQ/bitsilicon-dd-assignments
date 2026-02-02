module minutes_counter (
    input wire clk, rst_n, enable, clear,
    output reg [6:0] minutes
    // output wire done
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            minutes <= 0;
        end
        else if(clear)begin
            minutes <= 0;
        end 
        else if (enable) begin
            if (minutes == 99) begin
                minutes <= 0;
            end else begin
                minutes <= minutes + 1;
            end
        end
    end

    // assign done = (minutes == 99 && enable);

endmodule