
#include <QtWidgets>

#include "clockwindow.h"

ClockWindow::ClockWindow(QWidget *parent)
    : QMainWindow(parent, Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Tool)
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

    widget->setStyleSheet("background-color: rgba(153,151,150,0");

    //appearance based on settings
    this->displayClock(this->windowLayout);

    setCentralWidget(widget);

    //setup timer for collapsed label
    QTimer *timer = new QTimer(this);

    //signals and slots
    connect(this->closeButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(this->minimButton, SIGNAL(clicked()), this, SLOT(hideShowClock()));
    connect(this->settingsButton, SIGNAL(clicked()), this, SLOT(showSettings()));
    connect(GeneralModel::getInstance(), SIGNAL(settingChanged()), this, SLOT(checkDisplayed()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimeLabel()));

    timer->start(1000);
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

    this->horizontalSpace = new QSpacerItem(this->spaceWidth,0);
    inLayout->addSpacerItem(this->horizontalSpace);
    this->collapsedTimeLabel = this->setup_collapsed_label(inLayout);
    this->minimButton    = this->display_minimize_button(inLayout);
    this->closeButton    = this->display_close_button(inLayout);
}

QLabel* ClockWindow::setup_collapsed_label(QHBoxLayout* layout){
    QLabel* label = new QLabel();
    //set size properly
    layout->addWidget(label, 0, Qt::AlignLeft|Qt::AlignTop);
    label->hide();
    return label;
}

QToolButton* ClockWindow::display_close_button(QHBoxLayout* layout){

    QToolButton* button= new QToolButton();
    button->setIcon(QIcon(":/assets/window-close-symbolic.png"));

    layout->addWidget(button, 0, Qt::AlignRight|Qt::AlignTop);
    return button;

}

QToolButton* ClockWindow::display_minimize_button(QHBoxLayout* layout){
    QToolButton* button= new QToolButton();
    button->setIcon(QIcon(":/assets/window-minimize-symbolic.png"));
    layout->addWidget(button, 0, Qt::AlignRight|Qt::AlignTop);
    return button;
}

QToolButton* ClockWindow::display_settings_button(QGridLayout *layout){
    QToolButton* button= new QToolButton();
    button->setIcon(QIcon(":/assets/playlist-automatic-symbolic.png"));
    layout->addWidget(button, 3, 3, Qt::AlignRight|Qt::AlignBottom);
    return button;
}

void ClockWindow::displayClock(QGridLayout* layout){

    GeneralModel *model = GeneralModel::getInstance();
    if( model->mode == 1 ){
        if(this->digital != nullptr){
            this->digital->hide();
        }

        if(this->analog == nullptr){
            this->analog = new AnalogClock();
            layout->addWidget(analog, 2, 1, 1, 3, Qt::AlignCenter);
            return;
        }
        this->analog->show();
    }
    else {
       if (this->analog != nullptr){
           this->analog->hide();
       }

       if(this->digital == nullptr){
            this->digital = new DigitalClock();
            layout->addWidget(digital, 2, 1, 1, 3, Qt::AlignCenter);
            return;
       }
       this->digital->show();
    }

}

/***********************SLOTS***********************/

void ClockWindow::checkDisplayed(){
    this->displayClock(this->windowLayout);
}

void ClockWindow::updateTimeLabel(){
    this->collapsedTimeLabel->setText(QTime::currentTime().toString(DigitalClock::getTimeFormat()));
}

void ClockWindow::hideShowClock(){

    GeneralModel* model = GeneralModel::getInstance();

    if (this->collapsed){
        if (model->mode == 1){
            this->analog->show();
        }
        else{
            this->digital->show();
        }

        this->settingsButton->show();
        resize(this->baseW, this->baseH);
        this->collapsed = false;

        this->minimButton->setIcon(QIcon(":/assets/window-minimize-symbolic.png"));
        this->collapsedTimeLabel->hide();
        this->horizontalSpace->changeSize(this->spaceWidth,0);
    }

    else{
        if(model->mode == 1){
            this->analog->hide();
        }
        else{
            this->digital->hide();
        }

      this->settingsButton->hide();
      resize(this->collapsedW, this->collapsedH);
      this->collapsed = true;
      this->collapsedTimeLabel->show();
      this->minimButton->setIcon(QIcon(":/assets/window-maximize-symbolic.png"));
      this->horizontalSpace->changeSize(0,0);
    }
}

void ClockWindow::showSettings(){
    //uprav tak, aby se nedala vyklikat hromada oken
    SettingWindow *settings = new SettingWindow();
    settings->show();
}
