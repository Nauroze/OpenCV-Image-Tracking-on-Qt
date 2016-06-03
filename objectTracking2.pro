#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T18:42:28
# Author: Nauroze Hoath
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = objectTracking2
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp
INCLUDEPATH += C:\OpenCV3\opencv\opencv_bin2\install\include

LIBS += -L"C:/OpenCV3/opencv/opencv_bin2/install/x86/mingw/bin"
LIBS += -llibopencv_core310 -llibopencv_highgui310 -llibopencv_imgproc310 -llibopencv_features2d310 -llibopencv_calib3d310 -llibopencv_imgcodecs310 -llibopencv_video310 -llibopencv_videoio310 -llibopencv_videostab310
HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
