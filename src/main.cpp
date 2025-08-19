#include <iostream>
#include "Cpu.h"
#include "mainwindow.h"
#include <QApplication>
#include "sliderreader.h"
#include <boost/log/trivial.hpp>

void init()
{
        boost::log::add_file_log
        (
        boost::log::keywords::file_name = "sample_%N.log",
            boost::log::keywords::rotation_size = 10 * 1024 * 1024,
            boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
            boost::log::keywords::format = "[%TimeStamp%]: %Message%"
            );

#ifdef DEBUG
    boost::log::core::get()->set_filter
        (
            boost::log::trivial::severity >= logging::trivial::info
            );
#else
    logging::core::get()->set_filter
        (
            boost::log::trivial::severity >= logging::warning;
);
#endif
}


int main(int argc, char *argv[])
{
    init();
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
