#include "leader.h"

Leader::Leader(string name, int age,string duty, string department):
    Base(name, age),
    duty(duty),
    department(department)
{
    
}

void Leader::lead()
{
    cout<<"�쵼�쵼"<<endl;
}
