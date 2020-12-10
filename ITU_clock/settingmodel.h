#ifndef SETTINGMODEL_H
#define SETTINGMODEL_H

#include <QObject>
#include <QWidget>
#include <QSettings>

#include <QString>

class SettingModel : public QObject
{
    Q_OBJECT

protected:
    QString group;
    QString company;
    QString product;

public:
    explicit SettingModel(QObject *parent = nullptr);
    void defaultSetting();

signals:

};

#endif // SETTINGMODEL_H
