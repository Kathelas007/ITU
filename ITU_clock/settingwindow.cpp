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
    digitalModel = DigitalModel::getInstance();

    setMappers();
    setPages();
    loadSetting();
}

SettingWindow::~SettingWindow()
{
    delete ui;
    generalModel->saveSetting();
}

void SettingWindow::setMappers(){

//    General
    comboBoxMapper[ui->mode_cb] = &generalModel->mode;
    comboBoxMapper[ui->design_cb] = &generalModel->design;
    sliderMapper[ui->opacity_slider] = &generalModel->opacity;

    checkBoxMapper[ui->hours_chb] = &generalModel->hours;
    checkBoxMapper[ui->minutes_chb] = &generalModel->minutes;
    checkBoxMapper[ui->seconds_chb] = &generalModel->seconds;
    checkBoxMapper[ui->own_chb] = &generalModel->own;


    colorPushButtonMapper[ui->h_color_b] = &generalModel->h_color;
    colorPushButtonMapper[ui->m_color_b] = &generalModel->m_color;
    colorPushButtonMapper[ui->s_color_b] = &generalModel->s_color;
    colorPushButtonMapper[ui->b_color_b] = &generalModel->b_color;

//    Digital
    comboBoxMapper[ui->format_cb] = &digitalModel->format;
    lineEditMapper[ui->deliminer_le] = &digitalModel->deliminer;

//

}
void SettingWindow::setPages(){

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
    QMapIterator<QComboBox*,int *> cb(comboBoxMapper);
    while (cb.hasNext()) {
        cb.next();
        cb.key()->setCurrentIndex(*cb.value());
    }

    QMapIterator<QSlider*,int *> sl(sliderMapper);
    while (sl.hasNext()) {
        sl.next();
        sl.key()->setValue(*sl.value());
    }

    QMapIterator<QCheckBox*,bool *> chb(checkBoxMapper);
    while (chb.hasNext()) {
        chb.next();
        chb.key()->setChecked(*chb.value());
    }

    QMapIterator<QPushButton*,QColor*> pb(colorPushButtonMapper);
    while (pb.hasNext()) {
        pb.next();
        pb.key()->setText(pb.value()->name());
    }

    QMapIterator<QLineEdit*,QString*> le(lineEditMapper);
    while (le.hasNext()) {
        le.next();
        le.key()->setText(*le.value());
    }

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
