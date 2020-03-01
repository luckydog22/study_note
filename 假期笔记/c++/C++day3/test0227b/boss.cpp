#include "boss.h"


Boss::Boss(string name, int age, string title, string major, string duty, string department):
    Base(name, age),//Base是虚基类，所以需要在最底层的派生类中初始化
    Engineer(name, age, title, major),
    Leader(name, age, duty, department)
{
    
}
