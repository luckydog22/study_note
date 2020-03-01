#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QDebug>
#include <opencv2/opencv.hpp>

using namespace cv;
#define IMAGE_PATH(IMAGE) "D:/workspaace/testsrc/video/"#IMAGE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    path = "D:/workspaace/testsrc/src/";
    path_video = "D:/workspaace/testsrc/video/";
    index = 2;
    QDir dir(path);
    entryList = dir.entryList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_start_clicked()
{
//    namedWindow("show");
    while(true)
    {
        QString fileName = entryList[index];
        QString name = path+fileName;
        Mat img = imread(name.toStdString());
        if(!img.data)
        {
             qDebug()<<name;
            qDebug()<<"load failed";
            break;
        }
        imshow("show",img);
        int key = waitKey(0);
        if(key == 'a')
        {
            if(index == 2)
            {
                index = entryList.size()-1;
            }else
            {
                index--;
            }
        }else if(key == 'd')
        {
            if(index == entryList.size()-1)
            {
                index = 2;
            }else
            {
                index++;
            }
        }

    }

}

void MainWindow::on_pushButton_video_clicked()
{
    VideoCapture vc;
    QString str =IMAGE_PATH(snow.mp4);
    if(!vc.open(str.toStdString()))
    {
        qDebug()<<"open fail";
    }
   namedWindow("test");
    while(true)
    {
        Mat frame;
        vc>>frame;
        if(!frame.data)
        {
            qDebug()<<"load failed";
            break;
        }
        imshow("test",frame);
        int k = waitKey(0);
        if(k>='a' && k<= 'z')
        {
             imshow("test",frame);
        }
    }

}








