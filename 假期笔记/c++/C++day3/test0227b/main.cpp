#include <iostream>

using namespace std;

class Employee
{
public:
	virtual void work(){}
};

class Salasman : public Employee
{
public:
	
};

void fun(Employee* e)
{
    //Ϊ�˵��������ж���ĺ��������Ա��뽫ָ��ת������������
    Salasman* s = dynamic_cast<Salasman*>(e);
    if(s == NULL)
    {
        cout<<"ת��ʧ��"<<endl;
    }
    else
    {
        cout<<"�ɹ�"<<endl;
    }
}

int main()
{
   Employee* s = new Employee;
   fun(s);
    //��ϰ8
//    RoundTable rt(3, "��ɫ��", 2);
//    rt.show();
    //��ϰ9
//    Boss b("С��", 18, "111", "222", "333", "444");
//    b.develop();
//    b.eat();
//    b.lead();
    //��ϰ10
//    Shap* p;
//    srand(time(0));
//    switch(rand()%3)
//    {
//    case 0:
//        p = new Triangle(4,5,6);
//        break;
//    case 1:
//        p = new Square(2);
//        break;
//    case 2:
//        p = new CircleShap(3);
//        break;
//    }
//    //һ���Ĵ��룬ֻ����Ϊָ��ָ��Ķ���һ������ִ�г��˲�ͬ���߼�����̬
//    cout<<p->getType()<<" "<<p->getPerimeter()<<endl;
    return 0;
}

