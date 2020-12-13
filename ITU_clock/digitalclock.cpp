#include "digitalclock.h"

DigitalClock::DigitalClock(QWidget *parent) : QLCDNumber(parent)
{
    //design settings that don't change
    setSegmentStyle(Flat);
    setMinimumSize(180, 100);

    //refresh the clock´ every second
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    connect(GeneralModel::getInstance(), SIGNAL(settingChanged()), this, SLOT(displayClock()));
    connect(DigitalModel::getInstance(), SIGNAL(settingChanged()), this, SLOT(displayClock()));

    timer->start(1000);

    displayClock();
}

/********************SLOTS*********************/

void DigitalClock::displayClock(){

    GeneralModel* model = GeneralModel::getInstance();
    DigitalModel* digitalMod = DigitalModel::getInstance();


    //setup background and number colors
    QRgb bGround = model->b_color.rgb();
    this->setStyleSheet("background-color: rgba(" + QString::number(qRed(bGround)) +"," + QString::number(qGreen(bGround)) +"," + QString::number(qBlue(bGround)) + ","+ QString::number(model->opacity) +");");

    QPalette p;
    p.setColor(QPalette::WindowText, model->dial_color);
    setPalette(p);

    //setup time display format
    this->timeFormat = "";
    if(model->hours == true)
        this->timeFormat += "hh";
    if(model->minutes == true)
        this->timeFormat += digitalMod->deliminer + "mm";
    if(model->seconds == true)
        this->timeFormat += digitalMod->deliminer + "ss";

    setDigitCount(this->timeFormat.length());

    if(digitalMod->format == 0){
        this->timeFormat += " ap";
        setDigitCount(digitCount()+5);
    }

    displayTime();
}

void DigitalClock::displayTime(){
    QTime time = QTime::currentTime();
    QString text = time.toString(this->timeFormat);

    display(text);
}
