// sync_fifo_top.v
// Top-level synchronous FIFO module.
// Computes ADDR_WIDTH = clog2(DEPTH) via a Verilog function and
// instantiates the core sync_fifo module.

module sync_fifo_top #(
    parameter integer DATA_WIDTH = 8,
    parameter integer DEPTH      = 16,
    parameter integer ADDR_WIDTH = $clog2(DEPTH)
) (
    input  wire                      clk,
    input  wire                      rst_n,      // active-low synchronous reset
    input  wire                      wr_en,
    input  wire [DATA_WIDTH-1:0]     wr_data,
    output wire                      wr_full,
    input  wire                      rd_en,
    output wire [DATA_WIDTH-1:0]     rd_data,
    output wire                      rd_empty,
    output wire [ADDR_WIDTH:0]       count
);

    // -------------------------------------------------------------------------
    // Internal wire for rd_data from core
    // -------------------------------------------------------------------------
    wire [DATA_WIDTH-1:0] rd_data_w;

    assign rd_data = rd_data_w;

    // -------------------------------------------------------------------------
    // Core instantiation
    // -------------------------------------------------------------------------
    sync_fifo #(
        .DATA_WIDTH (DATA_WIDTH),
        .DEPTH      (DEPTH),
        .ADDR_WIDTH (ADDR_WIDTH)
    ) u_sync_fifo (
        .clk      (clk),
        .rst_n    (rst_n),
        .wr_en    (wr_en),
        .wr_data  (wr_data),
        .wr_full  (wr_full),
        .rd_en    (rd_en),
        .rd_data  (rd_data_w),
        .rd_empty (rd_empty),
        .count    (count)
    );

endmodule
