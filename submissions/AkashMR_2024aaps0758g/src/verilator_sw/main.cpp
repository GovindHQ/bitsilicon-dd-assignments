#include <iostream>
#include <verilated.h>
#include "Vstopwatch_top.h" // Verilator generated header

// Current simulation time
vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top* top = new Vstopwatch_top;

    // Initialize inputs
    top->clk = 0;
    top->rst_n = 0; // Assert reset initially
    top->start = 0;
    top->stop = 0;
    top->reset = 0;

    std::cout << "Starting Simulation..." << std::endl;

    // Simulation loop
    for (int i = 0; i < 2000; i++) {
        // Toggle Clock
        top->clk = !top->clk;
        
        // Release Reset after a few cycles
        if (i == 10) top->rst_n = 1;

        // Test Scenario 1: Start Stopwatch at cycle 20
        if (i == 20) {
            std::cout << "[CMD] Start" << std::endl;
            top->start = 1; 
        }
        if (i == 22) top->start = 0; // Pulse start

        // Test Scenario 2: Pause at cycle 1000 (roughly 5 seconds in logic time)
        if (i == 1000) {
            std::cout << "[CMD] Stop (Pause)" << std::endl;
            top->stop = 1;
        }
        if (i == 1002) top->stop = 0;

        // Test Scenario 3: Resume at cycle 1200
        if (i == 1200) {
             std::cout << "[CMD] Resume" << std::endl;
             top->start = 1;
        }
        if (i == 1202) top->start = 0;

        // Evaluate model
        top->eval();

        // Print status every time seconds change (on rising edge)
        if (top->clk == 1 && i > 15) {
             // Print every 100 cycles to avoid clutter, or check for change
             if (i % 100 == 0) {
                printf("Time: %02d:%02d | Status: %d\n", top->minutes, top->seconds, top->status);
             }
        }
        main_time++;
    }

    std::cout << "Simulation Finished." << std::endl;
    delete top;
    return 0;
}