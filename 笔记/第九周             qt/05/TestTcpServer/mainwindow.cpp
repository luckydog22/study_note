#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建服务端server对象
    server = new QTcpServer(this);
    //监听客户端的连接  QHostAddress::Any监听任意ip地址
    server->listen(QHostAddress::Any,55555);
    //连接新客户端连接信号
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnect()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newConnect()
{
    //获取客户端的socket
    client = server->nextPendingConnection();

    //客户端的两种状态 断开连接和成功后读取数据
    connect(client, SIGNAL(), this, SLOT(socket_disconnect()));
    connect(client, SIGNAL(readyRead()), this, SLOT(socket_read()));
    qDebug()<<"客户端连接";
}

void MainWindow::on_pushButton_send_clicked()
{
    //获取lineedit内容，2.write方法发送
    QString data = ui->lineEdit->text();
    client->write(data.toLocal8Bit().data());
}

void MainWindow::socket_disconnect()
{
    qDebug()<<"断开连接";
}

void MainWindow::socket_read()
{
    QByteArray data = client->readAll();
    ui->textBrowser->append(QString::fromLocal8Bit(data));
}
