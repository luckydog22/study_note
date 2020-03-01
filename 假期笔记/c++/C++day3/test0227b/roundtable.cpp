#include "roundtable.h"
#include <iostream>

using namespace std;

RoundTable::RoundTable(int r, string color, int height):
    Circle(r),
    Table(color, height)
{
    
}

void RoundTable::show()
{
    cout<<height<<" "<<3.14f*r*r<<" "<<color<<endl;
}
