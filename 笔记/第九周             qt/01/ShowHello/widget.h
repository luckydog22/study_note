#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;//根据ui文件生成的类，和下面的Widget不是一个类
}

class Widget : public QWidget
{
    Q_OBJECT
    //添加QT对象属性的宏 要是继承QObject的类，必须调用这个宏
public:
    explicit Widget(QWidget *parent = 0);
    //继承QObject的类 在构造函数中都要指定父节点参数
    //因为有父节点时对象才能被自动删除
    ~Widget();





private:
    Ui::Widget *ui;//指向界面文件生成的UI对象的指针
    bool b;
};

#endif // WIDGET_H
