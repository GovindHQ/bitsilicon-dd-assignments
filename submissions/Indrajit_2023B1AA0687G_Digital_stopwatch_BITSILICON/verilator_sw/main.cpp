#include <verilated.h>
#include "Vstopwatch_top.h"
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>


int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    Vstopwatch_top *dut = new Vstopwatch_top;

    dut->clk   = 0;
    dut->rst_n = 0;
    dut->start = 0;
    dut->stop  = 0;
    dut->reset = 0;

    // Helper lambda: one clock cycle
    auto tick = [&]() {
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
    };

    for (int i = 0; i < 5; i++)
        tick();

    dut->rst_n = 1;  

    dut->start = 1;
    tick();
    dut->start = 0;

    for (int t = 0; t < 99; t++) {
        tick();

        int min = dut->minutes;
        int sec = dut->seconds;

        std::cout << "Time: "
                  << std::setw(2) << std::setfill('0') << min
                  << ":"
                  << std::setw(2) << std::setfill('0') << sec
                  << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Pause at t = 40
        if (t == 40) dut->stop = 1;
        if (t == 41) {
            dut->stop = 0;
            std::cout << "Paused\n";
        }

        // Resume at t = 60
        if (t == 60) dut->start = 1;
        if (t == 61) {
            dut->start = 0;
            std::cout << "Resumed\n";
        }
    }

    tick();
    dut->reset = 0;

    std::cout << "Reset applied\n";

    delete dut;
    return 0;
}
