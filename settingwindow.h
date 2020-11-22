#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QMainWindow>
#include <QMap>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class SettingWindow; }
QT_END_NAMESPACE

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
