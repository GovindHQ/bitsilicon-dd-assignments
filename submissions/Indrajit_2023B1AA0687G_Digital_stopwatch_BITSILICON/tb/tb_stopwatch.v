
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
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .minutes(minutes),
        .seconds(seconds),
        .status(status)
    );

    // 10ns clock \u2192 1 tick = 1 second (for simulation)
    always #5 clk = ~clk;

    initial begin
        // Initialize
        clk   = 0;
        rst_n = 0;
        start = 0;
        stop  = 0;
        reset = 0;

        // Global reset
        #20;
        rst_n = 1;

        // Start stopwatch
        #20;
        start = 1;
        #10;
        start = 0;

        // Let it run
        #1700;

        // Pause
        stop = 1;
        #10;
        stop = 0;

        #50;

        // Resume
        start = 1;
        #10;
        start = 0;

        #100;

        // Reset stopwatch
        reset = 1;
        #10;
        reset = 0;

        #50;
        $finish;
    end

endmodule
