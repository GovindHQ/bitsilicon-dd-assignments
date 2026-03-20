// main.cpp
// Verilator-based control program for digital stopwatch
#include <iostream>
#include <iomanip>
#include <verilated.h>
#include "Vstopwatch_top.h"
#include <cstdlib>  // for atoi


unsigned int tick_delay_us = 1000000;  //  Default tick delay in microseconds

void print_status(Vstopwatch_top* dut) {
    const char* status_str;
    switch (dut->status) {
        case 0: status_str = "IDLE   "; break;
        case 1: status_str = "RUNNING"; break;
        case 2: status_str = "PAUSED "; break;
        default: status_str = "UNKNOWN"; break;
    }
    
    std::cout << "Status: " << status_str 
              << " | Time: " 
              << std::setfill('0') << std::setw(2) << (int)dut->minutes 
              << ":" 
              << std::setfill('0') << std::setw(2) << (int)dut->seconds 
              << std::endl;
}

// Function to cycle the clock
void tick(Vstopwatch_top* dut, vluint64_t& tickcount) {
    // Rising edge
    dut->clk = 1;
    dut->eval();
    tickcount++;
    
    // Falling edge
    dut->clk = 0;
    dut->eval();
    if (tick_delay_us > 0) {
        usleep(tick_delay_us);
    }
print_status(dut);

}

// Function to wait for N clock cycles
void wait_cycles(Vstopwatch_top* dut, vluint64_t& tickcount, int cycles) {
    for (int i = 0; i < cycles; i++) {
        tick(dut, tickcount);

    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // Instantiate the design
    Vstopwatch_top* dut = new Vstopwatch_top;
    
    vluint64_t tickcount = 0;
    
    std::cout << " Digital Stopwatch Controller " << std::endl;
    std::cout << " Verilator Co-Simulation Demo " << std::endl << std::endl;
    
    // Initialize inputs
    dut->rst_n = 0;
    dut->start = 0;
    dut->stop = 0;
    dut->reset = 0;
    dut->clk = 0;
    dut->eval();
    
    // Apply reset
    std::cout << "Applying reset..." << std::endl;
    wait_cycles(dut, tickcount, 2);
    dut->rst_n = 1;
    wait_cycles(dut, tickcount, 2);
    std::cout << std::endl;
    
    // Test 1: Start the stopwatch
    std::cout << "--- Test 1: Starting stopwatch ---" << std::endl;
    dut->start = 1;
    tick(dut, tickcount);
    dut->start = 0;
    tick(dut, tickcount);
    
    // Count for 10 seconds
    std::cout << "Counting for 10 seconds..." << std::endl;
    for (int i = 0; i < 10; i++) {
        wait_cycles(dut, tickcount, 1);
        if ((i + 1) % 5 == 0) {
            std::cout << "  ";
        }
    }
    std::cout << std::endl;
    
    // Test 2: Pause the stopwatch
    std::cout << "--- Test 2: Pausing stopwatch ---" << std::endl;
    dut->stop = 1;
    tick(dut, tickcount);
    dut->stop = 0;
    tick(dut, tickcount);
    
    std::cout << "Waiting 5 cycles while paused (time should not change)..." << std::endl;
    wait_cycles(dut, tickcount, 5);
    std::cout << "  ";
    std::cout << std::endl;
    
    // Test 3: Resume the stopwatch
    std::cout << "--- Test 3: Resuming stopwatch ---" << std::endl;
    dut->start = 1;
    tick(dut, tickcount);
    dut->start = 0;
    tick(dut, tickcount);
    
    std::cout << "Counting for 15 more seconds..." << std::endl;
    for (int i = 0; i < 15; i++) {
        wait_cycles(dut, tickcount, 1);
        if ((i + 1) % 5 == 0) {
            std::cout << "  ";
        }
    }
    std::cout << std::endl;
    
    // Test 4: Reset the stopwatch
    
    
    // Test 5: Demonstrate minute rollover
    std::cout << "--- Test 4: Testing minute rollover ---" << std::endl;
    
    
    // Fast forward to 59 seconds
    wait_cycles(dut, tickcount, 58-28);
    std::cout << "  ";
    
    std::cout << "Counting past 59 seconds to see rollover..." << std::endl;
    for (int i = 0; i < 5; i++) {
        wait_cycles(dut, tickcount, 1);
        std::cout << "  ";
    }
    std::cout << std::endl;
    
    // Final reset
    std::cout << "--- Final Reset ---" << std::endl;
    dut->reset = 1;
    tick(dut, tickcount);
    dut->reset = 0;
    tick(dut, tickcount);
    
    std::cout << std::endl << " Simulation Complete " << std::endl;
    std::cout << "Total clock cycles: " << tickcount << std::endl;
    
    // Cleanup
    dut->final();
    delete dut;
    
    return 0;
}
