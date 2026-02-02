# Makefile for the Stopwatch Verilator Simulation

# Define the directories and all files
RTL_DIR = ../rtl
OBJ_DIR = obj_dir
TOP_MODULE = stopwatch_top

# List of all verilog files
VERILOG_FILES = $(RTL_DIR)/stopwatch_top.v \
                $(RTL_DIR)/control_fsm.v \
                $(RTL_DIR)/seconds_counter.v \
                $(RTL_DIR)/minutes_counter.v

# The C++ software file
CPP_WRAPPER = main.cpp

all: run

# Step 1: Verilate
verilate:
	# Run Verilator to generate the C++ model
	verilator -Wall --cc --exe $(VERILOG_FILES) $(CPP_WRAPPER) --top-module $(TOP_MODULE)

# Step 2: Build/Compile C++
build: verilate
	# Use the makefile that Verilator generated to compile the C++ code
	make -j -C $(OBJ_DIR) -f V$(TOP_MODULE).mk

# Step 3: Run the simulation YAYY
run: build
	@echo "--- Running Simulation ---"
	./$(OBJ_DIR)/V$(TOP_MODULE)

# Clean up generated files (type 'make clean' to run this)
clean:
	rm -rf $(OBJ_DIR)