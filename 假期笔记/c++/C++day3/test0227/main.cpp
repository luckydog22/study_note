#include <iostream>
#include "point.h"
#include "circle.h"
#include "cylinder.h"

using namespace std;


int main()
{
    //��ϰ1
//    Triange t(4,5,6);
//    Triange t1(6,7,8);
//    int l = t+t1;//��������غ�����
//    cout<<l<<endl;
    //��ϰ2
//    Student students[3] = {Student(1,2,3), Student(4,5,6), Student(7,8,9)};
//    Student sum(0,0,0);
//    for(int i = 0;i < 3;i++)
//    {
//        cout<<"----------"<<endl;
//        sum+=students[i];//��Ϊ���������󣬶��󲻻ᱻɾ�������Ի���ÿ������������µĶ���
//        cout<<"+++++++++"<<endl;
//    }
//    sum.show();
    //��ϰ3
//    Time t(23, 59, 55);
//    for(int i = 0;i < 10;i++)
//    {
//        t++;
//        t.show();
//    }
    //��ϰ4
//    Vehicle v(4, 1200);
//    Car c(4, 1100, 5);
//    Truck t(12, 20000, 5, 30000);
//    v.show();
//    c.show();
//    t.show();
    //��ϰ5
    Circle c(0, 0, 4);
    cout<<c.area()<<endl;
    Cylinder cyl(0, 0, 4, 3);
    cout<<cyl.volume()<<endl;
	return 0;
}