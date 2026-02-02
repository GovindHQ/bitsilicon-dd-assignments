# Digital Stopwatch Controller

**Name:** Ayush Pralhad Shinde
**ID:** 2024A8PS0696G

## Overview
This project is a hardware-software co-design of a Digital Stopwatch. The timekeeping logic is implemented in Verilog RTL, while the control logic is handled by a C++ software wrapper using Verilator.

## Directory and file Structure
* **src/rtl/**: Contains the synthesizable Verilog source files.
* **src/tb/**: Contains the Verilog testbench.
* **src/verilator_sw/**: Contains the C++ control program and Makefile.
* **docs/**: Contains verification screenshots , some notes written on Notion.

## Tools Used
* **Verilog Simulation:** Icarus Verilog , iverilog , GTKWave
* **Software Co-Design:** Verilator , Make, G++ compiler

## Design Choices

### 1. Hardware Architecture (RTL)
* **Modular Design:** The system is split into `seconds_counter`, `minutes_counter`, and `control_fsm`.
* **FSM States:** The Control FSM uses three states:
    * `IDLE (00)`: System reset, counters at 0.
    * `RUNNING (01)`: Counters enabled, time incrementing.
    * `PAUSED (10)`: Counting stops, but current time value is retained.
* **Clock Speed Assumption:** For simulation purposes, the design assumes a fast clock where 1 second equals roughly 20ns to speed up verification.

### 2. Verification Strategy
* **Hardware Testbench:** `tb_stopwatch.v` verifies the core logic using a 20ns clock period.
* **Software Simulation:** The C++ wrapper (`main.cpp`) acts as a driver, issuing commands to the Verilated model to demonstrate the Start, Stop, Resume, and Reset functionality.

## How to Run

### 1. Hardware Simulation (Icarus Verilog)
To verify the Verilog logic independently:
```bash
iverilog -o my_stopwatch rtl/stopwatch_top.v rtl/control_fsm.v rtl/seconds_counter.v rtl/minutes_counter.v tb/test/tb_stopwatch.v
vvp my_stopwatch
