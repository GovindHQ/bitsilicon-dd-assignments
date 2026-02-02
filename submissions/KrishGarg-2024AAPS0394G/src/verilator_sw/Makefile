TOP_MOD = stopwatch_top
TB_CPP = stopwatch_sim.cpp
VERILOG_SRCS = stopwatch_top.v
EXE = obj_dir/V$(TOP_MOD)
#Commands
build:
	verilator -Wall -cc -I../rtl ../rtl/$(VERILOG_SRCS) --exe $(TB_CPP)
	make -C obj_dir -f V$(TOP_MOD).mk

run: build
	./$(EXE)

clean:
	rm -rf obj_dir