TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pokermanager.cpp \
    poker.cpp \
    judge.cpp \
    player.cpp \
    logic.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    pokermanager.h \
    poker.h \
    judge.h \
    player.h \
    logic.h

