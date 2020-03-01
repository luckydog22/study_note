#ifndef STUDENT_H
#define STUDENT_H


class Student
{
private:
    int cpp;
    int c;
    int linux;
public:
    Student(int cpp, int c, int linux);
    Student(const Student& other);
    Student operator+=(const Student& other);
    void show();
};

#endif // STUDENT_H
