#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpServer* server;
    QTcpSocket* client;

private slots:
    void newConnect();
    void on_pushButton_send_clicked();
    void socket_disconnect();
    void socket_read();
};

#endif // MAINWINDOW_H
