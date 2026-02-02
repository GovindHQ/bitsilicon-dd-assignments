#include "Vstopwatch_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"  // For VCD tracing
#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // Instantiate the Verilog module
    Vstopwatch_top* top = new Vstopwatch_top;

    // Enable VCD tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("stopwatch_waveform.vcd");

    // Initialize signals
    top->rst_n = 0;
    top->start = 0;
    top->stop = 0;
    top->reset = 0;
    top->clk = 0;

    // Reset
    top->eval();
    tfp->dump(0);
    top->rst_n = 1;
    top->eval();
    tfp->dump(1);

    // Simulation loop
    for (int i = 0; i < 120; ++i) {  // 120 seconds simulation
        // Toggle clock
        top->clk = !top->clk;
        top->eval();
        tfp->dump(i*2 + 2);

        if (top->clk) {  // On rising edge
            std::cout << "Cycle " << i/2 << ": Status=" << (int)top->status
                      << ", Time=" << std::setfill('0') << std::setw(2) << (int)top->minutes
                      << ":" << std::setfill('0') << std::setw(2) << (int)top->seconds << std::endl;

            // Control inputs at certain times
            if (i/2 == 5) top->start = 1;  // Start at 5 seconds
            else top->start = 0;

            if (i/2 == 15) top->stop = 1;  // Stop at 15 seconds
            else top->stop = 0;

            if (i/2 == 20) top->start = 1;  // Start again at 20 seconds
            else if (i/2 != 5) top->start = 0;

            if (i/2 == 80) top->reset = 1;  // Reset at 80 seconds
            else top->reset = 0;
        }

        // Delay for timing
        // In real simulation, use proper timing
    }

    // Close VCD file
    tfp->close();

    // Cleanup
    delete tfp;
    delete top;
    return 0;
}