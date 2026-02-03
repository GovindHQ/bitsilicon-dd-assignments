// main.cpp
// C++ control program for Digital Stopwatch using Verilator
// Demonstrates hardware-software co-design
//
// Clock Configuration:
//   - Hardware counts on every clock cycle (not tied to real time)
//   - In real FPGA: Use clock divider to count actual seconds
//   - In simulation: Each clock cycle = 1 "second" in stopwatch
//   - This allows fast simulation for testing
//
// Note: In production, you would:
//   1. Add a prescaler/divider to generate 1Hz enable from system clock
//   2. Or use the clock frequency to calculate real time
//   3. This code demonstrates the control interface independent of timing

#include <iostream>
#include <iomanip>
#include "Vstopwatch_top.h"
#include "verilated.h"

// Helper function to display stopwatch time
void display_stopwatch(Vstopwatch_top* stopwatch, vluint64_t sim_time, int clock_cycles) {
    std::string status_str;
    switch (stopwatch->status) {
        case 0: status_str = "IDLE   "; break;
        case 1: status_str = "RUNNING"; break;
        case 2: status_str = "PAUSED "; break;
        default: status_str = "UNKNOWN"; break;
    }
    
    std::cout << "[Sim:" << std::setw(6) << sim_time << "ns"
              << " | Clocks:" << std::setw(4) << clock_cycles << "] "
              << "Status: " << status_str << " | "
              << "Time: " << std::setw(2) << std::setfill('0') 
              << (int)stopwatch->minutes << ":"
              << std::setw(2) << std::setfill('0') 
              << (int)stopwatch->seconds
              << std::setfill(' ') << std::endl;
}

// Helper function to pulse a signal for one clock cycle
void pulse_signal(Vstopwatch_top* stopwatch, int signal_type, vluint64_t& main_time, int& clock_count) {
    // signal_type: 0=start, 1=stop, 2=reset
    
    // Set signal high
    if (signal_type == 0) stopwatch->start = 1;
    else if (signal_type == 1) stopwatch->stop = 1;
    else if (signal_type == 2) stopwatch->reset = 1;
    
    // Clock tick
    stopwatch->clk = 0;
    stopwatch->eval();
    main_time++;
    
    stopwatch->clk = 1;
    stopwatch->eval();
    main_time++;
    clock_count++;
    
    // Set signal low
    if (signal_type == 0) stopwatch->start = 0;
    else if (signal_type == 1) stopwatch->stop = 0;
    else if (signal_type == 2) stopwatch->reset = 0;
}

// Helper function to run clock cycles
void run_cycles(Vstopwatch_top* stopwatch, int num_cycles, vluint64_t& main_time, int& clock_count, bool verbose = false) {
    for (int i = 0; i < num_cycles; i++) {
        // Falling edge
        stopwatch->clk = 0;
        stopwatch->eval();
        main_time++;
        
        // Rising edge
        stopwatch->clk = 1;
        stopwatch->eval();
        main_time++;
        clock_count++;
        
        if (verbose && (i % 10 == 0 || i == num_cycles - 1)) {
            display_stopwatch(stopwatch, main_time, clock_count);
        }
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // Instantiate the stopwatch model
    Vstopwatch_top* stopwatch = new Vstopwatch_top;
    
    // Simulation time counter and clock cycle counter
    vluint64_t main_time = 0;
    int clock_cycles = 0;
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "Digital Stopwatch - Verilator Simulation" << std::endl;
    std::cout << "Clock: Each cycle = 1 'second' in stopwatch" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    // Initialize inputs
    stopwatch->clk = 0;
    stopwatch->rst_n = 1;       // rst_n is active-low, so 1 = not reset
    stopwatch->start = 0;
    stopwatch->stop = 0;
    stopwatch->reset = 0;
    stopwatch->eval();
    
    // Test 1: Global hardware reset
    std::cout << "--- Test 1: Global Hardware Reset (rst_n) ---" << std::endl;
    stopwatch->rst_n = 0;       // Assert global reset
    run_cycles(stopwatch, 2, main_time, clock_cycles);
    stopwatch->rst_n = 1;       // Deassert global reset
    run_cycles(stopwatch, 2, main_time, clock_cycles);
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    // Test 2: Start the stopwatch
    std::cout << "\n--- Test 2: Start Stopwatch ---" << std::endl;
    pulse_signal(stopwatch, 0, main_time, clock_cycles);  // Start
    std::cout << "Counting for 15 seconds..." << std::endl;
    run_cycles(stopwatch, 15, main_time, clock_cycles, true);
    
    // Test 3: Pause the stopwatch
    std::cout << "\n--- Test 3: Pause Stopwatch ---" << std::endl;
    pulse_signal(stopwatch, 1, main_time, clock_cycles);  // Stop
    display_stopwatch(stopwatch, main_time, clock_cycles);
    std::cout << "Paused for 5 cycles (time should NOT advance)..." << std::endl;
    run_cycles(stopwatch, 5, main_time, clock_cycles);
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    // Test 4: Resume the stopwatch
    std::cout << "\n--- Test 4: Resume Stopwatch ---" << std::endl;
    pulse_signal(stopwatch, 0, main_time, clock_cycles);  // Start
    std::cout << "Counting for 10 more seconds..." << std::endl;
    run_cycles(stopwatch, 10, main_time, clock_cycles, true);
    
    // Test 5: Functional reset to 00:00
    std::cout << "\n--- Test 5: Functional Reset (reset to 00:00) ---" << std::endl;
    pulse_signal(stopwatch, 2, main_time, clock_cycles);  // Reset
    display_stopwatch(stopwatch, main_time, clock_cycles);
    run_cycles(stopwatch, 2, main_time, clock_cycles);
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    // Test 6: Count to demonstrate seconds rollover
    std::cout << "\n--- Test 6: Demonstrate Rollover (59->00, min++) ---" << std::endl;
    std::cout << "Starting and fast-forwarding to 58 seconds..." << std::endl;
    pulse_signal(stopwatch, 0, main_time, clock_cycles);  // Start
    run_cycles(stopwatch, 58, main_time, clock_cycles);
    
    std::cout << "Approaching rollover..." << std::endl;
    for (int i = 0; i < 5; i++) {
        run_cycles(stopwatch, 1, main_time, clock_cycles);
        display_stopwatch(stopwatch, main_time, clock_cycles);
    }
    
    // Test 7: Multiple start/stop cycles
    std::cout << "\n--- Test 7: Multiple Start/Stop Cycles ---" << std::endl;
    
    pulse_signal(stopwatch, 2, main_time, clock_cycles);  // Reset
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    pulse_signal(stopwatch, 0, main_time, clock_cycles);  // Start
    run_cycles(stopwatch, 5, main_time, clock_cycles);
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    pulse_signal(stopwatch, 1, main_time, clock_cycles);  // Stop
    display_stopwatch(stopwatch, main_time, clock_cycles);
    run_cycles(stopwatch, 3, main_time, clock_cycles);
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    pulse_signal(stopwatch, 0, main_time, clock_cycles);  // Start
    run_cycles(stopwatch, 5, main_time, clock_cycles);
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    // Test 8: Global reset during operation
    std::cout << "\n--- Test 8: Global Reset During Operation ---" << std::endl;
    std::cout << "Starting stopwatch..." << std::endl;
    pulse_signal(stopwatch, 2, main_time, clock_cycles);  // Reset first
    pulse_signal(stopwatch, 0, main_time, clock_cycles);  // Start
    run_cycles(stopwatch, 10, main_time, clock_cycles);
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    std::cout << "Asserting global reset (rst_n = 0)..." << std::endl;
    stopwatch->rst_n = 0;
    run_cycles(stopwatch, 2, main_time, clock_cycles);
    stopwatch->rst_n = 1;
    run_cycles(stopwatch, 2, main_time, clock_cycles);
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    // Final cleanup
    std::cout << "\n--- Final Reset ---" << std::endl;
    pulse_signal(stopwatch, 2, main_time, clock_cycles);  // Reset
    display_stopwatch(stopwatch, main_time, clock_cycles);
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "Simulation Complete!" << std::endl;
    std::cout << "Total simulation time: " << main_time << "ns" << std::endl;
    std::cout << "Total clock cycles: " << clock_cycles << std::endl;
    std::cout << "Note: In hardware, add clock divider for real-time seconds" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    // Cleanup
    stopwatch->final();
    delete stopwatch;
    
    return 0;
}