#include "widget.h"
#include <QApplication>
//QApplication�����˸��ָ�����Ӧ�ó���Ĺ㷺��Դ������Ĭ�ϵ�����͹�ꡣ
int main(int argc, char *argv[])
{
   //a����������QApplication���󣬱��봴�����Ǹó���Ӧ�õĶ���
    QApplication a(argc, argv);
    Widget w;//����һ�����ڣ�Ĭ����ֻ��������ʾ
    w.show();//��ʾ������

    //ͨ��a  ����Ӧ�ó��򣻵�����QApplication.exec()ʱ���ͽ������¼�ѭ����Ӧ�ó���Ϳ�ʼ�ȴ��������¼�
    return a.exec();
}
