
链表无空头：
练习讲解：定义链表类class Link
1.链表节点结构体
struct Node
{
		int num;
		Node* pNext;
};
2.成员指针指向链表头pHead和链表尾pTrail
3.成员变量表示链表长度size
4.成员函数add向链表尾部插入数据
5.成员函数get获得指定位置的数据

#include <iostream>

using namespace std;

class MyLink
{
	struct Node
	{
		int num;
		Node* pNext;
	};
public:
	Node* pHead;
	Node* pTrail;
	int size;

	void init()
	{
		pHead = NULL;
		pTrail = NULL;
		size = 0;
	}

	void add(int data)
	{
		Node* pNode = createNode(data);
		if(pHead == NULL)
		{
			pHead = pNode;
			pTrail = pNode;
			return;
		}
		pTrail->pNext = pNode;
		pTrail = pNode;
	}

	int get(int index)
	{
		Node* pNode = pHead;
		for(int i = 0;i < index;i++)
		{
			pNode = pNode->pNext;
		}
		return pNode->num;
	}

	Node* createNode(int data)
	{
		Node* pNode = new Node;
		pNode->num = data;
		pNode->pNext = NULL;
		return pNode;
	}
};


int main()
{
	MyLink* pLink = new MyLink;
	pLink->init();

	for(int i = 0;i < 10;i++)
	{
		pLink->add(i);
	}

	for(int i = 0;i < 10;i++)
	{
		cout<<pLink->get(i)<<endl;
	}
}
==================================================
复习

空间：
new 
 
int *p;
p = new int;
delete p

p = new int[20];
delete[] p

stu *ps;
ps = new stu;
delete ps;


函数重载：函数名相同 形参列表(类型、参数的个数)，返回值无所谓

函数默认参数：
void fun(int a, int b = 10, int c = 10)
{
	
}

fun(1);

struct class异同 

类：
class Person
{
public:
	input();
private: 
		string name;
		int age;
};

【题目1】如何格式化输出bool类型的值？
在打印输出bool变量前使用boolalpha转换，使用noboolalpha解除转换。
cout << boolalpha << true << noboolalpha << endl;

【题目2】面向对象的三大特征是什么？请简要描述一下？
(1)封装，将具有相同属性和行为的一系列对象封装成一个类，将一系列重复性的代码封装成函数，数据的隐藏，将不对外公开的属性和行为使用private进行修饰，保证数据安全。
(2)继承，子类继承父类的所有非private的变量和函数，C++的继承允许一个子类同时继承多个父类。
(3)多态，一种状态多种表现形式，具体体现在父类指针（引用）指向子类对象。

/*****************************

		新课
		
******************************/

一、面向对象

c++中类class从c的struct 扩展而来

1.类与结构体的异同
	 	
	概念：class和struct的语法基本相同，从声明到使用，都很相似，但是struct的约束要比class多，理论上，struct能做到的class都能做到，但class能做到的stuct却不一定做的到。
	  类型：struct是值类型，class是引用类型，因此它们具有所有值类型和引用类型之间的差异。
	  效率：由于堆栈的执行效率要比堆的执行效率高，但是堆栈资源却很有限，不适合处理逻辑复杂的大对象，因此struct常用来处理作为基类型对待的小对象，而class来处理某个商业逻辑。

2.类与结构体的使用时机

   在表示诸如点、矩形等主要用来存储数据的轻量级对象时，首选struct
   在表示数据量大、逻辑复杂的大对象时，首选class。
   在表现抽象和多级别的对象层次时，class是最佳选择 


总结：c++中类class从c的struct 扩展而来 
	  c++的class和struct只有一个区别，默认访问权限不一样
习惯：c++中定义逻辑类的时候使用class，定义数据类型的时候使用struct

***测试访问权限
c++中struct 和class区别
struct 默认访问权限是 public
class 默认访问权限是 private

class Person
{
	int age;//私有权限  private
};

struct Node
{
	int age;//公有权限  public
};

示例：
#include<iostream>
using namespace std;

struct PS//struct中默认的访问权限是公有
{
	string name;
	int age;
	void show()
	{
		cout<<"我是"<<name<<"  今年"<<age<<endl;
	}
};

class PC//类中默认的访问权限是私有的
{
public:
	string name;
	int age;
	void show()
	{
		cout<<"我是"<<name<<"  今年"<<age<<endl;
	}
};
int main()
{
	PS s;
	s.name = "doudou";
	s.age = 18;
	s.show();
	
	PC c;
	c.name="kitty";
	c.age=20;
	c.show();
}

3.声明一个类 
class 类名 //c++中类名代表类的类型 
{
	
	
//访问权限
public:	
	数据（属性）
	函数（行为）
		
};//必须加分号

4.访问权限          
public:
		公有的数据和函数; 谁都可以访问
private:
		私有的数据和函数; 之后本类的内部可以访问
protected://继承的时候再讲
		受保护的数据和函数; 之后本类和派生类可以访问

示例：
#include <iostream>

using namespace std;

class Person
{
private://私有属性  类的外部不能访问
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
	p.setInfo(5,6,7);
	p.show();
	
}


练习：定义类 向数组中输入整数 并求出数组元素中的最大值，最小值和平均值
1.数组成员变量private修饰
2.成员函数input（int length）输入数组的值和数组长度  动态创建（根据当前的逻辑创建）new 
3.成员函数max 要求带返回值
4.成员函数min
5.成员函数agv

#include<iostream>

using namespace std;

class Array
{
private:
	int* p;
	int l;

public:
	void input(int length)
	{
		p = new int[length];
		l = length;
		//输入数值
		for(int i = 0 ; i < length; i++)
		{
			cin>>p[i];
		}
	}
	int max()
	{
		int max = p[0];
		for(int i = 1 ; i < l; i++)
		{
			if(max < p[i])
				max = p[i];
		}
		return max;
	}

	int min()
	{
		int m = p[0];
		for(int i = 1 ; i < l; i++)
		{
			if(m > p[i])
				m = p[i];
		}
		return m;
	}
	int avg()
	{
		int sum = 0;
		for(int i = 0 ; i < l; i++)
			sum+=p[i];
		int av = sum/l;

		return av;
	}

};

int main()
{

	Array a;
	a.input(4);
	cout<<"max: "<<a.max()<<endl;
	cout<<"min: "<<a.min()<<endl;
	cout<<"avg: "<<a.avg()<<endl;
}


5.封装性

封装的概念
	在程序设计中不是每个属性都需要对外公开(女人不公开体重跟年龄，男人不公开身高及收入)，而有一些类的属性是对外公开的(名字、性别等)。
	因此在设计类时必须在类的表示法中定义属性和行为的公开级别，将不对外公开的属性使用private进行修饰。
	
但因为被private修饰，所以外部无法对其进行写入与读取的操作，所以我们可以在public下留出读（getXXX()）或写（setXXX()）的操作函数。

#include <iostream>
#include <string>
using namespace std;

class Person{
private:
		int money;
		int id ;

public:
		string name;
public:
		void init(string n,int m,int i){
			name = n;
			money = m;
			id = i;
		}

		int getMoney(){
			return money;
		}
		void setMoney(int m)
		{
				money = m;
		}
		
		
		void setId(int i){
			
			id = i;
		}
		int getId(){
			return id;
		}
		
};

int main(){
	Person p;
	p.init("zhangsan",10000,1);
	cout << p.getId() << "." << p.name << " have " <<p.getMoney() << " dollars " <<endl ;
	return 0;
}
                                                                                          
***封装: 1)将具有相同属性和行为的一系列对象封装成一个类，将一系列重复性的代码封装成函数;
		 2)数据的隐藏，将不对外公开的属性和行为使用private进行修饰，保证数据安全。
		 

练习：创建一个类Product，成员变量自拟，使用set和get进行赋值与获取，在主函数创建三个产品对象并赋值，打印

#include<iostream>
#include<string>
using namespace std;

class Product
{
private:
	string name;
	int price;

public:
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void setPrice(int p)
	{
		price = p;
	}
	int getPrice()
	{
		return price;
	}

};


int main()
{
	Product p1;
	p1.setName("牙刷");
	p1.setPrice(5);
	cout<<p1.getName()<<"  "<<p1.getPrice()<<endl;

	Product* p2;
	p2->setName("灯泡");
	p2->setPrice(50);
	cout<<p2->getName()<<"  "<<p2->getPrice()<<endl;

}


6.类的声明和定义可以是分开的.h 和.cpp

示例1：在类外部实现成员函数
#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	void setAge(int a);
	void show();
};

void Person::setAge(int a)
{
	age = a;
}

void Person::show()
{
	cout<<age<<endl;
}

int main()
{
	Person* p = new Person;
	p->setAge(18);
	p->show();
}

示例2：分.h和.cpp
test.cpp

#include <iostream>
#include "person.h"

int main()
{
	Person* p = new Person;
	p->setAge(18);
	p->show();
}

person.h

//防止重复定义
#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
	int age;
public:
	void setAge(int a);
	void show();
};

#endif

person.cpp

#include "person.h"
#include <iostream>

using namespace std;

void Person::setAge(int a)
{
	age = a;
}

void Person::show()
{
	cout<<age<<endl;
}

练习：定义一个类，数据成员：length,width,heigh （分文件）
成员函数如下功能：Cube 长方体cuboid
1.由键盘输入长方体的长宽高input
2.计算长方体体积volume
3.输出长方体体积show

头文件
#ifndef CUBE_H
#define CUBE_H

class Cube
{
public:
	void input();
	int volume();
	void show();
private:
	int length;
	int width;
	int height;
};

#endif

源文件
#include "cube.h"
#include <iostream>

using namespace std;

void Cube::input()
{
	cout<<"输入 长宽高"<<endl;
	cin>>length>>width>>height;
}

int Cube::volume()
{
	return length*width*height;
}

void Cube::show()
{
	int v = volume();
	cout<<"v:"<<v<<endl;
}

main
#include <iostream>
#include "cube.h"

using namespace std;

int main()
{
	Cube c;
	c.input();
	c.show();
	return 0;
}




二.构造函数

1.构造函数的作用与语法

在创建对象的时候会自动调用的函数，是c++中特殊成员函数。

主要作用是在创建对象时初始化对象,为对象的成员变量赋值

对象的初始化:参考坦克大战游戏

/*定义一个坦克类*/
class Tank
{
private:
		int m_iposX;//横坐标
		int m_iposY;//纵坐标
public:
void init()//初始化函数 
{
	m_iposX = 0;
	m_iposY = 0;//赋值0后 后续的操作就清晰可控了 
}
};

int main()
{
	Tank t1;   //实例化一个坦克的对象
	t1.init(); // t1中横纵坐标置为0
	
	Tank t2;
	t2.init();
	
	return 0;
}
对象的初始化：有且仅初始化一次
              根据条件初始化
			  
思考：如何能避免误操作呢  
初始化函数 如何避免误操作
 忘记调用初始化函数
 重复调用初始化操作

2.构造函数的规则和特点
创建语法如下：
1.名字必须与类同名 无返回值 可能有参数
2.访问权限一般是public
3.用户不能调用构造函数 只有在类对象创建时 自动调用
注意： 如果在类的声明中没有显示的构造方法，则系统自动生成一个隐式的无参构造方法，
											如果有显示的构造方法，则不会生成。
  4. 实例化对象时，只用到一个构造函数

示例1：无参构造函数

#include<iostream>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:

	Person()//无参构造函数
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
	Person x;//x创建时 自动调用构造函数 完成初始化工作
}

示例2：无参构造函数 成员变量赋值
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
示例3：有参构造函数
class Person 
{
	public:
		Person()//无参构造函数
		{
			age = 10;//成员变量赋值
			cout<<"无参构造函数"<<endl;
		}
		//有参构造函数
		Person(int a)
		{
			age = a;
			cout<<"create a...."<<endl;
		}
		
		void show()
		{
			cout<<age<<endl;
		}
private:
	int age;
};
int main()
{
	Person x;      //x创建时 自动调用无参构造函数 完成初始化工作
	x.show();
	Person p1(20);//x创建时 自动调用有参构造函数 完成初始化工作
	p1.show();
}

练习：计算长方形周长 构造函数实现长宽赋值（构造函数带参数） 分文件写！

#include <iostream>

using namespace std;

class Cube
{
private:
	int length;
	int width;
public:
	Cube(int l, int w)
	{
		length = l;
		width = w;
	}

	int cir()
	{
		return (length+width)*2;
	}
};

int main()
{
	Cube c(10, 20);
	cout<<c.cir()<<endl;
	return 0;
}




5.构造函数的初始化列表：构造函数用冒号形式引出初始化列表

格式：成员变量名(初始值)

注意：初始化成员列表的顺序应该和成员声明的顺序保持一致，不建议使用成员初始化其他成员


#include <iostream>

using namespace std;

class Rect
{
private:
	int width;
	int height;
public:
	Rect(int widh, int h):
		width(width),
		height(h)
	{
		this->width = width;
		
	}
	
	int perimeter()
	{
		return width*2+height*2;
	}
};

int main()
{\\
rect r;
	Rect* p = new Rect(10, 20);//将参数传递给构造函数
	cout<<p->perimeter()<<endl;
	Rect r(10, 20);
	cout<<r.perimeter()<<endl;
}
	

练习1：实现一个分数类F  功能：F f1(3,4) 显示结果:3/4 
1.构造函数传入参数
2.成员函数show显示




练习2：键盘输入时间 显示输入时间的下一秒 Timer
1.定义成员变量 h m s
2.成员函数go 改变h m s 的值
3.成员函数show显示下一秒的时间






思考：构造函数调用几次：1）Person p[10]; //
						2) Person *p[10];//
							p[0] = new Person;//



三、this指针：

		是一个指针,指向对象本身，this只能在类的内部使用，
		在类的内部调用成员都是使用this调用的，可以省略

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
		this->age = age;
	}

	void show()
	{
		cout<<this->age<<endl;//不写this 叫隐式调用 写this叫显式调用
	}
};

int main()
{
	 
	p.show();
}

示例2:this存在的意义：在类的内部，将当前对象当做参数进行传递

练习：Person类，包含私有属性：姓名name，性别bool gender，年龄age，另一个对象的指针 Person *lover;
		1.构造函数初始化成员变量
		2.成员函数setAge给年龄赋值
		3.成员函数marry(Person& other)    输出name"和"other.name"喜结良缘!";
		4.成员函数show(); 输出"大家好！我是"gender，name，今年"age;
						  输出"爱人是:"lover->name;
private:
		string name;
		bool gender;
		int age;
		Person *lover;
		


练习或作业：定义扑克类Poker，私有属性color，point，创建54张牌存入数组中  大小王单独处理；只有花色，没有分值
			1.构造函数，初始化花色和点数（普通的牌）
			2.构造函数，初始化花色（大小王）
			3.成员函数 toString();显示54张牌 例：红桃2  黑桃A






