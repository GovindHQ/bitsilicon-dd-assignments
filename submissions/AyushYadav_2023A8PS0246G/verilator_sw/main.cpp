#include "verilated.h"
#include "Vstopwatch_top.h"
#include <iostream>

vluint64_t sim_time = 0;

// Clock generator and printer
void tick(Vstopwatch_top* top) {
    top->clk = 0;
    top->eval();
    sim_time++;

    top->clk = 1;
    top->eval();
    sim_time++;

    // Print every cycle
    std::cout << "t=" << sim_time << "  minutes=" << (int)top->minutes << "  seconds=" << (int)top->seconds << "  status="  << (int)top->status << std::endl;
}

// Pulse generator
void pulse(Vstopwatch_top* top, bool& sig) {
    sig = 1;
    tick(top);
    sig = 0;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vstopwatch_top* top = new Vstopwatch_top;

    // Initialize
    top->clk   = 0;
    top->rst_n = 1;   // active-low reset
    top->reset = 0;   // active-high reset
    top->start = 0;
    top->stop  = 0;

    // 1. Apply reset
    // ----------------------------------------------------
    top->rst_n = 0;   // assert reset
    for (int i = 0; i < 5; i++) tick(top);

    top->rst_n = 1;   // release reset
    tick(top);

    // 2. Give a start pulse
    // ----------------------------------------------------
    top->start = 1;
    tick(top);
    top->start = 0;

    // 3. Wait 60 cycles
    // ----------------------------------------------------
    for (int i = 0; i < 60; i++) tick(top);

    // 4. Give a stop pulse
    // ----------------------------------------------------
    top->stop = 1;
    tick(top);
    top->stop = 0;

    // 5. Wait 30 cycles
    // ----------------------------------------------------
    for (int i = 0; i < 30; i++) tick(top);

    // 6. Start again
    // ----------------------------------------------------
    top->start = 1;
    tick(top);
    top->start = 0;

    // 7. Wait 15 cycles
    // ----------------------------------------------------
    for (int i = 0; i < 15; i++) tick(top);

    // 8. Reset (active-high user reset)
    // ----------------------------------------------------
    top->reset = 1;
    tick(top);
    top->reset = 0;

    // 9. Start again
    // ----------------------------------------------------
    top->start = 1;
    tick(top);
    top->start = 0;

    // 10. Let it run for 65 cycles
    // ----------------------------------------------------
    for (int i = 0; i < 65; i++) tick(top);

    delete top;
    return 0;
}