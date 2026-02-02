module seconds_counter (
    input  wire clk,
    input  wire rst_n,
    input  wire enable,
    output reg  [5:0] seconds,
    output reg  sec_tick
);

    always @(posedge clk) begin
        if (!rst_n) begin
            seconds  <= 6'd0;
            sec_tick <= 1'b0;
        end else if (enable) begin
            if (seconds == 6'd59) begin
                seconds  <= 6'd0;
                sec_tick <= 1'b1;
            end else begin
                seconds  <= seconds + 6'd1;
                sec_tick <= 1'b0;
            end
        end else begin
            sec_tick <= 1'b0;
        end
    end

endmodule
