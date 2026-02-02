//The comments have been made after understanding the whole code although it is written with the help of artificial intelligence
// and the comments are solely made by the user and not artificial intelligence

module stopwatch_top (
    input  wire       clk, //input clock is taken
    input  wire       rst_n, //active low async reset
    input  wire       start, //to begin
    input  wire       stop, //to end
    input  wire       reset, //to clear time and back to idle position 
    output wire [7:0] minutes, //current minute count (0-99)
    output wire [5:0] seconds, //current second count (0-59)
    output wire [1:0] status //current FSM state
);
    wire count_en;
    wire sec_rollover; 
    wire clr_all;

    control_fsm fsm_inst (
        .clk(clk), .rst_n(rst_n), .start(start), .stop(stop), .reset(reset),
        .state(status), .count_en(count_en), .clear_counters(clr_all)
    ); // This makes an instantiation of the control_fsm module with the suitable parameters

    seconds_counter sec_inst (
        .clk(clk), .rst_n(rst_n), .en(count_en), .clr(clr_all),
        .seconds(seconds), .rollover(sec_rollover)
    ); // This makes an instantiation of the seconds_counter module with the suitable parameters

    minutes_counter min_inst (
        .clk(clk), .rst_n(rst_n), .en(sec_rollover), .clr(clr_all),
        .minutes(minutes)
    ); // This makes an instantiation of the minutes_counter module with the suitable parameters
endmodule