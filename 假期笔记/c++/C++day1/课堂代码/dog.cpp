#include "dog.h"
#include <iostream>

using namespace std;

//void setName(string n)//�������Dog::��ôsetname��������һ����ͨ��ȫ�ֺ���
//{
    
//}

void Dog::setName(string n)
{
    name = n;
}

void Dog::sleep()
{
    cout<<name<<"˯����"<<endl;
}

void Dog::eat()
{
    cout<<name<<"���躰��ؼҳԷ���"<<endl;
}