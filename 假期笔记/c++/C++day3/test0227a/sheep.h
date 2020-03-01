#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"

class Sheep : public Animal
{
public:
    Sheep(string name, string color, int legs);
    void roar();
};

#endif // SHEEP_H
