#include <iostream>
#include <iomanip>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vstopwatch_top.h" 

double sc_time_stamp() {
    return 0; 
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top* top = new Vstopwatch_top;

    // trace setup for waveform generation
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    //initialize hardware signals
    top->clk = 0;
    top->rst_n = 0;   
    top->start = 0;
    top->stop = 0;
    top->reset = 0;

    //main simulation loop
    for (int ticks = 0; ticks < 15000; ticks++) {
        // clock generation, period: 10 units
        if (ticks % 5 == 0) top->clk = !top->clk;

        // testbench stimulus
        if (ticks == 20)  top->rst_n = 1; // Release asynch reset
        if (ticks == 100) top->start = 1; // trigger start pulse
        if (ticks == 120) top->start = 0; 

        top->eval();
        tfp->dump(ticks);

        // Terminal Output logic
        static int last_sec = -1;
        if (top->seconds != last_sec) {
            std::cout << "Time: " << std::setw(2) << std::setfill('0') << (int)top->minutes 
                      << ":" << std::setw(2) << std::setfill('0') << (int)top->seconds 
                      << " [State: " << (int)top->status << "]" << std::endl;
            last_sec = top->seconds;
        }
    }

    std::cout << "Simulation Finished. Open waveform.vcd to see results." << std::endl;
    tfp->close();
    delete top;
    return 0;
}