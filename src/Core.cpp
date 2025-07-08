#include "Core.h"



namespace cpu 
{
    Core::Core(const std::string& corePath)
        : path(corePath)
    {
        std::cout << corePath.size() << std::endl;
        std::cout << corePath.substr(corePath.find_last_of("cpu") + 1) << std::endl ; 
        index  = corePath.empty() ? 0 : std::stoi(corePath.substr(corePath.find_last_of("cpu")+ 1));
    }

    void Core::setIndex(uint32_t idx) {
        index = idx;
    }
    uint32_t Core::getIndex() const {
        return index;
    }



    Core::~Core()
    {

    }
}