module minutes_counter (
    input wire clk,
    input wire rst_n,
    input wire reset,
    input wire en,
    output reg [7:0] count
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n || reset) begin
            count <= 8'd0;
        end else if (en) begin
            if (count == 8'd99)
                count <= 8'd0;
            else
                count <= count + 1'b1;
        end
    end

endmodule