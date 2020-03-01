#include <iostream>
#include "developer.h"
#include "manito.h"
#include "smallbird.h"
#include "company.h"

using namespace std;
void sort(int* arr, int len, bool(*cmp)(int,int));
bool upCmp(int a, int b);
bool downCmp(int a, int b);

int main()
{
    //练习6
//    Sheep s("山羊","白色",4);
//    s.roar();
//    Tiger t("老虎","白色",4);
//    t.run();
    //多态:的本质就是传递逻辑，让一样的代码执行不同的逻辑
    //C语言传函数指针实现多态
    //C++传对象实现多态，一个对象可以包含无数个函数和成员变量
//    int arr[10] = {12,23,45,78,43,23,67,89,43,6};
//    sort(arr, 10, upCmp);
//    for(int i = 0;i < 10;i++)
//    {
//        cout<<arr[i]<<endl;
//    }
//    sort(arr, 10, downCmp);
//    for(int i = 0;i < 10;i++)
//    {
//        cout<<arr[i]<<endl;
//    }
    //练习7
//    Company com;  
//    //Developer* dev指针可能指向Manito类对象也可能指向SmallBird类对象
//    Developer* dev = com.recruit();
//    com.work(dev);//在这里传入不同类型的对象，会执行不同的逻辑，多态
    
    return 0;
}

void sort(int* arr, int len, bool(*cmp)(int,int))
{
    for(int i = 0;i < len-1;i++)
    {
        for(int j = 0;j < len-1-i;j++)
        {
            if(cmp(arr[j],arr[j+1]))
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

bool upCmp(int a, int b)
{
    return a>b;
}

bool downCmp(int a, int b)
{
    return a<b;
}