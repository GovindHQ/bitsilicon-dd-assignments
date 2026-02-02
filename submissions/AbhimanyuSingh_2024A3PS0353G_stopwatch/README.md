Stopwatch Hardware-Software Co-Design Project

This project implements a digital stopwatch using Verilog HDL and hardware-software co-design methodology.

The stopwatch is designed in Verilog, simulated in ModelSim, and co-simulated with C++ using Verilator.

Directory Structure:

rtl/		-> Verilog source files
tb/		-> Verilog testbench
verilator_sw/   -> C++ program and Makefile

Files:

rtl/stopwatch_top.v
rtl/seconds_counter.v
rtl/minutes_counter.v
rtl/control_fsm.v
tb/tb_stopwatch.v
verilator_sw/main.cpp
verilator_sw/Makefile

How to Run Verilator Simulation:

cd verilator_sw
make
make run
