#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student
{
friend class Teacher;
private:
    string name;
    int score;
public:
    Student();
    Student(string name, int score);
    void show();
};

#endif // STUDENT_H
