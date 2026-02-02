all:
	verilator -Wall --cc ../rtl/stopwatch_top.v ../rtl/control_fsm.v ../rtl/seconds_counter.v ../rtl/minutes_counter.v --exe main.cpp
	make -C obj_dir -f Vstopwatch_top.mk Vstopwatch_top
	./obj_dir/Vstopwatch_top

clean:
	rm -rf obj_dir