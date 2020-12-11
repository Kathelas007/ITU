#ifndef ANALOGMODEL_H
#define ANALOGMODEL_H

#include "settingmodel.h"
#include <QObject>
#include <QColor>

class AnalogModel : public SettingModel
{
    Q_OBJECT

private:
   AnalogModel();
   static AnalogModel* instance;
   void loadSetting();


public:
   void saveSetting();
   static AnalogModel * getInstance();

   int dial_mode;
   int dial_description;
   QColor dial_color;

};

#endif // ANALOGMODEL_H
