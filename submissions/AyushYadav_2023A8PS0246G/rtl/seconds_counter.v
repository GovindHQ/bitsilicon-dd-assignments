`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.02.2026 14:12:31
// Design Name: 
// Module Name: seconds_counter
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

module seconds_counter(
    input cnt,
    input rst,
    input clk,
    output oflow,
    output [5:0] scnds
    );
    
    wire [5:0] nxts, currs, news;
    
    dff #(
        .w(6)
    )DS(
        .D(nxts),
        .clk(clk),
        .Y(currs)
    );
    
    wire main_rst;
    wire [6:0] diff;
    
    assign diff = {1'b0, currs} + 7'b100_0101; // seconds - 59
    assign oflow = ~diff[6];
    assign main_rst = rst | ~diff[6];
    
    mux_2#(
        .w(6)
    )addSelector(
        .d0(news), .d1(6'b0), 
        .select(main_rst),
        .y(nxts)
    );
    
    assign news = currs + {5'b0, cnt};
    assign scnds = currs;
    
endmodule

module mux_2#(
    parameter w = 1
    )(
    input [w-1:0] d0, d1, 
    input select,
    output reg [w-1:0] y
    );
    
    always @(*) begin
        case (select)
            1'b0 : y = d0;
            1'b1 : y = d1;
        endcase
    end
    
endmodule

module dff #(
    parameter w = 6
    )(
    input [w-1:0] D,
    input clk,
    output reg [w-1:0] Y
    );
    
    always @(posedge clk) begin
        Y <= D;
    end

endmodule
