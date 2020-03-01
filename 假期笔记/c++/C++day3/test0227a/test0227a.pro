TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    animal.cpp \
    sheep.cpp \
    tiger.cpp \
    developer.cpp \
    manito.cpp \
    smallbird.cpp \
    company.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    animal.h \
    sheep.h \
    tiger.h \
    developer.h \
    manito.h \
    smallbird.h \
    company.h

