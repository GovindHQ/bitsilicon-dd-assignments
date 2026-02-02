#include <iostream>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "Vstopwatch_top.h"
#include "verilated.h"

// --- Linux Helper: Check for keypress without stopping simulation ---
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

// 1 Clock Cycle = 20ns
void tick(Vstopwatch_top* top, vluint64_t& main_time) {
    top->clk = 1; top->eval(); main_time += 10;
    top->clk = 0; top->eval(); main_time += 10;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top* top = new Vstopwatch_top;
    vluint64_t main_time = 0;
    int last_printed_second = -1;

    // 1. Initial Reset
    top->rst_n = 0; tick(top, main_time);
    top->rst_n = 1; tick(top, main_time);
    std::cout << "=====================================" << std::endl;
    std::cout << "=== REAL-TIME STOPWATCH (200-MIN) ===" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Press 's' to START,\n 'p' to PAUSE,\n 'r' to RESET,\n 'q' to QUIT." << std::endl;

    bool keep_running = true;
    while (keep_running) {
        
        // A. Check for User Input (Non-blocking)
        if (kbhit()) {
            char cmd = getchar();
            // Reset pulsed signals
            top->start = 0; top->stop = 0; top->reset = 0;

            switch (cmd) {
                case 's': 
                    std::cout << "\n[CMD] START" << std::endl; 
                    top->start = 1; tick(top, main_time); top->start = 0;
                    break;
                case 'p': 
                    std::cout << "\n[CMD] PAUSE" << std::endl; 
                    top->stop = 1; tick(top, main_time); top->stop = 0;
                    break;
                case 'r': 
                    std::cout << "\n[CMD] RESET" << std::endl; 
                    top->reset = 1; tick(top, main_time); top->reset = 0;
                    break;
                case 'q': 
                    keep_running = false; 
                    break;
            }
        }

        // B. Advance Simulation Time
        tick(top, main_time);

        // C. Print Time ONLY when it changes
        if ((int)top->seconds != last_printed_second) {
             std::cout << "\rTime: " 
                       << std::setw(3) << std::setfill('0') << (int)top->minutes << ":"
                       << std::setw(2) << std::setfill('0') << (int)top->seconds 
                       << " [Status: " << (int)top->status << "]   " << std::flush;
             last_printed_second = (int)top->seconds;
             
             // Optional: Sleep a tiny bit to look like real seconds?
            //usleep(50000); // Uncomment this line to slow it down for human eyes
        }
        
        // If paused, we don't want to burn 100% CPU, so sleep a tiny bit
        if (top->status != 1) usleep(1000); 
    }

    top->final();
    delete top;
    return 0;
}