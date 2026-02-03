# Stopwatch Digital Design Project
**Student Name:** Sathwik Kumble
**Student ID:** 2024A3PS0378G

## Project Description
This is a Verilog implementation of a digital stopwatch. The design uses a hierarchical structure with a central Finite State Machine (FSM) to control the start, stop, and reset functionality, and separate counters for tracking time.

## Directory Structure
* `rtl/`: Contains the Verilog source files.
  * `stopwatch_top.v`: The top-level module connecting everything.
  * `control_fsm.v`: Logic for Idle, Running, and Paused states.
  * `seconds_counter.v`: 6-bit counter for 0-59 seconds.
  * `minutes_counter.v`: 8-bit counter for minutes.
* `main.cpp`: The C++ testbench for Verilator simulation.
* `Makefile`: Automation script for compiling and running the simulation.

## How to Run
I am using **Verilator** on Windows (UCRT64) to simulate the hardware.

1. **To compile and run the simulation:**
   ```bash
   make