`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.02.2026 19:41:55
// Design Name: 
// Module Name: minutes_counter
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


module minutes_counter(
    input rst,
    input clk,
    input oflow_s,
    output [6:0] mins
    );
    
    wire [6:0] nxtm, currm, newm;
    
    dff #(
        .w(7)
    )DM(
        .D(nxtm),
        .clk(clk),
        .Y(currm)
    );
    
    mux_2#(
        .w(7)
    )addSelector(
        .d0(newm), .d1(7'b0), 
        .select(rst),
        .y(nxtm)
    );
    
    assign newm = currm + {6'b0, oflow_s};
    assign mins = currm;
    
endmodule
