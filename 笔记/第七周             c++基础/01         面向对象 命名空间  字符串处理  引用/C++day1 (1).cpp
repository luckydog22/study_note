一、
1.软件安装
	cd ~/Desktop
	sudo dpkg -i *.deb
	
	c++ 
	
	C plus plus --- cpp
	
	《C++ primer》 第四版  第五版 C++11  《C程序设计语言》丹尼斯.理查
	
2.C++的语言特点及优势

C++实现了面向对象程序设计。在高级语言当中，处理运行速度是最快的，大部分的游戏软件，系统都是由C++来编写的。
C++语言非常灵活，功能非常强大。如果说C语言的优点是指针，那么C++的优点就是性能和类层次结构的设计。
C++非常严谨、精确和数理化，标准定义很细致。
C++语言的语法思路层次分明、相呼应;语法结构是显式的、明确的。

3. 面向过程就是分析出解决问题所需要的步骤，然后用函数把这些步骤一步一步实现，使用的时候一个一个依次调用就可以了。 

   面向对象是把构成问题事务分解成各个对象，建立对象的目的不是为了完成一个步骤，而是为了描叙某个事物在整个解决问题的步骤中的行为。

例如五子棋，
面向过程的设计思路：
①　开始游戏
②　黑子先走
③　绘制画面
④　判断输赢
⑤　轮到白子
⑥　绘制画面
⑦　判断输赢
⑧　返回步骤2
⑨　输出最后结果

面向对象的设计思路：整个五子棋可以分为 
①　玩家系统，黑白双方，这两方的行为是一模一样的
②　棋盘系统，负责绘制画面
③　规则系统，负责判定诸如犯规、输赢等。

第一类对象（玩家对象）负责接受用户输入，
 并告知第二类对象（棋盘对象）棋子布局的变化，棋盘对象接收到了棋子的变化就要负责在屏幕上面显示出这种变化，
 同时利用第三类对象（规则系统）来对棋局进行判定。
	
2、学习方法
1） 多复习
2） 练习
例子
练习
作业

	
3.c++与c区别

	c++ 面向对象  以对象为目标
	c 面向过程
	c++兼容c  高于c	
	
4.c++编译器 linux环境
1.编译器 g++  g++ 源程序文件
2.编辑器 vi 
3.源文件 .cpp 
4.头文件 .h
标准库头文件 .h省略 #include<iostream>
如果要使用c中标准库头文件 #include<stdio.h>  c++中变为#include<cstdio>


二、
1.第一个c++程序

示例1：vi demo.cpp  输出流

#include <iostream>
int main()
{
	std::cout<<" hello world !"<<std::endl; 
}

编译:g++ demo.cpp
运行：./a.out		

解释：
#include<iostream>// 输入输出头文件，相当于stdio.h

cout  格式：cout<<数据　
		 
<<   是输出流运算符，向输出流写数据，将数据输出到屏幕上
		
endl   换行符，'\n'

std:: 命名空间，使用标准库命名空间，

:: 作用域限定符   表示使用std名字空间中的cout  endl 

#include <iostream>
int main()
{
	int a = 10;	
	char c = 'q';
	std::cout<<a<<" "<<c<<std::endl;  //printf("%d",a);
}

示例2：输入流

#include <iostream>

int main()
{
	int age;
	cout<<"please input age:"<<endl;
	std::cin>>age;//scanf
	std::cout<<age<<std::endl; //printf("%d",age);

}

解释：
//cin　将输入的变量值放入变量中，

//>>  输入流运算符

练习：输入一个字符 如果是大写 则转为小写 如果是小写则转为大写
#include<iostream>
int main()
{
	std::cout<<"请输入一个字符"<<std::endl;
	char c;
	std::cin>>c;
	if(c >= 'a' && c <='z')
	{
		c-=32;
	}else if(c >= 'A' && c<= 'Z')
	{
		c+=32;
	}
	std::cout<<"c= "<<c<<std::endl;
}



三.命名空间 
	作用：避免同名冲突 ，学名：避免命名空间污染

1.命名空间的表示方法
（1）标准库的全部都放到名字空间std中  使用时 加上using namespace就可以  
 using namespace std;

示例：
#include <iostream>

using namespace std;//当前源文件使用命名空间 std    使用率最高

int main()
{
	char c;
	cin>>c;
	if(c>='a'&&c<='z')
	{
		c -= 32;
	}
	else if(c>='A'&&c<='Z')
	{
		c += 32;
	}
	cout<<c<<endl;
}

//练习：使用命名空间的方式，输入年龄age，输出：“my age is "age;

#include<iostream>       //头文件  声明

using namespace std;     //调用


int main()
{
	fun();
	cout<<"请输入一个age"<<endl;
	int age;
	cin>>age;
	cout<<"my age is"<<age<<endl;

}



（2）命名空间的第二种表示方法    使用率较低

示例：
	#include<iostream>//输入输出头文件
	
	using std::cout; //:: 作用域限定符   表示使用std名字空间中的cout  endl std::
	using std::cin;
	using std::endl;

	int main()
	{
		cout<<"hello world!"<<"my god";//cout 将数据输出到屏幕
		cout<<"come on baby!"<<endl;//endl 表示换行 '\n'

		char name[20];
		cout<<"please input name:";
		cin>>name;
		cout<<"name:"<<name<<endl;
		return 0;//c++中reurn 0 可有可无
	}
	
添加：cin同时拿到多个值：
	
#include<iostream>

using namespace std;

int main()
{
	cout<<"请输入一个age"<<endl;
	int age;
	char f;
	cin>>age>>f;
	cout<<"my age is"<<age<<" "<<f<<endl;


}
		
（3）命名空间的第三种表示方法	  

示例：
	#include<iostream>//输入输出头文件

	int main()
	{
		std::cout<<"hello world!"<<"my god";//cout 将数据输出到屏幕
		std::cout<<"come on baby!"<<std::endl;//endl 表示换行 '\n'

		char name[20];
		std::cout<<"please input name:";
		std::cin>>name;
		std::cout<<"name:"<<name<<std::endl;
		return 0;//c++中reurn 0 可有可无
	}

2.自己写命名空间

1）示例1：自定义命名空间teacher

#include <iostream>

using namespace std;

namespace teacher
{
	char name[20] = "小明";
}

using namespace teacher;

int main()
{
	cout<<"老师是"<<name<<endl;
}

2）示例2：定义命名空间teacher和worker

#include <iostream>

using namespace std;

namespace teacher
{
	char name[] = "dashen";
}

namespace worker
{
	char name[] = "daye";
}

using namespace teacher;
using namespace worker;

int main()
{
	cout<<"老师是"<<name<<endl;//编译错误
	cout<<teacher::name<<" and "<<worker::name<<endl;//正确用法 在名字冲突的情况下仍然要在使用前添加命名空间
}



练习：分别在teacher和worker命名空间中添加函数showName()来输出name

#include<iostream>

using namespace std;

//(1)自定义命名空间teacher
namespace teacher
{
	char name[20] = "小明";
	//添加了函数
	void showName()
	{
	//输出变量（当前命名空间下的变量）
		cout<<name<<endl;
	}
}
//自定义命名空间worker
namespace worker
{
	char name[20] = "daye";
	void showName()
	{
		cout<<name<<endl;
	}
}

using namespace teacher;
using namespace worker;

//(2)当有多个命名空间，并且变量名字相同，发生歧义的时候，要在调用的时候加上作用域

int main()
{
	teacher::showName();
	worker::showName();

}


3）示例3：匿名命名空间

#include <iostream>

using namespace std;

namespace teacher
{
	char name[] = "dashen";
	int age = 19;
}

namespace worker
{
	char name[] = "daye";
	int weight = 180;
}

using namespace teacher;
using namespace worker;

char name[] = "dashu";
char a =80;

int main()
{
	cout<<fun()<<endl;
	cout<<teacher::name<<"age = "<<age<<endl;
	cout<<worker::name<<"weight = "<<weight<<endl;
	cout<<::name<<endl;//C++会将没有命名空间的冲突声明放入匿名命名空间
}

四、字符串处理

1.c++字符串有两种处理方法

  1） c风格 用字符数组存储 用字符指针操作 char s[100]="mygod";   char *p = s;  
      C语言字符串的两个要素：1 '\0'结尾  2 字符类型的地址 //首地址
  
  2） c++标准库中string类

2. string类的操作

2.如何使用string类
(1)需要加头文件#include<string>
(2)需要加std命名空间  using namespace std;
(3)赋值 连接 拷贝。。。

/*
*************示例1：创建string对象
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{    //创建字符串的三种方式
	string s1 = "hello world";//创建对象 
	string s2("hello farsight");  
	string s3(s2);
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
}
/*
***************示例2：转换
*/
(1)c风格转为c++风格 

	string s="abvc";
	
	c++ --->c
（2）将string转换成C风格字符串

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	//使用C风格字符串创建string对象
	string s1 = "hello world";
	
	char buf[100];
	sprintf(buf, "s1 = %s", s1.c_str());
	
	cout<<buf<<endl;
}

注意：//C++不提倡使用C风格字符串，但是在调用一些API函数时会使用到C风格字符串，这时才有必要进行转换char*



////////////////一下操作都是对俩个字符串的处理
/*	
*****************示例3：赋值
*/
string对象赋值可以通赋值符号，直接将值赋予给目标对象
	
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "hello world";
	string s2 = "hello farsight";
	s2 = s;//strcpy
	cout<<s2<<endl;
}
/*
*******************示例4：拼接
*/
string可以通过”+”来与string对象进行拼接，

**注意: string只能拼接string，如果需要拼接其他类型，只能使用sprintf()进行复杂的字符串格式化
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1 = "hello";
	string s2 = " world";
	s1 += s2;//只能string拼接string
	cout<<s1<<endl;
	
	s1 += 1;//无法进行拼接　复杂的字符串格式化只能使用sprintf()
	
	cout<<s1<<endl;
}

string s1 = "aee";
string s2 = "bvv";
cout<<(s1 < s2)<<endl;

/*
*************示例4：比较 == != < > <= >=  真假 
*/

C++依然可以使用0和非0表示真假，C++增加bool类型专门表示真假true false
	真假  非0为真(true)  0是假(false)  

示例1：
#include<iostream>
using namespace std;

int main()
{
	bool b1;
	b1=10;
	cout<<b1<<endl;		//1

	 bool b2;
	 b2=-23;
	 cout<<b2<<endl;	//1

	 bool b3;
	 b3=true;
	cout<<b3<<endl;		//1

	bool b4;
	b4=false;
	cout<<b4<<endl;		//0

	cout<<sizeof(b4)<<endl;		//1个字节
}

示例2：

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1 = "hello world";
	string s2 = "hello world";
	cout<<(s1==s2)<<endl;  //1

	string s3 = "hello farsight";
	cout<<(s3!=s1)<<endl;  //1

	cout<<(s1>s3)<<endl;//1  比较第一个不相等的字符的大小
	
	if(s1 == s2)
	{
		cout<<"="<<endl;
	}else 
	{
		cout<<"!="<<endl;
	}
}
/*
*******************示例7：string类型的成员函数     empty() 和 size()  
*/
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	string s = " ";
	cout<<s.empty()<<endl;//0  不为空
	
	string s2 = "";
	cout<<s2.empty()<<endl;//1  为空

	string s3 = "hello world";//11   \0不算长度  
	cout<<s3.size()<<endl;
}

/*
**************示例8：获取字符对象
*/

C++可以通过字符串对象[下标]来直接获取该位置的字符。

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "hello world";
	for(int i = 0;i < s.size();i++)
	{
		cout<<s[i]<<endl; //通过角标的形式获取
	}
}
/*
******************示例9：cin输入字符串  
*/
cin无法输入空格  如果输入有空格 只拿到空格之前的

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin>>s;
	cout<<s<<endl;
}

/*
******************示例10：getline输入字符串  遇到'\n'结束输入
*/


读入一行的字符串，包括空格。但在c++中无法使用gets()函数，所以需要使用getline()函数

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin,s);
	cout<<s<<endl;
}

练习1：输入一个字符串，将其中的大写字母转换为小写字母
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string input;
	
	getline(cin,input);
	
	for(int i = 0 ; i < input.size();i++)
	{
		if(input[i]>='A'&& input[i]<='Z')
			input[i]+=32;
	}
	cout<<input<<endl;

}

练习2：随机点名  定义名字数组string names[]={}；随机抽取一个数组中的人员 

			随机数头文件 #include <cstdlib>
						 #include<ctime>
						 
						 srand(time(0));初始化随机种子
						 rand()%5; 生成随机数

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	string names[] = {"Rose","Jack","Daisy","hello kitty"};

	//初始化随机种子
	srand(time(0));
	//生成随机数
	int r = rand()%4;

	//输出对应元素
	cout<<names[r]<<endl;


}

练习3：1.定义结构体 结构体成员：string name 
								int age 
		编写函数实现：N个学生信息 宏定义N 
		2.inputStudentInfo()函数，需要将每个学生信息(姓名 学号)输入计算机保存, 
		3.find_stu(string serchName)函数,键盘输入某个学生的姓名 如果该学生存在 则输出其基本信息，
		如果不存在,则输出"not found"
			
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
//定义一个结构体

struct Student  // int
{
	string name;
	int age;

};

void inputStudentInfo(Student *s)
{
	for(int i = 0 ; i < 3; i++)
	{
		cout<<"input name"<<endl;
		getline(cin,s[i].name);
		cout<<"input age"<<endl;
		cin>>s[i].age;
		getchar();
	}

}
int find_stu(Student *s,string searchName)
{
	for(int i = 0 ; i < 3; i++)
	{
		if(s[i].name== searchName)
		{
			return i;
		}
	}
	return -1;
}


int main()
{
	//int a[3]
	Student stu[3];
	inputStudentInfo(stu);
	cout<<"input searchName"<<endl;
	string n;
	getline(cin,n);
	
	int result = find_stu(stu,n);
	
	if(result == -1)
	{
		cout<<"not found"<<endl;

	}else
		cout<<stu[result].name<<"  "<<stu[result].age<<endl;

	return 0;
}


三、引用 reference

引用   变量是一个别名，是c++对c的重要扩充。
也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。
C++之所以增加引用类型， 主要是把它作为函数参数，以扩充函数传递数据的功能。

功能：为一个变量起别名
引用符号：&  使用数据类型加引用符号&，声明引用。

1、基本使用
#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int& b = a;//声明b是a的引用（别名）   &是引用声明符 
	cout<<b<<endl;
	cout<<a<<endl;
	
	cout<<&a<<endl;
	cout<<&b<<endl;
	
	b = 100;
}

注意：必须初始化  引用不能单独存在，也不能改变指向
#include<iostream>
using namespace std;

int main()
{
	int a=100;
	int &ref=a;//1.引用必须初始化
	
	int b=78;
	ref=b;    //2.引用不可以改变方向
	
}

2、引用做为形参类型
#include<iostream>
using namespace std;

void fun(int &m)//int &m=a;  声明m为实参a的引用   //普通函数的参数就是形参 
{
	m = 100;
}

int main()
{
	int a=90;
	fun(a);  //a就是实参
	cout<<a<<endl;
}

练习：编写函数swap实现main中两个整数交换 要求：形参用引用
#include<iostream>

using namespace std;

void swap(int& m,int & n) //声明一个引用　m 是变量ａ的一个引用
{
	int temp;
	temp = m;
	m = n;
	n = temp;
}

int main()
{

	int a = 10,b = 20;
	swap(a,b);
	cout<<a<<"  "<<b<<endl;

#if 0
	//定义一个引用之后,注意：一定要初始化 引用不能单独存在
	//引用不能改变指向
	int& b = a;//生明ｂ是ａ的一个引用
	cout<<b<< "  "<<a<<endl;

	cout<<&a<< "  "<<&b<<endl;
	
	int c = 100;
	b = c;
	cout<<a<<endl;
#endif

}


3.引用做返回值
（1）引用作为返回值，是返回变量本身，而不是一个临时的值。要保证变量的生命周期足够长。


#include<iostream>
using namespace std;

int& max(int& x)
{
	x=90;
	return x;
}
int main()
{
	int a=3;
	max(a) = 8 ;
	cout<<a<<endl;
}

总结：

引用必须初始化。
引用不能单独存在。
引用也不能改变指向。


3、const修饰的引用：常引用 

(1)做形参
#include<iostream>
using namespace std;

void fun(const int &y)   //保护实参不被修改
{
	y=90;//
}
int main()
{
	int a=100;
	fun(a);
}
//普通引用   和   常引用

//能不能通过引用修改值
//修饰的对象

1./int a =10;
   int& b = a;
   b = 100;
   
   
2./int a1 = 8;
   const int & c = a1;
   a1 = 200;
   c=1222;
   


（2）判断下面的几种定义引用对错
int& b;	 
		//
int& b = 10;	//

const int& b = 10;//


示例1：
#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	const int& b = a;
	//b = 20;
	a = 20;
	cout<<a<<endl;
}
示例2：
#include <iostream>

using namespace std;

int main()
{	
	int a = 10;
	//int& c = a + 2;		//错误　普通引用不能使用临时值初始化
	const int& c = a + 2;	//正确　const修饰的引用可以使用临时值初始化
	cout<<c<<endl;
}

总结：

引用必须初始化。
引用不能单独存在。
引用也不能改变指向。
普通引用不能指向常量与临时量。

****引用与指针的区别

	引用很容易与指针混淆，它们之间有三个主要的不同
	
  不存在空引用。引用必须连接到一块合法的内存。
  一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
  引用必须在创建时被初始化。指针可以在任何时间被初始化。


补充：c++增加bool类型
1.表示真或假 非0为真   
2.大小至少1个字节 //官方说法 至少一个字节  虽然没遇到过不是一个字节的时候   面试时候问的话 
#include<iostream>
using namespace std;

int main()
{
	bool gender = true;// 真
	bool sex = false; // 假

	cout<<(gender?"帅哥":"美女")<<endl;
	cout<<(sex?"帅哥":"美女")<<endl;

	cout<<"gender:"<<boolalpha<<gender<<endl;//boolalpha 字母形式输出
	cout<<"sex:"<<sex<<endl;
	
	   bool c = true;						//noboolalpha  字母转换成0 1
       cout << "c = " <<noboolalpha<< c << endl;
}



c++逻辑语句：
for语句
for语句与C语言中的for语句相比，有个明显的改良，则是在第一个表达式中可以直接声明变量
for( int i = 0 ; i<=10 ; i++ ){
cout << i << endl;
}

作业1：打印水仙花数



	