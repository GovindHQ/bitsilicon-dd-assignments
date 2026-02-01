# Digital Stopwatch Controller – Hardware/Software Co-Design
**Student Name:** Arihant Bansal 
**Student ID:** 2024A7PS0629G

## Project Overview
This project implements a **Digital Stopwatch Controller** that measures elapsed time in **minutes and seconds (MM:SS)**.  
It follows a **hardware–software co-design** methodology:

- The **hardware (Verilog RTL)** implements all timekeeping, counting, and control logic.
- The **software (C++ program)** controls and observes the hardware model generated using **Verilator**.

All functional behavior of the stopwatch resides in hardware; the software acts only as a controller and monitor.

---

## Design Choices

### Modular RTL Architecture
The design follows a strict modular hierarchy, separating functionality into independent RTL modules:
- `control_fsm.v` – control and state management
- `seconds_counter.v` – seconds counting logic
- `minutes_counter.v` – minutes counting logic  

This separation improves readability, testability, and maintainability.

### Synchronous Counting
All counters are implemented as **fully synchronous up-counters**, clocked on the rising edge of the system clock.

### No Ripple Counters
In compliance with the hardware design constraints, **ripple counters were not used**.  
All state updates occur synchronously.

### FSM State Encoding
The control FSM uses a dedicated state machine to manage stopwatch operation:

- `00` – **IDLE**
- `01` – **PAUSED**
- `10` – **RUNNING**

The FSM output directly determines whether the counters increment, hold their value, or reset.

### Software Interface
The C++ program (`main.cpp`) interfaces with the Verilated hardware model using a **cycle-accurate simulation**.  
It issues control commands (start, pause, reset) and reports the current stopwatch value in a human-readable **MM:SS** format.

---

## Tool Versions

- **Verilator**: v5.0+ (used for C++ model generation)
- **Icarus Verilog (iverilog)**: v11.0+ (used for RTL verification)
- **GTKWave**: v3.3+ (used for waveform analysis)
- **Compiler**: `g++` (supporting C++11 or later)

---

### To generate testbench LLM was used


## Build and Execution Commands


### 1. Software Co-Design (Verilator)

### Step 1: Verilate the design
verilator -Wall -Wno-EOFNEWLINE -Wno-UNUSEDSIGNAL \
  --cc rtl/stopwatch_top.v \
  --exe verilator_sw/main.cpp \
  -Irtl \
  --Mdir verilator_sw/obj_dir

### Step 2: Compile the C++ executable
make -C verilator_sw/obj_dir -f Vstopwatch_top.mk Vstopwatch_top

### Step 3: Run the simulation
./verilator_sw/obj_dir/Vstopwatch_top        
(directly run if obj_dir folder in verilator_sw ->skip step 1 and 2)

https://github.com/user-attachments/assets/aa259b4c-15da-4226-837b-21dc457b0054
