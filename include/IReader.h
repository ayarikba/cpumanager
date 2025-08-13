#ifndef IREADER_H
#define IREADER_H


#include <iostream>

class IReader
{
public:
    virtual bool start_reader() = 0 ;
    virtual bool stop_reader() = 0 ;
    void print_all_values() ;

public:
    time_t get_interval()  {return interval ;}
    void set_interval(time_t interval) {this->interval = interval ; }
private:
    std::string read_path ;
    int desired_value ;
    int read_value ;
    time_t interval ;
};

#endif // IREADER_H
