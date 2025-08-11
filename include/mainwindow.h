#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void dostuff();
    enum class GoodThings {Angels, Dab, DepechMode};
    void doGood(MainWindow::GoodThings which);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
