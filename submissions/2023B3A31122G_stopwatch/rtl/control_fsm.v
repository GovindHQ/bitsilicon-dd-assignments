module control_fsm (
    input  wire       clk,
    input  wire       rst_n,      // Active-low hardware reset
    input  wire       start,      // Start button 
    input  wire       stop,       // Stop button 
    input  wire       reset,      // User Reset button 
    output wire       enable,     // 1 = Count, 0 = Hold
    output reg  [1:0] status      // 00=IDLE, 01=RUNNING, 10=PAUSED
);

    //State definitions
    localparam STATE_IDLE    = 2'b00;
    localparam STATE_RUNNING = 2'b01;
    localparam STATE_PAUSED  = 2'b10;

    // Internal state register
    reg [1:0] current_state, next_state;

   
    //Current state Logic
   
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            current_state <= STATE_IDLE;
        end else begin
            // User reset forces IDLE
            if (reset)
                current_state <= STATE_IDLE;
            else
                current_state <= next_state;
        end
    end

    
    //  Next State Logic
    
    always @(*) begin
        // Default to staying in the current state
        next_state = current_state;

        case (current_state)
            STATE_IDLE: begin
                // If Start is pressed, start running
                if (start) 
                    next_state = STATE_RUNNING;
            end

            STATE_RUNNING: begin
                // If Stop is pressed, pause the watch
                if (stop) 
                    next_state = STATE_PAUSED;
               
            end

            STATE_PAUSED: begin
                // If Start is pressed again, continue running
                if (start) 
                    next_state = STATE_RUNNING;
            end
            
            default: next_state = STATE_IDLE;
        endcase
    end

   //Output Logic
    
    // Update the status output to match the current state
    always @(*) begin
        status = current_state;
    end

    //enable signal is high only when we are running the stopwatch
    assign enable = (current_state == STATE_RUNNING);

endmodule