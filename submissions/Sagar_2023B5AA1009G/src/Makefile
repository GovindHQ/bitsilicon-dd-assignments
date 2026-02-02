# Makefile for Fedora Environment
VERILATOR = verilator
VERILATOR_FLAGS = -Wall -Wno-EOFNEWLINE --cc --exe --build --trace

# Directories
RTL_DIR = ../rtl
OBJ_DIR = obj_dir

# Project Source Files (Matches your 199-minute logic)
V_SOURCES = $(RTL_DIR)/stopwatch_top.v \
            $(RTL_DIR)/seconds_counter.v \
            $(RTL_DIR)/minutes_counter.v \
            $(RTL_DIR)/control_fsm.v

CPP_SOURCE = main.cpp
TOP_MODULE = stopwatch_top

# Targets
all: build run

build:
	$(VERILATOR) $(VERILATOR_FLAGS) $(V_SOURCES) $(CPP_SOURCE) --top-module $(TOP_MODULE)

run:
	./$(OBJ_DIR)/V$(TOP_MODULE)

clean:
	rm -rf $(OBJ_DIR) *.vcd