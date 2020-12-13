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
#include <QTranslator>

#include "generalmodel.h"
#include "digitalmodel.h"
#include "analogmodel.h"
#include "translator.h"
#include "main.h"


SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(languageChanged()), translator, SLOT(updateLanguage()));

    this->setWindowTitle(tr("ITU clock"));

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
}

void SettingWindow::setMappers(){

//    General
    comboBoxMapper[ui->mode_cb] = qMakePair(generalModel, &generalModel->mode);
    sliderMapper[ui->opacity_slider] = qMakePair(generalModel,&generalModel->opacity);

    checkBoxMapper[ui->hours_chb] = qMakePair(generalModel,&generalModel->hours);
    checkBoxMapper[ui->minutes_chb] = qMakePair(generalModel,&generalModel->minutes);
    checkBoxMapper[ui->seconds_chb] = qMakePair(generalModel,&generalModel->seconds);
    checkBoxMapper[ui->default_design_chb] = qMakePair(generalModel,&generalModel->design);

    colorPushButtonMapper[ui->h_color_b] = qMakePair(analogModel,&analogModel->h_color);
    colorPushButtonMapper[ui->m_color_b] = qMakePair(analogModel,&analogModel->m_color);
    colorPushButtonMapper[ui->s_color_b] = qMakePair(analogModel,&analogModel->s_color);
    colorPushButtonMapper[ui->b_color_b] = qMakePair(generalModel,&generalModel->b_color);

//    Digital
    comboBoxMapper[ui->format_cb] = qMakePair(digitalModel, &digitalModel->format);
    lineEditMapper[ui->deliminer_le] = qMakePair(digitalModel, &digitalModel->deliminer);

//    Analog
    comboBoxMapper[ui->dial_mode_cb] = qMakePair(analogModel, &analogModel->dial_mode);
    comboBoxMapper[ui->dial_desc_cb] = qMakePair(analogModel, &analogModel->dial_description);
    colorPushButtonMapper[ui->dial_color_p] = qMakePair(generalModel, &generalModel->dial_color);


}
void SettingWindow::setPages(){

    ui->pushButton_1->setChecked(true);
    this->activeButton = ui->pushButton_1;
    ui->stackedWidget->setCurrentWidget(ui->page_1);

    button_to_pages[ui->pushButton_1] = ui->page_1;
    button_to_pages[ui->pushButton_2] = ui->page_2;
    button_to_pages[ui->pushButton_3] = ui->page_3;
    button_to_pages[ui->pushButton_4] = ui->page_4;

    QMapIterator<QPushButton*, QWidget*> i(button_to_pages);
    while (i.hasNext()) {
        i.next();
        connect(i.key(), SIGNAL(clicked(bool)), this, SLOT(changePage(bool)));
    }
}

void SettingWindow::comboBoxChanged(int index){
     QComboBox* cb = qobject_cast<QComboBox*>(sender());
     *comboBoxMapper[cb].second = index;
     comboBoxMapper[cb].first->settingChanged();
}

void SettingWindow::colorPushButtonClicked(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QColor old_color = *colorPushButtonMapper[button].second;
    QColor new_color = QColorDialog::getColor(old_color, this);
    *colorPushButtonMapper[button].second = new_color;

    button->setText(new_color.name());

    colorPushButtonMapper[button].first->settingChanged();
}

void SettingWindow::checkBoxChanged(int state){
    QCheckBox* cb = qobject_cast<QCheckBox*>(sender());
    *checkBoxMapper[cb].second = bool(state);
    checkBoxMapper[cb].first->settingChanged();

}
void SettingWindow::lineEditChanged(QString text){
    QLineEdit* cb = qobject_cast<QLineEdit*>(sender());
    *lineEditMapper[cb].second = text;
    lineEditMapper[cb].first->settingChanged();

}
void SettingWindow::sliderChanged(int value){
    QSlider* cb = qobject_cast<QSlider*>(sender());
    *sliderMapper[cb].second = value;
    sliderMapper[cb].first->settingChanged();
}

void SettingWindow::designDisabling(int arg1){
    bool disable;
    if(arg1 == 0)
        disable = false;
    else
        disable = true;

    ui->b_color_b->setDisabled(disable);
    ui->h_color_b->setDisabled(disable);
    ui->m_color_b->setDisabled(disable);
    ui->s_color_b->setDisabled(disable);
    ui->dial_color_p->setDisabled(disable);

    // owndesign
    if(arg1 == 0){
        generalModel->b_color =QColor(ui->b_color_b->text());
         analogModel->h_color = QColor(ui->h_color_b->text());
         analogModel->m_color = QColor(ui->m_color_b->text());
         analogModel->s_color = QColor(ui->s_color_b->text());
        generalModel->dial_color = QColor(ui->dial_color_p->text());
    } // default design
    else{
        generalModel->b_color.setNamedColor("#772953");
        generalModel->dial_color.setNamedColor("#2c001e");
        analogModel->h_color.setNamedColor("#000000") ;
        analogModel->m_color.setNamedColor("#000000") ;
        analogModel->s_color.setNamedColor("#e95420") ;

    }

}


void SettingWindow::loadSetting(){
    QMapIterator<QComboBox*,QPair<SettingModel*, int *>> cb(comboBoxMapper);
    while (cb.hasNext()) {
        cb.next();
        cb.key()->setCurrentIndex(*cb.value().second);
        connect(cb.key(), SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxChanged(int)));
    }

    QMapIterator<QSlider*,QPair<SettingModel*, int *>> sl(sliderMapper);
    while (sl.hasNext()) {
        sl.next();
        sl.key()->setValue(*sl.value().second);
        connect(sl.key(), SIGNAL(valueChanged(int)), this, SLOT(sliderChanged(int)));
    }

    QMapIterator<QCheckBox*, QPair<SettingModel*, bool *>> chb(checkBoxMapper);
    while (chb.hasNext()) {
        chb.next();
        chb.key()->setChecked(*chb.value().second);
        connect(chb.key(), SIGNAL(stateChanged(int)), this, SLOT(checkBoxChanged(int)));
    }

    QMapIterator<QPushButton*, QPair<SettingModel*, QColor*>> pb(colorPushButtonMapper);
    while (pb.hasNext()) {
        pb.next();
        pb.key()->setText(pb.value().second->name());
        connect(pb.key(), SIGNAL(clicked()), this, SLOT(colorPushButtonClicked()));
    }

    QMapIterator<QLineEdit*, QPair<SettingModel*, QString*>> le(lineEditMapper);
    while (le.hasNext()) {
        le.next();
        le.key()->setText(*le.value().second);
        connect(le.key(), SIGNAL(textChanged(QString)), this, SLOT(lineEditChanged(QString))); // maybe edited
    }

    designDisabling(ui->default_design_chb->isChecked());

    setLanguage();
}

void SettingWindow::setLanguage(){

    if(generalModel->language == -1){
        auto loc = QLocale();
        if(loc == QLocale::English)
            ui->language_cb_2->setCurrentIndex(0);
        else if(loc == QLocale::Czech)
            ui->language_cb_2->setCurrentIndex(1);
        else if(loc == QLocale::German)
            ui->language_cb_2->setCurrentIndex(3);
        else
            ui->language_cb_2->setCurrentIndex(0);
    }

    else
        ui->language_cb_2->setCurrentIndex(generalModel->language);
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



void SettingWindow::on_language_cb_2_currentIndexChanged(int index)
{
    generalModel->language = index;
    generalModel->saveSetting();

    emit languageChanged();
}

void SettingWindow::on_default_design_chb_stateChanged(int arg1)
{
    designDisabling(arg1);
}
