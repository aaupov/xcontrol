QT += core gui
TARGET = XControl
SOURCES += main.cpp 

HEADERS += xcontrol.h 
LIBS += -lSDL
win32 {
DEFINES += SDL_WIN
}
