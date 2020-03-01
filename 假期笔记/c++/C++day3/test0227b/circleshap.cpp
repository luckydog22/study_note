#include "circleshap.h"

CircleShap::CircleShap(int r):r(r)
{
    
}

int CircleShap::getPerimeter()
{
    return 3.14f*r*r;
}

string CircleShap::getType()
{
    return "т╡пн";
}
