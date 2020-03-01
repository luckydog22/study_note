#include "engineer.h"

Engineer::Engineer(string name, int age, string title, string major):
    Base(name, age),
    title(title),
    major(major)
{
    
}

void Engineer::develop()
{
    cout<<"开发开发"<<endl;
}
