/********************************************************************************
** Form generated from reading UI file 'clockwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKWINDOW_H
#define UI_CLOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClockWindow
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *ClockWindow)
    {
        if (ClockWindow->objectName().isEmpty())
            ClockWindow->setObjectName(QString::fromUtf8("ClockWindow"));
        ClockWindow->resize(800, 600);
        centralwidget = new QWidget(ClockWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ClockWindow->setCentralWidget(centralwidget);

        retranslateUi(ClockWindow);

        QMetaObject::connectSlotsByName(ClockWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClockWindow)
    {
        ClockWindow->setWindowTitle(QApplication::translate("ClockWindow", "ClockWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClockWindow: public Ui_ClockWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKWINDOW_H
