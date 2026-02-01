# Digital Stopwatch Controller (Hardware-Software Co-Design)

## Author Information
**Name:** Akash M R
**ID:** 2024aaps0758g 

## 1. Project Overview
This project implements a **Digital Stopwatch Controller** using a hardware-software co-design approach. The core timekeeping logic and state machine are implemented in **Verilog RTL**, while the control and observation logic are handled by a **C++ software wrapper** using **Verilator**.

[cite_start]The stopwatch measures time in **MM:SS** format, supporting Start, Stop (Pause), and Reset functionalities[cite: 3, 7].

## 2. Directory Structure
The project follows the required modular structure:

* **rtl/**: Contains synthesizable Verilog source files.
    * `stopwatch_top.v`: Top-level module exposing control ports and status.
    * `control_fsm.v`: Finite State Machine managing IDLE, RUNNING, and PAUSED states.
    * `seconds_counter.v`: Modulo-60 counter for seconds.
    * `minutes_counter.v`: Modulo-100 counter for minutes.
* **verilator_sw/**: Contains the software simulation environment.
    * `main.cpp`: C++ testbench to drive the Verilated model.
    * `Makefile`: Build script for compiling and running the project.
    * `README.md`: Project documentation.
* **tb/**:
    * `tb_stopwatch_top.v`: Verilog testbench.

## 3. Tool Versions
[cite_start]The following tools were used to build and verify this project[cite: 96]:
* **Verilator:** [e.g., v4.200 - Run `verilator --version` to check]
* **Compiler:** [e.g., g++ 9.4.0 - Run `g++ --version` to check]
* **Make:** [e.g., GNU Make 4.2.1]
* **OS:** [e.g., Ubuntu 20.04 LTS / WSL2]

## 4. Build and Run Instructions
To compile and simulate the stopwatch, follow these steps:

1.  Navigate to the software directory:
    ```bash
    cd verilator_sw
    ```

2.  Build and Run the simulation:
    ```bash
    make run
    ```
    *This command uses Verilator to compile the RTL into a C++ model, builds the executable, and runs the simulation.*

3.  Clean build artifacts (optional):
    ```bash
    make clean
    ```

## 5. Design Choices
[cite_start]Per the assignment requirements, the following design decisions were made[cite: 99]:

### A. Modular Counters
[cite_start]Instead of a single large counter, the design is split into `seconds_counter` and `minutes_counter`[cite: 29].
* **Synchronous Design:** Both counters use synchronous reset and increment logic.
* **Cascading Logic:** The `minutes_counter` is enabled only when the `seconds_counter` overflows (reaches 59) AND the global enable signal is active. [cite_start]This avoids the use of ripple clocks, ensuring a fully synchronous design[cite: 9, 10].

### B. Finite State Machine (FSM)
[cite_start]The `control_fsm` module uses a 3-state Moore machine to manage the system status[cite: 27, 57]:
1.  **IDLE (2'b00):** The system waits for a start command. A reset signal here clears the counters.
2.  **RUNNING (2'b01):** Time increments on every clock cycle. The `count_enable` signal is asserted.
3.  **PAUSED (2'b10):** The system holds the current time. It returns to RUNNING on `start` or IDLE on `reset`.

**Encoding:** Binary encoding was used for simplicity and efficient state representation for a small number of states.

### C. Hardware-Software Split
* **Hardware:** Responsible strictly for "doing" (counting, state transitions, limit checking)[cite: 68].
* [cite_start]**Software:** Responsible for "commanding" (issuing start/stop signals) and "observing" (printing the MM:SS output to the console)[cite: 69].

## 6. Simulation Results
The `main.cpp` simulation performs the following verification steps:
1.  **Reset:** Ensures counters start at 00:00.
2.  **Start:** Verifies time increments.
3.  **Pause:** Verifies time retention when `stop` is asserted.
4.  **Resume:** Verifies counting continues from the paused value.
5.  **Rollover:** (Verified via logic inspection) Seconds roll over to minutes at 59.
