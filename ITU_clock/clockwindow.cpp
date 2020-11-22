#include "clockwindow.h"
#include "ui_clockwindow.h"

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

