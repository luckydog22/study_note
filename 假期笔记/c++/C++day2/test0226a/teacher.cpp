#include "teacher.h"
#include <iostream>

using namespace std;

int Teacher::num = 9;

Teacher::Teacher()
{
    students[0] = Student("添逸", 10);
    students[1] = Student("大明", 14);
    students[2] = Student("小明", 213);
    students[3] = Student("中明", 2);
    students[4] = Student("小舞", 15);
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
            cout<<"优秀 ";
        }
        else if(students[i].score>=80)
        {
            cout<<"良好 ";
        }
        else if(students[i].score>=70)
        {
            cout<<"中 ";
        }
        else
        {
            cout<<"不及格 ";
        }
        students[i].show();
    }
}



