# project build configuration
TOP = stopwatch_top
TB = main.cpp
RTL_DIR = rtl
OBJ_DIR = obj_dir

.PHONY: all compile run

all: compile run

compile:
	verilator -I$(RTL_DIR) --cc $(RTL_DIR)/$(TOP).v --exe $(TB) --trace
	make -C $(OBJ_DIR) -f V$(TOP).mk V$(TOP)

run:
	./$(OBJ_DIR)/V$(TOP)

clean:
	rm -rf $(OBJ_DIR) waveform.vcd