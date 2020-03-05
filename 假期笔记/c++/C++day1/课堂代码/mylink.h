#ifndef MYLINK_H
#define MYLINK_H

#include <cstdio>

class MyLink
{
private:
    struct Node//�ṹ�����ͱ���װ����������������ⲿʹ��
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
    
    void add(int data);//��β���������
    int get(int index);//����ָ��λ�õ�����
    int getSize();//��������ĳ���
};

#endif // MYLINK_H
