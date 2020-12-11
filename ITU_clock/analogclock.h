#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QtQuickWidgets/QQuickWidget>

class AnalogClock : public QWidget
{
    Q_OBJECT
public:
    explicit AnalogClock(QWidget *parent = nullptr);

private:
    void buildClock();
    void displayClock();

private slots:
    void displayTime();

signals:

};

#endif // ANALOGCLOCK_H
