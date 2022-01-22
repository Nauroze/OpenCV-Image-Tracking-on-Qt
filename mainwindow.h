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
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Start();
    ~MainWindow();

private:
    double area;
    double sideLength;
    const int WIDTH = 640;
    const int HEIGHT = 480;
    static const int MAX_OBJECTS = 20;
    const int MIN_OBJECT_AREA = 25 * 25;
    const int MAX_OBJECT_AREA = HEIGHT*WIDTH / 2;
    const std::string imageWindow = "Original Image";
    const std::string hsvWindow = "HSV Image";
    const std::string thresholdWindow = "Thresholded Image";
    bool breakLoop=false;
    cv::Mat cameraFeed_Mat;
    cv::Mat HSV_Mat;
    int track_x=0, track_y=0;
    cv::VideoCapture capture;

    //Hue, Saturation and Variance
    int H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX;

    //Struct to define the attributes of the objects to be tracked.
    struct item{
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
    };

    // Dynamic object who's attributes (specifically HSV) can be changed in real time.
    item testObject;

    // To store objects with defined values.
    std::vector<item> objects;

    void closeEvent (QCloseEvent *event);
    std::string numberToString(int number);
    void drawObject(int x, int y, cv::Mat &frame, item tempItem);
    void morphObject(cv::Mat &thresh);
    void trackObject(int &x, int &y, item tempItem, cv::Mat &cameraFeed);
    item setUpObject(std::string name, int hmin, int hmax, int smin, int smax, int vmin, int vmax);


private slots:

    void on_addButton_clicked();

    void on_defaultButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
