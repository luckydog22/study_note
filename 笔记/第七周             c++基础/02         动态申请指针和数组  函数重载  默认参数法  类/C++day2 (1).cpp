小测试：
1.简单介绍面向过程和面向对象思想的差异

2.使用命名空间的作用

3.自定义teacher命名空间，其中包含int age， 输出age

4.string s1 = "hello world";
	char buf[100];
	1）使用sprintf格式化字符串s1   

5.引用的特点

=============================================================
复习：
1.cout cin 
2.#include<iostream> using namespace std;
3.cout<<a  cin>>a
4.linux   vi  g++ 
5.endl  
6.名字空间
使用：
using namspace std;
using std::cin;
std::cin>>a 

自定义名字空间：
(1)名字空间::name
(2)内部优先 
(3)全局变量 匿名空间  ::name

8.bool 
9.string 
使用：string iostream std 
string s1;
strcpy strcat strcmp  = += 
 ----------------------------------------------------------------------------------	


总结：

1.引用的特点
	引用必须初始化。
	引用不能单独存在。
	引用也不能改变指向。
	普通引用不能指向常量与临时量。

2.引用与指针的区别

	引用很容易与指针混淆，它们之间有三个主要的不同
  1） 不存在空引用。引用必须连接到一块合法的内存。
  2） 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
  3） 引用必须在创建时被初始化。指针可以在任何时间被初始化。

笔试简答题：

【题目1】引用和指针有什么区别？
	引用是一个变量的别名，指针是一个变量，存的另一个变量的地址。
	引用不能为空引用，指针可以是空指针。
	引用赋值之后不可以改变指向，指针可以改变。
	引用不能单独存在，指针可以。
	引用必须进行初始化，指针可以随时初始化。

【题目2】函数参数传递中值传递、地址传递、引用传递有什么区别？
	值传递，形参的改变不影响实参，形参和实参只是将值传递过去，实际上地址还是两块地址，所以改变其中一个，不会影响另一个。
	地址传递，形参的改变会影响实参，形参中存的是实参的地址，改变形参中的值，实际上是改变它存的那块地址里的值。
	引用传递，形参的改变也会影响实参， 形参是实参的别名，形参和实参是同一个地址，所以改变一个必然会影响另一个。
	
=============================================================================	



	/*******************
			新课
	*******************/

一、指针

1、变量可能存在的空间：

1.堆： 自定义生命周期 malloc-free   new-delete 
2.栈： 作用域开始执行创建，作用域结束{}变量释放
3.静态： 与程序一样长生命周期                  


2.动态空间的申请和释放

c中   函数   malloc-free  #include<cstdlib>     malloc申请的内存空间是没有类型的void*   不会初始化 
c++中 关键字 new-delete 			            new申请的内存空间是有类型的              给内存初始化

int *p=(int*)malloc(23);//必须强转
int *p = new int;
1.变量
#include<iostream>

using namespace std;

int main()
{
	//开辟一快内存，存放的是整形的数据空间，返回空间首地址
	int* p = new int;
	*p = 123;
	//释放空间
	delete p;
	//ｐ是一个野指针
	p =NULL;//将野指针置成ＮＵＬＬ，保证误使用时一定出错

	//开辟一个空间，并将２００赋值进去
	int* p1 = new int(200);
	delete p1;
	p1 = NULL;
}


2.数组

#include<iostream>

using namespace std;

int main()
{
	//数组
	//开辟一块连续的内存，存储整形的数据空间，大小是10*sizeof(int),返回空间的首地址
	int *p = new int[10];
	for(int i = 0 ; i < 10; i++)
		p[i] = i;//*(p+i) = i;
	for(int i = 0 ; i < 10; i++)
		cout<<p[i];
		cout<<endl;
		
		delete[] p;
#if 0	
	//开辟一快内存，存放的是整形的数据空间，返回空间首地址
	int* p = new int;
	*p = 123;
	//释放空间
	delete p;
	//ｐ是一个野指针
	p =NULL;//将野指针置成ＮＵＬＬ，保证误使用时一定出错

	//开辟一个空间，并将２００赋值进去
	int* p1 = new int(200);
	delete p1;
	p1 = NULL;
#endif
}

注意：释放数组空间 要加[] ； 如果不加[]  删除的是数组的首地址


练习：从键盘输入学生分数 4 统计出最高分 最低分 平均分 要求：空间动态开辟

#include<iostream>

using namespace std;

int main()
{

//数组:动态的分配一块连续的内存空间，ｓｉｚｅｏｆ（ｐ）×５

	int *p = new int[4];

	for(int i = 0 ; i < 4; i++)
	{
		cin>>p[i];
	}
	int max = p[0], min = p[0],sum = p[0],avg = 0;

	for(int i = 1 ; i < 4 ; i++)
	{
		if(max < p[i])
			max = p[i];
		if(min > p[i])
			min = p[i];
		sum +=p[i];
	}

	avg = sum/4;
	cout<<"max = "<<max << "min = "<<min<<"avg = "<<avg<<endl;
	//释放空间
	delete[] p;

}


二、函数延伸

1、重载：overload
c++允许创建多个名称相同的函数(同一个函数名定义多个函数  一物多用)

要求：形参列表必须不同（形参的 类型 个数 至少有一种不同)，返回值无所谓

注意：如果形参列表相同 但返回值不同 是不可以重载

1.形参个数不同

void show(float a,float b)
{
	cout<<b*b<<endl;
}

void show(char s)
{
	cout<<"char...."<<s<<endl;
}

2.形参类型不同，返回值不同
#include <iostream>

using namespace std;

//函数的重载：函数名相同，参数列表不同
int show(int a,int b)
{
	cout<<"int..."<<a*b<<endl;
	return a*b;
}
void show(float a,float b)
{
	cout<<b*b<<endl;
}

void show(char s)
{
	cout<<"char...."<<s<<endl;
}

int main()
{
	int result = show(5,6);
	show(10.0f,3.3f);
	show('a');
}
练习1：重载dev函数，分别进行两个int类型和两个float类型的数相除


练习2：找出两个数最大值(两个数可能是int 也可能是float)
#include<iostream>

using namespace std;

//函数名字相同，参数的类型不同,参数的个数不同

int dev(int a ,int b)
{
	return a/b;
}

float dev(float a, float b)
{
	return a/b;
}

int Max(int a,int b)
{
	return (a>b?a:b);
}
float Max(float a, float b)
{
	return (a>b?a:b);
}



int main()
{
	cout<<dev(10,2)<<endl;
	cout<<dev(10.02f,2.0f)<<endl;

	cout<<Max(12,5)<<endl;
	cout<<Max(15.2f,2.4f)<<endl;
}




2、函数默认参数
默认参数：函数调用时 形参从实参得到值 
可以给形参一个默认值 形参值就不必从实参取值了
注意：形参列表只能从右侧开始有默认值 

示例1：

#include <iostream>

using namespace std;

//函数的重载：函数名相同，参数列表不同
//带默认参数：形参从实参得到值
//注意：形参列表只能从右侧有默认值

void fun(int a= 70,int b =80,int c = 90)
{
	cout<<"a: "<<a<<"b: "<<b<<"c: "<<c<<endl;
}

int main()
{
	fun(10,20,30);
	fun(10,20);
	fun(10);
	fun();
}


示例2：带声明的
#include <iostream>

using namespace std;


void fun(int a= 70,int b =80,int c = 90);
int main()
{
	fun(10,20,30);
	fun(10,20);
	fun(10);
	fun();
}
//函数的重载：函数名相同，参数列表不同
//带默认参数：形参从实参得到值
//注意：形参列表只能从右侧有默认值

void fun(int a,int b,int c )
{
	cout<<"a: "<<a<<"b: "<<b<<"c: "<<c<<endl;
}

练习：判断一个年份是否是闰年，声明中给默认年份2016

#include<iostream>

using namespace std;

//函数的重载：函数名字相同，参数的类型不同,参数的个数不同，返回值无所谓
//带默认参数：形参从实参得到值
//注意：形参列表从右侧开始有默认值


//函数的声明:　默认参数要在声明给加，函数不能有默认参数
void fun(int year = 2016);


int main()
{
//	fun(10,20,30);//实参
//	fun(10,20);
//	fun(10);
	fun();
}
void fun(int year )//形参
{
	if(year %4 == 0 && year %100 != 0 || year %400 == 0)
	{
		cout<<"leap year"<<endl;	
	}
	else
		cout<<"not"<<endl;
}




二、类的初步

从群众中来 到群众中去
客观-抽象-客观


1.定义类
class 类名
{
public:公有
};
2.创建类实例对象
	类名 对象名; 
3.调用类成员
	对象名.属性;
	对象名.方法();
	

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
	Student xiaoming;//栈空间创建
	xiaoming.setName("小明");
	xiaoming.setAge(18);
	xiaoming.print();
}

练习： 定义一个类，定义二维数组成员，重载函数print（），分别实现常规打印数组元素和以一定格式打印数组

数组数据初始化	    init();向二维数组中装入数据
0 1 2 3             print();
1 2 3 4
2 3 4 5

0#1#2#3            print(char space);
1#2#3#4
2#3#4#5

#include<iostream>


using namespace std;

class Array
{
public:
	int arr[3][4];

	void init()
	{
		for(int i = 0 ; i < 3; i++)
			for(int j = 0 ; j <4 ; j++)
				arr[i][j] = i+j;
	}
	void print()
	{
		for(int  i = 0 ; i < 3 ; i++)
		{
			for(int j = 0 ; j < 4 ;j ++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	void print(char space)
	{
		for(int i = 0 ; i  <3 ; i++)
		{
			for(int  j = 0 ; j  <4 ; j++)
			{
				if(j < 3)
				{
					cout<<arr[i][j]<<space;
				}else
				{
					cout<<arr[i][j]<<endl;
				}
			}
		}
	}

};


int main()
{
	Array array;
	array.init();
	array.print();
	array.print('#');
}


练习1：定义Dog类，有成员变量name，有成员函数setName起名，sleep睡觉，eat吃饭
	1.setName给属性name赋值
	2.sleep输出xxx睡觉了
	3.eat输出xxx妈妈喊你回家吃饭了

#include<iostream>
#include<string>
using namespace std;
class Dog
{
public:
	string name;

	void setName(string n)
	{
		name = n;
	}
	void sleep()
	{
		cout<<name<<"睡觉了"<<endl;
	}
	void eat()
	{
		cout<<name<<"妈妈喊你回家吃饭了"<<endl;
	}
};


int main()
{
	Dog d;
	d.setName("巧克力");
	d.sleep();
	d.eat();
}



示例2：堆空间创建对象

int main()
{
	Student* p = new Student;
	p->setName("小明");
	p->setAge(18);
	p->print();
	
	//删除对象
	delete p;
}


练习2：定义一个Circle类，有成员变量radius，有成员函数（setRadius）设置半径，（getLength）求周长，（getArea）求面积，π取3.14。
输入半径求出该半径的圆周长和面积
#include<iostream>
#include<string>
using namespace std;

#define PAI 3.14

class Circle
{
public:
	int radius;
	void setRadius( int r)
	{
		radius = r;
	}
	int getLength()
	{
		return 2*PAI*radius;
	}
	int getArea()
	{
		return PAI*radius*radius;
	}


};



int main()
{
	Circle *c = new Circle;
	c->setRadius(2);
	cout<<"length: "<<c->getLength()<<endl;
	cout<<"area: "<<c->getArea()<<endl;

}


练习3：自定义一个类实现栈结构，有出栈（pop）和入栈（push）功能，可以存放任意多整数

	1.成员变量指针指向数组int* stack;
	2.成员变量表示数组长度length
	3.成员函数pop()和push(int data)
	4.成员变量表示栈针index
	5.成员init给成员变量赋初始值(index，length = 10，创建数组)
	
	6.成员函数expand(); 扩充数组，扩充为原数组二倍长度

#include<iostream>

using namespace std;

class MyStack
{
public:
	int *p;
	int length;
	int index;
	//初始化：成员变量
	void init()
	{
		length = 10;
		p = new int[length];
		index = 0;
	}
	//进栈
	void push(int data)
	{
		if(index == length)
			expand();
		p[index] = data;
		index++;

	}
	//出栈
	int pop()
	{
		index--;
		return p[index];
	}
	//扩展函数
	void expand()
	{
		int newLength = length*2;
		int *newArr = new int[newLength];
		for(int i = 0 ; i < length; i++)
		{
			newArr[i] = p[i];
		}
		delete p;
		p = newArr;
		length = newLength;
		
	}

};

int main()
{
	MyStack* mt = new MyStack;
	mt->init();
	for(int i = 0 ; i < 30; i++)
		mt->push(i);
	for(int i = 0 ; i < 10; i++)
	cout<<mt->pop()<<"  ";
	cout<<endl;
}

//练习4：定义链表类class Link

1.链表节点结构体
struct Node
{
		int num;
		Node* pNext;     
};
2.成员指针指向链表头pHead和链表尾pTrail
3.成员变量表示链表长度size
4.成员函数add(int data)向链表尾部插入数据
5.成员函数get获得指定位置的数据


#include<iostream>

using namespace std;

class myLink
{
public:
	struct  Node
	{
		int num;
		Node* pNext;
	};
	Node* pHead;
	Node* pTail;
	int size;

	void init()
	{
		//1.创建空头结点
		Node* pNode = new Node;
		pNode->pNext = NULL;
	
		//2.头　尾指针　指向头结点
		pHead = pNode;
		pTail = pNode;
		//３．ｓｉｚｅ为０　头结点不计入链表长度
		size = 0;
	}

	void add(int data)
	{
		//１．创建新结点
		Node* pNode =  new Node;

		//２．ｄａｔａ保存到ｎｕｍ变量中
		pNode->num = data;
		//３．尾指针的ｎｅｘｔ指向新创建的结点
		pTail->pNext = pNode;
		//４．尾指针指向新创建的结点
		pTail = pNode;
		//５．长度＋＋
		size++;
	}

	int get(int index)
	{
		//找到头位置　pHead
		Node* pNode = pHead->pNext;
		for(int i = 0 ; i < index; i++)
		{
			//指针偏移
			pNode = pNode->pNext;
		}
		return pNode->num;
	}

};

int main()
{
	myLink* ml = new myLink;
	ml->init();
	for(int i = 0 ; i < 15; i++)
	{
		ml->add(i);
	}
	cout<<ml->get(2)<<endl;

	for(int i = 0 ; i < 15; i++)
		cout<<ml->get(i)<<"  ";
	cout<<endl;
	
}












	
     	  




