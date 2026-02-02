#include "Vstopwatch_top.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>

static vluint64_t sim_time = 0;

void tick(Vstopwatch_top *dut) {
    dut->clk = 0;
    dut->eval();
    sim_time++;

    dut->clk = 1;
    dut->eval();
    sim_time++;
}

void print_state(Vstopwatch_top *dut)
{
    std::cout
        << std::setw(2) << std::setfill('0') << (int)dut->minutes
        << ":"
        << std::setw(2) << std::setfill('0') << (int)dut->seconds
        << "  status=" << (int)dut->status
        << std::endl;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    Vstopwatch_top *dut = new Vstopwatch_top;

    // -----------------------
    // Initial values
    // -----------------------
    dut->clk   = 0;
    dut->rst_n = 0;
    dut->start = 0;
    dut->stop  = 0;
    dut->reset = 0;

    // power-up reset
    for (int i = 0; i < 5; i++)
        tick(dut);

    dut->rst_n = 1;
    tick(dut);

    std::cout << "After power-up:" << std::endl;
    print_state(dut);

    // -----------------------
    // start
    // -----------------------
    dut->start = 1;
    tick(dut);
    dut->start = 0;

    std::cout << "Running:" << std::endl;

    for (int i = 0; i < 130; i++) {
        tick(dut);
        print_state(dut);
    }

    // -----------------------
    // pause
    // -----------------------
    dut->stop = 1;
    tick(dut);
    dut->stop = 0;

    std::cout << "Paused:" << std::endl;
    print_state(dut);

    // stay paused for a few cycles
    for (int i = 0; i < 3; i++)
        tick(dut);

    // -----------------------
    // resume
    // -----------------------
    dut->start = 1;
    tick(dut);
    dut->start = 0;

    std::cout << "Resumed:" << std::endl;
    print_state(dut);

    for (int i = 0; i < 9; i++) {
        tick(dut);
        print_state(dut);
    }

    // -----------------------
    // reset (user reset)
    // -----------------------
    dut->reset = 1;
    tick(dut);
    dut->reset = 0;

    std::cout << "After reset:" << std::endl;
    print_state(dut);

    delete dut;
    return 0;
}
