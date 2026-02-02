
TOP       = stopwatch_top
VSRCS     = ../rtl/stopwatch_top.v \
            ../rtl/control_fsm.v \
            ../rtl/seconds_counter.v \
            ../rtl/minutes_counter.v

all: sim

sim:
	verilator -Wall --cc $(VSRCS) --top-module $(TOP) --exe main.cpp
	make -C obj_dir -f V$(TOP).mk V$(TOP)

run: sim
	./obj_dir/V$(TOP)

clean:
	rm -rf obj_dir logs *.vcd
