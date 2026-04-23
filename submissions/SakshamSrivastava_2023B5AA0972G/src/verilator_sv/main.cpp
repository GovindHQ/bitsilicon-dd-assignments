#include <verilated.h>
#include "Vstopwatch_top.h"
#include <iostream>
#include <iomanip>


vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

// Advance one full clock cycle
void tick(Vstopwatch_top* dut) {
    dut->clk = 0;
    dut->eval();
    main_time++;

    dut->clk = 1;
    dut->eval();
    main_time++;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vstopwatch_top* dut = new Vstopwatch_top;

    // Initialize inputs
    dut->clk   = 0;
    dut->rst_n = 0;
    dut->start = 0;
    dut->stop  = 0;
    dut->reset = 0;

    // Reset
    for (int i = 0; i < 5; i++) {
        tick(dut);
    }

    dut->rst_n = 1;
    tick(dut);

    // Start stopwatch
    dut->start = 1;
    tick(dut);     // sampled on clock edge
    dut->start = 0;

    std::cout << "Stopwatch started\n";

    for (int i = 0; i < 20; i++) {
        tick(dut);

        std::cout << "Time: "
                  << std::setw(2) << std::setfill('0') << (int)dut->minutes
                  << ":"
                  << std::setw(2) << std::setfill('0') << (int)dut->seconds
                  << "  State=" << (int)dut->status
                  << std::endl;
    }

    // Stop stopwatch
    dut->stop = 1;
    tick(dut);
    dut->stop = 0;

    std::cout << "Stopwatch paused\n";

    delete dut;
    return 0;
}
