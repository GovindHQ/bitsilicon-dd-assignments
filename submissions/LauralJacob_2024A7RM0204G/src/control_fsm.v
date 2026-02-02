module control_fsm (
    input  wire clk,
    input  wire rst_n,
    input  wire start,
    input  wire stop,
    input  wire reset,
    output reg  count_enable,
    output reg  [1:0] status
);

    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] current_state, next_state;

    always @(posedge clk) begin
        if (!rst_n)
            current_state <= IDLE;
        else
            current_state <= next_state;
    end

    always @(*) begin
        next_state   = current_state;
        count_enable = 1'b0;
        status       = current_state;

        if (reset) begin
            next_state = IDLE;
            status     = IDLE;
        end else begin
            case (current_state)
                IDLE: begin
                    if (start)
                        next_state = RUNNING;
                end

                RUNNING: begin
                    count_enable = 1'b1;
                    if (stop)
                        next_state = PAUSED;
                end

                PAUSED: begin
                    if (start)
                        next_state = RUNNING;
                end

                default: next_state = IDLE;
            endcase
        end
    end

endmodule
