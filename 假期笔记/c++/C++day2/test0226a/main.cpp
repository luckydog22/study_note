#include <iostream>
#include "oneinstance.h"

using namespace std;

int main()
{
    //练习4
//    Teacher t;
//    t.sort();
//    t.show();
    //单例模式
//    OneInstance* p1 = OneInstance::getInstance();
//    OneInstance* p2 = OneInstance::getInstance();
//    OneInstance* p3 = OneInstance::getInstance();
//    OneInstance* p4 = OneInstance::getInstance();
//    cout<<p1<<endl;
//    cout<<p2<<endl;
//    cout<<p3<<endl;
//    cout<<p4<<endl;
    
//    OneInstance::releaceInstance();
    int a = 10;
    //++a = 20;//将变量本身加1，然后返回自己，这里++a返回的是变量a本身
    a++ = 20;//返回的是a加1之前的值，而不是a本身，a本身此时已经是加1之后的值了
    cout<<a<<endl;
    return 0;
}











