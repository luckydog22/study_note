#ifndef MAINWINDOW_H
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
    void on_pushButton_choose_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

private:
    Ui::MainWindow *ui;
    QString path;
    QStringList entryList;//存放指定路径下所有的文件名
    int index = 2;

};

#endif // MAINWINDOW_H
