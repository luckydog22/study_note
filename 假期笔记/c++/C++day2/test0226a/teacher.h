#ifndef TEACHER_H
#define TEACHER_H

#include "student.h"

#define STUDENTS 5

class Teacher
{
private:
    Student students[STUDENTS];//��Ա�������ڵĿռ䣬ȡ���ڶ��󱻴������ĸ��ռ�
public:
    Teacher();
    void sort();
    void show();
    static int num;
};

#endif // TEACHER_H
