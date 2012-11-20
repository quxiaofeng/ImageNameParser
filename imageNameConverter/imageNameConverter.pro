#-------------------------------------------------
#
# Project created by QtCreator 2012-11-16T18:52:02
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = imageNameConverter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ../algorithms/anyoption.cpp \
    ../algorithms/nameconverter.cpp

HEADERS += ../algorithms/anyoption.h \
    ../algorithms/nameconverter.h

OTHER_FILES += \
    README.md
