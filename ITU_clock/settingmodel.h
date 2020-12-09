#ifndef SETTINGMODEL_H
#define SETTINGMODEL_H

#include <QObject>
#include <QWidget>
#include <QSettings>

#include <QString>

class SettingModel
{
protected:
    QString group;
    QString company;
    QString product;

public:
    SettingModel();
    void defaultSetting();
};

#endif // SETTINGMODEL_H
