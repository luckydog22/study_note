#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <opencv2/opencv.hpp>

using namespace cv;

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

void MainWindow::showImage()
{
    QString imageName = fileList[index];
    if(!imageName.endsWith(".jpg") && !imageName.endsWith(".png"))
    {
        return;
    }
    QString url = path+imageName;
    Mat src = imread(url.toStdString().c_str());
    if(src.empty())
    {
        return;
    }
    Mat temp;
    cvtColor(src, temp, CV_BGR2RGB);
    QImage img(temp.data, temp.cols, temp.rows, temp.cols*temp.channels(), QImage::Format_RGB888);
    ui->label_img->setFixedSize(img.size());
    ui->label_img->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::enableButtons()
{
    ui->pushButton_left->setEnabled(true);
    ui->pushButton_right->setEnabled(true);
}

void MainWindow::on_pushButton_left_clicked()
{
    if(index == 2)
    {
        index = fileList.size()-1;
    }
    else
    {
        index--;
    }
    showImage();
}

void MainWindow::on_pushButton_path_clicked()
{
    path = QFileDialog::getExistingDirectory(this, "请选择需要的文件夹", "d:/farsight/opencv/");
    path+="/";
    ui->lineEdit_path->setText(path);
    QDir dir(path);
    fileList = dir.entryList(QDir::Files);//获得所有的文件名字
    showImage();
    enableButtons();
}

void MainWindow::on_pushButton_right_clicked()
{
    if(index == fileList.size()-1)
    {
        index = 2;
    }
    else
    {
        index++;
    }
    showImage();
}
