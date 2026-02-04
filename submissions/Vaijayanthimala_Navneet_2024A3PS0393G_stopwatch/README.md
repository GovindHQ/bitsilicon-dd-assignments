# Digital Stopwatch Controller

## Description
This project implements a digital stopwatch using Verilog RTL and a C++ control program. The design is modular, separating the control logic from the timekeeping counters.

## Project Structure
- **rtl/**: Contains the synthesizable Verilog files (Top-level, FSM, and Counters).
- **verilator_sw/**: Contains the C++ test harness and the Makefile for the Verilator build flow.
- **tb/**: Contains the standard Verilog testbench for logic verification.

## Design Choices
- **Synchronous Logic**: To ensure reliability, all counters are synchronous. Ripple counters were not used to avoid timing hazards.
- **FSM-Based Control**: A 3-state Finite State Machine (IDLE, RUNNING, PAUSED) ensures the stopwatch only counts when explicitly started.
- **Modular Hierarchy**: The design is split into separate modules for the FSM, seconds counter, and minutes counter to ensure clarity and maintainability.

## How to Run
1. Navigate to the `verilator_sw/` directory.
2. Run `make`.
3. The program will compile the RTL into a C++ model and execute the simulation sequence, printing the time in MM:SS format.