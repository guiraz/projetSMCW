#-------------------------------------------------
#
# Project created by QtCreator 2013-04-17T17:51:05
#
#-------------------------------------------------

QT       += core gui

TARGET = rando
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addrando.cpp \
    randonnee.cpp

HEADERS  += mainwindow.h \
    addrando.h \
    randonnee.h \
    enumeration.h

DESTDIR = $$_PRO_FILE_PWD_

OUT_PWD = $$_PRO_FILE_PWD_

QMAKE_DISTCLEAN += -rf build/ rando.pro.user

MOC_DIR = build/moc

OBJECTS_DIR = build/obj