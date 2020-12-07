#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPushButton>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    Q_OBJECT
   public:
       explicit SettingWindow(QWidget *parent = nullptr);
        ~SettingWindow();

   public slots:
       void changePage(bool);

   private:
       Ui::SettingWindow *ui;
       QPushButton* activeButton;
       QMap<QPushButton *, QWidget *> button_to_pages;
};

#endif // SETTINGWINDOW_H
