# Define the top module name
MODULE = stopwatch_top

# Define paths
RTL_DIR = ../rtl
BUILD_DIR = obj_dir

# Default target
all:
	@echo "Building with Verilator..."
	# 1. Run Verilator to convert Verilog to C++
	# -cc: Create C++ output
	# --exe: Create executable
	# --build: Automatically compile the C++ files
	# -I: path to include verilog files
	verilator -Wall --cc --exe --build -j 4 \
		-I$(RTL_DIR) \
		$(RTL_DIR)/$(MODULE).v \
		main.cpp \
		--top-module $(MODULE)

	@echo "Build Complete. Run ./obj_dir/Vstopwatch_top to see results."

clean:
	rm -rf $(BUILD_DIR)