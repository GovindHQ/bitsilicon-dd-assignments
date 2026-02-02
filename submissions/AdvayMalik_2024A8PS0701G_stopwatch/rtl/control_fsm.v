module control_fsm (
    input wire clk,
    input wire rst_n, //global reset for hardware
    input wire start,
    input wire stop,
    input wire reset, //our manual reset
    output reg enable_count,
    output reg [1:0] current_state
);

    localparam IDLE = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED = 2'b10;

    always @(posedge clk) begin
        if (!rst_n || reset) begin
            current_state <= IDLE;
        end else begin
            case (current_state)
                IDLE: if (start) current_state <= RUNNING;
                RUNNING: if (stop) current_state <= PAUSED;
                PAUSED: if (start) current_state <= RUNNING;
                default: current_state <= IDLE; //covers all other states asw like running: reset.
            endcase
        end
    end

    always @(*) begin
      enable_count = (current_state == RUNNING);
    end

endmodule
