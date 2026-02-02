#include <verilated.h>
#include "Vstopwatch_top.h"
#include <cstdio>

vluint64_t main_time = 0;

double sc_time_stamp() { return main_time; }

// One full clock cycle = 2 time steps (low->high)
static void tick(Vstopwatch_top *top) {
    top->clk = 0;
    top->eval();
    main_time++;

    top->clk = 1;
    top->eval();
    main_time++;
}

// Print once per “second” (here: per rising edge)
static void print_time(Vstopwatch_top *top, int sec, const char *label) {
    unsigned int mm = top->minutes;
    unsigned int ss = top->seconds;
    unsigned int st = top->status;

    const char *st_str =
        (st == 0) ? "IDLE" :
        (st == 1) ? "RUNNING" :
        (st == 2) ? "PAUSED" : "ERROR";

    printf("T=%2d sec | %s | %02u:%02u status=%u (%s)\n",
           sec, label, mm, ss, st, st_str);
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top *top = new Vstopwatch_top;

    // Init inputs
    top->clk   = 0;
    top->rst_n = 0;
    top->start = 0;
    top->stop  = 0;
    top->reset = 0;

    // Global reset for a few cycles
    for (int i = 0; i < 5; ++i) tick(top);
    top->rst_n = 1;

    // We’ll track “seconds” as number of rising edges
    int sim_sec = 0;

    // Helper lambda to advance N seconds and print each second
    auto run_seconds = [&](int N, const char *label){
        for (int i = 0; i < N; ++i) {
            // one “second” = one tick (contains one posedge)
            tick(top);
            sim_sec++;
            print_time(top, sim_sec, label);
        }
    };

    // 1) After reset, stay IDLE 10 “sec”
    run_seconds(10, "IDLE");

    // 2) START (one-cycle pulse) then run 50 “sec”
    top->start = 1;
    tick(top);  // one second with start=1
    sim_sec++;
    top->start = 0;
    print_time(top, sim_sec, "START pressed");
    run_seconds(50, "RUNNING");

    // 3) STOP (pause)
    top->stop = 1;
    tick(top);
    sim_sec++;
    top->stop = 0;
    print_time(top, sim_sec, "STOP pressed");

    run_seconds(15, "PAUSED");

    // 4) START again (resume)
    top->start = 1;
    tick(top);
    sim_sec++;
    top->start = 0;
    print_time(top, sim_sec, "RESUME");

    run_seconds(35, "RUNNING");

    // 5) RESET
    top->reset = 1;
    tick(top);
    sim_sec++;
    top->reset = 0;
    print_time(top, sim_sec, "RESET pressed");

    run_seconds(10, "IDLE after reset");

    // 6) Final run to test rollover
    top->start = 1;
    tick(top);
    sim_sec++;
    top->start = 0;
    print_time(top, sim_sec, "FINAL START");

    run_seconds(75, "RUNNING final");

    printf("\n=== FINAL RESULTS ===\n");
    print_time(top, sim_sec, "FINAL");

    top->final();
    delete top;
    return 0;
}
