#include "teacher.h"
#include <iostream>

using namespace std;

int Teacher::num = 9;

Teacher::Teacher()
{
    students[0] = Student("����", 10);
    students[1] = Student("����", 14);
    students[2] = Student("С��", 213);
    students[3] = Student("����", 2);
    students[4] = Student("С��", 15);
}

void Teacher::sort()
{
    for(int i = 0;i < STUDENTS-1;i++)
    {
        for(int j = 0;j < STUDENTS-1-i;j++)
        {
            if(students[j].score < students[j+1].score)
            {
                Student temp = students[j];            
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

void Teacher::show()
{
    for(int i = 0;i < STUDENTS;i++)
    {
        if(students[i].score>=90)
        {
            cout<<"���� ";
        }
        else if(students[i].score>=80)
        {
            cout<<"���� ";
        }
        else if(students[i].score>=70)
        {
            cout<<"�� ";
        }
        else
        {
            cout<<"������ ";
        }
        students[i].show();
    }
}



