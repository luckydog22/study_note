#include <iostream>
#include "point.h"
#include "circle.h"
#include "cylinder.h"

using namespace std;


int main()
{
    //练习1
//    Triange t(4,5,6);
//    Triange t1(6,7,8);
//    int l = t+t1;//运算符重载很优雅
//    cout<<l<<endl;
    //练习2
//    Student students[3] = {Student(1,2,3), Student(4,5,6), Student(7,8,9)};
//    Student sum(0,0,0);
//    for(int i = 0;i < 3;i++)
//    {
//        cout<<"----------"<<endl;
//        sum+=students[i];//因为函数结束后，对象不会被删除，所以会调用拷贝构造生成新的对象
//        cout<<"+++++++++"<<endl;
//    }
//    sum.show();
    //练习3
//    Time t(23, 59, 55);
//    for(int i = 0;i < 10;i++)
//    {
//        t++;
//        t.show();
//    }
    //练习4
//    Vehicle v(4, 1200);
//    Car c(4, 1100, 5);
//    Truck t(12, 20000, 5, 30000);
//    v.show();
//    c.show();
//    t.show();
    //练习5
    Circle c(0, 0, 4);
    cout<<c.area()<<endl;
    Cylinder cyl(0, 0, 4, 3);
    cout<<cyl.volume()<<endl;
	return 0;
}