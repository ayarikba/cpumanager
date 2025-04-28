#include "Cpu.h"






void Cpu::print_cpu_info() {
    std::array<int, 4> cpui;
    std::array<char, 48> vendor;

#if defined(_MSC_VER)
    __cpuid(cpui.data(), 0);
#else
    __cpuid(0, cpui[0], cpui[1], cpui[2], cpui[3]);
#endif

    *reinterpret_cast<int*>(&vendor[0]) = cpui[1]; // EBX
    *reinterpret_cast<int*>(&vendor[4]) = cpui[3]; // EDX
    *reinterpret_cast<int*>(&vendor[8]) = cpui[2]; // ECX

    vendor[12] = '\0';

    std::cout << "CPU Vendor: " << vendor.data() << std::endl;


    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    while (std::getline(cpuinfo, line)) {
        std::cout << line << std::endl;
    }

}

