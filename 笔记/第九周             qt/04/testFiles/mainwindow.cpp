#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QDir>
#include<QDebug>
#include<QTextStream>
#define MAX_LEN 1024*1024
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



//获取指定路径下的文件列表
void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    //1.创建一个目标目录 文件夹
    QString path = "d:/wd/";

    //创建保存文件路径 #include<QDir>
    QDir dir(path);

    //2. 判断这个目录是否存在 不存在则创建
    if(!dir.exists())
        dir.mkpath(path);
    //3.提取目录中的文件 返回一个list列表   QStringList
    QStringList fileList = dir.entryList();
    qDebug()<<fileList[0]<<"   "<<fileList[1];
    for(int i = 2;i<fileList.size();i++)
    {
        //文件的名字 显示到listwidget中  （动态添加内容）
            ui->listWidget->addItem(fileList.at(i));//fileList[i]

    }

}
//  QFile写文件  头文件 #include<QFile>
void MainWindow::on_pushButton_qfilew_clicked()
{

    //1.创建一个文本
    QFile file("hello.txt");
    //打开成功的话
    if(file.open(QFile::ReadWrite|QFile::Truncate))//对文件的操作权限
    {
        //qint64 write(const char *data, qint64 len); qt-->c++-->c_str
        QString data = ui->lineEdit->text();

        //转成c++风格data.toStdString()
        //将c++风格转成char* c风格   .c_str()

       int len = file.write(data.toStdString().c_str(),data.size());
        ui->label->setText(QString("写入了 %1 个字节").arg(len));
    }

}

//  QFile读文件
void MainWindow::on_pushButton_qfiler_clicked()
{
    QFile file("hello.txt");
      if(file.open(QFile::ReadOnly))
      {
          //读取出来的内容放到buf中
          char buf[1024];
         int len = file.read(buf,1024);//1k
          QString d(buf);
          ui->label->setText(QString("读取了 %1 个字节").arg(len)+d);
      }
}

//QTextStream 字符流写入文件 头文件：#include<QTextStream>
void MainWindow::on_pushButton_textw_clicked()
{

    QFile file("hello.txt");
    if(file.open(QFile::ReadWrite|QFile::Truncate))
    {
        QTextStream out(&file);
       // out<<ui->lineEdit->text()<<endl;

        //qSetFieldWidth(10) 给十个位子 相当于%10d printf（%10d）
        // right 右对齐  aa          90
        out<<ui->lineEdit->text()<<qSetFieldWidth(10)<<right<<90<<endl;
    }
    file.close();
}

//读文件

void MainWindow::on_pushButton_textread_clicked()
{
    QFile file("hello.txt");
       if(file.open(QFile::ReadOnly))
       {
           QTextStream in(&file);
           QString data;
           //***while方式，拿回来的内容 格式丢失，没有空格的显示
//           while(!in.atEnd())//arend（）  结尾
//            {
//               QString data1;
//               in>>data1;//读取第一个字符串时遇到空白就停止了
//               data.append(data1);
//            }

        //in.readAll() 可以全部读取，包括空格样式
           data= in.readAll();
    ui->label->setText(data);
       }
       file.close();
}

void MainWindow::on_pushButton_copy_clicked()
{
    QFile src("D:/Demo/workspaace/testsrc/music/mouse baby.rmvb");
       QFile dst("C:/Users/daisy/Desktop/dst.rmvb");
       if(src.open(QIODevice::ReadOnly) && dst.open(QIODevice::WriteOnly))
       {
           QDataStream in(&src);
           QDataStream out(&dst);
           char buf[MAX_LEN];
           while(!in.atEnd())
           {
               int size = in.readRawData(buf, MAX_LEN);
               if(size == -1)
               {
                   qDebug()<<"读取失败";
                   break;
               }
               out.writeRawData(buf, size);
           }
           qDebug()<<"完成";
       }
       src.close();
       dst.close();
}
