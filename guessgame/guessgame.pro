#-------------------------------------------------
#
# Project created by QtCreator 2017-09-27T16:42:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = guessgame
TEMPLATE = app


SOURCES += main.cpp\
        guessmain.cpp \
    mybutton.cpp \
    guessplay.cpp

HEADERS  += guessmain.h \
    mybutton.h \
    guessplay.h

FORMS    += guessmain.ui

CONFIG  +=C++11

RESOURCES += \
    ../image/image.qrc

DISTFILES +=
