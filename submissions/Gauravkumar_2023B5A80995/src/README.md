
Overview

This project implements a digital stopwatch (MM:SS) using a hardware–software co-design approach. All timekeeping and control logic are implemented in Verilog hardware, while a C++ program interacts with the hardware model generated using Verilator.

Design Approach:

The hardware consists of a control FSM (IDLE, RUNNING, PAUSED), a seconds counter (0–59), and a minutes counter (0–99).

The FSM generates an enable signal that explicitly controls when counting occurs.

The seconds counter asserts a rollover signal on overflow, which increments the minutes counter.

All logic is fully synchronous; no ripple counters are used.

Software Co-Design:

Verilator converts the Verilog design into a cycle-accurate C++ model.
The C++ program generates clock cycles, issues start, stop, and reset commands, and reads the stopwatch time, printing it in MM:SS format.
Each clock cycle represents one simulated second for faster execution.

Tools Used:

Verilog, Verilator (C++14), VS Code.