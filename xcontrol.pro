QT += core gui 
TARGET = XControl
SOURCES += mainwindow.cpp \
           joytab.cpp \
           main.cpp \
           infoview.cpp \
           xcontrol.cpp \
           qjoystick.cpp \
           interface.cpp
HEADERS += xcontrol.h \
           mainwindow.h \
           joytab.h \
           infoview.h \
           qjoystick.h \
           interface.h
LIBS += -lSDL
win32 {
DEFINES += SDL_WIN
}
INCLUDEPATH += /usr/include/SDL
CONFIG += debug serialport static
FORMS = interface.ui
