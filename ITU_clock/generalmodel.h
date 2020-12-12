#ifndef GENERALMODEL_H
#define GENERALMODEL_H

#include "settingmodel.h"

#include <QColor>
#include <QObject>

class GeneralModel : public SettingModel
{
    Q_OBJECT
    GeneralModel();

    static GeneralModel* instance;
    void loadSetting();

public:
    void saveSetting();

    static GeneralModel * getInstance();

    // todo add window size
    int mode;
    int opacity;

    bool hours;
    bool minutes;
    bool  seconds;

    int design;
    bool own;

    QColor dial_color;
    QColor b_color;


};

#endif // GENERALMODEL_H
