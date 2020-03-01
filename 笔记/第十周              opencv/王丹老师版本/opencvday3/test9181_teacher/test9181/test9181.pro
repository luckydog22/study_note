#-------------------------------------------------
#
# Project created by QtCreator 2019-09-18T16:18:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test9181
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += C++11

INCLUDEPATH += D:\farsight\opencv\opencvtest\install\include
INCLUDEPATH += D:\farsight\opencv\opencvtest\install\include\opencv
INCLUDEPATH += D:\farsight\opencv\opencvtest\install\include\opencv2
LIBS += D:/farsight/opencv/opencvtest/install/x86/mingw/lib/libopencv_*.a
