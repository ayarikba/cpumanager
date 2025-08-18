#include "sliderreader.h"

SliderReader::SliderReader()
{
    BOOST_LOG_TRIVIAL(info) << "SliderReader initialized" << std::endl ;
}

SliderReader::~SliderReader()
{
    BOOST_LOG_TRIVIAL(info) << "SliderReader destructor called" << std::endl ;
}

/*!
 * \brief Starts cpu reading operation
 * \todo For now it takes cpu0 as freq reference taking avg or finding max is more secure ?
 * \return
 */
bool SliderReader::start_reader()
{
}

