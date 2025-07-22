#include "Core.h"
#include <iostream>
#include <fstream>



namespace cpu 
{
    Core::Core(const std::string& corePath)
        : path(corePath)
    {
        index  = corePath.empty() ? 0 : std::stoi(corePath.substr(corePath.find_last_of("cpu")+ 1));
        core_max_freq_path = path + "/cpufreq/scaling_max_freq";
        core_min_freq_path = path + "/cpufreq/scaling_min_freq";
        core_governor_path = path + "/cpufreq/scaling_governor";
    }

    void Core::setIndex(uint32_t idx) {
        index = idx;
    }
    uint32_t Core::getIndex() const {
        return index;
    }

    void Core::change_frequency(int frequency)
    {
        std::cout << core_max_freq_path << std::endl;
        std::ofstream wr(core_max_freq_path, std::ios::trunc);
        if (wr.is_open()) {
            wr << frequency;
            wr.close();
        } else {
            std::cerr << "Failed to open file: " << core_max_freq_path << std::endl;
        }
        // std::ofstream stream()
    }


    Core::~Core()
    {

    }
}