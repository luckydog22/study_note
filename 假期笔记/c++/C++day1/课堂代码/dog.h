#ifndef DOG_H
#define DOG_H

#include <string>

using namespace std;//C++给我们提供的所有的类和函数，命名空间都是std

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
