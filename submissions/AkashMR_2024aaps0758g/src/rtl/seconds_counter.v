module seconds_counter (
    input  wire       clk,
    input  wire       rst_n,
    input  wire       enable,     // From FSM
    input  wire       clear,      // From FSM
    output reg  [5:0] seconds,
    output wire       sec_tick    // Pulse high when seconds wraps 59->0
);

    // Combinational overflow logic
    // Tick is high only when counter is at max AND we are about to step (enabled)
    assign sec_tick = (seconds == 6'd59) && enable;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            seconds <= 6'd0;
        end else if (clear) begin
            seconds <= 6'd0;
        end else if (enable) begin
            if (seconds == 6'd59) begin
                seconds <= 6'd0;
            end else begin
                seconds <= seconds + 1'b1;
            end
        end
    end

endmodule
