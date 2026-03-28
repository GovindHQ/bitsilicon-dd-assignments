`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.02.2026 20:38:07
// Design Name: 
// Module Name: control_fsm
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module control_fsm(
    input start,
    input stop,
    input clk,
    input rst,
    output cnt
    );
    
    wire nxtState, currState;
    
    dff #(
        .w(1)
    )D_state(
        .D(nxtState),
        .clk(clk),
        .Y(currState)
    );
    
    assign nxtState = (~currState & start) | (currState & ~stop & ~rst);
    
    assign cnt = currState;
endmodule
