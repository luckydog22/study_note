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
    void on_pushButton_gray_clicked();

    void on_pushButton_rgb_clicked();

    void on_pushButton_change_gray_clicked();

    void on_pushButton_change_vec_clicked();

    void on_pushButton_gray_fan_clicked();

    void on_pushButton_vec_fan_clicked();

    void on_pushButton_kongbai_clicked();

    void on_pushButton_roi_clicked();

    void on_pushButton_vec3f_clicked();

    void on_pushButton_convertto_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
