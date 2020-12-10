
#include <QtWidgets>

#include "clockwindow.h"

ClockWindow::ClockWindow(QWidget *parent)
    : QMainWindow(parent, Qt::FramelessWindowHint)
{
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    QWidget* widget = new QWidget(this);
    this->windowLayout   = this->setup_layout(widget);
    this->closeButton    = this->display_close_button(this->windowLayout);
    this->minimButton    = this->display_minimize_button(this->windowLayout);
    this->settingsButton = this->display_settings_button(this->windowLayout);


    this->setup_window(widget);
    this->display_clock(this->windowLayout);
    setCentralWidget(widget);
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

void ClockWindow::setup_window(QWidget* widget){

    //add rest
    GeneralModel *model = GeneralModel::getInstance();
    widget->setStyleSheet("background-color: rgba(255,255,255,128);");
}

void ClockWindow::display_clock(QGridLayout* layout){
    //actually display clock
}
