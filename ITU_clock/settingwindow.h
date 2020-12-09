#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPushButton>

#include "generalmodel.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    GeneralModel * generalModel;
    void loadSetting();
    void setPages();

    Q_OBJECT
public:
   explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

public slots:
   void changePage(bool);

private slots:
       void on_color_bg_button_clicked();

private:
       Ui::SettingWindow *ui;
       QPushButton* activeButton;
       QMap<QPushButton *, QWidget *> button_to_pages;
};

#endif // SETTINGWINDOW_H
