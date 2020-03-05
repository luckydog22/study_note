#include "myrect.h"
#include <iostream>

using namespace std;

void MyRect::input()
{
    cout<<"ÇëÊäÈë ³¤ ¿í ¸ß"<<endl;
    cin>>length>>width>>height;
}

void MyRect::volum()
{
    v = length*width*height;
}

void MyRect::show()
{
    cout<<v<<endl;
}
