# Digital Stopwatch Controller - Assignment 1

**Name:** Laural Jacob  
**ID:** 2024A7RM0204G

## Overview
Digital stopwatch implemented using Verilog RTL with FSM control and Verilator-based C++ simulation.

## Design Summary
- FSM: IDLE, RUNNING, PAUSED
- Synchronous seconds (0–59) and minutes (0–99) counters
- Timekeeping fully in hardware
- Software controls start/stop/reset only

## Tools
- Icarus Verilog
- Verilator
- GCC
- WSL (Ubuntu)

## Verification
- RTL verified via Verilog testbench
- Hardware–software co-design verified using Verilator
