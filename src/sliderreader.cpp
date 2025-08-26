#include "sliderreader.h"

SliderReader::SliderReader(std::string read_path) : read_path(std::move(read_path)), m_timer(std::make_unique<Timer>())
{
   // BOOST_LOG_TRIVIAL(info) << "SliderReader initialized" << std::endl ;
}

SliderReader::~SliderReader()
{
   // BOOST_LOG_TRIVIAL(info) << "SliderReader destructor called" << std::endl ;
}

/*!
 * \brief Starts cpu reading operation
 * \todo For now it takes cpu0 as freq reference taking avg or finding max is more secure ?
 * \return
 */
bool SliderReader::start_reader()
{
    //BOOST_LOG_TRIVIAL(info) << "SliderReader start_reader called" << std::endl ;
    stream.open(read_path, std::ios::in);
    auto fileSize = stream.seekg(0, std::ios::end).tellg();
    stream.seekg(0);

    std::string buffer ;
    std::string read_val ;
    while(std::getline(stream, buffer))
    {
        read_val += buffer ;
    }

    read_value = std::stoi(read_val);
   // BOOST_LOG_TRIVIAL(info) << "CPU freq : "<< read_value << std::endl ;

    return true ;
}


bool SliderReader::stop_reader()
{
    return true ;
}
