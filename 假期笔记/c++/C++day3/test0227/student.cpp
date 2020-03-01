#include "student.h"
#include <iostream>

using namespace std;

Student::Student(int cpp, int c, int linux):
    cpp(cpp),
    c(c),
    linux(linux)
{
    
}

Student::Student(const Student &other)
{
    cout<<"拷贝构造"<<endl;
}

Student Student::operator+=(const Student &other)
{
    cpp+=other.cpp;
    c+=other.c;
    linux+=other.linux;
    return *this;
}

void Student::show()
{
    cout<<"cpp"<<cpp<<" c"<<c<<" linux"<<linux<<endl;
}
