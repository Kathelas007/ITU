#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPixmap>
#include <QImage>
#include <QPolygonF>
#include <QBrush>

#include "generalmodel.h"
#include "analogmodel.h"

class AnalogClock : public QGraphicsView
{
    Q_OBJECT
public:
    explicit AnalogClock(QWidget *parent = nullptr);

private:
    QGraphicsScene* clockScene;
    QGraphicsPixmapItem* clockFace=nullptr;
    QGraphicsRectItem* hourNeedle = nullptr;
    QGraphicsRectItem* minuteNeedle = nullptr;
    QGraphicsRectItem* secondNeedle = nullptr;

    QImage* faceImage;

    //items of the clock

    void buildClock();
    void displayClock();

private slots:
    void displayTime();

signals:

};

#endif // ANALOGCLOCK_H
