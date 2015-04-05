#-------------------------------------------------
#
# Project created by QtCreator 2015-01-17T22:42:45
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opengl2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui


mac: LIBS += -framework GLUT
else:unix|win32: LIBS += -lGLUT
