#include "cylinder.h"

Cylinder::Cylinder(int x, int y, int r, int h):
    Circle(x, y, r),h(h)
{
    
}

float Cylinder::volume()
{
    //为什么这里调用父类函数area不用加父类的域？
    //因为子类没有和父类重名的函数
    return area()*h;
}
