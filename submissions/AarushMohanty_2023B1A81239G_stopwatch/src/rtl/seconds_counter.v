 module seconds_counter (
    input  wire clk,
    input  wire rst_n,        // active-low reset
    input  wire enable,		  // if enable low, nothing happens(pause)
    output reg  [5:0] seconds,
    output wire sec_overflow
);

always @(posedge clk) begin
    if (!rst_n) begin
        seconds <= 6'd0;
    end
    else if (enable) begin
        if (seconds == 6'd59)
            seconds <= 6'd0;
        else
            seconds <= seconds + 6'd1;
    end
end

assign sec_overflow = (enable && seconds == 6'd59);

endmodule
