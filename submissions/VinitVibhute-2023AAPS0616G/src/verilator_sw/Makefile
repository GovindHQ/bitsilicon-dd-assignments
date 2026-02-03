# Makefile for Digital Stopwatch Verilator Simulation

# Verilator configuration
VERILATOR = verilator
VERILATOR_FLAGS = -Wall --cc --exe --build --trace

# Directories
RTL_DIR = ../rtl
SRC_DIR = .
BUILD_DIR = obj_dir

# Source files
RTL_SOURCES = $(RTL_DIR)/stopwatch_top.v \
              $(RTL_DIR)/control_fsm.v \
              $(RTL_DIR)/seconds_counter.v \
              $(RTL_DIR)/minutes_counter.v

CPP_SOURCES = $(SRC_DIR)/main.cpp

# Top module name
TOP_MODULE = stopwatch_top

# Output executable
EXECUTABLE = $(BUILD_DIR)/V$(TOP_MODULE)

# Default target
all: $(EXECUTABLE)

# Build the Verilated model and executable
$(EXECUTABLE): $(RTL_SOURCES) $(CPP_SOURCES)
	@echo "Building Verilator model..."
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TOP_MODULE) \
		$(RTL_SOURCES) \
		$(CPP_SOURCES)
	@echo "Build complete!"

# Run the simulation
run: $(EXECUTABLE)
	@echo "Running simulation..."
	@$(EXECUTABLE)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILD_DIR)
	rm -f *.vcd
	@echo "Clean complete!"

# Help target
help:
	@echo "Digital Stopwatch Verilator Makefile"
	@echo "===================================="
	@echo "Targets:"
	@echo "  all     - Build the Verilator model (default)"
	@echo "  run     - Build and run the simulation"
	@echo "  clean   - Remove build artifacts"
	@echo "  help    - Show this help message"
	@echo ""
	@echo "Usage:"
	@echo "  make        # Build the model"
	@echo "  make run    # Build and run simulation"
	@echo "  make clean  # Clean build files"

.PHONY: all run clean help