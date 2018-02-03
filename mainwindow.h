//#-------------------------------------------------
//#
//# Project created by QtCreator 2016-05-30T18:42:28
//# Author: Nauroze Hoath
//#
//#-------------------------------------------------



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <sstream>
#include <string>
#include <iostream>
#include <thread>
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <opencv2\opencv.hpp>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    //Variables to hold HSV values. (HSV = HUE, SATURATION and VALUE)
    int H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX;
    // Area and Sides of Threshold Contour
    double area;
    double sideLength;
    //capture frame width and height
    const int WIDTH = 640;
    const int HEIGHT = 480;
    //max number of objects to be tracked in frame
    static const int MAX_OBJECTS = 20;
    //minimum and maximum object area
    const int MIN_OBJECT_AREA = 25 * 25;
    const int MAX_OBJECT_AREA = HEIGHT*WIDTH / 2;
    //names that appear at the top of each window
    const std::string imageWindow = "Original Image";
    const std::string hsvWindow = "HSV Image";
    const std::string thresholdWindow = "Thresholded Image";
    bool breakLoop=false;
    //Matrix to store each frame of the webcam feed
    cv::Mat cameraFeed;
    //matrix storage for HSV image
    cv::Mat HSV;
    int x = 0, y = 0;
    cv::VideoCapture capture;

    //Struct to define the attributes of the objects to be tracked.
    typedef struct {
        std::string name;
        int x;
        int y;
        int H_MIN= H_MIN;
        int H_MAX = H_MAX;
        int S_MIN= S_MIN;
        int S_MAX= S_MAX;
        int V_MIN= V_MIN;
        int V_MAX= V_MAX;
        cv::Mat threshold;
    }item ;

    // Dynamic object who's attributes (specifically HSV) can be changed in real time.
    item testObject;
    // To store objects with defined values.
    std::vector<item> objects;

    void closeEvent (QCloseEvent *event);
    std::string numberToString(int number);
    void Start();
    void drawObject(int x, int y, cv::Mat &frame, item tempItem);
    void morphObject(cv::Mat &thresh);
    void trackObject(int &x, int &y, item tempItem, cv::Mat &cameraFeed);
    item setUpObject(std::string name, int hmin, int hmax, int smin, int smax, int vmin, int vmax);




    ~MainWindow();

private slots:

    void on_addButton_clicked();

    void on_defaultButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
