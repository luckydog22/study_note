#ifndef DOG_H
#define DOG_H

#include <string>

using namespace std;//C++�������ṩ�����е���ͺ����������ռ䶼��std

class Dog
{
public:
    string name;
    int age;
    
    void setName(string n);
    void sleep();
    void eat();
};

#endif // DOG_H
