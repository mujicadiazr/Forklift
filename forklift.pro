#-------------------------------------------------
#
# Project created by QtCreator 2014-01-20T16:41:37
#
#-------------------------------------------------

QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = forklift
TEMPLATE = app


SOURCES += main.cpp \
    glwidget.cpp \
    cam.cpp \
    forklift.cpp \
    light.cpp \
    model_obj.cpp \
    material.cpp \
    tga.cpp \
    texture.cpp

HEADERS  += \
    glwidget.h \
    objscene.h \
    cam.h \
    forklift.h \
    light.h \
    model_obj.h \
    material.h \
    tga.h \
    texture.h

unix{
LIBS += -L$$PWD/soUnix/ -lGLU
LIBS += -L$$PWD/soUnix/ -lglut
}


INCLUDEPATH += $$PWD/includeUnix
DEPENDPATH += $$PWD/includeUnix

win32{
LIBS += "../GxC/libWin32/freeglut.lib"
LIBS += "../GxC/libWin32/glut32.Lib"
LIBS += "../GxC/libWin32/OpenGL32.Lib"
}

RESOURCES += \
    OBJ.qrc
