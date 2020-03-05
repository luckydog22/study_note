
一、模板 ：
可以将类型当作参数进行传递

static_cast<>()
dynamic_cast<>()

示例：
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

1、函数模板：只适用于函数体相同 参数个数相同 类型不同的情况
使用：建立一个通用函数 其函数返回值类型和形参类型不具体制定 而是一个虚拟类型
注意：模板的声明和实现必须在同一个文件中，所以模板只有.h文件

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
	show<int>(a);//<>中传递类型参数 在这行调用中T的类型是int
	show<double>(d);//在这行调用中T的类型是 double
}

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




示例3：多类型参数
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
	Person<string> xiaoming(11);	
	xiaoming.eat("牛排");
	Person<string>* p = new Person<string>(10);
  p->eat("鸡排");
  delete p;
}

注意：类模板没有cpp文件，所有的函数实现都写在头文件中；对于模板类型操作，
	最好只是赋值、复制和取地址。

练习：增删改查
1.定义链表类Link
2.私有内部结构体Node{T data, Node* pNext, Node* pFront}
3.私有成员指针pHead  pTail
4.公有函数add(T data)向尾部添加元素
5.公有函数重载[] 返回 指定位置的数据,并可以通过[]修改对应位置的数据
6.公有函数erase(index)删除index位置的元素
7.公有函数erase(int start, T data)从start位置开始查找删除链表中data的元素，
		删除所有满足条件的元素。
8.公有函数size()返回链表的长度


二、explicit
explicit用来防止由构造函数定义的隐式转换。

1、隐式转换：可以用单个实参来调用的构造函数定义了从形参类型到该类类型的
		一个隐式转换。
注意：隐式转换在绝大部分情况下是不好的。


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
};

int main()
{
    Person p = 10;//Person p(10);  隐式转换
    Person p2 = "farsight";//Person p1("farsight");
    return 0;
}

示例1.1
class Person
{
public:
    Person()
    {}
    Person(int a)
    {}
};

void fun(Person p)
{
    
}

int main()
{
    fun(1);//隐式转换，使用参数1 创建了一个Person对象
｝
示例2：
#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
    int a = 10;
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
除非有一个好理由（参考C++ string）允许构造函数被用于隐式类型转换，
否则要把它声明为explicit。


三、STL：标准模板库  standard  template  library
容器：顺序(线性)容器   关联容器 键值对key-value
所有的容器都是自增长

1、顺序容器：使用方式基本一致，实现原理不一样，根据对数据的操作选择适合的容器
vector 支持快速随机访问  数组原理 推荐  O（1）
list	 支持快速插入/删除  链表原理		O（N）
deque	 双端队列  一段一段的数组连起来

1.常用操作
示例1：常用操作
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(rand()%100);//向尾部插入
    }
    
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v[0] = 521;
    for(int i = 0;i < v.size();i++)//size()是容器中的数据个数
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
示例2：迭代器遍历
引例：使整型变量每次只能被加1或者减1，并且值在0~10之间
class A
{
private:
    int a;
public:
    A():a(0)
    {}    
    void operator++()
    {
        if(a == 10)
        {
            return;
        }
        a++;
    }   
    void operator--()
    {
        if(a == 0)
        {
            return;
        }
        a--;
    }
};

int main()
{
	A s;
	++s;
	--s;
	return 0;	
}

C++中的迭代器是对指针的封装，迭代器提供特定的函数让调用者对指针进行特定的安全的操作

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);//向尾部添加元素
    }
    //将所有的值为偶数的元素变成0
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        if(*iter%2 == 0)
            *iter = 0;
    }
    
    //begin是容器的头元素 ，end并不是尾元素，而是无效的元素表示容器结束
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;//*来访问迭代器指向的元素
    }
    
    return 0;
}

示例3.1：迭代器遍历删除
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> v;
    for(int i = 0;i < 100;i++)
    {
        v.push_back(i);
    }
    
    for(list<int>::iterator iter = v.begin();iter != v.end();)
    {
        if(*iter%2 == 0)
        {
            iter = v.erase(iter);//erase返回值是指向删除节点的下一个节点的迭代器
        }
        else
        {
            iter++;
        }
    }
    
    for(list<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;
    }
    
    return 0;
}
示例3.2：查找迭代器删除
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    														//前闭后开区间：包含begin但是你不包含end
    vector<int>::iterator iter = find(v.begin(), v.end(), 3);
    
    v.erase(iter);
    
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;
    }
    
    return 0;
}

3.3：查找迭代器删除自定义类型
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int num;
    char name;
    Node(int num, char name):num(num),name(name)
    {}
    
    bool operator==(const Node& other) const
    {
        if(num == other.num && name == other.name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void show()
    {
        cout<<num<<" "<<name<<endl;
    }
};

int main()
{   
    vector<Node> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(Node(i,'a'+i));
    }
    
    vector<Node>::iterator iter = find(v.begin(), v.end(), Node(30,'e'));
    
    if(iter != v.end())//没有找到返回end()
        v.erase(iter);
    
    for(vector<Node>::iterator iter = v.begin();iter != v.end();iter++)
    {
        iter->show();
    }
    
    return 0;
}
2.其他操作
2.1.迭代器操作：(适用于所有的标准库容器) 
*iter 返回迭代器所指向的引用 
iter->mem 对iter进行解引用 
++iter 自增 
iter++ 
–-iter 自减 
iter–-
iter1==iter2 比较两个迭代器是否相等 
iter1！=iter2 
iter +n、iter-n、iter1+=iter2、iter1-=iter2 
注：任何改变容器大小的操作都有可能使得迭代器失效
2.2.begin()和end()成员（支持所有容器） 
c.begin() 、c.end() 返回一个迭代器，指向第一个和最后一个的下一个成员 
c.rbegin() 返回一个逆序迭代器。指向容器c的最后一个元素 
c.rend() 返回一个逆序迭代器，指向容器c的第一个元素的前面一个位置
2.3.在容器中添加元素 
c.push_back(t) 支持所有容器 
c.push_front(t) 只支持list和deque容器 
c.insert(p,t)、c.insert(p,n,t)、c.insert(p,b,e) 支持所有容器
2.4.容器大小的操作（支持所有容器） 
c.size() 返回c中的元素个数。返回类型为c::size_type 
c.max_size() 返回c中所能容纳的最大个数，类型为：c::size_type 
c.empty() 
c.resize(n) 改变容器的大小
2.5.访问元素 
c.back() 返回容器c中的最后一个元素的引用 
c.front() 返回容器c中的第一个元素的以引用 
c[n] 下标操作 只适用于vector和deque 只能操作已存在的元素 
c.at[n] 下标操作 只适用于vector和deque 只能操作已存在的元素
2.6.删除操作 
c.erase(p) 删除迭代器p指向的元素 
c.erase(b,e) 
c.clear() 删除容器c中的所有元素 
c.pop_back() 删除容器c中的最后一个元素 
c.pop_front() 删除容器c中的第一个元素，只适用于list和deque
2.7.赋值与swap 
c1=c2 删除c1中的所有元素，再把c2中的所有元素赋值给c1c 
c1.swap(c2) 交换内容 
c.assgin(b,e) 重置c中的元素，并将迭代器范围内的元素赋值给c 
c.assgin(n,t) 将容器c重新设置为存储n个值为t的元素

3.queue、stack、priority_queue 
容器适配器都需要一个基础容器(vector list deque)，不同容器适配器其基础的容器也不一样 
queue：先进先出的数据结构，需要在队头和队尾同时操作元素，所以其可以关联的容器有list（默认）和deque； 
stack：先进后出的数据结构，只需要在队尾操作元素即可，其可关联三种容器； 
priority_queue:由于其在插入元素时根据优先级插入元素，插入位置不固定。
		所以其要求有随机访问的功能，所以一般只建立在vector和deque上；
示例1：
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    //vector<int> v;
    //stack<int, vector<int> > s(v);//模板参数1 stack存放的数据类型 模板参数2 stack基于的容器类型
    stack<int> s;//使用默认容器
		//具体实现原理参考第一天的栈练习，将练习中的动态数组换成vector
    for(int i = 0;i < 10;i++)
    {
        s.push(i);
    }
    
    while(!s.empty())
    {
        cout<<s.top()<<endl;//获得栈顶元素，但是元素不出栈
        s.pop();//站定元素出栈
    }
    return 0;
}
示例2：优先队列
优先队列又叫堆
堆是用来找极值（极大值、极小值）
C++的优先队列找极大值
#include <queue>

using namespace std;

class Person
{
public:
    Person(int age):age(age){}
    bool operator<(const Person& other) const
    {
        return age>other.age;
    }
    void show() const
    {
        cout<<age<<endl;
    }
private:
    int age;
};

int main()
{
    priority_queue<Person, vector<Person> > que;
    que.push(Person(12));
    que.push(Person(2));
    que.push(Person(66));
    que.push(Person(5));
    while(!que.empty())
    {
        que.top().show();
        que.pop();
    }
    return 0;
}

4.栈适配的操作 
s.empty() 判断栈是否为空 
s.size() 返回栈中元素个数 
s.pop() 删除栈顶元素 
s.top() 返回栈顶元素，但是不删除 
s.push(item) 在栈顶压入新的元素
5.队列和优先级队列 
q.empty()、q.size()、q.top()、 
q.front()、q.back() 只适用于队列 
q.top() 只适用于优先级队列


2、关联容器
1. pair<T1, T2>  pair也是一种模板类型。键(key)值(value)对
	它的数据成员是公有的，分别命名为first和second
	在map容器中，叫first为key，叫second为velue
示例：

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	pair<string, int> p("hehe", 10);
	cout<<p.first<<" "<<p.second<<endl;
}
	
2. map<key, value> 关联容器，以键值对key-value形式存放数据  红黑树
O（logN）
map是存放pair的容器，map中的每个节点都是一个pair

二叉树

查找二叉树：每个节点的做孩子比它小，右孩子比它大

平衡查找二叉树(AVL树)：左右两个子树深度差不大于1

红黑树：不是为了提升AVL树的查找效率，而是为了提升AVL树的插入效率；牺牲一定的平衡性，减少插入数据时的旋转操作
1.将所有节点标记成红的或者黑的
2.根节点一定是黑的
3.不能有两个红节点连在一起
4.从根到叶子的任意路径黑节点的数量必须相等

2.1 插入和查询操作
示例：
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	//map不能有相同键
	m.insert(pair<string, int>("小明",18));//插入数据  不允许键重复，如果键重复无法插入
	m["小强"] = 20;//插入数据，如果key已经存在就修改数据

	cout<<m["小明"]<<endl;
	cout<<m["小强"]<<endl;
}

2.2 迭代器遍历
示例：

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	m.insert(pair<string, int>("小明",18));
	m["小强"] = 20;
	
	for(map<string, int>::iterator iter = m.begin();iter != m.end();iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
}

2.3 查找
示例：
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	m.insert(pair<string, int>("小明",18));
	m["小强"] = 20;
	
	cout<<m.count("小明")<<endl;//count查找该key出现的次数，返回值可能是0或者1 0表示没有该key，1表示有而且数量就是1
	cout<<m.count("小红")<<endl;

	map<string, int>::iterator iter = m.find("小红");//find返回该key的迭代器对象
	if(iter != m.end())
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	else
	{
		cout<<"查无此项"<<endl;
	}
}

2.4 删除
m.erase(k)   //从m中删除key为k的元素。
m.erase(p)   //从m中删除迭代器p指定的元素

2.5 自定义key类型
重载运算符 <

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person
{
public:
    Person(const char* name):name(name)
    {
        
    }
    bool operator<(const Person& other) const
    {
        return name < other.name;
    }
    string getName() const
    {
        return name;
    }
private:
    string name;
};

int main()
{
    map<Person, int> m;
    m.insert(pair<Person, int>("jack", 18));
    m.insert(pair<Person, int>("rose", 1));
    m.insert(pair<Person, int>("tom", 2));
    m.insert(pair<Person, int>("jerry", 3));
    
    for(map<Person, int>::iterator iter = m.begin();iter != m.end();iter++)
    {
    		//左中右 jack  jerry  rose tom
        cout<<iter->first.getName()<<" "<<iter->second<<endl;
    }
    
    return 0;
}

2.6 自定义链表类中添加迭代器遍历
#ifndef LINK
#define LINK

template<typename T>
class Link
{
private:
    struct Node
    {
        Node()
        {}
        Node(T data):
            data(data),
            pNext(NULL),
            pFront(NULL)
        {}
        T data;
        Node* pNext;
        Node* pFront;
    };
public:
    class iterator
    {
    friend class Link;
    private:
        Node* pNode;
    public:  
        bool operator!=(const iterator& other)
        {
            return pNode != other.pNode;
        }
        void operator++(int a)
        {
            pNode = pNode->pNext;
        }
        T* operator->()
        {
            return &(pNode->data);
        }
        T& operator*()
        {
            return pNode->data;
        }
    };
    iterator begin()
    {
        iterator i;
        i.pNode = pHead->pNext;
        return i;
    }
    
    iterator end()
    {
        iterator i;
        i.pNode = NULL;
        return i;
    }
    Link():mSize(0)
    {
        Node* pNode = new Node();
        pHead = pNode;
        pTail = pNode;
    }
    
    Link& add(T data)
    {
        Node* pNode = new Node(data);
        pTail->pNext = pNode;
        pNode->pFront = pTail;
        pTail = pNode;
        mSize++;
        return *this;
    }
    
    int size()
    {
        return mSize;
    }
    
    T& operator[](int index)
    {
        Node* pNode = find(index);
        return pNode->data;
    }
    
    Link& erase(int index)
    {
         Node* pNode = find(index);
         deleteNode(pNode);
         return *this;
    }
    
    Link& erase(int start, const T& data)
    {
        Node* pNode = find(start);
        for(int i = start;i < mSize;i++)
        {
            if(pNode->data == data)//这样使用模板是不科学的
            {
                deleteNode(pNode);
                mSize--;
                break;
            }
            pNode = pNode->pNext;
        }
        return *this;
    }
private:
    Node* find(int index)
    {
        Node* pNode = pHead->pNext;
        for(int i = 0;i < index;i++)
        {
            pNode = pNode->pNext;
        }
        return pNode;
    }
    void deleteNode(Node* pNode)
    {
        if(pNode == pTail)
        {
            pTail = pTail->pFront;
            pTail->pNext = NULL;
            delete pNode;
        }
        else
        {
            pNode->pFront->pNext = pNode->pNext;
            pNode->pNext->pFront = pNode->pFront;
            delete pNode;
        }
    }
private:
    Node* pHead;
    Node* pTail;
    int mSize;
};

#endif // LINK

