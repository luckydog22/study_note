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
    MyPoker(string color);//��ʼ����С��
    MyPoker();
    void show();
};

#endif // MYPOKER_H
