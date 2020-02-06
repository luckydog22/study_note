#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<opencv2/opencv.hpp>
#include<QDebug>
#include<iostream>
using namespace std;
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



void MainWindow::on_pushButton_ke_clicked()
{

      Mat src = imread(IMAGE_PATH(1.jpg));
      Mat dst = Mat(src.size(),src.type());
      imshow("src",src);
    int rows = src.rows;
    int width = src.channels()*src.cols;
    int channel= src.channels();

    for(int y=1;y<rows-1;y++)
    {
        uchar* current = src.ptr<uchar>(y);
        uchar* per = src.ptr<uchar>(y-1);
        uchar* next = src.ptr<uchar>(y+1);
         uchar* dstLine = dst.ptr<uchar>(y);
         for(int i=channel;i<width-channel;i++)
         {
             dstLine[i]=saturate_cast<uchar>(
                         5*current[i]-(
                             current[i-channel]+
                         current[i+channel]+
                            per[i]+next[i]
                             )
                         );
         }

    }
    imshow("dst",dst);

}


void MainWindow::on_pushButton_arr_clicked()
{

    Mat src = imread(IMAGE_PATH(lovely.jpg));
    Mat dst = Mat(src.size(),src.type());
    imshow("src",src);

    int rows = src.rows;
    int width = src.cols;
    for(int i = 1;i<rows-1;i++)
    {
        uchar(*current)[3] = src.ptr<uchar[3]>(i);
        uchar(*per)[3]=src.ptr<uchar[3]>(i-1);
        uchar(*next)[3]=src.ptr<uchar[3]>(i+1);
        uchar(*dstLine)[3]=dst.ptr<uchar[3]>(i);
        for(int j=1;j<width-1;j++)
        {
            for(int k=0;k<3;k++)
            {
                dstLine[j][k]=saturate_cast<uchar>(
                            5*current[j][k]-(
                                current[j-1][k]+
                            current[j+1][k]+
                            per[j][k]+next[j][k]
                                )

                            );
            }
        }


    }
    imshow("dst",dst);

}

void MainWindow::on_pushButton_2d_clicked()
{
    //掩膜操作
    Mat src = imread(IMAGE_PATH(psb.jpg));
    Mat dst = Mat(src.size(),src.type());
    imshow("src",src);
    Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
    filter2D(src,dst,src.depth(),kernel);
    imshow("dst",dst);

}

void MainWindow::on_pushButton_video_clicked()
{
   VideoCapture vc;
   if(!vc.open("D:/workspaace/testsrc/video/snow.mp4"))
   {
       qDebug()<<"摄像头打开失败";
   }
//   namedWindow("src");

    while(true)
    {
        Mat frame;
        vc>>frame;
        if(frame.empty())
         {
            break;
         }
        Mat dst = Mat(frame.size(),frame.type());
        Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
        filter2D(frame,dst,frame.depth(),kernel);
        imshow("src",frame);
        imshow("dst",dst);
//        if(waitKey(30)>0)
//           {
//               break;
//           }
        int k = waitKey(0);
              if(k>='a' && k<= 'z')
              {
                 imshow("test",frame);
                  imshow("test",dst);
              }
             if(k == 'A')
             {
                  break;
              }
    }

}

void MainWindow::on_pushButton_copy_clicked()
{
    //浅拷贝
   /* Mat src = imread(IMAGE_PATH(2.jpg));
    Mat dst(src);
    imshow("src",src);
    imshow("dst",dst);*/
    //深拷贝 copyTo
    /*Mat src = imread(IMAGE_PATH(2.jpg));
    Mat dst;
    src.copyTo(dst);
    imshow("dst",dst);*/
    //深拷贝 clone
    Mat src = imread(IMAGE_PATH(2.jpg));
    Mat dst;
   dst = src.clone();
    imshow("dst",dst);


}

void MainWindow::on_pushButton_line_clicked()
{
    Mat src=imread(IMAGE_PATH(2.jpg));
    Mat dst;
    src.copyTo(dst);
//    Mat dst(src);
    int cols = src.cols*src.channels();
    for(int i = 10 ; i <20;i++)
    {
        uchar* line = dst.ptr<uchar>(i);
        for(int j = 0 ; j <cols;j++)
        {
            line[j]=0;
        }
    }
    imshow("src",src);
    imshow("dst",dst);
}
//构造
void MainWindow::on_pushButton_scalar_clicked()
{
//    Mat m = Mat(400,500,CV_8UC3,Scalar(0,0,255));
//    imshow("src",m);
    Mat m;
    m.create(400/*高度*/,200/*宽度*/,CV_8UC3);
    m = Scalar(127,0,255);
    imshow("src",m);
    cout<<m<<endl;

}

void MainWindow::on_pushButton_array_clicked()
{
    Mat C = (Mat_<char>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout << "C = " << endl << " " << C << endl;
}

void MainWindow::on_pushButton_test_clicked()
{
    Scalar colors[7] = {Scalar(0, 0, 255),
                        Scalar(0, 125, 255),
                        Scalar(0, 255, 255),
                        Scalar(0, 255, 0),
                        Scalar(255, 255, 0),
                        Scalar(255, 0, 0),
                        Scalar(240, 32, 160)};
    string titles[7] = { "1","2","3","4","5","6","7"};
    for(int i = 0 ; i <7; i++)
    {
        Mat color(100,100,CV_8UC3,colors[i]);
        imshow(titles[i],color);
    }


}
