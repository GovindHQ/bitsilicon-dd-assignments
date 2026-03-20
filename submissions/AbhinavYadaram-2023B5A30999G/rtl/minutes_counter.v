`timescale 1ns / 1ps


module minutes_counter (
    input wire clk,
    input wire rst_n,
    input wire clear,
    input wire enable, // Active only when seconds overflows
    output reg [7:0] min_count
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            min_count <= 0;
        end else if (clear) begin
            min_count <= 0;
        end else if (enable) begin
            if (min_count == 99)
                min_count <= 0; // Roll over 
            else
                min_count <= min_count + 1;
        end
    end
endmodule