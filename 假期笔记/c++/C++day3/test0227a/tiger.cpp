#include "tiger.h"


Tiger::Tiger(string name, string color, int legs):
    Animal(name, color, legs)
{
    
}

void Tiger::run()
{
    cout<<getLegs()<<"条腿的"<<getColor()<<"颜色的"<<getName()<<"呼呼跑"<<endl;
}
