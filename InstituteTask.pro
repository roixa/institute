#-------------------------------------------------
#
# Project created by QtCreator 2014-11-12T17:43:16
#
#-------------------------------------------------

QT       += core gui
 QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InstituteTask
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fileparser.cpp \
    datamanager.cpp \
    gaussfunc.cpp \
    perceptron.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    fileparser.h \
    datamanager.h \
    gaussfunc.h \
    perceptron.h \
    qcustomplot.h

FORMS    += mainwindow.ui
