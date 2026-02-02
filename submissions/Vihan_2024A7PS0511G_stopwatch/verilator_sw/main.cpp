//The comments have been made after understanding the whole code although it is written with the help of artificial intelligence
// and the comments are solely made by the user and not artificial intelligence

#include <iostream>
#include <iomanip>
#include "Vstopwatch_top.h"
#include "verilated.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top* top = new Vstopwatch_top;

    auto tick = [&]() {
        top->clk = 1; top->eval();
        top->clk = 0; top->eval();
    };

    // 1. Reset the system
    top->rst_n = 0; tick();
    top->rst_n = 1;
    std::cout << "System Reset." << std::endl;

    // 2. Start the stopwatch
    top->start = 1; tick();
    top->start = 0;
    std::cout << "Stopwatch Started..." << std::endl;

    // 3. Run for 125 cycles (simulating time passing)
    for (int i = 0; i < 125; i++) {
        tick();
        if (i % 20 == 0) {
            std::cout << "Time: " << std::setw(2) << std::setfill('0') << (int)top->minutes 
                      << ":" << std::setw(2) << std::setfill('0') << (int)top->seconds << std::endl;
        }
    }

    // 4. Pause
    top->stop = 1; tick();
    top->stop = 0;
    std::cout << "Stopwatch Paused." << std::endl;

    delete top;
    return 0;
}