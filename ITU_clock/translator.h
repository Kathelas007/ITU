#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QGuiApplication>
#include <QTranslator>

#include "generalmodel.h"

class Translator : public QObject
{
    Q_OBJECT
public:
    explicit Translator(QGuiApplication* app);

private:
    QGuiApplication* a;
    GeneralModel * gm;
    QTranslator t;

    void setLanguageFromGeneralModel();

signals:

public slots:
    void updateLanguage();

};

#endif // TRANSLATOR_H
