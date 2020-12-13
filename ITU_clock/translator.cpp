#include "translator.h"
#include "generalmodel.h"

#include <QGuiApplication>
#include <QDebug>

Translator::Translator(QGuiApplication* app)
{
    a = app;
    gm = GeneralModel::getInstance();

    if(gm->language == -1){
        QLocale loc = QLocale();

        if(loc.language() == QLocale::Czech)
            t.load(":/ITU_clock_cs_CZ");

        else if(loc.language() == QLocale::German)
            t.load(":/ITU_clock_de_DE");

        if(loc.language() != QLocale::English)
            a->installTranslator(&t);
    } else {
        setLanguageFromGeneralModel();
    }
}

void Translator::setLanguageFromGeneralModel(){

    a->removeTranslator(&t);

    if(gm->language == 1){
        t.load(":/ITU_clock_cs_CZ");
    } else if(gm->language == 2)
        t.load(":/ITU_clock_de_DE");

    if(gm->language != 0){
     a->installTranslator(&t);
    }
}

void Translator::updateLanguage(){
    setLanguageFromGeneralModel();
}
