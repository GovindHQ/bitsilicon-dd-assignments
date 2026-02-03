`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.02.2026 21:06:45
// Design Name: 
// Module Name: stopwatch_top
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


module stopwatch_top (
    input wire clk,
    input wire rst_n, // ACTIVE LOW
    input wire start,
    input wire stop,
    input wire reset,
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status // 00=IDLE, 01=RUNNING, 10=PAUSED
    );
    
    wire cnt, oflow;
    wire [6:0] mins;
    wire [5:0] scnds;
    
    seconds_counter SC(
        .cnt(cnt),
        .rst(reset | ~rst_n),
        .clk(clk),
        .oflow(oflow),
        .scnds(scnds)
    );
    
    minutes_counter MC(
        .rst(reset | ~rst_n),
        .clk(clk),
        .oflow_s(oflow),
        .mins(mins)
    );
    
    control_fsm CF(
        .start(start),
        .stop(stop),
        .clk(clk),
        .rst(reset | ~rst_n),
        .cnt(cnt)
    );
    
    wire sNZ = (|mins) | (|scnds);
    
    assign minutes = {1'b0, mins};
    assign seconds = scnds;
    
    assign status[0] = cnt;
    assign status[1] = sNZ & ~cnt;
    
endmodule
