#include "studentfriend.h"
#include <iostream>

using namespace std;

StudentFriend::StudentFriend(int score, string name):
    score(score),
    name(name)
{
    
}

void StudentFriend::show()
{
    cout<<name<<" "<<score<<endl;
}
