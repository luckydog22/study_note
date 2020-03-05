#include "myprint.h"
#include <iostream>

using namespace std;

MyPrint::MyPrint()
{
    int num = 0;
    for(int i = 0;i < HEIGHT;i++)
    {
        for(int j = 0;j < WIDTH;j++)
        {
            arr[i][j] = num++;
        }
    }
}

void MyPrint::print()
{
    print(' ');
}

void MyPrint::print(char space)
{
    for(int i = 0;i < HEIGHT;i++)
    {
        for(int j = 0;j < WIDTH;j++)
        {
            if(j == WIDTH-1)
            {
                cout<<arr[i][j];
            }
            else
            {
                cout<<arr[i][j]<<space;
            }         
        }
        cout<<endl;
    }
}

