int *p;

int a[5] = {1,3,4,5};

p = a;//不加&

a[i] === *(p+i) ==== p[i] ==== *(a+i) //值相等

a+i === p+i === &p[i] === &a[i] //地址相同

p = p + i;
a = a + i;// 错误，因为a是常量，上面的p是变量，赋值出现错误


int main(int argc, const char *argv[])
{
	//值相等 *(p+i) === a[i] ==== p[i] === *(a+i)
	//地址相同 p+i === &a[i] === &p[i] === a+i
	int a[5] = {1,2,3,4,5};
	int *p = a;
	printf("%d %d %d %d %p %p %p %p\n",*(p+0),*(a+0),a[0],p[0],p+0,a+0,&a[0],&p[0]);
	printf("%d %d %d %d %p %p %p %p\n",*(p+1),*(a+1),a[1],p[1],p+1,a+1,&a[1],&p[1]);
	return 0;
}

1.指针运算 

	1.1 指针的算术运算

		+   -   ++  --  *(取内容)
		int a[5] = {1,2,3,4,5};
		int *p = a;		//假设p = 0x00001100;
		p + 1;			//p + 1  ?  0x00001104;
		p + 2;   		//p + 2  ?  0x00001108
		p++; // p = p + 1
		a++; //??错误，因为a地址常量

		char a[6] = "hello";
		char *p = a;		//假设p = 0x00001100;
		p + 1;			    //p + 1  ?    0x00001101;

		int a[5];
		int b[5];
		int *p = a;
		int *q = b;

		p + q ?     //错，因为两个地址相加毫无意义
		
		
		#include <stdio.h>
		
		int main(int argc, const char *argv[])
		{
			double a[5] = {1,2,3,4,100};
			double *p = a;
			double *q = &a[4];
			int n = q - p;//指针变量相减得到间隔的数据数,而不是地址量的差值
			printf("%p %p\n",p,q);//p和q地址量相差32   32/8 --->4
			printf("n is %d\n",n); //打印n == 4
			return 0;
		}

		int a[5];

		int *p = &a[0];
		int *q = &a[3];

	1.2	指针的关系运算

		指针  ==   !=   >     <
		
		（1）两指针之间的关系运算表示它们指向的地址位置之间的关系。指向地址大的指针大于指向地址小的指针。
		（2）具有不同数据类型的指针之间的关系运算没有意义，指向不同数据区域的数据的两指针之间，关系运算也没有意义。
		（3）指针与一般整数变量之间的关系运算没有意义。但可以和零进行等于或不等于的关系运算，判断指针是否为空
		
		###代码演示 指针是否指向同一个地址
		
		#include <stdio.h>
		int main()
		{
			int a = 10;
			int b = 20;
			int *p = &a;
			int *q = &b;
			if(p == q)
			{
				printf("指向了同一个地址\n");
			}
			//无打印输出，因为p和q保存的地址不同，p指向变量a，q指向变量b，地址不同无打印
		}   
		
		#include <stdio.h>
		void reverse(int *p, int n)
		{
			int temp;
			int *q = p+n-1;//q指向数组中的最后一个元素
			while(p < q)
			{
				temp = *p;
				*p = *q;
				*q = temp;
				p++;
				q--;
			}
		}
		void printArray(int *p,int n)
			{
				int i;
				for(i = 0; i < n; i++)
				{
					printf("%d ",p[i]);
				}
				printf("\n");
			}
		
		int main()
		{
			int a[5] = {1,2,3,4,5};
			printArray(a,5);
			reverse(a,5);
			printArray(a,5);
			return 0;
		}
		
		##练习1 写一个函数，计算数组中成绩小于60的人数,要求数组定义在main函数中
		int a[] = {90, 80, 70, 55, 63, 53, 28}; 
		
			#include <stdio.h>
			int low_60(int *p, int n)
			{
				int i, c = 0; //c用来计数
				for(i = 0; i < n; i++)
				{
					if(*(p + i) < 60)
					{
						c++;
					}
				}
				return c;
			}
			int main()
			{
				int a[] = {90, 80, 70, 50);
				int x  = low_60(a,sizeof(a)/sizeof(a[0]));
				printf("low 60 is %d\n", x);
			}		
			
		##练习2 写一个函数，查找一个字符串中某个字母出现的次数
		#include <stdio.h>

	int countLetter(char *s, char letter)//s代表被查找的字符串，letter 被查找字符出现的次数
	{
		//方法一
		/*
		int count = 0;
		int i = 0;
		while(s[i] != '\0')
		{
			if(s[i] == letter)
			{
				count++;
			}
			i++;
		}
		*/
		//方法二
		int count = 0;
		while(*s != '\0')
		{
			if(*s == letter)
			{
				count++;
			}
			s++;//指针向后移动，指向下一个元素
		}
		return count;
	}


	int main(int argc, const char *argv[])
	{
		char a[] = "hello world";
		int count = countLetter(a,'l');
		printf("count is %d\n",count);
		return 0;
	}
			
	##练习3 编写一个函数，完成下面功能，能将Hello World!   转换成Lipps Asvph!
		
			
	1.3 空指针

		int a = 0;

		int *p;
		*p = 10;  	//如果p未初始化就直接进行*p操作，会出下面提示
		////Segmentation fault (core dumped)

		此时p 是野指针(未指向一个有效地址的指针， 非常不好)

		如果p定义时，不知道该指向哪，那么p初始化为NULL
		
		#include <stdio.h>

		// *(p+i) === a[i] ==== p[i] ==== *(a+i)
		// p+i === &a[i] ==== &p[i] ==== a+i


		int main(int argc, const char *argv[])
		{
			int *p = NULL;//此时的指针变量p解释野指针
			if(p == NULL)//判断指针是否为空
			{
				printf("p is NULL\n");
			}
			return 0;
		}

		#define NULL 0

	1.4 值传递和地址传递（*****）

		////如果想实现用一个函数，交换两个数
		//写一个swap, 交换两个数
		#include <stdio.h>
		void swap(int a, int b)		//a , b是形参
		{
			int t;
			t = a;
			a = b;
			b = t;
		}

		int main()
		{
			int x = 5, y = 9;
			swap(x, y);		//x y 是实参，在调用时，会用实参值初始化形参
			printf("x is %d, y is %d\n", x, y);	//x is 9, y is 5
		}

		/////那么上面的问题就可以采用地址传递， 地址传递可以改变实参的值
		#include <stdio.h>
		void swap(int *a, int *b)		//a , b是形参
		{
			int t;
			t = *a;
			*a = *b;
			*b = t;
		}

		int main()
		{
			int x = 5, y = 9;
			swap(&x, &y);		
			printf("x is %d, y is %d\n", x, y);	//x is 9, y is 5
		}
		
		函数参数传递，有两种方式
		
		///值传递，通常改变不了参数的值, 就是把实参的值传递给形参，然后形参运算，跟实参没有任何关系

		///地址传递，可以改变参数的值, 参数是一个指针变量

		##练习4
		
			编写函数fun：从n个学生的成绩中统计出低于平均分的学生人数，由函数返回值返回，
			平均分存放在形参*ptr_aver所指的存储单元中(即平均分由参数返回),低于平均分的人数
			由返回值返回。
			函数原型为：int fun( float *s, int n, float *ptr_aver );
			例如：若输入8名学生的成绩如下
	
			80.5  60  72  90.5  98  51.5  88  64
			
			则低于平均分的学生人数为：4(平均分:75.5625)。
			
			#include <stdio.h>

			int fun( float *s, int n, float *ptr_aver )
			{
				//1.输入ｎ个学生的成绩
				int count = 0;//计数器统计人数
				float sum = 0;
				int i;
				for(i = 0; i < n; i++)
				{
					scanf("%f",s+i);
					sum += s[i];
				//	scanf("%f",&s[i]);
				}
				//2.求平均值
				*ptr_aver = sum / n;//得到了平均值
				//3.统计低于平均值的人数
				for(i = 0; i < n; i++)
				{
					if(*(s+i) < *ptr_aver)
					{
						count++;
					}
				}
				return count;
			}

			int main(int argc, const char *argv[])
			{
				float a[100];//用来保存学生成绩
				float avg;//用来保存平均值
				int count;
				count = fun(a,8,&avg);
				printf("人数:%d\n avg is %.2f\n",count,avg);
				return 0;
			}

////结论：

	一个函数要想给调用者传递值有两种方式
	
	1. 返回值 
	
	2. 参数地址传递
		
	1.5 指针变量所占内存空间的大小		
			
		int a;   //sizeof(a)   ?  4
		char a;   //sizeof(a)   ?  1
		double a;   //sizeof(a)   ?  8
		short a;   //sizeof(a)   ?  2
		float a;   //sizeof(a)   ?  4

		///sizeof （能求出某个变量占用的内存空间大小）
		int *p;		
		char *q;	    

		sizeof(p)    ? 4  p的类型是什么? int *(整型指针)        
		sizeof(*p)   ? 4   *p的类型是什么? int (整型)      
		sizeof(q)    ? 4  q的类型是什么? char *(字符指针)      
		sizeof(*q)   ? 1   *q的类型是什么？char (字符) 

		//结论: 无论什么指针，都占用4字节
		
		int main(int argc, const char *argv[])
		{
			int *p;
			char *q;
			double *z;
			printf("sizeof(p) is %d\n",sizeof(p)); //4
			printf("sizeof(q) is %d\n",sizeof(q)); //4
			printf("sizeof(z) is %d\n",sizeof(z)); //4
			return 0;
		}
		
		
	1.6  字符串比较函数
	
		//字符串处理函数
		strcmp   //字符串比较

		#include <stdio.h>
		#include <string.h>
		int main()
		{
			int x;
			x = strcmp("abc", "abc");	//字符串相等 返回值是0
			printf("x is %d\n", x);
			x = strcmp("abcd", "abc");	//字符串 "abcd" > "abc" 返回值是1
			printf("x is %d\n", x);
			x = strcmp("abcd", "bc");	//字符串 "abcd" < "bc"  返回值是-1
			printf("x is %d\n", x);
		}
		
		int num = atoi("2345");
		
		##练习5编写一个函数，比较两个字符串，
		
		 # 字符串1 > 字符串2 返回1，字符串1 == 字符串2，返回0， 字符串1 < 字符串2，返回-1
		 # 写函数测试，不允许用strcmp函数
		int my_strcmp(char *s1,char *s2)
		{
			
		}
		
		  "abc"  < "bbc"
		  "abc"  < "b"
		  "bc"  > "abc"
		  "abc"  = "abc"

			

2. 变量（全局变量、局部变量）

	2.1变量定义
	
		int a;		//int 变量类型， a 变量名
		float b;	//float 变量类型  b 变量名

	2.2变量定义规范
	
		变量名可以由英文字母，数字，和_组成，不可以以数字开头
		sum1   //ok
		sum    //ok

		1sum   //no
		sum?   //no

		变量如果由多个单词组成 可以采用两个方式
		linux风格
			student_name
		windows风格
			StudentName

	2.3局部变量(定义在函数中的变量属于局部变量)
	
		#include <stdio.h>
		void fun()
		{
			int x = 100;
		}
		int main()
		{
			printf("x is %d\n", x);
		}
	
		hello.c:8:22: error: ‘x’ undeclared 
		hello.c的第8行有错误，x未定义

		#include <stdio.h>
		void fun()	//函数定义
		{
			int x;
			printf("fun x is %d\n", x);
		}
		int main()
		{
			int x = 200;
			printf("main x is %d\n", x);
			fun();	//函数调用
		}

		局部变量特点
		
		1) 两个不同函数中可以有同名变量
		2) 局部变量只在所定义的函数中有效
		3) 参数和局部变量也不能同名
		4) 局部变量如果没赋初值，那么值为 随机值
		

	2.4全局变量(定义在函数外面的变量是全局变量，在程序的任何位置都可以访问)
	
		#include <stdio.h>
		int x;
		void fun()
		{
			int x;
			x = 100;
			printf("fun x is %d\n", x);
		}
		int main()
		{
			fun();
			printf("main x is %d\n", x);
		}

		1) 全局变量在程序的任何位置都可以使用

		2) 只要有一个地方改了全局变量，其他地方也改

		3) 全局变量如果未初始化 默认值为        0

		4) 全局变量不能同名， 但全局变量可以和局部变量同名，优先使用局部变量

	2.5 函数声明（作用是告诉编译器，此函数是长什么样的）
		
		函数的定义尽量放在函数调用的前面，函数先定义再调用

		如果函数定义在函数调用的下面，函数就要先声明一下

		函数的声明：
		#include <stdio.h>
		int max(int a, int b);		//函数声明，作用是告诉编辑器，函数长什么样
		int main()
		{
			int x = max(3, 5);
		}
		int max(int a, int b)		//这样做不好，
		{
			return a > b ? a : b;
		}

		1) void fun();    ///要注意：有" ; "

		2) 函数的声明不需要函数体

		3) 函数的声明一定与定义一致

		4) 函数的声明尽量放在头文件中


3.作业

	8只猴子围坐成一个圈，
	按顺时针方向从1到8编号。
	然后从1号猴子开始
	沿顺时针方向从1开始报数，
	报到m的猴子出局，
	再从刚出局猴子的下一个位置重新开始报数，
	如此重复，直至剩下一个猴子，
	它就是大王。
	设计并编写程序，实现如下功能：
	（1）	要求由用户输入报的数m。
	（2）	给出当选猴王的编号。
