#include "Cpu.h"
#include <set>

Cpu::Cpu()
{
    
}


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

    this->vendor = std::string(vendor.data());

}

int Cpu::getPhysicalCoreCount() {
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    std::set<std::string> unique_cores;

    std::string physical_id, core_id;

    while (std::getline(cpuinfo, line)) {
        if (line.find("physical id") != std::string::npos)
            physical_id = line.substr(line.find(":") + 2);
        else if (line.find("core id") != std::string::npos) {
            core_id = line.substr(line.find(":") + 2);
            unique_cores.insert(physical_id + "-" + core_id);
        }
    }
    std::cout << unique_cores.size() << std::endl ; 

    this->physical_core_count = unique_cores.size() ; 
    return unique_cores.size();
}


int Cpu::getCoreCount()
{
    unsigned int core = std::thread::hardware_concurrency();
    this->core_count = core ;

    return core ; 
}


int Cpu::createCores()
{
    int core_index = 0;
    while (true) {
        std::string core_path = "/sys/devices/system/cpu/cpu" + std::to_string(core_index);
        if (std::filesystem::exists(core_path)) {
            Core core_instance(core_index); 
            cores.push_back(core_instance); 
            core_index++;
        } else {
            break;
        }
    }
    return cores.size(); 
}