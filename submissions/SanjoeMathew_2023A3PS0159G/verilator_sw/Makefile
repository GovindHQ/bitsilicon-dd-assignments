TOP = stopwatch_top

RTL = ../rtl/stopwatch_top.v \
      ../rtl/seconds_counter.v \
      ../rtl/minutes_counter.v \
      ../rtl/control_fsm.v \
      ../rtl/minutes_counter.v

all:
	verilator -Wall --cc $(RTL) --exe main.cpp
	make -C obj_dir -f V$(TOP).mk

run:
	./obj_dir/V$(TOP)

clean:
	rm -rf obj_dir
