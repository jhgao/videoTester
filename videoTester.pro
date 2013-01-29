#-------------------------------------------------
#
# Project created by QtCreator 2013-01-29T09:40:55
#
#-------------------------------------------------

QT       += core gui phonon

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = videoTester
TEMPLATE = app


SOURCES += main.cpp\
        videotesterwindow.cpp \
    gui/droplineedit.cpp

HEADERS  += videotesterwindow.h \
    gui/droplineedit.h

FORMS    += videotesterwindow.ui
