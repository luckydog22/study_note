#include "time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m, int s):
    h(h),m(m),s(s)
{
    
}

Time Time::operator++(int a)
{
    s++;
    m+=s/60;
    h+=m/60;
    
    s%=60;
    m%=60;
    h%=24;
}

void Time::show()
{
    cout<<h<<":"<<m<<":"<<s<<endl;
}
