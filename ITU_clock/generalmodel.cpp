#include "generalmodel.h"

#include <QDebug>
#include <QSettings>

GeneralModel * GeneralModel::instance;


GeneralModel::GeneralModel() : SettingModel()
{
    group = "General";
    loadSetting();

    connect(this, SIGNAL(settingChanged()), this, SLOT(saveSetting()));
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
    dial_color = settings.value("dial_color").value<QColor>();
    b_color = settings.value("b_color").value<QColor>();
    language = settings.value("language").toInt();
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
    settings.setValue("dial_color", dial_color);
    settings.setValue("b_color", b_color);
    settings.setValue("language", language);
    settings.endGroup();
}
