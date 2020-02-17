#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<opencv2/opencv.hpp>
#include<QDebug>
#include<QPainter>

using namespace cv;
#define IMAGE_PATH(IMAGE)"D:/workspaace/testsrc/"#IMAGE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Mat src = imread(IMAGE_PATH(psb.jpg));
    Mat rgb;
    cvtColor(src,rgb,CV_BGR2RGB);
    QImage img(rgb.data,rgb.cols,rgb.rows,rgb.cols*rgb.channels(),QImage::Format_RGB888);
    ui->label_img->setFixedSize(img.size());
    ui->label_img->setPixmap(QPixmap::fromImage(img));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Mat src = imread(IMAGE_PATH(rabit.jpg));
    Mat rgb;
    cvtColor(src,rgb,CV_BGR2RGB);
    QImage img(rgb.data,rgb.cols,rgb.rows,rgb.cols*rgb.channels(),QImage::Format_RGB888);


    QPainter painter(this);
    painter.drawImage(0,0,img);

}
