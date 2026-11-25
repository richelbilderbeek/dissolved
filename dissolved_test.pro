# Tests for the game, with code coverage measured in CI
# Run with: ./dissolved_test

#-------------------------------------------------
#
# Project created by QtCreator 2014-06-29T07:45:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dissolved_test
TEMPLATE = app


SOURCES += dissolved_test.cpp\
        dissolvedwidget.cpp

HEADERS  += dissolvedwidget.h

FORMS    +=

RESOURCES += \
    dissolved.qrc \
    photos1.qrc \
    photos2.qrc

QT += testlib
CONFIG += console
CONFIG -= app_bundle
