#include "boss.h"


Boss::Boss(string name, int age, string title, string major, string duty, string department):
    Base(name, age),//Base������࣬������Ҫ����ײ���������г�ʼ��
    Engineer(name, age, title, major),
    Leader(name, age, duty, department)
{
    
}
