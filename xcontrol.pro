QT += core gui
TARGET = XControl
SOURCES += mainwindow.cpp \
           transmatrix.cpp \
           main.cpp \
           infoview.cpp \
           xcontrol.cpp
HEADERS += xcontrol.h \
           mainwindow.h \
           transmatrix.h \
           infoview.h
LIBS += -lSDL
win32 {
DEFINES += SDL_WIN
}
INCLUDEPATH += /usr/include/SDL
