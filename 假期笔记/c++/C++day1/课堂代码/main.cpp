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
		cout<<"��������"<<endl;
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
	Person b(a);//���ö���b �Ŀ������캯��
	cout<<"end"<<endl;
	b.show();
}
//int main()
//{
    //��ϰ1
//    Dog d;
//    d.setName("С��");
//    d.sleep();
//    d.eat();
    //��ϰ2
//    MyStack mt;
//    for(int i = 0;i < 100;i++)
//    {
//        mt.push(i);
//    }
//    cout<<"-----------"<<endl;
//    for(int i = 0;i < 100;i++)
//    {
//        cout<<mt.top()<<endl;//�����ǰջ��Ԫ��
//        mt.pop();//��ջ
//    }
    //��ϰ3
//    MyLink ml;
//    for(int i = 0;i < 100;i++)
//    {
//        ml.add(i);
//    }
    
//    for(int i = 0;i < ml.getSize();i++)
//    {
//        cout<<ml.get(i)<<endl;
//    }
    //��ϰ4
//    MyPrint mp;
//    mp.print();
//    cout<<"---------"<<endl;
//    mp.print('*');
    //��ϰ5
//    MyArr ma;
//    int arr[5] = {12,34,56,89,43};
//    ma.input(arr, 5);
//    cout<<ma.max()<<endl;
//    cout<<ma.min()<<endl;
//    cout<<ma.agv()<<endl;
    //��ϰ6
//    MyRect mr;
//    mr.input();
//    mr.volum();
//    mr.show();
    //��ϰ7
    //ջ
//    MyLongRect mlr(2, 4);//�����캯�����������������ﲻ��ֱ�ӵ��ù��캯��
//    cout<<mlr.l()<<endl;
    //��
//    MyLongRect* mlr = new MyLongRect(2, 4);
//    cout<<mlr->l()<<endl;
//    delete mlr;
    //��ϰ8
//    MyF mf(2, 7);
//    mf.show();
    //��ϰ9
//    MyTime mt(23, 59, 55);
//    for(int i = 0;i < 10;i++)
//    {
//        mt.go();
//        mt.show();
//    }
    //��ϰ10
//    MyPoker pokers[54];//���������Ͷ�������ʱ�����������޲ι��캯��������Ԫ�س�ʼ��
//    string colors[4] = {"����","����","��Ƭ","�ݻ�"};
//    string points[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
//    int index = 0;
//    for(int i = 0;i < 4;i++)
//    {
//        for(int j = 0;j < 13;j++)
//        {
//            pokers[index++] = MyPoker(colors[i], points[j]);//��������ֵ
//            //����
////            MyPoker mp(colors[i], points[j]);
////            pokers[index++] = mp;
//        }
//    }
//    pokers[index++] = MyPoker("����");
//    pokers[index] = MyPoker("С��");
//    for(int i = 0;i < 54;i++)
//    {
//        pokers[i].show();
//    }
//    return 0;
//}

