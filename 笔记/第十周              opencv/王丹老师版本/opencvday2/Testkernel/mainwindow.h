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


    void on_pushButton_ke_clicked();

    void on_pushButton_arr_clicked();

    void on_pushButton_2d_clicked();

    void on_pushButton_video_clicked();

    void on_pushButton_copy_clicked();

    void on_pushButton_line_clicked();

    void on_pushButton_scalar_clicked();

    void on_pushButton_array_clicked();

    void on_pushButton_test_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
