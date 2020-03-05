#ifndef TEACHER_H
#define TEACHER_H

#include "student.h"
#define STUDENTS 5

class Teacher
{
private:
    Student* students[STUDENTS];
public:
    Teacher();
    ~Teacher();
    
    Student* randHappyBoy();
    void hehe(Student* hb);
    void show();
};

#endif // TEACHER_H
