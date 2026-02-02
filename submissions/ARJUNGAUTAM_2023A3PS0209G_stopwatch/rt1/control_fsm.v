module control_fsm (
    input wire clk,
    input wire rst_n,   // Active-low reset
    input wire start,
    input wire stop,
    input wire reset,
    output reg [1:0] status  // 00: IDLE, 01: RUNNING, 10: PAUSED
);

// State definitions
localparam IDLE = 2'b00;
localparam RUNNING = 2'b01;
localparam PAUSED = 2'b10;

// FSM logic
always @(posedge clk or negedge rst_n) begin
    if (!rst_n || reset) begin
        status <= IDLE;
    end else begin
        case (status)
            IDLE: begin
                if (start) begin
                    status <= RUNNING;
                end
            end
            RUNNING: begin
                if (stop) begin
                    status <= PAUSED;
                end
            end
            PAUSED: begin
                if (start) begin
                    status <= RUNNING;
                end
            end
            default: status <= IDLE;
        endcase
    end
end

endmodule