#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle : public Point
{
protected:
    int r;
public:
    Circle(int x, int y, int r);
    float area();
};

#endif // CIRCLE_H
