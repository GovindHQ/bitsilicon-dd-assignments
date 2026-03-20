`timescale 1ns / 1ps

module control_fsm (
    input wire clk,
    input wire rst_n,       
    input wire start,       
    input wire stop,
    input wire reset_btn,   
    output reg count_enable,
    output reg clear_time,  
    output reg [1:0] status  // 00: IDLE, 01: RUNNING, 10: PAUSED
);

    // Encoding the states
    localparam STATE_IDLE    = 2'b00;
    localparam STATE_RUNNING = 2'b01;
    localparam STATE_PAUSED  = 2'b10;

    reg [1:0] current_state, next_state;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            current_state <= STATE_IDLE;
        else
            current_state <= next_state;
    end

    always @(*) begin
        // Defaults
        next_state = current_state;
        count_enable = 0;
        clear_time = 0;
        status = current_state;

        case (current_state)
            STATE_IDLE: begin
                clear_time = 1; // Keep counters cleared in IDLE
                if (start) next_state = STATE_RUNNING;
            end

            STATE_RUNNING: begin
                count_enable = 1; // Enable counting
                if (stop)        next_state = STATE_PAUSED;
                else if (reset_btn)  next_state = STATE_IDLE;
            end

            STATE_PAUSED: begin
                // Retain current value (count_enable is 0)
                if (start)       next_state = STATE_RUNNING;
                else if (reset_btn)  next_state = STATE_IDLE;
            end
            
            default: next_state = STATE_IDLE;
        endcase
    end
endmodule