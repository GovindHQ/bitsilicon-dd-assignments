// Code your testbench here
// or browse Examples
module sync_fifo_tb;
    localparam TB_DEPTH = 8;
    localparam TB_DATA_WIDTH = 16;
    reg clk;
    reg rst_n;
                 
    reg wr_en;
  reg [TB_DATA_WIDTH-1: 0] wr_data;
    wire wr_full;
                 
    reg rd_en;
    wire [TB_DATA_WIDTH-1:0] rd_data;
    wire rd_empty;

    wire [$clog2(TB_DEPTH): 0] count;

    reg [TB_DATA_WIDTH-1:0] model_mem [0:TB_DEPTH-1];
    integer model_wr_ptr;
    integer model_rd_ptr;
    integer model_count;
    integer model_rd_empty;
    integer model_wr_full;

    integer cov_full;
    integer cov_empty;
    integer cov_wrap;
    integer cov_simul;
    integer cov_overflow;
    integer cov_underflow;

    reg [TB_DATA_WIDTH-1:0] model_rd_data;

    sync_fifo #(.DATA_WIDTH(TB_DATA_WIDTH),
                .DEPTH(TB_DEPTH) 
    ) dut (
                .clk(clk),
                .rst_n(rst_n),

                .wr_en(wr_en),
                .wr_data(wr_data),
                .wr_full(wr_full),

                .rd_empty(rd_empty),
                .rd_data(rd_data),
                .rd_en(rd_en),

                .count(count)
            );
    assign model_rd_empty = (model_count == 0);
    assign model_wr_full = (model_count == TB_DEPTH);

    always @(posedge clk) begin 
        if(!rst_n) begin 
            model_wr_ptr <= 0;
            model_rd_ptr <= 0;
            model_count <= 0;
        end
      else if (!model_wr_full && wr_en && !model_rd_empty && rd_en) begin 
            model_rd_ptr <= model_rd_ptr + 1;
            model_wr_ptr <= model_wr_ptr + 1;
        end
      else if(!model_wr_full && wr_en) begin 
            model_mem[model_wr_ptr] <= wr_data;
            model_wr_ptr <= model_wr_ptr + 1;
            model_count <= model_count + 1;
        end 
      else if (!model_rd_empty && rd_en) begin 
            model_rd_data <= model_mem[model_rd_ptr];
            model_rd_ptr <= model_rd_ptr + 1;
            model_count <= model_count - 1;
        end

        if (model_wr_ptr == TB_DEPTH - 1) model_wr_ptr <= 0;
        if (model_rd_ptr == TB_DEPTH - 1) model_rd_ptr <= 0;
    end

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        wr_en = 0;
        rd_en = 0;
        rst_n = 0;
    	wr_data = 0;
		#15 rst_n = 1;
        $display(" ");
        //Reset test
        $display("Reset test");
        for(integer i = 0; i < 2; i = i +1) begin
            @(negedge clk)
            wr_en = 1;
            wr_data = $random;
            $display("rd_ptr = %0.1d, wr_ptr = %0.1d, count = %0.1d, rd_empty = %0.1d, wr_full = %0.1d", model_rd_ptr, model_wr_ptr, model_count, model_rd_empty, model_wr_full);
        end
        @(negedge clk);
         rst_n = 0;
        
        @(negedge clk);
        wr_en = 0;
        $display("After reset");
        $display("rd_ptr = %0.1d, wr_ptr = %0.1d, count = %0.1d, rd_empty = %0.1d, wr_full = %0.1d", model_rd_ptr, model_wr_ptr, model_count, model_rd_empty, model_wr_full);
       
        #15rst_n = 1;
         $display(" ");
      	//Single Data read/write
        $display("Single Read/Write test");
      for(integer i = 0; i < 1; i = i + 1) begin
        @(negedge clk); 
      	wr_en = 1;
      	wr_data = $random;
         $display("rd_ptr = %0.1d, wr_ptr = %0.1d, count = %0.1d, rd_empty = %0.1d, wr_full = %0.1d", model_rd_ptr, model_wr_ptr, model_count, model_rd_empty, model_wr_full);
      end
      @(negedge clk);
      wr_en = 0;
      for(integer i = 0; i < 1; i = i + 1) begin
            @(negedge clk); 
            rd_en = 1;
            $display("rd_ptr = %0.1d, wr_ptr = %0.1d, count = %0.1d, rd_empty = %0.1d, wr_full = %0.1d", model_rd_ptr, model_wr_ptr, model_count, model_rd_empty, model_wr_full);

        end
        @(negedge clk);
        rd_en = 0; 
        $display("rd_ptr = %0.1d, wr_ptr = %0.1d, count = %0.1d, rd_empty = %0.1d, wr_full = %0.1d", model_rd_ptr, model_wr_ptr, model_count, model_rd_empty, model_wr_full);

        #5 rst_n = 0;
        #5 rst_n = 1;
        $display(" ");

        //Fill test
        $display("Fill test");
        for(integer i = 0; i < 9; i = i+1) begin
            @(negedge clk) ; 
            wr_en = 1;
            wr_data = $random;
        end
        assign cov_full = cov_full + 1;
        $display("wr_full = %d", wr_full);
        $display("count = %d, depth = %d", count, TB_DEPTH);
        
         $display(" ");
        //Overflow attempt
        $display("Overflow attempt");
        for(integer i = 0; i < 2; i = i +1) begin
            @(negedge clk)
            wr_en = 1;
            $display("rd_ptr = %0.1d, wr_ptr = %0.1d, count = %0.1d, rd_empty = %0.1d, wr_full = %0.1d", model_rd_ptr, model_wr_ptr, model_count, model_rd_empty, model_wr_full);

        end
        assign cov_overflow = cov_overflow + 1;
         $display("count = %d, depth = %d", count, TB_DEPTH);
        $display(" ");

        //Drain test
        $display("Drain test");
        @(negedge clk);
        wr_en = 0;
        for(integer i = 0; i < 9; i=i+1) begin
            @(negedge clk)
            rd_en = 1;
        end
        @(negedge clk);
        rd_en = 0;

        $display("rd_empty = %d", rd_empty);
        $display("count = %d, depth = %d", count, TB_DEPTH);
        $display(" ");
        assign cov_empty = cov_empty + 1;


        //Underflow attempt
        $display("Underflow test");
        for(integer i = 0; i < 5; i = i +1)begin
            @(negedge clk);
            rd_en = 1;
            $display("count = %0.1d, rd_ptr = %0.1d, rd_data = %0.1d", count, model_rd_ptr, model_rd_data);
        end
        @(negedge clk)
        rd_en = 0;
        cov_underflow = cov_underflow + 1;
        $display(" ");
       //Simultaneous read/write test
       $display("Simultaneous read/write and Wraping around test");
       for(integer i = 0; i < 3; i= i+1) begin
        @(negedge clk);
        wr_en = 1;
        wr_data = $random;
       end
       @(negedge clk)
       wr_en = 0;

        for(integer i = 0; i < 9; i= i+1) begin
            @(negedge clk);
            rd_en = 1;
            wr_en = 1;
            $display("rd_ptr = %d, wr_ptr = %d, counter = %d", model_rd_ptr, model_wr_ptr, model_count);
        end
        cov_simul = cov_simul + 1;
        cov_wrap = cov_wrap + 1;
        #20;
        $display("");
        $display("Summary");
        $display("cov_full = %0.1d", cov_full);
        $display("cov_empty = %0.1d", cov_empty);
        $display("cov_wrap = %0.1d", cov_wrap);
        $display("cov_simul = %0.1d", cov_simul);
        $display("cov_overflow = %0.1d", cov_overflow);
        $display("cov_underflow = %0.1d", cov_underflow);
        $display("--- Simulation Complete ---");
        $finish();
    end

    // The Scoreboard (Compares DUT vs GRM)
    always @(negedge clk) begin
        // If a read was successfully requested and the FIFO wasn't empty...
        if (rst_n && rd_en && !rd_empty) begin
            // Compare the hardware output to the model output
            if (rd_data !== model_rd_data) begin
                $display("[SCOREBOARD FAIL] Time %0t | Expected: %h, Got: %h", $time, model_rd_data, rd_data);
            end else begin
                $display("[SCOREBOARD PASS] Time %0t | Data Match: %h", $time, rd_data);
            end
        end
    end
      

    
endmodule