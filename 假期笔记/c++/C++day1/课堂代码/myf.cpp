#include "myf.h"
#include <iostream>

using namespace std;

MyF::MyF(int son, int mot):
    son(son),
    mot(mot)
{
    
}

void MyF::show()
{
    cout<<son<<"/"<<mot<<endl;
}


