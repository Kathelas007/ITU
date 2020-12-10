#include "generalmodel.h"

#include <QDebug>
#include <QSettings>

GeneralModel * GeneralModel::instance;


GeneralModel::GeneralModel() : SettingModel()
{
    group = "General";
    loadSetting();
}

GeneralModel* GeneralModel::getInstance(){
    if(!instance)
        instance = new GeneralModel();

    return instance;
}

void GeneralModel::loadSetting(){
    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, company, product);
    settings.beginGroup(group);
    mode = settings.value("mode").toInt();
    opacity = settings.value("opacity").toInt();
    hours = settings.value("hours").toBool();
    minutes = settings.value("minutes").toBool();
    seconds = settings.value("seconds").toBool();
    design = settings.value("design").toInt();
    own = settings.value("own").toBool();
    h_color = settings.value("h_color").value<QColor>();
    m_color = settings.value("m_color").value<QColor>();
    s_color = settings.value("s_color").value<QColor>();
    b_color = settings.value("b_color").value<QColor>();
    settings.endGroup();
}

void GeneralModel::saveSetting(){
    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, company, product);
    settings.beginGroup(group);
    settings.setValue("mode", mode);
    settings.setValue("opacity", opacity);
    settings.setValue("hours", hours);
    settings.setValue("minutes", minutes);
    settings.setValue("seconds", seconds);
    settings.setValue("design", design);
    settings.setValue("own", own);
    settings.setValue("h_color", h_color);
    settings.setValue("m_color", m_color);
    settings.setValue("s_color", s_color);
    settings.setValue("b_color", b_color);
    settings.endGroup();
}
