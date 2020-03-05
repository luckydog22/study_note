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
    if(index == len)//如果数组已经满了，那么扩张
    {
        expand();
    }
    arr[index++] = data;//将入栈的数据存入数组中
}

void MyStack::pop()
{
    index--;//并不需要释放数据，只要改变栈顶位置就可以，下次入栈时会覆盖掉无用的数据
}

int MyStack::top()
{
    return arr[index-1];//这里千万不要改变index的值，因为既没有入栈也没有出栈
}

void MyStack::expand()
{
    int newLen = len*2;
    int* newArr = new int[newLen];//创建新的数组
    for(int i = 0;i < len;i++)
    {
        newArr[i] = arr[i];//将原来数组中的数据存放到新的数组中
    }
    delete[] arr;//删除原来的数组
    arr = newArr;//成员指针指向新的数组
    len = newLen;
}