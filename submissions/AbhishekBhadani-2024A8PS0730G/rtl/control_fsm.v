module control_fsm (
    input  wire clk,
    input  wire rst_n,   
    input  wire start,
    input  wire stop,
    input  wire reset,   
    output reg  enable_count,
    output reg  [1:0] status   // 00=IDLE, 01=RUNNING, 10=PAUSED
);

    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] state, next_state;

    // state register
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= IDLE;
        else
            state <= next_state;
    end

    // next-state and outputs
    always @(*) begin
        next_state    = state;
        enable_count  = 1'b0;

        case (state)
            IDLE: begin
                if (start)
                    next_state = RUNNING;
                else
                    next_state = IDLE;
            end

            RUNNING: begin
                enable_count = 1'b1;
                if (reset)
                    next_state = IDLE;
                else if (stop)
                    next_state = PAUSED;
                else
                    next_state = RUNNING;
            end

            PAUSED: begin
                if (reset)
                    next_state = IDLE;
                else if (start)
                    next_state = RUNNING;
                else
                    next_state = PAUSED;
            end

            default: next_state = IDLE;
        endcase
    end

    // status output mirrors state
    always @(*) begin
        status = state;
    end

endmodule
