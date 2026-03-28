sim:
	verilator --cc ../rtl/*.v --exe ../verilator_sw/main.cpp -top-module stopwatch_top
	make -C obj_dir -f Vstopwatch_top.mk
run:
	./obj_dir/Vstopwatch_top
clean:
	rm -rf obj_dir