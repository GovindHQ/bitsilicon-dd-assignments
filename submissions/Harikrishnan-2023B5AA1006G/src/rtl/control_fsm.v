// control_fsm.v
module control_fsm (
    input wire clk,
    input wire rst_n,       // active-low reset async
    input wire start,       // start signal
    input wire stop,        // stop/pause signal
    input wire reset,       // reset signal sync
    output reg enable,      // enable signal for counters
    output reg [1:0] status // 00=IDLE, 01=RUNNING, 10=PAUSED
);

    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] state, next_state;

    always @(posedge clk or negedge rst_n) begin// rst_n will be triggered regardless of cloack
        if (!rst_n) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end

    always @(*) begin
        next_state = state;
        case (state)
            IDLE: begin
                if (start)
                    next_state = RUNNING;
                else if (reset)
                    next_state = IDLE;
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
        enable = (state == RUNNING);
        status = state;
    end

endmodule
