# Verilator Makefile for stopwatch simulation

# Verilog source files
VERILOG_SRC = ../rt1/stopwatch_top.v ../rt1/control_fsm.v ../rt1/seconds_counter.v ../rt1/minutes_counter.v

# Verilator flags
VERILATOR_FLAGS = -Wall --cc --exe --build --trace

# Target executable
TARGET = sim_stopwatch

# Default target
all: $(TARGET)

# Build the simulation
$(TARGET): main.cpp $(VERILOG_SRC)
	verilator $(VERILATOR_FLAGS) -o $(TARGET) main.cpp $(VERILOG_SRC)
	cp obj_dir/$(TARGET) .

# Clean
clean:
	rm -rf obj_dir $(TARGET) *.vcd

# Run the simulation
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run