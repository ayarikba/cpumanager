#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include "comboboxhelper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    min_freq_reader = std::make_unique<SliderReader>("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq") ;
    max_freq_reader =  std::make_unique<SliderReader>("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq") ;




    signal_manager =  std::make_unique<SignalManager>();
}



MainWindow::~MainWindow(){
    delete ui;
}

