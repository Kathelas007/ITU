QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += quick

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analogclock.cpp \
    analogmodel.cpp \
    digitalclock.cpp \
    digitalmodel.cpp \
    generalmodel.cpp \
    main.cpp \
    clockwindow.cpp \
    settingmodel.cpp \
    settingwindow.cpp \
    translator.cpp

HEADERS += \
    analogclock.h \
    analogmodel.h \
    clockwindow.h \
    digitalclock.h \
    digitalmodel.h \
    generalmodel.h \
    main.h \
    settingmodel.h \
    settingwindow.h \
    translator.h

FORMS += \
    settingwindow.ui

TRANSLATIONS += \
    ITU_clock_cs_CZ.ts
    ITU_clock_de_DE.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc \
    translation.qrc

DISTFILES += \
    ITU_clock_de_DE.ts
