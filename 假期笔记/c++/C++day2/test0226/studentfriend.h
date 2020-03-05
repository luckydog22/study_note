#ifndef STUDENTFRIEND_H
#define STUDENTFRIEND_H

#include <string>

using namespace std;

class StudentFriend
{
friend int compare(const StudentFriend& st1, const StudentFriend& st2);
private:
    int score;
    string name;
public:
    StudentFriend(int score, string name);
    void show();
};

#endif // STUDENTFRIEND_H
