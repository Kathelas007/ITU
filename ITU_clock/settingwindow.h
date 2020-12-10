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

#include "generalmodel.h"
#include "digitalmodel.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    GeneralModel * generalModel;
    DigitalModel* digitalModel;

    void loadSetting();
    void setPages();
    void setMappers();

    QMap<QComboBox*, int*> comboBoxMapper;
    QMap<QPushButton*, QColor*> colorPushButtonMapper;
    QMap<QCheckBox*, bool *> checkBoxMapper;
    QMap<QLineEdit*, QString*> lineEditMapper;
    QMap<QSlider*, int*> sliderMapper;

    Q_OBJECT
public:
   explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

public slots:
   void changePage(bool);

private slots:
   void comboBoxChanged(int);
   void colorPushButtonClicked(bool);
   void checkBoxChanged(int);
   void lineEditChanged(QString);
   void sliderChanged(int);

private:
       Ui::SettingWindow *ui;
       QPushButton* activeButton;
       QMap<QPushButton *, QWidget *> button_to_pages;
};

#endif // SETTINGWINDOW_H
