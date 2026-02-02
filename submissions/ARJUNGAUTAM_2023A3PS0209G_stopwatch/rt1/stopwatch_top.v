module stopwatch_top (
    input wire clk,
    input wire rst_n,   // active-low reset
    input wire start,
    input wire stop,
    input wire reset,
    output wire [7:0] minutes,
    output wire [5:0] seconds,
    output wire [1:0] status
);

// Internal signals
wire rollover;  // From seconds to minutes
wire running;   // Derived from status

// Instantiate FSM
control_fsm fsm_inst (
    .clk(clk),
    .rst_n(rst_n),
    .start(start),
    .stop(stop),
    .reset(reset),
    .status(status)
);

// Determine if running
assign running = (status == 2'b01);

// Instantiate seconds counter
seconds_counter sec_inst (
    .clk(clk),
    .rst_n(rst_n),
    .reset(reset),
    .enable(running),
    .seconds(seconds),
    .rollover(rollover)
);

// Instantiate minutes counter
minutes_counter min_inst (
    .clk(clk),
    .rst_n(rst_n),
    .reset(reset),
    .enable(rollover),
    .minutes(minutes)
);

endmodule