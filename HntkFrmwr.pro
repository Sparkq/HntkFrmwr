#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T21:08:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HntkFrmwr
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fxload/ezusb.c \
    fxload/fxload.c

HEADERS  += mainwindow.h \
    fxload/ezusb.h \
    fxload/fxload.h \
    libusb.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml



RESOURCES += \
    res.qrc

unix:!macx: LIBS += -L$$PWD/libs/libusb-armv7a/ -lusb

INCLUDEPATH += $$PWD/libs/libusb-armv7a
DEPENDPATH += $$PWD/libs/libusb-armv7a

unix:!macx: PRE_TARGETDEPS += $$PWD/libs/libusb-armv7a/libusb.a
