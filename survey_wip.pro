#-------------------------------------------------
#
# Project created by QtCreator 2014-05-19T13:13:36
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = survey_wip
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    dlg1.cpp \
    dlg2.cpp \
    mw.cpp \
    data.cpp \
    querycontainer.cpp \
    dlg4.cpp

HEADERS  += \
    dlg1.h \
    dlg2.h \
    mw.h \
    data.h \
    querycontainer.h \
    dlg4.h

FORMS    += \
    dlg1.ui \
    dlg2.ui \
    mw.ui \
    dlg4.ui
