#include "widget.h"
#include "ui_widget.h"
#include<QDebug>



Widget::Widget(QWidget *parent) :
    QWidget(parent),//初始化父类
    ui(new Ui::Widget)//创建ui对象
{
    //ui = new Ui::Widget;
    ui->setupUi(this);  //设置ui的父对象  让UI对象与当前的窗口产生关联



}

Widget::~Widget()
{
    delete ui;
}





