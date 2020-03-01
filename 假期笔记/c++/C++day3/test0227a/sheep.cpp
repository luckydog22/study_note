#include "sheep.h"


Sheep::Sheep(string name, string color, int legs):
    Animal(name, color, legs)
{
    
}

void Sheep::roar()
{
    cout<<getLegs()<<"条腿的"<<getColor()<<"颜色的"<<getName()<<"咩咩叫"<<endl;
}
