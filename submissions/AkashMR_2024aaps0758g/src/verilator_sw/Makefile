MODULE=stopwatch_top

build: ./*.cpp ../rtl/*.v
	verilator -Wall --cc --exe --build -I../rtl ../rtl/$(MODULE).v main.cpp

run: build
	./obj_dir/V$(MODULE)

clean:
	rm -rf obj_dir
