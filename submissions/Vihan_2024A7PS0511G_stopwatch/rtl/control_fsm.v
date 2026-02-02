//The comments have been made after understanding the whole code although it is written with the help of artificial intelligence
// and the comments are solely made by the user and not artificial intelligence

module control_fsm (
    input  wire       clk, //input clock taken
    input  wire       rst_n, //active low async reset
    input  wire       start, //button to start/resume after stop
    input  wire       stop, //button to stop the counters
    input  wire       reset,//to reset the counters
    output reg [1:0]  state,//localparam states to show IDLE,RUNNING OR PAUSED
    output wire       count_en,//enable param to start counters
    output wire       clear_counters//clear the counters to 0
);
    localparam IDLE    = 2'b00;
    localparam RUNNING = 2'b01;
    localparam PAUSED  = 2'b10;

    reg [1:0] next_state; //temp reg to store the next state

    // State Transition Logic
    always @(*) begin
        next_state = state;
        case (state)
            IDLE:   
            begin
                if (start)
                begin
                    next_state = RUNNING;
                end
            end 
            RUNNING:
            begin
                if (stop)
                begin
                    next_state = PAUSED;
                end
            end
            PAUSED:  
            begin
                if (start)
                begin
                    next_state = RUNNING;
                end
                if (reset)
                begin
                    next_state = IDLE;
                end
            end
            default: next_state = IDLE;
        endcase
        // Global reset override
        if (reset)
        begin
            next_state = IDLE;
        end
    end

    // Sequential Block
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) //hardware async neg reset
        begin
            state <= IDLE;
        end
        else
        begin
            state <= next_state;
        end
    end

    assign count_en = (state == RUNNING); //count only when the counters are in the running condition
    assign clear_counters = (reset && state != RUNNING); //cler the counters when user presses reset button and the state is not running
endmodule