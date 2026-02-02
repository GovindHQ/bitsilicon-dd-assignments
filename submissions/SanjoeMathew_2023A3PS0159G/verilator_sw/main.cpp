#include "Vstopwatch_top.h"
#include "verilated.h"
vluint64_t main_time = 0;

// Required by Verilator
double sc_time_stamp() {
    return main_time;
}
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top top;

    top.clk   = 0;
    top.reset = 1;
    top.start = 0;
    top.stop  = 0;

    // Reset for 2 cycles
    for (int i = 0; i < 2; i++) {
        top.clk = 0; top.eval(); main_time++;
        top.clk = 1; top.eval(); main_time++;
    }

    top.reset = 0;

    // Start pulse
    top.start = 1;
    top.clk = 0; top.eval(); main_time++;
    top.clk = 1; top.eval(); main_time++;
    top.start = 0;

    // Run 10 seconds
    for (int i = 0; i < 10; i++) {
        top.clk = 0; top.eval(); main_time++;
        top.clk = 1; top.eval(); main_time++;
    }

    return 0;
}
