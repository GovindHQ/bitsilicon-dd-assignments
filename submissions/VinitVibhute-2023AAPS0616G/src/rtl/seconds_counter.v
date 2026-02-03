// seconds_counter.v
// Synchronous seconds counter (0-59)
// Counts from 0 to 59, then rolls over to 0 and generates a carry signal
// rst_n: Global asynchronous reset for hardware initialization
// clear: Synchronous clear (controlled by reset signal from user)

module seconds_counter (
    input wire clk,
    input wire rst_n,           // active-low asynchronous reset (global)
    input wire enable,          // count enable from FSM
    input wire clear,           // synchronous clear (functional reset)
    output reg [5:0] seconds,   // seconds value (0-59)
    output wire carry_out       // combinational carry to minutes counter
);

    // Combinational lookahead carry generation
    // Tells minutes counter to prepare for increment on next edge
    // This ensures both seconds rollover and minutes increment happen simultaneously
    assign carry_out = (seconds == 6'd59) && enable;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Global reset: initialize to safe state
            seconds <= 6'd0;
        end
        else if (clear) begin
            // Functional reset: user clearing stopwatch
            seconds <= 6'd0;
        end
        else if (enable) begin
            if (seconds == 6'd59) begin
                seconds <= 6'd0;    // Roll over to 0
            end
            else begin
                seconds <= seconds + 1'b1;
            end
        end
    end

endmodule 