module control_fsm (
    input  wire clk,
    input  wire rst_n,
    input  wire start,
    input  wire stop,
    input  wire reset,
    output reg  [1:0] state,
    output reg        count_en
);

    // State encoding
    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] next_state;

    // State register
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= IDLE;
        else
            state <= next_state;
    end

    // Next-state logic
    always @(*) begin
        next_state = state;   // default assignment

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

            // Required for Verilator (prevents CASEINCOMPLETE)
            default: begin
                next_state = IDLE;
            end
        endcase
    end

    // Output logic
    always @(*) begin
        count_en = (state == RUNNING);
    end

endmodule
