module sync_fifo #(parameter integer DATA_WIDTH = 8,
                   parameter integer DEPTH = 16)
( input wire clk,
  input wire rst_n,
                 
  input wire wr_en,
  input wire [DATA_WIDTH-1: 0] wr_data,
  output wire wr_full,
                 
  input wire rd_en,
  output reg [DATA_WIDTH-1:0] rd_data,
  output wire rd_empty,
  output reg [$clog2(DEPTH): 0] count);

  reg [$clog2(DEPTH)-1 : 0] rd_ptr;
  reg [$clog2(DEPTH)-1: 0] wr_ptr;

  reg [DATA_WIDTH-1:0] mem [0:DEPTH-1] ;

  assign rd_empty = (count == 0);
  assign wr_full = (count == DEPTH);

  always @(posedge clk) begin 
    if(!rst_n) begin 
      wr_ptr <= 0;
      rd_ptr <= 0;
      count <= 0;
    end
  end

  always @ (posedge clk) begin 
    if (!wr_full && wr_en && !rd_empty && rd_en) begin 
      wr_ptr <= wr_ptr + 1 ;
      rd_ptr <= rd_ptr + 1 ;
    end else if (!wr_full && wr_en) begin 
      mem[wr_ptr] <= wr_data;
      wr_ptr <= wr_ptr + 1 ;
      count <= count + 1;
    end else if (!rd_empty && rd_en) begin 
      rd_data <= mem[rd_ptr];
      rd_ptr <= rd_ptr + 1;
      count <= count - 1;
    end

    if (wr_ptr == DEPTH - 1) wr_ptr <= 0;
    if (rd_ptr == DEPTH - 1) rd_ptr <= 0;

  end

endmodule
