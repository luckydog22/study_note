#include "student.h"
#include <iostream>

using namespace std;

Student::Student(int score, string name):
    score(score),
    name(name)
{
    
}

void Student::setScore(int score)
{
    this->score = score;
}

void Student::show()
{
    cout<<name<<" "<<score<<endl;   
}
