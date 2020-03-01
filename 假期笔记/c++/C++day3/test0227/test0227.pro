TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    triange.cpp \
    student.cpp \
    time.cpp \
    vehicle.cpp \
    car.cpp \
    truck.cpp \
    point.cpp \
    circle.cpp \
    cylinder.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    triange.h \
    student.h \
    time.h \
    vehicle.h \
    car.h \
    truck.h \
    point.h \
    circle.h \
    cylinder.h

