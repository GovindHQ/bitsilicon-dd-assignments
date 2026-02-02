module control_fsm (
    input  wire       clk,
    input  wire       rst_n,
    input  wire       start,
    input  wire       stop,
    input  wire       reset,
    output reg  [1:0] status,
    output wire       count_en,
    output wire       clear_counters
);

    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] state, next_state;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) state <= IDLE;
        else if (reset) state <= IDLE;
        else state <= next_state;
    end

    always @(*) begin
        next_state = state;
        case (state)
            IDLE:    if (start) next_state = RUNNING;
            RUNNING: if (stop)  next_state = PAUSED;
            PAUSED:  begin
                if (start) next_state = RUNNING;
                if (reset) next_state = IDLE;
            end
            default: next_state = IDLE;
        endcase
    end

    always @(*) status = state;
    assign count_en = (state == RUNNING);
    assign clear_counters = reset;

endmodule