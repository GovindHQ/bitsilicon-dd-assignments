module seconds_counter (
    input  wire clk,
    input  wire rst_n,
    input  wire reset,
    input  wire enable,

    output reg  [5:0] seconds
);

    always @(posedge clk) begin
        if (!rst_n || reset) begin
            seconds <= 6'd0;
        end else if (enable) begin
            if (seconds == 6'd59)
                seconds <= 6'd0;
            else
                seconds <= seconds + 6'd1;
        end
    end

endmodule
