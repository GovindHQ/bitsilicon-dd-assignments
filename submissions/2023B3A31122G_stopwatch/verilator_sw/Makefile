# Makefile for Verilator Stopwatch

# Tool definitions
VERILATOR = verilator
CXX = g++

# Project Directories
RTL_DIR = ../rtl
OBJ_DIR = obj_dir

# Source Files
VERILOG_SRC = $(RTL_DIR)/stopwatch_top.v
CPP_SRC = main.cpp
TOP_MODULE = stopwatch_top

# Flags
VERILATOR_FLAGS = -Wall --cc --exe --build -I$(RTL_DIR) \
                  --top-module $(TOP_MODULE) \
                  -Wno-style -Wno-fatal

# Targets
.PHONY: all clean run

all: run

# 1. Verilate and Build
# This step converts Verilog -> C++ AND compiles the C++ -> Executable
$(OBJ_DIR)/V$(TOP_MODULE): $(VERILOG_SRC) $(CPP_SRC)
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILOG_SRC) $(CPP_SRC)

# 2. Run the simulation
run: $(OBJ_DIR)/V$(TOP_MODULE)
	@echo "--- Running Simulation ---"
	./$(OBJ_DIR)/V$(TOP_MODULE)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR)