module stopwatch_top (
    input  wire       clk,
    input  wire       rst_n,    // Active-low hardware reset
    input  wire       start,    // Start button
    input  wire       stop,     // Stop button
    input  wire       reset,    // User Reset button (Active-high)
    output wire [7:0] minutes,  // 00-120
    output wire [5:0] seconds,  // 00-59
    output wire [1:0] status    // 00=IDLE, 01=RUNNING, 10=PAUSED
);


    
    //Combining the hardware reset[Active-low] and user reset[Active-high]
    wire system_rst_n;
    assign system_rst_n = rst_n & (~reset); //taking the complement of reset to make it active-low

    
    wire enable_counting; // From FSM to Seconds Counter
    wire seconds_roll;    // From Seconds (at 59) to Minutes Counter
    wire minutes_end;     // From Minutes (at 120) to Seconds Counter

    
    //Module Instantinations
    

    // Control FSM
    
    control_fsm fsm_inst (
        .clk(clk),
        .rst_n(rst_n),        // FSM only resets on hard reset, handles the reset input internally
        .start(start),
        .stop(stop),
        .reset(reset),        
        .enable(enable_counting),
        .status(status)
    );

    //Seconds Counter (0-59)
    
    seconds_counter sec_inst (
        .clk(clk),
        .rst_n(system_rst_n), // Reset if hardware reset or user reset is pressed
        .enable(enable_counting),
        .min_end(minutes_end),// Reset when minutes reach 120
        .seconds(seconds),    
        .roll(seconds_roll)   // Output signal when seconds = 59
    );

    // Minutes Counter (0-120)
    
    minutes_counter min_inst (
        .clk(clk),
        .rst_n(system_rst_n), // Reset if hardware reset or user reset is pressed
        .enable(seconds_roll),// Connects to the rollover signal from seconds
        .minutes(minutes),    
        .min_end(minutes_end) // Output signal when minutes reach 120
    );

endmodule

module jk_flip_flop (
    input wire clk,
    input wire rst,
    input wire j,
    input wire k,
    output reg q
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            q <= 1'b0;
        end else begin
            case ({j, k})
                2'b00: q <= q;      // Hold
                2'b01: q <= 1'b0;   // Reset
                2'b10: q <= 1'b1;   // Set
                2'b11: q <= ~q;     // Toggle
            endcase
        end
    end
endmodule