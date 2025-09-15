#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sliderreader.h"
#include "signalmanager.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private:
    std::unique_ptr<SliderReader> min_freq_reader;
    std::unique_ptr<SliderReader> max_freq_reader;
    std::unique_ptr<SignalManager> signal_manager ;

};
#endif // MAINWINDOW_H
