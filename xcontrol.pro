QT += core gui
TARGET = XControl
SOURCES += main.cpp \
           mainwindow.cpp \
           transmatrix.cpp
HEADERS += xcontrol.h \
           mainwindow.h \
           transmatrix.h
LIBS += -lSDL
win32 {
DEFINES += SDL_WIN
}
INCLUDEPATH += /usr/include/SDL
CXX=clang++
