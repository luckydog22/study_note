#include <iostream>
#include "mypoker.h"

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age)
	{
		this->age = age;
	}

	Person(const Person& other):age(other.age)
	{
		cout<<"拷贝构造"<<endl;
	}

	void show()
	{
		cout<<this->age<<endl;
	}
};

int main()
{
	Person a(19);
	cout<<"start"<<endl;
	Person b(a);//调用对象b 的拷贝构造函数
	cout<<"end"<<endl;
	b.show();
}
//int main()
//{
    //练习1
//    Dog d;
//    d.setName("小明");
//    d.sleep();
//    d.eat();
    //练习2
//    MyStack mt;
//    for(int i = 0;i < 100;i++)
//    {
//        mt.push(i);
//    }
//    cout<<"-----------"<<endl;
//    for(int i = 0;i < 100;i++)
//    {
//        cout<<mt.top()<<endl;//输出当前栈顶元素
//        mt.pop();//出栈
//    }
    //练习3
//    MyLink ml;
//    for(int i = 0;i < 100;i++)
//    {
//        ml.add(i);
//    }
    
//    for(int i = 0;i < ml.getSize();i++)
//    {
//        cout<<ml.get(i)<<endl;
//    }
    //练习4
//    MyPrint mp;
//    mp.print();
//    cout<<"---------"<<endl;
//    mp.print('*');
    //练习5
//    MyArr ma;
//    int arr[5] = {12,34,56,89,43};
//    ma.input(arr, 5);
//    cout<<ma.max()<<endl;
//    cout<<ma.min()<<endl;
//    cout<<ma.agv()<<endl;
    //练习6
//    MyRect mr;
//    mr.input();
//    mr.volum();
//    mr.show();
    //练习7
    //栈
//    MyLongRect mlr(2, 4);//给构造函数传参数，但是这里不是直接调用构造函数
//    cout<<mlr.l()<<endl;
    //堆
//    MyLongRect* mlr = new MyLongRect(2, 4);
//    cout<<mlr->l()<<endl;
//    delete mlr;
    //练习8
//    MyF mf(2, 7);
//    mf.show();
    //练习9
//    MyTime mt(23, 59, 55);
//    for(int i = 0;i < 10;i++)
//    {
//        mt.go();
//        mt.show();
//    }
    //练习10
//    MyPoker pokers[54];//创建类类型对象数组时，会调用类的无参构造函数对数组元素初始化
//    string colors[4] = {"红桃","黑桃","方片","草花"};
//    string points[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
//    int index = 0;
//    for(int i = 0;i < 4;i++)
//    {
//        for(int j = 0;j < 13;j++)
//        {
//            pokers[index++] = MyPoker(colors[i], points[j]);//匿名对象赋值
//            //或者
////            MyPoker mp(colors[i], points[j]);
////            pokers[index++] = mp;
//        }
//    }
//    pokers[index++] = MyPoker("大王");
//    pokers[index] = MyPoker("小王");
//    for(int i = 0;i < 54;i++)
//    {
//        pokers[i].show();
//    }
//    return 0;
//}

