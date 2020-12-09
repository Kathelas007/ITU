#include "generalmodel.h"

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
