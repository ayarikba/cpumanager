#pragma once
 
#include <iostream>
#include <array>
#include <fstream>

#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <cpuid.h>
#endif


class Cpu
{
    public:
    Cpu();
    ~Cpu();
    
    void print_cpu_info();

    protected:




    private:
    std::string model_name ;
    short core_count ;


};