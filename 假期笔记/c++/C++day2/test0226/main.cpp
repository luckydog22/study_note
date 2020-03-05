#include <iostream>
#include "studentfriend.h"

using namespace std;

int compare(const StudentFriend& st1, const StudentFriend& st2);
int main()
{
    //��ϰ1 ��С��Ū����
    //��ϰ2
//    Book b("c++ primer", "C++����");
//    b.show();
    //��ϰ3
    StudentFriend students[5] = {
        StudentFriend(34, "����"),//ʹ�����������ջ�ռ������ʼ��
        StudentFriend(44, "����"),
        StudentFriend(54, "����"),
        StudentFriend(14, "����"),
        StudentFriend(32, "����"),
    };
    int max = 0, min = 0;
    for(int i = 1;i < 5;i++)
    {
        if(compare(students[i], students[max]) == 1)
        {
            max = i;
        }
        else if(compare(students[i], students[min]) == -1)
        {
            min = i;
        }
    }
    students[max].show();
    students[min].show();
    return 0;
}

int compare(const StudentFriend& st1, const StudentFriend& st2)
{
    if(st1.score > st2.score)
    {
        return 1;
    }
    else if(st1.score < st2.score)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
