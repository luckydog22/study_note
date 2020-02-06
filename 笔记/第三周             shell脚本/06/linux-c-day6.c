
一、 指针函数、函数指针、 函数指针数组

1. 指针函数。      是函数。 返回值是指针类型的函数。 
char *strcpy(char *dest, const char *src);
void *malloc(size_t size);

2. 函数指针。      是指针。用来指向函数的指针。 
函数名是函数的首地址。 

		函数                                   指针      
void print_array(int *p,int n);           void (*p)(int *,int );     p = print_array ;      
int get_min(int a,int b);                 int (*p)(int a,int b);     p = get_min ;       p(34,88);

// 练习1： 请定义指针，指向对应的函数。 
int get_max(int x,int y);                  int (*p)(int ,int ) = get_max ;                                 
void *malloc(size_t size);                 void *(*p)(size_t );             p = malloc ;
int strcmp(const char *s1,const char *s2); int (*p)(const char *,const char *) = strcmp ;
int rand( void );                          int (*p)( void );    p = rand ;

问题： 以下变量的类型是？
int a;               变量
int a[10];           数组 
int *a;              指针 
int *a[10];          数组。 指针数组。 
int (*a)[10];        指针。 数组指针。 
int (*a[2])[10];     数组。 每个元素都是指针。都是数组指针。 
int *a(int);         函数。 指针函数。 
int (*a)(int);       指针。 函数指针。 int fun(int);
int *(*a)(int);      指针。 函数指针。 int *fun(int);
int (*a[2])(int);    数组。 共两个元素，都是函数指针。 两个： int (*a)(int);     指针指向的函数是： int fun(int);

示例： 
////////////////
#include <stdio.h>
int get_min(int a,int b)    // 找两个数中最小值。 
{
	return a<b?a:b;
}
int get_max(int x,int y)    // 找两个数中最大值。 
{
	return x>y?x:y;
}
int fun( int (*p)(int ,int )  ,int x,int y)   // 此函数有三个参数：一个指针（函数指针）、两个变量
{
	return p(x,y);   // 返回的是具体运算。 
}
int main()
{
	printf("%d\n", fun(get_max,56,44));  // 调用 fun 函数。第一个参数，传递的是函数的首地址。 
	return 0;
}

// 练习2： 完成实验六-练习1. 写完之后，再尝试使用函数指针编写执行一次。 
#include <stdio.h>
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int main()
{
	int (*p)(int,int);
	p = add;
	printf(" result : %d\n", p(34,2));
	p = sub;
	printf(" result : %d\n", p(34,2));
	p = mul;
	printf(" result : %d\n", p(34,2));
	return 0;
}


3. 函数指针数组。 
上题中的例子，修改成函数指针数组去分别保存函数地址。 
///////////////////////
#include <stdio.h>
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int main()
{
	int (*p[3])(int,int) = {add,sub,mul};   // 定义数组。共3个元素。每个元素保存了一个函数地址（函数名）。

	int i;
	for(i=0; i<3; i++)
		printf(" result : %d\n", p[i](34,2)); // 分别实现 3 个运算。 
	return 0;
}



二、 带参宏   

宏：    是简单的符号替换。 不区分数据类型。在预处理阶段完成宏的替换（宏值替换掉宏名）  
注意：  一般，宏名采用大写。   
特点：  (1) 可以一改全改。   (2) 可以解释宏值的意义。 
#define MAX 1024

带参宏示例： 
//////////////////
#include <stdio.h>
#define DOUBLE(x)  2*(x)
int main()
{
	printf("%d",DOUBLE(4+1));
}

// 练习：使用带参宏实现功能： 求一个数的平方
#include <stdio.h>
#define SQUARE(x) (x)*(x)
int main()
{
	printf("%d\n",SQUARE(6+2));
}
// 练习： 请定义一个宏，判断这个数的奇偶性。（如果是偶数，得到真的是偶数（1），如果不是偶数，返回0.）
#include <stdio.h>
#define JUDGE(x)   (x)%2==0 ? 1:0
int main()
{
	printf("%d\n",JUDGE(3));
}



三、 递归函数        自己调用自己的函数，叫递归函数。    
两种表现形式：
(1)直接调用自己：
void fun()
{
	fun();
}
(2)间接调用自己： 
void fun1()
{
	fun();
}
void fun()
{
	fun1();
}

使用示例：  m!   4! 
4! = 4 * 3!;
3! = 3 * 2!;
2! = 2 * 1!; 
1! = 1;
////////////////
#include <stdio.h>
int jie(int n)
{
	if(n == 1)
		return 1;
	int result = n * jie(n-1);
	return result;
}
int main()
{
	printf("%d\n",jie(6));
}

// 练习： 斐波那契数列。用递归实现。打印第 20 项。  1 1 2 3 5 8 13 ...
#include <stdio.h>
int fib(int n)
{
	if(n==1 || n==2)
		return 1;
	int res = fib(n-1) + fib(n-2);
	return res;
}
int main()
{
	printf("%d\n",fib(20));
}

总结: 
递归函数分为两个阶段： 递推阶段、回归阶段。 
递推阶段： 函数不断调用的阶段。此时不断的占用栈空间。 
回归阶段： 函数不断的执行结束，释放空间的阶段。 

使用时注意： 
(1) 要有调用自己的语句。 
(2) 一定要有结束条件！！！！！！ 
(3) 要有实现功能的语句。 
(4) 先测试再使用。 



四、 条件编译  
1.  #ifdef  
///// demo.c //////
#include <stdio.h>
int main()
{
#ifdef N           // 条件编译：如果 N 这个宏已经定义，那么包含的这段就参与编译。 如果未定义宏，那么该段不参与编译。 
	printf("hello world!\n");
#endif 
	printf("11111111111111111\n");
}
///////////
编译的过程： 
(1) 如果代码中已经定义了宏，那么直接编译即可。  gcc a.c 
(2) 如果代码中没有定义该宏，但是想执行条件编译中的语句，那么，要在编译时，定义这个宏： gcc a.c -D N 


2.  #else 
/////////demo.c ///////
#include <stdio.h>
int main()
{
#ifdef N               // 如果定义了宏，则执行 #ifdef 这段代码。如果未定义宏，则执行 else 中的代码段。   
	printf("hello world!\n");
#else 
	printf("11111111111111111\n");
#endif 
}
//////////
编译二者选一： 
gcc a.c  
gcc a.c -D N 


3.  #ifndef  
/////// my.h //////
#ifndef _MY_H 
#define _MY_H  1 

#define IN_CLASSC(a)            ((((in_addr_t)(a)) & 0xe0000000) == 0xc0000000)    // 设定带参宏
#define IN_CLASSC_NET           0xffffff00                 // 宏定义
struct in_addr 
{
	in_addr_t s_addr;        // 定义结构类型 
};
extern int printf(const char *arg,...);    // 声明函数
// 等 操作

#endif 



五、 标准 main 函数
格式： 
int main(int argc,char *argv[])
{
	...;
	return 0;
}

参数的意义： 
argc    : 作用是：统计命令行参数的个数。 
argv[0] : 保存了执行文件的名字。  
argv[1] : 保存了传递来的第一个参数。 
argv[2] : 保存了传递来的第二个参数。 

示例： 
/////////////////
#include <stdio.h>
int main(int argc,char *argv[])
{
	printf("%d\n",argc);
	printf("%s\n",argv[0]);
	printf("%s\n",argv[1]);
	printf("%s\n",argv[2]);
	printf("%s\n",argv[3]);
}

// 练习： 实验六-练习6 
#include <stdio.h>
int  main(int argc,char *argv[])
{
	printf("%s   %s    %s\n",argv[1],argv[2],argv[3]);
	return 0;
}

// 练习： 使用命令行传参，实现简单计算器功能。  ./a.out 3 + 12   输出结果 15
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	if(argc < 4)
	{
		printf("%s num1 symbol num2\n",argv[0]);
		return -1;
	}
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[3]);
	switch( *argv[2] )
	{
		case '+' : printf("%d \n",num1 + num2);  break;
		case '-' : printf("%d \n",num1 - num2);  break;
		case '*' : printf("%d \n",num1 * num2);  break;
		case '/' : printf("%d \n",num1 / num2);  break;
		default  : break;	
	}
	return 0;
}



// 作业： 实验五 - 练习8.
// 下周： 数据结构：  指针、 结构体。



