module control_fsm(
    input wire clk,       // Kept for interface consistency
    input wire [1:0] mode,
    input wire rst, 
    output reg [1:0] status
);

always @(*) begin
    if (!rst) begin
        status = 2'b00; 
    end else begin
        case (mode)
            2'b00:status = 2'b00;
            2'b01:status = 2'b01;
            2'b10:status = 2'b10;
            default: status = 2'b00;
        endcase
    end
end

endmodule