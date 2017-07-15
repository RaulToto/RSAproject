QT += core
QT -= gui

CONFIG += c++11

TARGET = RSAproject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    rsa.cpp \
    primalitytest.cpp \
    randomgeneration.cpp

HEADERS += \
    rsa.h \
    primalitytest.h \
    randomgeneration.h