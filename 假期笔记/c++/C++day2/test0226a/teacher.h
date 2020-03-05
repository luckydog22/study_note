#ifndef TEACHER_H
#define TEACHER_H

#include "student.h"

#define STUDENTS 5

class Teacher
{
private:
    Student students[STUDENTS];//成员变量所在的空间，取决于对象被创建在哪个空间
public:
    Teacher();
    void sort();
    void show();
    static int num;
};

#endif // TEACHER_H
