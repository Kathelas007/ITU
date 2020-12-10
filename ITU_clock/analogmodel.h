#ifndef ANALOGMODEL_H
#define ANALOGMODEL_H

#include <QObject>
#include "settingmodel.h"

class AnalogModel : public QObject, SettingModel

{
    Q_OBJECT
public:
    explicit AnalogModel(QObject *parent = nullptr);

signals:

};

#endif // ANALOGMODEL_H
