# Synchronous FIFO – Assignment 2

## Overview

This submission implements a parameterised synchronous FIFO in Verilog, together with a
self-checking testbench containing a golden reference model, a scoreboard, 25 directed and
stress tests, random stimulus, and 11 manual coverage counters.

---

## File Structure

```
<studentid>_fifo_verify/
├── rtl/
│   ├── sync_fifo_top.v   # Top-level module ($clog2 parameter + DUT wrapper)
│   └── sync_fifo.v       # Core FIFO implementation
├── tb/
│   └── tb_sync_fifo.v    # Self-checking testbench (25 tests)
└── docs/
    └── README.md         # This file
```

---

## RTL Design

### `sync_fifo_top.v`
- Exposes the public interface specified in the assignment.
- Uses `$clog2(DEPTH)` as a parameter default to derive `ADDR_WIDTH` at elaboration time — legal in Verilog-2001 and avoids the port-list function call issue.
- Instantiates `sync_fifo` with the computed `ADDR_WIDTH`.
- `rd_data` is an `output wire` driven by a clean `assign` statement — no unnecessary `reg` or `always` block.

### `sync_fifo.v`
- **Memory array** — `reg [DATA_WIDTH-1:0] mem [0:DEPTH-1]`
- **Write pointer** — `wr_ptr`, wraps at `DEPTH-1 → 0`
- **Read pointer** — `rd_ptr`, wraps at `DEPTH-1 → 0`
- **Occupancy counter** — `count_r`, `[ADDR_WIDTH:0]` wide
- All logic is **synchronous** (rising clock edge only) and **synthesisable**.
- **Active-low synchronous reset** (`rst_n`) zeroes all state.
- Flags are combinationally derived:
  - `rd_empty = (count_r == 0)`
  - `wr_full  = (count_r == DEPTH)`
- Simultaneous valid read + write leaves count unchanged and advances both pointers.

---

## Testbench Architecture (`tb_sync_fifo.v`)

### Golden Reference Model
An independent cycle-accurate behavioural implementation using:

| Variable        | Purpose                          |
|-----------------|----------------------------------|
| `model_mem`     | Behavioural storage array        |
| `model_wr_ptr`  | Next write location              |
| `model_rd_ptr`  | Next read location               |
| `model_count`   | Number of stored elements        |
| `model_rd_data` | Expected read output             |

The model snapshots `model_count` into a local `snap_count` before any updates, so both
the write and read validity checks use the pre-cycle state — exactly matching hardware
behaviour. The model never reads DUT outputs.

### Scoreboard
After every rising edge (once reset is de-asserted) the scoreboard compares:

| Signal     | Expected               |
|------------|------------------------|
| `rd_data`  | `model_rd_data`        |
| `count`    | `model_count`          |
| `rd_empty` | `(model_count == 0)`   |
| `wr_full`  | `(model_count == DEPTH)` |

On mismatch the scoreboard prints time, cycle, test name, seed, expected/actual values,
input signals, and model pointer state, then calls `$finish`.

---

## Test Suite (25 Tests)

### Spec-Required Directed Tests

| ID  | Name                  | What it verifies                                              |
|-----|-----------------------|---------------------------------------------------------------|
| T01 | Reset                 | Pointers, count, flags after reset de-assertion               |
| T02 | Single Write/Read     | Basic data integrity, count ±1, flag transitions              |
| T03 | Fill                  | `wr_full` assertion at `count == DEPTH`                       |
| T04 | Drain                 | `rd_empty` assertion at `count == 0`, FIFO ordering           |
| T05 | Overflow Attempt      | State unchanged when writing to a full FIFO                   |
| T06 | Underflow Attempt     | State unchanged when reading from an empty FIFO               |
| T07 | Simultaneous R/W      | Both pointers advance, count unchanged                        |
| T08 | Pointer Wrap-Around   | Data integrity across the `DEPTH-1 → 0` boundary             |

### Extra Stress Tests

| ID  | Name                  | What it verifies                                              |
|-----|-----------------------|---------------------------------------------------------------|
| T09 | Mid-Operation Resets  | 3 scenarios: partial fill, full, partial fill+drain           |
| T10 | Burst Write/Read      | Back-to-back full burst write then full burst read            |
| T11 | Alternating W/R       | 64-cycle steady-state single write / single read              |
| T12 | Simul R/W at Full     | Simultaneous R+W exactly at full boundary                     |
| T13 | Near-Empty Boundary   | Hammer reads at count=1, verify only one succeeds             |
| T14 | Near-Full Boundary    | Hammer writes at count=DEPTH-1, verify only one succeeds      |
| T15 | All-Zeros Pattern     | Data path with 0x00 through full fill+drain                   |
| T16 | All-Ones Pattern      | Data path with 0xFF through full fill+drain                   |
| T17 | Walking Ones          | Each bit position set individually                            |
| T18 | Walking Zeros         | Each bit position cleared individually                        |
| T19 | Checkerboard 0xAA/55  | Alternating bit pattern through full fill+drain               |
| T20 | Double Wrap-Around    | 3× fill+drain forces pointers to wrap twice                   |
| T21 | Reset After Partial   | Reset mid-fill, verify no stale data survives restart         |
| T22 | Long Random Stress    | 5 seeds × 500 random cycles = 2500 cycles total               |
| T23 | Rapid Cycles          | 10 back-to-back fill+drain cycles                             |
| T24 | Write-Heavy Random    | 75% write probability, 500 cycles                             |
| T25 | Read-Heavy Random     | 75% read probability, 500 cycles                             |

---

## Manual Coverage Counters (11 bins)

| Counter          | Meaning                                          |
|------------------|--------------------------------------------------|
| `cov_full`       | Clock cycles in which FIFO was full              |
| `cov_empty`      | Clock cycles in which FIFO was empty             |
| `cov_wrap`       | Write or read pointer wrap-around events         |
| `cov_simul`      | Valid simultaneous read + write cycles           |
| `cov_overflow`   | Write attempts on a full FIFO                    |
| `cov_underflow`  | Read attempts on an empty FIFO                   |
| `cov_near_full`  | Cycles where count == DEPTH-1                    |
| `cov_near_empty` | Cycles where count == 1                          |
| `cov_reset_mid`  | Resets applied while FIFO was non-empty          |
| `cov_burst_wr`   | Consecutive write-only cycles (burst write)      |
| `cov_burst_rd`   | Consecutive read-only cycles (burst read)        |

All 11 counters are printed at end of simulation. A warning is issued if any is zero.

---

## How to Simulate

### Icarus Verilog
```bash
iverilog -o fifo_sim rtl/sync_fifo_top.v rtl/sync_fifo.v tb/tb_sync_fifo.v
vvp fifo_sim
```

### Waveform Dump (GTKWave)
Add to the top of the `initial` block in `tb_sync_fifo.v`:
```verilog
$dumpfile("fifo.vcd");
$dumpvars(0, tb_sync_fifo);
```
Then: `gtkwave fifo.vcd`

### ModelSim / Questa
```tcl
vlog rtl/sync_fifo_top.v rtl/sync_fifo.v tb/tb_sync_fifo.v
vsim -c tb_sync_fifo -do "run -all; quit"
```

### VCS
```bash
vcs rtl/sync_fifo_top.v rtl/sync_fifo.v tb/tb_sync_fifo.v -o simv && ./simv
```

---

## Parameters

| Parameter    | Default | Description                        |
|--------------|---------|------------------------------------|
| `DATA_WIDTH` | 8       | Width of each data word (bits)     |
| `DEPTH`      | 16      | Number of entries in the FIFO      |

---

## Expected Console Output (passing run)

```
==============================================
  SYNC FIFO GRUELLING TESTBENCH  (25 tests)
==============================================
[...] T01_RESET                          ... PASS
[...] T02_SINGLE_WR_RD                   ... PASS
...
[...] T25_READ_HEAVY                     ... PASS

==============================================
  COVERAGE SUMMARY
==============================================
  cov_full       = ...
  cov_empty      = ...
  cov_wrap       = ...
  cov_simul      = ...
  cov_overflow   = ...
  cov_underflow  = ...
  cov_near_full  = ...
  cov_near_empty = ...
  cov_reset_mid  = ...
  cov_burst_wr   = ...
  cov_burst_rd   = ...
==============================================
All 11 coverage bins non-zero. Coverage adequate.
==============================================
  ALL 25 TESTS PASSED  |  Total cycles = ...
==============================================
```
