#ifndef MYPOKER_H
#define MYPOKER_H

#include <string>

using namespace std;

class MyPoker
{
private:
    string color;
    string point;
public:
    MyPoker(string color, string point);
    MyPoker(string color);//初始化大小王
    MyPoker();
    void show();
};

#endif // MYPOKER_H
