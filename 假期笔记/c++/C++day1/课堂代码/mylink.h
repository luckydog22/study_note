#ifndef MYLINK_H
#define MYLINK_H

#include <cstdio>

class MyLink
{
private:
    struct Node//结构体类型被封装起来，不允许类的外部使用
    {
        int num;
        Node* pNext;
        Node():pNext(NULL){}
        Node(int num):num(num),pNext(NULL)
        {}
    };
    Node* pHead;
    Node* pTail;
    int size;
public:
    MyLink();
    ~MyLink();
    
    void add(int data);//向尾部添加数据
    int get(int index);//返回指定位置的数据
    int getSize();//返回链表的长度
};

#endif // MYLINK_H
