#include "Vstopwatch_top.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);
	Vstopwatch_top* top = new Vstopwatch_top;

	top->clk =0;
	top->rst_n=0;
	top->start=0;
	top->stop=0;
	top->reset=0;



	auto tick = [&]() {
		top->clk=0; top->eval();
		top->clk=1; top->eval();
};

for(int i=0; i<5; i++) tick();
top->rst_n = 1;

top->start=1;
tick();
top->start = 0;

for(int i=0;i<200;i++){
	tick();
	if(i%20==0){
		std::cout << "TIME = "
			  << (int)top->minutes
			  << ":"
			  << (int)top->seconds
			  << std::endl;

		}
	}
	
	delete top;
	return 0;
}
