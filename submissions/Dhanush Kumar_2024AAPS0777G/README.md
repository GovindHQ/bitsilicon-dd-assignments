PROJECT : DESIGNING A Digital Stopwatch Controller
NAME: DHANUSH KUMAR
BITS ID : 2024AAPS0777G
   
TOOLS AND VERSION:
Simulator (RTL): Icarus Verilog iverilog (version 11.0)
 Verilator 5.020 
BUILD :
Verilog Testbench Simulation (Icarus Verilog)
iverilog -g2012 \
rtl/stopwatch_top.v \
rtl/control_fsm.v \
rtl/seconds_counter.v \
rtl/minutes_counter.v \
tb/tb_stopwatch.v \
-o tb_stopwatch

TO RUN: vvp tb_stopwatch

Verilator + C++ Simulation:

Clean previous build:
rm -rf obj_dir
FOR A NEW BUILD:
verilator -Wall --cc \
rtl/stopwatch_top.v \
rtl/control_fsm.v \
rtl/seconds_counter.v \
rtl/minutes_counter.v \
--exe verilator_sw/main.cpp \
--build
TO RUN:
./obj_dir/Vstopwatch_top
    
DESIGN CHOICES:

control_fsm.v – controls stopwatch operation

seconds_counter.v – counts seconds (0–59)

minutes_counter.v – counts minutes (0–99)

stopwatch_top.v – integrates all submodules
Synchronous Design Considerations:
This design follows standard synchronous digital design principles:

All state changes occur on the rising edge of the clock
As a result, during simulation, displayed values may appear one clock cycle later than intuitive “human timing”.

This behavior is expected and correct for clocked hardware systems.
