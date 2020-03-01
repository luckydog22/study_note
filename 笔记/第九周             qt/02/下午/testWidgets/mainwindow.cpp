#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//checkbox的提交按钮
void MainWindow::on_pushButton_checkbox_clicked()
{
    QString s;
    //先获取一下那些事被选中状态的
    if(ui->checkBox->isChecked())
    {
        s.append(ui->checkBox->text());

      //  ui->checkBox->text();
    }
    if(ui->checkBox_2->isChecked())
        s.append(ui->checkBox_2->text());
    ui->label->setText(s);

}
//radiobutton 单选按钮
void MainWindow::on_pushButton_radiobutton_clicked()
{
    //获取按钮上的文本 ui->checkBox->text()

    if(ui->radioButton->isChecked())
    {
        ui->label_radio->setText("falm");
    }else  if(ui->radioButton_2->isChecked())
        ui->label_radio->setText("man");

}


//组合框 下拉菜单
void MainWindow::on_pushButton_combo_clicked()
{
    //ui->comboBox->currentText() 获取选中的那条文本内容
    ui->label_combo->setText(ui->comboBox->currentText());
    ui->label_com2->setText(ui->comboBox->currentText().append("aaaaaaaaa"));
}
//当前文本发生变化时， 参数QString &arg1 为文本内容
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->label_combo->setText(arg1);
}

//自旋钮 提交按钮
void MainWindow::on_pushButton_spinbox_clicked()
{
    //获取自旋钮控件中的值 显示到label中
    int v = ui->spinBox->value();
    double d = ui->doubleSpinBox->value();
    //将int转成字符串QString().setNum(d)
    ui->label_doublespin->setText(QString().setNum(d));
  //  QString("%1").arg(v);
    ui->label_spinbox->setNum(v);
}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
     ui->label_spinbox->setText(arg1);
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
     ui->label_doublespin->setNum(arg1);
}

//进度条
void MainWindow::on_pushButton_progress_clicked()
{
   //获取进度条的显示值 ui->progressBar->value();
//    while(1)
//    {
             ui->progressBar->setValue(ui->progressBar->value()+10);
             Sleep(1000);
//    }


}
//进度条的值改变时，
void MainWindow::on_progressBar_valueChanged(int value)
{

     ui->label_progress->setNum(value);
}

//滑动条 当按住 滑动时促发信号
void MainWindow::on_horizontalScrollBar_sliderMoved(int position)
{
    ui->label_scorller->setNum(position);
}
//滑动条 当点击 按下时促发
void MainWindow::on_horizontalScrollBar_sliderPressed()
{
    ui->label_scorller->setNum(ui->horizontalScrollBar->value());
}
//滑动条 当抬起 释放时促发
void MainWindow::on_horizontalScrollBar_sliderReleased()
{
    ui->label_scorller->setNum(ui->horizontalScrollBar->value());
}
//滑动条 当滑动 按下或者抬起，只要值发生改变时，会促发
void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    ui->label_slider->setNum(value);
}

//单击效果
void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
   ui->label_double->setText(item->text());
}
//双击效果
void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}
