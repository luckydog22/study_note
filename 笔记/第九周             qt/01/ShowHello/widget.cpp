#include "widget.h"
#include "ui_widget.h"
#include<QDebug>



Widget::Widget(QWidget *parent) :
    QWidget(parent),//��ʼ������
    ui(new Ui::Widget)//����ui����
{
    //ui = new Ui::Widget;
    ui->setupUi(this);  //����ui�ĸ�����  ��UI�����뵱ǰ�Ĵ��ڲ�������



}

Widget::~Widget()
{
    delete ui;
}





