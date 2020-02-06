#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<opencv2/opencv.hpp>
#include<QTimer>
using namespace cv;
#define IMAGE_PATH(IMAGE)"D:/workspaace/testsrc/"#IMAGE
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
    void nextFrame();

private:
    Ui::MainWindow *ui;
    QTimer timer;
    VideoCapture vc;
};

#endif // MAINWINDOW_H
