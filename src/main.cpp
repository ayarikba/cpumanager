#include <iostream>
#include "Cpu.h"


int main()
{
    std::cout << "hello world" << std::endl ;
    auto cpu = new cpu::Cpu();
    //cpu->print_cpu_info();
    //std::cout << core << std::endl;
    //std::cout << cpu->getCoreCount() << std::endl ; 
    cpu->change_frequency(4000000);
}