#ifndef CLOCKWINDOW_H
#define CLOCKWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QToolButton>
#include <QGridLayout>
#include <QHBoxLayout>

#include "digitalclock.h"
#include "analogclock.h"

#include "generalmodel.h"
#include "settingwindow.h"

class ClockWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClockWindow(QWidget *parent = nullptr);

public slots:
    void checkDisplayed();

private slots:
    void hideShowClock();
    void showSettings();

private:
    DigitalClock* digital = nullptr;
    AnalogClock* analog = nullptr;

    QGridLayout* windowLayout;

    QToolButton* closeButton;
    QToolButton* minimButton;
    QToolButton* settingsButton;

    bool collapsed = false;

    int baseW      = 200;
    int baseH      = 200;

    int collapsedW = 200;
    int collapsedH = 22;

    int mouseCoordX;
    int mouseCoordY;

    QGridLayout* setup_layout(QWidget* widget);
    void set_close_minim_buttons(QGridLayout* layout);

    QToolButton* display_close_button(QHBoxLayout* layout);
    QToolButton* display_minimize_button(QHBoxLayout* layout);
    QToolButton* display_settings_button(QGridLayout* layout);

    void displayClock(QGridLayout* layout);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};
#endif // CLOCKWINDOW_H
