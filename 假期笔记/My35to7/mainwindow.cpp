#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cstdlib>
#include<ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(Btn0Slot()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(Btn1Slot()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Btn2Slot()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Btn3Slot()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(Btn4Slot()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(Btn5Slot()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(Btn6Slot()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(Btn7Slot()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(Btn8Slot()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(Btn9Slot()));
    connect(ui->pushButton_ok,SIGNAL(clicked()),this,SLOT(BtnOkSlot()));
    connect(ui->pushButton_clear,SIGNAL(clicked()),this,SLOT(BtnClearSlot()));
    connect(ui->pushButton_result,SIGNAL(clicked()),this,SLOT(BtnOpenSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Btn0Slot()
{
    qDebug()<<"btn0";
   selecting+='0';
   ui->label_choose->setText(selecting);
   //获取按键上的文本内容
//   qDebug()<<ui->pushButton_0->text();
}

void MainWindow::Btn1Slot()
{
 qDebug()<<"btn1";
 selecting+='1';
 ui->label_choose->setText(selecting);
}

void MainWindow::Btn2Slot()
{
 qDebug()<<"btn2";
 selecting+='2';
 ui->label_choose->setText(selecting);
}

void MainWindow::Btn3Slot()
{
 qDebug()<<"btn3";
 selecting+='3';
 ui->label_choose->setText(selecting);
}

void MainWindow::Btn4Slot()
{
 qDebug()<<"btn4";
 selecting+='4';
 ui->label_choose->setText(selecting);
}

void MainWindow::Btn5Slot()
{
 qDebug()<<"btn5";
 selecting+='5';
 ui->label_choose->setText(selecting);
}

void MainWindow::Btn6Slot()
{
 qDebug()<<"btn6";
 selecting+='6';
 ui->label_choose->setText(selecting);
}

void MainWindow::Btn7Slot()
{
 qDebug()<<"btn7";
 selecting+='7';
 ui->label_choose->setText(selecting);
}

void MainWindow::Btn8Slot()
{
 qDebug()<<"btn8";
 selecting+='8';
 ui->label_choose->setText(selecting);

}

void MainWindow::Btn9Slot()
{
 qDebug()<<"btn9";
 selecting+='9';
 ui->label_choose->setText(selecting);
}

void MainWindow::BtnOkSlot()
{
 qDebug()<<"btnOk";

int selectNum = selecting.toInt();
 if(numCount<7 && selectNum<35)
 {
     //追加字符串，
     selected+=selecting;
     //上方label中的数值之间有个空格，更方便看
     selected += ' ';
     //清空字符串和label
     ui->label_choose->clear();
     selecting.clear();
     //等待开奖label显示 选择的数
     ui->label_num->setText(selected);
     //记录可输入的数字个数
     numCount++;
     //加入容器中

//     if(!containsNum(selectNum))
     selectedNums.push_back(selectNum);
 }

}

void MainWindow::BtnClearSlot()
{
    qDebug()<<"btnclear";
    //字符串清空
    selecting.clear();
    //清空label中的内容
    ui->label_choose->clear();
}


void MainWindow::BtnOpenSlot()
{
    qDebug()<<"btnOpen";
    if(numCount < 7) return;
    //1.生成随机数
    vector<int> nums = randNums();
    //2. check(nums)函数是校验有几个相同的数, showResult 显示中奖结果
    showResult(check(nums));
    //3.显示中奖号码
    showNums(nums);

}
vector<int> MainWindow::randNums()
{
    //随机生成七个不相同的数,保存到容器中
    vector<int> v;
    for(int i = 0 ; i <7 ; i++)
    {
        int num;
        do
        {
            num = rand()%35+1;

        }while(containsNum(v,num));//while条件，循环停止的条件，存在返回值为true，则循环继续，重新生成一个，
                                   //不存在返回值false，保存到容器
        v.push_back(num);
    }
    return v;


}
bool MainWindow::containsNum(vector<int> &v, int num)
{
    //用生成的随机数 同容器内的其他元素进行比较，有相同则返回true
    for(int i = 0 ; i < v.size();i++)
    {
        if(num == v[i])
            return true;
    }
    return false;

}

bool MainWindow::containsNum(int num)
{
    //传入的num同selectedNums中的元素比较，有相同返回true
    for(int i = 0 ; i < selectedNums.size(); i++)
    {
        if(num == selectedNums[i])
            return true;
    }
    return false;

}

//传入的nums为随机数的容器
int MainWindow::check(vector<int> nums)
{
    //比较有几个相同的数
    int count = 0;
    for(int i = 0;i < nums.size();i++)
    {
        //判断返回值
        if(containsNum(nums[i]))
        {
            count++;
        }
    }
    return count;
}




void MainWindow::showResult(int count)
{
    switch (count) {
    case 7:
        ui->label_win->setText("500W");
        break;
    case 6:
        ui->label_win->setText("30W");
        break;
    case 5:
        ui->label_win->setText("10W");
        break;
    case 4:
        ui->label_win->setText("500");
        break;
    case 3:
        ui->label_win->setText("100");
        break;
    case 2:
        ui->label_win->setText("50");
        break;
    case 1:
        ui->label_win->setText("5");
        break;
    default:
        ui->label_win->setText("谢谢参与");

        break;
    }

}
//显示中奖号码，把随机数打出来
void MainWindow::showNums(vector<int> nums)
{
    QString numsStr;
    for(int i = 0 ; i <nums.size();i++)
    {
        numsStr.append(QString().setNum(nums[i])+" ");
    }
    ui->label_result->setText(numsStr);
}
