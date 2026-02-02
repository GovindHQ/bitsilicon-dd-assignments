# Makefile for Verilator Stopwatch Project

# Tools
VERILATOR = verilator
CXX = g++

# Directories
RTL_DIR = ../rtl
SW_DIR = .
OBJ_DIR = obj_dir

# Files
VERILOG_SRCS = $(RTL_DIR)/stopwatch_top.v \
               $(RTL_DIR)/control_fsm.v \
               $(RTL_DIR)/seconds_counter.v \
               $(RTL_DIR)/minutes_counter.v
CPP_SRC = $(SW_DIR)/main.cpp
TOP_MODULE = stopwatch_top

# Flags
VERILATOR_FLAGS = -Wall --cc --exe
VERILATOR_FLAGS += -I$(RTL_DIR)
# Optional: Suppress harmless warnings if needed
# VERILATOR_FLAGS += -Wno-style

# Targets
.PHONY: all clean run

all: $(OBJ_DIR)/V$(TOP_MODULE)

$(OBJ_DIR)/V$(TOP_MODULE): $(VERILOG_SRCS) $(CPP_SRC)
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILOG_SRCS) $(CPP_SRC)
	make -C $(OBJ_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)

run: all
	./$(OBJ_DIR)/V$(TOP_MODULE)

clean:
	rm -rf $(OBJ_DIR)