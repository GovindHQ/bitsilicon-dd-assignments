TOP = stopwatch_top
RTL = rtl/stopwatch_top.v \
	rtl/control_fsm.v \
	rtl/seconds_counter.v \
	rtl/minutes_counter.v

SIM = sim/main.cpp
OBJDIR = obj_dir
all:
	verilator -Wall --cc $(RTL) --exe $(SIM)
	make -C $(OBJDIR) -f V$(TOP).mk

run:
	./$(OBJDIR)/V$(TOP)

clean:
	rm -rf $(OBJDIR) *.vcd

