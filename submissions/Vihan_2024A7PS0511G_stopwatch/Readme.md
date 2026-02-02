# Digital Stopwatch Controller
A hardware-software co-design project using Verilog and Verilator.

## Structure
- `/rtl`: Verilog source files.
- `/tb`: Traditional Verilog testbench.
- `/verilator_sw`: C++ control program and Makefile.

## How to Build
1. Install Verilator.
2. Navigate to `verilator_sw/`.
3. Run `make`.

## Design Choices
- **Synchronous Counters**: Used to avoid glitches common in ripple counters.
- **FSM-based Control**: Ensures clear state transitions between IDLE, RUNNING, and PAUSED.