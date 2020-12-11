#include "analogclock.h"

AnalogClock::AnalogClock(QWidget *parent) : QWidget(parent)
{
    //set the unchanging appearance aspects
    setMinimumSize(160, 160);

    //display the default clock
    buildClock();

    //edit the default clock according to settings
    displayClock();

    //refresh widget appearance after every second
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    timer->start(1000);
}

void AnalogClock::buildClock(){

    //assemble and display default analog clock

}

void AnalogClock::displayClock(){

    //apply additional settings


    //start displaying correct time
    this->displayTime();
}

/*******************SLOTS*******************/

void AnalogClock::displayTime(){

}
