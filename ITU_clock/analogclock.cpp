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

    AnalogModel* analogMod = AnalogModel::getInstance();

    //select clock face type
    if (analogMod->dial_mode == 0){

        if(analogMod->dial_description == 0){
            this->faceImage = new QImage(":/assets/clock_face_full_numbers.png");
        }

        else{
            this->faceImage = new QImage(":/assets/clock_face_partial_markings.png");
        }
    }

    else if (analogMod->dial_mode ==1){
        this->faceImage = new QImage(":/assets/clock_face_full_markings.png");
    }

    else{
        this->faceImage = new QImage(":/assets/clock_face_none.png");
    }

    //apply current dial color on the clock face
    this->paintClockFace();

    //create items for needles
    this->hourNeedle = new QGraphicsRectItem(72,25,6,50);
    this->minuteNeedle = new QGraphicsRectItem(73,15,4,60);
    this->secondNeedle = new QGraphicsRectItem(74,5,2,70);

    this->hourNeedle->setTransformOriginPoint(75,75);
    this->minuteNeedle->setTransformOriginPoint(75,75);
    this->secondNeedle->setTransformOriginPoint(75,75);

    this->clockFace = new QGraphicsPixmapItem(QPixmap::fromImage(*(this->faceImage)));
    this->clockFace->setScale(0.25);
    this->clockScene->addItem(this->clockFace);
    this->clockScene->addItem(this->hourNeedle);
    this->clockScene->addItem(this->minuteNeedle);
    this->clockScene->addItem(this->secondNeedle);
}

void AnalogClock::displayClock(){

    GeneralModel* generalMod = GeneralModel::getInstance();
    AnalogModel* analogMod   = AnalogModel::getInstance();

    //TODO: check if correct clockface is set, if not, change it
    //this->paintClockFace();

    QRgb bGround = generalMod->b_color.rgb();
    this->setStyleSheet("background-color: rgba(" + QString::number(qRed(bGround)) +"," + QString::number(qGreen(bGround)) +"," + QString::number(qBlue(bGround)) + ","+ QString::number(generalMod->opacity) +");");

    //start displaying correct time
    this->displayTime();
}

void AnalogClock::paintClockFace(){
    AnalogModel* analogMod = AnalogModel::getInstance();
    QPainter clockFacePainter(this->faceImage);
    clockFacePainter.setPen(analogMod->dial_color);
    QBitmap mask = QBitmap::fromImage(this->faceImage->createMaskFromColor(QColor(Qt::black).rgb(), Qt::MaskOutColor));
    clockFacePainter.drawPixmap(this->faceImage->rect(), mask, mask.rect());
}

/*******************SLOTS*******************/

void AnalogClock::displayTime(){

    QTime time = QTime::currentTime();
    this->hourNeedle->setRotation(30.0 * ((time.hour() + time.minute() / 60.0)));
    this->minuteNeedle->setRotation(6.0 * (time.minute() + time.second() / 60.0));
    this->secondNeedle->setRotation(6.0 * time.second());
}
