`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.02.2026 14:42:48
// Design Name: 
// Module Name: tb_scnds
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

module tb_stopwatch_top;

    reg clk;
    reg start, stop, reset;
    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    stopwatch_top UUT (
        .clk(clk),
        .rst_n(1'b1),   // ignored for this TB
        .start(start),
        .stop(stop),
        .reset(reset),
        .minutes(minutes),
        .seconds(seconds),
        .status(status)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Helper task to apply inputs and wait one cycle
    task apply(input s, input p, input r);
        begin
            start = s;
            stop  = p;
            reset = r;

            @(posedge clk);
        end
    endtask

    initial begin
        start = 0;
        stop  = 0;
        reset = 1;
        @(posedge clk);

        apply(0,0,0);
        apply(1,0,0);

        repeat (5) apply(0,0,0);

        apply(0,1,0);

        repeat (3) apply(0,0,0);

        apply(1,0,0);

        repeat (10) apply(0,0,0);

        apply(0,0,1);
        apply(1,0,0);

        repeat (70) apply(0,0,0);
        $stop;
    end

endmodule
