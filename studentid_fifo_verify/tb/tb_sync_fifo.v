// tb_sync_fifo.v  –  GRUELLING self-checking testbench for sync_fifo_top
//
// Tests included:
//  Directed (spec-required):
//   T01  Reset
//   T02  Single Write / Read
//   T03  Fill (full condition)
//   T04  Drain (empty condition)
//   T05  Overflow attempt
//   T06  Underflow attempt
//   T07  Simultaneous Read/Write
//   T08  Pointer Wrap-Around
//
//  Extra stress tests:
//   T09  Multiple resets mid-operation
//   T10  Back-to-back burst write then burst read
//   T11  Alternating single write / single read (steady-state)
//   T12  Simultaneous R/W at full boundary
//   T13  Near-empty boundary (count=1)
//   T14  Near-full boundary (count=DEPTH-1)
//   T15  All-zeros data pattern
//   T16  All-ones data pattern
//   T17  Walking-ones data pattern
//   T18  Walking-zeros data pattern
//   T19  Alternating 0xAA / 0x55 checkerboard pattern
//   T20  Double wrap-around (pointers wrap twice)
//   T21  Reset after partial fill, verify clean restart
//   T22  Long random stress (5 seeds x 500 cycles)
//   T23  Rapid fill+drain cycles (10 back-to-back)
//   T24  Write-heavy random (75% write probability)
//   T25  Read-heavy random (75% read probability)

`timescale 1ns/1ps

module tb_sync_fifo;

    // =========================================================================
    // Parameters
    // =========================================================================
    parameter integer DATA_WIDTH = 8;
    parameter integer DEPTH      = 16;
    parameter integer ADDR_WIDTH = 4;

    localparam real CLK_PERIOD = 10.0;

    // =========================================================================
    // DUT signals
    // =========================================================================
    reg                   clk;
    reg                   rst_n;
    reg                   wr_en;
    reg  [DATA_WIDTH-1:0] wr_data;
    wire                  wr_full;
    reg                   rd_en;
    wire [DATA_WIDTH-1:0] rd_data;
    wire                  rd_empty;
    wire [ADDR_WIDTH:0]   count;

    // =========================================================================
    // DUT instantiation
    // =========================================================================
    sync_fifo_top #(
        .DATA_WIDTH (DATA_WIDTH),
        .DEPTH      (DEPTH)
    ) dut (
        .clk      (clk),
        .rst_n    (rst_n),
        .wr_en    (wr_en),
        .wr_data  (wr_data),
        .wr_full  (wr_full),
        .rd_en    (rd_en),
        .rd_data  (rd_data),
        .rd_empty (rd_empty),
        .count    (count)
    );

    // =========================================================================
    // Clock
    // =========================================================================
    initial clk = 0;
    always #(CLK_PERIOD/2.0) clk = ~clk;

    // =========================================================================
    // Golden model state
    // =========================================================================
    reg [DATA_WIDTH-1:0] model_mem    [0:DEPTH-1];
    integer              model_wr_ptr;
    integer              model_rd_ptr;
    integer              model_count;
    reg [DATA_WIDTH-1:0] model_rd_data;

    // =========================================================================
    // Bookkeeping
    // =========================================================================
    integer cycle;
    integer seed;
    reg [255:0] current_test;

    // =========================================================================
    // Coverage counters
    // =========================================================================
    integer cov_full;
    integer cov_empty;
    integer cov_wrap;
    integer cov_simul;
    integer cov_overflow;
    integer cov_underflow;
    integer cov_near_full;
    integer cov_near_empty;
    integer cov_reset_mid;
    integer cov_burst_wr;
    integer cov_burst_rd;

    reg [ADDR_WIDTH-1:0] prev_wr_ptr_model;
    reg [ADDR_WIDTH-1:0] prev_rd_ptr_model;
    integer consec_wr;
    integer consec_rd;

    // =========================================================================
    // Golden model + scoreboard
    // =========================================================================
    always @(posedge clk) begin : golden_and_score
        prev_wr_ptr_model <= model_wr_ptr[ADDR_WIDTH-1:0];
        prev_rd_ptr_model <= model_rd_ptr[ADDR_WIDTH-1:0];

        if (rst_n) begin
            begin : model_update
                integer snap_count;
                snap_count = model_count;

                if (wr_en && (snap_count == DEPTH))   cov_overflow  = cov_overflow  + 1;
                if (rd_en && (snap_count == 0))        cov_underflow = cov_underflow + 1;
                if (snap_count == DEPTH-1)             cov_near_full  = cov_near_full  + 1;
                if (snap_count == 1)                   cov_near_empty = cov_near_empty + 1;

                if (wr_en && !rd_en && (snap_count < DEPTH)) consec_wr = consec_wr + 1;
                else                                          consec_wr = 0;
                if (rd_en && !wr_en && (snap_count > 0))     consec_rd = consec_rd + 1;
                else                                          consec_rd = 0;
                if (consec_wr > 1) cov_burst_wr = cov_burst_wr + 1;
                if (consec_rd > 1) cov_burst_rd = cov_burst_rd + 1;

                if (wr_en && (snap_count < DEPTH) && rd_en && (snap_count > 0)) begin
                    model_mem[model_wr_ptr] = wr_data;
                    model_wr_ptr  = (model_wr_ptr == DEPTH-1) ? 0 : model_wr_ptr + 1;
                    model_rd_data = model_mem[model_rd_ptr];
                    model_rd_ptr  = (model_rd_ptr == DEPTH-1) ? 0 : model_rd_ptr + 1;
                    cov_simul = cov_simul + 1;
                end else begin
                    if (wr_en && (snap_count < DEPTH)) begin
                        model_mem[model_wr_ptr] = wr_data;
                        model_wr_ptr = (model_wr_ptr == DEPTH-1) ? 0 : model_wr_ptr + 1;
                        model_count  = model_count + 1;
                    end
                    if (rd_en && (snap_count > 0)) begin
                        model_rd_data = model_mem[model_rd_ptr];
                        model_rd_ptr  = (model_rd_ptr == DEPTH-1) ? 0 : model_rd_ptr + 1;
                        model_count   = model_count - 1;
                    end
                end
            end

            if (model_count == DEPTH) cov_full  = cov_full  + 1;
            if (model_count == 0)     cov_empty = cov_empty + 1;
            if ((prev_wr_ptr_model == DEPTH-1) && (model_wr_ptr == 0)
                 && (model_wr_ptr != prev_wr_ptr_model))
                cov_wrap = cov_wrap + 1;
            if ((prev_rd_ptr_model == DEPTH-1) && (model_rd_ptr == 0)
                 && (model_rd_ptr != prev_rd_ptr_model))
                cov_wrap = cov_wrap + 1;

            // Scoreboard
            #1;

            if (rd_en && !rd_empty) begin
                if (rd_data !== model_rd_data) begin
                    $display("==============================================");
                    $display("SCOREBOARD ERROR  time=%0t  cycle=%0d", $time, cycle);
                    $display("  Test     : %s", current_test);
                    $display("  Seed     : %0d", seed);
                    $display("  Signal   : rd_data");
                    $display("  Expected : 0x%02h", model_rd_data);
                    $display("  Got      : 0x%02h", rd_data);
                    $display("  Inputs   : wr_en=%b wr_data=0x%02h rd_en=%b", wr_en, wr_data, rd_en);
                    $display("  Model    : wr_ptr=%0d rd_ptr=%0d count=%0d",
                             model_wr_ptr, model_rd_ptr, model_count);
                    $display("==============================================");
                    $finish;
                end
            end

            if (count !== model_count) begin
                $display("==============================================");
                $display("SCOREBOARD ERROR  time=%0t  cycle=%0d", $time, cycle);
                $display("  Test     : %s", current_test);
                $display("  Seed     : %0d", seed);
                $display("  Signal   : count");
                $display("  Expected : %0d  Got : %0d", model_count, count);
                $display("  Inputs   : wr_en=%b wr_data=0x%02h rd_en=%b", wr_en, wr_data, rd_en);
                $display("  Model    : wr_ptr=%0d rd_ptr=%0d count=%0d",
                         model_wr_ptr, model_rd_ptr, model_count);
                $display("==============================================");
                $finish;
            end

            if (rd_empty !== (model_count == 0)) begin
                $display("==============================================");
                $display("SCOREBOARD ERROR  time=%0t  cycle=%0d", $time, cycle);
                $display("  Test     : %s", current_test);
                $display("  Signal   : rd_empty  Expected=%b  Got=%b",
                         (model_count==0), rd_empty);
                $display("==============================================");
                $finish;
            end

            if (wr_full !== (model_count == DEPTH)) begin
                $display("==============================================");
                $display("SCOREBOARD ERROR  time=%0t  cycle=%0d", $time, cycle);
                $display("  Test     : %s", current_test);
                $display("  Signal   : wr_full  Expected=%b  Got=%b",
                         (model_count==DEPTH), wr_full);
                $display("==============================================");
                $finish;
            end

            cycle = cycle + 1;
        end
    end

    // =========================================================================
    // Tasks
    // =========================================================================
    task apply_reset;
        integer i;
        begin
            rst_n = 0; wr_en = 0; rd_en = 0; wr_data = 0;
            model_wr_ptr = 0; model_rd_ptr = 0;
            model_count = 0; model_rd_data = 0;
            consec_wr = 0; consec_rd = 0;
            for (i = 0; i < DEPTH; i = i + 1) model_mem[i] = 0;
            repeat (3) @(posedge clk);
            @(negedge clk); rst_n = 1;
            @(posedge clk);
        end
    endtask

    task apply_mid_reset;
        integer i;
        begin
            if (model_count > 0) cov_reset_mid = cov_reset_mid + 1;
            @(negedge clk); rst_n = 0; wr_en = 0; rd_en = 0;
            model_wr_ptr = 0; model_rd_ptr = 0;
            model_count = 0; model_rd_data = 0;
            consec_wr = 0; consec_rd = 0;
            for (i = 0; i < DEPTH; i = i + 1) model_mem[i] = 0;
            repeat (3) @(posedge clk);
            @(negedge clk); rst_n = 1;
            @(posedge clk);
        end
    endtask

    task drive_cycle;
        input                  t_wr_en;
        input [DATA_WIDTH-1:0] t_wr_data;
        input                  t_rd_en;
        begin
            @(negedge clk);
            wr_en = t_wr_en; wr_data = t_wr_data; rd_en = t_rd_en;
            @(posedge clk); #2;
        end
    endtask

    task idle; begin drive_cycle(0, 0, 0); end endtask

    task fill_fifo;
        input [DATA_WIDTH-1:0] base;
        integer i;
        begin
            for (i = 0; i < DEPTH; i = i + 1)
                drive_cycle(1, base + i[DATA_WIDTH-1:0], 0);
        end
    endtask

    task drain_fifo;
        integer i;
        begin
            for (i = 0; i < DEPTH; i = i + 1)
                drive_cycle(0, 0, 1);
        end
    endtask

    // =========================================================================
    // T01 – Reset
    // =========================================================================
    task test_reset;
        begin
            current_test = "T01_RESET";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset; idle;
            if (rd_empty!==1||wr_full!==0||count!==0) begin
                $display("FAIL %s", current_test); $finish; end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T02 – Single Write / Read
    // =========================================================================
    task test_single_wr_rd;
        begin
            current_test = "T02_SINGLE_WR_RD";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            drive_cycle(1, 8'hA5, 0);
            if (count!==1) begin $display("FAIL %s count!=1",current_test);$finish;end
            drive_cycle(0, 0, 1);
            if (rd_data!==8'hA5) begin $display("FAIL %s data mismatch",current_test);$finish;end
            if (count!==0) begin $display("FAIL %s count!=0",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T03 – Fill
    // =========================================================================
    task test_fill;
        begin
            current_test = "T03_FILL";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset; fill_fifo(8'h00); idle;
            if (count!==DEPTH||wr_full!==1) begin
                $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T04 – Drain
    // =========================================================================
    task test_drain;
        begin
            current_test = "T04_DRAIN";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset; fill_fifo(8'h10); drain_fifo; idle;
            if (count!==0||rd_empty!==1) begin
                $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T05 – Overflow Attempt
    // =========================================================================
    task test_overflow;
        integer i;
        begin
            current_test = "T05_OVERFLOW";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset; fill_fifo(8'h20);
            for (i=0;i<5;i=i+1) drive_cycle(1,8'hFF,0);
            idle;
            if (count!==DEPTH) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T06 – Underflow Attempt
    // =========================================================================
    task test_underflow;
        integer i;
        begin
            current_test = "T06_UNDERFLOW";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<5;i=i+1) drive_cycle(0,0,1);
            idle;
            if (count!==0) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T07 – Simultaneous R/W
    // =========================================================================
    task test_simul;
        integer i; integer cnt_before;
        begin
            current_test = "T07_SIMUL_RW";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DEPTH/2;i=i+1) drive_cycle(1,8'h40+i[DATA_WIDTH-1:0],0);
            cnt_before = count;
            for (i=0;i<8;i=i+1) drive_cycle(1,8'h80+i[DATA_WIDTH-1:0],1);
            idle;
            if (count!==cnt_before) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T08 – Pointer Wrap-Around
    // =========================================================================
    task test_wrap;
        integer i;
        begin
            current_test = "T08_WRAP";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DEPTH-2;i=i+1) drive_cycle(1,i[DATA_WIDTH-1:0],0);
            for (i=0;i<DEPTH-2;i=i+1) drive_cycle(0,0,1);
            for (i=0;i<DEPTH;i=i+1)   drive_cycle(1,8'hC0+i[DATA_WIDTH-1:0],0);
            for (i=0;i<DEPTH;i=i+1)   drive_cycle(0,0,1);
            idle;
            if (count!==0) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T09 – Multiple Resets Mid-Operation
    // =========================================================================
    task test_mid_resets;
        integer i;
        begin
            current_test = "T09_MID_RESETS";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DEPTH/2;i=i+1) drive_cycle(1,8'hAA+i[DATA_WIDTH-1:0],0);
            apply_mid_reset;
            if (count!==0||rd_empty!==1||wr_full!==0) begin
                $display("FAIL %s after reset1",current_test);$finish;end
            for (i=0;i<DEPTH;i=i+1) drive_cycle(1,i[DATA_WIDTH-1:0],0);
            apply_mid_reset;
            if (count!==0||rd_empty!==1) begin
                $display("FAIL %s after reset2",current_test);$finish;end
            for (i=0;i<DEPTH/2;i=i+1) drive_cycle(1,i[DATA_WIDTH-1:0],0);
            for (i=0;i<3;i=i+1)        drive_cycle(0,0,1);
            apply_mid_reset;
            if (count!==0) begin $display("FAIL %s after reset3",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T10 – Burst Write then Burst Read
    // =========================================================================
    task test_burst;
        integer i;
        begin
            current_test = "T10_BURST";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DEPTH;i=i+1) drive_cycle(1,8'hB0+i[DATA_WIDTH-1:0],0);
            for (i=0;i<DEPTH;i=i+1) drive_cycle(0,0,1);
            idle;
            if (count!==0) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T11 – Alternating Single Write / Read
    // =========================================================================
    task test_alternating;
        integer i;
        begin
            current_test = "T11_ALTERNATING";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            drive_cycle(1, 8'h01, 0);
            for (i=0;i<64;i=i+1) begin
                drive_cycle(1, i[DATA_WIDTH-1:0], 0);
                drive_cycle(0, 0, 1);
            end
            drive_cycle(0, 0, 1);
            idle;
            if (count!==0) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T12 – Simultaneous R/W at Full Boundary
    // =========================================================================
    task test_simul_at_full;
        integer i;
        begin
            current_test = "T12_SIMUL_AT_FULL";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            fill_fifo(8'hD0);
            for (i=0;i<8;i=i+1) drive_cycle(1,8'hE0+i[DATA_WIDTH-1:0],1);
            drain_fifo; idle;
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T13 – Near-Empty Boundary
    // =========================================================================
    task test_near_empty;
        integer i;
        begin
            current_test = "T13_NEAR_EMPTY";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            drive_cycle(1, 8'h77, 0);
            for (i=0;i<5;i=i+1) drive_cycle(0,0,1);
            drive_cycle(1, 8'h88, 0);
            drive_cycle(0, 0, 1);
            idle;
            if (count!==0) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T14 – Near-Full Boundary
    // =========================================================================
    task test_near_full;
        integer i;
        begin
            current_test = "T14_NEAR_FULL";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DEPTH-1;i=i+1) drive_cycle(1,i[DATA_WIDTH-1:0],0);
            for (i=0;i<5;i=i+1) drive_cycle(1,8'hF0+i[DATA_WIDTH-1:0],0);
            if (count!==DEPTH) begin $display("FAIL %s count!=DEPTH",current_test);$finish;end
            drain_fifo; idle;
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T15 – All-Zeros
    // =========================================================================
    task test_all_zeros;
        integer i;
        begin
            current_test = "T15_ALL_ZEROS";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DEPTH;i=i+1) drive_cycle(1,8'h00,0);
            for (i=0;i<DEPTH;i=i+1) drive_cycle(0,0,1);
            idle;
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T16 – All-Ones
    // =========================================================================
    task test_all_ones;
        integer i;
        begin
            current_test = "T16_ALL_ONES";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DEPTH;i=i+1) drive_cycle(1,8'hFF,0);
            for (i=0;i<DEPTH;i=i+1) drive_cycle(0,0,1);
            idle;
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T17 – Walking Ones
    // =========================================================================
    task test_walking_ones;
        integer i;
        begin
            current_test = "T17_WALKING_ONES";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DATA_WIDTH;i=i+1) drive_cycle(1,(1<<i),0);
            for (i=0;i<DATA_WIDTH;i=i+1) drive_cycle(0,0,1);
            idle;
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T18 – Walking Zeros
    // =========================================================================
    task test_walking_zeros;
        integer i;
        begin
            current_test = "T18_WALKING_ZEROS";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DATA_WIDTH;i=i+1) drive_cycle(1,~(1<<i),0);
            for (i=0;i<DATA_WIDTH;i=i+1) drive_cycle(0,0,1);
            idle;
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T19 – Checkerboard 0xAA/0x55
    // =========================================================================
    task test_checkerboard;
        integer i;
        reg [DATA_WIDTH-1:0] pat;
        begin
            current_test = "T19_CHECKERBOARD";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DEPTH;i=i+1) begin
                pat = (i%2==0) ? 8'hAA : 8'h55;
                drive_cycle(1,pat,0);
            end
            for (i=0;i<DEPTH;i=i+1) drive_cycle(0,0,1);
            idle;
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T20 – Double Wrap-Around
    // =========================================================================
    task test_double_wrap;
        begin
            current_test = "T20_DOUBLE_WRAP";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            repeat(3) begin fill_fifo(8'hC0); drain_fifo; end
            idle;
            if (count!==0) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T21 – Reset After Partial Fill
    // =========================================================================
    task test_reset_restart;
        integer i;
        begin
            current_test = "T21_RESET_RESTART";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<DEPTH/2;i=i+1) drive_cycle(1,8'hDE,0);
            apply_mid_reset;
            for (i=0;i<DEPTH;i=i+1) drive_cycle(1,i[DATA_WIDTH-1:0],0);
            for (i=0;i<DEPTH;i=i+1) drive_cycle(0,0,1);
            idle;
            if (count!==0) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T22 – Long Random Stress (5 seeds x 500 cycles)
    // =========================================================================
    task test_long_random;
        integer i, s, r_wr, r_rd;
        reg [DATA_WIDTH-1:0] r_data;
        begin
            current_test = "T22_LONG_RANDOM";
            $display("[%0t] %-35s ...", $time, current_test);
            for (s=0;s<5;s=s+1) begin
                seed = 100 + s*37;
                apply_reset;
                for (i=0;i<500;i=i+1) begin
                    r_wr  = $random(seed)%2;
                    r_rd  = $random(seed)%2;
                    r_data= $random(seed);
                    drive_cycle(r_wr[0],r_data,r_rd[0]);
                end
            end
            $display("[%0t] PASS: %s (5 seeds x 500 cycles)", $time, current_test);
        end
    endtask

    // =========================================================================
    // T23 – Rapid Fill+Drain Cycles
    // =========================================================================
    task test_rapid_cycles;
        integer i;
        begin
            current_test = "T23_RAPID_CYCLES";
            $display("[%0t] %-35s ...", $time, current_test);
            apply_reset;
            for (i=0;i<10;i=i+1) begin
                fill_fifo(i[DATA_WIDTH-1:0]<<4);
                drain_fifo;
            end
            idle;
            if (count!==0) begin $display("FAIL %s",current_test);$finish;end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T24 – Write-Heavy Random (75% write)
    // =========================================================================
    task test_write_heavy;
        integer i, r;
        reg [DATA_WIDTH-1:0] r_data;
        begin
            current_test = "T24_WRITE_HEAVY";
            $display("[%0t] %-35s ...", $time, current_test);
            seed = 999;
            apply_reset;
            for (i=0;i<500;i=i+1) begin
                r=      $random(seed)%4;
                r_data= $random(seed);
                drive_cycle((r!=3),r_data,(r==3));
            end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // T25 – Read-Heavy Random (75% read)
    // =========================================================================
    task test_read_heavy;
        integer i, r;
        reg [DATA_WIDTH-1:0] r_data;
        begin
            current_test = "T25_READ_HEAVY";
            $display("[%0t] %-35s ...", $time, current_test);
            seed = 12345;
            apply_reset;
            fill_fifo(8'h50);
            for (i=0;i<500;i=i+1) begin
                r=      $random(seed)%4;
                r_data= $random(seed);
                drive_cycle((r==0),r_data,(r!=0));
            end
            $display("[%0t] PASS: %s", $time, current_test);
        end
    endtask

    // =========================================================================
    // Main
    // =========================================================================
    initial begin
        clk=0; rst_n=0; wr_en=0; rd_en=0; wr_data=0;
        cycle=0; seed=42; current_test="INIT";
        consec_wr=0; consec_rd=0;
        cov_full=0; cov_empty=0; cov_wrap=0; cov_simul=0;
        cov_overflow=0; cov_underflow=0;
        cov_near_full=0; cov_near_empty=0; cov_reset_mid=0;
        cov_burst_wr=0; cov_burst_rd=0;
        model_wr_ptr=0; model_rd_ptr=0; model_count=0; model_rd_data=0;

        $dumpfile("fifo.vcd");
        $dumpvars(0, tb_sync_fifo);

        $display("==============================================");
        $display("  SYNC FIFO GRUELLING TESTBENCH  (25 tests)");
        $display("==============================================");

        // Spec-required
        test_reset;
        test_single_wr_rd;
        test_fill;
        test_drain;
        test_overflow;
        test_underflow;
        test_simul;
        test_wrap;
        // Extra stress
        test_mid_resets;
        test_burst;
        test_alternating;
        test_simul_at_full;
        test_near_empty;
        test_near_full;
        test_all_zeros;
        test_all_ones;
        test_walking_ones;
        test_walking_zeros;
        test_checkerboard;
        test_double_wrap;
        test_reset_restart;
        test_long_random;
        test_rapid_cycles;
        test_write_heavy;
        test_read_heavy;

        $display("");
        $display("==============================================");
        $display("  COVERAGE SUMMARY");
        $display("==============================================");
        $display("  cov_full       = %0d", cov_full);
        $display("  cov_empty      = %0d", cov_empty);
        $display("  cov_wrap       = %0d", cov_wrap);
        $display("  cov_simul      = %0d", cov_simul);
        $display("  cov_overflow   = %0d", cov_overflow);
        $display("  cov_underflow  = %0d", cov_underflow);
        $display("  cov_near_full  = %0d", cov_near_full);
        $display("  cov_near_empty = %0d", cov_near_empty);
        $display("  cov_reset_mid  = %0d", cov_reset_mid);
        $display("  cov_burst_wr   = %0d", cov_burst_wr);
        $display("  cov_burst_rd   = %0d", cov_burst_rd);
        $display("==============================================");

        begin : cov_check
            integer fail; fail=0;
            if(cov_full==0)      begin $display("WARNING: cov_full=0");      fail=1;end
            if(cov_empty==0)     begin $display("WARNING: cov_empty=0");     fail=1;end
            if(cov_wrap==0)      begin $display("WARNING: cov_wrap=0");      fail=1;end
            if(cov_simul==0)     begin $display("WARNING: cov_simul=0");     fail=1;end
            if(cov_overflow==0)  begin $display("WARNING: cov_overflow=0");  fail=1;end
            if(cov_underflow==0) begin $display("WARNING: cov_underflow=0"); fail=1;end
            if(cov_near_full==0)  begin $display("WARNING: cov_near_full=0");  fail=1;end
            if(cov_near_empty==0) begin $display("WARNING: cov_near_empty=0"); fail=1;end
            if(cov_reset_mid==0)  begin $display("WARNING: cov_reset_mid=0");  fail=1;end
            if(cov_burst_wr==0)   begin $display("WARNING: cov_burst_wr=0");   fail=1;end
            if(cov_burst_rd==0)   begin $display("WARNING: cov_burst_rd=0");   fail=1;end
            if(fail==0) $display("All 11 coverage bins non-zero. Coverage adequate.");
        end

        $display("==============================================");
        $display("  ALL 25 TESTS PASSED  |  Total cycles = %0d", cycle);
        $display("==============================================");
        $finish;
    end

endmodule
