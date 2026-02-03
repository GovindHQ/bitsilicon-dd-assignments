// control_fsm.v
// Control FSM for stopwatch with three states: IDLE, RUNNING, PAUSED
// Generates enable signals for counters based on current state
// rst_n: Global asynchronous reset for hardware initialization
// reset: Functional reset to return to IDLE state (user command)

module control_fsm (
    input wire clk,
    input wire rst_n,           // active-low asynchronous reset (global)
    input wire start,           // start/resume signal
    input wire stop,            // stop/pause signal
    input wire reset,           // functional reset to IDLE (user command)
    output reg count_enable,    // enable signal for counters
    output reg [1:0] status     // 00=IDLE, 01=RUNNING, 10=PAUSED
);

    // State encoding
    localparam [1:0] IDLE    = 2'b00;
    localparam [1:0] RUNNING = 2'b01;
    localparam [1:0] PAUSED  = 2'b10;

    reg [1:0] current_state, next_state;

    // State register with asynchronous reset
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            current_state <= IDLE;
        end
        else begin
            current_state <= next_state;
        end
    end

    // Next state logic - reset is now treated as a synchronous input
    always @(*) begin
        next_state = current_state;  // Default: stay in current state
        
        case (current_state)
            IDLE: begin
                if (start) begin
                    next_state = RUNNING;
                end
            end
            
            RUNNING: begin
                if (reset) begin
                    next_state = IDLE;
                end
                else if (stop) begin
                    next_state = PAUSED;
                end
            end
            
            PAUSED: begin
                if (reset) begin
                    next_state = IDLE;
                end
                else if (start) begin
                    next_state = RUNNING;
                end
            end
            
            default: begin
                next_state = IDLE;
            end
        endcase
    end

    // Output logic
    always @(*) begin
        case (current_state)
            IDLE: begin
                count_enable = 1'b0;
                status = 2'b00;
            end
            
            RUNNING: begin
                count_enable = 1'b1;
                status = 2'b01;
            end
            
            PAUSED: begin
                count_enable = 1'b0;
                status = 2'b10;
            end
            
            default: begin
                count_enable = 1'b0;
                status = 2'b00;
            end
        endcase
    end

endmodule