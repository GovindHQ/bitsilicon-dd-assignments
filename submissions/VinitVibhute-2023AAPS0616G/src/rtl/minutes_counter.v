// minutes_counter.v
// Synchronous minutes counter (0-99)
// Increments on carry signal from seconds counter
// rst_n: Global asynchronous reset for hardware initialization
// clear: Synchronous clear (controlled by reset signal from user)

module minutes_counter (
    input wire clk,
    input wire rst_n,           // active-low asynchronous reset (global)
    input wire enable,          // count enable from FSM
    input wire clear,           // synchronous clear (functional reset)
    input wire carry_in,        // carry from seconds counter
    output reg [7:0] minutes    // minutes value (0-99)
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Global reset: initialize to safe state
            minutes <= 8'd0;
        end
        else if (clear) begin
            // Functional reset: user clearing stopwatch
            minutes <= 8'd0;
        end
        else if (enable && carry_in) begin
            if (minutes == 8'd99) begin
                minutes <= 8'd0;    // Roll over at 99
            end
            else begin
                minutes <= minutes + 1'b1;
            end
        end
    end

endmodule