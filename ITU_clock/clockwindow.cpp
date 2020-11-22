#include "clockwindow.h"
#include "ui_clockwindow.h"

//#include "settingwindow.h"

ClockWindow::ClockWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClockWindow)
{
    ui->setupUi(this);
}

ClockWindow::~ClockWindow()
{
    delete ui;
}


void ClockWindow::on_toolButton_clicked()
{
//    SettingWindow *setting= new SettingWindow();
//    setting->show();
}
