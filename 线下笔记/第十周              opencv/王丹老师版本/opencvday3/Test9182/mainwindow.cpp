#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<opencv2/opencv.hpp>
#include<QDebug>
#include<QFileDialog>
#include<QPainter>

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

void MainWindow::on_pushButton_choose_clicked()
{
     path = QFileDialog::getExistingDirectory();
     ui->lineEdit->setText(path);
        qDebug()<<path;
        QDir dir(path);

        entryList = dir.entryList();

        QString entry = entryList[index];
        QString name = path+"/"+entry;//路径+文件名
        Mat img = imread(name.toStdString().c_str());
        if(!img.data)
        {
            qDebug()<<name;
            qDebug()<<"load faild";
             return ;
        }
        QImage image(name);
//        ui->label->setFixedSize(image.size());
//       ui->label->setPixmap(QPixmap::fromImage(image));
        ui->label->setPixmap(QPixmap(name));

}

void MainWindow::on_pushButton_left_clicked()
{
     qDebug()<<index;
    QString entry = entryList[index];
     QString name = path+"/"+entry;//路径+文件名
    Mat img = imread(name.toStdString().c_str());
    if(index == 2)
    {
        index = entryList.size()-1;
    }
    else
    {
        index--;
    }
    QImage image(name);
//        ui->label->setFixedSize(image.size());
//       ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->setPixmap(QPixmap(name));
}

void MainWindow::on_pushButton_right_clicked()
{
    QString entry = entryList[index];
     QString name = path+"/"+entry;//路径+文件名
    Mat img = imread(name.toStdString().c_str());
    if(index == entryList.size()-1)
    {
        index = 2;
    }
    else
    {
        index++;
    }
    QImage image(name);
//        ui->label->setFixedSize(image.size());
//       ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->setPixmap(QPixmap(name));
}
