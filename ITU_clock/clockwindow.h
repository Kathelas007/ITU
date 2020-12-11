#ifndef CLOCKWINDOW_H
#define CLOCKWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QToolButton>
#include <QGridLayout>
#include <QHBoxLayout>

#include "digitalclock.h"

#include "generalmodel.h"
#include "settingwindow.h"



class ClockWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClockWindow(QWidget *parent = nullptr);

private slots:
    void hideShowClock();
    void showSettings();

private:
    DigitalClock* digital;

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

    void setup_window(QWidget* widget);
    void display_clock(QGridLayout* layout);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};
#endif // CLOCKWINDOW_H
