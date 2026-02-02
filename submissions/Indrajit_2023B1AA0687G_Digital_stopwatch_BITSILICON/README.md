# Digital Stopwatch Controller – Design Approach

## Problem Approach
The stopwatch is implemented using a hardware–software co-design methodology.  
All timing and control logic is implemented in hardware (Verilog RTL), while the
software layer is used only for stimulation and observation.

The design separates control logic from timekeeping logic to ensure modularity
and correctness.

## Design Strategy

### 1. Control via Finite State Machine (FSM)
A Finite State Machine (FSM) controls when the stopwatch is allowed to count.

States:
- IDLE
- RUNNING
- STOPPED

Inputs:
- start
- stop
- reset

Output:
- count_enable

The FSM does not perform any counting.  
It only decides whether counting is enabled.

### 2. Synchronous Timekeeping Counters
Elapsed time is maintained using synchronous up-counters:

- Seconds counter: 0–59
- Minutes counter: 0–99

Counters increment only when:
- The FSM is in the RUNNING state
- A tick_1s pulse is asserted

All counters share a single global clock, ensuring a fully synchronous design
with no ripple counter behavior.

### 3. Separation of Concerns
- FSM (control path): decides when time progresses
- Counters (data path): determine how time advances
- Clock: defines when registers update

This separation simplifies debugging and guarantees correct pause and resume
behavior.

### 4. Simulation and Verification
The design is verified through simulation:

- FSM is tested independently before integrating counters
- Edge cases such as reset during run and second-to-minute rollover are validated
- Verilator is used to connect the hardware model with a C/C++ testbench

## Key Design Principles
- Behavioral RTL over gate-level logic
- Single global clock (no clock gating)
- Enable-based counter control
- Robust handling of illegal FSM states

## Outcome
This approach results in a clean, modular, and testable stopwatch design that
meets all functional requirements while following good synchronous digital
design practices.
