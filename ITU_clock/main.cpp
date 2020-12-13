#include "clockwindow.h"
#include "settingwindow.h"
#include "settingmodel.h"
#include "generalmodel.h"

#include <QDebug>
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;

    QLocale loc = QLocale();

    if(loc.language() == QLocale::Czech)
        t.load(":/ITU_clock_cs_CZ");

    else if(loc.language() == QLocale::German)
        t.load(":/ITU_clock_de_DE");

    if(loc.language() != QLocale::English)
        a.installTranslator(&t);

//    ClockWindow w;
//    w.show();

    SettingWindow s;
    s.show();

    return a.exec();
}
