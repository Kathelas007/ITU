#include "digitalmodel.h"


DigitalModel * DigitalModel::instance;


DigitalModel::DigitalModel() : SettingModel()
{
    group = "Digital";
    loadSetting();

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
