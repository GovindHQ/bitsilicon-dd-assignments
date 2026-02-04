module seconds_counter (
    input wire clk,
    input wire rst_n,
    input wire reset,
    input wire en,
    output reg [5:0] count,
    output wire rollover
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n || reset) begin
            count <= 6'd0;
        end else if (en) begin
            if (count == 6'd59)
                count <= 6'd0;
            else
                count <= count + 1'b1;
        end
    end

    assign rollover = en && (count == 6'd59);

endmodule