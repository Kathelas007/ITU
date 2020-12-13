#include "analogclock.h"

AnalogClock::AnalogClock(QWidget *parent) : QGraphicsView(parent)
{
    //set the unchanging appearance aspects
    setMinimumSize(150, 150);
    resize(150,150);
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    this->circleRegion = new QRegion(this->rect(), QRegion::Ellipse);
    this->setMask(*(this->circleRegion));
    this->clockScene = new QGraphicsScene(this);
    setScene(this->clockScene);

    this->lastFaceColor = QColor(Qt::black);
    this->lastHourColor = QColor(Qt::black);
    this->lastMinuteColor = QColor(Qt::black);
    this->lastSecondColor = QColor(Qt::black);

    //display the default clock
    buildClock();

    //edit the default clock according to settings
    displayClock();

    //refresh widget appearance after every second
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    connect(GeneralModel::getInstance(), SIGNAL(settingChanged()), this, SLOT(displayClock()));
    connect(AnalogModel::getInstance(), SIGNAL(settingChanged()), this, SLOT(displayClock()));

    timer->start(1000);
}

void AnalogClock::buildClock(){

    this->selectClockFaceType();

    this->hourNeedle = new QImage(":/assets/hour_needle.png");
    this->minuteNeedle = new QImage(":/assets/minute_needle.png");
    this->secondNeedle = new QImage(":/assets/second_needle.png");

    //apply current dial color on the clock face
    this->paintClockFace();
    this->paintNeedles();

    this->clockFace = new QGraphicsPixmapItem(QPixmap::fromImage(*(this->faceImage)));
    this->clockFace->setScale(0.256);

    this->hourNeedleItem = new QGraphicsPixmapItem(QPixmap::fromImage(*(this->hourNeedle)));
    this->hourNeedleItem->setOffset(70,-15);
    this->hourNeedleItem->setScale(0.5);
    this->hourNeedleItem->setTransformOriginPoint(75,75);

    this->minuteNeedleItem = new QGraphicsPixmapItem(QPixmap::fromImage(*(this->minuteNeedle)));
    this->minuteNeedleItem->setOffset(70,-35);
    this->minuteNeedleItem->setScale(0.5);
    this->minuteNeedleItem->setTransformOriginPoint(75,75);

    this->secondNeedleItem = new QGraphicsPixmapItem(QPixmap::fromImage(*(this->secondNeedle)));
    this->secondNeedleItem->setOffset(72,-55);
    this->secondNeedleItem->setScale(0.5);
    this->secondNeedleItem->setTransformOriginPoint(75,75);

    this->clockScene->addItem(this->clockFace);
    this->clockScene->addItem(this->hourNeedleItem);
    this->clockScene->addItem(this->minuteNeedleItem);
    this->clockScene->addItem(this->secondNeedleItem);
}

void AnalogClock::selectClockFaceType(){

    AnalogModel* analogMod = AnalogModel::getInstance();



    //select clock face type
    if (analogMod->dial_mode == 0 && analogMod->dial_description != 2){

        if(analogMod->dial_description == 0){
            this->faceImage = new QImage(":/assets/clock_face_full_numbers.png");
        }

        else if (analogMod->dial_description == 1){
            this->faceImage = new QImage(":/assets/clock_face_partial_markings.png");
        }
    }

    else if (analogMod->dial_mode ==1 && analogMod->dial_description != 2){
        this->faceImage = new QImage(":/assets/clock_face_full_markings.png");
    }

    else{
        this->faceImage = new QImage(":/assets/clock_face_none.png");
    }

    this->lastDialMode = analogMod->dial_mode;
    this->lastDescription = analogMod->dial_description;
    this->lastFaceColor = QColor(Qt::black);
}

void AnalogClock::paintClockFace(){
    GeneralModel* generalMod = GeneralModel::getInstance();
    QPainter clockFacePainter(this->faceImage);
    clockFacePainter.setPen(generalMod->dial_color);
    QBitmap mask = QBitmap::fromImage(this->faceImage->createMaskFromColor(this->lastFaceColor.rgb(), Qt::MaskOutColor));
    clockFacePainter.drawPixmap(this->faceImage->rect(), mask, mask.rect());
    this->lastFaceColor = generalMod->dial_color;
    clockFacePainter.end();
}

void AnalogClock::paintNeedles(){

    AnalogModel* analogMod = AnalogModel::getInstance();
    QBitmap mask;

    QPainter hourPainter(this->hourNeedle);
    hourPainter.setPen(analogMod->h_color);
    mask = QBitmap::fromImage(this->hourNeedle->createMaskFromColor(this->lastHourColor.rgb(), Qt::MaskOutColor));
    hourPainter.drawPixmap(this->hourNeedle->rect(), mask, mask.rect());
    this->lastHourColor = analogMod->h_color;
    hourPainter.end();

    QPainter minutePainter(this->minuteNeedle);
    minutePainter.setPen(analogMod->m_color);
    mask = QBitmap::fromImage(this->minuteNeedle->createMaskFromColor(this->lastMinuteColor.rgb(), Qt::MaskOutColor));
    minutePainter.drawPixmap(this->minuteNeedle->rect(), mask, mask.rect());
    this->lastMinuteColor = analogMod->m_color;
    minutePainter.end();

    QPainter secondPainter(this->secondNeedle);
    secondPainter.setPen(analogMod->s_color);
    mask = QBitmap::fromImage(this->secondNeedle->createMaskFromColor(this->lastSecondColor.rgb(), Qt::MaskOutColor));
    secondPainter.drawPixmap(this->secondNeedle->rect(), mask, mask.rect());
    this->lastSecondColor = analogMod->s_color;
    secondPainter.end();
}

/*******************SLOTS*******************/
void AnalogClock::displayClock(){

    GeneralModel* generalMod = GeneralModel::getInstance();
    AnalogModel* analogMod   = AnalogModel::getInstance();

    if (this->lastDialMode != analogMod->dial_mode || this->lastDescription != analogMod->dial_description){
        selectClockFaceType();
    }

    this->paintClockFace();
    this->clockFace->setPixmap(QPixmap::fromImage(*(this->faceImage)));

    QRgb bGround = generalMod->b_color.rgb();
    this->setStyleSheet("background-color: rgba(" + QString::number(qRed(bGround)) +"," + QString::number(qGreen(bGround)) +"," + QString::number(qBlue(bGround)) + ","+ QString::number(generalMod->opacity) +");");

    //repaint needles
    if(this->lastHourColor != analogMod->h_color || this->lastMinuteColor != analogMod->m_color || this->lastSecondColor != analogMod->s_color){
    this->paintNeedles();
    this->hourNeedleItem->setPixmap(QPixmap::fromImage(*(this->hourNeedle)));
    this->minuteNeedleItem->setPixmap(QPixmap::fromImage(*(this->minuteNeedle)));
    this->secondNeedleItem->setPixmap(QPixmap::fromImage(*(this->secondNeedle)));
    }

    //which needles to show
    if(generalMod->hours == true)
        this->hourNeedleItem->show();
    else
        this->hourNeedleItem->hide();

    if(generalMod->minutes == true)
        this->minuteNeedleItem->show();
    else
        this->minuteNeedleItem->hide();

    if(generalMod->seconds == true)
       this->secondNeedleItem->show();
    else
       this->secondNeedleItem->hide();

    //start displaying correct time
    this->displayTime();
}

void AnalogClock::displayTime(){

    QTime time = QTime::currentTime();
    this->hourNeedleItem->setRotation(30.0 * ((time.hour() + time.minute() / 60.0)));
    this->minuteNeedleItem->setRotation(6.0 * (time.minute() + time.second() / 60.0));
    this->secondNeedleItem->setRotation(6.0 * time.second());
}
