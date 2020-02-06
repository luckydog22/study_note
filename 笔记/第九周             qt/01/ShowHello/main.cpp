#include "widget.h"
#include <QApplication>
//QApplication管理了各种各样的应用程序的广泛资源，比如默认的字体和光标。
int main(int argc, char *argv[])
{
   //a是这个程序的QApplication对象，必须创建，是该程序应用的对象。
    QApplication a(argc, argv);
    Widget w;//创建一个窗口，默认是只创建不显示
    w.show();//显示主窗体

    //通过a  运行应用程序；当调用QApplication.exec()时，就进入了事件循环，应用程序就开始等待并处理事件
    return a.exec();
}
