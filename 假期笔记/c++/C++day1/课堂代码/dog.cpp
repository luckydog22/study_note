#include "dog.h"
#include <iostream>

using namespace std;

//void setName(string n)//如果不加Dog::那么setname函数就是一个普通的全局函数
//{
    
//}

void Dog::setName(string n)
{
    name = n;
}

void Dog::sleep()
{
    cout<<name<<"睡觉了"<<endl;
}

void Dog::eat()
{
    cout<<name<<"妈妈喊你回家吃饭了"<<endl;
}