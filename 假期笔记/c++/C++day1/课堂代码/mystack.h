#ifndef MYSTACK_H
#define MYSTACK_H


class MyStack
{
private:
    int len;//动态数组的长度
    int* arr;//指向动态数组的指针
    int index;//栈顶位置
    void expand();//数组扩张
public:
    MyStack();
    ~MyStack();
    void push(int data);//入栈
    void pop();//出栈
    int top();//返回栈顶元素
};

#endif // MYSTACK_H
