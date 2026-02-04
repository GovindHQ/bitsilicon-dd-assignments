module tb_stopwatch();
    reg        clk;
    reg        rst_n;
    reg        start;
    reg        stop;
    reg        reset;
    
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

    always #5 clk = ~clk;

    initial begin
       
        clk   = 0;
        rst_n = 0;
        start = 0;
        stop  = 0;
        reset = 0;

	//releasing asynch reset
        #20 rst_n = 1;

	//start -> stop after minute counter increment -> stop
        #20 start = 1;
        #10 start = 0; 
	#620 stop = 1;
        #10 stop = 0;
	#30 reset = 1;
        #10  reset = 0;
	
	//start -> reset
        #50 start = 1;
        #10 start = 0;
	#50 reset = 1;
        #10 reset = 0;

	//start -> asynch reset
	#50 start = 1;
        #10 start = 0;
	#50 rst_n = 0;
	
        #100 $finish;
    end

endmodule
