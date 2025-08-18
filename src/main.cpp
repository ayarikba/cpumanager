#include <iostream>
#include "Cpu.h"
#include "mainwindow.h"
#include <QApplication>

void init()
{

    logging::add_file_log
        (
            keywords::file_name = "sample_%N.log",
            keywords::rotation_size = 10 * 1024 * 1024,
            keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
            keywords::format = "[%TimeStamp%]: %Message%"
            );

#ifdef DEBUG
    logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::trivial::info
            );
#else
    logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::warning;
);
}


int main(int argc, char *argv[])
{
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
