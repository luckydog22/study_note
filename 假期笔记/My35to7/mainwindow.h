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

public slots:
    void Btn0Slot();
    void Btn1Slot();
    void Btn2Slot();
    void Btn3Slot();
    void Btn4Slot();
    void Btn5Slot();
    void Btn6Slot();
    void Btn7Slot();
    void Btn8Slot();
    void Btn9Slot();

    void BtnOkSlot();
    void BtnClearSlot();
    void BtnOpenSlot();

    bool containsNum(int num);
    bool containsNum(vector<int>& v, int num);

    vector<int> randNums();
    int check(vector<int> nums);
    void showResult(int count);
    void showNums(vector<int> nums);
private:
    Ui::MainWindow *ui;
    //输入的字符串 用来临时拼接用
    QString selecting;
    //输入的字符串 用来保存到上方的label中
    QString selected;
    //保存上方label中的数值的容器，等待开奖时候用来比较
    vector<int> selectedNums;
    //记录我输入的个数，不能超过七个
    int numCount = 0;

};

#endif // MAINWINDOW_H
