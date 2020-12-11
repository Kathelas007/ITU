#include "clockwindow.h"
#include "settingwindow.h"
#include "settingmodel.h"
#include "generalmodel.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    ClockWindow w;
//    w.show();

    SettingWindow s;
    s.show();

    return a.exec();
}
