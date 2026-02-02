module control_fsm (
    input  wire clk,
    input  wire rst_n,
    input  wire start,
    input  wire stop,
    input  wire reset,

    output reg  count_en,
    output reg  [1:0] status
);

    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] state, next_state;

    always @(posedge clk) begin
        if (!rst_n)
            state <= IDLE;
        else
            state <= next_state;
    end

    always @(*) begin
        next_state = state;

        if (reset)
            next_state = IDLE;
        else begin
            case (state)
                IDLE:    if (start) next_state = RUNNING;
                RUNNING: if (stop)  next_state = PAUSED;
                PAUSED:  if (start) next_state = RUNNING;
                default: next_state = IDLE;
            endcase
        end
    end

    always @(*) begin
        status   = state;
        count_en = (state == RUNNING);
    end

endmodule
