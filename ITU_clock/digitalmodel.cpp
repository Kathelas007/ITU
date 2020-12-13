#include "digitalmodel.h"
#include "generalmodel.h"

#include <iostream>

#include <QDebug>

DigitalModel * DigitalModel::instance;


DigitalModel::DigitalModel() : SettingModel()
{
    group = "Digital";
    loadSetting();

    connect(this, SIGNAL(settingChanged()), this, SLOT(saveSetting()));
}

DigitalModel* DigitalModel::getInstance(){
    if(!instance)
        instance = new DigitalModel();

    return instance;
}

void DigitalModel::loadSetting(){
    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, company, product);
    settings.beginGroup(group);
    format = settings.value("format").toInt();
    deliminer = settings.value("deliminer").toString();
    settings.endGroup();
}

void DigitalModel::saveSetting(){
    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, company, product);
    settings.beginGroup(group);
    settings.setValue("format", format);
    settings.setValue("deliminer", deliminer);
    settings.endGroup();
}
