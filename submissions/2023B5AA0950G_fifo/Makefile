
TB_FILE = tb/sync_fifo_tb.v
DUT_FILE = rtl/sync_fifo.v rtl/sync_fifo_top.v
TOP_MODULE = sync_fifo_tb
EXECUTABLE = ./obj_dir/V$(TOP_MODULE)

all: simulate

compile: $(TB_FILE) $(DUT_FILE) 
	verilator --binary --timing --Wno-fatal $(TB_FILE) $(DUT_FILE)

simulate: compile
	$(EXECUTABLE)

clean:
	rm -rf obj_dir
