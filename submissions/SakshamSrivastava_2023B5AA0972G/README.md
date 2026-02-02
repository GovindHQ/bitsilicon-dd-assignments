Digital Stopwatch Controller

This submission implements a digital stopwatch using Verilog RTL.
The design uses synchronous seconds (00–59) and minutes (00–99) counters,
controlled by a finite state machine (FSM) with IDLE, RUNNING, and PAUSED states.

The stopwatch supports start, stop, and reset operations.
RTL functionality was verified using ModelSim.
Software co-design was implemented using Verilator with a C++ test driver.

Author: Saksham Srivastava
