#-------------------------------------------------
#
# Project created by QtCreator 2013-01-11T14:39:05
#
#-------------------------------------------------

QT       += core gui
QT       += network


TARGET = test1
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    networksetup.cpp \
    login.cpp \
    tcpconnect.cpp

HEADERS  += mainwindow.h \
    networksetup.h \
    login.h \
    tcpconnect.h

FORMS    += mainwindow.ui \
    networksetup.ui \
    login.ui
