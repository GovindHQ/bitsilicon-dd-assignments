`timescale 1ns/1ps

module tb_stopwatch;

    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;

    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    stopwatch_top dut (
        .clk     (clk),
        .rst_n   (rst_n),
        .start   (start),
        .stop    (stop),
        .reset   (reset),
        .minutes (minutes),
        .seconds (seconds),
        .status  (status)
    );

    // Clock: 10 ns period
    always #5 clk = ~clk;

    function [79:0] state_name;
        input [1:0] s;
        begin
            case (s)
                2'b00: state_name = "IDLE";
                2'b01: state_name = "RUNNING";
                2'b10: state_name = "PAUSED";
                default: state_name = "UNKNOWN";
            endcase
        end
    endfunction

    initial begin
        clk = 0;
        rst_n = 0;
        start = 0;
        stop  = 0;
        reset = 0;

        #20 rst_n = 1;

        // Start
        @(posedge clk) start = 1;
        @(posedge clk) start = 0;

        repeat (65) @(posedge clk);

        // Pause
        @(posedge clk) stop = 1;
        @(posedge clk) stop = 0;

        repeat (10) @(posedge clk);

        // Resume
        @(posedge clk) start = 1;
        @(posedge clk) start = 0;

        repeat (40) @(posedge clk);

        // Reset stopwatch (clears time)
        @(posedge clk) reset = 1;
        @(posedge clk) reset = 0;

        repeat (5) @(posedge clk);

        $display("\nSimulation complete.");
        $finish;
    end

    always @(posedge clk) begin
        if (rst_n) begin
            $display("TIME=%0t | %s | %2d:%02d",
                     $time,
                     state_name(status),
                     minutes,
                     seconds);
        end
    end

endmodule
