
//////////////////////////////////////////////////////////01  对图片进行锐化操作，手动实现
#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
     Mat src = imread("1.pgm");

     if(src.data)
         cout<<"ok"<<endl;
     else
         cout<<"error"<<endl;

     namedWindow("srcWin",CV_WINDOW_AUTOSIZE);

     imshow("srcWin",src);


     //获得图片通道
     int offset = src.channels();

     int rows = src.rows;
     int clos = src.cols*offset;

     int row = 0;
     int col  = 0;

     //定义指针变量  负责上一行
     uchar *pre = NULL;
     uchar *cur = NULL;
     uchar *next = NULL;

     //定义mat图像(须和原图片一样大小)
     Mat dst = Mat::zeros(src.size(),src.type());

     uchar *output = NULL;

     for(row=1;row<rows-1;row++)
     {
         //获得原图的三行  行指针
         pre = src.ptr<uchar>(row-1);

         cur = src.ptr<uchar>(row);

         next = src.ptr<uchar>(row+1);

         //dst当前行（获得目标图的行指针）
         output = dst.ptr<uchar>(row);
         //遍历列（取得原图的中心像素周围的四个元素）
         for(col = offset;col<clos - offset;col++)
         {
            //锐化
             output[col] =saturate_cast<uchar> (  5*cur[col]-(  pre[col] +
                                                              next[col] +cur[col-offset] + cur[col+offset] )  );
         }


     }

     namedWindow("dstWin",CV_WINDOW_AUTOSIZE);

     imshow("dstWin",dst);

     waitKey(0);

     return 0;



}

//////////////////////////////////////////////////////////////02 调用系统函数锐化  图片
#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
     Mat src = imread("1.pgm");

     if(src.data)
         cout<<"ok"<<endl;
     else
         cout<<"error"<<endl;

     namedWindow("srcWin",CV_WINDOW_AUTOSIZE);

     imshow("srcWin",src);

     //定义mat图像(须和原图片一样大小)
    Mat dst = Mat::zeros(src.size(),src.type());

    Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);

    //系统函数锐化
    filter2D(src,dst,src.depth(),kernel);

     namedWindow("dstWin",CV_WINDOW_AUTOSIZE);

     imshow("dstWin",dst);

     waitKey(0);

     return 0;



}

//////////////////////////////////////////////////////////////02 调用系统函数锐化  视频
#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
    //创建视频对象
    VideoCapture v;

    //打开视频，并判断是否打开成功
    if(v.open("01.mp4"))
        cout<<"ok"<<endl;
    else
        cout<<"open false"<<endl;

    //创建Map对象来保存视频的每一帧
    //因为视频是由无数张图片组合而成
    Mat src;

    //创建将来要显示的视频窗口，窗口之创建一次  ，下面无数次调用
    namedWindow("SrcWin",CV_WINDOW_AUTOSIZE);

    //定义一个按键
    char c =0;

    //将视频的每一帧读出来
    while(v.read(src))
    {
        //数字为0代表一直阻塞，别的数字代表俩张图片显示的时间间隔
        c = waitKey(30);

        imshow( "SrcWin",src );

        //创建一个  同类型的mat对象来装  反差后的每一帧
        Mat dst2 = Mat::zeros(src.size(),src.type());

        //创建掩膜核心
        Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
        //系统函数锐化
        filter2D(src,dst2,src.depth(),kernel);

        namedWindow("dst2Win",CV_WINDOW_AUTOSIZE);

        imshow("dst2Win",dst2);

        if(c==27)
            break;

    }

    return 0;

}



/////////////////////////////////////////////////////////03  手动反差  图片
#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
     Mat src = imread("head9.jpg");

     if(src.data)
         cout<<"ok"<<endl;
     else
         cout<<"error"<<endl;

     namedWindow("srcWin",CV_WINDOW_AUTOSIZE);

     imshow("srcWin",src);

     Mat test = Mat::zeros(src.size(),src.type());
     cvtColor(src,test,CV_BGR2GRAY);
     namedWindow("testWin",CV_WINDOW_AUTOSIZE);
     imshow("testWin",test);

     int rows = test.rows;
     int cols = test.cols;

     int row = 0;
     int col = 0;

     for(row = 0;row<rows;row++)
     {
         for(col = 0;col<cols;col++)
         {
            test.at <uchar>(row,col) = 255 -test.at<uchar>(row,col);
         }
     }

     namedWindow("test1",CV_WINDOW_AUTOSIZE);

     imshow("test1",test);

     waitKey(0);
     return 0;

}

//////////////////////////////////////////////////////////////04  调用系统函数反差  视频
#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
    //创建视频对象
    VideoCapture v;

    //打开视频，并判断是否打开成功
    if(v.open("01.mp4"))
        cout<<"ok"<<endl;
    else
        cout<<"open false"<<endl;

    //创建Map对象来保存视频的每一帧
    //因为视频是由无数张图片组合而成
    Mat src;

    //创建将来要显示的视频窗口，窗口之创建一次  ，下面无数次调用
    namedWindow("SrcWin",CV_WINDOW_AUTOSIZE);

    //定义一个按键
    char c =0;

    //将视频的每一帧读出来
    while(v.read(src))
    {
        //数字为0代表一直阻塞，别的数字代表俩张图片显示的时间间隔
        c = waitKey(30);

        imshow( "SrcWin",src );

        //创建一个  同类型的mat对象来装  反差后的每一帧
        Mat dst2 = Mat::zeros(src.size(),src.type());

        //对其反差操作
        bitwise_not(src,dst2);

        namedWindow("dst2Win",CV_WINDOW_AUTOSIZE);

        imshow("dst2Win",dst2);

        if(c==27)
            break;

    }

    return 0;

}

//////////////////////////////////////////////混合图片
#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
    //第一张图片
    Mat src1 = imread("1.pgm");
    if(src1.data)
        cout<<"ok"<<endl;
    else
        cout<<"error"<<endl;

    //第二张图片
    Mat src2 = imread("2.pgm");
    if(src2.data)
        cout<<"ok"<<endl;
    else
        cout<<"error"<<endl;

    //创建图片窗口
    namedWindow("src1Win",CV_WINDOW_AUTOSIZE);
    namedWindow("src2Win",CV_WINDOW_AUTOSIZE);

    //展示俩战图片
    imshow("src1Win",src1);
    imshow("src2Win",src2);

    Mat dst = Mat::zeros( src1.size(),src2.type() );
    double a= 0.5;

    if(     (src1.rows == src2.rows)  &&
            (src1.cols == src2.cols) &&
            (src1.type() == src2.type() )   )
    {
        //输入的图片1，系数，图片二，系数，默认值，生成混合图片
        addWeighted(src1,(1-a),src2,a,0.0,dst  );
    }

    //显示混合图片
    namedWindow("dstWin",CV_WINDOW_AUTOSIZE);

    imshow("dstWin",dst);

    waitKey(0);

    return -1;

}

////////////////////////////////////////////////// 保存一张需要的图片
#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
    VideoCapture v;

    if(  v.open("01.mp4") )
        cout<<"ok"<<endl;
    else
        cout<<"open fail"<<endl;

    namedWindow("srcWin",CV_WINDOW_AUTOSIZE);

    Mat src;


    char c = 0;

    double a =0;

    while(v.read(src))
    {
        imshow("srcWin",src);

        c = waitKey(30);

        if(c=='f')
            imwrite("222.jpg",src);

        if(c=='k')
            break;
    }

    return -1;

}

////////////////////////////////////////////////////////////////混合视频
#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
    //创建视频对象
    VideoCapture v;

    //打开要打开的视频文件
    if(  v.open("01.mp4") )
        cout<<"ok"<<endl;
    else
        cout<<"open fail"<<endl;

    namedWindow("srcWin",CV_WINDOW_AUTOSIZE);

    //创建图片对象，保存视频的每一帧
    Mat src;

    //读取要混合的图片，并判断读取是否成功
    Mat src3 = imread("222.jpg");
    if(src3.data==0)
    {
        cout<<"src3  ok"<<endl;
        return -1;
    }
    else
        cout<<"src3 error"<<endl;
    //*******************************

    char c = 0;

    //定义一个a值，保存混合度
    double a =0.5;

    while(v.read(src))
    {

         Mat dst = Mat::zeros(src.size(),src.type());


        c = waitKey(30);
        imshow("srcWin",src);

        //加以限制，只有像素，矩阵大小相同     类型也相同  混合才有意义
        if(  (src.rows == src3.rows) &&( src.cols == src3.cols) && (src.type() == src3.type() ))
        {
            addWeighted(src,(1-a),src3,a,0.0,dst);
        }

        namedWindow("dstWin",CV_WINDOW_AUTOSIZE);

        imshow("dstWin",dst);

        if(c== 27)
            break;
    }
    return -1;
}


