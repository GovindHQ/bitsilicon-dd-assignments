module control_fsm (
    input  wire clk,
    input  wire rst_n,     // active-low reset
    input  wire start,
    input  wire stop,
    input  wire reset,    // synchronous stopwatch reset
    output reg  enable,
    output reg  [1:0] status
);

    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] state, next_state;

    // State register
    always @(posedge clk) begin
        if (!rst_n)
            state <= IDLE;
        else
            state <= next_state;
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
                if (reset)
                    next_state = IDLE;
                else if (stop)
                    next_state = PAUSED;
            end

            PAUSED: begin
                if (reset)
                    next_state = IDLE;
                else if (start)
                    next_state = RUNNING;
            end

            default: next_state = IDLE;
        endcase
    end

    // Output logic (Moore)
    always @(*) begin
        enable = 1'b0;
        status = state;

        if (state == RUNNING)
            enable = 1'b1;
    end

endmodule
