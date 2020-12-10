#ifndef CLOCKWINDOW_H
#define CLOCKWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QToolButton>
#include <QGridLayout>

#include "generalmodel.h"

class ClockWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClockWindow(QWidget *parent = nullptr);

private slots:

private:
    QGridLayout* windowLayout;

    QToolButton* closeButton;
    QToolButton* minimButton;
    QToolButton* settingsButton;

    QGridLayout* setup_layout(QWidget* widget);
    QToolButton* display_close_button(QGridLayout* layout);
    QToolButton* display_minimize_button(QGridLayout* layout);
    QToolButton* display_settings_button(QGridLayout* layout);

    void setup_window(QWidget* widget);
    void display_clock(QGridLayout* layout);
};
#endif // CLOCKWINDOW_H
