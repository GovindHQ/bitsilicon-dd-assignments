module stopwatch_top(input wire clk,
input wire rst_n,
input wire start,
input wire stop,
input wire rst,
output wire [7:0] minutes,
output wire [5:0] seconds,
output wire [1:0] status);

wire tick_connection;
reg [1:0] mode_reg; 
always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        mode_reg <= 2'b00; 
    end else begin
        if (rst) mode_reg <= 2'b00;
        else if (stop) mode_reg <= 2'b01; 
        else if (start) mode_reg <= 2'b10; 
    end
    end
seconds_counter SEC(.clk(clk),.rst(rst_n),.status(mode_reg),.tick_out(tick_connection),.seconds(seconds));
minutes_counter MIN(.clk(clk),.rst(rst_n),.status(mode_reg),.tick_in(tick_connection),.minutes(minutes));
control_fsm FSM(.clk(clk),.mode(mode_reg),.rst(rst_n),.status(status));
endmodule
