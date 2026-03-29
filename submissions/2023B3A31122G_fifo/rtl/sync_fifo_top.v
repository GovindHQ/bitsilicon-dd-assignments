module sync_fifo_top #(
    parameter integer DATA_WIDTH = 8,  //No. ofbits each piece of data has
    parameter integer DEPTH      = 16 // No. of total pieces of data the FIFO can hold
)(
    input  wire                   clk,      // system clock
    input  wire                   rst_n,    // Reset signal (active low)
    input  wire                   wr_en,    // Set to 1 for writing data
    input  wire [DATA_WIDTH-1:0]  wr_data,  // The actual data being sent in
    output wire                   wr_full,  // check if FIFO is full before writing
    input  wire                   rd_en,    // Set to 1 for reading data
    output wire [DATA_WIDTH-1:0]  rd_data,  // The data coming out of the FIFO
    output wire                   rd_empty, // checks if FIFO is empty before reading
    output wire [clog2(DEPTH): 0] count     // Shows the no. of items inside
);

    // function to  calculate no. of address bits needed for FIFO depth. 
    
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

   
    // connecting internal logic to top module 
    sync_fifo #(
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(DEPTH)
    ) fifo_inst (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(wr_en),
        .wr_data(wr_data),
        .wr_full(wr_full),
        .rd_en(rd_en),
        .rd_data(rd_data),
        .rd_empty(rd_empty),
        .count(count)
    );

endmodule