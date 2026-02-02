module tb_stopwatch;

    // Inputs to DUT (Device Under Test)
    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;

    // Outputs from DUT
    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    // Instantiate DUT
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

    // -------------------------
    // Clock generation
    // -------------------------
    always #5 clk = ~clk;

    // -------------------------
    // Test sequence
    // -------------------------
    initial begin
        // Initial values
        clk   = 0;
        rst_n = 0;
        start = 0;
        stop  = 0;
        reset = 0;

        // Apply hardware reset
        #20;
        rst_n = 1;

        // Wait a little
        #20;

        // Start stopwatch
        start = 1;
        #10;
        start = 0;

        // Let it run for some time
        #200;

        // Pause stopwatch
        stop = 1;
        #10;
        stop = 0;

        // Wait while paused
        #100;

        // Resume stopwatch
        start = 1;
        #10;
        start = 0;

        // Let it run again
        #200;

        // Functional reset
        reset = 1;
        #10;
        reset = 0;

        // Wait and finish
        #100;

        $finish;
    end

endmodule
