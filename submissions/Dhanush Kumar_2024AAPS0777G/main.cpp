#include "Vstopwatch_top.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>

using namespace std;

void tick(Vstopwatch_top* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vstopwatch_top* dut = new Vstopwatch_top;

    dut->clk   = 0;
    dut->rst_n = 0;
    dut->start = 0;
    dut->stop  = 0;
    dut->reset = 0;

    for (int i = 0; i < 5; i++)
        tick(dut);

    dut->rst_n = 1;

    dut->start = 1;
    tick(dut);
    dut->start = 0;

    cout << "Stopwatch running:" << endl;
    for (int i = 0; i < 5; i++) {
        tick(dut);
        cout << setw(2) << setfill('0') << (int)dut->minutes
             << ":" << setw(2) << setfill('0') << (int)dut->seconds
             << endl;
    }

    dut->stop = 1;
    tick(dut);
    dut->stop = 0;

    cout << "Paused at: "
         << setw(2) << setfill('0') << (int)dut->minutes
         << ":" << setw(2) << setfill('0') << (int)dut->seconds
         << endl;

    dut->start = 1;
    tick(dut);
    dut->start = 0;

    cout << "Resumed:" << endl;
    for (int i = 0; i < 5; i++) {
        tick(dut);
        cout << setw(2) << setfill('0') << (int)dut->minutes
             << ":" << setw(2) << setfill('0') << (int)dut->seconds
             << endl;
    }

    dut->reset = 1;
    tick(dut);
    dut->reset = 0;

    cout << "After reset: "
         << setw(2) << setfill('0') << (int)dut->minutes
         << ":" << setw(2) << setfill('0') << (int)dut->seconds
         << endl;

    delete dut;
    return 0;
}
