#include "clockwindow.h"
#include "settingwindow.h"
#include "settingmodel.h"
#include "generalmodel.h"
#include "translator.h"
#include "main.h"

#include <QDebug>
#include <QApplication>
#include <QTranslator>

Translator *translator;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    translator = new Translator(&a);

    ClockWindow w;
    w.show();

//    SettingWindow s;
//    s.show();

    return a.exec();
}
