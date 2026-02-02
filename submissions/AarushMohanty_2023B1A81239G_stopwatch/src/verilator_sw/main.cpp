#include <verilated.h>
#include "Vstopwatch_top.h"
#include <iostream>
#include <iomanip>

// Global simulation time
vluint64_t sim_time = 0;

// Clock tick helper
void tick(Vstopwatch_top* dut) {
    dut->clk = 0;
    dut->eval();
    sim_time++;

    dut->clk = 1;
    dut->eval();
    sim_time++;
}

// FSM state helper
const char* state_name(uint8_t s) {
    switch (s) {
        case 0: return "IDLE";
        case 1: return "RUNNING";
        case 2: return "PAUSED";
        default: return "UNKNOWN";
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // Instantiate DUT
    Vstopwatch_top* dut = new Vstopwatch_top;

    // Initial values
    dut->clk   = 0;
    dut->rst_n = 0;
    dut->start = 0;
    dut->stop  = 0;
    dut->reset = 0;

    // Global reset
    for (int i = 0; i < 5; i++)
        tick(dut);

    dut->rst_n = 1;

    std::cout << "Stopwatch simulation started\n";

    // START
    dut->start = 1;
    tick(dut);
    dut->start = 0;

    // Run ~65 seconds
    for (int i = 0; i < 65; i++) {
        tick(dut);
        std::cout << "TIME=" << std::setw(4) << i
                  << " | " << state_name(dut->status)
                  << " | "
                  << std::setw(2) << std::setfill('0') << (int)dut->minutes
                  << ":"
                  << std::setw(2) << std::setfill('0') << (int)dut->seconds
                  << std::setfill(' ')
                  << std::endl;
    }

    // PAUSE
    dut->stop = 1;
    tick(dut);
    dut->stop = 0;

    for (int i = 0; i < 10; i++) {
        tick(dut);
        std::cout << "PAUSED | "
                  << std::setw(2) << std::setfill('0') << (int)dut->minutes
                  << ":"
                  << std::setw(2) << std::setfill('0') << (int)dut->seconds
                  << std::setfill(' ')
                  << std::endl;
    }

    // RESUME
    dut->start = 1;
    tick(dut);
    dut->start = 0;

    for (int i = 0; i < 20; i++) {
        tick(dut);
        std::cout << "RESUME | "
                  << std::setw(2) << std::setfill('0') << (int)dut->minutes
                  << ":"
                  << std::setw(2) << std::setfill('0') << (int)dut->seconds
                  << std::setfill(' ')
                  << std::endl;
    }

    // RESET stopwatch
    dut->reset = 1;
    tick(dut);
    dut->reset = 0;

    tick(dut);

    std::cout << "RESET  | "
              << std::setw(2) << std::setfill('0') << (int)dut->minutes
              << ":"
              << std::setw(2) << std::setfill('0') << (int)dut->seconds
              << std::setfill(' ')
              << " | " << state_name(dut->status)
              << std::endl;

    // Cleanup
    dut->final();
    delete dut;

    std::cout << "Simulation complete\n";
    return 0;
}
