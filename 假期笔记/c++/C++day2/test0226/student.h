#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student
{
private:
    int score;
    string name;    
public:
    Student(int score, string name);
    void setScore(int score);
    void show();
};

#endif // STUDENT_H
