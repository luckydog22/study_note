

复习：

设计模式之单例模式 

1.单例模式的作用与目的

作用：保证了一个类仅有一个实例，并提供了一个访问它的全局访问点

目的：为了保证类的实例对象只有一个

主要解决：一个全局使用的类 频繁的创建与销毁

关键： 构造函数和拷贝构造私有化

2、实现方法

	1.私有构造函数和拷贝构造函数   不让类的外部创建对象
	2.静态类指针     在静态成员函数中实现只创建一个对象的逻辑
	3.静态成员函数返回类指针  用来实例化(new)对象


运算符重载：参数个数由运算符决定，参数类型随意，返回值类型随意
int operator+(int a)
Person
{};
Person p;
Person p1;
p + p1;
运算符的左值调用运算符

赋值运算符重载，会有默认的赋值运算符重载
p = p1;
Person p(p1);
person p2 = p1;

取地址运算符也会有默认的
++ -- 重载
前缀：没有参数
后缀：定义一个int类型参数

不能重载的运算符:5个 sizeof()  ?:  .  ::  .* 成员指针运算符

继承
class Person{};
class Student : public Person
{};
继承权限，从父类继承的成员所能有的最大访问权限



【题目1】请简要描述C++中的重载运算符

【题目2】如何重载前++和后++运算符？


【题目3】面向对象的三大特征是什么？请简要描述一下？

【题目4】C++的访问权限都有什么？请描述？


【题目5】在继承时，继承方式都有什么影响？


/*****************************

		新课
		
******************************/


一、虚函数

c++中定义成员函数时 前边加关键字virtual 这个函数就是虚函数  virtual void eat();

对比重载：overload 在同一个类中，函数名相同，参数列表不同，返回值无所谓，叫重载

1、重写： override  子类中定义和父类中虚函数同名，
同返回值类型，同参数列表的函数，叫重写。
示例1：   
#include <iostream>
#include <string>

using namespace std;

class A{
    public:
        void show(){
            cout << "A show()..." << endl;
        }
};
class B:public A{
    public:
        void show(){
                cout << "B show()..." << endl;

        }
};
int main(){
     A a;
     a.show();
     B b;
     b.show(); //优先调用自己的函数
	return 0;
}
	
2.虚函数的作用
c++中定义成员函数时前边加关键字virtual，这个函数就是虚函数：

virtual void eat(){
cout << “ eating ...” << endl; 
}
重写示例：
#include <iostream>
#include <string>

using namespace std;

class A{
    public:
      virtual void show(){
            cout << "A show()..." << endl;
        }
};
class B:public A{
    public:
        void show(){
                cout << "B show()..." << endl;
				}
};
int main(){
     A a;
     a.show();
     B b;
     b.show();
	return 0;
}
补充：
////////////////////////////////////////////
子类中可以不重写父类中的虚函数，不是强制要求
如何调用重写的函数，必须使用：父类指针指向子类对象

【题目】C++重写、重载的区别？


示例：
#include <iostream>
#include <string>

using namespace std;

class A{
    public:
       virtual   void show(){
            cout << "A show()..." << endl;
        }
};
class B:public A{
    public:
        void show(){
                cout << "B show()..." << endl;
        }
};
int main(){
    A  *p = new B;
    p->show();
    return 0;
}

3.父类指针指向子类对象与虚函数实现多态

父类* 指针 = new 子类();
Shape* shape = new Rectangle();
使用这种方式，父类的指针可以指向自己的所有派生类对象。

如果使用这种指针方式，若调用父类普通函数，则调用函数时依然是父类的方法；
///*****//
若调用父类的虚函数，调用函数时调用的是子类重写之后的函数。

多态: 1./子类可以重写父类中virtual函数，
2./用父类指向子类的指针或引用可以访问子类中重写的方法：为了将逻辑（类）当做参数进行传递
       3./父类可以调用子类重写的方法

**********父类类型的指针 可以指向子类类型的对象*******重要 
1.画图演示
2. 说明调用顺序  1）/看父类有没有虚函数
				 2）/如果有，去子类中找有没有重写，有就执行子类重写的方法；
				 3）/如果子类没有重写，就去执行父类的虚函数。

补充：
///////////////////
一人虚，后代全虚

试题：
如果函数在基类中被声明为virtual，则函数在其派生类中（A）
A. 都是虚函数
B。只有被重新声明时才是虚函数
C. 只有被重新声明为virtual时才是虚函数
D。 都不是虚函数



练习：
1.定义基类Developer，有虚函数develop()
2.定义大神类Manito和菜鸟类SmallBird继承Developer，重写develop()
3.定义公司类Company  1)定义成员函数招聘recruit()随机生成一个开发者对象，返回值为Developer*
					 2)定义Company类的成员函数work(Developer* )，调用Developer的develop()
					 
5.main中创建Company对象，调用recruit()获得一个Developer，然后调用work()传入Developer参数



二、多重继承

c++支持从多个基类派生出一个新类
格式：
class 子类名:继承方式 父类名1,继承方式 父类名2
{
	
};

示例：
1.Baby类，私有成员name，age，函数sleep()，eat()
2.Student类，私有成员score，函数study()
3.Xiaoming类继承Baby和Student类
  查看函数调用情况
   
#include <iostream>
#include <string>

using namespace std;

class Baby
{
private:
	string name;
	int age;
public:
	Baby(string name, int age):
		name(name),
		age(age)
	{
		cout<<"baby create"<<endl;
	}


	virtual void sleep()
	{
		cout<<"baby "<<name<<" sleep"<<endl;
	}

	virtual void eat()
	{
		cout<<"baby "<<name<<" eat"<<endl;
	}
};


class Student
{
private:
	int score;
public:
	Student(int score):score(score)
	{
		cout<<"student create"<<endl;
	}

	virtual void study()
	{
		cout<<"good good study"<<endl;
	}
};

class Xiaoming : public Baby, public Student
{
public:
	//初始化父类的顺序应该和继承的顺序保持一致
	//初始化成员变量的顺序应该和成员变量声明的顺序保持一致
	Xiaoming(string name, int age, int score):
		Baby(name, age),
		Student(score)
	{
		cout<<"xiaoming create"<<endl;
	}

	void eat()
	{
		cout<<"吃不下"<<endl;
	}

	void sleep()
	{
		cout<<"睡不着"<<endl;
	}

	void study()
	{
		cout<<"学不进去"<<endl;
	}
};

int main()
{
	Xiaoming* xm = new Xiaoming("小明",18,1);
	Baby* bb = xm;
	Student* s = xm;

	bb->eat();
	bb->sleep();
	//bb->study();//父类指针不能调用父类中没有声明的成员
	
	//s->eat();
	//s->sleep();
	s->study();
}



练习：设计一个圆类Circle(半径)和一个桌子类Table(高度和颜色)  再设计一个圆桌类RoundTable 
	它从前两个类派生 
要求：输出一个圆桌的高度 颜色  和面积



三、虚基类

以virtual声明的基类 使得在继承间接共同基类时 只对共同的基类初始化一次
格式：class 派生类名:virtual 继承方式 基类名
这种继承称作虚继承
只能在派生的时候声明虚基类

示例1：
#include <iostream>
#include <string>

using namespace std;

class A
{
protected:
	int money;
public:
	A(int money):money(money)
	{
		cout<<"a create"<<endl;
	}
};

class B : public A
{
public:      //B  中必须定义构造函数，如果不写就会调用父类默认无参构造函数，就会报错
	B(int money):A(money)
	{
		cout<<"b create"<<endl;
	}
};

class C : public A
{
public:
	C(int money):A(money)
	{
		cout<<"c create"<<endl;
	}
};

class D : public B, public C
{
public:
	D(int money):B(money-1),C(money+1)
	{
		cout<<"d create"<<endl;
	}

	void show()
	{
		cout<<C::money<<endl;//D对象中有两个money成员，需要通过类名::调用指定成员
	}
};

int main()
{
	D d(1);//  A B A C D 
	d.show();
}

//
初始化的时候必须是先父后子  

////////////////////类设计的合理，是不会出现这种现象的，有共同的基类A 
/////////////面试爱问 虚基类 发生歧义 

示例2：让D类中只有一个money  使用虚继承，是公共的基类只被初始化一次

#include <iostream>
#include <string>

using namespace std;

class A
{
protected:
	int money;
public:
	A()
	{
		cout<<"a create"<<endl;
	}
};

class B : virtual public A
{
public:
	B()
	{
		cout<<"b create"<<endl;
	}
};

class C : virtual public A
{
public:
	C()
	{
		cout<<"c create"<<endl;
	}
};

class D : public B, public C
{
public:
	D(int money)
	{
		cout<<"d create"<<endl;
	}

	void show()
	{
		cout<<money<<endl;
	}
};

int main()
{
	D d(1);
	d.show();
}

示例3：虚基类需要在最底层的派生类的初始化列表里对虚基类进行初始化

#include <iostream>
#include <string>

using namespace std;

class A
{
protected:
	int money;
public:
	A(int money):money(money)
	{
		cout<<"a create"<<endl;
	}
};

class B : virtual public A
{
public:
	B(int money):A(money)
	{
		cout<<"b create"<<endl;
	}
};

class C : virtual public A
{
public:
	C(int money):A(money)
	{
		cout<<"c create"<<endl;
	}
};

class D : public B, public C
{
public:
	D(int money):A(money),B(money),C(money)//在最底层的派生类的初始化列表中对虚基类进行初始化
	{
		cout<<"d create"<<endl;
	}

	void show()
	{
		cout<<money<<endl;
	}
};

int main()
{
	D d(1);
	d.show();
}


练习：设计一个虚基类Base   包括：protected数据: 姓名和年龄     成员函数eat();
      由它派生出领导类Leader 包含:私有数据职务duty和部门department            成员函数lead();
      再有Base类派生出工程师类Engineer 包含：私有数据职称major 专业professional  成员函数develop();
      然后由Leader类和Engineer类派生出主任工程师类Boss



小复习：

//虚基类：

	以virtual声明的基类 使得在继承间接共同基类时 只对共同的基类初始化一次
	
//虚函数：

	C++的虚函数主要作用是“运行时多态”，父类中提供虚函数的实现，为子类提供默认的函数实现。
	子类可以重写父类的虚函数实现子类的特殊化。
	
//父类指针指向子类对象与虚函数实现多态：

	父类* 指针 = new 子类();
	Shape* shape = new Rectangle();
	使用这种方式，父类的指针可以指向自己的所有派生类对象。
	如果使用这种指针方式，若调用父类普通函数，则调用函数时依然是父类的方法；若调用父类的虚函数，调用函数时调用的是子类重写之后的函数。

//多态:

	  1.子类可以重写父类中virtual函数，
	  2.用父类指向子类的指针或引用可以访问子类中重写的方法：为了将逻辑（类）当做参数进行传递
      3.父类可以调用子类重写的方法
	     	   
四、纯虚函数

1.纯虚函数：
	1）在基类中没有实现 
	2）/必须在派生类中加以实现   需要派生类实现其函数定义
	3）有纯虚函数的类相当于接口 抽象类 不能直接实例化

2.格式： 
virtual 返回值类型 函数名(形参列表) = 0 ; //声明此函数是纯虚函数

3.抽象类：包含纯虚函数的类  不允许创建抽象类对象
补充：
////////////////
天生当爹

4.抽象类:就是用来被继承的，纯虚函数就是用来被重写的。

5.定义纯虚函数的目的 是为了可以通过抽象类的指针去调用子类对象中重写的函数。


虚表：当类中定义虚函数后，编译器会生成一个虚函数表
（虚表，相当于一堆函数指针），
父类指针指向子类对象时，通过虚表去锁定调用子类中重写的函数。

示例1：
#include <iostream>
#include <string>

using namespace std;

class Person//  1.person是不能实例化的 person* p = new person; 会报错 
{
protected:
	string name;
public:
	Person(string name):name(name)
	{}
	virtual void sleep() = 0;
};

class Xiaoming : public Person
{
public:
	Xiaoming(string name):Person(name)
	{}
	void sleep()// 2.如果没有重写这个函数，是不能实例化对象的 Person* xm = new Xiaoming("小明");
	{
		cout<<"呼呼呼"<<endl;
	}
};

int main()
{
	//3.父类指针指向子类对象  
	Person* xm = new Xiaoming("小明");
	xm->sleep();
}

//练习：
定义一个抽象类形状Shape
纯虚函数：获得周长：int getPerimeter();
          得到形状：string getType();
		  
		 子类三角形：Triangle
			属性：边长 a、b、c  
			
		子类圆形：Circle
			属性：半径
			
		子类正方形：Square
		属性：边长a  
 


思考：析构函数的调用顺序
析构函数的调用顺序和构造函数的调用顺序是相反的

示例1：成员变量和构造函数   和   父类的成员变量和构造函数  以及   析构函数的顺序

补充：重点
/////////////////////////////
#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout<<"A create"<<endl;
    }
    
    ~A()
    {
        cout<<"A delete"<<endl;
    }
};

class B
{
private:
    A a;
public:
    B()
    {
        cout<<"B create"<<endl;
    }
    
    ~B()
    {
        cout<<"B delete"<<endl;
    }
};

class C
{
public:
    C()
    {
        cout<<"C create"<<endl;
    }
    ~C()
    {
        cout<<"C delete"<<endl;
    }
};

class D : public B
{
private:
    C c;
public:
    D()
    {
        cout<<"D create"<<endl;
    }
    ~D()
    {
        cout<<"D delete"<<endl;
    }
};

int main()
{
    D d;
    return 0;
}

总结：
	 1）成员变量和构造函数：/先成员 后构造  
	 2）父类的成员变量和构造函数： 先成员 后构造 
	 3）析构函数的顺序：同构造的顺序相反
	 
	
示例2：多继承的父类子类的初始化顺序
 
 
#include <iostream>

using namespace std;

class A
{
public:
    A(int a)
    {
        cout<<"A create"<<endl;
    }
    
    ~A()
    {
        cout<<"A delete"<<endl;
    }
};

class B
{
public:
    B(int a)
    {
        cout<<"B create"<<endl;
    }
    
    ~B()
    {
        cout<<"B delete"<<endl;
    }
};

class C : public B, public A
{
public:
    C():A(1),B(1)
    {
        cout<<"C create"<<endl;
    }
    ~C()
    {
        cout<<"C delete"<<endl;
    }
};

int main()
{
    C c;
    return 0;
}


总结：
补充：
/////////////////////////////////////////

1./无论构造与析构都是以继承顺序为准
2./成员变量赋值时，按照事先声明的顺序来的，
二者，均和参数列表无关


五、虚析构函数

使用父类指针指向子类对象，并通过父类指针删除子类对象时，
无法调用子类的析构函数。需要将父类的析构函数定义成虚析构

#include <iostream>
#include <string>

using namespace std;

class Animal                                    
{
public:
	Animal()
	{
		cout<<"Animal create"<<endl;
	}

	virtual ~Animal()
	{
		cout<<"Animal delete"<<endl;
	}
};

class Tiger : public Animal
{
public:
	Tiger()
	{
		cout<<"Tiger create"<<endl;
	}
	~Tiger()
	{
		cout<<"Tiger delete"<<endl;
	}
};

int main()
{
	Animal* p = new Tiger();

	delete p;
}
