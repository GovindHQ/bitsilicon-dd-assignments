module seconds_counter(
    input wire clk,
    input wire rst_n,
    input wire enable,
    output reg [5:0] seconds,
    output reg rollover
);

always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        seconds  <= 0;
        rollover <= 0;
    end
    else if (enable) begin
        if (seconds == 6'd59) begin
            seconds  <= 0;
            rollover <= 1;
        end
        else begin
            seconds  <= seconds + 1;
            rollover <= 0;
        end
    end
    else begin
        seconds  <= seconds;   // hold value
        rollover <= 0;
    end
end

endmodule
