#include "settingmodel.h"

SettingModel::SettingModel(QObject *parent) : QObject(parent)
{
    company = "StackUndeflow";
        product = "ITU_Clock";

        QSettings settings(QSettings::NativeFormat, QSettings::UserScope, company, product);
        if(settings.allKeys().length() == 0)
            defaultSetting();
}

void SettingModel::defaultSetting(){
    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, company, product);
    settings.beginGroup("General");
    settings.setValue("mode", 0);
    settings.setValue("opacity", 206);
    settings.setValue("hours", true);
    settings.setValue("minutes", true);
    settings.setValue("seconds",true);
    settings.setValue("design",true);
    settings.setValue("dial_color", QColor("#2c001e"));
    settings.setValue("b_color", QColor("#772953"));
    settings.setValue("language", -1);
    settings.endGroup();

    settings.beginGroup("Digital");
    settings.setValue("format", 1);
    settings.setValue("deliminer", ":");
    settings.endGroup();

    settings.beginGroup("Analog");
    settings.setValue("dial_mode", 0);
    settings.setValue("dial_description", 1);
    settings.setValue("h_color", QColor("#000000"));
    settings.setValue("m_color", QColor("#000000"));
    settings.setValue("s_color", QColor("e95420"));
    settings.endGroup();
}

