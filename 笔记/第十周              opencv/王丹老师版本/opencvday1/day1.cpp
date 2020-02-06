
OpenCV是一个基于BSD许可（开源）发行的跨平台计算机视觉库，
可以运行在Linux、Windows、Android和Mac OS操作系统上。
它轻量级而且高效——由一系列 C 函数和少量 C++ 类构成，同时提供了Python、Ruby、MATLAB等语言的接口，
实现了图像处理和计算机视觉方面的很多通用算法。

一、环境配置和第一个opencv项目

qt-opencv构建记录.doc

INCLUDEPATH += D:\opencv\opencv3.4-qt-install\install\include
INCLUDEPATH += D:\opencv\opencv3.4-qt-install\install\include\opencv
INCLUDEPATH += D:\opencv\opencv3.4-qt-install\install\include\opencv2
LIBS += D:/opencv/opencv3.4-qt-install/install/x86/mingw/lib/libopencv_*.a


dll 动态库  动态链接库  运行的时候
LIBS 静态库  编译时用的

二、基础函数和类

//1.创建mat对象  读取图片内容
（之后对图片的操作，就对mat对象操作，计算机无法直接识别图像）
//相对路径  绝对路径都可以
  Mat src = imread("1.pgm");  

//2.判读读取是否成功
（1）src.data==0;
（2）src.empty()==false;

//3.创建显示窗口
//           窗口名称 ， （设置窗口大小）窗口自适应 
namedWindow("src",CV_WINDOW_AUTOSIZE);  

//4.在窗口显示图片
//  窗口名称, 图片对象  
imshow("dst",dst);

//5.转换图像色彩空间（彩色--》纯色）  三通道转为单通道，效率高
Mat dst;  //定义一个变量，存储转换后的图片
		//原图片对象  存储的目标对象   目标颜色（定义好的宏）
cvtColor(src,dst,CV_BGR2GRAY);

//6.复制图片（只有单通道的图片对象，才可以用imwrite）
		//原图片   目标图片
imwrite("gray.png",dst);
		//格式化多张图片
imwrite( format("z%d.jpg",cout) );




#include <opencv2/opencv.hpp>  //头文件  加强文件

1.opencv中表示图像的类Mat  // Mat 用来表示图片

2.加载图像
Mat imread( const String& filename, int flags = IMREAD_COLOR );

imread功能是加载图像文件成为一个Mat对象

参数1：图片的路径，图像文件名称
参数2：图像的色彩空间模式（默认为BGR）
		第二个参数表示加载的图像是什么类型，支持常见的三个参数值
		
返回值：图像对象

//注意：opencv支持jpg，png，tiff等常见格式图像文件加载
宏定义：#define IMAGE_PATH (IMAGE) "D:/workspaace/testsrc/src/"#IMAGE

3.创建窗口

void namedWindow(const String& winname, int flags = WINDOW_AUTOSIZE);
参数1：窗口的名称（英文）
参数2：窗口属性，默认为根据图像设置窗口尺寸

4.转换图像色彩空间 修改图像  //  将三通道的 转成单通道 效率高 
void cvtColor( InputArray src, OutputArray dst, int code, int dstCn = 0 );
参数1：输入图像
参数2：输出图像
参数3：色彩空间  详情ColorConversionCodes
参数4：通道数，默认根据色彩空间决定

eg：转灰度 
    Mat src = "D:/workspaace/testsrc/68.jpg";
    if(!src.data)
    {
        cout<<"load image failed"<<endl;
    }
    
    imshow("src",src);
    //转灰度
    Mat dst;
    cvtColor(src,dst,CV_BGR2GRAY);
    imwrite("gray.png",dst);

    namedWindow("gray");//,cv_window_autosize
    imshow("gray",dst);
    waitKey(0);
    return 0;
	
eg2：读取一张图片
    namedWindow("show");
    string p = "D:/workspaace/testsrc/src/1.jpg";
    Mat img = imread(p);
    if(!img.data)
    {
        cout<<"load image failed"<<endl;

    }
    imshow("show",img);
    waitKey(0);

5.保存图像
bool imwrite( const String& filename, InputArray img,
              const std::vector<int>& params = std::vector<int>());
参数1：图片文件的名字
参数2：保存的图像对象
参数3：参数（一般不需要指定）
注意：只有8位、16位的PNG、JPG、Tiff文件格式而且是单通道或者三通道的BGR的图像才可以通过这种方式保存

6.键盘输入
int waitKey(int delay = 0);
参数1：等待输入的时间，默认0一直等待
返回值：

7.在窗口显示图像
void imshow(const String& winname, const ogl::Texture2D& tex);
参数1：窗口名称
参数2：图像对象

练习：做一个图片查看器，用键盘a和d控制切换图片  使用vector<string> v;保存图片名称
练习2：新建一个Qt项目，主窗口有一个按钮，启动浏览器，点击button，弹出namedWindow窗口，显示图片，用键盘a和d控制切换图片
 		
项目示例1：TestMat
项目示例2：TestMat2
eg1:
string getName(string name)
{
    string path = "D:/workspaace/testsrc/src/";
    return path+name;
}

int main()
{

    vector<string> v;
    for(int i = 1 ; i <6; i++)
    {
        char buf[100];
       sprintf(buf,"%d.jpg",i);
       v.push_back(buf);
    }

    int index = 0 ;
    while(true)
    {
        string p = getName(v[index]);
        cout<<p<<endl;
        Mat img = imread(p);
        if(!img.data)
        {
            cout<<"load image failed"<<endl;
            break;

        }
        imshow("show",img);
        int k = waitKey(0);
        if(k == 'a')
        {
            if(index == 0)
            {
                index = 4;
            }else
            {
                index--;
           }

        }else if(k == 'd')
        {
           if(index == 4)
            {
                index = 0;
           }else
           {
                index++;
           }
        }

    }
    return 0;
}
eg2:
string p = getName(v[index]);
        cout<<p<<endl;
        Mat img = imread(p);
        if(!img.data)
        {
            cout<<"load image failed"<<endl;
            break;

        }
        imshow("show",img);
        Mat dst;
        cvtColor(img,dst,CV_BGR2GRAY);
        imwrite("gray.png",dst);

        namedWindow("gray");
        imshow("gray",dst);

//练习2使用：
		
 QStringList entryList;//存放指定路径下所有的文件名
  
 QString path = "D:/workspaace/testsrc/src/";//指定路径
	
	int index = 2;//重点要注意：从2开始，前两个是.点
使用：
  QDir dir(path); 

  entryList = dir.entryList(); 	
  
eg:

//头文件：
  QStringList entryList;
    QString path ;
    int index ;
//构造函数：
 path = "D:/workspaace/testsrc/src/";
    index = 2;
    QDir dir(path);
    entryList = dir.entryList();

//button点击事件：
namedWindow("show");
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
            if(key == 2)
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
	

三、播放视频

1.视频类VideoCapture

2.打开视频
bool open(const String& filename);
参数1：视频路径
返回值：打开成功

3.读取视频帧
VideoCapture& operator >> (CV_OUT Mat& image);
参数1：读取到Mat对象
返回值：VideoCapture对象

示例：
include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define IMAGE_PATH(IMAGE) "d:/farsight/opencv/testres/"#IMAGE

int main()
{
    VideoCapture cap;
    if(!cap.open(IMAGE_PATH(test.avi)))
    {
        cout<<"视频文件没有找到"<<endl;
        return 0;
    }
    namedWindow("test");
    Mat frame;
    while(1)
    {
        cap>>frame;
        if(frame.empty())//!frame.data
            break;
        imshow("test", frame);
        if(waitKey(50)>=0)
            break;
    }
    waitKey(0);
    return 0;
}

练习2：播放视频文件，每按一次键盘切换一帧
示例：TestMat2

VideoCapture vc;
    QString str = path_video+"snow.mp4";
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


 
 















