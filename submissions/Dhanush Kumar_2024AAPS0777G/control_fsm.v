module control_fsm (
    input  wire clk,
    input  wire rst_n,
    input  wire start,
    input  wire stop,
    input  wire reset,
    output reg  enable_count,
    output reg  [1:0] status
);

    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] state, next_state;

    // State register
    always @(posedge clk) begin
        if (!rst_n) begin
            state <= IDLE;
        end
        else begin
            state <= next_state;
        end
    end

    // Next-state logic
    always @(*) begin
        next_state = state;
        case (state)
            IDLE: begin
                if (start)
                    next_state = RUNNING;
            end

            RUNNING: begin
                if (stop)
                    next_state = PAUSED;
                else if (reset)
                    next_state = IDLE;
            end

            PAUSED: begin
                if (start)
                    next_state = RUNNING;
                else if (reset)
                    next_state = IDLE;
            end

            default: next_state = IDLE;
        endcase
    end

    // Output logic
    always @(*) begin
        enable_count = (state == RUNNING);
        status       = state;
    end

endmodule
