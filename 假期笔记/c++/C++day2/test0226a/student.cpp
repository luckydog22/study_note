#include "student.h"
#include <iostream>

using namespace std;

Student::Student()
{
    
}

Student::Student(string name, int score):
    name(name),
    score(score)
{
    
}

void Student::show()
{
    cout<<name<<" "<<score<<endl;
}
