#include "analogmodel.h"

AnalogModel * AnalogModel::instance;

AnalogModel::AnalogModel()
{
    group = "Analog";
    loadSetting();
}

AnalogModel* AnalogModel::getInstance(){
    if(!instance)
        instance = new AnalogModel();

    return instance;
}

void AnalogModel::loadSetting(){
    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, company, product);
    settings.beginGroup(group);
    dial_mode = settings.value("dial_mode").toInt();
    dial_description = settings.value("dial_description").toInt();
    dial_color = settings.value("dial_color").value<QColor>();
    settings.endGroup();
}

