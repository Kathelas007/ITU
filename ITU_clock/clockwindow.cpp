
#include <QtWidgets>

#include "clockwindow.h"

ClockWindow::ClockWindow(QWidget *parent)
    : QMainWindow(parent, Qt::FramelessWindowHint)
{
    this->setup_layout();
    this->display_close_button();
    this->display_minimize_button();

    //select clock according to settings
    //TODO work with settings
    this->display_clock();
}

void ClockWindow::setup_layout(){


}

void ClockWindow::display_close_button(){

}

void ClockWindow::display_minimize_button(){

}

void ClockWindow::display_clock(){

}
