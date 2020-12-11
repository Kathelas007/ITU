#include "digitalclock.h"

DigitalClock::DigitalClock(QWidget *parent) : QLCDNumber(parent)
{
    //design settings that don't change
    setSegmentStyle(Flat);
    setMinimumSize(180, 100);

    //refresh the clock´ every second
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    timer->start(1000);

    //podle nastavení
    //bude volat displayTime()
    displayClock();
}


void DigitalClock::displayClock(){

    GeneralModel* model = GeneralModel::getInstance();


    //setup color
    //TODO: upravit, aby zobrazovalo pro jednotlivé kusy zvlášť, jestli to jde
    setPalette(model->h_color);

    //setup time display format
    this->timeFormat = "";
    if(model->hours == true)
        this->timeFormat += "hh";
    if(model->minutes == true)
        this->timeFormat += ":mm";
    if(model->seconds == true)
        this->timeFormat += ":ss";

    //TODO: ještě pořešit am/pm z nastavení (legit, je potřeba akorát přidat do formátovacího stringu)
    setDigitCount(this->timeFormat.length());


    displayTime();
}

/********************SLOTS*********************/

void DigitalClock::displayTime(){
    QTime time = QTime::currentTime();
    QString text = time.toString(this->timeFormat);
    display(text);
}
