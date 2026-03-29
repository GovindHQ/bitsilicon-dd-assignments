module sync_fifo #(
    parameter integer DATA_WIDTH = 8,
    parameter integer DEPTH      = 16
)(
    input  wire                   clk,
    input  wire                   rst_n,    // Active low synchronous reset
    input  wire                   wr_en,
    input  wire [DATA_WIDTH-1:0]  wr_data,
    output wire                   wr_full,
    input  wire                   rd_en,
    output reg  [DATA_WIDTH-1:0]  rd_data,
    output wire                   rd_empty,
    output reg  [clog2(DEPTH): 0] count     // Tracks no. of items stored
);

    //  function to  calculate no. of address bits needed for FIFO depth. 
    function integer clog2;
        input integer depth;
        integer i;
        begin
            clog2 = 0;
            for (i = depth - 1; i > 0; i = i >> 1) begin
                clog2 = clog2 + 1;
            end
        end
    endfunction

    localparam ADDR_WIDTH = clog2(DEPTH);

    // Internal storage and pointers 
    reg [DATA_WIDTH-1:0] mem [0:DEPTH-1]; // memory array
    reg [ADDR_WIDTH-1:0] wr_ptr;          // Points to  next write location
    reg [ADDR_WIDTH-1:0] rd_ptr;          // Points to next read location

    //  status flags
    assign rd_empty = (count == 0);
    assign wr_full  = (count == DEPTH);

    // hardware logic 
    always @(posedge clk) begin
        if (!rst_n) begin
            // Reset everything to zero when reset is active 
            wr_ptr  <= 0;
            rd_ptr  <= 0;
            count   <= 0;
            rd_data <= 0;
        end else begin
            // 1. Write Operation 
            if (wr_en && !wr_full) begin
                mem[wr_ptr] <= wr_data;
                wr_ptr      <= (wr_ptr == DEPTH-1) ? 0 : wr_ptr + 1;
            end

            // 2. Read Operation
            if (rd_en && !rd_empty) begin
                rd_data <= mem[rd_ptr];
                rd_ptr  <= (rd_ptr == DEPTH-1) ? 0 : rd_ptr + 1;
            end

            // 3. No. of items Update 
            // If we write but don't read, count goes up
            if ((wr_en && !wr_full) && !(rd_en && !rd_empty)) begin
                count <= count + 1;
            // If we read but don't write, count goes down
            end else if (!(wr_en && !wr_full) && (rd_en && !rd_empty)) begin
                count <= count - 1;
            end
            
        end
    end

endmodule