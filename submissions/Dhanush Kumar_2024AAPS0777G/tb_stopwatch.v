`timescale 1ns/1ps

module tb_stopwatch;

    // Testbench signals
    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;

    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    // Instantiate the DUT
    stopwatch_top dut (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .minutes(minutes),
        .seconds(seconds),
        .status(status)
    );

    // Clock generation: 10 ns period
    always #5 clk = ~clk;

    // Test sequence
    initial begin
        // Initialize signals
        clk   = 0;
        rst_n = 0;
        start = 0;
        stop  = 0;
        reset = 0;

        // Apply reset
        #20;
        rst_n = 1;

        // Start stopwatch
        #10;
        start = 1;
        #10;
        start = 0;

        // Let it run for some time
        repeat (5) begin
            #10;
            $display("RUNNING  Time = %02d:%02d  Status=%b",
                     minutes, seconds, status);
        end

        // Pause stopwatch
        stop = 1;
        #10;
        stop = 0;

        #20;
        $display("PAUSED   Time = %02d:%02d  Status=%b",
                 minutes, seconds, status);

        // Resume stopwatch
        start = 1;
        #10;
        start = 0;

        repeat (5) begin
            #10;
            $display("RUNNING  Time = %02d:%02d  Status=%b",
                     minutes, seconds, status);
        end

        // Reset stopwatch
        reset = 1;
        #10;
        reset = 0;

        #10;
        $display("RESET    Time = %02d:%02d  Status=%b",
                 minutes, seconds, status);

        // Finish simulation
        #20;
        $finish;
    end

endmodule
