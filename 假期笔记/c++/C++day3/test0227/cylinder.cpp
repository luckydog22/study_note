#include "cylinder.h"

Cylinder::Cylinder(int x, int y, int r, int h):
    Circle(x, y, r),h(h)
{
    
}

float Cylinder::volume()
{
    //Ϊʲô������ø��ຯ��area���üӸ������
    //��Ϊ����û�к͸��������ĺ���
    return area()*h;
}
