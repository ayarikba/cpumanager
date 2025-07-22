#include "Cpu.h"

namespace cpu 
{

Cpu::Cpu()
{
    createCores();
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

void Cpu::printCores()
{
    for (const auto& core : cores) {
        std::cout << "Core Index: " << core->getIndex() << std::endl;
        // std::cout << "Temperature: " << core->getTemperature() << " C" << std::endl;
        // std::cout << "Max Frequency: " << core->getMaxFreq() << " Hz" << std::endl;
        // std::cout << "Min Frequency: " << core->getMinFreq() << " Hz" << std::endl;
    }
}

int Cpu::createCores()
{
    int core_index = 0;
    while (true) {
        std::string core_path = "/sys/devices/system/cpu/cpu" + std::to_string(core_index);
        if (std::filesystem::exists(core_path)) {
            cores.push_back(std::make_unique<Core>(core_path)); 
            core_index++;
        } else {
            break;
        }
    }

    std::cout << "Number of cores created: " << cores.size() << std::endl; 
    return cores.size(); 

}

void Cpu::change_frequency(int freq)
{
    for (const auto& core : cores)
        core->change_frequency(freq);
}


}