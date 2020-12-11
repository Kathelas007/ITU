#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>

class AnalogClock : public QWidget
{
    Q_OBJECT
public:
    explicit AnalogClock(QWidget *parent = nullptr);

private:
    void displayClock();

private slots:
    void displayTime();

signals:

};

#endif // ANALOGCLOCK_H
