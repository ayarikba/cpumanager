#pragma once
 
#include <iostream>
#include <array>
#include <fstream>
#include <thread>
#include <memory>
#include <vector>
#include <set>
#include <filesystem>
#include "Core.h"

#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <cpuid.h>
#endif


namespace cpu 
{
constexpr const char* INFO_PATH = "/proc/cpuinfo";
class Cpu
{
    public:
    Cpu();
    ~Cpu();
    
    void print_cpu_info();
    int getPhysicalCoreCount();
    int getCoreCount();
    void printCores();

    protected:



    private:
    int createCores(); 

    private:
    std::string vendor;
    int core_count;
    int physical_core_count;
    static constexpr size_t ARRAY_SIZE = 10; // Define a valid size
    std::vector<std::unique_ptr<Core>> cores;

    private:
    

};

}