#include "sheep.h"


Sheep::Sheep(string name, string color, int legs):
    Animal(name, color, legs)
{
    
}

void Sheep::roar()
{
    cout<<getLegs()<<"���ȵ�"<<getColor()<<"��ɫ��"<<getName()<<"�����"<<endl;
}
