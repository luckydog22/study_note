#include <iostream>
#include "studentfriend.h"

using namespace std;

int compare(const StudentFriend& st1, const StudentFriend& st2);
int main()
{
    //练习1 不小心弄丢了
    //练习2
//    Book b("c++ primer", "C++大神");
//    b.show();
    //练习3
    StudentFriend students[5] = {
        StudentFriend(34, "大娃"),//使用匿名对象给栈空间数组初始化
        StudentFriend(44, "二娃"),
        StudentFriend(54, "三娃"),
        StudentFriend(14, "四娃"),
        StudentFriend(32, "五娃"),
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
