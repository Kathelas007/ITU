/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *nav_bar_frame;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_9;
    QFrame *mode_frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QFrame *opacity_frame;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QFrame *mode_frame_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;
    QFrame *color_frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QPushButton *pushButton_6;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_7;
    QFrame *mode_frame_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QComboBox *comboBox_2;
    QFrame *opacity_frame_2;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_8;
    QFrame *mode_frame_3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_16;
    QComboBox *comboBox_3;
    QFrame *mode_frame_4;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_23;
    QComboBox *comboBox_4;
    QFrame *mode_frame_5;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_24;
    QComboBox *comboBox_5;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QString::fromUtf8("SettingWindow"));
        SettingWindow->resize(800, 500);
        SettingWindow->setMinimumSize(QSize(800, 500));
        SettingWindow->setMaximumSize(QSize(800, 500));
        centralwidget = new QWidget(SettingWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        nav_bar_frame = new QFrame(centralwidget);
        nav_bar_frame->setObjectName(QString::fromUtf8("nav_bar_frame"));
        nav_bar_frame->setMinimumSize(QSize(100, 0));
        nav_bar_frame->setMaximumSize(QSize(100, 16777215));
        nav_bar_frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        nav_bar_frame->setFrameShape(QFrame::NoFrame);
        nav_bar_frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(nav_bar_frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_1 = new QPushButton(nav_bar_frame);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(0, 40));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"  background-color: rgb(255, 255, 255);\n"
"    border: 0px s;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(243, 243, 243);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  background-color: rgb(233, 84, 32);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        pushButton_1->setCheckable(true);

        verticalLayout->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(nav_bar_frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{	background-color: rgb(255, 255, 255);\n"
"    border: 0px s;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(243, 243, 243);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  background-color: rgb(233, 84, 32);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        pushButton_2->setCheckable(true);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(nav_bar_frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{	background-color: rgb(255, 255, 255);\n"
"    border: 0px s;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(243, 243, 243);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  background-color: rgb(233, 84, 32);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        pushButton_3->setCheckable(true);

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(nav_bar_frame);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->setFrameShadow(QFrame::Raised);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        verticalLayout_4 = new QVBoxLayout(page_1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame_2 = new QFrame(page_1);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        mode_frame = new QFrame(frame_2);
        mode_frame->setObjectName(QString::fromUtf8("mode_frame"));
        mode_frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        mode_frame->setFrameShape(QFrame::StyledPanel);
        mode_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(mode_frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(mode_frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(mode_frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(120, 0));
        comboBox->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout_9->addWidget(mode_frame);

        opacity_frame = new QFrame(frame_2);
        opacity_frame->setObjectName(QString::fromUtf8("opacity_frame"));
        opacity_frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        opacity_frame->setFrameShape(QFrame::StyledPanel);
        opacity_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(opacity_frame);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_2 = new QLabel(opacity_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        horizontalSlider = new QSlider(opacity_frame);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider);


        verticalLayout_9->addWidget(opacity_frame);

        mode_frame_6 = new QFrame(frame_2);
        mode_frame_6->setObjectName(QString::fromUtf8("mode_frame_6"));
        mode_frame_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        mode_frame_6->setFrameShape(QFrame::StyledPanel);
        mode_frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(mode_frame_6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(mode_frame_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        checkBox_3 = new QCheckBox(mode_frame_6);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_9->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(mode_frame_6);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_9->addWidget(checkBox_2);

        checkBox_4 = new QCheckBox(mode_frame_6);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        horizontalLayout_9->addWidget(checkBox_4);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_9->addWidget(mode_frame_6);

        color_frame = new QFrame(frame_2);
        color_frame->setObjectName(QString::fromUtf8("color_frame"));
        color_frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        color_frame->setFrameShape(QFrame::StyledPanel);
        color_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(color_frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(color_frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        checkBox = new QCheckBox(color_frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(100, 0));
        checkBox->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(checkBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(color_frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        pushButton = new QPushButton(color_frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(100, 0));
        pushButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(color_frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        pushButton_4 = new QPushButton(color_frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(100, 0));
        pushButton_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(color_frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        pushButton_5 = new QPushButton(color_frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(100, 0));
        pushButton_5->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(color_frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        pushButton_6 = new QPushButton(color_frame);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(100, 0));
        pushButton_6->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_9->addWidget(color_frame);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);


        verticalLayout_4->addWidget(frame_2);

        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_3);
        verticalLayout_7->setSpacing(20);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        mode_frame_2 = new QFrame(frame_3);
        mode_frame_2->setObjectName(QString::fromUtf8("mode_frame_2"));
        mode_frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        mode_frame_2->setFrameShape(QFrame::StyledPanel);
        mode_frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(mode_frame_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(mode_frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        comboBox_2 = new QComboBox(mode_frame_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(120, 0));
        comboBox_2->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_8->addWidget(comboBox_2);


        verticalLayout_7->addWidget(mode_frame_2);

        opacity_frame_2 = new QFrame(frame_3);
        opacity_frame_2->setObjectName(QString::fromUtf8("opacity_frame_2"));
        opacity_frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        opacity_frame_2->setFrameShape(QFrame::StyledPanel);
        opacity_frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_20 = new QHBoxLayout(opacity_frame_2);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_10 = new QLabel(opacity_frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_20->addWidget(label_10);

        lineEdit = new QLineEdit(opacity_frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(120, 0));
        lineEdit->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_20->addWidget(lineEdit);


        verticalLayout_7->addWidget(opacity_frame_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);


        verticalLayout_6->addWidget(frame_3);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_10 = new QVBoxLayout(page_3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        frame_4 = new QFrame(page_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        mode_frame_3 = new QFrame(frame_4);
        mode_frame_3->setObjectName(QString::fromUtf8("mode_frame_3"));
        mode_frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        mode_frame_3->setFrameShape(QFrame::StyledPanel);
        mode_frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_14 = new QHBoxLayout(mode_frame_3);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_16 = new QLabel(mode_frame_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_14->addWidget(label_16);

        comboBox_3 = new QComboBox(mode_frame_3);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(120, 0));
        comboBox_3->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_14->addWidget(comboBox_3);


        verticalLayout_8->addWidget(mode_frame_3);

        mode_frame_4 = new QFrame(frame_4);
        mode_frame_4->setObjectName(QString::fromUtf8("mode_frame_4"));
        mode_frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        mode_frame_4->setFrameShape(QFrame::StyledPanel);
        mode_frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_21 = new QHBoxLayout(mode_frame_4);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_23 = new QLabel(mode_frame_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_21->addWidget(label_23);

        comboBox_4 = new QComboBox(mode_frame_4);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setMinimumSize(QSize(120, 0));
        comboBox_4->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_21->addWidget(comboBox_4);


        verticalLayout_8->addWidget(mode_frame_4);

        mode_frame_5 = new QFrame(frame_4);
        mode_frame_5->setObjectName(QString::fromUtf8("mode_frame_5"));
        mode_frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        mode_frame_5->setFrameShape(QFrame::StyledPanel);
        mode_frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_22 = new QHBoxLayout(mode_frame_5);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_24 = new QLabel(mode_frame_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_22->addWidget(label_24);

        comboBox_5 = new QComboBox(mode_frame_5);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setMinimumSize(QSize(120, 0));
        comboBox_5->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_22->addWidget(comboBox_5);


        verticalLayout_8->addWidget(mode_frame_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_4);


        verticalLayout_10->addWidget(frame_4);

        stackedWidget->addWidget(page_3);

        horizontalLayout->addWidget(stackedWidget);

        SettingWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SettingWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        SettingWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SettingWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SettingWindow->setStatusBar(statusbar);

        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingWindow)
    {
        SettingWindow->setWindowTitle(QApplication::translate("SettingWindow", "MainWindow", nullptr));
        pushButton_1->setText(QApplication::translate("SettingWindow", "General", nullptr));
        pushButton_2->setText(QApplication::translate("SettingWindow", "Digital", nullptr));
        pushButton_3->setText(QApplication::translate("SettingWindow", "Analog", nullptr));
        label->setText(QApplication::translate("SettingWindow", "Mode", nullptr));
        comboBox->setItemText(0, QApplication::translate("SettingWindow", "Digital", nullptr));
        comboBox->setItemText(1, QApplication::translate("SettingWindow", "Analog", nullptr));

        label_2->setText(QApplication::translate("SettingWindow", "Opacity", nullptr));
        label_3->setText(QApplication::translate("SettingWindow", "Display", nullptr));
        checkBox_3->setText(QApplication::translate("SettingWindow", "Hours", nullptr));
        checkBox_2->setText(QApplication::translate("SettingWindow", "Minutes", nullptr));
        checkBox_4->setText(QApplication::translate("SettingWindow", "Seconds", nullptr));
        label_4->setText(QApplication::translate("SettingWindow", "Own design", nullptr));
        checkBox->setText(QString());
        label_5->setText(QApplication::translate("SettingWindow", "Backgroud color", nullptr));
        pushButton->setText(QApplication::translate("SettingWindow", "#fff", nullptr));
        label_6->setText(QApplication::translate("SettingWindow", "Hour color", nullptr));
        pushButton_4->setText(QApplication::translate("SettingWindow", "#fff", nullptr));
        label_7->setText(QApplication::translate("SettingWindow", "Minute color", nullptr));
        pushButton_5->setText(QApplication::translate("SettingWindow", "#fff", nullptr));
        label_8->setText(QApplication::translate("SettingWindow", "Second color", nullptr));
        pushButton_6->setText(QApplication::translate("SettingWindow", "#fff", nullptr));
        label_9->setText(QApplication::translate("SettingWindow", "Format", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("SettingWindow", "12 h", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("SettingWindow", "24 h", nullptr));

        label_10->setText(QApplication::translate("SettingWindow", "Deliminer", nullptr));
        lineEdit->setText(QApplication::translate("SettingWindow", ":", nullptr));
        label_16->setText(QApplication::translate("SettingWindow", "Dial mode", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("SettingWindow", "Hours", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("SettingWindow", "Minutes", nullptr));
        comboBox_3->setItemText(2, QApplication::translate("SettingWindow", "None", nullptr));

        label_23->setText(QApplication::translate("SettingWindow", "Dial description", nullptr));
        comboBox_4->setItemText(0, QApplication::translate("SettingWindow", "Latin Numbers", nullptr));
        comboBox_4->setItemText(1, QApplication::translate("SettingWindow", "Rome Numbers", nullptr));
        comboBox_4->setItemText(2, QApplication::translate("SettingWindow", "None", nullptr));

        label_24->setText(QApplication::translate("SettingWindow", "Dial color", nullptr));
        comboBox_5->setItemText(0, QApplication::translate("SettingWindow", "Latin Numbers", nullptr));
        comboBox_5->setItemText(1, QApplication::translate("SettingWindow", "Rome Numbers", nullptr));
        comboBox_5->setItemText(2, QApplication::translate("SettingWindow", "None", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
