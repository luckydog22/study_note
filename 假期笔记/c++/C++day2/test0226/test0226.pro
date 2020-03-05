TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    student.cpp \
    teacher.cpp \
    book.cpp \
    studentfriend.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    student.h \
    teacher.h \
    book.h \
    studentfriend.h

