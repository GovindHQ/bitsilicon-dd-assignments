# Assignment 1 - Stopwatch

## Overview

This repository contains the RTL design and simulation setup for Assignment 1, which implements a stopwatch using Verilog. The design is modular and verified using **Verilator** with a C++ testbench and **ModelSim**.

The stopwatch supports basic control operations such as **start**, **stop**, and **reset**, and displays elapsed time in **minutes and seconds**.

---

## Tools & Versions
The following tools were used to develop and verify this project:
* **Verilator**: v5.020
* **GCC / G++**: v13.3.0
* **GNU Make**: 4.3
---

## Project Structure

```
src/
├── rtl/
│   ├── stopwatch_top.v
│   ├── control_fsm.v
│   ├── seconds_counter.v
│   └── minutes_counter.v
├── verilator_sw/
│   ├── stopwatch_sim.cpp
│   ├── Makefile
├── tb/
│   ├── TB_stopwatch.v
└── README.md
```

---

## Design Description

### 1. `stopwatch_top.v`

Top-level module that integrates all submodules. It connects the control FSM with the seconds and minutes counters and provides the overall stopwatch functionality.

Responsibilities:

* Clock and reset distribution
* Instantiation of FSM and counters
* Top-level signal routing

---

### 2. `control_fsm.v`

Implements a **finite state machine (FSM)** to control stopwatch operation.

States include:

* **IDLE** – Stopwatch is reset/not running
* **RUNNING** – Time is incrementing
* **PAUSED** – Stopwatch is stopped but retains its value

The FSM responds to control inputs such as `start`, `stop`, and `reset`, and generates enable signals for the counters.

---

### 3. `seconds_counter.v`

Implements the seconds counting logic.

Features:

* Counts seconds from 0 to 59
* Generates a rollover tick to increment the minutes counter
* Resets appropriately based on FSM control signals

---

### 4. `minutes_counter.v`

Implements the minutes counting logic.

Features:

* Increments on second rollover
* Resets on global reset or FSM reset
* Counts minutes from 0 to 99

---

## Simulation Setup

### `stopwatch_sim.cpp`

C++ testbench used with Verilator to simulate the RTL design.

Responsibilities:

* Generates clock and reset
* Applies control stimuli (start/stop/reset)
* Advances simulation time
* Observes, verifies and displays counter outputs

---

## Build & Run Instructions

### Step 1: Generate Verilator build files

From the `verilator_sw` directory:

```bash
make build
```
### Step 2: Run the simulation

```bash
make run
```

---

## ModelSim Simulation

The RTL design can also be simulated using ModelSim with the provided Verilog testbench in the '\tb' directory

---

## Design Choices & Assumptions

* **Modular Design**: FSM, seconds counter, and minutes counter are separated for clarity and reuse.
* **Synchronous Design**: All state and counters are clocked on the rising edge of the clock.

