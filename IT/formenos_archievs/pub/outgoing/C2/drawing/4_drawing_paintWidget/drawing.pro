#-------------------------------------------------
#
# Project created by QtCreator 2014-11-12T16:36:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drawing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintwidget.cpp

HEADERS  += mainwindow.h \
    paintwidget.h

FORMS    += mainwindow.ui
