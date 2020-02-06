#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

#include<opencv2/opencv.hpp>
using namespace cv;

#define IMAGE_PATH(IMAGE)"D:/workspaace/testsrc/"#IMAGE
void myAddWeight(Mat src1,float a1, Mat src2,float a2,Mat& output);

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



void MainWindow::on_pushButton_only_clicked()
{
    //查看单通道图片 一个像素点的值
    Mat  src = imread(IMAGE_PATH(68.jpg));
    Mat gray;
    cvtColor(src,gray,CV_BGR2GRAY);
    uchar value = gray.at<uchar>(10,10);
    qDebug()<<value;
    imshow("gray",gray);

}

void MainWindow::on_pushButton_three_clicked()
{
    //查看三通道图片 一个像素点的值
    Mat  src = imread(IMAGE_PATH(68.jpg));
  Vec3b value = src.at<Vec3b>(10,10);
   qDebug()<<(int)value[0]<<(int)value[1]<<(int)value[2];
   imshow("src",src);

}

void MainWindow::on_pushButton_clicked()
{
    //把一块变成白色
     Mat  src = imread(IMAGE_PATH(lovely.jpg));
     for(int i = 0 ; i <150; i++)
     {
         for(int j = 0 ; j <100; j++)
         {
//             Vec3b value = src.at<Vec3b>(i,j);
             src.at<Vec3b>(Point(j,i))[0] = 255;
              src.at<Vec3b>(Point(j,i))[1] = 255;
               src.at<Vec3b>(Point(j,i))[2] = 255;
               //用构造函数的方式传值 下面的是错的 不会写
//            src.at<Vec3b>(255,255,255) ;
         }
     }
     imshow("src",src);
        /*
         * 感兴趣的区域
         */
//     Mat roisrc = src(Rect(200,0,200,100));
//     imshow("src",src);
//     imshow("roi",roisrc);

}

/*
 * 自定义合成函数
*/
void myAddWeight(Mat src1,float a1, Mat src2,float a2,Mat& output)
{
    int width = src1.channels()*src1.cols;
    int height = src1.rows;
    output.create(src1.size(),src1.type());
    for(int y=0;y<height;y++)
    {
        uchar* line1 = src1.ptr(y);
        uchar* line2 = src2.ptr(y);
        uchar* oline = output.ptr(y);
        for(int x = 0 ; x<width;x++)
        {
            oline[x] =line1[x]*a1+line2[x]*a2;
        }
    }




}
void MainWindow::on_pushButton_2_clicked()
{
    //两个图片的大小需要一样大
    Mat src1 = imread(IMAGE_PATH(bg1.jpg));
    Mat src2 = imread(IMAGE_PATH(bg2.jpg));
    Mat dst;
   myAddWeight(src1,0.5,src2,0.5,dst);//自己重写合成方法
//    addWeighted(src1,0.5,src2,0.5,0,dst);
   /*
    * 第五个参数 越大越亮 换成100尝试
    */
    imshow("src1",src1);
    imshow("src2",src2);
    imshow("dst",dst);
}

void MainWindow::on_pushButton_3_clicked()
{

    Mat src = imread(IMAGE_PATH(lovely.jpg));
    Mat dst = Mat::zeros(src.size(),src.type());
    int rows = src.rows;
    int cols = src.cols;

    float a = 2.0f;
    float b = 20.f;
    for(int i = 0 ; i <rows; i++)
    {
        for(int j = 0 ; j <cols;j++)
        {
            Vec3b point = src.at<Vec3b>(i,j);
            dst.at<Vec3b>(i,j)[0] = saturate_cast<uchar>(point[0]*a+b);
             dst.at<Vec3b>(i,j)[1] = saturate_cast<uchar>(point[0]*a+b);
             dst.at<Vec3b>(i,j)[2] = saturate_cast<uchar>(point[0]*a+b);
        }
    }
    imshow("src",src);
    imshow("dst",dst);

}








