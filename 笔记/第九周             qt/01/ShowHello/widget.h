#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;//����ui�ļ����ɵ��࣬�������Widget����һ����
}

class Widget : public QWidget
{
    Q_OBJECT
    //���QT�������Եĺ� Ҫ�Ǽ̳�QObject���࣬������������
public:
    explicit Widget(QWidget *parent = 0);
    //�̳�QObject���� �ڹ��캯���ж�Ҫָ�����ڵ����
    //��Ϊ�и��ڵ�ʱ������ܱ��Զ�ɾ��
    ~Widget();





private:
    Ui::Widget *ui;//ָ������ļ����ɵ�UI�����ָ��
    bool b;
};

#endif // WIDGET_H
