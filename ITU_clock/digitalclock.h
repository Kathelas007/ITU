#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

#include "generalmodel.h"

class DigitalClock : public QLCDNumber
{
    Q_OBJECT
public:
    explicit DigitalClock(QWidget *parent = nullptr);

private slots:
    void displayTime();

private:

    QString timeFormat;

    void displayClock();

signals:

};

#endif // DIGITALCLOCK_H
