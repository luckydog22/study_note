#ifndef MYSTACK_H
#define MYSTACK_H


class MyStack
{
private:
    int len;//��̬����ĳ���
    int* arr;//ָ��̬�����ָ��
    int index;//ջ��λ��
    void expand();//��������
public:
    MyStack();
    ~MyStack();
    void push(int data);//��ջ
    void pop();//��ջ
    int top();//����ջ��Ԫ��
};

#endif // MYSTACK_H
