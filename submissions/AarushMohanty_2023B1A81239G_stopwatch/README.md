# 📘 Digital Stopwatch Controller  
Hardware–Software Co-Design using Verilog & Verilator Project by Aarush Mohanty

---------------------------------------------------------------------

1. Project Overview
-------------------

This project implements a Digital Stopwatch Controller that measures
elapsed time in minutes and seconds (MM:SS).

The design follows a hardware–software co-design approach, where:

- All timekeeping and control logic is implemented in Verilog RTL
- A C++ program interacts with the hardware model generated using Verilator
- The stopwatch supports start, stop (pause), resume, and reset operations

The design is fully synchronous, modular, and synthesizable.
Verification is done using ModelSim and Verilator.

---------------------------------------------------------------------

2. Functional Requirements (Implemented)
----------------------------------------

The stopwatch hardware satisfies all requirements specified in the assignment:

- Synchronous up-counters for seconds and minutes
- Seconds count from 00 to 59
- Minutes count from 00 to 99
- Seconds rollover increments minutes
- Start begins or resumes counting
- Stop pauses counting while retaining the current time
- Reset clears the time to 00:00 and returns the FSM to the IDLE state
- Counting occurs only when enabled by the control FSM
- FSM state and current time are observable at the top-level outputs

---------------------------------------------------------------------

3. Design Architecture
----------------------

3.1 Module Hierarchy

stopwatch_top
|
+-- control_fsm
+-- seconds_counter
+-- minutes_counter

Each module has a single, well-defined responsibility and communicates
through clean, synchronous interfaces.

---------------------------------------------------------------------

3.2 Module Descriptions
-----------------------

control_fsm.v
--------------
- Implements a Moore FSM with three states:
  - IDLE (00)
  - RUNNING (01)
  - PAUSED (10)
- Generates the enable signal for the counters
- Handles start, stop, and reset commands
- FSM state is exposed via the status output

seconds_counter.v
-----------------
- Synchronous counter for seconds (0–59)
- Counts only when enable is asserted
- Generates a one-cycle sec_overflow pulse on rollover

minutes_counter.v
-----------------
- Synchronous counter for minutes (0–99)
- Increments only on sec_overflow
- Counts only when enabled

stopwatch_top.v
---------------
- Top-level module that instantiates all submodules
- Exposes minutes, seconds, and FSM status outputs
- Implements a clean reset strategy for full system correctness

---------------------------------------------------------------------

4. Reset Strategy (Design Choice)
--------------------------------

Two reset signals are used:

- rst_n  : Active-low global system reset
- reset  : Synchronous stopwatch reset command

Inside stopwatch_top, these are combined as:

    wire global_rst_n = rst_n & ~reset;

This ensures that:
- Both FSM and counters reset to a known state
- Reset clears the stopwatch time to 00:00
- FSM returns to the IDLE state
- Behavior matches the assignment specification exactly

---------------------------------------------------------------------

5. Verification
---------------

5.1 Verilog Testbench (tb/tb_stopwatch.v)

The testbench verifies the following behaviors:

- Reset → IDLE → 00:00
- Start → RUNNING → counting begins
- Seconds rollover → minutes increment
- Stop → PAUSED → time held constant
- Resume → continues from held value
- Reset → IDLE → 00:00

Simulation output in ModelSim confirms correct behavior.

---------------------------------------------------------------------

5.2 Verilator Software Co-Design
--------------------------------

- Verilator is used to generate a cycle-accurate C++ model of the hardware
- The same Verilog RTL is used without modification
- A C++ program (main.cpp) drives:
  - clk
  - start
  - stop
  - reset
- The program reads:
  - minutes
  - seconds
  - status

The stopwatch time is printed in human-readable MM:SS format.

---------------------------------------------------------------------

6. Directory Structure
----------------------

<studentnameid>_stopwatch/
|
+-- rtl/
|   +-- stopwatch_top.v
|   +-- seconds_counter.v
|   +-- minutes_counter.v
|   +-- control_fsm.v
|
+-- tb/
|   +-- tb_stopwatch.v
|
+-- verilator_sw/
|   +-- main.cpp
|   +-- Makefile
|
+-- README.md

---------------------------------------------------------------------

7. Tools Used
-------------

- ModelSim (Version: 20.1.1)       : RTL simulation and waveform analysis
- Verilator(Version: 5.020 2024-01-01 rev (Debian 5.020-1))       : Verilog-to-C++ translation
- GNU Make (Version: 4.3,Built for x86_64-pc-linux-gnu)        : Build automation
- G++ (Version: Ubuntu 13.3.0-6ubuntu2~24.04  )            : C++ compilation

---------------------------------------------------------------------

8. Build and Run Instructions
-----------------------------

8.1 ModelSim (RTL Simulation)

Commands to run the RTL simulation:

    vlib work
    vlog rtl/*.v
    vlog tb/tb_stopwatch.v
    vsim tb_stopwatch
    run -all

---------------------------------------------------------------------

8.2 Verilator Simulation

All commands are run from the verilator_sw/ directory.

Build the project:

    make

Build and run the simulation:

    make run

Clean generated files:

    make clean
