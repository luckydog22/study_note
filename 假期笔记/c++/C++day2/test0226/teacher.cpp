#include "teacher.h"
#include <ctime>
#include <cstdlib>

Teacher::Teacher()
{
    students[0] = new Student(10, "������");
    students[1] = new Student(12, "���������ҵ���");
    students[2] = new Student(14, "��ֻ�ں���");
    students[3] = new Student(15, "���Ƽӿ���");
    students[4] = new Student(11, "������һ��");
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

