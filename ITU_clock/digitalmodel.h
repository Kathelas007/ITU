#ifndef DIGITALMODEL_H
#define DIGITALMODEL_H

#include "settingmodel.h"
#include <QObject>

class DigitalModel : public SettingModel
{
     Q_OBJECT

private:
    DigitalModel();
    static DigitalModel* instance;
    void loadSetting();


public:
    void saveSetting();
    static DigitalModel * getInstance();

    int format;
    QString deliminer;


};

#endif // DIGITALMODEL_H
