#include "Vstopwatch_top.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>
double sc_time_stamp(){
    return 0;
}
vluint64_t main_time = 0;

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top *top = new Vstopwatch_top;

    auto tick = [&]() {
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();
        main_time++;
    };

    top->rst_n = 0;
    tick(); tick();
    top->rst_n = 1;

    top->start = 1;
    tick();
    top->start = 0;

    for (int i = 0; i < 75; i++) {
        tick();
        std::cout << std::setw(2) << std::setfill('0') << (int)top->minutes
                  << ":"
                  << std::setw(2) << std::setfill('0') << (int)top->seconds
                  << std::endl;
    }

    top->stop = 1;
    tick();
    top->stop = 0;

    tick(); tick();

    top->start = 1;
    tick();
    top->start = 0;

    for (int i = 0; i < 10; i++)
        tick();

    delete top;
    return 0;
}