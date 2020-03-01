
复习：
this 指向当前对象的指针

拷贝构造函数 函数名（类名）(const 类名& other)

拷贝构造函数的调用时机
1 使用一个对象初始化另一个对象 Person p; Person p2 = p; Person p3(p);
2 函数参数 void fun(Person p);
3 函数返回值 Person fun()  返回堆空间

成员变量初始化顺序  成员声明顺序->构造函数

默认构造函数和拷贝构造函数 

私有构造函数和拷贝构造函数

深拷贝和浅拷贝
默认拷贝构造函数是浅拷贝，自定义拷贝构造函数实现深拷贝

析构函数 ~Person();
常函数 this使用const修饰的
常对象 const Person p; 只能调用常函数
mutable 修饰的成员可以在常函数中修改


********************************
		笔试简答题
********************************

【题目1】描述一下常函数与常对象？
常函数const修饰在形参列表的后面，常函数中的成员变量不能被修改。
常对象const可以修饰在类的前面或类的后面，对象中的成员属性不能被修改。

【题目2】c++中如何打破const的限制？
使用mutable关键字

【题目3】析构函数是什么？有哪些特点？
析构函数是在对象自动销毁时被系统调用的函数，作用是释放对象中开辟的内存空间，防止内存泄漏。
析构函数没有返回类型，函数名为~加类名，没有形参列表，不能被重载（每个类中只能有一个析构函数）。

【题目4】const关键字有什么作用？
const修饰之后变为“只读”。
变量被const修饰变为常量，值被初始化后，不能再修改。
常函数const修饰在形参列表的后面，常函数中的成员变量不能被修改。
常对象，对象中的成员属性不能被修改。
常引用，引用中的属性值不能被修改。


/*****************************

		新课
		
******************************/

一、友元

友元的概念：

	友元可以访问与其好友关系的类中的私有(private)成员
	  使用friend关键字进行修饰
	  
//////////////////////////////	
  
补充：
//派谁去有下手的对象
//你的朋友惦记的是你的对象

	  
***注意*** 但友元破坏类的封装特性，慎用！

友元的特点：

	(1)友元是单向的
	(2)友元不能传递
	(3)友元不能继承
	
	
友元：友元函数和友元类

1、友元函数
1.将普通函数声明为友元函数  friend + 函数声明
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
	cout<<t.hour<<endl;
}
int main()
{
	Time t1(16,14,50);
	display(t1);
}

2.友元成员函数

time.h
class Date;


class Time
{
    friend void disPlay(Time& t);
public:
    Time(int hour);
    ~Time();
    void show(Date& d);
 private:
    int hour;
};

date.h
class Time;
class Date
{
    friend void Time::show(Date& d);
public:
    Date(int year);
    ~Date();
  private:
    int year;
};


friend的函数 可以是另一个类中的成员函数 一个函数可以被多个类声明为朋友

//示例练习：	Time 类，私有成员: 时h，分m，秒s
						 公有构造
						 公有函数:display(Date& d)
				Date类   友元Time类中的函数display(Date& d)
				         私有成员: 年year 月mon 日 day
						 公有构造

见test1217项目


//练习：
1.有个学生类Student 
		包括：私有成员：姓名 成绩  
              void setData(string name, int score)给成员变量赋值
   
2.在main定义 student数组5个元素并赋值 Students[5]
3.设计一个全局友元函数 比较两个学生的成绩的高低 int compare(Student&, Student&);  a>b return 1; a<b return -1; 相等 0
4. 求出最高分和最低分的学生

main.cpp
#include <iostream>
#include "student.h"
using namespace std;

int compare(Student& s1,Student& s2)
{
    if(s1.score > s2.score)
        return 1;
    else if(s1.score < s2.score)
        return -1;
    else
        return 0;
}
int main()
{
    Student s[5];
    s[0].setData("aa",54);
    s[1].setData("bb",76);
    s[2].setData("cc",98);
    s[3].setData("dd",59);
    s[4].setData("ee",99);

    int max = 0,min = 0;
    for(int i =1; i< 5; i++)
    {
        if(compare(s[i],s[max]) == 1)
            max = i;
        if(compare(s[i],s[min])== -1)
            min = i;
     }
    s[max].show();
    s[min].show();
    return 0;
}

stu.h
#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student
{
friend int compare(Student& s1,Student& s2);
 private:
    string name;
    int score;
public:
    Student();
    void setData(string name,int score);
    void show();

    ~Student();
};

#endif // STUDENT_H

stu.cpp

#include "student.h"
#include<iostream>

using namespace std;
Student::Student()
{

}

void Student::setData(string name, int score)
{
    this->name = name;
    this->score = score;
}

void Student::show()
{
    cout<<name<<" "<<score<<endl;
}

Student::~Student()
{

}




2、友元类
friend + 类声明

示例：
#include <iostream>
#include <string>

using namespace std;

class Worker
{
	
	friend class Student;
	
};

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
1、友元是单向的
2、友元不能传递 //  见上面新写的worker类 
3、友元不能继承

注意：友元破坏类的封装特性，慎用！


//练习：
1.有个学生类Student 包括私有成员：姓名 成绩 ;  student构造函数对成员赋值
2.设计一个友元类Teacher 
	1)teacher类中包含 私有成员数组 student* s[5];  构造函数对数组元素赋值
	2)teacher类对学生数组进行排序  公有成员函数sort(); 降序
	3)teacher类输出成绩对应等级  公有函数show(); >=90 优 80-89 良  70-79中 60-69及格  <60不及格  
	
	public.h
#ifndef PUBLIC_H
#define PUBLIC_H

#include "teacher.h"
#include "student.h"


#endif // PUBLIC_H

student.h
#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include "public.h"
using namespace std;

class teacher;
class student

{
    friend class teacher;
 private:
    string name;
    int score;
public:
    student(string name,int score);
    ~student();
};

#endif // STUDENT_H

teacher.h

#ifndef TEACHER_H
#define TEACHER_H
#include "public.h"
class student;
class teacher
{
private:
    student *s[5];
public:
    teacher();
    void sort();
    void show();
    ~teacher();
};

#endif // TEACHER_H

main.h
#include <iostream>
#include "public.h"
using namespace std;

int main()
{
    teacher t;
    t.sort();
    t.show();
    return 0;
}

student.cpp
#include "public.h"

student::student(string name, int score):name(name),score(score)
{

}

student::~student()
{

}

teacher.cpp

#include "public.h"
#include <iostream>

using namespace std;
teacher::teacher()
{
    s[0] = new student("易建联",98);
    s[1] = new student("赵继伟",87);
    s[2] = new student("郭艾伦",88);
    s[3] = new student("阿布都",34);
    s[4] = new student("周琦",0);
}

void teacher::sort()
{
    for(int i = 0 ; i < 4; i++)
      {
        for(int j = 0 ; j < 4-i; j++)
        {
            if(s[i]->score< s[i+1]->score)
            {
                student* temp;
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        }

    }

}

void teacher::show()
{
    for(int i = 0 ; i < 5 ;i++)
    {
        if(s[i]->score >= 90)
            cout<<"优"<<endl;
       else if(s[i]->score> 80)
            cout<<"良"<<endl;
        else if(s[i]->score > 70)
            cout<<"中"<<endl;
        else if(s[i]->score == 0)
            cout<<"啥也不是"<<endl;
        else
            cout<<"不及格"<<endl;
    }

}

teacher::~teacher()
{

}


数组小总结：
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Student
{
	
};

class Teacher
{
private:
	
	Student s[10];//类成员变量所在空间同类对象所在空间相同
	
	// Teacher在栈空间 数组元素就在栈空间
	//Teacher在堆空间 数组元素就在堆空间
	
	Student* ps;//ps指针指向的对象所在的空间和teacher无关
};

int main()
{
	Student s[10];
	
	
	Student* s1[10];
	//s1肯定在栈空间 10个野指针
	
	
	Student* s2 = new Student[10];
	
	
}

注意：友元破坏类的封装特性，慎用！


				
二、c++中异常机制

1.异常是什么？
  异常是程序在执行期间产生的问题。C++ 异常是指在程序运行时发生的特殊情况，比如尝试除以零的操作。

2.检测异常的三个步骤：检查(try) 抛出(throw) 捕捉(catch)
	
	try: try 块中的代码标识将被激活的特定异常。它后面通常跟着一个或多个 catch 块。
 
	throw: 当问题出现时，程序会抛出一个异常。这是通过使用 throw 关键字来完成的。
 	
	catch: 在您想要处理问题的地方，通过异常处理程序捕获异常。catch 关键字用于捕获异常。
 

3.try...catch语法

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
		throw b;
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
		div(1, 0);
		div(1.0, 0.0);
		
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
		if(1)
		{
			cout<<"异常1"<<endl;
			break;
		}


		if(2)
		{
			cout<<"异常2"<<endl;
			break;
		}
	}while(false);
	return 0;
}

练习：给出三角形三边 a、b、c 求三角形周长 
只有a+b>c b+c>a a+c>b 才能构成三角形 设置异常处理 对不符合三角形条件的 输出警告信息 不予计算
异常类 class TriExcept  检测方法 check


--------------------------------------
示例2：类对象作为函数参数
#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		
		cout<<"无参构造"<<endl;
	}

	Person(int age):age(age)
	{
		cout<<"有参构造"<<endl;
	}
	void show(Person* p)
	{
		for(int i = 0 ; i < 5; i++)
		{
			cout<<p[i]->age<<endl;
		}
		cout<<age<<endl;
	}
private:
	int age;
};

void fun(Person p)
{
	p.show();
}

int main()
{
	Person s[4];
	s[0] = person(15);
	
	Person ps[5] = {Person(10), Person(20), Person(30), Person(49), Person(120)};
	
	Person p(10);
	p.show(ps);
	fun(p);
	
	fun(Person(100));
	return 0;
}

/*
*******回去复习前两天的练习，数组换成匿名对象的形式创建**************

*/




四、c++中静态成员

补充：
静态变量：（1）类外赋值
	  （2）使用时，必须标明作用域
静态函数：使用时，表明作用域


1、静态成员变量
	1.属于整个类 静态成员变量只存储一份供所有对象使用
	2.必须在类外单独初始化 而且只能全局进行 否则不会分配空间 编译报错
	
#include<iostream>
using namespace std;
class Stu
{
public:
	static int num ;//声明静态成员变量
};

int Stu::num = 10;//默认值为0
//int Stu::num=89;//初始化
int main()
{
	cout<<Stu::num<<endl;
}

2、静态成员函数

没有this指针，所以静态成员函数不能访问本类中的非静态成员，静态函数只能调用静态成员

#include<iostream>
using namespace std;
class Stu
{
	public:
		static int num;//声明静态成员变量
		static int get_num()
		{
			`return num;//没有this指针
		}
};

int Stu::num=89;
int main()
{
	cout<<Stu::get_num()<<endl;	
}

五、设计模式之单例模式 

1.单例模式的作用与目的

作用：保证了一个类仅有一个实例，并提供了一个访问它的全局访问点

目的：为了保证类的实例对象只有一个

主要解决：一个全局使用的类 频繁的创建于销毁

  举例：例如在Windows 是多进程多线程的，在操作一个文件的时候，就不可避免地出现多个进程或线程同时操作一个文件的现象，
所以所有文件的处理必须通过唯一的实例来进行。

何时使用：想控制实例数目，节省系统资源的时候

关键： 构造函数和拷贝构造私有化

2、实现方法
1.私有构造函数和拷贝构造函数   不让类的外部创建对象
2.静态类指针     在静态成员函数中实现只创建一个对象的逻辑
3.静态成员函数返回类指针  用来实例化(new)对象


#include <iostream>

using namespace std;

class stu
{
private:
    static stu* s;
    stu();
    stu(const stu&);
public:
    static stu* get_instance();
};

stu::stu(){}
stu::stu(const stu&){}
stu* stu::s = NULL;
stu* stu::get_instance()
{
    if(s==NULL)
    {
        s = new stu;
    }
    return s;
}

int main()
{
    stu *s1 = stu::get_instance();
    stu *s2 = stu::get_instance();

    cout<<s1<<endl;
    cout<<s2<<endl;


}