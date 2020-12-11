#include "analogclock.h"

AnalogClock::AnalogClock(QWidget *parent) : QWidget(parent)
{
    //set the unchanging appearance aspects
    setMinimumSize(180, 100);

    //refresh widget appearance after every second
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    timer->start(1000);

    displayClock();
}

void AnalogClock::displayClock(){

    //udělat přípravy pro všechna ta personalizovaná nastavení

}

/*******************SLOTS*******************/

void AnalogClock::displayTime(){

}
