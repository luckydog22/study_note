


小测试：
1.class和struct的差异: 默认访问权限 

2.构造函数的调用时机和作用 ：创建对象 自动调用  给成员变量初始化

3.写个类student，包括私有属性 名字，年龄，通过构造函数给成员变量初始化

class student
{
private:
string name;
int age;
public:
 student(string name,int age):name(name),age(age){}
	
};
	

注意：初始化成员的顺序应该和成员声明的顺序保持一致，不建议使用成员初始化其他成员




/*****************************

		新课
		
******************************/



一、拷贝构造函数

class student
{
public:
	student()
	{
		cout<<"student"<<endl;
	}
private:
	string m_name;
};
int main()
{
	student stu1;
	student stu2=stu1;//拥有了stu1的值
	student stu3(stu1);
}
/*运行只打印了一行student的值 
 实例化对象的时候一定会调用构造函数 对吧 前面没有讲错 没有讲完
这两种调用了构造函数 调用了特殊的构造函数
 但是调用的不是这个构造函数 调用了拷贝 
 在定义时跟普通的基本相同 只是参数上面有些严格的要求*/



1、声明：  函数名（类名）(const 类名 &对象名)  
使用一个对象初始化另一个新的对象的时候调用拷贝构造

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

	Person(const Person& other):age(other.age)//引用跟自己的数据类型完全相同
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
说明：
如果没有自定义的拷贝构造函数则系统自动生成一个默认的拷贝构造函数

当采用直接初始化或复制初始化实例化对象时，系统自动调用拷贝构造函数

2、拷贝构造函数调用三种情况：

（1）程序中需要创建一个新对象 并用另一个同类的对象对它初始化 
示例：
#include<iostream>

using namespace std;

class Person
{
public:
	int age;
	string name;
	Person(int age)
	{
		this->age = age;
		cout<<"构造函数"<<endl;
	}
	Person()
	{
		cout<<"无参构造"<<endl;
	}
	//拷贝构造函数
	//格式：类名相同　同类型的对象的引用
	//默认的拷贝构造函数功能是：逐个给成员变量进行赋值
	//调用了拷贝构造函数，就不会在调用构造函数了
	Person(const Person& other)//Person& other = a;
	{
		age = other.age;
	//	name = other.name;
		cout<<"拷贝构造函数"<<endl;
	}
	void show()
	{
		cout<<age<<endl;
	}

};


int main()
{
	//堆空间创建对象
	Person* p = new Person(12);
	Person * p1 = new Person(*p);
	p1->show();
	
	//栈空间创建对象
	
	//用对象来初始化对象的时候
	Person b = a;
	b.show();
//	Person c(a);
}


（2）当函数的参数为类的对象时
示例1：
void farsight(Person p);//person p（a） ;

int main()
{
	Person a(19);	
	farsight(a);       //使用对象a初始化函数的参数p，a和p是两个独立的对象
}

void farsight(Person p){}

示例2：
void farsight(Person& p); person & p = a;//没有新的对象  p就是a本身

int main()
{
	Person a(19);
	cout<<"start"<<endl;
	farsight(a);//p是a的别名，p和a是同一个对象
	cout<<"end"<<endl;
}
void farsight(Person& p){}

综合示例：

class Person{
private:
	int age;
public:
	Person()
	{
		cout<<"无参构造函数"<<endl;
	}
	Person(const Person& other)
	{
		cout<<"拷贝构造函数"<<endl;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	void show()
	{
		cout<<age<<endl;
	}
		
};
void fun(int a)
{
	cout<<"a:"<<a<<endl;
	a+=2;
}
void fun(Person p)
{
	p.setage(23);
}

void fun(Person& p)
{
	p.setage(23);
}

int main()
{
	int b=10;
	fun(b);
	cout<<"b:"<<b<<endl;
	
	Person a(12);
	fun(a);
	a.show();
	return 0;
	
}

//此处
（3）函数的返回值为类对象，堆空间的对象，如果返回栈空间的对象，不会创建新的临时对象
示例：
Person farsight();

int main()
{	
	Person f = farsight();//接的空间在哪（栈）
	cout<<&f<<endl;// 栈空间 地址是一样的  返回对象本身
}

Person farsight()
{
	//堆
	Person* p = new Person(19);
	cout<<p<<" after new"<<endl;
	return *p;
	
	//栈
	Person p;
	cout<<&p<<endl;
	return p;
}



//练习：
1、Student类
1.私有成员score，name
2.构造函数传入score，name
3.公有函数setScore给score赋值
4.公有函数show显示成绩和名字
2、Teacher类
1.Student* students[5]私有数组保存学生对象
2.公有构造函数，给students数组赋值
3.公有函数randHappyBoy()随机抽取一个学生
4.公有函数hehe()将随机抽取的这个学生改为0分
5.公有函数show()显示最终的所有学生成绩




创建对象

3、私有构造函数和拷贝构造函数
示例1：私有构造函数 不能创建对象
#include <iostream>

using namespace std;

class Person
{
private:
	int age;
private:
	Person(int age)
	{
		this->age = age;
		cout<<"构造"<<endl;
	}
public:
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
	Person p(19);//报错  不能创建对象
}
示例2：私有拷贝构造函数  不能复制对象
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
		cout<<"构造"<<endl;
	}
private:
	Person(const Person& other):age(other.age)
	{
		cout<<"拷贝构造"<<endl;
	}

	void show()
	{
		cout<<this->age<<endl;
	}
};
Person farsight();

int main()
{
	Person p(19);
	Person b = p;//报错 不能复制对象
}

4、深拷贝与浅拷贝
//////////////////////自己写的代码 
#include<iostream>
#include<string>
using namespace std;

class Phone
{
};

class Person
{
private:
	Phone *pPhone;
public:
	Person()
	{
		pPhone = new Phone;
	}

	Person(const Person &other)
	{
		pPhone = new Phone(*(other.pPhone));
	}

	Phone *getp()
	{
		return pPhone;
	}
};

int main()
{
	Person *p = new Person;
	Person p1(*p);
	cout<<p->getp()<<endl;
	cout<<p1.getp()<<endl;

}

///////////////////老师代码
示例1：浅拷贝  拷贝对象的时候，不对指针成员所指向的对象进行拷贝，
两个对象的指针成员指向的是同一个对象
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Phone
{
private:
	string name;
public:
	Phone(string name):name(name){}
};

class Person
{
private:
	Phone* pPhone;
public:
	Person()
	{
		pPhone = new Phone("诺基亚plus");
	}
	Phone* getPhone()
	{
		return pPhone;
	}

};

int main()
{
	Person* xiaoming = new Person();
	Person xiaoqiang(*xiaoming);
	
	
	cout<<xiaoming->getPhone()<<endl;
	cout<<xiaoqiang.getPhone()<<endl;
}

示例2：深拷贝  需要在对象的拷贝构造函数中对成员指针所指向的对象也进行拷贝

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Phone
{
private:
	string name;
public:
	Phone(string name):name(name){}
	string getName()
	{
		return name;
	}
};

class Person
{
private:
	Phone* pPhone;
public:
	Person()
	{
		pPhone = new Phone("诺基亚plus");
	}

	Person(const Person& other)
	{
		pPhone = new Phone(*(other.pPhone));//将成员指针指向的对象进行复制
	}

	Phone* getPhone()
	{
		return pPhone;
	}

};

int main()
{
	Person* xiaoming = new Person();
	Person xiaoqiang(*xiaoming);
	cout<<xiaoming->getPhone()<<endl;
	cout<<xiaoqiang.getPhone()<<endl;
	cout<<xiaoming->getPhone()->getName()<<endl;
	cout<<xiaoqiang.getPhone()->getName()<<endl;
}

注意：能用浅拷贝就不用深拷贝

5、类成员的初始化顺序：先按照成员变量的声明顺序初始化成员变量，
最后调用构造函数

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout<<"A"<<endl;
	}
};

class B
{
public:
	B()
	{
		cout<<"B"<<endl;
	}
};

class C
{
private:
	B b;
	A a;
	
public:
	C()
	{
		cout<<"C"<<endl;
	}
};

int main()
{
	C c;
}

6、默认构造函数和默认拷贝构造函数
1.默认构造函数，当没有显式的定义构造函数时，系统会自动生成一个默认构造函数，没有参数也没有逻辑；一旦显式的定义了构造函数，将不会生成默认构造函数。
示例：
#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age):age(age)
	{
	
	}
};

int main()
{
	Person* p = new Person;
}



//没有显式定义构造函数时正确，定义上面的构造函数时，错误


2.默认拷贝构造函数：在没有显式的定义拷贝构造函数时，系统会自动生成一个拷贝构造函数，将成员变量逐个赋值(浅拷贝）
如果显式的定义拷贝构造函数，那么默认拷贝构造函数和默认构造函数都没有了

示例：
#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age):age(age)
	{
	
	}
	int getAge()
	{
		return age;
	}
};

int main()
{
	Person* p = new Person(19);
	Person* p2 = new Person(*p);//调用默认拷贝构造函数
	cout<<p->getAge()<<endl;
	cout<<p2->getAge()<<endl;
}


三、析构函数（啥也不干  默认五个函数）

1、析构函数是一个特殊的成员函数 作用与构造函数相反
功能：当对象脱离其作用域(对象所在的函数已经调用完毕) 系统自动调用析构函数 
	   析构函数往往做"清理善后"工作
声明：没有返回值 名字必须与类名同名 没有参数 名字前 ~
析构函数不能有参数，不能被重载

//////////////////////
栈空间 自动创建  自动释放
推空间  手动创建  手动释放
using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age):age(age)
	{
		cout<<"构造"<<endl;
	}
	int getAge()
	{
		return age;
	}
	~Person()
	{
		cout<<"析构"<<endl;
	}
};

int main()
{
	Person* p = new Person(19);
	delete p;
	
//	Person p1(20);
}


//练习：
设计一个Book类包含图书的书名，作者成员 其中：书名和作者用字符型指针
	1.构造函数为作者及书名指针开辟空间并将传入的书名
	和作者拷贝到数组中Book(char* name, char* author)
	2.一个析构函数，删除书名和作者数组
	3.成员函数print()输出数据
	




四、常对象

补充：
//const 会将原有的共功能限制为只读 

//在堆创建对象  变量放在常量区里  会给默认值

1、常函数：
 常函数中的this是被const修饰的，
 
在常函数中成员变量不能被修改, 

常函数只能调用常函数

示例：
#ifndef TEST_H
#define TEST_H


class test
{
private :
    int age;
public:
    test();
    void show();
  //  void show() const;
    ~test();
};

#endif // TEST_H

#include "test.h"
#include<iostream>

using namespace std;

test::test()
{
    age  = 12;
}

void test::show()
{
    age = 13;
    cout<<"........"<<endl;
}

//void test::show() const
//{//
 //   cout<<"const..........."<<endl;
//}

test::~test()
{

}

#include <iostream>
#include"test.h"

using namespace std;

int main()
{
    const test p;
    p.show();
    return 0;
}

2、声明常对象： 
const 类名 对象名(实参)
类名 const 对象名(实参)

注意常对象：(1)成员变量必须有初值 （2）只能调用常成员函数 

补充：
(1)原因：常对象---->常函数----->常函数不能对成员变量进行进行修改（只读）

功能：希望对象所有成员的值不被修改

注意：常对象只能---------->调用常成员函数     是单向的 //*****重点

利用const 修饰，也可以构成函数的重载

void show()               void show()  const



3、mutable： mutable修饰的成员变量可以在常函数中修改
示例：
#include <iostream>

using namespace std;

class Person
{
private:
	string name;
	int age;
	mutable int a;
public:
	Person(int age,string name):age(age),name(name),a(10){}
	void show()
	{
		cout<<age<<" "<<name<<endl;
	}
	void show() const
	{
		a++;
		cout<<age<<"$$$"<<name<<" "<<a<<endl;
	}
};

int main()
{
	Person p(20, "小明");
	p.show();
	const Person p2(30, "小强");
	p2.show();
}