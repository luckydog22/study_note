#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"

class Cylinder : public Circle
{
private:
    int h;
public:
    Cylinder(int x, int y, int r, int h);
    float volume();
};

#endif // CYLINDER_H
