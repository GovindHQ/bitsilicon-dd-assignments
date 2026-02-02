module stopwatch_tb;
reg clk,start,stop,reset;
wire [7:0] minute;
wire [5:0] seconds;
wire [1:0] state;

stopwatch_top uut (
        .clk(clk),
        .reset(reset),
        .start(start),
        .stop(stop),
        .minute(minute),
        .seconds(seconds),
        .state(state)
    );
always begin
#0.5 clk=1'b0;
#0.5 clk=1'b1;
end
initial begin
        reset = 1;
        start = 0;
        stop  = 0;

        #2;
        reset = 0;

        start = 1;
        #1;
        start = 0;

        #65;

        stop = 1;
        #1;
        stop = 0;

        #5;
        
        start = 1;
        #1;
        start = 0;

        #10;

        reset = 1;
        #2;
        reset = 0;

        #5;
        $stop;
    end

endmodule
