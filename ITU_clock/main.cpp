#include "clockwindow.h"
#include "settingwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClockWindow w;
    w.show();

    SettingWindow s;
    s.show();

    return a.exec();
}
