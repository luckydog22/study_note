#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

using namespace std;

class Base
{
protected:
    string name;
    int age;
public:
    Base(string name, int age);
    void eat();
};

#endif // BASE_H
