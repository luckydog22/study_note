
/////按键实现 图片查看
#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
# include<vector>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
    vector<string> v;

    v.push_back("age.jpg");
    v.push_back("hh.jpg");
    v.push_back("kk.jpg");


    Mat src = imread(v[0]);
    namedWindow("srcWin",CV_WINDOW_AUTOSIZE);
    imshow("srcWin",src);

   char c =0;
   int pos = 0;

    while(1)
    {
        c = waitKey(30);
        if(c == 'a')
        {
            pos--;
            if(pos ==-1)
                pos = 2;
        }
        else if(c == 'd')
        {
            //二选一
            pos++;
            pos = pos%3;

            //if(pos == 3)
            //pos = 0;
        }

        Mat src = imread(v[pos]);
        imshow("srcWin",src);

        if(c == 32)
            break;
    }

    return 0;

}

///
///练习04：
 ///（1）Mat(Size size, int type) 创建Mat对象填充红色
/// （2）创建3*3的红色的图片
 ///（3）获得Mat图片的行、列、通道

#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
#include <vector>
using namespace  cv;
using namespace cv::face;
using namespace std;
int main(int argc, char *argv[])
{
   Mat src = imread("age.jpg");

   Mat dst = Mat::zeros(src.size(),src.type());

   dst = Scalar(255,255,255);

   namedWindow("dstWin",CV_WINDOW_AUTOSIZE);

   imshow("dstWin",dst);

   Mat dst1 = Mat(3,3,CV_8UC1,Scalar(128));

   namedWindow("dst1Win",CV_WINDOW_AUTOSIZE);

   imshow("dst1Win",dst1);

   cout<<src.rows<<endl;
   cout<<src.cols<<endl;
   cout<<src.channels()<<endl;


   char c =waitKey(0);

   if(c==27)
   return 0;
}

//练习 05
//更改bgr视频为gray视频输出
//播放视频文件，输入g记录存储一张视频里面的一帧（即一张图片）

#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>
#include <vector>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
    //创建视频对象
    VideoCapture v;

    //判断打开是否成功
    if(!v.open("01.mp4"))
    {
          cout<<"error"<<endl;
          return -1;
    }

    //创建窗口
    namedWindow("video",CV_WINDOW_AUTOSIZE);
    char c = 0;
    //创建图片对象保存每一张
    Mat src;

    //开始读取
    while(v.read(src))
    {
        Mat dst = Mat::zeros(src.size(),src.type());

        //灰度化
        cvtColor(src,dst,CV_BGR2GRAY);

        imshow("video",dst);

        //等待30毫秒
        c = waitKey(30);

        //定义按键 保存图片内的每一帧
        if(c == 'c')
            imwrite("55.jpg",src);

        if(c == 27)
            break;
    }
   return 0;
}

//



