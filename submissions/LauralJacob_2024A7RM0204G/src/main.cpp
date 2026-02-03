#include "Vstopwatch_top.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>

vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

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

    dut->rst_n = 0;
    tick(dut);
    dut->rst_n = 1;

    dut->start = 1;
    tick(dut);
    dut->start = 0;

    for (int i = 0; i < 60; i++) {
        tick(dut);
        std::cout << std::setw(2) << std::setfill('0')
                  << (int)dut->minutes << ":"
                  << std::setw(2)
                  << (int)dut->seconds << std::endl;
    }

    delete dut;
    return 0;
}
