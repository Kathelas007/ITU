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

/********************SLOTS*********************/

void DigitalClock::displayClock(){

    GeneralModel* model = GeneralModel::getInstance();

    //TODO:nastavit správně nejen průhlednost, ale i barvu pozadí
    QRgb bGround = model->b_color.rgb();
    this->setStyleSheet("background-color: rgba(" + QString::number(qRed(bGround)) +"," + QString::number(qGreen(bGround)) +"," + QString::number(qBlue(bGround)) + ","+ QString::number(model->opacity) +");");

    //setup color
    setPalette(model->dial_color);

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

void DigitalClock::displayTime(){
    QTime time = QTime::currentTime();
    QString text = time.toString(this->timeFormat);
    display(text);
}
