#include "mystack.h"

MyStack::MyStack():
    len(10),
    arr(new int[len]),
    index(0)
{
    
}

MyStack::~MyStack()
{
    delete[] arr;
}

void MyStack::push(int data)
{
    if(index == len)//��������Ѿ����ˣ���ô����
    {
        expand();
    }
    arr[index++] = data;//����ջ�����ݴ���������
}

void MyStack::pop()
{
    index--;//������Ҫ�ͷ����ݣ�ֻҪ�ı�ջ��λ�þͿ��ԣ��´���ջʱ�Ḳ�ǵ����õ�����
}

int MyStack::top()
{
    return arr[index-1];//����ǧ��Ҫ�ı�index��ֵ����Ϊ��û����ջҲû�г�ջ
}

void MyStack::expand()
{
    int newLen = len*2;
    int* newArr = new int[newLen];//�����µ�����
    for(int i = 0;i < len;i++)
    {
        newArr[i] = arr[i];//��ԭ�������е����ݴ�ŵ��µ�������
    }
    delete[] arr;//ɾ��ԭ��������
    arr = newArr;//��Աָ��ָ���µ�����
    len = newLen;
}