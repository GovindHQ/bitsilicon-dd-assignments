module minutes_counter #(
    parameter MAX_MINUTES = 8'd99
) (
    input  wire      clk,
    input  wire      rst_n,       
    input  wire      reset,       
    input  wire      enable_min,  
    output reg [7:0] minutes      
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            minutes <= 8'd0;
        end else begin
            if (reset) begin
                minutes <= 8'd0;
            end else if (enable_min) begin
                if (minutes == MAX_MINUTES)
                    minutes <= 8'd0;
                else
                    minutes <= minutes + 8'd1;
            end
        end
    end

endmodule

