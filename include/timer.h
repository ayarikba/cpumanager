#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <QThread>
class Timer : public QObject {
    Q_OBJECT

public:
    Timer() : m_Timer(new QTimer(this))
    {
        connect(m_Timer, &QTimer::timeout, this,[this](){emit triggered();});
    }

    void initProperties(unsigned int m_frequency)
    {
        m_Interval = static_cast<int>(1000 / double(m_frequency));
    }
    ~Timer() {
        if (m_Timer->isActive()) {
            m_Timer->stop();
        }
    }

signals:
    void triggered();

public slots:
    void onThreadStarted() {
        // LOG_INFO("Timer thread started, starting QTimer...");
        m_Timer->setInterval(m_Interval);
        m_Timer->start();
    }

    void stop() {
        if (m_Timer->isActive()) {

            m_Timer->stop();
        }
    }

private:
    QTimer* m_Timer;
    int m_Interval;
};

#endif
