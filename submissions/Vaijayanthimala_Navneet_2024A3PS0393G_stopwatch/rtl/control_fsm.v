module control_fsm (
    input wire clk,
    input wire rst_n,
    input wire start,
    input wire stop,
    input wire reset,
    output reg [1:0] state_out,
    output wire count_en
);

    parameter IDLE = 2'b00, RUNNING = 2'b01, PAUSED = 2'b10;
    reg [1:0] state, next_state;

    // Sequential state update
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) 
            state <= IDLE;
        else if (reset) 
            state <= IDLE;
        else 
            state <= next_state;
    end

    // Next state logic
    always @(*) begin
        case (state)
            IDLE:    next_state = start ? RUNNING : IDLE;
            RUNNING: next_state = stop  ? PAUSED  : RUNNING;
            PAUSED:  next_state = start ? RUNNING : PAUSED;
            default: next_state = IDLE;
        endcase
    end

    assign count_en = (state == RUNNING);
    
    always @(*) begin
        state_out = state;
    end

endmodule