TOP=stopwatch_top

all:
	verilator -Wall --cc ../rtl/*.v --top-module $(TOP) --exe main.cpp --build
	./obj_dir/V$(TOP)

clean:
	rm -rf obj_dir
