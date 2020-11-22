/********************************************************************************
** Form generated from reading UI file 'clockwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QString::fromUtf8("ClockWindow"));
        SettingWindow->resize(800, 600);
        centralwidget = new QWidget(SettingWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SettingWindow->setCentralWidget(centralwidget);

        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingWindow)
    {
        SettingWindow->setWindowTitle(QApplication::translate("SettingWindow", "SettingWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
