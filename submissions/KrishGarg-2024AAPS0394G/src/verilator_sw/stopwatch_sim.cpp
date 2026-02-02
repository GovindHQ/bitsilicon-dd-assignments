#include "Vstopwatch_top.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>
#include <bitset>
#include <functional>

vluint64_t main_time = 0;
double sc_time_stamp() {
    return main_time;
}

// Run through N clock cycles
template <typename TickFn>
void run_cycles(int n, TickFn tick) {
    while (n--) tick();
}

// Display function
template <typename TickFn>
void showTime(int n, TickFn tick, Vstopwatch_top* top) {
    for (int i = 0; i < n; i++) {
        tick();
        switch(top->status) {
            case 0b00: std::cout << "STOPWATCH IDLE     |"; break;
            case 0b01: std::cout << "STOPWATCH RUNNING  |"; break;
            case 0b10: std::cout << "STOPWATCH PAUSED   |"; break;
            default:   std::cout << "STOPWATCH IDLE     |"; break;
        }
        std::cout << "T=" << std::setw(4) << main_time
                  << " | TIME="
                  << std::setw(2) << std::setfill('0') << (int)top->minutes
                  << ":"
                  << std::setw(2) << std::setfill('0') << (int)top->seconds
                  << std::setfill(' ')
                  << std::endl;
    }
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    auto* top = new Vstopwatch_top;

    // One full clock cycle
    auto tick = [&]() {
        top->clk = 0; top->eval();
        top->clk = 1; top->eval();
        main_time++;
    };

    // Make everything 0
    top->clk   = 0;
    top->rst_n = 0;
    top->start = 0;
    top->stop  = 0;
    top->reset = 0;

    // Active low reset
    showTime(2, tick, top);
    top->rst_n = 1;

    // Start stopwatch
    top->start = 1;
    showTime(2, tick,top);
    top->start = 0;

    run_cycles(18, tick);

    // Pause stopwatch
    top->stop = 1;
    showTime(2, tick, top);
    top->stop = 0;

    run_cycles(7, tick);
    showTime(1, tick, top);

    // Resume stopwatch
    top->start = 1;
    showTime(2, tick, top);
    top->start = 0;
    showTime(5, tick, top);
    run_cycles(30, tick);
    showTime(7, tick, top);
    top->reset = 1;
    showTime(2, tick, top);
    top->reset = 0;
    top->start = 1;
    showTime(2, tick, top);
    top->start = 0;
    showTime(2, tick, top);

    //Terminate simulation
    top->final();
    delete top;
    return 0;
}
