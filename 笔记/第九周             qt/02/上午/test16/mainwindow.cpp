#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    name_my = "admin";
    pass_my = "123456";

    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(slot_dendlu()));

    connect(&b,SIGNAL(my_signal()),this,SLOT(slot_signal()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_dendlu()
{
    QString  name = ui->lineEdit_user_2->text();
    QString pass = ui->lineEdit_psw_2->text();
    if(name==name_my)
    {
        if(pass == pass_my)
        {
            ui->label_4->setText("succ");
        //  boss *b  = new boss(this);
        b.show();
        this->hide();
        }else
        {
            ui->label_4->setText("密码错误");
        }
    }else
    {
        ui->label_4->setText("用户名错误");
    }

}

void MainWindow::slot_signal()
{
    this->show();
    b.hide();
}
