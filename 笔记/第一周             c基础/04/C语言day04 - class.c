#复习：


类型转换 : 隐式转换和强制类型转换

int + float == float 

char ---> short ---> int ---> long ---> float ----> double 
1			2		4			4			4			8

int a;
sizeof(int); ---> 4
sizeof(a); ---> 4

字符输出函数 

putchar('A');
putchar('\n');
char a = 'a';
putchar(a);


字符串输出函数 

puts("hello");//自带换行符

float a = 3.14;
printf("%.2f\n",a)

%x
int a = 9;
printf("%02d\n",a);

while循环 

while(条件)//只要条件成立，就执行{}里面的语句
{//循环体
	
}

##C语言中非零即为真
while(1)
{
	//执行语句
}

int i = 0; //循环变量初始化
while(i <= 100)//循环结束条件
{
	//执行语句
	i++;//循环变量自加 自减
}
/////循环结束 i 的值 101


for循环  

int i;
for(i = 1; i <= 100; i++)
{
	//循环执行语句
	printf("hello world!!\n");
}

用for写一个死循环 for(;;)
	

break; //结束 switch或循环体

continue; //结束本次循环


1. 一维数组
	
	
	如果有一些同类型的数据，又特别多，
	有100个学生，输入这些学生的成绩，又求平均值

	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10....a100

	可以用数组解决上面的问题


	1.1	怎么定义一个数组
	
		int a[100];  //int 元素类型 a 是数组名， [ ]代表数组  100元素个数  

	1.2 数组元素怎么赋值(数组元素下标是从0开始的)
	
		
		int a[5] = {1,2,3,4,5};
		
		a[0] = 1;   ///a[0] 第1个元素
		a[1] = 2;   ///a[1] 第2个元素
		a[2] = 3;   ///a[2] 第3个元素	
		a[3] = 4;   ///a[3] 第4个元素	
		a[4] = 5;   ///a[4] 第5个元素
		a[5] ?      ///a[5] 第6个元素，不存在，无效	

		整型数组
		int a[5];

		字符型数组
		char a[5];

		浮点型数组
		float a[5];

		数组占用内存空间大小
		
		int a = 10;
		
		sizeof(a) ?  4

		int a[5];
		
		sizeof(a) ?  20 //a  数组的名字，sizeof(数组名)求整个数组所占内存空间的大小
		
		//数组名就是数组在内存当中存储的首地址
		
		//数组在内存当中是连续存储的
		
		//数组的其实下标是0，终止下标是元素个数n-1

	1.3 数组初始化
	
	
		(1)完全初始化，所有的元素，都会赋值
		
			int a[5] = {1,2,3,4,5};
			
			a[0] ---> 1
			a[1] ---> 2
			a[2] ---> 3
			a[3] ---> 4
			a[4] ---> 5

		(2)部分初始化(没赋值的元素默认为0)
		
			int a[5] = {1,2};
			a[0] ---> 1
			a[1] ---> 2
			a[2] ---> 0
			a[3] ---> 0
			a[4] ---> 0
			
			但是不可以这样
			
			int a[3] = {1,2,3,4,5};	//初始化值个数不可以多于定义时元素个数， 错

		(3)元素个数不写
		
			int a[] = {1,2,3,4,5};
		
			元素个数不写，能从初始化值中自动计算出来

			####代码演示：遍历数组
#
			#include <stdio.h>
			int main()
			{
				int i;
				int a[5] = {1,2,3,4,5};	//定义数组时，直接初始化
				printf("%d,%d,%d,%d,%d\n", a[0], a[1], a[2], a[3], a[4]);	//
				for(i = 0; i < 5; i++)
				{
					printf("%d\n", a[i]);
				}
			}

			###练习1 
			
			  有10个学生成绩是
			  
			  int a[10] = {90, 80, 70, 60, 50, 40, 30,99,98,77};

			 要求，求出学生总成绩，求出学生平均成绩
			 
			#include <stdio.h>
			int main()
			{
				int a[10] = {90, 80, 70, 60, 50, 40, 30,99,98,77};
				int i, sum = 0;	//sum 不给初值，那么是随机值
				for(i = 0; i < 10; i++)
				{
					sum += a[i];	//sum += a[10]; //错
				}
				printf("sum is %d, avg is %d\n", sum, sum / 10);	
			} 
				
			###练习2 ///上面的练习，成绩由键盘输入10个学生成绩，然后打印输出和与平均值	
			
			
			#include <stdio.h>
			int main()
			{
				int a[10];
				int i, sum = 0;	//sum 不给初值，那么是随机值
				for(i = 0; i < 10; i++)
				{
					scanf("%d", &a[i]);
				}
				for(i = 0; i < 10; i++)
				{
					sum += a[i];	//sum += a[10]; //错
				}
				printf("sum is %d, avg is %d\n", sum, sum / 10);	
			} 

			###练习3
			
			输出Fibonacci数列前20项, 先正序输出，然后逆序输出。
			
			1 1 2 3 5 8 13 21 34 55 
			
			a[2] = a[0] + a[1]
			a[3] = a[1] + a[2]
			
#include <stdio.h>

int main()
{
	int a[20] = {1,1};//部分初始化
	int i;
	for(i = 2; i < 20; i++)
	{
		a[i] = a[i-1] + a[i-2];
	}
	//遍历数组,正序输出
	for(i = 0; i < 20; i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
	//
	for(i = 19; i >= 0; i--)
	{
		printf(" %d",a[i]);
	}
	//遍历数组，倒序输出
	printf("\n");
	
} 
	1.4 冒泡排序
	
		原理：每次两个数进行比较，从数组的前两个元素开始，如果前面的数 > 后面的数，就交换
		
        第一趟会求出一个最大值，并且放在最后面，
		
		然后 依此类推，经过最多N-1趟，排好序
		
		
		int a[7] = {55, 32, 68, 31, 72, 98, 21}; 
		
		
		
		******
		*****
		****
		***
		**
		*
		
		i = 0  6
		i = 1  5
		i = 2  4
		i = 3  3 
		i = 4  2
		
		

		#include <stdio.h>

		int main()
		{
			int temp;
			int a[7] = {55, 32, 68, 31, 72, 98, 21}; 
			int i,j;
			for(i = 0; i < 7-1; i++)
			{
				for(j = 0; j < 7-1-i; j++)
				{
					if(a[j] > a[j+1])
					{//交换位置
						temp = a[j];
						a[j] = a[j+1];
						a[j+1] = temp;
					}
				}
			}
			//遍历数组
			for(i = 0; i < 7; i++)
			{
				printf("%d ",a[i]);
			}
			printf("\n");
			return 0;
		}
		
		
		##练习4
		
		输入10个考试分数，
		然后找到最高分、最低分，打印输出
		
		
		#include <stdio.h>

		int main()
		{
			int a[10];
			int i;
			int max,min;//用来保存最大值和最小值
			//输入10个数
			for(i = 0; i < 10; i++)
			{
				scanf("%d",&a[i]);
			}
			//假设数组中的第一个元素就是最大值　最小值
			max = a[0];
			min = a[0];
			for(i = 1; i < 10; i++)
			{
				max = max < a[i] ? a[i] : max;//永远让max中保存最大值
				min = min > a[i] ? a[i] : min;
				/*
				if(max < a[i])
				{
					max = a[i];
				}
				if(min > a[i])
				{
					min = a[i];
				}
				*/
			}
			printf("max is %d\nmin is %d\n",max,min);
			return 0;
		}
				
			

2. 字符和字符串
	
	
	
	2.1 字符和字符串举例
	
	'A' 字符  
	'?'
	'a'
	'0'
	"hello"  ---->字符串

	字符串组成 "hello" ---> 'h' 'e' 'l' 'l' 'o'  '\0'

			'\0' 字符串结束符， 碰到'\0' 表示字符串结束
			
	打印字符串，求字符串长度， copy字符串，都会用到'\0'结束符

	'\0' ----> 数字0
	
	

	2.2 如何保存字符串？ --->用字符数组

		char a[] = "hello";   =====>  char a[6] = "hello"; //因为字符串以 '\0'
		
		char b[] = {'h','e','l','l','o'}; ====>char b[5] = {'h','e','l','l','o'};
		
		sizeof(a)   ?  // 6 sizeof(数组名)求整个数组所占内存空的大小 1 * 6 ==== 6 
		int a[5]; sizeof(a) ---> 20

	2.3 字符串输出
		
		###代码举例
		
		#include <stdio.h>
		int main()
		{
			char a[] = "hello";		//char a[100];
			int i;
			scanf("%s", a);		//a 不加&, 因为a 是字符串首地址
			//以字符方式一个一个输出
			for(i = 0; i < 6; i++)
			{
				printf("%c", a[i]);
			}	
			printf("\n");	
			//字符串整体输出
			printf("%s\n", a);	//a 是字符串首地址
		}

		##练习5 定义一个字符串数组，用scanf输入，然后分别用两种方式打印
		
			 1  "%s" 
			 2  循环 + "%c"

			
		#include <stdio.h>
		int main()
		{
			char a[100] = "hello";		//char a[100];
			int i;
			scanf("%s", a);		//a 不加&, 因为a 是字符串首地址
			//gets(a); //字符串输入函数
			//以字符方式一个一个输出
			for(i = 0; i < 6; i++)
			{
				printf("%c", a[i]);
			}	
			printf("\n");	
			//字符串整体输出
			printf("%s\n", a);	//a 是字符串首地址
		}
		##练习6 
		
		//给你字符串数组，char a[100] = "hello";
		
		写一个程序，求出字符串长度，"hello"   5;
		
		int len = 0;//用来保存字符串的长度
		
		char a[100] = "hello"; ===》sizeof(a) === 100
		
		
		int i = 0;
		while(a[i] != '\0')
		{
			i++;
		}
		
		a[0] -- 'h'
		a[1] -- 'e'
		a[2] -- 'l'
		a[3] -- 'l'
		a[4] -- 'o'
		a[5] -- '\0'
		
		
		//字符串的长度 等于 '\0'位置所对应的下标
		方法1：
		#include <stdio.h>
		int main()
		{
			char a[100] = "hello";
			int i = 0;
			while(a[i] != '\0')
			{
				i++;
			}
			printf("len is %d\n", i);
		} 
		方法2：
		#include <stdio.h>
		int main()
		{
			char a[100] = "hello";
			int i = 0;
			for(i = 0; i < 100; i++)
			{
				if(a[i] == '\0')
				{
					break;
				}
			}
			printf("len is %d\n", i);
		} 

	2.6 字符串拷贝
	

		对于数组来说，如果将一个数组赋值给另一个数组
		char a[] = "hello";
		char b[6];

		将a ----> b

		b = a;   //错， 数组不可以整体赋值，除了初始化 

		b = "hello"; //错

		可以一个一个赋值
		b[0] = a[0];
		b[1] = a[1];
		b[2] = a[2];


		##练习7：完成一个字符串copy, 将a字符串中的数据copy到b中
		
				char b[100];
				char a[] = "hello";
		
		#include <stdio.h>
		int main()
		{
			int i = 0;
			char a[] = "hello";
			char b[100];
			while(a[i] != '\0')//a[i] == '\0'的是时候循环结束，说明'\0'没有拷贝给b数组
			{
				b[i] = a[i];
				i++;
			}
			b[i] = '\0'; //注意此处一定要将'\0'复制过去
			printf("b is %s\n", b);
		}
		
	

	2.7 字符串处理函数讲解

		1) 求字符串长度            strlen
		2) 字符串copy              strcpy
		3) 将两个字符串连接在一起  strcat

		#####代码演示 

		#include <stdio.h>
		#include <string.h>     //字符串处理头文件
		
		int main()
		{
			char a[100] = "hello";
			char b[100];
			char c[100] = " world";
			int l = strlen(a);	//strlen --> string length
			printf("l is %d\n", l);
			strcpy(b, a);		//将a copy 给  b
			printf("b is %s\n", b);
			strcat(a, c);		//将c连接在a后面, 注：a 应该能装下 a + c
			printf("a is %s\n", a);
		}


		##练习8
				将字符串char a[] = "Hello World!"中的小写字母转大写

				'a'  ---> 97
				'A'  ---> 65
				'A' = 'a' - 32;
				
				
				
				
				
				
				
				
				
				
				

				#include <stdio.h>
				int main()
				{
					char a[] = "Hello World!";
					int i = 0;
					while(a[i] != '\0')
					{
						if(a[i] >= 'a' && a[i] <= 'z')//判断小写字母的条件
						{
							a[i] -= 32;
						}
						i++;
					}
					printf("%s\n", a);
				}


3.作业：

 1. 围绕着山顶有10个圆形排列的洞，狐狸要吃兔子，
  兔子说：“可以，但必须先找到我，我就藏身于这十个洞中的某个洞。
  你从1号洞找，下次隔1个洞（即3号洞）找，第三次隔2个洞（即6号洞）找，
  再隔3个…以后在这个圆圈中如此类推，次数不限。”但狐狸从早到晚进进出出了1000次，仍没有找到兔子。
	问：兔子可能在哪个洞里？
	2 4 7 9
#include <stdio.h>

int main()
{
	int a[10] = { 0 };//代表10个洞，初始值为0，如果被找过，标记为1
	int i;//循环变量,找了1000次
	int j = 0;// 代表狐狸去找的洞号，初始值为0，代表第一个洞号
	//i 0 1 2 3 4
	//j 0 2 5 9 14
	for(i = 0; i < 1000; i++)
	{
		a[j] = 1;//找完的洞
		j = (j+i+2)%10;		//狐狸要找的下一个洞号
	}
	//再循环判断，那个元素的值为0，代表狐狸没有去过
	for(i = 0; i < 10; i++)
	{
		//if(!a[i])
		if(a[i] == 0)
		{
			printf("可能是%d\n",i+1);
		}
	}
	return 0;
}

//////////////
int i = -100;
do
{
	
}while(i++);//因为++在后，先条件判断运算，再++，当i等于0的时候，循环结束，也就是说，条件判断运算先结束，后++，所以结束后i的值为1
printf("i is %d\n",i);//打印的结果是1


 2. 消除一句话中所有的原音字母，例如
 
	char a[] = "I am a student!"

 
	输出： m  stdnt!


#include <stdio.h>

int main(int argc, const char *argv[])
{
	char a[] = "I aam a Student!!";
	int i = 0;
	int j;
	puts(a);
	while(a[i] != '\0')
	{
		if(a[i] == 'a'|| a[i] == 'e' || a[i] == 'i' || a[i] == 'o' ||
				a[i] == 'u' || a[i] == 'I')
		{//如果进入if条件，遇到元音字母，i的位置就是元音字母的位置
			j = i;//j记录了即将被删除的元音字母位置
			while(a[j] != '\0')
			{
				a[j] = a[j+1];//逐个向前覆盖（赋值）
				j++;
			}
			//continue;//后面的i++没有被执行
			i--;
		}
		i++;
	}
	puts(a);
	return 0;
}


#include <stdio.h>

int main(int argc, const char *argv[])
{
	char a[] = "I am a student!!";
	char b[] = "aeiouAEIOU";
	int i = 0,j,k;
	puts(a);
	while(a[i] != '\0')//遍历I am a student!!
	{
		j = 0;
		while(b[j] != '\0')//如果出现元音字母执行break,那么while循环不是自然结束,b[j] 不会等于'\0'
		{
			if(a[i] == b[j])//遇到元音字母break
			{
				break;
			}
			j++;
		}
		if(b[j] != '\0')//说明执行过break,出现了原因字母需要删除
		{
			k = i;//k保存出现元音字母位置的下标
			while(a[k] != '\0')//逐个向前覆盖
			{
				a[k] = a[k+1];
				k++;
			}
			i--;
		}
		i++;
	}
	puts(a);
	return 0;
}