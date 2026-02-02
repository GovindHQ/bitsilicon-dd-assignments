module seconds_counter (
    input  wire       clk,
    input  wire       rst_n,   // Active low system reset 
    input  wire       enable,  //Running signal from fsm
    input  wire       min_end, // Reset when minutes reach 120
    output wire [5:0] seconds,
    output wire       roll     // Output signal when seconds = 59
);

    
    wire [5:0] Q;        // flipflop outputs
   
    wire       rst_combined; // The output of the OR gate [system reset + rollover reset + minute reset]
    
    //JK Input logic
    wire j0, j1, j2, j3, j4, j5;
    
    assign j0 = enable;
    assign j1 = Q[0] & j0;      // AND gate for FF1
    assign j2 = Q[1] & j1;      // AND gate for FF2
    assign j3 = Q[2] & j2;      // AND gate for FF3
    assign j4 = Q[3] & j3;      // AND gate for FF4
    assign j5 = Q[4] & j4;      // AND gate for FF5

 //Reset Logic
    
    
    assign roll = Q[5] & Q[4] & Q[3] & Q[1]& Q[0]; //When seconds =59 value changes to 1. Since roll acts as the enable for minutes counter, at the very next positive edge the flip flop will toggle.
    wire reset_60= Q[5] & Q[4] & Q[3] & Q[2];

   
    assign rst_combined = reset_60 | (~rst_n) | min_end; //Combining the resets

    // flip flop instantiation
    
    
    
    
    jk_flip_flop ff0 (.clk(clk), .rst(rst_combined), .j(j0), .k(j0), .q(Q[0]));
    jk_flip_flop ff1 (.clk(clk), .rst(rst_combined), .j(j1), .k(j1), .q(Q[1]));
    jk_flip_flop ff2 (.clk(clk), .rst(rst_combined), .j(j2), .k(j2), .q(Q[2]));
    jk_flip_flop ff3 (.clk(clk), .rst(rst_combined), .j(j3), .k(j3), .q(Q[3]));
    jk_flip_flop ff4 (.clk(clk), .rst(rst_combined), .j(j4), .k(j4), .q(Q[4]));
    jk_flip_flop ff5 (.clk(clk), .rst(rst_combined), .j(j5), .k(j5), .q(Q[5]));

    // Output assignment
    assign seconds = Q;

endmodule

