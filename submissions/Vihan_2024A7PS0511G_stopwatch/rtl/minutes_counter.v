//The comments have been made after understanding the whole code although it is written with the help of artificial intelligence
// and the comments are solely made by the user and not artificial intelligence

module minutes_counter (
    input  wire       clk,// input clock taken
    input  wire       rst_n,//active low async reset
    input  wire       en, // Linked to seconds rollover
    input  wire       clr,//clear signal for counter and reset it to 0
    output reg [7:0]  minutes//output minutes (8 bit output as 2^8 = 256 and we need to calculate till 99 minutes, 7 bit output would also work but 8 bit is more recommended(gemini))
);
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            minutes <= 8'd0; //hardware reset
        else if (clr)
            minutes <= 8'd0; //FSM reset
        else if (en) begin
            if (minutes == 8'd99)
                minutes <= 8'd0; // Roll over at 99
            else
                minutes <= minutes + 1'b1; //else increment minutes by 1
        end
    end
endmodule