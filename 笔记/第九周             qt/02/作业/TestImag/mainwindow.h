#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initImages();
private slots:
    void on_pushButton_per_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_change_clicked();

private:
    Ui::MainWindow *ui;
    vector<QPixmap> images;
    int position;
    bool flag;
};

#endif // MAINWINDOW_H
