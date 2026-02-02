
# Verilator tool
VERILATOR = verilator

# Top-level module name
TOP = stopwatch_top

# Directories
RTL_DIR = ../rtl
OBJ_DIR = obj_dir

# Verilog source files
VERILOG_SRCS = \
	$(RTL_DIR)/stopwatch_top.v \
	$(RTL_DIR)/seconds_counter.v \
	$(RTL_DIR)/minutes_counter.v \
	$(RTL_DIR)/control_fsm.v

# C++ source file
CPP_SRC = main.cpp

# Verilator flags
VERILATOR_FLAGS = -Wall --cc --exe

# Default target
all: build

# -------------------------------
# Build Verilated model + binary
# -------------------------------
build:
	$(VERILATOR) $(VERILATOR_FLAGS) \
		$(VERILOG_SRCS) \
		$(CPP_SRC)
	make -C $(OBJ_DIR) -f V$(TOP).mk

# -------------------------------
# Run simulation
# -------------------------------
run: build
	./$(OBJ_DIR)/V$(TOP)

# -------------------------------
# Clean build artifacts
# -------------------------------
clean:
	rm -rf $(OBJ_DIR)

# -------------------------------
# Help
# -------------------------------
help:
	@echo "Available targets:"
	@echo "  make        - Build the Verilated stopwatch"
	@echo "  make run    - Build and run simulation"
	@echo "  make clean  - Remove generated files"
