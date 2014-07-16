#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T22:29:22
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XinputRemoteClient
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    client.cpp

HEADERS  += widget.h \
    client.h

FORMS    += widget.ui
