
小测试：

1.友元的特点
2.写一个对全局函数show（）的友元,访问类Person中的私有成员age

3.写出拷贝构造的格式，以及促发拷贝构造函数调用的三种情况分别是什么，文字描述即可

4.异常检测的格式，写一个对函数dev()的检测

5.析构函数有哪些特点



复习：
友元：1 友元函数  2 友元类
异常检测
匿名对象
Person p = Person("xiaoming").setAge(19);
静态成员：成员变量 必须在类的外部单独定义  成员函数 没有this，所以访问不了普通的成员变量和成员函数    static
单例模式：让类的对象只有一个
1、私有化构造函数
2、定义静态函数创建实例对象
3、静态成员指针指向唯一的那个实例对象

【题目1】C++重写、重载的区别？

重写							重载
前提（涉及类的个数）	发生在继承情况，2个以上		在同一个类中，1个
返回类型					必须相同						 可以不同
函数名					必须相同						 必须相同
参数列表					必须相同						 必须不同（个数或类型不同）

【题目2】一个数据成员是否可以既是const又是static，如果不行，为什么？

可以的，是静态常量。只读并且共享。

【题目3】友元的作用？
当在类的外面想要使用该类的私有成员，可以通过友元来破坏封装性，
可以使用友元函数（在类外编写函数，在类内声明为友元函数）、友元类（声明一个类来访问另一个类中的私有成员）、
友元成员函数（在一个类中有一个成员函数想访问另一个类中的私有成员，将这个函数声明为另一个类的友元成员函数）。
友元不能继承，友元不能传递，友元是单向的。

【题目4】拷贝构造函数的作用，自动调用拷贝构造函数的几种情形

三种情形下会调用拷贝构造函数，
(1)当用一个已有对象给另一个同类的对象进行初始化时
(2)当一个函数的参数是一个类的对象时
(3)当一个函数的返回值是一个类的对象时

【题目5】编写一个单例模式的关键点是什么？

单例模式是保证程序中这个类只有一个实例，
构造函数和拷贝构造函数私有化，保证在类的外部不能创建和拷贝对象（0例）
在类的内部留出一个静态私有的本类的指针用来承接惟一的实例，并在类外初始为NULL
并在类的内部编写一个静态公有函数来获取实例，判断指针是否存有地址。
如果有地址，则直接返回实例，如果没有，使用new关键字创建一个实例并返回。

【题目6】深拷贝与浅拷贝的区别
当类中有指针成员时，
浅拷贝只将指针中保存的地址复制给新的对象，实际上还是指的同一块内存，当析构函数对两个对象进行内存释放时会出现double free异常（释放第一个对象时，已将内存删除，第二个对象释放时还是找的原有地址，但内存已不存在）。
深拷贝拷贝时不拷贝地址，是将原对象指针中指向的内存进行拷贝，新对象指针存储新内存的地址，原对象指针存储原内存的地址，所以释放时互不干扰。

/*****************************

		新课
		
******************************/



一、运算符重载

为什么要有运算符重载？
如果类没有重载运算符，类的对象不能进行运算符的操作
Person
{};
Person p;
Person p1;

p + p1;


1、定义
1.重载：给运算符重新赋予新的含义，在类的内部定义的运算符重载和成员函数是一样的

2.重载方法：定义一个重载运算符的函数 在需要执行被重载的运算符时 系统会自动调用该函数

3.重载运算符格式：
	函数类型 operator 运算符名称(形参列表)
	
补充：
运算符重载  其实是一种特殊的成员函数
	
4.运算符重载的参数个数由/运算符本身//决定，但是类型可以自定义

//.由运算符的左值调用运算符的重载

补充：
在我看来，运算符重载的实质，

1./提供了一种另类的调用成员函数的方法，通过运算符 和 左值  的形式来实现了

2./对象里的数据 与  对象外的数据进行的交流

是成员变量需要和外界变量（别的对象的成员变量，普通变量）运算
而对象里的数据，无法直接与外界交流，只能通过对象

6.如果类没有重载运算符，类的对象不能进行运算符的操作

注意：可以将函数的重载定义成全局的，但是不方便

	Person(int a)
	{
		age = a;
	}

	bool operator==(const Person &s);	//==运算符的两个操作数 一个是this 一个是参数
};

bool Person::operator==(const Person &s)
{
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
	if(p1==p2)//p1.operator==(p2)
	{
		cout<<"the age is equal!"<<endl;
	}
	else 
	{
		cout<<"not equal"<<endl;
	}
}

示例2：类型自定义

#ifndef TEST_H
#define TEST_H


class test
{
private :
    int age;
public:
    test();
    void show();
    void operator ==(int a);
    ~test();
};

#endif // TEST_H

#include "test.h"
#include<iostream>

using namespace std;

test::test()
{

}

void test::show()
{

    cout<<age<<endl;
}

void test::operator ==(int a) //只要主函数写成 ：对象==值，
                                        //就会默认调用这个函数

{
    this->age = a;
	//cout<<"ni hao"<<endl;
}

test::~test()
{

}

#include <iostream>
#include"test.h"

using namespace std;

int main()
{
    test t;
    t == 2;  //左值运算，当左边是对象才会运算符重载
   t.operator ==(2);  //运算符重载，其实是特殊的成员函数
    t.show();
}



练习：设计一个三角形类Triange 包含三角形三条边长的私有数据成员
    另有一个重载运算符'+'  以实现求两个三角形周长之和  注意：两个三角形对象相加
	
	
******        头文件       ****************
#ifndef THREE_H
#define THREE_H


class three
{
private:
    int a1,a2,a3;
public:
    three(int a,int b,int c);
    int judge() const;
    void operator + (const three& other );
    ~three();
};

#endif // THREE_H

***********   成员函数   *****************

#include "three.h"
#include<iostream>

using namespace std;

three::three(int a,int b,int c):
    a1(a),
    a2(b),
    a3(c)
{

}

int three::judge() const
{
    if((a1 + a2) > a3 && (a1 + a3) > a2 && (a2 + a3) > a1)
    {
            int length = a1+a2 +a3;
            return length;
    }

    return 0;
}

void three::operator + (const three & other)
{
    /*
    int length1 = this->judge();
    int length2 = other.judge();
    return(length1 + length2);
    */
    cout<<"ni hao"<<endl;
}

three::~three()
{

}

*****************  主函数    ********************
#include <iostream>
#include"three.h"
using namespace std;

int main()
{
    three t1(3,4,5);
    three t2(5,12,13);

   //if(t1.judge() && t2.judge())
    t1+t2;
    t1.operator +(t2);

    return 0;
}

****************************************************



2、赋值运算符重载：C++会对每个类默认重载赋值运算符，默认的逻辑是成员变量逐个赋值

示例1：重载赋值运算符

*************   类的声明       **************
#ifndef TEST_H
#define TEST_H


class test
{
private :
    int age;
public:
    test();
    void show();
    test &operator =(int a);
    ~test();
};

#endif // TEST_H

*************   成员函数  **********************

#include "test.h"
#include<iostream>

using namespace std;

test::test()
{

}

void test::show()
{

    cout<<age<<endl;
}

 test &test::operator =(int a)

{
    this->age = a;
    cout<<"你好"<<endl;
    return *this;
}

test::~test()
{

}

****************   main  *******************
#include <iostream>
#include"test.h"

using namespace std;

int main()
{
    test t;
  //  t = 2;
    (t = 2).show();  //调用函数的同时会接到自己的返回值
}



示例2：系统默认的赋值运算符
***********		类的声明	*****************
#ifndef TEST_H
#define TEST_H


class test
{
private :
    int age;
public:
    test(int a);
    void show();
    void operator =(const test & other);
    ~test();
};

#endif // TEST_H


******************	成员函数的实现 **********************
#include "test.h"
#include<iostream>

using namespace std;

test::test(int a)
{
    age = a;
}

void test::show()
{

    cout<<age<<endl;
}

 void test::operator =(const test& other)
{
    this->age = other.age;
}

test::~test()
{

}



***********************		main	************************
#include <iostream>
#include"test.h"

using namespace std;

int main()
{
    test t1(2);
    test t2(3);

    t1 = t2;
    t1.show();  //调用函数的同时会接到自己的返回值
}


3.总结

  1）必须重载和默认赋值运算符相同类型的参数，才能覆盖掉默认的赋值运算符
  2）自己重载了 系统的重载是否还在？

      系统的还在 因为我们重载的赋值运算符的参数和c++默认生成的不一样，所以不会覆盖掉默认赋值运算符的重载
  3）要求会写   在写出来一个系统默认的例子，写个和系统一样的  怕面试和笔试题题的时候 问

  4）赋值运算符是算浅拷贝 没有特殊需求 是不用覆盖系统默认的 

4. C++默认存在的函数

	1）默认构造函数
	
	2）默认拷贝构造函数
	3）析构函数
	4）默认=重载  
	//补充：
	//右边为常引用   void test::operator =(const test& other)
	5）默认&重载 //  有争议 有人说不是 如果笔试或者面试时问到，就说默认的为五个函数 知道总比不知道强
                 //并不重要 没人会重写这个 




5、++ -- 运算符重载
默认情况下为前缀形式 operator++()    前缀

后缀形式需要添加一个int类型参数，参数无意义，仅仅用于区分前缀和后缀形式  operator++(int a)  后缀

示例：
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age):age(age)
	{}
	
	Person& operator++()
	{
		cout<<"前缀形式"<<endl;
		++age;
		return *this;
	}
	Person& operator++(int a)
	{
		cout<<"后缀形式"<<endl;
		age++;
		return *this;
	}
};

int main()
{
	Person p(19);
	p++;
	++p;
}

6、不能重载的运算符  ?:   sizeof()   .   ::    .*成员指针运算符



//练习：设计一个学生类 包括姓名和三门成绩(C++ C linux) 利用重载运算符'+=' 将所有学生成绩的和汇总到一个学生对象中
    1.string name;
		int cscore;
		int cppscore;
		int linuxscore;
	2.构造函数给成员变量初始化
	3.show（）方法，显示
	
	注意：在main中用匿名对象的形式创建三个对象的数组，并赋值，


**************	类的声明    ******************
#ifndef FUZHI_H
#define FUZHI_H


class fuzhi
{
private:
    int age;
    int num;
    int score;
public:
    fuzhi(int,int,int);
    void show();
    void operator += (const fuzhi&);


    ~fuzhi();
};

#endif // FUZHI_H

***********************   成员函数的实现	****************************

#include "fuzhi.h"
#include<iostream>
using namespace std;

fuzhi::fuzhi(int a, int n, int s) :
    age(a),
    num(n),
    score(s){}

void fuzhi::show()
{
    cout<<age<<endl;
    cout<<num<<endl;
    cout<<score<<endl;
}

void fuzhi::operator +=(const fuzhi& other)
{
    this->age  +=other.age;
    this->num +=other.num;
    this->score +=other.score;
}


fuzhi::~fuzhi()
{

}

*******************	    main ·	************************
#include <iostream>
#include"fuzhi.h"
using namespace std;

int main()
{
    fuzhi f1(10,10,10);
    fuzhi f2(20,20,20);
    fuzhi f3(30,30,30);
    f1 += f2;
    f3 +=f1;
    f3.show();
}


忠告：不要为了重载运算符而重载运算符，重载运算符只是为了代码看起来更加简洁



二、类继承

1.继承的概念 

继承允许依据一个类来定义另一个类，使创建和维护一个应用程序变得更容易。这样做，也达到了重用代码功能和提高执行时间的效果。
当创建一个类时，不需要重新编写新的数据成员和成员函数，只需指定新建的类继承了一个已有的类的成员即可。
已有的类称为基类或父类，新建的类称为派生类或子类。
一个子类可以有多个父类，它继承了多个父类的特性。

面向对象三大特性：
	***封装、继承和多态
	***继承可以实现面向对象代码重用，继承也是实现多态的必要语法

2.继承语法  基类 派生类  父类 子类
class 子类名:继承方式 父类名1，继承方式 父类名2，继承方式 父类名3....
{
	子类新添加的成员;	
}

示例1：
#include <iostream>
#include <string>

using namespace std;

class Food
{
public:

};

class KFC : public Food
{
public:
    KFC(string chips)
    {
        this->chips = chips;
    }
    string chips;

    void show()
    {
        cout<<"KFC中的  "<<chips<<endl;
    }
};

int main()
{
    KFC k("薯条");
    k.show();
}

思考：引伸1 如果父类中定义了同名的变量呢？
#include <iostream>
#include <string>

using namespace std;

class Food
{
public:
	string  chips;

};

class KFC : public Food
{
public:
    KFC(string chips)
    {
        this->chips = chips;
    }
    string chips;

    void show()
    {
        cout<<"KFC中的  "<<chips<<endl;
    }
};

int main()
{
    KFC k("薯条");
    k.show();
}
//练习：在父类Food中定义和子类同名的show()方法，查看调用情况



引伸2：子类中没有成员变量，父类中定义
#include <iostream>
#include <string>

using namespace std;

class Food
{
public:
	string  chips;

};

class KFC : public Food
{
public:
    KFC(string chips)
    {
        this->chips = chips;
    }
   void show()
    {
        cout<<"KFC中的  "<<chips<<endl;
    }
    
};

int main()
{
    KFC k("薯条");
    k.show();
}


3.继承中构造函数的赋值方法
	
子类通过参数列表赋值示例：猜考 父类的无参构造是否会调用？

///////////////////////////
补充：
构造函数，先父后子
	
class Food{
public:
	Food()
	{
		cout<<"我是父类构造函数"<<endl;
	}		
};
class KFC : public Food
{
public:	
	KFC(string chips):chips(chips)
	{		
		cout<<"我是子类构造函数"<<endl;
	} 	
private:
	string chips;
}

int main()
{
	KFC k("薯条");
	return 0;
}

****结论：如果没有显式的调用父类构造函数，会默认调用父类无参的构造函数****


思考：如果子类无成员，如何通过参数列表给父类成员初始化？
class Food{
public:	
	
	string chips;
		
};
class KFC : public Food
{
	KFC()
	{
		
	}
	void show()
	{
		cout<<"KFC中的  "<<chips<<endl;
	}
}

int main()
{
	KFC k("薯条");
	k.show();
	return 0;
}

****知识点：子类的初始化列表中可以通过父类的构造函数来初始化父类的成员****

class Food{
public:
    string chips;
	Food(string chips):chips(chips)
    {
        cout<<"父类有参构造"<<endl;
    }	
};
class KFC : public Food
{
public:
	
	KFC(string chips):
	Food(chips)
	{}	
	void show()
	{
		cout<<"KFC中的 "<<chips<<endl;
	}
};

int main()
{
	KFC k("薯条");
	k.show();
	return 0;
}

***注意：如果父类中没有无参构造函数，子类的初始化列表中必须显式的调用父类带参的构造函数****

******知识点：初始化顺序：先初始化父类，然后初始化自己成员
******格式：用逗号分隔
示例：
class Food{
public:
    string chips;
	Food(string chips):chips(chips)
    {
        cout<<"父类有参构造"<<endl;
    }	
};
class KFC : public Food
{
public:
	
	KFC(string chips,string Hamburg):
	Food(chips),
	Hamburg(Hamburg)
	{}	
	void show()
	{
		cout<<"KFC中的"<<chips<<"加"<<Hamburg<<endl;
	}
	string Hamburg;
};

int main()
{
	KFC k("薯条","汉堡");
	k.show();
	return 0;
}


综合练习：
/****************************************/
/*父类 ：Person类
*       定义构造函数，通过参数列表形式初始化成员
	    数据：
		  名字 name
		  年龄 age
*子类： Student类
		定义构造函数，通过参数列表形式 初始化父类及子类成员
		数据：
		  工作 work
		 成员函数：show()显示数据*/
/****************************************/








//练习：编写程序 
设计一个汽车类Vehicle 包含的数据成员：车轮个数wheels,车重weight 
小车类car是汽车类的派生类 包含数据成员:载人数passenger_load 
卡车类Truck是汽车类的派生类 包含： 载人数passenger_load  载重量pay_load
每个类都有相关数据的输出方法show显示所有的成员




4.继承访问方式的影响:

public继承     子类继承后的访问权限不变
protected继承  子类继承后，父类中的public变成protected，其它不变(protected:只有子类可以用)
private继承    子类继承后，父类中的public和protected变成private，其他不变

//////////////////
补充：
protected：只是限制了子类使用父类的权限，子类可以在自己内部使用父类的东西，不能在子类之外，用子类对象使用父类的东西
权限只可大变小


示例：
#include <iostream>
#include <string>

using namespace std;

class A
{
public:
	int a;
	A(int a):a(a){}
	
	void show()
	{
		cout<<a<<endl;
	}
};

class B : public A
{
public:
	B(int a):A(a){}
};

int main()
{
	B b(10);
	b.show();//编译错误  show在B中是protected的访问权限
}

//练习：
先设计一个Point类 包含：x，y(坐标)  --基类
由Point类派生出一个Circle类 增加数据成员r(半径)
Circle类定义函数计算面积
由Circle类为直接基类派生出一个Cylinder（圆柱体）类 再增加成员h(高)
Cylinder（圆柱体）类定义函数计算体积


//练习：
定义一个类Animal
属性：名称 颜色 腿条数
写构造方法：给属性赋值
每个属性私有权限，可以通过get，set方法赋值
方法：eat()，move()无参数方法

定义一个子类Sheep
咩咩叫：roar()

定义一个子类Tiger
奔跑run()

创建测试类
创建四条腿白色山羊，调用相关方法
创建四条腿白色东北虎，调用相关方法

//作业：在Time类中设计如下重载运算符函数++
       1.私有成员h m s
       2.重载后缀++ 让时间编程下一秒
       3.show函数显示时间
	   

