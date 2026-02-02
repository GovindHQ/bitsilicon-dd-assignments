#include "Vstopwatch_top.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top* top = new Vstopwatch_top;

    auto tick = [&]() {
        top->clk = 0; top->eval();
        top->clk = 1; top->eval();
    };

    top->rst_n = 0;
    tick();
    top->rst_n = 1;

    top->start = 1; tick(); top->start = 0;

    for (int i = 0; i < 7000; i++) {
        tick();
        std::cout << std::setw(2) << std::setfill('0') << (int)top->minutes
                  << ":" << std::setw(2) << (int)top->seconds << std::endl;
    }

    top->stop = 1; tick(); top->stop = 0;
    tick();

    top->start = 1; tick(); top->start = 0;

    delete top;
    return 0;
}
