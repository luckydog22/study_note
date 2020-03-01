#include "triangle.h"

Triangle::Triangle(int a, int b, int c):a(a),b(b),c(c)
{
    
}

int Triangle::getPerimeter()
{
    return a+b+c;
}

string Triangle::getType()
{
    return "Èý½ÇÐÎ";
}
