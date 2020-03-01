#ifndef LEADER_H
#define LEADER_H

#include "base.h"

class Leader : virtual public Base
{
private:
    string duty;
    string department;
public:
    Leader(string name, int age, string duty, string department);
    
    void lead();
};

#endif // LEADER_H
