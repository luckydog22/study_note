#include "tiger.h"


Tiger::Tiger(string name, string color, int legs):
    Animal(name, color, legs)
{
    
}

void Tiger::run()
{
    cout<<getLegs()<<"���ȵ�"<<getColor()<<"��ɫ��"<<getName()<<"������"<<endl;
}
