#-------------------------------------------------
#
# Project created by QtCreator 2019-09-20T09:18:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test920
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
CONFIG +=c++11
INCLUDEPATH += D:\opencv\opencv3.4-qt-install\install\include
INCLUDEPATH += D:\opencv\opencv3.4-qt-install\install\include\opencv
INCLUDEPATH += D:\opencv\opencv3.4-qt-install\install\include\opencv2
LIBS += D:/opencv/opencv3.4-qt-install/install/x86/mingw/lib/libopencv_*.a
