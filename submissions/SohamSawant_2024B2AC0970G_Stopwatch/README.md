# Digital Stopwatch Controller

## Overview
This project implements a Digital Stopwatch Controller that measures elapsed time in
minutes and seconds (MM:SS). The design follows a hardware–software co-design approach:
all timekeeping and control logic is implemented in Verilog RTL, while a C++ program
interacts with the hardware model generated using Verilator.

---

## Hardware Design (Verilog RTL)

### Functional Description
- The stopwatch measures time in seconds (00–59) and minutes (00–99).
- The design supports start, stop (pause), resume, and reset operations.
- Counting occurs only when enabled by the control FSM.
- When paused, the stopwatch retains its current time.
- Reset clears the time to 00:00 and returns the FSM to the IDLE state.

### Modules
- **stopwatch_top.v**  
  Top-level module exposing control inputs and observable outputs.
- **seconds_counter.v**  
  Synchronous up-counter for seconds (0–59).
- **minutes_counter.v**  
  Synchronous up-counter for minutes (0–99).
- **control_fsm.v**  
  Control finite state machine with states:
  - IDLE
  - RUNNING
  - PAUSED

---

## Verification (ModelSim)
- The Verilog design was verified using ModelSim.
- A testbench was used to validate FSM transitions and counter behavior.
- Waveforms were inspected to confirm correct functionality.

---

## Software Co-Design (Verilator)
- Verilator was used to generate a cycle-accurate C++ model of the hardware.
- A C++ program controls the stopwatch and prints time in MM:SS format.

### Build and Run
```bash
cd verilator_sw
verilator -Wall --timing --cc ../rtl/*.v --top-module stopwatch_top --exe main.cpp --build
./obj_dir/Vstopwatch_top