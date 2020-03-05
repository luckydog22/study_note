#include "mylongrect.h"

MyLongRect::MyLongRect(int w, int l)
{
    width = w;
    length = l;
}

int MyLongRect::l()
{
    return (width+length)*2;
}
