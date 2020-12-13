#ifndef CLOCKWINDOW_H
#define CLOCKWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QToolButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTime>
#include <QCursor>

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
    void updateTimeLabel();

private:
    DigitalClock* digital = nullptr;
    AnalogClock* analog = nullptr;

    QGridLayout* windowLayout;

    QSpacerItem* horizontalSpace;
    QLabel*      collapsedTimeLabel;
    QToolButton* closeButton;
    QToolButton* minimButton;
    QToolButton* settingsButton;

    bool collapsed = false;
    int spaceWidth = 130;
    int baseW      = 200;
    int baseH      = 200;

    int collapsedW = 200;
    int collapsedH = 22;

    int mouseCoordX;
    int mouseCoordY;

    QSize baseIconSize = QSize(20,20);

    QGridLayout* setup_layout(QWidget* widget);
    void set_close_minim_buttons(QGridLayout* layout);

    QLabel*      setup_collapsed_label(QHBoxLayout* layout);
    QToolButton* display_close_button(QHBoxLayout* layout);
    QToolButton* display_minimize_button(QHBoxLayout* layout);
    QToolButton* display_settings_button(QGridLayout* layout);

    void displayClock(QGridLayout* layout);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};
#endif // CLOCKWINDOW_H
