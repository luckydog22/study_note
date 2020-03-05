#include "mypoker.h"
#include <iostream>

using namespace std;

MyPoker::MyPoker(string color, string point):
    color(color),
    point(point)
{
    
}

MyPoker::MyPoker(string color):
    color(color),
    point("")
{
    
}

MyPoker::MyPoker()
{
    cout<<"无参构造"<<endl;
}

void MyPoker::show()
{
    cout<<color<<point<<endl;   
}

