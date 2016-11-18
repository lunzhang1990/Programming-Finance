#-------------------------------------------------
#
# Project created by QtCreator 2016-04-12T09:53:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = FinalPro
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stock.cpp \
    stockmarket.cpp \
    stocklist.cpp \
    bankaccount.cpp \
    stockaccount.cpp \
    mylabel.cpp \
    myline.cpp \
    qcustomplot.cpp

HEADERS  +=mainwindow.h \
    account.h \
    stock.h \
    stockmarket.h \
    stocklist.h \
    bankaccount.h \
    stockaccount.h \
    mylabel.h \
    myline.h \
    qcustomplot.h

FORMS    += mainwindow.ui

INCLUDEPATH +=/Applications/Matlab/MATLAB_R2016a.app/extern/include
LIBS += -L/Applications/Matlab/MATLAB_R2016a.app/bin/maci64 -lmx -leng -lmex
