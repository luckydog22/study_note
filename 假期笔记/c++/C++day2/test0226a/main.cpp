#include <iostream>
#include "oneinstance.h"

using namespace std;

int main()
{
    //��ϰ4
//    Teacher t;
//    t.sort();
//    t.show();
    //����ģʽ
//    OneInstance* p1 = OneInstance::getInstance();
//    OneInstance* p2 = OneInstance::getInstance();
//    OneInstance* p3 = OneInstance::getInstance();
//    OneInstance* p4 = OneInstance::getInstance();
//    cout<<p1<<endl;
//    cout<<p2<<endl;
//    cout<<p3<<endl;
//    cout<<p4<<endl;
    
//    OneInstance::releaceInstance();
    int a = 10;
    //++a = 20;//�����������1��Ȼ�󷵻��Լ�������++a���ص��Ǳ���a����
    a++ = 20;//���ص���a��1֮ǰ��ֵ��������a����a�����ʱ�Ѿ��Ǽ�1֮���ֵ��
    cout<<a<<endl;
    return 0;
}











