#include "animal.h"

Animal::Animal(string name, string color, int legs):
    name(name),
    color(color),
    legs(legs)
{
    
}

void Animal::eat()
{
    cout<<"��ɶѽ"<<endl;
}

void Animal::move()
{
    cout<<"ȥ��ѽ"<<endl;
}
