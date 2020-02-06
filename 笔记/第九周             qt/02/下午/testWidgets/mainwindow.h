#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidgetItem>
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
    void on_pushButton_checkbox_clicked();

    void on_pushButton_radiobutton_clicked();

    void on_pushButton_combo_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);



    void on_pushButton_spinbox_clicked();

    void on_spinBox_valueChanged(const QString &arg1);

    void on_doubleSpinBox_valueChanged(double arg1);


    void on_pushButton_progress_clicked();

    void on_progressBar_valueChanged(int value);

    void on_horizontalScrollBar_sliderMoved(int position);

    void on_horizontalScrollBar_sliderPressed();

    void on_horizontalScrollBar_sliderReleased();

    void on_horizontalScrollBar_valueChanged(int value);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
