module control_fsm (
    input  wire       clk,
    input  wire       rst_n,      // Asynchronous hardware reset
    input  wire       start,
    input  wire       stop,
    input  wire       reset,      // Synchronous logical reset
    output reg        count_en,   // Enable signal for counters
    output reg        clear,      // Clear signal for counters
    output wire [1:0] status      // Current state encoding
);

    // State Encoding
    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] current_state, next_state;

    // Output current state status
    assign status = current_state;

    // Sequential Logic: State Update
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            current_state <= IDLE;
        end else begin
            current_state <= next_state;
        end
    end

    // Combinational Logic: Next State Logic
    always @(*) begin
        next_state = current_state; // Default to hold state

        case (current_state)
            IDLE: begin
                if (start) begin
                    next_state = RUNNING;
                end
            end

            RUNNING: begin
                if (reset) begin
                    next_state = IDLE;
                end else if (stop) begin
                    next_state = PAUSED;
                end
            end

            PAUSED: begin
                if (reset) begin
                    next_state = IDLE;
                end else if (start) begin
                    next_state = RUNNING;
                end
            end

            default: next_state = IDLE;
        endcase
    end

    // Output Logic
    always @(*) begin
        // Defaults
        count_en = 1'b0;
        clear    = 1'b0;

        case (current_state)
            IDLE: begin
                clear = 1'b1; // Clear counters in IDLE
            end
            RUNNING: begin
                count_en = 1'b1;
            end
            PAUSED: begin
                count_en = 1'b0; // Freeze counters
            end
            default: begin
                clear = 1'b1;
            end
        endcase
    end

endmodule
