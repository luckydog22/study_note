

复习： 
gcc  : 预处理、编译、汇编、链接
make : 工程管理工具。   makefile - 编译规则
gdb  ：调试器。 
指针 ：基本数据类型。是保存地址值的类型。  示例： int *p; char *x; 
数组 ：int a[10]; 数组名是数组首地址。 数组中的元素，在内存中连续存放。 



新课
一、 指针数组、 字符指针数组、数组指针 

(1) 指针数组    是数组。    每个元素都是指针的数组。    
定义数组：   int *a[5];    5个元素，每个都是指针类型。  |int *|int *|int *|int *|int *|
元素名称： 5个指针。
a[0]   a[1]   a[2]   a[3]   a[4]   // 下标从零开始。

示例： 
/////////////////
#include <stdio.h>
int main()
{
	int a[10] = {2,2,2,2,2,2,2,2,2,2};
	int b[10] = {6,6,6,6,6,6,6,6,6,6};
	int c[10] = {1,2,3,4,5,6,7,8,9,0};
	int *p[3] = {a,b,c};          //	p[0] = a;	p[1] = b;

	int i,j;
	for(j=0; j<3; j++)
	{
		for(i=0; i<10; i++)
			printf("%d ",p[j][i]);  // p[0] = a;  p[1] = b; p[2] = c;
		printf("\n");
	}
	return 0;
}

（2）字符指针数组。  char *a[5];   5个指针。 |char *|char *|char *|char *|char *|

示例： 
//////////////////
#include <stdio.h>
int main()
{
	char s[] = "hello";
	char x[] = "beautiful";
	char r[] = "future";

	char *p[3] = {s,x,r};    

	int i;
	for(i=0; i<3; i++)
		printf("%s\n",p[i]);
	return 0;
}

疑问： char *p[3] = {"hello","beautiful","future"};   // 定义的是 3 个指针，保存的是 3 个地址。字符串的首地址。 

// 练习： 随机点名。 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	char *name[4] = {"xiaoming","xiaoli","xiaonan","xiaohong"};
	while(1)
	{
		printf("%s\n",name[rand()%4]);
		getchar();
	}
}

// 练习：定义字符指针数组 char *str[5]分别指向 5 个字符串常量，从小到大输出字符串的内容。 
#include <stdio.h>
#include <string.h>
int main()
{
	char *str[5] = {"for","better","future","hello","world"};     //    str[0] = “for”的地址

	int i,j;
	char *temp;
	for(i=0; i<5-1; i++)
	{
		for(j=0; j<5-1-i; j++)
		{
			if( strcmp(str[j],str[j+1]) > 0)   // if(str[j] > str[j+1])   
			{
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
	}
	for(i=0; i<5; i++)
		printf("%s\n",str[i]);
}


整形指针数组      int *a[10]
字符指针数组


（3） 数组指针.      是指针。  是指向数组的指针。    
初始二维数组： int a[3][10]= {{1,6,6,6},{2,4,3,1},{3,1,2,3,4,5}}; 

定义数组指针： int (*p)[10];         
指针指向变量： p = a;
初始化：       int (*p)[10] = a;

示例： 
/////////////
已知： int b[5][10];    int a[2][10];
可以如下指针，指向已知的两个二维数组：    int (*p)[10];    p = a; 或者 p = b;


示例代码： 
//////////////////////
#include <stdio.h>
// fun功能：打印二维数组的值。
void fun(int (*p)[4],int row)      // 传递参数时，定义数组指针，接二维数组的首地址。 
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<4; j++)
			printf("%d  ",p[i][j]);
		printf("\n");
	}
}
int main()
{
	int a[3][4] = {{4},{4},{4}};
	int b[5][4] = {{5},{5}};
	fun(b,5);
}

// 问： 请标明以下数据的数据类型   
int a;          // 整形
int *a;         // 指针  
int a[10];      // 数组  
int *a[10];     // 数组。 每个元素都是指针的数组。  （10个一级指针） 
int (*a)[10];   // 指针。 指向二维数组的指针。      （1个二级指针）

数据类型：  
基本数据类型： int char float double long  指针      
构造类型：     数组、 结构体    
空类型：       void 

// 练习：编写一个程序实现以下功能：用数组指针处理一个二维数组，求出二维数组所有元素的和。 
	int array[3][4]={ {7,  10, -2,   3}, 
                      {14, 30,  6, -15}, 
                      {0,   5,  27, -7} }； 
///////////////////
#include <stdio.h>
int get_sum(int (*p)[4],int row)
{
	int i,j,sum = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<4; j++)
			sum += p[i][j];
	}
	return sum;
}
int main()
{
	int array[3][4] = {{7,10,-2,3},
			   {14,30,6,-15},
			   {0,5,27,-7}};
	int res = get_sum(array,3);
	printf("res : %d\n",res);
	return 0;
}



二、 const  
功能： 使变量常量化。

示例1： 
///////////////
int const a = 45; 
a = 66;
printf("%d \n",a);
//////
编译： 
kayla@ubuntu:~$ gcc x.c
x.c: In function ‘main’:
x.c:5:4: error: assignment of read-only variable ‘a’       // 变量 a 的权限： read-only ，不能修改。所以赋值为非法赋值。
  a = 77;
    ^

示例2： 
////////////////
#include <stdio.h>
int main()
{
	int a = 34,b = 100;
	int * const p = &a;     // 变量 p 被 const 修饰，成为定值。所以p 不能再保存 b 的地址。 
	p = &b;
	printf("%d\n",*p);
}
///////
kayla@ubuntu:~$ gcc x.c
x.c: In function ‘main’:
x.c:7:4: error: assignment of read-only variable ‘p’
  p = &b;
    ^

示例3： 
//////////////////
#include <stdio.h>
int main()
{
	int a = 34;
	int const *p = &a;     // const 修饰 *p. *p 是常量。 所以：要想修改变量 a 的值，只能变量a 自己重新赋值，不能通过指针，修改变量的值。 
	*p = 77;
	printf("%d\n",*p);
}
//////////
编译： 
kayla@ubuntu:~$ gcc x.c
x.c: In function ‘main’:
x.c:5:4: error: assignment of read-only variable ‘a’
  a = 77;
    ^

总结：     
const int a ;         // a 是常量。  
int const a ;         // a 是常量。  
int * const a;        // a 是常量。 
int const *a;         // *a 是常量。 
const int *a;         // *a 是常量。  
int const * const a;  // a 和 *a 都是常量。 



三、 数据的存储类型      
auto   register   extern   static 

1. 静态外部链接    extern
//// a.c ////
int a = 200;

//// b.c ///
#include <stdio.h>
extern int a;        // 变量的声明。声明：存储类型 + 数据类型 + 变量名。    声明外部存在变量a, 在当前位置可以使用。 
int main()
{
	printf("a = %d\n",a);
}


2. 静态内部链接   static 
1）static 修饰全局变量  
//// a.c ////
static int a = 200;      // static 修饰全局变量。将当前的全局变量限定在当前文件内使用，不可被外部借用。

//// b.c ///
#include <stdio.h>
extern int a;        // 变量的声明。声明：存储类型 + 数据类型 + 变量名。    声明外部存在变量a, 在当前位置可以使用。 
int main()
{
	printf("a = %d\n",a);
}
编译结果： 
kayla@ubuntu:~/work$ gcc a.c b.c
/tmp/ccFBGMv6.o: In function `main':
b.c:(.text+0x6): undefined reference to `a'     // a 未定义。 因为 a.c 中的变量 a, 被 static 修饰限定。
collect2: error: ld returned 1 exit status


2）static 修饰局部变量。      //被修饰的局部变量成为静态变量。
示例： 
///////////////////
#include <stdio.h>
void fun()
{
	static int a = 23;
	printf("a = %d\n",a);
	a++;
	return ;
}
int main()
{
	fun();
	fun();
	fun();
}
执行结果： 
kayla@ubuntu:~$ ./a.out
a = 23
a = 24
a = 25

3）static 修饰了函数： 被修饰的函数，限定在当前文件内使用。 


c语言定义的四个内存分区： 
代码区：     RO    代码。  
静态全局区： 全局变量、静态变量、字符串常量、
堆区：       malloc   手动申请和释放。           
栈区：       局部变量区。 函数。 系统自动分配和释放栈区内存。   



四、 二级指针 
int a = 100;      int *p = &a;       int **q = &p;   
	
地址： 0x00001234    0x00001238      0x0000123c 
变量：    a              p               q  
值  ：   100         0x00001234      0x00001238

表示： 
		a = 100       *p = 100       **q = 100 
	 &a=0x00001234  p=0x00001234    *q=0x00001234
	                &p=0x00001238   q = 0x00001238
					                &q= 0x0000123c

示例： 编写函数，实现功能： 获取一块内存空间保存数据。 
/////////// m.c //// 
#include <stdio.h>
#include <stdlib.h>
void get_memory(int n,int **q)  // q 为输出型参数，接到变量的地址，只为了给这个地址上的变量赋值。 
{
	*q = (int *)malloc(n * sizeof(int));     // malloc 得到的空间，通过 q,间接的赋值给了主程序中的 变量 p. 
	return ;
}
int main()
{
	int *p = NULL;  
    get_memory(10,&p);      // 将 p 的地址传递上去，只为了让 p 得到一个值。 
	if(p == NULL)
	{
		perror("malloc");
		return -1;
	}
	int i,sum = 0;
	for(i=0; i<10; i++)
	{
		scanf("%d",p+i);      // 正常使用堆空间地址。
		sum += p[i];
	}
	printf("sum = %d\n",sum);
	free(p);
	return 0;
}
//////////// mem.c //// 方式二： 一级指针。
#include <stdio.h>
#include <stdlib.h>
int *get_memory(int n)     // 函数功能。 
{
	int *p = (int *)malloc(n * sizeof(int));
	return p;
}
int main()
{
	int *p = get_memory(10);
	if(p == NULL)
	{
		perror("malloc");
		return -1;
	}
	int i,sum = 0;
	for(i=0; i<n; i++)
	{
		scanf("%d",p+i);
		sum += p[i];
	}
	printf("sum = %d\n",sum);
	return 0;
}


// 作业： 晚自习题  day3. 
// 预习： 函数指针、指针函数、递归函数





