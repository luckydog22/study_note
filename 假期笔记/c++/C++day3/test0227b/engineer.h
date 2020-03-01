#ifndef ENGINEER_H
#define ENGINEER_H

#include "base.h"

class Engineer : virtual public Base
{
private:
    string title;
    string major;
public:
    Engineer(string name, int age, string title, string major);
    void develop();
};

#endif // ENGINEER_H
