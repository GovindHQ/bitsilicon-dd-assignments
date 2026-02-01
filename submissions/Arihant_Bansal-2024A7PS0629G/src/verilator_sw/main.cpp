#include "Vstopwatch_top.h"
#include "verilated.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iomanip>

//logic for single clk cycle

void tick(Vstopwatch_top &stpwatch){
    (stpwatch).clk=1;
    (stpwatch).eval();
    (stpwatch).clk=0;
    (stpwatch).eval();
}
void reset_termio(struct termios &oldt){
    tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vstopwatch_top *stopwatch= new Vstopwatch_top;
    char x;
    char ch;
    bool sim=false;
    
    struct termios newt,oldt;
    tcgetattr(STDIN_FILENO,&oldt);
    newt=oldt;

    while(true){
        if(!sim){
            std::cout << "--- STOPWATCH INTERFACE ---" << std::endl;
            std::cout << "[1] Start  [2] Stop  [3] Reset  [q] Quit" << std::endl;
            std::cin >> x;
        }

        if(x=='1'){
            sim=true;
            bool start=true;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO,TCSANOW,&newt);
            int flags = fcntl(STDIN_FILENO,F_GETFL,0);
            fcntl(STDIN_FILENO,F_SETFL,flags|O_NONBLOCK);

            (*stopwatch).rst_n = 0;
            tick(*stopwatch);
            (*stopwatch).rst_n = 1;
            tick(*stopwatch);

            (*stopwatch).start = 1; 
            tick(*stopwatch);
            std::cout << "\r\033[KTime: " << std::setfill('0') << std::setw(2)<< (int)(*stopwatch).minutes << ":" << std::setfill('0') << std::setw(2)<< (int)(*stopwatch).seconds << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            (*stopwatch).start = 0;

            while(start){
                if (read(STDIN_FILENO, &ch, 1) > 0){
                    if(ch=='1'){
                        (*stopwatch).start = 1; 
                        tick(*stopwatch);
                        (*stopwatch).start = 0;
                        std::cout << "\r\033[KTime: " << std::setfill('0') << std::setw(2)<< (int)(*stopwatch).minutes << ":" << std::setfill('0') << std::setw(2)<< (int)(*stopwatch).seconds << std::flush;
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    }
                    else if(ch=='2'){
                        (*stopwatch).stop=1;
                        tick(*stopwatch);
                        (*stopwatch).stop=0;
                    }
                    else if(ch=='3'){
                        (*stopwatch).rst=1;
                        tick(*stopwatch);
                        (*stopwatch).rst=0;
                    }
                    else if(ch=='q'){
                        (*stopwatch).rst_n = 0;
                        tick(*stopwatch);
                        (*stopwatch).rst_n = 1;
                        tick(*stopwatch);
                        std::cout<<std::endl;
                        std::cout<<"exiting...."<< std::endl;
                        break;
                    }
                }
                else{
                    tick(*stopwatch);
                    std::cout << "\r\033[KTime: " << std::setfill('0') << std::setw(2)<< (int)(*stopwatch).minutes << ":" << std::setfill('0') << std::setw(2)<< (int)(*stopwatch).seconds << std::flush;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                }
            }
            reset_termio(oldt);
            break;
        }
        else if(x=='2'){
            std::cout<<"Please first start the stopwatch"<< std::endl;
        }
        else if(x=='3'){
            std::cout<<"Please first start the stopwatch"<< std::endl;
        }
        else if(x=='q'){
            std::cout<<"exiting...."<< std::endl;
            return 0; 
        }
        else{
            std::cout<<"Please select a valid input"<< std::endl;
        }
    }
}
