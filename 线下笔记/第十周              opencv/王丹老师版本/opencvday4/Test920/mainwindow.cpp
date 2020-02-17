#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(nextFrame()));
//    timer.start(50);
//    if(!vc.open(0))
//    {
//        qDebug()<<"视频打开失败";
//        return;
//    }

//    Mat src = imread(IMAGE_PATH(5.jpg));
//    Mat dst;
//    medianBlur(src,dst,7);
//    imshow("src",src);
//    imshow("dst",dst);

//    vector<uchar> v;
//    v.push_back(5);
//    v.push_back(5);
//    v.push_back(5);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(6);
//    v.push_back(6);
//    v.push_back(9);
//    v.push_back(7);
//    v.push_back(7);

//    Mat src(v);
//    int channels = 0;
//    Mat dst;
//    int size = 5;
//    float range[2] = {0,10};
//    const float* ranges[] = {range};
//    calcHist(&src,//要统计的数组
//                1,//数组的元素个数
//                &channels,//统计数组中图片的哪个通道
//                noArray(),//不要进行掩膜操作
//                dst,//输出
//                1,//和参数2相等
//                &size,//分成10个区间
//                ranges//统计值的范围 前闭后开区间
//                );
//    for(int i = 0 ; i <dst.rows; i++)
//    {
//        float* line = dst.ptr<float>(i);
//        qDebug()<<*line;
//    }
   Mat src = imread(IMAGE_PATH(bb.jpg));
   Mat dst;
   Mat kernel = getStructuringElement(MORPH_CROSS,Size(20,20));
//   dilate(src,dst,kernel);

        erode(src,dst,kernel);
        imshow("src",src);
        imshow("dst",dst);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextFrame()
{
    Mat frame;
    vc>>frame;
    if(frame.empty())
    {
        qDebug()<<"读取视频信息失败";
        return;
    }
    Mat temp;
    cvtColor(frame,temp,CV_BGR2RGB);
    medianBlur(frame,temp,7);
    flip(temp,temp,1);
//     Mat dst;

    QImage img(temp.data,temp.cols,temp.rows,QImage::Format_RGB888);

    ui->label_face->setPixmap(QPixmap::fromImage(img));


}
