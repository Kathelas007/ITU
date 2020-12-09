
#include <QtWidgets>

#include "clockwindow.h"

ClockWindow::ClockWindow(QWidget *parent)
    : QMainWindow(parent, Qt::FramelessWindowHint)
{
    QWidget* widget = new QWidget(this);
    this->buttonLayout   = this->setup_layout(widget);
    this->closeButton    = this->display_close_button(this->buttonLayout);
    this->minimButton    = this->display_minimize_button(this->buttonLayout);
    this->settingsButton = this->display_settings_button(this->buttonLayout);
    setCentralWidget(widget);

    //get settings
    this->display_clock();
}

QGridLayout* ClockWindow::setup_layout(QWidget *widget){
    QGridLayout* layout = new QGridLayout();
    widget->setLayout(layout);
    return layout;
}

QToolButton* ClockWindow::display_close_button(QGridLayout* layout){
    //properly implement (the others too)
    //bind to correct actions, probs self defined, or just use it as normal push buttons, should be possible
    //set button style
    //make the damn clock!
    QToolButton* button= new QToolButton();
    layout->addWidget(button, 1, 3);
    return button;

}

QToolButton* ClockWindow::display_minimize_button(QGridLayout* layout){
    QToolButton* button= new QToolButton();
    layout->addWidget(button, 1, 2);
    return button;
}

QToolButton* ClockWindow::display_settings_button(QGridLayout *layout){
    QToolButton* button= new QToolButton();
    layout->addWidget(button, 3, 3);
    return button;
}

void ClockWindow::display_clock(){

}
