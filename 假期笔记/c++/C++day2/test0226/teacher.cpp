#include "teacher.h"
#include <ctime>
#include <cstdlib>

Teacher::Teacher()
{
    students[0] = new Student(10, "甜蜜蜜");
    students[1] = new Student(12, "月亮代表我的心");
    students[2] = new Student(14, "我只在乎你");
    students[3] = new Student(15, "美酒加咖啡");
    students[4] = new Student(11, "潇洒走一回");
    srand(time(0));
}

Teacher::~Teacher()
{
    for(int i = 0;i < STUDENTS;i++)
    {
        delete students[i];
    }
}

Student* Teacher::randHappyBoy()
{
    return students[rand()%STUDENTS];
}

void Teacher::hehe(Student *hb)
{
    hb->setScore(0);
}

void Teacher::show()
{
    for(int i = 0;i < STUDENTS;i++)
    {
        students[i]->show();
    }
}

