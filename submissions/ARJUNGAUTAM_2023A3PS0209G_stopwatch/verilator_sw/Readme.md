# Stopwatch Verilator Simulation

This directory contains the Verilator setup for simulating the stopwatch design.

## Prerequisites
- Verilator installed
- Make
- C++ compiler

## Building and Running
1. Navigate to this directory: `cd verilator_sw`
2. Build the simulation: `make`
3. Run the simulation: `make run` or `./sim_stopwatch`

## Description
The simulation runs for 120 clock cycles (assuming 1Hz clock), demonstrating start, stop, and reset functionality.

## Files
- `main.cpp`: C++ testbench
- `Makefile`: Build script
- `Readme.md`: This file