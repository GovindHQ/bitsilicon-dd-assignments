# Digital Stopwatch Controller

## Design Choices
1. **Synchronous Logic:** The design uses a single clock domain. The 1Hz timing is generated via a tick enable pulse, not a derived clock, to ensure timing reliability.
2. **Parameters:** The 'TICK_LIMIT' is parameterized in 'stopwatch_top.v'. It is currently set to 5 for simulation visibility (so seconds count up fast). **For real hardware, set this to 50,000,000.**
3. **FSM:** A 3-state FSM (IDLE, RUNNING, PAUSED) controls the enable signal for the counters.

## How to Run
1. **RTL Simulation:** Use Icarus Verilog on 'tb/tb_stopwatch.v'.
2. **Verilator:** Run 'make' in the 'verilator_sw'directory. 
