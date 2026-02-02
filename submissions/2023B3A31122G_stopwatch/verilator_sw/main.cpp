#include <iostream>
#include <iomanip>
#include "Vstopwatch_top.h"
#include "verilated.h"

// Current simulation time (required by Verilator)
vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    // 1. Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // 2. Instantiate the Hardware Model
    Vstopwatch_top* top = new Vstopwatch_top;

    // 3. Helper Lambda to "Tick" the Clock
    // Toggles clock 0 -> 1 -> 0 and advances time
    auto tick = [&](int count = 1) {
        for (int i = 0; i < count; i++) {
            // Rising edge
            top->clk = 1;
            top->eval();
            
            // Falling edge
            top->clk = 0;
            top->eval();
            
            main_time++;
        }
    };

    // 4. Helper to print status
   // Updated Helper to print status (removed the debug signal error)
    auto print_time = [&]() {
        std::cout << "[" 
                  << std::setw(2) << std::setfill('0') << (int)top->minutes << ":"
                  << std::setw(2) << std::setfill('0') << (int)top->seconds << "] "
                  << "Status: " << (int)top->status 
                  << std::endl;
    };
    std::cout << "=== STARTING HARDWARE SIMULATION ===" << std::endl;

    // --- PHASE 1: INITIAL RESET ---
    std::cout << "\n[Action] Applying Hardware Reset..." << std::endl;
    top->rst_n = 0;  // Hold reset
    top->start = 0;
    top->stop = 0;
    top->reset = 0;
    tick(5);         // Wait 5 cycles
    top->rst_n = 1;  // Release reset
    tick(1);
    print_time();    // Should be 00:00

    // --- PHASE 2: START COUNTING ---
    std::cout << "\n[Action] Pressing START..." << std::endl;
    top->start = 1;  // Press button
    tick(1);         // For 1 clock cycle
    top->start = 0;  // Release button
    
    // Run for 65 seconds to prove minute rollover works
    std::cout << "[Info] Running for 65 seconds..." << std::endl;
    for (int i = 0; i < 7201; i++) {
        tick(1);     // Advance 1 second
        if (i < 65 || (i > 7195 && i <= 7200)) {
            print_time();
        } else if (i == 7195) {
            std::cout << "... Fast-forwarding to the end ..." << std::endl;
        }
    }

    // --- PHASE 3: PAUSE ---
    std::cout << "\n[Action] Pressing STOP (Pause)..." << std::endl;
    top->stop = 1;
    tick(1);
    top->stop = 0;

    // Run for 5 cycles to prove it stays paused
    std::cout << "[Info] Waiting 5 seconds (Should stay paused)..." << std::endl;
    for (int i = 0; i < 5; i++) {
        tick(1);
        print_time();
    }

    // --- PHASE 4: RESUME ---
    std::cout << "\n[Action] Pressing START (Resume)..." << std::endl;
    top->start = 1;
    tick(1);
    top->start = 0;
    
    std::cout << "[Info] Running for 5 more seconds..." << std::endl;
    for (int i = 0; i < 5; i++) {
        tick(1);
        print_time();
    }

    // --- PHASE 5: USER RESET ---
    std::cout << "\n[Action] Pressing USER RESET..." << std::endl;
    top->reset = 1;
    tick(1);
    top->reset = 0;
    
    std::cout << "[Info] Checking reset state..." << std::endl;
    tick(2);
    print_time(); // Should be 00:00

    std::cout << "\n=== SIMULATION COMPLETE ===" << std::endl;

    // Cleanup
    top->final();
    delete top;
    return 0;
}