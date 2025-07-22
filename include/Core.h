#pragma once
#include <cstdint>
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

namespace cpu 
{
class Core
{
    public:
    Core(const std::string& corePath);
    ~Core();

    void setIndex(uint32_t idx);
    uint32_t getIndex() const;

    void setTemperature(uint32_t temp);
    uint32_t getTemperature() const;

    void setMaxFreq(uint64_t freq);
    uint64_t getMaxFreq() const;

    void setMinFreq(uint64_t freq);
    uint64_t getMinFreq() const;

    void change_frequency(int frequency);

    protected:
    

    private:
    std::string path ;
    std::string core_max_freq_path ;
    std::string core_min_freq_path ;
    std::string core_governor_path ;
    uint32_t index ;
    uint32_t temperature ;
    uint64_t max_freq ; 
    uint64_t min_freq ;
    
};

}