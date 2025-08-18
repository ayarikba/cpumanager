#ifndef SLIDERREADER_H
#define SLIDERREADER_H

#include <QObject>
#include <QWidget>
#include <IReader.h>
#include <boost/log/trivial.hpp>
#include <fstream>39

/*!
 * \brief The SliderReader class that used as middleware between actual cpu valu and desired val
 */
class SliderReader : public IReader
{
public:
    SliderReader();
    bool start_reader() override;
    bool stop_reader()  override;
    void print_all_values();
    time_t get_interval();
    void set_interval();


private:
    std::string read_path ;
    time_t interval ;
    int read_value;
    int desired_value;


};

#endif // SLIDERREADER_H
