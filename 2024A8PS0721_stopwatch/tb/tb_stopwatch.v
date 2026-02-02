`timescale 1ns/1ps

module tb_stopwatch;

    reg clk;
    reg rst_n;
    reg start;
    reg stop;
    reg reset;

    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    stopwatch_top dut (
        .clk     (clk),
        .rst_n   (rst_n),
        .start   (start),
        .stop    (stop),
        .reset   (reset),
        .minutes (minutes),
        .seconds (seconds),
        .status  (status)
    );

    // Clock generation: 20ns period
    initial begin
        clk = 0;
        forever #10 clk = ~clk;  // 20ns period
    end

    // time in seconds (ns/20)
    integer sim_time_sec;
    always @(posedge clk) begin
        sim_time_sec = $time / 20;
        $display("T=%0d sec | rst_n=%b start=%b stop=%b reset=%b | %02d:%02d status=%b (%s)", 
                 sim_time_sec, rst_n, start, stop, reset, 
                 minutes, seconds, status,
                 status == 2'b00 ? "IDLE"   :
                 status == 2'b01 ? "RUNNING" :
                 status == 2'b10 ? "PAUSED" : "ERROR");
    end

    initial begin
        $display("=== Stopwatch Testbench Started (1sec = 20ns) ===");
        
        // Initialize all inputs
        rst_n  = 0; start = 0; stop = 0; reset = 0;
        
        // 1. Reset release (IDLE state)
        #40;
        rst_n = 1;
        $display("\n--- Reset released, should be IDLE ---");
        repeat (10) @(posedge clk);  

        // 2. START
        $display("\n--- START pressed ---");
        @(posedge clk);
        start = 1; #20; start = 0;  
        
        repeat (50) @(posedge clk);  

        // 3. STOP 
        $display("\n--- STOP pressed (%d:%02d) ---", minutes, seconds);
        @(posedge clk);
        stop = 1; #20; stop = 0;    
        
        repeat (15) @(posedge clk);  

        // 4. START again - should RESUME from current time
        $display("\n--- START to resume ---");
        @(posedge clk);
        start = 1; #20; start = 0;
        
        repeat (35) @(posedge clk);  

        // 5. RESET - should clear to 00:00 IDLE
        $display("\n--- RESET pressed (%d:%02d) ---", minutes, seconds);
        @(posedge clk);
        reset = 1; #20; reset = 0;
        
        repeat (10) @(posedge clk);  

        // 6. Final test: Run to rollover
        $display("\n--- Final run: test second->minute rollover ---");
        @(posedge clk);
        start = 1; #20; start = 0;
        
        repeat (75) @(posedge clk);  // Run 75 seconds (past 60sec rollover)

        $display("\n=== FINAL RESULTS ===");
        $display("Final time: %d:%02d, Status: %b (%s)", 
                 minutes, seconds, status,
                 status == 2'b00 ? "IDLE"   :
                 status == 2'b01 ? "RUNNING" :
                 status == 2'b10 ? "PAUSED" : "ERROR");
        
        #100;  // Final settle
        $display("\n=== Simulation Complete ===");
        $finish;
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            if (minutes != 0 || seconds != 0) 
                $display("ERROR: Time not cleared during reset");
        end
    end

endmodule

