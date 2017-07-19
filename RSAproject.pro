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
    randomgenerator.cpp \
    gamal.cpp

HEADERS += \
    rsa.h \
    primalitytest.h \
    bitvector.h \
    randomgenerator.h \
    gamal.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/release/ -lntl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/debug/ -lntl
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/ -lntl

INCLUDEPATH += $$PWD/../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../usr/include
