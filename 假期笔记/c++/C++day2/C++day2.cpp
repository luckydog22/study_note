
一、拷贝构造函数
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

2、拷贝构造函数调用三种情况：
（1）程序中需要创建一个新对象 并用另一个同类的对象对它初始化 
示例：
int main()
{
	Person a(19);
	cout<<"start"<<endl;
	Person b(a);//调用对象b 的拷贝构造函数
	Person c = a;//调用对象c的拷贝构造函数
	cout<<"end"<<endl;
	b.show();
}
（2）当函数的参数为类的对象时
示例1：
void farsight(Person p);

int main()
{
	Person a(19);
	cout<<"start"<<endl;
	farsight(a);//使用对象a初始化函数的参数p，a和p是两个独立的对象
	cout<<"end"<<endl;
}

void farsight(Person p){}

示例2：
void farsight(Person& p);

int main()
{
	Person a(19);
	cout<<"start"<<endl;
	farsight(a);//p是a的别名，p和a是同一个对象
	cout<<"end"<<endl;
}

void farsight(Person& p){}


（3）函数的返回值为类对象
如果返回的对象在函数结束后会被删除，那么会将对象本身返回（废物利用），此时不会
调用拷贝构造；如果返回的对象在函数结束后不会被删除，那么会调用拷贝构造函数，复制
一个对象返回。
示例：
Person farsight();

int main()
{
	farsight();
}

Person farsight()
{
	Person* p = new Person(19);
	cout<<"after new"<<endl;
	return *p;
}

练习：
1、Student类
1.私有成员score，name
2.构造函数传入score，name
3.公有函数setScore给score赋值
4.公有函数show显示成绩和名字
2、Teacher类
1.Student* students[5]私有数组保存学生对象
2.公有构造函数，给students数组赋值
3.公有函数randHappyBoy()随机抽取一个学生   Student* randHappyBoy();
4.公有函数hehe()将随机抽取的这个学生改为0分 void hehe(Student* hb);
5.公有函数show()显示最终的所有学生成绩



3、私有构造函数和拷贝构造函数
示例1：私有构造函数 不能创建对象
#include <iostream>

using namespace std;

class Person
{
private:
	Person()
	{}
public:
	Person(int a)
	{}
};

int main()
{
	Person p2;//报错因为无参的构造函数私有化了
	Person p(1);
	return 0;
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
示例1：浅拷贝  拷贝对象的时候，不对指针成员所指向的对象进行拷贝，两个对象的指针成员指向的是同一个对象
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
	Person xiaoming;
	Person xiaoqiang(xiaoming);//默认拷贝构造，浅拷贝
	cout<<xiaoming.getPhone()<<endl;
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
		//用other的phone拷贝一个新的phone对象
		pPhone = new Phone(*other.pPhone);//将成员指针指向的对象进行复制
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

5、类成员的初始化顺序：先按照成员变量的声明顺序初始化成员变量，最后调用构造函数

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
public:
	C()
	{
		cout<<"C"<<endl;
	}
private:
	A a;
	B b;
};

int main()
{
	C c;
}

6、默认构造函数和默认拷贝构造函数
1.默认构造函数，当没有显式的定义构造函数时，系统会自动生成一个默认构造函数，
	没有参数也没有逻辑；一旦显式的定义了构造函数，将不会生成默认构造函数。
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
	Person* p = new Person();//没有显式定义构造函数时正确，定义上面的构造函数时，错误
}

2.默认拷贝构造函数：在没有显式的定义拷贝构造函数时，系统会自动生成一个
	拷贝构造函数，将成员变量逐个赋值（浅拷贝）；当显式的定义拷贝构造函数
	时，系统将不会生成默认拷贝构造函数以及默认构造函数。
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


三、析构函数
1、析构函数是一个特殊的成员函数 作用与构造函数相反
功能：当对象脱离其作用域(对象所在的函数已经调用完毕) 系统自动调用析构函数 析构函数往往做"清理善后"工作
声明：没有返回值 名字必须与类名同名 没有参数 名字前 ~
析构函数不能有参数，不能被重载
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
	~Person()
	{
		cout<<"析构"<<endl;
	}
};

int main()
{
	Person* p = new Person(19);
	delete p;
}

练习：
设计一个Book类包含图书的书名，作者成员 其中：书名和作者用字符型指针
1.构造函数为作者及书名指针开辟空间并将传入的书名和作者拷贝到数组中
		Book(char* name, char* author)
2.一个析构函数，删除书名和作者数组
3.成员函数print()输出数据



四、常对象
1、常函数：常函数中的this是被const修饰的，在常函数中成员变量不能被修改

#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age):age(age){}

	void add() const//常函数
	{
		cout<<++age<<endl;
	}
};

int main()
{
	Person p(20);
	p.add();
}

2、声明常对象： 
const 类名 对象名(实参)
类名 const 对象名(实参)

注意常对象：（1）常对象必须初始化（定义构造函数） （2）只能调用常成员函数
功能：希望对象所有成员的值不被修改
注意：常对象只能调用常函数，普通对象优先调用普通函数，如果没有普通函数，调用常函数。
#include<iostream>
using namespace std;
class Person
{
private:
	string name;
	int age;
public:
	Person(string n,int age);
	void show();
	void show()const;//可以"重载"  特殊的重载
};

Person::Person(string name,int age):name(name),age(age)
{

}

void Person::show()//自由
{
	cout<<"我是"<<name<<" 今年"<<age<<endl;
}

void Person::show()const  //可以访问常对象 不可以修改其值
{
	cout<<"我是const "<<name<<" 今年"<<age<<endl;
}

int main()
{
		const Person a("昆山龙哥",36);
		a.show();

		Person b("昆山电池动车哥",43);
		b.show();//非常对象默认调用自由的成员函数
}

3、mutable：mutable修饰的成员变量可以在常函数中修改
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


五、友元
友元可以访问与其好友关系的类中的私有成员 
友元：友元函数和友元类
1、友元函数
将普通函数声明为友元函数  friend + 函数声明
#include<iostream>
using namespace std;
class Time
{
friend void display(Time &t);//display可以访问Time类中的私有成员
public:
	Time(int,int,int);
private:
	int hour;
	int minute;
	int second;
	
};

Time::Time(int h,int m,int s):hour(h),minute(m),second(s)
{

}

void display(Time &t)
{
	cout<<t.hour<<endl;//
}
int main()
{
	Time t1(16,14,50);
	display(t1);
}


练习：
1.有个学生类student 包括：私有成员：姓名 成绩 
2.在main定义student数组5个元素并初始化
3.设计一个全局友元函数 比较两个学生的成绩的高低 compare
4.求出最高分和最低分的学生




2、友元类
friend + 类声明

示例：
#include <iostream>
#include <string>

using namespace std;

class Teacher;
class Student
{
friend class Teacher;
private:
	string name;
	int score;
public:
	Student(string name, int score):
		name(name),
		score(score)
	{}
};

class Teacher
{
public:
	void look(Student& s)
	{
		cout<<s.name<<" "<<s.score<<endl;
	}
};

int main()
{
	Teacher t;
	Student s("小张",19);
	t.look(s);
}

友元：
1、友元是单向的  你把别人当朋友，别人没把你当朋友
2、友元不能传递	 朋友的朋友不是朋友
3、友元不能继承	 爸爸的朋友不是自己的朋友

练习：
1.有个学生类student 包括私有成员：姓名 成绩 ；  student 构造函数对成员赋值
2.设计一个友元类teacher 
3.teacher类中包含私有成员数组 student s[5]  构造函数对数组元素赋值
4.teacher类对学生数组进行排序  公有成员函数 sort() 降序
5.teacher类输出成绩对应等级 >=90 优 80-89 良  70-79中 60-69及格  <60不及格  公有函数show()



注意：友元破坏类的封装特性，慎用！
				
六、c++中异常机制

异常分为3部分：检查(try) 抛出(throw) 捕捉(catch)
格式：
try 
{
	被检查语句
}
catch(异常处理的类型 变量名)
{
	进行异常处理的语句;
}
例子1：
#include<iostream>
using namespace std;

int mydiv(int a,int b)
{
	if(b==0)
	{
		cout<<"throw....."<<endl;
		throw b;//抛出异常
	}
	return a/b;
}
int main()  
{
	int a=10;
	int b=0;

	try
	{
		int result = mydiv(10,0);
		cout<<result<<endl;
	}
	catch(int e)
	{
		cout<<"catch int "<<e<<endl;
	}
}

例子2：捕捉多异常
#include <iostream>

using namespace std;

class ExceptA
{
public:
	void show()
	{
		cout<<"异常A"<<endl;
	}
};

class ExceptB
{
public:
	void show()
	{
		cout<<"异常B"<<endl;
	}
};

int div(int a, int b)
{
	if(b == 0)
	{
		ExceptA e;
		throw e;
	}
	return a/b;
}

double div(double a, double b)
{
	if(b == 0)
	{
		ExceptB e;
		throw e;
	}
	return a/b;
}

int main()
{
	try
	{
		div(1.0, 0.0);//可能抛出ExceptB
		div(1, 0);//可能抛出ExceptA
	}
	catch(ExceptA e)
	{
		e.show();	
	}
	catch(ExceptB e)
	{
		e.show();
	}
	catch(...)//捕捉剩余的异常
	{
		cout<<"other e"<<endl;	
	}
}

应用中的异常检测
int main()
{
	do
	{
		if()
		{
			cout<<"异常1"<<endl;
			break;
		}

		if()
		{
			cout<<"异常2"<<endl;
			break;
		}
	}while(false);	//do-while的存在是为了给break提供运行环境
	return 0;
}

练习：给出三角形三边 a、b、c (不敲了)
求三角形周长 
只有a+b>c b+c>a a+c>b 才能构成三角形 设置异常处理 对不符合三角形条件的 
	输出警告信息 不予计算


七、内联函数
inline修饰的函数，可以是成员函数，可以是全局函数。
内联函数建议编译器将函数在调用处展开，省去了却换函数的开销，只适用于逻辑非常
	简单的函数。
内联函数必须在声明的文件中实现。

八、c++中静态成员
1、静态成员变量
1.属于整个类 静态成员变量只存储一份供所有对象使用
2.必须在类外单独初始化 而且只能全局进行 否则不会分配空间 编译报错
#include<iostream>
using namespace std;
class Stu
{
public:
	static int num;//声明静态成员变量
};

int Stu::num = 10;//默认值为0
//int Stu::num=89;//初始化
int main()
{
	cout<<Stu::num<<endl;
	//或者
	Stu s;
	cout<<s.num<<endl;
}

2、静态成员函数
没有this指针，所以静态成员函数不能访问本类中的非静态成员，静态函数只能
	调用静态成员

#include<iostream>
using namespace std;
class Stu
{
public:
	int age;
	static int num;//声明静态成员变量
	static int get_num()
	{
		cout<<age<<endl;//错误 age是普通成员变量，不能在静态成员函数中使用
		return num;//静态成员函数可以使用静态成员变量
	}
};

int Stu::num=89;
int main()
{
	cout<<Stu::get_num()<<endl;	
	//或者
	Stu s;
	cout<<s.get_num()<<endl;
}

九、单例模式 
创建类的对象也叫实例化对象，每个对象叫做类的一个实例。
1、目的：为了保证类的实例对象只有一个
2、实现方法
1.私有构造函数和拷贝构造函数   不让类的外部创建对象
2.静态成员函数返回类指针  用来实例化(new)对象
3.静态类指针     在静态成员函数中实现只创建一个对象的逻辑




十、运算符重载
运算符重载的目的：为了让代码看起来更佳优雅
1、定义
1.重载：给运算符重新赋予新的含义，在类的内部定义的运算符和成员函数是一样的
2.重载方法：定义一个重载运算符的函数 在需要执行被重载的运算符时 系统会自动调用该函数
3.重载运算符格式：
	函数类型 operator 运算符名称(形参列表)
4.运算符重载的参数个数由运算符本身决定，但是类型可以自定义
5.由运算符的左值调用运算符的重载
6.如果类没有重载运算符，类的对象不能进行运算符的操作

注意：可以将函数的重载定义成全局的，但是在全局函数中，访问类的私有成员不方便；参数列表中必须包含类类型

示例1：
#include<iostream>
using namespace std;
class Person
{
private:
	int age;
public:
	Person(int a)
	{
		age = a;
	}

	bool operator==(const Person &s);	//==运算符的两个操作数 一个是this 一个是参数
};

bool Person::operator==(const Person &s)
{
	//在运算符的重载中，this是运算符的左值
	if(this->age==s.age)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main()
{
	Person p1(20);//p1==p2
	Person p2(20);
	if(p1==p2)//p1.operator(p2)
	{
		cout<<"the age is equal!"<<endl;
	}
	else 
	{
		cout<<"not equal"<<endl;
	}
}

示例2：类型自定义

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	int age;
	string name;
public:
	Person(int age, string name):age(age),name(name)
	{}

	bool operator==(const Person& p)
	{
		cout<<this<<endl;
		return this->age==p.age;
	}

	bool operator==(int a)
	{
		return age==a;
	}
};

int main()
{
	Person p1(1, "小明");
	Person p2(1, "小强");
	cout>>p1;
	if(p1 == 20)
	{
		cout<<"hehe"<<endl;
	}
	return 0;
}

示例3：重载全局运算符

class Person
{
friend ostream& operator<<(ostream& c, const Person& p);
private:
    int age;
public:
    Person(int age):age(age){}
};

int main()
{
    Person p(10);
    cout<<p;
    return 0;
}
//重载cout的<<  或者cin的>>时只能使用全局重载
//全局重载  参数中必须含有类类型
ostream& operator<<(ostream& c, const Person& p)
{
    c<<p.age;
    return c;
}


2、赋值运算符重载，C++会对每个类默认重载赋值运算符，默认的逻辑是成员变量逐个赋值(浅拷贝)

必须重载和默认赋值运算符相同类型的参数，才能覆盖掉默认的赋值运算符

C++默认存在的函数
默认构造函数
默认拷贝构造函数
默认析构函数
默认=重载  
默认&重载

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(){}
	Person(string name):name(name)
	{}

	Person& operator=(string name)
	{
		this->name = name;
		return *this;
	}

	Person& operator=(int age)
	{
		this->age = age;
		return *this;
	}

	void show()
	{
		cout<<name<<" "<<age<<endl;
	}
};

int main()
{
	Person p1("小明");
	p1 = 19;
	p1 = "小强";
	p1.show();
	Person p2 = p1;//等价于Person p2(p1);  调用拷贝构造函数，和赋值运算符一点关系都没有
}

3、++ -- 运算符重载
默认情况下为前缀形式 operator++()    前缀

后缀形式需要添加一个int类型参数，参数无意义，仅仅用于区分前缀和后缀形式  operator++(int a)  后缀

示例：前缀和后缀的区别
int main()
{
	int a = 10;
	//++a = 20;//前缀形式表达式的结果是变量a本身
	a++ = 20;//编译错误，后缀形式返回值是a加1之前的一个临时的变量，不能作为左值
	cout<<a<<endl;
	return 0;
}

示例：
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Person
{
private:
	int age;
	string name;
public:
	Person(){}
	Person(int age, string name):age(age),name(name)
	{}

	Person& operator++()
	{
		age++;
		return *this;
	}

	Person operator++(int a)//参数没有任何实际意义，仅仅是告诉编译器这是一个后缀的重载
	{
		Person p = *this;
		age++;
		return p;
	}

	void show()
	{
		cout<<name<<" "<<age<<endl;
	}
};
int main()
{
	Person p(10, "小明");
	(++p).show();
	(p++).show();
	p.show();
	return 0;
}
《C++ primer》没有plus

