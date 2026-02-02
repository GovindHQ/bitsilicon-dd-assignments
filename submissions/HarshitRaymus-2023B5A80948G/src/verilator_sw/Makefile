TOP=stopwatch_top

all:
	verilator -Wall --cc ../rtl/$(TOP).v ../rtl/control_fsm.v ../rtl/seconds_counter.v ../rtl/minutes_counter.v --exe main.cpp
	make -C obj_dir -f V$(TOP).mk

run:
	./obj_dir/V$(TOP)

clean:
	rm -rf obj_dir
