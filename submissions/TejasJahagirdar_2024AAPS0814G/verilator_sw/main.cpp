#include <verilated.h>
#include "Vstopwatch_top.h"
#include <iostream>
#include <iomanip>

// Advance simulation by ONE clock cycle (1 second)
void tick(Vstopwatch_top* sw)
{
    sw->clk = 0;
    sw->eval();
    sw->clk = 1;
    sw->eval();
}

// Pulse a signal AND advance time (used for START, RESET)
void pulse_with_tick(Vstopwatch_top* sw, CData& signal)
{
    signal = 1;
    tick(sw);     // consumes exactly one second
    signal = 0;
}

// Assert a signal WITHOUT advancing time (used for STOP)
void pulse_no_tick(CData& signal)
{
    signal = 1;
}

// Deassert a signal
void release(CData& signal)
{
    signal = 0;
}

// Print time
void print_time(Vstopwatch_top* sw, const char* tag = "")
{
    std::cout << "Time = "
              << std::setw(2) << std::setfill('0') << (int)sw->minutes
              << ":"
              << std::setw(2) << std::setfill('0') << (int)sw->seconds
              << tag
              << std::endl;
}

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);


    // Create stopwatch hardware

    Vstopwatch_top* sw = new Vstopwatch_top;

    // Initial conditions
    sw->clk   = 0;
    sw->rst_n = 0;   // active-low reset
    sw->start = 0;
    sw->stop  = 0;
    sw->reset = 0;


    // Global reset

    std::cout << "Global reset\n";
    tick(sw);
    tick(sw);
    sw->rst_n = 1;


    // START stopwatch

    std::cout << "Stopwatch STARTED\n";
    pulse_with_tick(sw, sw->start);

    // Run for 300 seconds
    for (int i = 0; i < 300; i++)
    {
        print_time(sw);
        tick(sw);
    }


    // PAUSE stopwatch 

    // Print last running time
    print_time(sw);
    std::cout << "Stopwatch PAUSED\n";

    // Assert stop
    sw->stop = 1;

    // Tick once so FSM captures PAUSE
    tick(sw);

    // Stay paused
    for (int i = 0; i < 5; i++)
    {
        print_time(sw, " (PAUSED)");
        tick(sw);
    }


    // Release stop
    release(sw->stop);


    // RESUME stopwatch

    std::cout << "Stopwatch RESUMED\n";
    pulse_with_tick(sw, sw->start);

    // Run for 50 more seconds
    for (int i = 0; i < 50; i++)
    {
        print_time(sw);
        tick(sw);
    }


    // RESET stopwatch

    std::cout << "Stopwatch RESET\n";
    pulse_with_tick(sw, sw->reset);
    print_time(sw);

    delete sw;
    return 0;
}
