#ifndef SLIDERREADER_H
#define SLIDERREADER_H

#include <QObject>
#include <QWidget>
#include <IReader.h>

class SliderReader : public IReader
{
public:
    public:
    SliderReader();


public:
    std::string read_path ;
    time_t interval ;


};

#endif // SLIDERREADER_H
