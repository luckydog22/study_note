一、运算符重载

4、不能重载的运算符  ?:   sizeof()   .   ::    .*成员指针运算符

成员指针运算符示例：

示例1：
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	int age;
	string name;
public:
	Person(){}
	Person(int age, string name):age(age),name(name)
	{}

	void show()
	{
		cout<<name<<" "<<age<<endl;
	}
};

int main()
{
	int Person::* p;//成员指针，成员指针不是简单指向某个对象的成员变量
	//成员指针不一定指向哪个对象的成员变量
	p = &Person::age;//p指向Person类的age成员，仅仅是指向成员而已，并不
	//知道是指向哪个对象的

	Person p1(20, "你好使");
	Person p2(30, "小明行");

	cout<<p1.*p<<endl;//对象.*成员指针   调用对象的成员
	cout<<p2.*p<<endl;
	return 0;
}
示例2：

#include <iostream>
using namespace std;

class Person
{
public:
	int age;
public:
	Person(int age):age(age){}
	void show()
	{
		cout<<age<<endl;
	}
};

int main()
{
	Person xiaoming(10);
	Person xiaohong(20);
	//ps是成员函数指针，只能指向Person类的成员函数
	void(Person::*ps)() = &Person::show;//此时还不确定指向的是哪个对象的show函数
	(xiaoming.*ps)();//执行xiaoming对象的show函数
	(xiaohong.*ps)();//执行xiaoihong对象的show函数
	//成员指针运算符一般用于类对象的函数作为回调函数
	//传参数的时候，不知要传函数，还要传调用函数的对象
	xiaoming.show();
	xiaohong.show();

	return 0;
}


练习：设计一个三角形类Triange 包含三角形三条边长的私有数据成员
另有一个重载运算符'+'  以实现求两个三角形周长之和  
注意：两个三角形对象相加


练习：设计一个学生类 包括姓名和三门成绩(C++ C linux) 
	利用重载运算符'+=' 将所有学生成绩的和汇总到一个学生对象中


练习：在Time类中设计如下重载运算符函数++
1.私有成员h m s
2.重载后缀++ 让时间变成下一秒
3.show函数显示时间

忠告：不要为了重载运算符而重载运算符，重载运算符只是为了代码看起来更加简洁

二、类继承 
封装、继承和多态面向对象三大特性
继承可以是面向对象代码重用，继承也是实现多态的必要语法

1、基类 派生类  父类 子类
class 子类名:继承方式 父类名1，继承方式 父类名2，继承方式 父类名3....
{
	子类新添加的成员;	
}

示例1：
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string name;
public:
	void show()
	{
		cout<<name<<endl;
	}
};

class Xiaoming : public Person
{
public:
	Xiaoming(string name)
	{
		//成员变量name是从父类Person继承过来的，而且name的父类中的访问权限是protected
		//所以子类Xiaoming对name有访问权限。
		//子类继承父类，会继承父类中所有的成员，包括私有的成员，只是没有
		//对私有成员的访问权限而已.
		this->name = name;
	}
};

int main()
{
	Xiaoming xm("小明");
	xm.show();
}

示例2：子类的初始化列表中可以通过父类的构造函数来初始化父类的成员，
	如果没有显式的调用父类构造函数，会默认调用父类无参的构造函数，
	如果父类中没有无参构造函数，子类的初始化列表中必须显式的调用父类带参的构造函数
#include<iostream>
using namespace std;
class Person
{
protected:
	string name;
	bool gender;
public:
		void eat(const char*food)
		{
			cout<<name<<"吃"<<food<<endl;
		}
		void sleep()
		{
			cout<<name<<" sleep"<<endl;
		}
		void show()
		{
			cout<<"大家好 我是"<<(gender?"帅哥":"美女")<<name<<" 很荣幸认识你!"<<endl;
		}
		Person(const char *na,bool g):name(na),gender(g)
		{
			cout<<"person create"<<endl;
		}
};

class Teacher:public Person 
{
private:
	string course;
public:
		Teacher(const char*na,bool g,string c):Person(na,g),course(c)//na和g会传递给父类的构造函数
		{
			cout<<"teacher create"<<endl;
		}
		void teach(const char *c)
		{
			cout<<name<<"老师"<<"讲"<<"课程"<<course<<endl;
		}

		void show()//子类该写了父类的成员 隐藏来自父类同名的成员 子类可以拓展
		{
			cout<<"我是"<<course<<"老师"<<name<<" comeon(掌声)!"<<endl;
		}
};

int main()
{

	//Person a("李朝阳",true);
	Teacher t("doudou",false,"c++");
	
	t.eat("饺子");
	t.show();
	t.Person::show();//可以使用父类的show
} 

练习：编写程序 
设计一个汽车类Vehicle 包含的数据成员：车轮个数wheels,车重weight 
小车类car是汽车类的派生类 包含数据成员:载人数passenger_load 
卡车类Truck是汽车类的派生类 包含： 载人数passenger_load  载重量pay_load
每个类都有相关数据的输出方法show显示所有的成员


2、继承方式影响:

public继承   子类继承后的访问权限不变
protected继承  子类继承后，父类中的public变成protected，其它不变
private继承	子类继承后，父类中的public和protected变成private，其他不变

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

class B : protected A
{
public:
	B(int a):A(a){}
};

int main()
{
	B b(10);
	b.show();//编译错误  show在B中是protected的访问权限
}

练习：
先设计一个Point类 包含：x，y(坐标)  --基类
由Point类派生出一个Circle类 增加数据成员r(半径)
Circle类定义函数计算面积
由Circle类为直接基类派生出一个Cylinder（圆柱体）类 再增加成员h(高)
Cylinder（圆柱体）类定义函数计算体积


练习：
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



三、虚函数
虚函数的目的是重写
重写的目的是多态

c++中定义成员函数时 前边加关键字virtual 这个函数就是虚函数  virtual void eat();


对比重载：overload 在同一个类中或者是全局的函数，函数名相同，参数列表不同，
	返回值无所谓，叫重载。在继承中父类和子类中不存在重载关系
1、重写：override 子类继承父类，父类中定义虚函数，
	子类中定义和父类中虚函数同名，同返回值类型，同参数列表的函数，叫重写。
	重写后子类加不加virtual都可以，子类中重写后的函数依然是虚函数
示例：
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	//虚函数　子类可以重写
	virtual void eat()
	{
		cout<<"Person eat"<<endl;
	}
};

class Student : public Person
{
public:
	//重写父类的　eat函数
	void eat()//子类中的是不是虚函数？ 是虚函数
	{
		cout<<"student eat"<<endl;
	}
};

多态: 子类可以重写父类中virtual函数，用父类指向子类的指针或引用可以访问子
		类中重写的函数，通过将不同类型的对象进行传递来实现复杂逻辑的传递。

1.父类的指针和引用可以指向子类对象
2.父类的指针和引用可以调用子类中重写的函数

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	//虚函数　子类可以重写
	virtual void eat()
	{
		cout<<"Person eat"<<endl;
	}

	void sleep()
	{
		cout<<"Person sleep"<<endl;
	}
};

class Student : public Person
{
public:
	//重写父类的　eat函数
	void eat()
	{
		cout<<"student eat"<<endl;
	}

	void sleep()
	//sleep函数不是重写的函数，因为父类中的sleep不是虚函数，sleep只是一个
	//和父类中重名的函数而已W
	{
		cout<<"student sleep"<<endl;
	}
};

int main()
{
	Student xiaoming;
	Person& p1 = xiaoming;//父类引用指向子类对象
	p1.eat();//会调用子类中重写的eat函数
	p1.sleep();//因为父类中sleep没有定义成虚函数，所以没有重写，所以调用父类的sleep

	Person* p2 = &xiaoming;//指针的用法同引用
	p2->eat();
	p2->sleep();
}

练习：
1.定义基类Developer，有虚函数develop()
2.定义大神类Manito和菜鸟类SmallBird继承Developer，重写develop()
3.定义公司类Company，定义成员函数招聘recruit()随机生成一个开发者对象，返回值为Developer*
4.定义Company类的成员函数work(Developer* )，调用Developer的develop()
5.main中创建Company对象，调用recruit()获得一个Developer，然后调用work()传入Developer参数





四、多重继承
c++支持从多个基类派生出一个新类
格式：
class 子类名:继承方式 父类名1,继承方式 父类名2
{
	
};

示例：
1.Baby类，私有成员name，age，函数sleep()，eat()
2.Student类，私有成员score，函数study()
3.Xiaoming类继承Baby和Student类

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

思考：析构函数的调用顺序
析构函数的调用顺序和构造函数的调用顺序是相反的
示例1：成员变量和构造函数和父类的成员变量和构造函数以及析构函数的顺序
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
	//先初始化父类，再初始化子类；在类的内部先初始化成员变量，再调用构造函数。
    D d;
    return 0;
}

示例2：多继承的父类子类的初始化顺序
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

class C : public B, public A
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

int main()
{
    C c;
    return 0;
}



练习：设计一个圆类Circle(半径)和一个桌子类Table(高度和颜色)  
	再设计一个圆桌类RoundTable 它从前两个类派生 
要求：输出一个圆桌的高度 面积和颜色




五、虚基类
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
public:
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
		cout<<money<<endl;//D对象中有两个money成员，需要通过类名::调用指定成员
	}
};

int main()
{
	D d(1);
	d.show();
}

虚继承很有用吗？如果类的层次设计的逻辑清晰，是不会出现需要虚继承的情况的。

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
	D(int money):A(money),B(money+1),C(money-1)
	//在最底层的派生类的初始化列表中对虚基类进行初始化
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

练习：设计一个虚基类Base 包括：protected数据姓名和年龄及 成员函数eat()
由它派生出领导类Leader 包含私有数据职务和部门及 函数lead()
再有Base类派生出工程师类Engineer 包含私有数据职称 专业及 函数develop()
然后由Leader类和Engineer类派生出主任工程师类Boss




六、纯虚函数
纯虚函数的目的：基类中的没有逻辑的函数不需要实现
纯虚函数：在基类中没有实现 必须在派生类中加以实现  
有纯虚函数的类相当于接口 不能直接实例化
需要派生类实现其函数定义
格式： 
virtual 返回值类型 函数名(形参列表)=0  //声明此函数时纯虚函数
纯虚函数不能被实现，只能被重写

抽象类：包含纯虚函数的类  不允许创建抽象类对象

抽象类就是用来被继承的，纯虚函数就是用来被重写的。
定义纯虚函数的目的是为了可以通过抽象类的指针去调用子类对象中重写的函数。

虚表：当类中定义虚函数后，编译器会生成一个虚函数表（虚表，相当于一堆函数指针），
父类指针指向子类对象时，通过虚表去锁定调用子类中
重写的函数。虚表这个东西在语法上没有可操作的空间。

示例1：
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string name;
public:
	Person(string name):name(name)
	{}
	virtual void sleep()=0;//因为有了纯虚函数，所以Person是抽象类，不能实例化对象
};

class Xiaoming : public Person
{
public:
	Xiaoming(string name):Person(name)
	{}
	void sleep()
	{
		cout<<"呼呼呼"<<endl;
	}
};

int main()
{
	Person* xm = new Xiaoming("小明");
	xm->sleep();
}

练习：定义一个抽象类形状Shape
纯虚函数：获得周长：int getPerimeter();
          得到形状：string getType();
子类三角形：Triangle
   属性：边长 a、b、c   
子类圆形：Circle
   属性：半径
子类正方形：Square
  属性：边长a  
 

语言本身什么也干不了，语言的使用脱离不了语言的环境
做游戏开发(需求)---->cocos2dx(环境)----->lua js c++(选择一个环境支持的语言)

七、虚析构函数
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


练习：
设计某小型公司的人员管理系统

（1）类

①Employee类：
成员变量（私有）：编号id、姓名name、性别gender、出生日期birthday、职位position和基本工资basicSalary。
出生日期使用自定义的Date（日期）类；
多个构造函数：缺省(无参)构造函数、带参数的构造函数、带默认参数的构造函数；
共有函数计算工资virtual float getSalary()


②Date类：
成员变量：年year、月month、日date
成员函数：SetYear(int year)、SetMonth(int month)、SetDay(int day)、GetYear()、GetMonth()、GetDay()等
多个构造函数：缺省构造函数、带参数的构造函数、带默认参数的构造函数；

③由Employee类派生销售员工Salasman类，Salasman类包含两个新数据成员：销售额sales和提成比例commrate。

④由Salasman类派生出销售经理Salamanager类。Salasmanager类包含新数据成员：职务工资jobSalary。

（2）月工资计算办法：
一般员工月薪=基本工资
销售员工月薪=基本工资+销售额*提成率  
销售经理月薪=基本工资+职务工资+销售额*提成率

（3）基本功能如下，需将以下功能转化为不同的成员函数：

①各类人员信息的录入（包括基本工资等）；

②各类人员信息的显示（包括月工资）；name 工资

③用对象数组保存已输入的人员对象；

④可以修改人员的基本信息，如：姓名、职位等；

⑤可以通过编号或姓名进行人员查询。

八、模板 ：
可以将类型当作参数进行传递

static_cast<>()
dynamic_cast<>()
// 将父类类型的指针转换成子类类型的指针，
//使用dynamic_cast转换指针类型，父类中必须有虚函数

示例：
class Employee
{
public:
	virtual void work(){}
};

class Salasman : public Employee
{
public:
	void work(){}
};

Employee* e = new Employee();
Salasman* s = dynamic_cast<Salasman*>(e);
if(s == NULL)
{
    cout<<"转换失败"<<endl;
}
else
{
    cout<<"成功"<<endl;
}




