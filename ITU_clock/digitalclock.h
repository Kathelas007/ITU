#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

#include "generalmodel.h"
#include "digitalmodel.h"

class DigitalClock : public QLCDNumber
{
    Q_OBJECT
public:
    explicit DigitalClock(QWidget *parent = nullptr);


public slots:
    void displayClock();

private slots:
    void displayTime();

private:

    QString timeFormat;

signals:

};

#endif // DIGITALCLOCK_H
