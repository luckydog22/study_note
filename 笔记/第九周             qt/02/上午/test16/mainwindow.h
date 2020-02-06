#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "boss.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slot_dendlu();
    void slot_signal();

private:
    Ui::MainWindow *ui;
    QString name_my;
    QString pass_my;
    boss b;

};

#endif // MAINWINDOW_H
