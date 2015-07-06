#-------------------------------------------------
#
# Project created by QtCreator 2015-07-05T21:50:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pdi
TEMPLATE = app


SOURCES += src/main.cpp\
           src/mainwindow.cpp \
    src/Processamento.cpp \
    src/Alerta.cpp

HEADERS  += include/mainwindow.h \
    include/Processamento.h \
    include/Alerta.h

FORMS    += tela/mainwindow.ui


INCLUDEPATH += .
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2
INCLUDEPATH += /usr/local/include/opencv2/core
INCLUDEPATH += /usr/local/include/opencv2/highgui
INCLUDEPATH += /usr/local/include/opencv2/imgproc
INCLUDEPATH += /usr/local/include/opencv2/flann
INCLUDEPATH += /usr/local/include/opencv2/photo
INCLUDEPATH += /usr/local/include/opencv2/video
INCLUDEPATH += /usr/local/include/opencv2/features2d
INCLUDEPATH += /usr/local/include/opencv2/objdetect
INCLUDEPATH += /usr/local/include/opencv2/calib3d
INCLUDEPATH += /usr/local/include/opencv2/ml
INCLUDEPATH += /usr/local/include/opencv2/contrib
LIBS += `pkg-config opencv --cflags --libs`
