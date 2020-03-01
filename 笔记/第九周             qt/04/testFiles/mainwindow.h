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
    void on_pushButton_clicked();

    void on_pushButton_qfilew_clicked();

    void on_pushButton_qfiler_clicked();

    void on_pushButton_textw_clicked();

    void on_pushButton_textread_clicked();

    void on_pushButton_copy_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
