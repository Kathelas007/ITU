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
    h_color = settings.value("h_color").value<QColor>();
    m_color = settings.value("m_color").value<QColor>();
    s_color = settings.value("s_color").value<QColor>();
    settings.endGroup();
}

void AnalogModel::saveSetting(){
    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, company, product);
    settings.beginGroup(group);
    settings.setValue("dial_mode", dial_mode);
    settings.setValue("dial_description", dial_description);
    settings.setValue("h_color", h_color);
    settings.setValue("m_color", m_color);
    settings.setValue("s_color", s_color);
    settings.endGroup();
}
