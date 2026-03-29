# Digital Stopwatch Controller (Hardware-Software Co-Design)

## Overview
This project implements a Digital Stopwatch Controller using a hardware-software co-design approach. The core logic (counters and FSM) is implemented in Verilog RTL, while the verification and control are handled by a C++ testbench using Verilator.

## Directory Structure
* `rtl/`: Contains synthesizable Verilog source files (`stopwatch_top.v`, `control_fsm.v`, `seconds_counter.v`, `minutes_counter.v`).
* `verilator_sw/`: Contains the C++ control program (`main.cpp`) and the `Makefile`.
* `tb/`: Contains the Verilog testbench (`tb_stopwatch.v`).

## Design Choices
* **Modular Architecture:** The design is split into three dedicated modules:
    * `control_fsm`: A 3-state Finite State Machine (IDLE, RUNNING, PAUSED) handling control signals.
    * `seconds_counter`: A generic 0-59 counter with combinational overflow logic to ensure immediate minute updates.
    * `minutes_counter`: A 0-99 counter driven by the seconds overflow signal.
* **Synchronous Logic:** All sequential logic is triggered on the rising edge of the clock.
* **Reset Strategy:** * `rst_n`: Asynchronous active-low system reset (power-on).
    * `reset`: Synchronous active-high user reset (functional).
* **C++ Integration:** The simulation treats 1 clock cycle as 1 second (no clock divider) to speed up verification of minute rollovers.

## Tools Used
* **Verilator:** Used to compile Verilog RTL into a cycle-accurate C++ model.
* **Make:** Used for build automation.
* **GTKWave:** (Optional) Used for waveform viewing if VCD files are generated.

## Build and Run Instructions
To compile and run the simulation, navigate to the `verilator_sw` directory and run:

```bash
make run