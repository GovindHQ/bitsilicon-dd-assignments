# Digital Stopwatch Controller -

**Project Submission**  
by Harikrishnan 


---

## Project Overview

This project implements a digital stopwatch controller that measures elapsed time in MM:SS format (minutes:seconds). The design follows a hardware-software co-design approach where:

- **Hardware (Verilog RTL)**: Implements all timekeeping logic, counters, and finite state machine
- **Software (C++)**: Controls and observes the hardware model via Verilator-generated interface

###  Features
- Synchronous up-counters for seconds (0-59) and minutes (0-99)
- Three-state FSM: IDLE, RUNNING, PAUSED
- Start, Stop/Pause, and Reset control inputs
- Clean state transitions with pause/resume capability
- Observable time and status outputs
- Verilator-based C++ testbench for hardware verification

---

## Design Architecture

```
stopwatch_top (Top-level module)
├── control_fsm (Finite State Machine)
├── seconds_counter (0-59 synchronous counter)
└── minutes_counter (0-99 synchronous counter)
```

### Signal Flow

```
Control Inputs → FSM → Enable Signal → Counters → Time Outputs
                  ↓
              Status Output
```


---

## Requirements Compliance

### Counter Requirements ✓

| Requirement | Implementation | Status |
|------------|----------------|--------|
| Synchronous up-counters | Both seconds and minutes use `always @(posedge clk)` | **PASS** |
| No ripple counters | All counters are edge-triggered synchronous | **PASS** |

### Functional Requirements ✓

| # | Requirement | Implementation | Status |
|---|------------|----------------|--------|
| 1 | Start, stop, reset controls | All three inputs implemented with single-cycle synchronous operation | **PASS** |
| 2 | Increment seconds (00-59) with rollover | `seconds_counter` counts 0-59, asserts overflow at 59 | **PASS** |
| 3 | Minutes support 00-99 minimum | `minutes_counter` uses 8-bit register, supports 0-99 with rollover | **PASS** |
| 4 | Stop retains current time | FSM PAUSED state disables counting; values held | **PASS** |
| 5 | Reset clears to 00:00, returns to IDLE | Synchronous clear signal; FSM transitions to IDLE on reset | **PASS** |
| 6 | Counting only when FSM enables | `enable` signal from FSM gates all counting logic | **PASS** |
| 7 | Time and FSM state observable | `minutes`, `seconds`, and `status` are output ports | **PASS** |


## Hardware Implementation

### 1. Control FSM (`control_fsm.v`)

**Purpose:** Manages stopwatch states and generates enable signal for counters

**State Encoding:**
```verilog
IDLE    = 2'b00  // Initial state, time at 00:00
RUNNING = 2'b01  // Actively counting
PAUSED  = 2'b10  // Counting halted, time retained
```

**State Transitions:**

| Current State | Input | Next State |
|--------------|-------|------------|
| IDLE | `start` | RUNNING |
| IDLE | `reset` | IDLE |
| RUNNING | `stop` | PAUSED |
| RUNNING | `reset` | IDLE |
| PAUSED | `start` | RUNNING |
| PAUSED | `reset` | IDLE |

- Three-process FSM: state register, next-state logic (combinational), output logic
- Non-blocking assignments (`<=`) in sequential always block
- Combinational logic uses blocking assignments (`=`)
- Active-low asynchronous reset
- Enable output is high only in RUNNING state

**Design Rationale:**
- Separating next-state and output logic prevents combinational loops
- Using `always @(*)` ensures sensitivity to all inputs in combinational blocks
- Default case in state machine prevents latches

### 2. Seconds Counter (`seconds_counter.v`)

**Purpose:** Counts elapsed seconds from 0 to 59 with overflow detection

**Implementation Details:**
- 6-bit register (`[5:0]`) accommodates 0-59 range
- Increments on each clock cycle when `enable` is high
- Rolls over from 59 to 0 automatically
- Overflow signal is combinational: `overflow = (count == 59) && enable`
- Synchronous clear takes precedence over counting

**Design Rationale:**
- Combinational overflow (rather than registered) allows single-cycle propagation to minutes counter
- Priority: reset → clear → enable ensures predictable behavior
- Non-blocking assignments prevent race conditions

### 3. Minutes Counter (`minutes_counter.v`)

**Purpose:** Counts elapsed minutes from 0 to 99

**Implementation Details:**
- 8-bit register (`[7:0]`) supports 0-255 range (requirement: minimum 0-99)
- Increments only when `enable` input is high (driven by seconds overflow)
- Rolls over from 99 to 0 to meet specification
- Independent synchronous clear

**Enable Signal:**
```verilog
// In stopwatch_top.v
.enable(sec_overflow & enable)
```
- Minutes increment only when BOTH seconds overflow AND FSM is in RUNNING state
- Prevents minutes increment during pause or when stopped at 59 seconds

**Rationale:**
- Gating with FSM enable prevents spurious increments during state transitions
- Synchronous operation ensures glitch-free counting

### 4. Top-Level Integration (`stopwatch_top.v`)

**Purpose:** Instantiates and connects all submodules

**Signal Connections:**

| Signal | Source | Destination | Purpose |
|--------|--------|-------------|---------|
| `enable` | FSM output | Both counters | Gates counting operation |
| `sec_overflow` | Seconds counter | Minutes counter enable | Triggers minute increment |
| `clear_counters` | Direct from `reset` input | Both counters | Synchronous counter reset |
| `status` | FSM output | Top-level output | State visibility |

**Key Design Decisions:**

1. **Counter Clear Logic:**
   ```verilog
   assign clear_counters = reset;
   ```
   - Simple direct connection ensures immediate clearing
   - FSM separately handles state reset

2. **Minutes Enable Logic:**
   ```verilog
   .enable(sec_overflow & enable)
   ```
   - AND gate ensures minutes only increment when:
     - Seconds have overflowed (59→0), AND
     - FSM is in RUNNING state
   - Prevents minutes increment when paused at 59 seconds

3. **Modular Design:**
   - Each module has single, well-defined responsibility
   - Clean interfaces with minimal inter-module dependencies
   - Easy to verify and maintain independently

---

## Software Implementation

### Verilator C++ Control Program (`main.cpp`)

**Purpose:** Control and observe the Verilated hardware model

**Architecture:**

```
main()
  ├── Initialize DUT (Device Under Test)
  ├── Apply reset sequence
  ├── Test 1: Start stopwatch
  ├── Test 2: Pause functionality
  ├── Test 3: Resume from pause
  ├── Test 4: Reset operation
  ├── Test 5: Minute rollover (59s → 1m 0s)
  └── Cleanup and report
```

**Key Functions:**

1. **`print_status()`**
   - Decodes status register to human-readable state
   - Formats time as MM:SS with zero-padding
   - Called after every clock cycle for continuous monitoring

2. **`tick()`**
   - Generates one complete clock cycle (rise + fall)
   - Calls `eval()` for each edge to update model
   - Automatically prints status after each cycle

3. **`wait_cycles()`**
   - Helper to advance simulation by N cycles
   - Used for time delays in test sequences



### Makefile

*
**Build Process:**

1. **Verilate Phase:**
   ```bash
   verilator -Wall -Wno-fatal --trace --cc --exe --build \
       -o ../stopwatch_sim rtl/*.v main.cpp
   ```
   - Generates C++ model from Verilog
   - Enables waveform tracing (`--trace`)
   - Creates executable in parent directory

2. **Compilation Phase:**
   - Makefile invokes generated `obj_dir/Vstopwatch_top.mk`
   - Links Verilated model with C++ control program
   - Produces final executable: `stopwatch_sim`



---

## Build and Run Instructions

### Prerequisites

**Required Tools:**
- Verilator (version 5.020)
- GCC/G++ compiler (13.3.0)
- Make utility

**Installation:**
```bash
# Ubuntu/Debian
sudo apt-get install verilator g++ make gtkwave

# macOS (Homebrew)
brew install verilator gtkwave

# Verify installation
verilator --version
```

### Building the Verilator Simulation

```bash
# Navigate to verilator_sw directory
cd verilator_sw/

# Build the simulation
make

# Or build and run in one command
make run
```


### Running the Verilog Testbench (Optional)

For  Verilog simulation:

**Using Icarus Verilog(12.0 (stable)):**
```bash
# Compile
iverilog -o stopwatch_sim \
    rtl/stopwatch_top.v rtl/control_fsm.v \
    rtl/seconds_counter.v rtl/minutes_counter.v \
    tb/tb_stopwatch.v

# Run
vvp stopwatch_sim

```



### Cleaning Build Artifacts

```bash
# From verilator_sw directory
make clean

# Removes:
# - obj_dir/ (Verilated C++ files)
# - stopwatch_sim (executable)
# - *.vcd (waveform dumps)
```

---
