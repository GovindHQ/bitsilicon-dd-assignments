`timescale 1ns / 1ps


module seconds_counter (
    input wire clk,
    input wire rst_n,
    input wire clear,        
    input wire enable,       // Count enable from FSM
    output reg [5:0] sec_count,
    output reg sec_ovf       // Overflow signal to minutes counter
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            sec_count <= 0;
            sec_ovf <= 0;
        end else if (clear) begin
            sec_count <= 0;
            sec_ovf <= 0;
        end else if (enable) begin
            sec_ovf <= 0; // Default
            if (sec_count == 59) begin
                sec_count <= 0;
                sec_ovf <= 1; // Trigger minute increment
            end else begin
                sec_count <= sec_count + 1;
            end
        end
    end
endmodule