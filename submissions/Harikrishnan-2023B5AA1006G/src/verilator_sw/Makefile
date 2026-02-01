# Makefile for Verilator-based stopwatch simulation

# Verilator configuration
VERILATOR = verilator
VERILATOR_FLAGS = -Wall -Wno-fatal --trace --cc

# Directories
RTL_DIR = ../rtl
BUILD_DIR = obj_dir

# Source files
RTL_SOURCES = $(RTL_DIR)/stopwatch_top.v \
              $(RTL_DIR)/control_fsm.v \
              $(RTL_DIR)/seconds_counter.v \
              $(RTL_DIR)/minutes_counter.v

CPP_SOURCES = main.cpp

# Top module
TOP_MODULE = stopwatch_top

# Executable name
EXECUTABLE = stopwatch_sim

# Make targets
.PHONY: all clean run

all: $(EXECUTABLE)

# Verilate the design
$(BUILD_DIR)/V$(TOP_MODULE).mk: $(RTL_SOURCES)
	$(VERILATOR) $(VERILATOR_FLAGS) --exe --build \
		-o ../$(EXECUTABLE) \
		$(RTL_SOURCES) $(CPP_SOURCES)

# Build the executable
$(EXECUTABLE): $(BUILD_DIR)/V$(TOP_MODULE).mk
	make -C $(BUILD_DIR) -f V$(TOP_MODULE).mk

# Run the simulation
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE) *.vcd


