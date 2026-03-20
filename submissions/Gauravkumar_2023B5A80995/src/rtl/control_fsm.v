module control_fsm (
    input  wire clk,
    input  wire rst_n,
    input  wire start,
    input  wire stop,
    input  wire reset,
    output reg  [1:0] state,
    output reg  count_en
);

localparam IDLE    = 2'b00;
localparam RUNNING = 2'b01;
localparam PAUSED  = 2'b10;

always @(posedge clk) begin
    if (!rst_n || reset) begin
        state <= IDLE;
    end else begin
        case (state)
            IDLE: begin
                if (start) state <= RUNNING;
            end
            RUNNING: begin
                if (stop) state <= PAUSED;
            end
            PAUSED: begin
                if (start) state <= RUNNING;
            end
            default: state <= IDLE;
        endcase
    end
end

always @(*) begin
    case (state)
        RUNNING: count_en = 1'b1;
        default: count_en = 1'b0;
    endcase
end

endmodule
