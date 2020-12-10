#ifndef GENERALMODEL_H
#define GENERALMODEL_H

#include "settingmodel.h"

#include <QColor>


class GeneralModel : SettingModel
{
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

    QColor h_color;
    QColor m_color;
    QColor s_color;
    QColor b_color;

};

#endif // GENERALMODEL_H
