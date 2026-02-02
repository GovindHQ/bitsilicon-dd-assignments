# Stopwatch-Assign1-Harshit Raymus  
## Overview

This project implements a digital stopwatch that measures elapsed time in **minutes and seconds (MM:SS)**.  
All timekeeping and control logic is implemented in **hardware (Verilog RTL)**.  
A **C++ program using Verilator** drives the control inputs and observes the outputs.

The stopwatch supports:

- start
- stop (pause)
- resume
- reset

The current time and FSM state are observable through the top-level module.

---

## Directory Structure
stopwatch/ 
├── rtl/
│ ├── stopwatch_top.v
│ ├── control_fsm.v
│ ├── seconds_counter.v
│ └── minutes_counter.v
├── tb/
│ └── tb_stopwatch.v
├── verilator_sw/
│ ├── main.cpp
│ └── Makefile
└── README.md

---

## Tools Used

- Verilator
- GNU g++
- GNU make
- Icarus Verilog
- Visual Studio Code (WSL – Ubuntu)

---

## Top-Level Interface

Top module:
stopwatch_top

Ports:

- `clk`
- `rst_n` (active-low global reset)
- `start`
- `stop`
- `reset`
- `minutes[7:0]`
- `seconds[5:0]`
- `status[1:0]`

FSM state encoding:

- `00` – IDLE (Status=0)
- `01` – RUNNING(Status=1)
- `10` – PAUSED(Status=2)

---

## Design Architecture
stopwatch_top
├── control_fsm
├── seconds_counter
└── minutes_counter

---

## Control FSM

The control FSM has three states:

- IDLE
- RUNNING
- PAUSED

State transitions:

- IDLE → RUNNING on `start`
- RUNNING → PAUSED on `stop`
- PAUSED → RUNNING on `start`
- Any state → IDLE on `reset`

The FSM generates a `count_en` signal.  
The counters increment **only when `count_en = 1`**.

The current FSM state is exported through the `status` output.

---

## Seconds Counter

The seconds counter:

- is fully synchronous
- counts from `00` to `59`
- resets to `00` on:
  - global reset (`rst_n`)
  - user reset (`reset`)
- increments only when `count_en` is high

---

## Minutes Counter

The minutes counter:

- is fully synchronous
- counts from `00` to `99`
- resets to `00` on:
  - global reset (`rst_n`)
  - user reset (`reset`)

Minute increment is generated using a **combinational carry condition**:
inc = count_en && (seconds == 59)

This avoids the one-cycle delay that would occur if a registered carry signal were used.

---

## Reset Strategy

Two reset signals are used:

- `rst_n`  
  Global active-low reset (power-up / simulation reset)

- `reset`  
  User stopwatch reset

The user `reset` clears:

- the FSM state (back to IDLE)
- the seconds counter
- the minutes counter

This satisfies the requirement:

> Reset shall clear the time to 00:00 and return the FSM to an idle state.

---

## Software Co-Design

Verilator is used to generate a cycle-accurate C++ model of the hardware.

The C++ program:

- drives only the top-level inputs
- reads only the top-level outputs
- does **not** implement any timekeeping logic

The program demonstrates:

- reset
- start
- pause
- resume
- long-duration run
- minute rollover
- FSM state observation

The time is printed in human-readable `MM:SS` format along with the FSM status.

---

## Build and Run (Verilator)

From the project root:

bash:
cd verilator_sw
make
make run

Clean build:
make clean

RTL Simulation:
iverilog -g2012 -o sim rtl/*.v tb/tb_stopwatch.v
vvp sim

## Design Notes

* All counters are synchronous.
* Ripple counters are not used.
* All sequential logic uses non-blocking assignments.
* No simulation-only constructs or delays are used in RTL.
* Minute rollover is generated combinationally from the seconds value to ensure correct timing.

## Summary
This project demonstrates a clean FSM-controlled stopwatch design with modular RTL and a Verilator-based software driver
