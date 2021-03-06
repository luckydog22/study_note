﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_video_clicked();

private:
    Ui::MainWindow *ui;

    QStringList entryList;
    QString path ;
    QString path_video;
    int index ;


};

#endif // MAINWINDOW_H
