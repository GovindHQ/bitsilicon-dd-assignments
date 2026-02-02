module minutes_counter (
    input  wire       clk,
    input  wire       rst_n,    // Active low system reset 
    input  wire       enable,   // The roll output from the seconds counter
    output wire [7:0] minutes,
    output wire       min_end   // Output signal when minutes = 120
);

    
    wire [7:0] Q;           // flip flop outputs
    wire       rst_combined;// The output of the OR gate [system reset + rollover reset + minute reset]
    
    // JK Input logic
    wire j0, j1, j2, j3, j4, j5, j6, j7;
    
    assign j0 = enable;        // LSB to the roll signal from seconds counter
    assign j1 = Q[0] & j0;     // AND gate for FF1
    assign j2 = Q[1] & j1;     // AND gate for FF2
    assign j3 = Q[2] & j2;     // AND gate for FF3
    assign j4 = Q[3] & j3;     // AND gate for FF4
    assign j5 = Q[4] & j4;     // AND gate for FF5
    assign j6 = Q[5] & j5;     // AND gate for FF6
    assign j7 = Q[6] & j6;     // AND gate for FF7

   //Reset Logic
    
    
    assign min_end = Q[6] & Q[5] & Q[4] & Q[3];// Reset when minutes reach 120 

    
    assign rst_combined = min_end | (~rst_n);//Comining Resets

    // flip flop instantiation
    
    jk_flip_flop ff0 (.clk(clk), .rst(rst_combined), .j(j0), .k(j0), .q(Q[0]));
    jk_flip_flop ff1 (.clk(clk), .rst(rst_combined), .j(j1), .k(j1), .q(Q[1]));
    jk_flip_flop ff2 (.clk(clk), .rst(rst_combined), .j(j2), .k(j2), .q(Q[2]));
    jk_flip_flop ff3 (.clk(clk), .rst(rst_combined), .j(j3), .k(j3), .q(Q[3]));
    jk_flip_flop ff4 (.clk(clk), .rst(rst_combined), .j(j4), .k(j4), .q(Q[4]));
    jk_flip_flop ff5 (.clk(clk), .rst(rst_combined), .j(j5), .k(j5), .q(Q[5]));
    jk_flip_flop ff6 (.clk(clk), .rst(rst_combined), .j(j6), .k(j6), .q(Q[6]));
    jk_flip_flop ff7 (.clk(clk), .rst(rst_combined), .j(j7), .k(j7), .q(Q[7]));

    // Output assignment
    assign minutes = Q;

endmodule


