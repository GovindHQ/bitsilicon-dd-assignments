#include "Vstopwatch_top.h"
#include "verilated.h"
#include <iostream>

static void tick(Vstopwatch_top* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top* dut = new Vstopwatch_top;

    int t = 0;

    // Initialize signals
    dut->rst_n = 1;
    dut->start = 0;
    dut->stop  = 0;
    dut->reset = 1;
    
    std::cout << "RESET APPLIED\n";
    // Apply reset
    for (int i = 0; i < 5; i++) {
        tick(dut);
        std::cout
            << "t = " << t++
            << ", start = " << int(dut->start)
            << ", stop = "  << int(dut->stop)
            << ", reset = " << int(dut->reset)
            << ", min = "   << int(dut->minutes)
            << ", sec = "   << int(dut->seconds)
            << std::endl;
    }

    dut->reset = 0;  // release reset

    // Start stopwatch
    dut->start = 1;
    tick(dut);
    std::cout << "STOPWATCH STARTED\n";
    std::cout
        << "t = " << t++
        << ", start = " << int(dut->start)
        << ", stop = "  << int(dut->stop)
        << ", reset = " << int(dut->reset)
        << ", min = "   << int(dut->minutes)
        << ", sec = "   << int(dut->seconds)
        << std::endl;
    dut->start = 0;

    // Run
    for (int i = 0; i < 5; i++) {
        tick(dut);
        std::cout
            << "t = " << t++
            << ", start = " << int(dut->start)
            << ", stop = "  << int(dut->stop)
            << ", reset = " << int(dut->reset)
            << ", min = "   << int(dut->minutes)
            << ", sec = "   << int(dut->seconds)
            << std::endl;
    }

    // Pause
    dut->stop = 1;
    tick(dut);
    std::cout << "STOPWATCH PAUSED\n";
    std::cout
        << "t = " << t++
        << ", start = " << int(dut->start)
        << ", stop = "  << int(dut->stop)
        << ", reset = " << int(dut->reset)
        << ", min = "   << int(dut->minutes)
        << ", sec = "   << int(dut->seconds)
        << std::endl;
    dut->stop = 0;

    // Wait while paused
    for (int i = 0; i < 5; i++) {
        tick(dut);
        std::cout
            << "t = " << t++
            << ", start = " << int(dut->start)
            << ", stop = "  << int(dut->stop)
            << ", reset = " << int(dut->reset)
            << ", min = "   << int(dut->minutes)
            << ", sec = "   << int(dut->seconds)
            << std::endl;
    }

    // Resume
    dut->start = 1;
    std::cout << "STOPWATCH RESTARTED\n";
    for (int i = 0; i < 5; i++){
        tick(dut);
        std::cout
        << "t = " << t++
        << ", start = " << int(dut->start)
        << ", stop = "  << int(dut->stop)
        << ", reset = " << int(dut->reset)
        << ", min = "   << int(dut->minutes)
        << ", sec = "   << int(dut->seconds)
        << std::endl;
    }
    dut->start = 0;
    
    std::cout << "STOPWATCH RESET\n";
    dut-> reset = 1;
    tick(dut);
    dut -> reset = 0;
    
    dut->start = 1;
    tick(dut);
    dut->start = 0;
    // Run again
    for (int i = 0; i < 65; i++) {
        tick(dut);
        std::cout
            << "t = " << t++
            << ", start = " << int(dut->start)
            << ", stop = "  << int(dut->stop)
            << ", reset = " << int(dut->reset)
            << ", min = "   << int(dut->minutes)
            << ", sec = "   << int(dut->seconds)
            << std::endl;
    }


    delete dut;
    return 0;
}

