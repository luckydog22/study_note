#ifndef BOSS_H
#define BOSS_H

#include "engineer.h"
#include "leader.h"

class Boss : public Engineer, public Leader
{
public:
    Boss(string name, int age, string title, string major, string duty, string department);
};

#endif // BOSS_H
