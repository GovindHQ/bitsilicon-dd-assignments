# Synchronous FIFO Design and Verification

## Project Overview
This project implements a **Synchronous FIFO (First-In-First-Out)** memory buffer using Verilog HDL. A FIFO is a digital storage structure that ensures the first piece of data written is the first one to be read out. This specific design uses a single clock for both reading and writing operations.

## Technical Specifications
* **Data Width**: 8 bits (default).
* **Depth**: 16 entries (default).
* **Reset**: Active-low synchronous reset.
* **Status Flags**: Includes Full and Empty signals to prevent data loss.
* **Occupancy Counter**: A real-time counter tracking the number of items currently stored.

## File Structure
The project is organized into the following directories:

* **rtl/**: Contains the hardware logic.
    * `sync_fifo_top.v`: The top-level module.
    * `sync_fifo.v`: The core FIFO logic including pointers and memory.
* **tb/**: Contains the verification environment.
    * `tb_sync_fifo.v`: The self-checking testbench.
* **docs/**: Documentation.
    * `README.md`: Project instructions and summary.

## Verification Strategy
The design is verified using a **Self-Checking Testbench** that includes:

1. **Golden Reference Model**: An independent behavioral model that predicts the correct FIFO state every cycle.
2. **Scoreboard**: Automatically compares the hardware outputs against the Golden Model and terminates on any mismatch.
3. **Directed Tests**: Specific scenarios including Reset, Fill/Drain, Overflow/Underflow, and Pointer Wrap-around.
4. **Coverage Counters**: Tracks how many times specific conditions (like full or empty) were triggered during the simulation.

## How to Run the Simulation
You will need **Icarus Verilog** and **GTKWave** installed on your system.

### 1. Compile the Design
Run this command in your terminal from the project root folder:
```bash
iverilog -o fifo_sim rtl/sync_fifo_top.v rtl/sync_fifo.v tb/tb_sync_fifo.v
```
### 2. Execute the Simulation
Run the compiled simulation executable:
```bash
vvp fifo_sim
```
### 3. View Waveforms
To visually inspect the digital signals, generate the VCD file during simulation and open it with GTKWave:
```bash
gtkwave dump.vcd
```