#ifndef GENERALMODEL_H
#define GENERALMODEL_H

#include "settingmodel.h"

#include <QColor>


class GeneralModel : SettingModel
{
    GeneralModel();
    ~GeneralModel(){};

    static GeneralModel* instance;
    void loadSetting();
    void saveSetting(QString key,QString value);
public:
    static GeneralModel * getInstance();

    int mode;
    int opacity;

    bool hours;
    bool minutes;
    bool  seconds;

    int design;
    bool own;

    QColor h_color;
    QColor m_color;
    QColor s_color;
    QColor b_color;

};

#endif // GENERALMODEL_H
