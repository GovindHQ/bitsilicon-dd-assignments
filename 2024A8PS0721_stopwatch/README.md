# Digital Stopwatch Controller

## Overview
This project implements a Digital Stopwatch Controller that measures elapsed time in
minutes and seconds (MM:SS). The design follows a hardware–software co-design approach:
all timekeeping and control logic is implemented in Verilog RTL, while a C++ program
interacts with the hardware model generated using Verilator.

---

## 1. Directory Structue
```text
src
|
+-- rtl/
| +-- stopwatch_top.v
| +-- seconds_counter.v
| +-- minutes_counter.v
| +-- control_fsm.v
|
+-- tb/
| +-- tb_stopwatch.v
|
+-- verilator_sw/
| +-- main.cpp
| +-- Makefile

README.md
```
---

## 2. Tools Version
- Verilator : 5.045
- ModelSim-Intel : 2020.1
- C++ compiler : g++ 13.3.0

## 3. RTL Design Overview (rtl/)
1. **stopwatch_top.v**
- Top-level module controlling the entire system of inputs and outputs.
- Input : clk, rst_n, start, stop, reset
- Ouput : minutes, seconds, status (IDLE, RUNNING, PAUSED)

2. **control_fsm.v**
- Control finite state machine
- Three states: IDLE (00), RUNNING (01), PAUSED (10).
- Inputs: clk, rst_n, start, stop, reset.
- Outputs:enable_count, status.

3. **mintues_counter.v**
- Synchronous up-counter for minutes(0-99)
- Inputs: clk, rst_n, reset, enable_min (driven by sec_rollover).
- Output: minutes.

4. **seconds_counter.v**
- Synchronous up-counter for seconds (0–59).
- Inputs: clk, rst_n, reset, enable.
- Outputs: seconds, sec_rollover (when 59 -> 0, becomes 1).
- sec_rollover to generate minute increments for minutes_counter.

---

## 4. Testbench (tb/tb_stopwatch.v)
- Generates a clock-1sec:20ns
- Reset Release: Holds rst_n=0,IDLE (10 cycles wait).
- Start: Pulses start; runs for 50 "seconds" 
- Stop: Pulses stop waits 15 cycles.
- Resume: Pulses start again; runs extra 35 "seconds" (~01:25 total).
- Reset: Pulses reset (clears to 00:00 IDLE),waits 10 cycles.
- Rollover Test: Starts and runs 75 "seconds" to test sec_rollover.
- Final(100 ns) and $finish.

---

## 5. Verilator (verilator_sw/main.cpp)
- tick() : full clock cycle, Each tick = 1 simulated "second."
- Reset (5 cycles rst_n = 0) → IDLE (10 sec)
- START pulse → RUNNING (50 sec)
- STOP pulse → PAUSED (15 sec)  
- START pulse → RUNNING (35 sec)
- RESET pulse → IDLE (10 sec)
- START → RUNNING (75 sec,checks sec_rollover)

---

# Build and Run
```bash
cd verilator_sw
make sim
make run