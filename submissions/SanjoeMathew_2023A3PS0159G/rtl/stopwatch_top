module stopwatch_top(
input wire clk,start,stop,reset,
output wire [7:0] minute,
output wire [5:0] seconds,
output wire [1:0] state
    );
wire enable;
wire rollover;

fsm fsm_uut( .clk(clk),
        .reset(reset),
        .start(start),
        .stop(stop),
        .enable(enable),
        .state(state));

second_counter second_uut(   .clk(clk),
        .reset(reset),
        .enable(enable),
        .seconds(seconds),
        .rollover(rollover));
        
minute_counter minute_uut(.clk(clk),
        .reset(reset),
        .rollover(rollover),
        .minute(minute));
endmodule
