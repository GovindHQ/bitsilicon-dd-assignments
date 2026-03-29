Digital Stopwatch Controller: Hardware-Software Co-Design
Project Overview
This project implements a digital stopwatch using a hardware software co design approach. The timekeeping and control logic are written in Verilog (RTL), while a C++ control program (using Verilator) serves as the software interface to drive and observe the hardware.

Directory Structure
Following the assignment requirements, the project is organized as follows:


Hardware Design Choices
Synchronous Counters: Both seconds and minutes use synchronous up-counters

FSM-Driven Logic: A Finite State Machine handles the transitions between IDLE, RUNNING, and PAUSED. This ensures that the stopwatch only counts when the START signal is received and retains its state when STOP is pressed.

Rollover Logic: The seconds_counter generates a roll pulse when it hits 59. This pulse acts as the enable signal for the minutes_counter, ensuring a precise rollover from 59s to 1m.

Unified Reset: A combined system_rst_n wire allows the hardware to be cleared by either a physical hardware reset (rst_n, active-low) or a user reset button (reset, active-high).

Software Design
The C++ program (main.cpp) acts as the 'Driver' for the hardware:

Clock Management: Manually toggles the clock signal in a simulation loop to drive the synchronous logic.

Automated Testing: The software sequence performs an initial reset, starts the timer, verifies a minute rollover, tests the pause/resume functionality, and finally tests the user reset button.

Human-Readable Output: Hardware outputs are formatted into a [MM:SS] string for terminal display.

Build and Execution Instructions
Prerequisites
Ensure you have the following tools installed:

Verilator (Tested version: 5.020)

G++ / Build-Essential

Icarus Verilog & GTKWave (For RTL verification)

Running the Verilator Simulation
To build the hardware model and run the C++ control program:

Navigate to the verilator_sw folder:

Bash
cd verilator_sw
Compile and run using the Makefile:

Bash
make
Running the Verilog Testbench (Icarus)
To verify the raw RTL before software integration:

Bash
iverilog -o sim.vvp ../rtl/*.v ../tb/tb.v
vvp sim.vvp
# Optional: view waveforms
gtkwave dump.vcd
Tool Versions


Verilator: [5.020]

Icarus Verilog: [12.0]

Compiler: g++ (Ubuntu 11.4.0)