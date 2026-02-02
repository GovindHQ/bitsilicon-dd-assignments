module seconds_counter (
    input  wire       clk,
    input  wire       rst_n,        
    input  wire       reset,        
    input  wire       enable,       
    output reg [5:0]  seconds,      
    output reg        sec_rollover  
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin 			// if rst_n==0 then seconds -> 00 and rollover- > 0
            seconds     <= 6'd0;
            sec_rollover <= 1'b0;
        end 
	else begin			
            sec_rollover <= 1'b0;
            if (reset) begin
                seconds <= 6'd0;
            end 
	    else if (enable) begin
                if (seconds == 6'd59) begin 	// seconds ->59->00 and rollover -> 1
                    seconds <= 6'd0;
                    sec_rollover <= 1'b1;
                end else begin
                    seconds <= seconds + 6'd1;
                end
            end
        end
    end

endmodule

