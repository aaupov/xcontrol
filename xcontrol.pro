QT += core gui 
TARGET = XControl
SOURCES += mainwindow.cpp \
           joytab.cpp \
           main.cpp \
           infoview.cpp \
           xcontrol.cpp \
           qjoystick.cpp
HEADERS += xcontrol.h \
           mainwindow.h \
           joytab.h \
           infoview.h \
           qjoystick.h
LIBS += -lSDL
win32 {
DEFINES += SDL_WIN
}
INCLUDEPATH += /usr/include/SDL
CONFIG += debug serialport
FORMS = Formbad.ui
