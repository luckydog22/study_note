#include "triange.h"


Triange::Triange(int a, int b, int c):a(a),b(b),c(c)
{
    
}

int Triange::operator+(const Triange &other)
{
    int lself = a+b+c;
    int lother = other.a+other.b+other.c;
    return lself+lother;
}
