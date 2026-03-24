// sync_fifo.v
// Synchronous FIFO core module
// Instantiated by sync_fifo_top

module sync_fifo #(
    parameter integer DATA_WIDTH = 8,
    parameter integer DEPTH      = 16,
    parameter integer ADDR_WIDTH = $clog2(DEPTH)  // safe default if instantiated standalone
) (
    input  wire                  clk,
    input  wire                  rst_n,       // active-low synchronous reset
    input  wire                  wr_en,
    input  wire [DATA_WIDTH-1:0] wr_data,
    output wire                  wr_full,
    input  wire                  rd_en,
    output reg  [DATA_WIDTH-1:0] rd_data,
    output wire                  rd_empty,
    output wire [ADDR_WIDTH:0]   count
);

    // -------------------------------------------------------------------------
    // Internal storage
    // -------------------------------------------------------------------------
    reg [DATA_WIDTH-1:0] mem [0:DEPTH-1];

    // -------------------------------------------------------------------------
    // Pointers and occupancy counter
    // -------------------------------------------------------------------------
    reg [ADDR_WIDTH-1:0] wr_ptr;
    reg [ADDR_WIDTH-1:0] rd_ptr;
    reg [ADDR_WIDTH:0]   count_r;

    assign count    = count_r;
    assign rd_empty = (count_r == 0);
    assign wr_full  = (count_r == DEPTH);

    // -------------------------------------------------------------------------
    // Valid operation qualifiers
    // -------------------------------------------------------------------------
    wire valid_wr = wr_en & ~wr_full;
    wire valid_rd = rd_en & ~rd_empty;

    // -------------------------------------------------------------------------
    // Synchronous logic
    // -------------------------------------------------------------------------
    always @(posedge clk) begin
        if (!rst_n) begin
            wr_ptr  <= {ADDR_WIDTH{1'b0}};
            rd_ptr  <= {ADDR_WIDTH{1'b0}};
            count_r <= {(ADDR_WIDTH+1){1'b0}};
            rd_data <= {DATA_WIDTH{1'b0}};
        end else begin
            // Write port
            if (valid_wr) begin
                mem[wr_ptr] <= wr_data;
                wr_ptr      <= (wr_ptr == DEPTH-1) ? {ADDR_WIDTH{1'b0}} : wr_ptr + 1'b1;
            end

            // Read port
            if (valid_rd) begin
                rd_data <= mem[rd_ptr];
                rd_ptr  <= (rd_ptr == DEPTH-1) ? {ADDR_WIDTH{1'b0}} : rd_ptr + 1'b1;
            end

            // Occupancy counter
            // Simultaneous valid read+write => count unchanged
            if (valid_wr && !valid_rd)
                count_r <= count_r + 1'b1;
            else if (valid_rd && !valid_wr)
                count_r <= count_r - 1'b1;
            // else (neither, or both) => unchanged
        end
    end

endmodule
