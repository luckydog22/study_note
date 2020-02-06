复习：

//虚基类：
	以virtual声明的基类 使得在继承间接共同基类时 只对共同的基类初始化一次
	
//虚函数：
	C++的虚函数主要作用是“运行时多态”，父类中提供虚函数的实现，为子类提供默认的函数实现。子类可以重写父类的虚函数实现子类的特殊化。
	
//父类指针指向子类对象与虚函数实现多态：

	父类* 指针 = new 子类();
	Shape* shape = new Rectangle();
	使用这种方式，父类的指针可以指向自己的所有派生类对象。
	如果使用这种指针方式，若调用父类普通函数，则调用函数时依然是父类的方法；若调用父类的虚函数，调用函数时调用的是子类重写之后的函数。

//多态:
	  1.子类可以重写父类中virtual函数，
	  2.用父类指向子类的指针或引用可以访问子类中重写的方法：为了将逻辑（类）当做参数进行传递
      3.父类可以调用子类重写的方法
	  
1.纯虚函数：
	1）在基类中没有实现 
	2）必须在派生类中加以实现   需要派生类实现其函数定义
	3）有纯虚函数的类相当于接口 不能直接实例化

2.格式： 
virtual 返回值类型 函数名(形参列表) =0  //声明此函数是纯虚函数

3.抽象类：包含纯虚函数的类  不允许创建抽象类对象

4.抽象类就是用来被继承的，纯虚函数就是用来被重写的。

5.定义纯虚函数的目的是为了可以通过抽象类的指针去调用子类对象中重写的函数。


虚表：当类中定义虚函数后，编译器会生成一个虚函数表（虚表，相当于一堆函数指针），父类指针指向子类对象时，通过虚表去锁定调用子类中
重写的函数。



【题目1】在继承时，继承方式都有什么影响？

当用public继承时，派生类继承到的所有成员访问权限不变
当用protected继承时，派生类继承到的public成员变为protected，其余不变
当用private继承时，派生类集成到的所有成员都为private

【题目2】虚析构函数的作用

当用父类指针指向子类对象时，释放父类对象时不会调用子类的析构函数，所以定义父类的析构函数时需要加virtual，使其成为虚析构函数


/*********************************************
			
			新课

**********************************************/


一、模板 ：

可以将类型当作参数进行传递


1、函数模板： 只适用于函数体相同 参数个数相同 类型不同的情况
   使用：建立一个通用函数 其函数返回值类型和形参类型不具体制定 而是一个虚拟类型
   
 *****  注意：模板的声明和实现必须在同一个文件中，所以模板只有.h文件
 
 补充：
 //////////////////
 因为模板的T作用域就在于类里，出了类就失效了


 
int div(int a,int b)
{
	return a/b;
}
float div(float a,float b)
{
	return a/b;
}
int main()
{
	div<float>(3,2);
	
}

示例1：
#include<iostream>
using namespace std;

template<typename T> 	//<>类型参数列表  类型参数T可以在函数的任意位置当作类型来使用
void show(T data)
{
	cout<<data<<endl;
}

int main()
{
	double d=1.23;
	int a=90;
	show<int>(a);//<>中传递类型参数
	show<double>(d);
}

补充：
//////////////////
使用模板时，比平常的调用，多了 <类型>

示例2：
#include<iostream>
using namespace std;

template<typename T>
T show(T data)
{
	return data+90;
}

int main()
{
	double d=1.23;
	int a=90;
	cout<<show<int>(a)<<endl;
	cout<<show<double>(d)<<endl;
}

练习：做两个数的除法，函数返回值返回结果

//函数的模板 关键字：template  <typename T>是参数的类型
template<typename T,typename U>
T div(T a, U b)
{

    return a/b;
}

int main()
{
    cout<<div<int,float>(10,3.5f)<<endl; //<>中传递类型参数

    return 0;
}



示例2：多类型参数
#include <iostream>
#include <string>

using namespace std;

template<typename T,typename U>
T div(T a, T b, U c)
{
	cout<<c<<endl;
	return a/b;
}

int main()
{
	cout<<div<double, string>(10, 3, "hello farsight")<<endl;
}

2、类模板

//对于模板类型的变量，一般可以new delete 赋值 拷贝 +

示例：
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Person
{
public:
    Person(int age):age(age)
    {
        
    }
		void eat(T food)
		{
			cout<<food<<age<<endl;
		}
private:
    int age;
};

int main()
{
	Person<string> xiaoming(2);	
	xiaoming.eat("牛排");
	
	Person<string>* p = new Person<string>(10);
  p->eat("鸡排");
  delete p;
}

注意：类模板没有cpp文件，所有的函数实现都写在头文件中；对于模板类型操作，只能是赋值、复制和取地址。

练习：增删改查

1.定义模板链表类Link
2.私有内部结构体Node{T data, Node* pNext, Node* pFront}
3.私有成员指针pHead  pTail size 
4.公有函数add(T data)向尾部添加元素



5.公有函数重载operator[] 返回 指定位置的数据,并可以通过[]修改对应位置的数据

T& operator[](int index)
{
	
}
cout<<link[2]<<endl;
link[2] = 12;

6.公有函数erase(index)删除index位置的元素

7.公有函数erase(int start, T data)从start位置开始查找删除链表中data的元素

8.公有函数size()返回链表的长度

#include <iostream>

using namespace std;

template<typename T>
class Link
{
 private:
    //结点结构体
    struct Node
    {
        //指向上一个 下一个结点的指针
        T data;
        Node* pNext;
        Node* pFront;
        //构造函数
        Node(){}
        Node(T data):data(data),pNext(NULL),pFront(NULL)
        {
        }

    };
  //头尾指针
    Node* pHead;
    Node* pTail;
    int mSize;
 public:
    Link()
    {
        //创建空头结点
        Node* p = new Node;
        //头尾指针指向空头结点
        pHead = p;
        pTail = p;
        mSize = 0;
    }
    //增加一个结点
    void add(T data)
    {
        Node* pNode = new Node(data);
        //1.尾指针指向的结点的next  指向新建的结点
        pTail->pNext = pNode;
        //2.新建结点的front 指向尾节点
        pNode->pFront = pTail;
        //3.尾指针指向新建的结点
        pTail = pNode;
        //4.长度++
        mSize++;
    }

    //删除一个结点
    void erase(int index)
    {
        //循环 找到链表中位置为index的这个结点
    Node* pNode = pHead->pNext;
    for(int i =1; i< index; i++)
    {
        pNode = pNode->pNext;
    }
    if(pNode == pTail)
    {
       //删除的为尾节点时
        pTail = pTail->pFront;
        pTail->pNext = NULL;

    }else
    {
        //删除中间结点时
        pNode->pFront->pNext = pNode->pNext;
        pNode->pNext->pFront = pNode->pFront;
    }
    delete pNode;
    mSize--;
}
    //运算符重载[]
    T& operator[](int index)
    {
        Node* pNode = pHead->pNext;
        for(int i = 1; i< index; i++ )
            pNode = pNode->pNext;
        return pNode->data;
    }
    //从start位置开始查找，删除数据为data的结点
     void erase(int start, T data)
     {
         Node* pNode = pHead->pNext;
         for(int i =1; i<start; i++)
             pNode= pNode->pNext;
         for(int i = start; i< mSize; i++)
         {
             if(pNode->data == data)
             {
                 erase(i);
             }
             //else

                 pNode = pNode->pNext;

         }

      }

    int getSize()
    {
        return mSize;
    }

};


int main()
{
   Link<int> l;
   for(int i = 0 ; i < 10; i++)
       l.add(i);
   cout<<l.getSize()<<endl;

    //获取第4个位置的数据
   cout<<"第三个位置："<<l[3]<<endl;

    cout<<"------------------"<<endl;

   //修改第3个位置的数据 ，值为100
    l[3] = 100;

   for(int i = 1 ; i< l.getSize();i++)
       cout<<l[i]<<endl;

    cout<<"------------------"<<endl;

   l.erase(1,5);

   for(int i = 1 ; i<l.getSize();i++)
       cout<<l[i]<<endl;

    return 0;
}




三、explicit
explicit用来防止由构造函数定义的隐式转换。

1、隐式转换：可以用单个实参来调用的构造函数定义了从形参类型到该类类型的一个隐式转换。

示例1：
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    int age;
    string name;
public:
    Person()
    {
        cout<<"no arg"<<endl;
    }
    
    Person(int age):age(age)
    {
        cout<<"int arg"<<endl;
    }
    
    Person(const char* name):name(name)
    {
        cout<<"string arg"<<endl;
    }
	void show()
	{
		cout<<age<<endl;
	}
};

void fun(Person p)
{
	p.show();
}

int main()
{
    Person p = 10;   //Person p(10);  隐式转换
    Person p2 = "farsight";//Person p1("farsight");
	
	///////针对后加的代码和fun方法  可以这样调用：fun(10); 这样的写法太浪  不好 如意产生歧义
    return 0;
}

示例2：
#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
    int a ;
	string s;
public:
    Test(int a, string s):a(a)
    {
        cout<<a<<endl;
    }

};
int main()
{
    Test a = 10;//不能隐式转换
    return 0;
}

示例3：
#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
    int a = 10;
public:
    Test(int a, string s = "farsight"):a(a)
    {
        cout<<a<<endl;
    }

};
int main()
{
    Test a = 10;//隐式转换
    return 0;
}

*******通过一个参数就能调用构造函数的时候，就能促发隐式转换

2、explicit
示例：
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    int age;
    string name;
public:
    Person()
    {
        cout<<"no arg"<<endl;
    }
    
    explicit Person(int age):age(age)
    {
        cout<<"int arg"<<endl;
    }
    
    explicit Person(const char* name):name(name)
    {
        cout<<"string arg"<<endl;
    }
};

int main()
{
    Person p = 10;//Person p(10);
    Person p2 = "farsight";//Person p1("farsight");
    return 0;
}
explicit的优点是可以避免不合时宜的类型变换，缺点无。
被声明为explicit的构造函数通常比其non-explicit兄弟更受欢迎。
因为它们禁止编译器执行非预期（往往也不被期望）的类型转换。
除非有一个好理由允许构造函数被用于隐式类型转换，否则要把它声明为explicit。
