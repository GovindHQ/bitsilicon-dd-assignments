module control_fsm (
    input wire clk, rst_n, start, stop, reset,
    output reg [1:0] status,
    output reg c_enable
);

    localparam IDLE = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED = 2'b10;

    reg [1:0] current_state, next_state;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            current_state <= IDLE;
        end else begin
            current_state <= next_state;
        end
    end

    always @(*) begin

        next_state = current_state;
        c_enable = 1'b0;
        status = current_state;

        case (current_state)
            IDLE: begin
                if (start) next_state = RUNNING;
            end

            RUNNING: begin
                c_enable = 1'b1;
                if (stop) next_state = PAUSED;
            end

            PAUSED: begin
                if (start) next_state = RUNNING;
                else if (reset) next_state = IDLE;
            end

            default: next_state = IDLE;
        endcase
    end

endmodule