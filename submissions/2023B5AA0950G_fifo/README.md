# Synchronous FIFO (sync_fifo)

This repository contains a simple synchronous FIFO implementation and a verification environment that uses a scoreboard to verify correct behavior across a set of edge cases.

## Project Layout 

- `rtl/`: RTL sources
  - `sync_fifo.v` - core FIFO implementation
  - `sync_fifo_top.v` - top-level wrapper connecting FIFO to testbench harness
- `tb/`: testbench sources
  - `sync_fifo_tb.v` - testbench with stimulus and scoreboard
- `build/`: simulation outputs (binaries, waveforms)

## Design Summary
- **Type:** Synchronous FIFO (single-clock domain)
- **Features:** Parameterizable depth/width (see RTL), full/empty status, write/read enable, synchronous reset.

## Verification
- **Testbench:** `tb/sync_fifo_tb.v` drives stimulus to the top-level wrapper and collects results.
- **Scoreboard:** A scoreboard compares expected data flow (model) to the FIFO outputs to detect mismatches.

## Edge Cases Verified
- **Underflow (read when empty):**
- **Overflow (write when full):** 
- **Simultaneous write/read:** 
- **Reset during activity:** 
- **Pointer wrap-around:** 

## Run Simulation (Verilator + Makefile)
The project was simulated using Verilator. 

Simple run (from repository root):

```bash
make