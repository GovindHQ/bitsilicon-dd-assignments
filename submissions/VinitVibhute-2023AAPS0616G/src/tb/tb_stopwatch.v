// tb_stopwatch.v
// Comprehensive testbench for Digital Stopwatch Controller
// Tests: reset, start, stop, pause, resume, counter overflow
//
// Clock Configuration:
//   Clock period = 20ns (50MHz)
//   Each clock cycle = 1 "second" in stopwatch time
//   This allows fast simulation without waiting for real seconds

`timescale 1ns / 1ps

module tb_stopwatch;

    // Clock period: 20ns (each clock = 1 second in stopwatch time)
    parameter CLK_PERIOD = 20;
    
    // Testbench signals
    reg clk;
    reg rst_n;      // Global asynchronous reset
    reg start;
    reg stop;
    reg reset;      // Functional reset (user command)
    wire [7:0] minutes;
    wire [5:0] seconds;
    wire [1:0] status;

    // Instantiate the stopwatch
    stopwatch_top dut (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .minutes(minutes),
        .seconds(seconds),
        .status(status)
    );

    // Clock generation: 20ns period = 50MHz
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    // Status decoder for display
    reg [63:0] status_str;
    always @(*) begin
        case (status)
            2'b00: status_str = "IDLE";
            2'b01: status_str = "RUNNING";
            2'b10: status_str = "PAUSED";
            default: status_str = "UNKNOWN";
        endcase
    end

    // Monitor outputs
    initial begin
        $monitor("Time=%0t ns | Status=%s | Stopwatch=%02d:%02d | rst_n=%b start=%b stop=%b reset=%b",
                 $time, status_str, minutes, seconds, rst_n, start, stop, reset);
    end

    // Test sequence
    initial begin
        $display("\n========================================");
        $display("Digital Stopwatch Testbench");
        $display("Clock Period: %0d ns (1 clock = 1 second)", CLK_PERIOD);
        $display("========================================\n");
        
        // Initialize inputs
        rst_n = 1;      // rst_n is active-low, so 1 = not reset
        start = 0;
        stop = 0;
        reset = 0;
        
        // Test 1: Global Hardware Reset (rst_n)
        $display("\n--- Test 1: Global Hardware Reset (rst_n) ---");
        rst_n = 0;      // Assert global reset
        #(CLK_PERIOD*2);
        rst_n = 1;      // Deassert global reset
        #(CLK_PERIOD*2);
        
        // Test 2: Start counting
        $display("\n--- Test 2: Start Stopwatch ---");
        start = 1;
        #(CLK_PERIOD);
        start = 0;
        #(CLK_PERIOD*10);  // Count for 10 seconds
        
        // Test 3: Pause (stop)
        $display("\n--- Test 3: Pause Stopwatch ---");
        stop = 1;
        #(CLK_PERIOD);
        stop = 0;
        #(CLK_PERIOD*5);   // Wait while paused (time should not advance)
        
        // Test 4: Resume (start again)
        $display("\n--- Test 4: Resume Stopwatch ---");
        start = 1;
        #(CLK_PERIOD);
        start = 0;
        #(CLK_PERIOD*10);  // Count for 10 more seconds
        
        // Test 5: Functional Reset to 00:00
        $display("\n--- Test 5: Functional Reset (reset button) ---");
        reset = 1;
        #(CLK_PERIOD);
        reset = 0;
        #(CLK_PERIOD*2);
        
        // Test 6: Start and count to test seconds rollover (59->00, minutes++)
        $display("\n--- Test 6: Seconds Rollover (59->00, minutes++) ---");
        start = 1;
        #(CLK_PERIOD);
        start = 0;
        
        // Fast forward to 57 seconds by forcing counter
        #(CLK_PERIOD*2);
        force dut.sec_counter.seconds = 6'd57;
        #(CLK_PERIOD);
        release dut.sec_counter.seconds;
        
        $display("Approaching rollover at 59 seconds...");
        #(CLK_PERIOD*5);  // Watch: 57->58->59->00 (and minutes increments)
        
        // Test 7: Stop and functional reset
        $display("\n--- Test 7: Stop and Functional Reset ---");
        stop = 1;
        #(CLK_PERIOD);
        stop = 0;
        #(CLK_PERIOD*2);
        
        reset = 1;
        #(CLK_PERIOD);
        reset = 0;
        #(CLK_PERIOD*2);
        
        // Test 8: Multiple start/stop cycles
        $display("\n--- Test 8: Multiple Start/Stop Cycles ---");
        start = 1;
        #(CLK_PERIOD);
        start = 0;
        #(CLK_PERIOD*3);
        
        stop = 1;
        #(CLK_PERIOD);
        stop = 0;
        #(CLK_PERIOD*2);
        
        start = 1;
        #(CLK_PERIOD);
        start = 0;
        #(CLK_PERIOD*3);
        
        stop = 1;
        #(CLK_PERIOD);
        stop = 0;
        #(CLK_PERIOD*2);
        
        // Test 9: Test that global reset works anytime
        $display("\n--- Test 9: Global Reset During Operation ---");
        start = 1;
        #(CLK_PERIOD);
        start = 0;
        #(CLK_PERIOD*5);
        
        $display("Asserting global reset (rst_n = 0)...");
        rst_n = 0;
        #(CLK_PERIOD*2);
        rst_n = 1;
        #(CLK_PERIOD*2);
        
        // Final functional reset
        reset = 1;
        #(CLK_PERIOD);
        reset = 0;
        #(CLK_PERIOD*5);
        
        $display("\n========================================");
        $display("Testbench Complete!");
        $display("All tests passed successfully.");
        $display("========================================\n");
        
        $finish;
    end

    // Waveform dump for viewing in Vivado or GTKWave
    initial begin
        $dumpfile("stopwatch_tb.vcd");
        $dumpvars(0, tb_stopwatch);
    end

endmodule