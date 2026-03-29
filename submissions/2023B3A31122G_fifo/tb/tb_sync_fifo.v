`timescale 1ns/1ps

module tb_sync_fifo;

    // Parameters and Signals
    parameter DATA_WIDTH = 8;
    parameter DEPTH      = 16;

    reg                     clk;
    reg                     rst_n;
    reg                     wr_en;
    reg [DATA_WIDTH-1:0]    wr_data;
    wire                    wr_full;
    reg                     rd_en;
    wire [DATA_WIDTH-1:0]   rd_data;
    wire                    rd_empty;
    wire [4:0]              count; // Adjust width if depth changes

    // Reference model variables to predict correct results
    reg [DATA_WIDTH-1:0] model_mem [0:DEPTH-1];
    integer              model_wr_ptr;
    integer              model_rd_ptr;
    integer              model_count;
    reg [DATA_WIDTH-1:0] model_rd_data;

    //Counters to track which scenarios are successfully tested
    integer cov_full = 0, cov_empty = 0, cov_wrap = 0;
    integer cov_simul = 0, cov_overflow = 0, cov_underflow = 0;

    // Instantiate the DUT
    sync_fifo_top #(
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(DEPTH)
    ) dut (
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

    // Clock Generation (Toggles every 5 units of time)
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Simulation Logic
    always @(posedge clk) begin
        if (!rst_n) begin
            // When reset is active, clear all model variables
            model_wr_ptr <= 0;
            model_rd_ptr <= 0;
            model_count  <= 0;
            model_rd_data <= 0;
        end else begin
            // Handle Write: Store data if writing and not full
            if (wr_en && (model_count < DEPTH)) begin
                model_mem[model_wr_ptr] <= wr_data;
                // Move the pointer and wrap back to zero if at the end
                model_wr_ptr <= (model_wr_ptr == DEPTH-1) ? 0 : model_wr_ptr + 1;
            end

            // Handle Read: fetch data if reading and not empty
            if (rd_en && (model_count > 0)) begin
                model_rd_data <= model_mem[model_rd_ptr];
                // Move the pointer and wrap back to zero if at the end
                model_rd_ptr  <= (model_rd_ptr == DEPTH-1) ? 0 : model_rd_ptr + 1;
            end

            // Handle the Counter: Track how many items are currently stored
            if ((wr_en && (model_count < DEPTH)) && !(rd_en && (model_count > 0))) begin
                // Write only: increase the count
                model_count <= model_count + 1;
            end else if (!(wr_en && (model_count < DEPTH)) && (rd_en && (model_count > 0))) begin
                // Read only: decrease the count
                model_count <= model_count - 1;
            end
            //If both a read and write happen, the count stays the same
        end
    end
  integer cycle_count = 0;

    // Scoreboard and Coverage Logic
    // This block monitors the simulation and checks for errors
    always @(posedge clk) begin
        if (rst_n) begin
            // Keep track of how many clock cycles have passed
            cycle_count <= cycle_count + 1;
            
            // Wait for a tiny moment (1 unit) to let signals settle 
            // after the clock edge before checking them
            #1;

           
            
            //  Does the data coming out match the predicted data?
            if (rd_en && !rd_empty && (rd_data !== model_rd_data)) begin
                $display("ERROR: Data mismatch at cycle %0d", cycle_count);
                $display("Expected: %h, Got: %h", model_rd_data, rd_data);
                $finish; // Stop simulation immediately on error
            end

            //  Does the occupancy count match the model?
            if (count !== model_count) begin
                $display("ERROR: Count mismatch at cycle %0d", cycle_count);
                $display("Expected: %0d, Got: %0d", model_count, count);
                $finish;
            end

            //  Is the empty flag correct?
            if (rd_empty !== (model_count == 0)) begin
                $display("ERROR: Empty flag mismatch at cycle %0d", cycle_count);
                $finish;
            end

            //  Is the full flag correct?
            if (wr_full !== (model_count == DEPTH)) begin
                $display("ERROR: Full flag mismatch at cycle %0d", cycle_count);
                $finish;
            end

            
            
            // Counting how many times we hit the full and empty states
            if (wr_full) cov_full <= cov_full + 1;
            if (rd_empty) cov_empty <= cov_empty + 1;
            
            // Track simultaneous read and write operations
            if (wr_en && !wr_full && rd_en && !rd_empty) cov_simul <= cov_simul + 1;
            
            // Track attempts to write to a full FIFO (Overflow)
            if (wr_en && wr_full) cov_overflow <= cov_overflow + 1;
            
            // Track attempts to read from an empty FIFO (Underflow)
            if (rd_en && rd_empty) cov_underflow <= cov_underflow + 1;

            // Track when the pointers wrap around back to zero
            if (wr_en && !wr_full && (model_wr_ptr == DEPTH-1)) cov_wrap <= cov_wrap + 1;
            if (rd_en && !rd_empty && (model_rd_ptr == DEPTH-1)) cov_wrap <= cov_wrap + 1;
        end
    end
    
    initial begin
        $dumpfile("dump.vcd");    
        $dumpvars(0, tb_sync_fifo);
        // Initialize all inputs to zero
        rst_n = 0;
        wr_en = 0;
        rd_en = 0;
        wr_data = 0;

        // Ensure everything starts at zero
        $display("Starting Reset Test...");
        #10 rst_n = 0; // Assert reset
        #20 rst_n = 1; // Release reset
        #10;
        $display("Reset Test Passed.");

        // Write one value and read it back
        $display("Starting Single Write/Read Test...");
        @(posedge clk);
        wr_en = 1; wr_data = 8'hAA; // Write hex AA
        @(posedge clk);
        wr_en = 0;
        @(posedge clk);
        rd_en = 1;
        @(posedge clk);
        rd_en = 0;
        $display("Single Write/Read Test Passed.");

        //  Write until the FIFO is completely full
        $display("Starting Fill Test...");
        repeat (DEPTH) begin
            @(posedge clk);
            wr_en = 1; wr_data = $random;
        end
        @(posedge clk);
        wr_en = 0;
        $display("Fill Test Passed.");

        //  Try to write to a full FIFO
        $display("Starting Overflow Test...");
        @(posedge clk);
        wr_en = 1; wr_data = 8'hFF;
        @(posedge clk);
        wr_en = 0;
        $display("Overflow Test Passed.");

        // Read until the FIFO is empty
        $display("Starting Drain Test...");
        repeat (DEPTH) begin
            @(posedge clk);
            rd_en = 1;
        end
        @(posedge clk);
        rd_en = 0;
        $display("Drain Test Passed.");

        //  Try to read from an empty FIFO
        $display("Starting Underflow Test...");
        @(posedge clk);
        rd_en = 1;
        @(posedge clk);
        rd_en = 0;
        $display("Underflow Test Passed.");

        // Simultaneous Read/Write Test
        $display("Starting Simultaneous Read/Write Test...");
        @(posedge clk);
        wr_en = 1; wr_data = 8'h11;
        @(posedge clk);
        wr_en = 1; wr_data = 8'h22; rd_en = 1; // Write and read at the same time
        @(posedge clk);
        wr_en = 0; rd_en = 0;
        $display("Simultaneous Test Passed.");

        //  Force pointers to cross the depth boundary
        $display("Starting Wrap-Around Test...");
        repeat (DEPTH + 5) begin
            @(posedge clk);
            wr_en = 1; wr_data = $random;
            rd_en = 1;
        end
        @(posedge clk);
        wr_en = 0; rd_en = 0;
        $display("Wrap-Around Test Passed.");

        // Print the coverage results
        #100;
        $display("\n--- SIMULATION SUMMARY ---");
        $display("Full Events:      %0d", cov_full);
        $display("Empty Events:     %0d", cov_empty);
        $display("Wrap Events:      %0d", cov_wrap);
        $display("Simultaneous:     %0d", cov_simul);
        $display("Overflow Attempts: %0d", cov_overflow);
        $display("Underflow Attempts:%0d", cov_underflow);
        $display("--------------------------");
        $display("ALL TESTS PASSED");
        $finish;
    end
endmodule