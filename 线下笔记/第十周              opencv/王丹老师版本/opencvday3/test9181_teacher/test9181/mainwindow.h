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
private:
    void showImage();
    void enableButtons();
private slots:
    void on_pushButton_left_clicked();
    
    void on_pushButton_path_clicked();
    
    void on_pushButton_right_clicked();
    
private:
    Ui::MainWindow *ui;
    
    QString path;
    QStringList fileList;
    int index = 2;
};

#endif // MAINWINDOW_H
