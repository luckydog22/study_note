#include "animal.h"

Animal::Animal(string name, string color, int legs):
    name(name),
    color(color),
    legs(legs)
{
    
}

void Animal::eat()
{
    cout<<"³ÔÉ¶Ñ½"<<endl;
}

void Animal::move()
{
    cout<<"È¥ÄÄÑ½"<<endl;
}
