
#include <QtWidgets>

#include "clockwindow.h"

ClockWindow::ClockWindow(QWidget *parent)
    : QMainWindow(parent, Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint)
{
    //basic appearance

    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    statusBar()->hide();
    setMinimumSize(this->collapsedW, this->collapsedH);
    resize(this->baseW,this->baseH);

    //elements
    QWidget* widget = new QWidget(this);
    this->windowLayout   = this->setup_layout(widget);
    set_close_minim_buttons(this->windowLayout);
    this->settingsButton = this->display_settings_button(this->windowLayout);

    //appearance based on settings
    this->setup_window(widget);
    this->display_clock(this->windowLayout);


    setCentralWidget(widget);

    //signals and slots
    connect(this->closeButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(this->minimButton, SIGNAL(clicked()), this, SLOT(hideShowClock()));
    connect(this->settingsButton, SIGNAL(clicked()), this, SLOT(showSettings()));
}

void ClockWindow::mousePressEvent(QMouseEvent *event) {
    mouseCoordX = event->x();
    mouseCoordY = event->y();
}

void ClockWindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-mouseCoordX, event->globalY()-mouseCoordY);
}

QGridLayout* ClockWindow::setup_layout(QWidget *widget){
    QGridLayout* layout = new QGridLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    widget->setLayout(layout);
    return layout;
}

void ClockWindow::set_close_minim_buttons(QGridLayout * layout){
    QHBoxLayout* inLayout   = new QHBoxLayout();
    layout->addLayout(inLayout, 1,3);
    inLayout->addSpacerItem(new QSpacerItem(130, 0));
    this->minimButton    = this->display_minimize_button(inLayout);
    this->closeButton    = this->display_close_button(inLayout);
}

QToolButton* ClockWindow::display_close_button(QHBoxLayout* layout){
    //properly implement (the others too)
    //bind to correct actions, probs self defined, or just use it as normal push buttons, should be possible
    //set button style
    QToolButton* button= new QToolButton();
    layout->addWidget(button, 0, Qt::AlignRight|Qt::AlignTop);
    return button;

}

QToolButton* ClockWindow::display_minimize_button(QHBoxLayout* layout){
    QToolButton* button= new QToolButton();
    layout->addWidget(button, 0, Qt::AlignRight|Qt::AlignTop);
    return button;
}

QToolButton* ClockWindow::display_settings_button(QGridLayout *layout){
    QToolButton* button= new QToolButton();
    layout->addWidget(button, 3, 3, Qt::AlignRight|Qt::AlignBottom);
    return button;
}

void ClockWindow::setup_window(QWidget* widget){

    GeneralModel *model = GeneralModel::getInstance();
    widget->setStyleSheet("background-color: rgba(153,151,150,"+ QString::number(model->opacity) +");");
}

void ClockWindow::display_clock(QGridLayout* layout){

    GeneralModel *model = GeneralModel::getInstance();
    if(model->mode == 1 ){
        //zobraz digitalni hodiny
    }
    else {
        //zobraz analogovy hodiny
    }
}

/***********************SLOTS***********************/
void ClockWindow::hideShowClock(){

    if (this->collapsed){
        //zobraz hodiny
        this->settingsButton->show();
        resize(this->baseW, this->baseH);
        this->collapsed = false;
    }

    else{
      //schovej hodiny
      this->settingsButton->hide();
      resize(this->collapsedW, this->collapsedH);
      this->collapsed = true;
    }
}

void ClockWindow::showSettings(){
    //uprav tak, aby se nedala vyklikat hromada oken
    SettingWindow *settings = new SettingWindow();
    settings->show();
}
