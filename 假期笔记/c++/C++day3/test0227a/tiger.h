#ifndef TIGER_H
#define TIGER_H

#include "animal.h"

class Tiger : public Animal
{
public:
    Tiger(string name, string color, int legs);
    void  run();
};

#endif // TIGER_H
