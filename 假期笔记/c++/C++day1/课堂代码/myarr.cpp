#include "myarr.h"

void MyArr::input(int* src, int len)
{
    arrLen = len;
    arr = new int[len];
    for(int i = 0;i < len;i++)
    {
        arr[i] = src[i];
    }
}

int MyArr::max()
{
    int m = arr[0];
    for(int i = 1;i < arrLen;i++)
    {
        if(arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}

int MyArr::min()
{
    int m = arr[0];
    for(int i = 1;i < arrLen;i++)
    {
        if(arr[i] < m)
        {
            m = arr[i];
        }
    }
    return m;
}

int MyArr::agv()
{
    int sum = 0;
    for(int i = 0;i < arrLen;i++)
    {
        sum += arr[i];
    }
    return sum/arrLen;
}

MyArr::~MyArr()
{
    delete[] arr;
}

