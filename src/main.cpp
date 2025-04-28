#include <iostream>
#include "Cpu.h"


int main()
{
    std::cout << "hello world" << std::endl ;
    auto cpu = new Cpu();
    cpu->print_cpu_info();
    
}