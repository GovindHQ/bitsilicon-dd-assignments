                                                              Digital Stopwatch Controller

                                                                  Name: Vinit Vibhute  
                                                               Student ID:2023AAPS0616G



## Tool Versions

- Verilog Simulator: Xilinx Vivado 2020.2 (XSIM)
- Hardware-Software Integration: Verilator 4.038
- C++ Compiler: g++ (GCC) 11.4.0
- Build System: GNU Make 4.3
- Development Platform: WSL Ubuntu 22.04

---

## Build Commands

### Vivado Simulation

1. Create new RTL project in Vivado 2020.2
2. Add design sources: `stopwatch_top.v`, `control_fsm.v`, `seconds_counter.v`, `minutes_counter.v`
3. Add simulation source: `tb_stopwatch.v`
4. Run behavioral simulation: **Flow → Run Simulation → Run Behavioral Simulation**

### Verilator Simulation

```bash
cd src/
make        # Build the Verilated model
make run    # Build and run simulation
make clean  # Clean build artifacts
```

---

## Design Choices

### 1. Dual Reset Architecture

Choice: Two separate resets - `rst_n` (global asynchronous) and `reset` (functional synchronous)

Rationale:
- `rst_n`: Hardware initialization at power-up (asynchronous, active-low)
- `reset`: User "clear stopwatch" button (synchronous)
- Separates low-level hardware initialization from user-facing functionality
- Follows real FPGA design practices

### 2. Combinational Lookahead Carry

Choice: Carry signal is combinational (wire), not registered (reg)

```verilog
output wire carry_out;
assign carry_out = (seconds == 6'd59) && enable;
```

Rationale:
- Ensures seconds and minutes counters update on the same clock edge
- Prevents skipping display values (00:59 → 01:00, not 00:59 → 00:00 → 01:01)
- Standard technique used in real hardware (adders, counters, CPUs)
- Critical for proper synchronous operation

### 3. Clock Frequency Independence

Choice: Hardware counts every clock cycle; testbench uses 20ns clock period

Rationale:
- Fast simulation: 1 clock cycle = 1 stopwatch second
- Tests 60 seconds in 1.2 microseconds instead of real-time
- Design portable across different clock frequencies
- Production deployment would add prescaler for actual 1Hz counting

### 4. Synchronous Counters

Choice: All counters use synchronous design with non-blocking assignments

Rationale:
- Better for synthesis and FPGA timing closure
- No propagation delay issues
- Easier to meet timing constraints
- Industry-standard practice


### 5. FSM State Encoding

Choice: Three states - IDLE (00), RUNNING (01), PAUSED (10)

Rationale:
- Clear separation of stopwatch modes
- Simple state transitions
- Status output directly reflects FSM state
- Easy to extend with additional states if needed

---

## Module Specifications

### stopwatch_top (Top-level)

| Port      | Direction | Width | Description                           |
|-----------|-----------|-------|---------------------------------------|
| clk       | input     | 1     | System clock                          |
| rst_n     | input     | 1     | Active-low asynchronous reset (global)|
| start     | input     | 1     | Start/resume command                  |
| stop      | input     | 1     | Stop/pause command                    |
| reset     | input     | 1     | Functional reset to 00:00 and IDLE    |
| minutes   | output    | 8     | Current minutes (0-99)                |
| seconds   | output    | 6     | Current seconds (0-59)                |
| status    | output    | 2     | 00=IDLE, 01=RUNNING, 10=PAUSED        |

### control_fsm

- Implements three-state FSM (IDLE/RUNNING/PAUSED)
- Generates `count_enable` signal for counters
- Handles all state transitions based on control inputs

### seconds_counter

- Synchronous up-counter (0-59)
- Generates combinational lookahead carry at 59
- Rolls over to 0 after 59

### minutes_counter

- Synchronous up-counter (0-99)
- Increments on carry from seconds counter
- Rolls over to 0 after 99

---

## Testing

**Test Coverage:**
- Global reset (rst_n) and functional reset (reset)
- Start, stop, resume operations
- Seconds counting (0-59) and rollover
- Minutes increment on seconds overflow
- Critical transition: 00:59 → 01:00 verified
- FSM state transitions
- Multiple start/stop cycles

**Results:** All tests passed in both Vivado and Verilator simulations.

---

## Key Implementation Details

**Clock Configuration:**
- Testbench: 20ns period (50MHz) for fast simulation
- Each clock cycle represents 1 stopwatch second
- Production: Add prescaler to generate actual 1Hz enable signal

**Reset Behavior:**
- `rst_n=0`: Initializes all registers to known state (asynchronous)
- `reset=1`: Clears time to 00:00, FSM returns to IDLE (synchronous)

**Carry Propagation:**
- Combinational carry ensures synchronous counter updates
- No intermediate invalid states during rollover transitions
