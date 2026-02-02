# Digital Stopwatch Controller (Hardware-Software Co-Design)

**Name:** [YOUR NAME HERE]
**ID:** [YOUR BITS ID HERE]

## 1. Overview
This project implements a digital stopwatch controller that measures elapsed time in **Minutes:Seconds**. It follows a strict hardware-software co-design approach:
* **Hardware (Verilog RTL):** Implements all timekeeping, counting logic, and state management.
* **Software (C++):** Acts as a driver to control the simulation inputs (buttons) and observe outputs via Verilator.

## 2. Hardware Design Implementation
The hardware logic is based on a custom **Gate-Level T-Flip-Flop** design.

### Design Choices
* **Modulo-200 Counter:** The stopwatch counts from **00:00 to 199:59**. It uses a 6-bit seconds counter (0-59) and an 8-bit minutes counter (0-199).
* **T-Flip-Flop Logic:** The counters utilize T-Flip-Flops where the T-input is derived by ANDing the outputs of all preceding stages (Low-Input Enable configuration).
* **Universal Reset:** A synchronous reset signal clears all counters to 00:00 and returns the FSM to the IDLE state.
* **Single Control Line:** The Start and Stop buttons control a single internal `count_en` signal via the FSM.

### Design Diagrams
Below are the hand-drawn schematics used to implement the RTL logic.

**Minutes Counter Logic (0-199):**
![Minutes Counter](diagrams/1000152287.jpg)
*Figure 1: 8-bit T-FF structure implementing the minute counter.*

**Logic Derivation & Equations:**
![Logic Equations](diagrams/1000152286.jpg)
*Figure 2: Derivation of the rollover logic for 59 (seconds) and 199 (minutes).*

---

## 3. Software Co-Design
The software simulation is built using **Verilator**. It provides a real-time, interactive command-line interface to verify the hardware functionality.

### AI Attribution
**Note:** The C++ control driver (`verilator_sw/main.cpp`) and the build configuration (`verilator_sw/Makefile`) were generated with the assistance of the **Gemini AI** model. The software was designed to interface strictly with the hardware ports defined in the assignment specifications.

---

## 4. How to Run the Simulation

### Prerequisites
* Verilator
* Make
* G++

### Build and Run Instructions
1.  Navigate to the software directory:
    ```bash
    cd verilator_sw
    ```

2.  Compile the C++ model and Verilog RTL:
    ```bash
    make
    ```

3.  Run the interactive stopwatch:
    ```bash
    ./obj_dir/Vstopwatch_top
    ```

### Controls
Once the simulation is running, use your keyboard to control the hardware:
* **s**: Press **START** (Enables counting)
* **p**: Press **STOP/PAUSE** (Holds current value)
* **r**: Press **RESET** (Clears time to 000:00)
* **q**: Quit the simulation

### Adjusting Simulation Speed (Crucial for Demo)
By default, the simulation runs at maximum CPU speed (millions of cycles per second). To make the stopwatch count at a **human-readable pace** (approx. 1 second per real second):

1.  Open `verilator_sw/main.cpp`.
2.  Locate the `usleep` command inside the print loop (around line 87):
    ```cpp
    // usleep(50000); // Uncomment this line to slow it down for human eyes
    ```
3.  **Uncomment this line** (remove the `//`).
4.  Save the file and run `make` again to rebuild.

---

## 5. Waveform Verification
To view the signal waveforms (gtkwave), run the Verilog testbench from the project root:

```bash
# From project root
iverilog -o sim_stopwatch rtl/*.v tb/tb_stopwatch.v
vvp sim_stopwatch
gtkwave dump.vcd