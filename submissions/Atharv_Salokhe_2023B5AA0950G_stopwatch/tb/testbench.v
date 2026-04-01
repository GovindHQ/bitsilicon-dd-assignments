// Code your testbench here
// or browse Examples


module tb_stopwatch;


    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;

    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    integer t;


    stopwatch_top s1 (
        .clk     (clk),
        .rst_n   (rst_n),
        .start   (start),
        .stop    (stop),
        .reset   (reset),
        .minutes (minutes),
        .seconds (seconds),
        .status  (status)
    );


    initial clk = 0;
    always #5 clk = ~clk;

    always @(posedge clk) begin
        $display(
            "t = %0d, start = %0b, stop = %0b, reset = %0b, min = %0d, sec = %0d",
            t, start, stop, reset, minutes, seconds
        );
        t = t + 1;
    end

    initial begin
        // Initialize
        t     = 0;
        rst_n = 1;
        start = 0;
        stop  = 0;
        reset = 1;


        #50;        // hold reset for a few cycles
        reset = 0;  // release reset

      $display("Stopwatch started /n");
        // start

        #20;
        start = 1;
        #20;
        start = 0;

        #200;
		
      $display("Stopwatch stopped /n");
        stop = 1;
        #20;
        stop = 0;

		//wait
        #100;
      $display("Stopwatch resumed");
		//resume
        start = 1;
        #20;
        start = 0;
		
        #200;

      	#200;

        $finish;
    end

endmodule
