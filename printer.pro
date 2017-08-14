#-------------------------------------------------
#
# Project created by QtCreator 2017-05-02T21:39:45
#
#-------------------------------------------------

QT       += core gui
QT += sql
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = printer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    printer.cpp \
    component.cpp \
    printerdao.cpp \
    databasemanager.cpp \
    componentdao.cpp \
    printerlistwidget.cpp \
    addprinterform.cpp \
    printermodel.cpp \
    printerform.cpp \
    addcomponentform.cpp \
    componentcheck.cpp

HEADERS  += mainwindow.h \
    printer.h \
    component.h \
    printerdao.h \
    databasemanager.h \
    componentdao.h \
    printerlistwidget.h \
    addprinterform.h \
    printermodel.h \
    printerform.h \
    addcomponentform.h \
    componentcheck.h

FORMS    += mainwindow.ui \
    printerlistwidget.ui \
    addprinterform.ui \
    printerform.ui \
    addcomponentform.ui \
    componentcheck.ui
