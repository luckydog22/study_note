#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //按照给如的文件名构建一个图像 参数是文件名
    QPixmap p = QPixmap(":/heads/head1.jpg");
    //让label显示图片资源
    ui->label->setPixmap(p);
    //让图片跟我传入的文件一样大小
    ui->label->setGeometry(QRect(ui->label->pos(),p.size()));
    flag = false;
    //初始化 将图片对象保存到容器中
    initImages();

}

void MainWindow::initImages()
{
    position = 0;
    //将32个图片对象保存到容器中
    for(int i = 1; i<= 32; i++)
    {
        QString path = QString(":/heads/head%1.jpg").arg(i);
        images.push_back(QPixmap(path));
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
//点击上一张
void MainWindow::on_pushButton_per_clicked()
{
    //第一张时，显示最后一张
    if(position > 0)
    {
        --position;
    }
    else
    {
        position = images.size()-1;
    }
    //label显示图片
    ui->label->setPixmap(images[position]);
}

void MainWindow::on_pushButton_next_clicked()
{
   //最后一张时，变到第一张
    if(position<images.size()-1)
    {
        ++position;
    }else
    {
        position = 0;
    }
     ui->label->setPixmap(images[position]);
}
//两张图片切换
void MainWindow::on_pushButton_change_clicked()
{
    QPixmap p;
    if(flag)
    {
         p = QPixmap(":/heads/head1.jpg");
        ui->label->setPixmap(p);
        ui->label->setGeometry(QRect(ui->label->pos(),p.size()));
        flag = false;
    }else
    {
        flag = true;
        p = QPixmap(":/heads/head30.jpg");
       ui->label->setPixmap(p);
       ui->label->setGeometry(QRect(ui->label->pos(),p.size()));
    }
}
