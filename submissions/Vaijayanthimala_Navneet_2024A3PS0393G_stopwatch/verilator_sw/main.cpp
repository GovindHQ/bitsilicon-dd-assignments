#include <iostream>
#include <iomanip>
#include "Vstopwatch_top.h"
#include "verilated.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top* top = new Vstopwatch_top;

    // Helper to pulse the clock
    auto tick = [&]() {
        top->clk = 1; top->eval();
        top->clk = 0; top->eval();
    };

    // System Startup
    top->rst_n = 0; tick();
    top->rst_n = 1; tick();
    
    // Press Start
    top->start = 1; tick();
    top->start = 0;

    std::cout << "Starting Simulation..." << std::endl;

    for (int i = 0; i < 500; i++) {
        tick();
        if (i % 20 == 0) {
            std::cout << "Current Time: " 
                      << std::setw(2) << std::setfill('0') << (int)top->minutes << ":"
                      << std::setw(2) << std::setfill('0') << (int)top->seconds 
                      << " [Status: " << (int)top->status << "]" << std::endl;
        }
    }

    delete top;
    return 0;
}