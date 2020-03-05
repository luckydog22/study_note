#include "mytime.h"
#include <iostream>

using namespace std;

MyTime::MyTime(int h, int m, int s):
    h(h),
    m(m),
    s(s)
{
    
}

void MyTime::go()
{
    s += 1;
    m += s/60;
    h += m/60;
    
    s %= 60;
    m %= 60;
    h %= 24;
}

void MyTime::show()
{
    cout<<h<<":"<<m<<":"<<s<<endl;
}
