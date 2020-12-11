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
    settings.setValue("mode", 1);
    settings.setValue("opacity", true);
    settings.setValue("hours", true);
    settings.setValue("minutes", true);
    settings.setValue("seconds",false);
    settings.setValue("design",1);
    settings.setValue("own", true);
    settings.setValue("h_color", QColor(Qt::black));
    settings.setValue("m_color", QColor(Qt::black));
    settings.setValue("s_color", QColor(Qt::black));
    settings.setValue("b_color", QColor(Qt::white));
    settings.endGroup();

    settings.beginGroup("Digital");
    settings.setValue("format", 1);
    settings.setValue("deliminer", "*");
    settings.endGroup();

    settings.beginGroup("Analog");
    settings.setValue("dial_mode", 1);
    settings.setValue("dial_description", 1);
    settings.setValue("dial_color", QColor(Qt::red));
    settings.endGroup();
}

