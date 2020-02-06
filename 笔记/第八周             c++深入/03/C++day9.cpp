复习：
函数模板 template<typename T, typename Q> 函数声明
函数名<int, float>()
类模板	template<typename T, typename Q> 类声明
类名<int, string> 对象名				new 类名<int, string>()

explicit：修饰构造函数，禁止隐式转换
隐式转换：当构造函数可以只传递一个参数的时候，可以通过参数初始化对象

-----------------------------------------------------------------------------------------------

在写C++程序的时候会发现STL是一个不错的东西，减少了代码量，使代码的复用率大大提高，减轻了程序猿的负担。
还有一个就是容器，你会发现要是自己写一个链表、队列，或者是数组的时候，既要花时间还要操心怎么去维护，
里面的指针啊，内存够不够用啊，长度问题，有没有可能溢出啊等等一系列的问题等着我们去解决，还是比较头疼的。
所以容器的出现解决了这一个问题，它将这些数据结构都封装成了一个类，只需要加上头文件，我们就可以轻松的应用，
不用那么复杂，就连指针也被封装成了迭代器，用起来更方便，更人性化，方便了我们的编程，对于程序员来说还是一大福音！！

 C++中的容器类包括“顺序存储结构”和“关联存储结构”，
 前者包括vector，list，deque等；
 后者包括set，map，multiset，multimap等。
 若需要存储的元素数在编译器间就可以确定，可以使用数组来存储，否则，就需要用到容器类了。

***********************************************************************************************
1.vector
    连续存储结构，每个元素在内存上是连续的；支持高效的随机访问和在尾端插入/删除操作，但其他位置的插入/删除操作效率低下；
	相当于一个数组，但是与数组的区别为：内存空间的扩展。vector支持不指定vector大小的存储，但是数组的扩展需要程序员自己写；[2]
2.deque
    连续存储结构，即其每个元素在内存上也是连续的，类似于vector，不同之处在于，deque提供了两级数组结构，
	第一级完全类似于vector，代表实际容器；另一级维护容器的首位地址。这样，deque除了具有vector的所有功能外，还支持高效的首/尾端插入/删除操作。
    deque   双端队列 
    deque是在功能上合并了vector和list。
    优点： (1) 随机访问方便，即支持[ ]操作符
           (2) 在内部方便的进行插入和删除操作
           (3) 可在两端进行push、pop
    缺点：占用内存多	
3.list
    非连续存储结构，具有双链表结构，每个元素维护一对前向和后向指针，因此支持前向/后向遍历。支持高效的随机插入/删除操作，
	但随机访问效率低下，且由于需要额外维护指针，开销也比较大。
	可以不分配必须的内存大小方便的进行添加和删除操作。使用的是非连续的内存空间进行存储。
   优点： (1) 不使用连续内存完成动态操作。
               (2) 在内部方便的进行插入和删除操作
               (3) 可在两端进行push、pop
   缺点： (1) 不能进行内部的随机访问，即不支持[ ]操作符和vector.at()
               (2) 相对于verctor占用内存多
   使用区别：
             （1）如果你需要高效的随即存取，而不在乎插入和删除的效率，使用vector
             （2）如果你需要大量的插入和删除，而不关心随机存取，则应使用list
             （3）如果你需要随机存取，而且关心两端数据的插入和删除，则应使用deque


【问题：vector VS. list VS. deque】
    a、若需要随机访问操作，则选择vector；
    b、若已经知道需要存储元素的数目，则选择vector；
    c、若需要随机插入/删除（不仅仅在两端），则选择list
    d、只有需要在首端进行插入/删除操作的时候，还要兼顾随机访问效率，才选择deque，否则都选择vector。
    e、若既需要随机插入/删除，又需要随机访问，则需要在vector与list间做个折中-deque。
    f、当要存储的是大型负责类对象时，list要优于vector；当然这时候也可以用vector来存储指向对象的指针，
       同样会取得较高的效率，但是指针的维护非常容易出错，因此不推荐使用。

【问题一：list和vector的区别】

（1）vector为存储的对象分配一块连续的地址空间，随机访问效率很高。但是插入和删除需要移动大量的数据，效率较低。尤其当vector中存储
的对象较大，或者构造函数复杂，则在对现有的元素进行拷贝的时候会执行拷贝构造函数。
（2）list中的对象是离散的，随机访问需要遍历整个链表，访问效率比vector低。但是在list中插入元素，尤其在首尾插入，效率很高，只需要改变元素的指针。

（3）vector是单向的，而list是双向的；

（4）向量中的iterator在使用后就释放了，但是链表list不同，它的迭代器在使用后还可以继续用；链表特有的；

【问题二 deque和vector的区别】

（1）两端都能够快速插入和删除元素。vector只能在尾端进行。

（2）deque的元素存取和迭代器操作会稍微慢一些。因为deque的内部结构会多一个间接过程。

（3）迭代器是特殊的智能指针，而不是一般指针。它需要在不同的区块之间跳转。

（4）因为deque使用不止一块内存（而vector必须使用一块连续内存），所以deque的max_size()可能更大。

（5）不支持对容量和内存分配时机的控制。

注意：在除了首尾两端的其他地方插入和删除元素，都将会导致指向deque元素的任何pointers、references、iterators失效。不过，deque的内存重分配优于vector。因为其内部结构显示不需要复制所有元素。

6、deque的内存区块不再被使用时，会被释放。deque的内存大小是可缩减的。不过，是不是这么做以及怎么做由实作版本定义。


【问题五：用vector存储自定义类对象时，自定义类对象须满足】
    a、有可供调用的无参构造函数（默认的或自定义的）；

    b、有可用的拷贝赋值函数（默认的或自定义的）

【问题六：迭代器iterator】

     a、vector与deque的迭代器支持算术运算，list的迭代器只能进行++/--操作，不支持普通的算术运算。

     b .向量中的iterator在使用后就释放了，但是链表list不同，它的迭代器在使用后还可以继续用；链表特有的；
	

*****************************************************************************************

		/***********************

				新课

		*********************/
	
		
		
一、STL：标准模板库  standard  template  library
容器：顺序(线性)容器   关联容器 键值对key-value
所有的容器都是自增长

1、顺序容器：使用方式基本一致，实现原理不一样，根据对数据的操作选择适合的容器
vector 支持快速随机访问  数组原理 推荐  O（1）
list	支持快速插入/删除  链表原理		O（N）
deque	双端队列

1.常用操作
示例1：常用操作:插入数据 通过方法push_back（）
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
        v.push_back(rand()%100);
    }
    //重载了[]运算符，支持通过[]访问对应位置的元素
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}

示例2：查找元素  重载了[]运算符，支持通过[]访问对应位置的元素,并修改值

	int main()
{
    srand(time(0));
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(rand()%100);
    }
    
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
	cout<<endl;
	
	//修改第0个位置的值为521，运算符重载返回的值的引用
	
    v[0] = 521;
	
	//重新输出所有值，查看修改情况
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}

练习：将100以内能整除2的值保存入容器中，并其中能整除3的值更改为0，输出最后的结果

 for(int i = 0 ; i < 100;i++ )
   {
       if(i%2 == 0)
       v.push_back(i);
   }
   for(int i = 0 ; i <v.size();i++ )
   {
       if(v[i]%3 == 0)
       v[i] = 0;
   }
   
   

示例3：迭代器遍历

C++中的迭代器是对指针的封装，迭代器提供特定的函数让调用者对指针进行
特定的安全的操作

1）如何调用迭代器 vector<int>::iterator iter  i
2）第一个元素的位置指针通过函数v.begin()返回 i=0;
3）遍历结束的条件，最后一个无效元素的位置 通过v.end()返回  i<10
4）*iter；通过*，来访问迭代器指向的元素

注意：begin是容器的头元素 ，end并不是尾元素，而是无效的元素表示容器结束

示例：
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
   
     
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;//*来访问迭代器指向的元素
    }
    
    return 0;
}

练习：将100以内能整除2的数都更改为0，输出最后的结果



//补充：
v.insert();  //采用头插法
(1)   (v.begin，20)  
(2)  （v.begin,v.begin+3,v.begin+5）  //意思就是这个区间的东西 插入到v.begin之前
//参数1：//待插入位置
//参数二：//可以是待插入元素  也可以是待插入区间


//迭代器遍历删除不累加

//查找迭代器删除找完后需要判断
1）加入头文件 #include <algorithm>
2）查找方法为：vector<int>::iterator iter = find(v.begin(), v.end(), 3);
3）注意：find方法只能删除找到的第一个元素

示例3.1：迭代器遍历删除

示例：删除方法 v.erase(iter);

注意：迭代器所指向的对象被删除后，迭代器就无效了，erase函数会返回一个新的迭代器，
		指向删除元素的下一个元素

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    
    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    
    //迭代器所指向的对象被删除后，迭代器就无效了，erase函数会返回一个新的迭代器，指向删除元素的下一个元素
    for(vector<int>::iterator iter = v.begin();iter != v.end();)
    {
        if(*iter%2 == 0)
            iter = v.erase(iter);//使用新的迭代器继续遍历  
		                         //erase返回值是指向删除节点的下一个节点的迭代器
        else 
            iter++;
    }
    
    //begin是容器的头元素 ，end并不是尾元素，而是无效的元素表示容器结束
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;//*来访问迭代器指向的元素
    }
    
    return 0;
}

//练习：将100以内能整除2的值保存入容器中，并其中能整除3的值删除，输出最后的结果，用迭代器遍历


示例3.2：查找迭代器删除

1）加入头文件 #include <algorithm>
2）查找方法为：vector<int>::iterator iter = find(v.begin(), v.end(), 3);
3）注意：find方法只能删除找到的第一个元素


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
    
    vector<int>::iterator iter = find(v.begin(), v.end(), 3);
    
    v.erase(iter);
    
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;
    }
    
    return 0;
}

思考：如果容器中没有要查找的元素呢？

加入判断：
int main()
{
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    
    vector<int>::iterator iter = find(v.begin(), v.end(), 3);
    
	加入判断：说明没找到结尾之前，找到了匹配的元素，
				如果找到了end位置，说明容器中没有匹配的元素
	if(iter != v.end())
	{
		v.erase(iter);
	}
       
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;
    }
    
    return 0;
}

3.3：查找迭代器删除自定义类型

示例：
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Person
{
 public:
    int age;
    string name;
    Person(int age,string name):age(age),name(name)
    {

    }
    bool operator==(const Person& o)
    {
        if(this->age == o.age && this->name == o.name)
            return true;
        else
            return false;
    }
    void show()
    {
        cout<<age<<"  "<<name<<endl;
    }

};

int main()
{
    vector<Person> v;
    v.push_back(Person(12,"aaa"));
    v.push_back(Person(13,"bbb"));
    v.push_back(Person(14,"ccc"));
    v.push_back(Person(15,"ddd"));

    vector<Person>::iterator iter = find(v.begin(),v.end(),Person(12,"aaa"));

    if(iter!= v.end())
        v.erase(iter);


    for(vector<Person>::iterator iter = v.begin();iter != v.end();iter++)
        iter->show();
    return 0;
}

练习：定义结构体Node，成员变量 int num;char name;
					2)构造函数，给变量初始化
					3）成员函数 show（）；输出num和name
					
		定义容器vector为Node类型，循环插入数据，num为循环变量i的值，
		name为字母a~z
		查找数据中有没有Node(1,'e')，有就删除
		迭代器遍历，输出所有数据
		
		
		
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct teacher
{
    int age;
    char name;

    teacher(int age,char name):age(age),name(name)
    {


    }
    void show()
    {
        cout<<age<<"  ";
        cout<<name<<endl;
    }
    bool operator ==(const teacher& other)
    {
        if(this->age == other.age && this->name == other.name)
            return true;
        return false;
    }

};

int main()
{
    vector<teacher> v;
    for(       int i =0;i<26;i++  )
    {
        v.push_back(teacher(i,'a'+i));
    }

    for(   vector<teacher>::iterator iter = v.begin();iter!=v.end();iter++  )
    {
       iter->show();
    }
    cout<<endl;
     v.clear();
  //    vector<teacher>::iterator iter = find(v.begin(),v.end(),teacher(1,'b'));
   //   if(iter!=v.end())


      for(   vector<teacher>::iterator iter = v.begin();iter!=v.end();iter++  )
      {
         iter->show();
      }
}






2.其他操作
2.1.迭代器操作：(适用于所有的标准库容器) 
*iter 返回迭代器所指向的引用 
2.2.begin()和end()成员（支持所有容器） 
c.begin() 、c.end() 返回一个迭代器，指向第一个和最后一个的下一个成员 
2.3.在容器中添加元素 
c.push_back(t) 支持所有容器 
c.push_front(t) 只支持list和deque容器 
c.insert(p,t)、c.insert(p,n,t)、c.insert(p,b,e) 支持所有容器
2.4.容器大小的操作（支持所有容器） 
c.size() 返回c中的元素个数。返回类型为c::size_type 
c.max_size() 返回c中所能容纳的最大个数，类型为：c::size_type 
c.empty() 
2.5.访问元素 
c.back() 返回容器c中的最后一个元素的引用 
c.front() 返回容器c中的第一个元素的以引用 
c[n] 下标操作 只适用于vector和deque 只能操作已存在的元素 
c.at() 下标操作 只适用于vector和deque 只能操作已存在的元素
2.6.删除操作 
c.erase(p) 删除迭代器p指向的元素 
c.erase(b,e) 
c.clear() 删除容器c中的所有元素 
c.back();获取最后一个元素
c.pop_back() 删除容器c中的最后一个元素 
c.pop_front() 删除容器c中的第一个元素，只适用于list和deque




2、关联容器
1. pair<T1, T2>  pair也是一种模板类型。键(key)值(value)对
	它的数据成员是公有的，分别命名为first和second
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


map容器map<key, value>  头文件：#include <map>
	
2. map<key, value> 通过关联容器保存数据，以键值对key-value形式存放数据  红黑树

2.1 插入和查询操作

示例1：插入数据
注意：插入数据  不允许键重复，如果键重复无法插入	 


2.2 迭代器遍历
示例：

#include <iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    pair<string,int> p("11",12);
    pair<string,int> p1("22",123);
    pair<string,int> p2("33",122);

  //  cout<<p.first<<"         "<<p.second<<endl;

    map<string,int> m;
    m.insert(p);
    m.insert(p1);
    m.insert(p2);
    m.insert(pair<string,int>("kk99",25));

    for(map<string,int>::iterator iter = m.begin();iter!=m.end();iter++)
    {
        cout<<iter->first<<"  "<<iter->second<<endl;
    }
}


2.3 查找 可以通过[]进行查找
1.示例：
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	//关联容器的形式
	m.insert(pair<string, int>("小明",18));
	//通过[]形式
	m["小强"] = 20;

}
2.示例：count("小明")函数，count查找该key出现的次数，返回值可能是0或者1 
0表示没有该key，1表示有而且数量就是1

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

	map<string, int> m;
	//关联容器的形式
	m.insert(pair<string, int>("小明",18));
	cout<<m.count("小明")<<endl;
	cout<<m.count("小红")<<endl;
}

注意：是否会新建对象：     
			m["aaa"] = 6;//会
			cout<< m["bbb"]<<endl;//会
			cout<< m.count("bbb")<<endl;// 0  1

3.示例：find（）函数进行查找，find返回该key的迭代器对象

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	
	map<string, int> m;
	//关联容器的形式
	m.insert(pair<string, int>("小明",18));
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
	

2.4 删除  从m中删除key为k的元素   m.erase(k)   



示例2：删除  从m中删除迭代器p指定的元素  m.erase(p)  

#include <iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    pair<int,string>p1(2,"pp");
    pair<int,string>p2(5,"tt");

    map<int,string> m;
    m.insert(p1);
    m.insert(p2);

    m[9] = "www";

        for(map<int,string>::iterator iter = m.begin();iter!=m.end();iter++)
        {
            cout<<iter->first<<"  "<<iter->second<<endl;
        }
        cout<<"********************************"<<endl;

        //key delete
        m.erase(9);

        //iterator delete
        map<int,string>::iterator iter =m.find(2);
        if(iter!=m.end())
            m.erase(iter);

        for(map<int,string>::iterator iter = m.begin();iter!=m.end();iter++)
        {
            cout<<iter->first<<"  "<<iter->second<<endl;
        }

//    pair<string,int> p("11",12);
//    pair<string,int> p1("22",123);
//    pair<string,int> p2("33",122);

//    map<string,int> m;
//    m.insert(p);
//    m.insert(p1);
//    m.insert(p2);
//    m.insert(pair<string,int>("kk99",25));
//    m["pp"] = 20;
//    cout<<m["99"]<<endl;

//    for(map<string,int>::iterator iter = m.begin();iter!=m.end();iter++)
//    {
//        cout<<iter->first<<"  "<<iter->second<<endl;
//    }
}



********************综合练习：********************************
 #include <iostream>
#include<vector>
#include<algorithm>

#include<map>

using namespace std;

int main()
{
   //关联容器 pair
    pair<int,int> p(1,12);
    //键key:first  值value: second
  //  cout<<p.first<<"  "<<p.second<<endl;

    //定义map容器

    //自带排序功能：键 大小顺序 键值的类型 string：按照第一个不相等的字符大小  int 由大到小
    //不能插入键值重复的数据
    map<string,int> m;//vector<int>
    //插入数据 insert
    m.insert(pair<string,int>("小明",1));
    m.insert(pair<string,int>("b",2));
    m.insert(pair<string,int>("daisy",3));
    m.insert(pair<string,int>("tom",4));
    m.insert(pair<string,int>("jack",4));

    //查找 赋值
    m["tom"] = 20;


  //如果你要查找的键值不存在 那么就会新建一个数据 键值：就是你查找的键值
    m["rose"] = 18;

    //查询在容器中存在几个这个数据 count:返回值 0/1 0:不存在 1：存在
    cout<<m.count("tom111")<<endl;

    //输出键值tom111 对应的value是多少
    cout<<m["tom111"]<<endl;

    //find()函数查找 find返回该key的迭代器对象 注意：是map容器中的成员函数
    map<string, int>::iterator iter = m.find("小红");
        if(iter != m.end())
        {
            // iter->first :键值   iter->second： value的值
            cout<<iter->first<<" "<<iter->second<<endl;
        }
        else
        {
            cout<<"查无此项"<<endl;
        }


        //删除 按照key的方式
         m.erase("rose");

        //删除 按照迭代器删除
      map<string,int>::iterator iter1 = m.find("tom");

      if(iter1 != m.end())
             m.erase(iter1);

     //遍历
      for(map<string,int>::iterator iter = m.begin();iter != m.end();iter++)
      {
          cout<<iter->first<<"  "<<iter->second<<endl;
      }


    return 0;
}

**********************************************************************8

2.5 自定义key类型  需要重载运算符 <

示例：
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
    m.insert(pair<Person, int>("jack", 18));//m.insert(pair<Person, int>(Person("jack"), 18));
    m.insert(pair<Person, int>("rose", 1));
    m.insert(pair<Person, int>("tom", 2));
    m.insert(pair<Person, int>("jerry", 3));
    
    for(map<Person, int>::iterator iter = m.begin();iter != m.end();iter++)
    {
        cout<<iter->first.getName()<<" "<<iter->second<<endl;
    }
    
    return 0;
}



综合练习：21点
1、使用单例模式管理扑克属性数据 PokerManager
	1.私有成员vector,保存花色 
	2.私有成员vector保存点数   vector<string> point;
	3.私有成员map保存分值 map<string,int> score;
	4.定义相应的get函数
	5.构造函数中对成员赋值
	
2、定义扑克类Poker 私有属性 花色（红桃等）、点数（A 2 3 J Q等）、分值（21点每个点数的分值）
	1.构造函数传入花色和点数（花色：大王 小王）
	2.构造函数中根据点数自动分配分值属性，可将14种点数以键（点数）值（分值）对形式存放到map中 map[point]  score
	
3、定义裁判类Judge
	1.私有成员容器适配器，存放顺序的54张牌
	2.洗牌，随机选取两个位置，交换对应位置的牌，void shuffle(vector<pocker>& pockersVec);
	3.公有函数deal()发牌，每调用一次从容器最后一个位置发出一张牌 pocker deal()； back(); pop_back();
		
4、定义玩家类Player
	1.私有成员vector容器存放手中的牌
	2.私有成员name
	3.公有函数计算当前手牌总分值 getscore()
	4.公有函数显示手中的牌 show() 
	5.公有函数addPoker()传入一个Poker对象存入vector容器中
	
5、主逻辑类Logic
	1.私有成员Judge对象
	2.私有成员vector存放Player对象
	3.构造函数中向私有成员vector添加Player对象
	
	
	4.公有函数run()负责游戏主要逻辑 while()
	4.1 询问每个玩家是否要牌，放弃要牌则失去以后询问机会
	4.2 Judeg对象deal()一个牌给要牌的玩家addPoker()
	4.3 校验要牌玩家的分值是否超过21点，超过则提前出局，失去以后询问机会
	4.4 显示所有玩家手牌
	4.5	如果没有可询问对象，则停止游戏
	4.6 循环回4.1

