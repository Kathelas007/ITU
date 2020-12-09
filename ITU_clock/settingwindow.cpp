#include "settingwindow.h"
#include "ui_settingwindow.h"

#include <stdio.h>
#include <cstdio>
#include <iostream>

#include <QColor>
#include <QColorDialog>

#include "generalmodel.h"


SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    generalModel = GeneralModel::getInstance();

    setPages();
    loadSetting();
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::setPages(){

//  ui->deliminer_line_edit->setAlignment(Qt::AlignVCenter);

    ui->pushButton_1->setChecked(true);
    this->activeButton = ui->pushButton_1;
    ui->stackedWidget->setCurrentWidget(ui->page_1);

    button_to_pages[ui->pushButton_1] = ui->page_1;
    button_to_pages[ui->pushButton_2] = ui->page_2;
    button_to_pages[ui->pushButton_3] = ui->page_3;

    QMapIterator<QPushButton*, QWidget*> i(button_to_pages);
    while (i.hasNext()) {
        i.next();
        connect(i.key(), SIGNAL(clicked(bool)), this, SLOT(changePage(bool)));
    }
}

void SettingWindow::loadSetting(){
    ui->mode_combo->setCurrentIndex(generalModel->mode);
}

void SettingWindow::changePage(bool active){
   QPushButton* button = qobject_cast<QPushButton*>(sender());
   if(active == false and button == this->activeButton){
        button->setChecked(true);
        return;
   }

    this->activeButton->setChecked(false);
    this->activeButton = button;

    ui->stackedWidget->setCurrentWidget(button_to_pages[button]);
}

void SettingWindow::on_color_bg_button_clicked()
{

}
