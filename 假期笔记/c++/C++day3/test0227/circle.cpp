#include "circle.h"

Circle::Circle(int x, int y, int r):Point(x, y),r(r)
{
    
}

float Circle::area()
{
    return 3.14f*r*r;
}
