#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include "comboboxhelper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->comboBox, (&QComboBox::activated), this , &MainWindow::dostuff);
    ComboBoxHelper::setup<int>(ui->comboBox, 5, {{"Low", 1}, {"Medium", 5}, {"High", 10}}, this, &MainWindow::doGood);


    ComboBoxHelper::setup<GoodThings>(ui->comboBox_3, GoodThings::Angels,
                                      {{"Angels", GoodThings::Angels},
                                       {"Depeche Mode", GoodThings::DepechMode},
                                        {"KDAB Videos on YouTube", GoodThings::Dab}},
                                      [this](GoodThings which) { doGood(which); });

}

void MainWindow::doGood(MainWindow::GoodThings which)
{
    switch(which)
    {
        case GoodThings::Angels:
            std::cout << "Angel" << std::endl;
            break;
        case GoodThings::Dab:
            std::cout << "m" << std::endl;
            break;
        case GoodThings::DepechMode:
            std::cout << "sd" << std::endl;
    }
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::dostuff()
{
    std::cout << "hello" << std::endl;
}
