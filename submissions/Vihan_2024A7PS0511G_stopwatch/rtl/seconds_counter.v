//The comments have been made after understanding the whole code although it is written with the help of artificial intelligence
// and the comments are solely made by the user and not artificial intelligence

module seconds_counter (
    input  wire       clk, //input clock is taken
    input  wire       rst_n,//active low async reset
    input  wire       en,//enable signal for counter....counter only starts once en is high (1)
    input  wire       clr,//clear signal for counter and reset it to 0
    output reg [5:0]  seconds,//output seconds (6 bit output as 2^6 = 64 and we need to calculate till 59 seconds)
    output wire       rollover //rollover signal (when high it means that minutes_counter will increment by 1 as 59 seconds have ticked already)
);
    //start to calculate the seconds
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) 
            seconds <= 6'd0; //hardware reset
        else if (clr)
            seconds <= 6'd0; //FSM reset
        else if (en) begin
            if (seconds == 6'd59)
                seconds <= 6'd0; //if already 59 then reset it to 0 and rollover will increment minutes by 1 if en=1
            else
                seconds <= seconds + 1'b1; //else increment seconds by 1
        end
    end
    //assigning rollover when en is high and seconds have reached 59
    assign rollover = (en && (seconds == 6'd59));
endmodule