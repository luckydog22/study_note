#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/opencv.hpp>
#include <QDebug>
using namespace cv;

#define IMAGE_PATH(IMAGE) "D:/workspaace/testsrc/src/"#IMAGE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//查看单通道图片 一个像素点的值
void MainWindow::on_pushButton_gray_clicked()
{
    Mat src = imread(IMAGE_PATH(68.jpg));
    if(src.empty())
    {
        qDebug()<<"load failed";
        return;
    }
    Mat gray;
    cvtColor(src,gray,CV_BGR2GRAY);
    uchar value = gray.at<uchar>(10,10);
   // uchar v = gray.at<uchar>(Point(x,y));
    qDebug()<<value;
    imshow("gray",gray);
}
//查看三通道图片 一个像素点的值
void MainWindow::on_pushButton_rgb_clicked()
{
    Mat src = imread(IMAGE_PATH(68.jpg));
    if(!src.data)
    {
        qDebug()<<"load failed";
        return;
    }
  Vec3b value =  src.at<Vec3b>(10,20);
  qDebug()<<(int)value[0]<<(int)value[1]<<(int)value[2]<<endl;
    imshow("src",src);
}
//修改灰度图像素值
void MainWindow::on_pushButton_change_gray_clicked()
{
    Mat src = imread(IMAGE_PATH(68.jpg));
    if(src.empty())
    {
        qDebug()<<"falied";
        return;
    }
    Mat gray;
    cvtColor(src,gray,CV_BGR2GRAY);
    for(int i = 0 ; i <100; i++)
    {
        for(int j = 0; j<100;j++)
        {
            gray.at<uchar>(j,i) = 0;
        }
    }
    imshow("gray",gray);
}
//修改RGB图像素值
void MainWindow::on_pushButton_change_vec_clicked()
{
    Mat src = imread(IMAGE_PATH(68.jpg));
    for(int i = 0 ; i < 100; i++)
    {
        for(int j = 0 ; j<100; j++)
        {
            src.at<Vec3b>(j,i)[0] = 128;
            src.at<Vec3b>(j,i)[1] = 255;
            src.at<Vec3b>(j,i)[2] = 255;
            //用构造函数的方式传值
//         src.at<Vec3b>(j,i)[128,255,255] ;
        }
    }
    imshow("dst",src);

}
//单通道反差图片
void MainWindow::on_pushButton_gray_fan_clicked()
{
    Mat src = imread(IMAGE_PATH(68.jpg));
    Mat gray;
    cvtColor(src,gray,CV_BGR2GRAY);
    int width = src.cols;
    int height = src.rows;
    for(int i = 0 ; i <width; i++)
    {
        for(int j = 0; j<height; j++)
        {
            int value = gray.at<uchar>(j,i);
            gray.at<uchar>(j,i) = 255-value;
        }
    }
    imshow("dst",gray);

}
//三通道反差图片
void MainWindow::on_pushButton_vec_fan_clicked()
{
    Mat src = imread(IMAGE_PATH(68.jpg));
    Mat dst;
    dst.create(src.size(),src.type());
    int height = src.rows;
    int width = src.cols;
    for(int i = 0 ; i <width; i++)
    {
        for(int j = 0 ; j< height; j++)
        {
            Vec3b value = src.at<Vec3b>(j,i);
            int b = value[0];
            int g = value[1];
            int r = value[2];
            dst.at<Vec3b>(j,i)[0] = 255-b;
             dst.at<Vec3b>(j,i)[1] = 255-g;
             dst.at<Vec3b>(j,i)[2] = 255-r;
        }
    }
    imshow("src",src);
    imshow("dst",dst);

}
//空白图像赋值
void MainWindow::on_pushButton_kongbai_clicked()
{
    Mat src;
    src.create(300,400,CV_8UC3);
    src = Scalar(0,0,255);
    imshow("src",src);

}
//ROI(感兴趣区域)
void MainWindow::on_pushButton_roi_clicked()
{
    Mat src = imread(IMAGE_PATH(68.jpg));
    Rect rect(10,10,100,150);
    Mat dst = src(rect);
    imshow("dst",dst);
    imshow("src",src);

}
//Vec3b与Vec3f
void MainWindow::on_pushButton_vec3f_clicked()
{
     Mat src = imread(IMAGE_PATH(68.jpg));
     int width = src.cols;
     int height = src.rows;
     Mat dst;
     dst.create(src.size(),src.type());
     for(int i = 10;i<width;i++)
     {
         for(int j = 20; j<height;j++)
         {
           float b= src.at<Vec3f>(j,i)[0];
           float g = src.at<Vec3f>(j,i)[1];
            float r = src.at<Vec3f>(j,i)[2];
//            dst.at<Vec3f>(j,i)[0]=0;
//            dst.at<Vec3f>(j,i)[1]=0;
//            dst.at<Vec3f>(j,i)[2]=0;
    qDebug()<<b<<" "<<g<<" "<<r;
         }
     }
     imshow("src",src);
     imshow("dst",dst);


}
//把CV_8UC1转换到CV32F1
void MainWindow::on_pushButton_convertto_clicked()
{
     Mat src = imread(IMAGE_PATH(68.jpg));
     Mat gray;
     cvtColor(src,gray,CV_BGR2GRAY);
     Mat dst;
     dst.create(src.size(),src.type());
     gray.convertTo(dst,CV_32F);
     imshow("src",src);
     imshow("gray",gray);
     imshow("dst",dst);

}
