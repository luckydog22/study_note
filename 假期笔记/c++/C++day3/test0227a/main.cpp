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
    //��ϰ6
//    Sheep s("ɽ��","��ɫ",4);
//    s.roar();
//    Tiger t("�ϻ�","��ɫ",4);
//    t.run();
    //��̬:�ı��ʾ��Ǵ����߼�����һ���Ĵ���ִ�в�ͬ���߼�
    //C���Դ�����ָ��ʵ�ֶ�̬
    //C++������ʵ�ֶ�̬��һ��������԰��������������ͳ�Ա����
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
    //��ϰ7
//    Company com;  
//    //Developer* devָ�����ָ��Manito�����Ҳ����ָ��SmallBird�����
//    Developer* dev = com.recruit();
//    com.work(dev);//�����ﴫ�벻ͬ���͵Ķ��󣬻�ִ�в�ͬ���߼�����̬
    
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