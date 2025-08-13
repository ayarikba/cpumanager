#include <IReader.h>


void IReader::print_all_values()
{
    std::cout << "Read path : " << read_path  << std::endl;
    std::cout << "Desired Value" << desired_value << std::endl ;
    std::cout << "Read Value :" << read_value << std::endl ;
}
