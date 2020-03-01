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
    //为了调用子类中定义的函数，所以必须将指针转换成子类类型
    Salasman* s = dynamic_cast<Salasman*>(e);
    if(s == NULL)
    {
        cout<<"转换失败"<<endl;
    }
    else
    {
        cout<<"成功"<<endl;
    }
}

int main()
{
   Employee* s = new Employee;
   fun(s);
    //练习8
//    RoundTable rt(3, "灰色的", 2);
//    rt.show();
    //练习9
//    Boss b("小明", 18, "111", "222", "333", "444");
//    b.develop();
//    b.eat();
//    b.lead();
    //练习10
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
//    //一样的代码，只是因为指针指向的对象不一样，就执行出了不同的逻辑，多态
//    cout<<p->getType()<<" "<<p->getPerimeter()<<endl;
    return 0;
}

