#-------------------------------------------------
#
# Project created by QtCreator 2013-04-05T19:35:15
#
#-------------------------------------------------

QT       += core gui serialport widgets network

TARGET = SubscriberLed
TEMPLATE = app


SOURCES += main.cpp\
        guipanel.cpp 

HEADERS  += guipanel.h \

FORMS    += guipanel.ui

QT += widgets #Para QT4-->QT5

CONFIG += qwt analogwidgets qmqtt colorwidgets



