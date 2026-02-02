#include "Vstopwatch_top.h"
#include "verilated.h"
#include <stdio.h>

vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

void tick(Vstopwatch_top *top) {

    top->clk = 0;
    top->eval();
    main_time++;

    top->clk = 1;
    top->eval();
    main_time++;
}

int main(int argc, char **argv) {

    Verilated::commandArgs(argc, argv);

    Vstopwatch_top *top = new Vstopwatch_top;

    top->rst_n = 0;
    tick(top);     
    top->rst_n = 1;

    top->start = 1;
    tick(top);
    top->start = 0;

    for (int i = 0; i < 120; i++) {
        tick(top);
    }

    top->stop = 1;
    tick(top);
    top->stop = 0;

    printf("Paused at %02d:%02d\n", top->minutes, top->seconds);

    top->start = 1;
    tick(top);
    top->start = 0;

    for (int i = 0; i < 60; i++) {
        tick(top);
    }

    printf("Final Time %02d:%02d\n", top->minutes, top->seconds);

    delete top;
    return 0;
}
