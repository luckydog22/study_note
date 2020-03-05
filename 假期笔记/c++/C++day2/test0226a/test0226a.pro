TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    student.cpp \
    teacher.cpp \
    oneinstance.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    student.h \
    teacher.h \
    oneinstance.h

