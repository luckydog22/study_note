#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Animal
{
private://˽�г�ԱҲ�ᱻ����̳У�ֻ������û�жԸ���˽�г�Ա�ķ���Ȩ�޶���
    string name;
    string color;
    int legs;
public:
    Animal(string name, string color, int legs);
    inline void setName(string name){this->name = name;}
    inline string getName(){return name;}
    inline void setColor(string color){this->color = color;}
    inline string getColor(){return color;}
    inline void setLegs(int legs){this->legs = legs;}
    inline int getLegs(){return legs;}
    void eat();
    void move();
};

#endif // ANIMAL_H
