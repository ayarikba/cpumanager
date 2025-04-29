#pragma once
#include <cstdint>

class Core
{
    public:
    Core();
    ~Core();



    protected:
    

    private:
    uint32_t index ;
    uint32_t temperature ;
    uint64_t max_freq ; 
    uint64_t min_freq ;
    
}