TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    circle.cpp \
    table.cpp \
    roundtable.cpp \
    base.cpp \
    leader.cpp \
    engineer.cpp \
    boss.cpp \
    shap.cpp \
    triangle.cpp \
    circleshap.cpp \
    square.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    circle.h \
    table.h \
    roundtable.h \
    base.h \
    leader.h \
    engineer.h \
    boss.h \
    shap.h \
    triangle.h \
    circleshap.h \
    square.h

