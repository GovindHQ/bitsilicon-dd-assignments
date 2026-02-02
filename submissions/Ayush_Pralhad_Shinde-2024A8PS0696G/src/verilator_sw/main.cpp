#include "Vstopwatch_top.h"
#include "verilated.h"
#include <iostream>

vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top* top = new Vstopwatch_top;

    top->clk = 0;
    top->rst_n = 0;
    top->start = 0;
    top->stop = 0;
    top->reset = 0;

    printf("--- Simulation Start ---\n");

    for (int i = 0; i < 10; i++) {
        top->clk = !top->clk;
        top->eval();
    }
    top->rst_n = 1;
    printf("Reset Released.\n");

    top->start = 1;
    top->clk = !top->clk; top->eval();
    top->clk = !top->clk; top->eval();
    top->start = 0;
    printf("Button Pressed: START\n");

    for (int i = 0; i < 4000; i++) {
        top->clk = !top->clk;
        top->eval();
        
        if (top->clk == 1 && i % 2000 == 0) {
            printf("Time: %d:%02d\n", top->minutes, top->seconds);
        }
    }

    top->stop = 1;
    top->clk = !top->clk; top->eval();
    top->clk = !top->clk; top->eval();
    top->stop = 0;
    printf("Button Pressed: STOP (Pause)\n");

    for (int i = 0; i < 1000; i++) {
        top->clk = !top->clk;
        top->eval();
    }
    printf("Paused Time Check: %d:%02d\n", top->minutes, top->seconds);

    top->start = 1;
    top->clk = !top->clk; top->eval();
    top->clk = !top->clk; top->eval();
    top->start = 0;
    printf("Button Pressed: START (Resume)\n");

    for (int i = 0; i < 4314 ; i++) {
        top->clk = !top->clk;
        top->eval();
    }
    printf("Final Time: %d:%02d\n", top->minutes, top->seconds);

    top->final();
    delete top;
    return 0;
}