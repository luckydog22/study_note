一、指针

1、变量可能存在的空间：
1.堆：自定义生命周期malloc-free   new-delete 
2.栈：作用域开始执行创建，作用域结束{}变量释放  
3.静态：与程序一样长生命周期

动态空间的申请和释放
c中 函数 malloc-free  #include<cstdlib>      malloc申请的内存空间是没有类型的void* ，内有初始化
c++中 关键字 new-delete 										 new申请的内存空间是有类型的，有初始化
1.变量
#include<iostream>
using namespace std;

int main()
{//类类型的变量叫对象，内置类型int char float等等叫变量
	int *p = new int;//开辟一个存放整型数的空间 返回空间的首地址
	int* p2 = new int(100);//将堆空间的int类型变量初始化成100
	*p = 123;

	cout<<"p:"<<p<<' '<<"*p:"<<*p<<endl;

	delete p;//p是野指针
	p = NULL;//将野指针置成NULL保证误使用时一定会出错
}

2.数组
#include<iostream>
using namespace std;

int main()
{
	//动态创建数组new 类型[数组长度] 数组长度可以是变量
	int *p = new int[10];//开辟一块存储整形数据的数组空间 大小为10*sizeof(int) 返回该空间首地址，没有初始化
	int len = 20;
	int* p3 = new int[len];
	//int arr[len];//这个数组的创建是错误的，因为这不是动态创建，长度只能是常量
	int *p2 = new int[10]();//初始化成0  ()内不可以填写数字，只能初始化成0
	for(int i=0;i<10;i++)
	{
		p[i] = i+1;
	}

	for(int i=0;i<10;i++)
	{
		cout<<p[i]<<' ';
	}

	delete[] p;//释放数组空间
	p = NULL;
}

数组扩张
#include <iostream>
using namespace std;

int arrLen = 10;
void expand(int*& arr);

int main()
{
	int* arr = new int[arrLen];

	int len;//如果len大于10，上面动态创建的数组就不够长了
	cin>>len;
	for(int i = 0;i < len;i++)
	{
		if(i == arrLen)//if条件为真，说明原数组不够长了，需要扩张
		{
			expand(arr);
		}
		arr[i] = i;
	}

	for(int i = 0;i < len;i++)
	{
		cout<<arr[i]<<endl;
	}

	delete[] arr;
	return 0;
}

void expand(int*& arr1)
{
	int newLen = arrLen*2;//新的数组长度
	int* newArr = new int[newLen];//创建新的数组，长度是原数组的2倍

	for(int i = 0;i < arrLen;i++)//将原数组中的数据复制到新的数组中
	{
		newArr[i] = arr1[i];
	}
	delete[] arr1;// 删除原来的数组
	arr1 = newArr;//arr1是函数的参数，arr1在函数结束后就应该消失了呀？
	//arr1是引用，在这里是main函数中的arr在expand函数的别名，所以这里是
	//对main函数中的arr赋值
	arrLen = newLen;
}

二、类的初步
为什么要使用类？


《三傻大闹宝莱坞》：
“记录,分析,总结,整理的工具；讨论并解释知识,有图片的和没图片的；
硬皮的,软装订的,护封的,没护封的；有前言,简介,目录,索引；
用于人类大脑的启示,理解,改进,加强和教育；通过视觉实现,有时也用触觉.”



1.定义类
class 类名
{
public:
};
2.创建类实例对象
3.调用类成员

示例1：栈空间创建对象并调用成员函数
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	//成员函数之间共用成员变量
	string name;//成员变量  属性
	int age;	//成员变量  属性

	void setName(string n)//成员函数
	{
		name = n;
	}

	void setAge(int a)
	{
		age = a;
	}

	void print()
	{
		cout<<name<<" "<<age<<endl; 
	}
};
int main()
{
	//对象.   指针->
	Student xiaoming;//栈空间创建
	xiaoming.setName("小明");
	xiaoming.setAge(18);
	xiaoming.print();
}

示例2：堆空间创建对象

int main()
{
	Student* p = new Student;
	p->setName("小明");
	p->setAge(18);
	p->print();
	delete p;//不delete就会内存泄漏
}


练习：定义Dog类，有成员变量name，有成员函数setName起名，
	sleep睡觉，eat吃饭
1.setName给属性name赋值
2.sleep输出xxx睡觉了
3.eat输出xxx妈妈喊你回家吃饭了


练习：自定义一个类实现栈结构，有出栈（pop）和入栈（push）功能，
	（top）获得栈顶元素，可以存放任意多整数
1.成员变量指针指向数组
2.成员变量表示数组长度
3.成员函数pop()和push()、top()
4.成员变量表示栈针 int index
5.成员init给成员变量赋初始值（这里我要使用构造函数）


练习：定义链表类class Link
1.链表节点结构体
struct Node
{
		int num;
		Node* pNext;
};
2.成员指针指向链表头pHead和链表尾pTail
3.成员变量表示链表长度size
4.成员函数add向链表尾部插入数据
5.成员函数get获得指定位置的数据



三、函数
1、(函数)重载：overload(是英文名，不是关键字)
重载是为了提升代码可读性的
c++允许创建多个名称相同的函数(同一个函数名定义多个函数  一物多用)
要求：形参列表必须不同（形参类型或者形参个数），返回值类型无所谓
注意：如果形参列表相同 但返回值不同 是不可以重载
1.形参个数不同，全局函数的重载
#include<iostream>
using namespace std;

int fun(int a)
{
	return a*a;
}

int fun(int a,int b)
{
	return a*b;
}

int main()
{
	cout<<fun(10)<<endl;
	cout<<fun(20,40)<<endl;
}

2.类型不同
示例：

#include <iostream>

using namespace std;

int dev(int num1, int num2)
{
	return num1/num2;
}

float dev(float num1, float num2)
{
	return num1/num2;
}

int main()
{
	cout<<dev(10, 3)<<endl;
	cout<<dev(10.0f, 3.0f)<<endl;
}

练习： 定义一个类，定义二维数组成员，重载函数print，
	分别实现常规打印数组元素和以一定格式打印数组
1.print()元素之间使用空格
2.print(char space)元素之间使用space


2、函数默认参数
默认参数：函数调用时 形参从实参得到值 
传递参数的时候，一定是从参数列的表左边开始传递
可以给形参一个默认值 形参值就不必从实参取值了
注意：形参列表只能从右侧开始有默认值 
示例1：
#include<iostream>
using namespace std;

void func(int a=80,int b=90,int c=100)//实参传递 形参的值为传递过来的值 如果实参不传递 则形参的值为默认值
{
	cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
}
int main()
{
	func(10,20,30);
	func(10,20);
	func(10);
	func();
}


示例2：
函数如果在声明时给了默认值，那么在实现的时候就不能添加默认值
#include<iostream>
using namespace std;

void func(int year=2016);//函数声明时 指定了默认值2016 则函数调用时 可以不指定实参
int main()
{
	func();
}

void func(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
	{
		cout<<"leap year!"<<endl;
	}
	else 
	{
		cout<<"common year!"<<endl;
	}
}

注意：函数参数的默认值，要从后面的参数开始定义

四、访问权限 
c++中类class从c的struct 扩展而来 
c++的class和struct只有一个语法区别，默认访问权限不一样
class默认是private，struct默认是public
习惯：c++中定义逻辑类的时候使用class，定义数据类型的时候使用struct，如果区分不清
	就全用class。

1.声明一个类 
class 类名 //c++中类名代表类的类型 
{
	//访问权限
	public:
		公有的数据和函数; 谁都可以访问
	private:
		私有的数据和函数; 之后本类的内部可以访问
	protected://继承的时候再讲
		受保护的数据和函数; 之后本类和派生类可以访问
};//必须加分号

//数据：成员变量 函数：成员函数  成员函数可以访问私有变量
#include <iostream>

using namespace std;

class Person
{
private://私有属性  类的外部不能访问  类的外部：在类以外定义的函数
	int money;
	int house;
	int phone;
public:
	void setInfo(int m, int h, int p) //公共的函数 类的外部可以访问
	{
		money = m;	//类的内部可以任意访问私有属性
		house = h;
		phone = p;
	}

	void show()
	{
		cout<<money<<" "<<house<<" "<<phone<<endl;
	}
};

int main()
{
	Person p;
	p.money = 10;//main函数不是类中的函数，对类中的私有成员没有访问权限
	p.setInfo(1,2,3);
	p.show();
	return 0;
}

练习：定义类 向数组中输入整数 并求出数组元素中的最大值，最小值和平均值
1.数组成员变量private修饰，应该是一个指针
2.成员函数input输入数组的值和数组长度  动态创建（根据当前的逻辑创建）
3.成员函数max
4.成员函数min
5.成员函数agv

练习：定义一个类，数据成员：length,width,heigh 
成员函数如下功能：
1.由键盘输入长方体的长宽高  input函数中输入
2.计算长方体体积
3.输出长方体体积


五、构造函数
目的：为了给对象初始化，不仅是为了初始化成员变量，也可以执行一些初始化的逻辑。
构造函数：在创建对象的时候会自动调用的函数 
是c++中特殊成员函数 主要是在创建对象时 初始化对象 为对象的成员变量赋值
(1)
注意：
a、名字必须与类同名 无返回值 可能有参数
b、访问权限一般是public，没有构造函数的访问权限就不能创建对象
c、用户不能调用构造函数 只有在类对象创建时 自动调用
class Person 
{
	public:
		Person()//构造函数
		{
			;
		}
};

示例1：

#include<iostream>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:

	Person()
	{
		cout<<"i am constructor...."<<endl;	
	}
	void show()
	{
		cout<<"我是"<<name<<"  今年"<<age<<endl;
	}
};

int main()
{
	Person x;
}

示例2：
#include<iostream>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:

	Person()
	{
		//赋值:  先定义，后赋值。  比如 int a; a = 10;
		//初始化: 定义变量的时候赋值叫初始化  比如int a = 10;
		name="guanyu";//成员变量赋值   
		age = 0;//成员变量赋值
	}
	void show()
	{
		cout<<"我是"<<name<<"  今年"<<age<<endl;
	}
};

int main()
{
	Person x;//x创建时 自动调用构造函数 完成初始化工作
	x.show();
}

练习：计算长方形周长 构造函数实现长宽赋值（构造函数带参数）


5.构造函数的初始化列表：
初始化列表的目的是给成员变量初始化。
构造函数用冒号形式引出初始化列表：
注意：初始化顺序是按照成员声明的顺序，初始化成员的顺序应该和成员声明的顺序保持一致，不建议使用成员初始化其他成员
格式：成员变量名(初始值)

#include <iostream>

using namespace std;

class Rect
{
private:
	int width;
	int height;
public:
	Rect(int width, int height):width(width),height(height)//在初始化列表中被初始化的必须是成员变量
	{
	}

	int perimeter()
	{
		return width*2+height*2;
	}
};

int main()
{
	Rect* p = new Rect(10, 20);//将参数传递给构造函数
	cout<<p->perimeter()<<endl;
	Rect r(10, 20);
	cout<<r.perimeter()<<endl;
}

示例：初始化顺序
创建类对象的时候，先初始化成员变量，再调用构造函数；成员变量按照声明顺序初始化。
建议：初始化列表的顺序和声明的顺序保持一致。
《C++ primer》
#include <iostream>

using namespace std;

class A
{
public:
	A(int a)
	{
		cout<<"A"<<endl;
	}
};

class B
{
public:
	B(int a)
	{
		cout<<"B"<<endl;
	}
};

class C
{
private:
	A a;
	B b;
public:
	C():b(1),a(2)
	{
		cout<<"C"<<endl;
	}
};

int main()
{
	C c;//A B C
	return 0;
}
	

练习：实现一个分数类F  功能：F f1(3,4) 显示结果:3/4 
1.构造函数传入参数
2.成员函数show显示




练习：键盘输入时间 显示输入时间的下一秒
1.定义成员变量 h m s
2.成员函数go 改变h m s 的值
3.成员函数show显示下一秒的时间



6.匿名对象
目的：函数传参数、赋值、初始化时不想创建一个有名字的对象。
创建方式：类型名(构造函数的参数)，匿名对象只能栈空间创建。

#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age):age(age)
	{
		cout<<"构造"<<endl;
	}
private:
	int age;
};

void fun(Person p)
{
    
}

int main()
{
    fun(Person(10));
    //或者
    Person p(10);
    fun(p);
｝




练习：定义扑克类，私有属性color，point，创建54张牌存入数组中 (构造函数重载)



六、this指针：是一个指针，指向对象本身，this只能在类的内部使用，在类的内部调用
		成员都是使用this调用的，可以省略
在类的内部调用成员变量和成员函数，都是使用this调用，所以可以省略this；省略this
		的时候叫隐式使用this，写出this的时候叫显式使用this
		
总结：只有类的成员函数可以使用this指针，哪个对象调用的成员函数，this指针就指向
	哪个对象。
		
示例1：
#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age)
	{
		this->age = age;//这个例子只是为了给this找存在感
	}

	void show()
	{
		cout<<age<<endl;
	}
};

int main()
{
	Person p(19);
	p.show();
}

示例2:

#include<iostream>
using namespace std;
class Person 
{
public:
	Person(string n,bool g=true);

	void setAge(int year);
	void show();
	void marry(Person &other);
private:
	string name;
	bool gender;
	int age;
	Person *lover;
};

Person::Person(string n,bool g)
{
			name=n;
			gender = g;
			age = 0;
			lover=NULL;
}

void Person::setAge(int year)
{
	this->age = year;
}

void Person::show()
{
	cout<<"大家好！我是"<<(gender?"帅哥":"美女  ")<<name<<"，今年"<<age<<endl;
	cout<<"爱人是:"<<lover->name<<endl;
}

void Person::marry(Person& other)
{
	this->lover = &other;
	other.lover = this;//this 指针 指向当前对象
	cout<<name<<"和"<<other.name<<"喜结良缘!"<<endl;

	cout<<this<<endl;
}

int main()
{
	Person b("邓超",true);
	Person a("孙俪",false);
	a.setAge(20);
	b.setAge(38);

	a.marry(b);
	a.show();
	//b.marry(a);
	b.show();
}

七、拷贝构造函数
1、声明：  函数名（类名）(const 本类类名 &对象名)  //复制构造函数
使用同类型的一个对象初始化另一个对象的时候调用拷贝构造

#include <iostream>

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

