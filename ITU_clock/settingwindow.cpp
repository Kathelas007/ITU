#include "settingwindow.h"
#include "ui_settingwindow.h"

#include <stdio.h>
#include <cstdio>


SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);

       // ???
//       ui->deliminer_line_edit->setAlignment(Qt::AlignVCenter);

       ui->pushButton_1->setChecked(true);
       this->activeButton = ui->pushButton_1;
       ui->stackedWidget->setCurrentWidget(ui->page_1);

       button_to_pages[ui->pushButton_1] = ui->page_1;
       button_to_pages[ui->pushButton_2] = ui->page_2;
       button_to_pages[ui->pushButton_3] = ui->page_3;

       QMapIterator<QPushButton*, QWidget*> i(button_to_pages);
       while (i.hasNext()) {
           i.next();
           connect(i.key(), SIGNAL(clicked(bool)), this, SLOT(changePage(bool)));
       }
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::changePage(bool active){
   QPushButton* button = qobject_cast<QPushButton*>(sender());
   if(active == false and button == this->activeButton){
        button->setChecked(true);
        return;
   }

    this->activeButton->setChecked(false);
    this->activeButton = button;

    ui->stackedWidget->setCurrentWidget(button_to_pages[button]);
}
