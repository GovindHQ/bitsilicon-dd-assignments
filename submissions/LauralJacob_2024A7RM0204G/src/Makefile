TOP=stopwatch_top

all:
	verilator -Wall --cc *.v --top-module $(TOP) --exe main.cpp
	make -C obj_dir -f V$(TOP).mk
	./obj_dir/V$(TOP)

clean:
	rm -rf obj_dir
