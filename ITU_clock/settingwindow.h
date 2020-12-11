#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QSlider>
#include <QMap>
#include <QPair>

#include "generalmodel.h"
#include "digitalmodel.h"
#include "analogmodel.h"
#include "settingmodel.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    GeneralModel * generalModel;
    DigitalModel* digitalModel;
    AnalogModel * analogModel;

    void loadSetting();
    void setPages();
    void setMappers();

    QMap<QComboBox*, QPair<SettingModel*, int*>> comboBoxMapper;
    QMap<QPushButton*, QPair<SettingModel*,QColor*>> colorPushButtonMapper;
    QMap<QCheckBox*, QPair<SettingModel*,bool *>> checkBoxMapper;
    QMap<QLineEdit*, QPair<SettingModel*,QString*>> lineEditMapper;
    QMap<QSlider*, QPair<SettingModel*,int*>> sliderMapper;

    Q_OBJECT
public:
   explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

public slots:
   void changePage(bool);

private slots:
   void comboBoxChanged(int);
   void colorPushButtonClicked();
   void checkBoxChanged(int);
   void lineEditChanged(QString);
   void sliderChanged(int);

private:
       Ui::SettingWindow *ui;
       QPushButton* activeButton;
       QMap<QPushButton *, QWidget *> button_to_pages;
};

#endif // SETTINGWINDOW_H
