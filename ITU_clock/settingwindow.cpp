#include "settingwindow.h"
#include "ui_settingwindow.h"

#include <stdio.h>
#include <cstdio>
#include <iostream>

#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include<QFontDialog>
#include<QColorDialog>

#include "generalmodel.h"
#include "digitalmodel.h"
#include "analogmodel.h"


SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);

    digitalModel = DigitalModel::getInstance();
    generalModel = GeneralModel::getInstance();
    analogModel = AnalogModel::getInstance();

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

//    Analog
    comboBoxMapper[ui->dial_mode_cb] = &analogModel->dial_mode;
    comboBoxMapper[ui->dial_desc_cb] = &analogModel->dial_mode;
    colorPushButtonMapper[ui->dial_color_p] = &analogModel->dial_color;

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

void SettingWindow::comboBoxChanged(int index){
     QComboBox* cb = qobject_cast<QComboBox*>(sender());
     *comboBoxMapper[cb] = index;
     generalModel->settingChanged();
}

void SettingWindow::colorPushButtonClicked(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QColor old_color = *colorPushButtonMapper[button];
    QColor new_color = QColorDialog::getColor(old_color, this);
    *colorPushButtonMapper[button] = new_color;

    button->setText(new_color.name());

    generalModel->settingChanged();


}

void SettingWindow::checkBoxChanged(int state){
    QCheckBox* cb = qobject_cast<QCheckBox*>(sender());
    *checkBoxMapper[cb] = bool(state);
    generalModel->settingChanged();

}
void SettingWindow::lineEditChanged(QString text){
    QLineEdit* cb = qobject_cast<QLineEdit*>(sender());
    *lineEditMapper[cb] = text;
    generalModel->settingChanged();

}
void SettingWindow::sliderChanged(int value){
    QSlider* cb = qobject_cast<QSlider*>(sender());
    *sliderMapper[cb] = value;
    generalModel->settingChanged();
}


void SettingWindow::loadSetting(){
    QMapIterator<QComboBox*,int *> cb(comboBoxMapper);
    while (cb.hasNext()) {
        cb.next();
        cb.key()->setCurrentIndex(*cb.value());
        connect(cb.key(), SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxChanged(int)));
    }

    QMapIterator<QSlider*,int *> sl(sliderMapper);
    while (sl.hasNext()) {
        sl.next();
        sl.key()->setValue(*sl.value());
        connect(sl.key(), SIGNAL(valueChanged(int)), this, SLOT(sliderChanged(int)));
    }

    QMapIterator<QCheckBox*,bool *> chb(checkBoxMapper);
    while (chb.hasNext()) {
        chb.next();
        chb.key()->setChecked(*chb.value());
        connect(chb.key(), SIGNAL(stateChanged(int)), this, SLOT(sliderChanged(int)));
    }

    QMapIterator<QPushButton*,QColor*> pb(colorPushButtonMapper);
    while (pb.hasNext()) {
        pb.next();
        pb.key()->setText(pb.value()->name());
        connect(pb.key(), SIGNAL(clicked()), this, SLOT(colorPushButtonClicked()));
    }

    QMapIterator<QLineEdit*,QString*> le(lineEditMapper);
    while (le.hasNext()) {
        le.next();
        le.key()->setText(*le.value());
        connect(le.key(), SIGNAL(textChanged(QString)), this, SLOT(lineEditChanged(QString))); // maybe edited
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
