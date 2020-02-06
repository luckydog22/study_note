复习：

	&& //一假即假，同真为真 
	
	|| //一真即真，同假为假
	
	！ //真--》假  假-》真
	
	&& 和 || 存在短路运算  
	
	&& 短路 ---》让第一个条件为假 
	
	|| 短路 ---》让第一个条件为真
	
	++ --
	
	a++; //先运算 再++
	
	++a;//先++，再运算 
	
	int a = 3;
	int b = 5;
	int c = a++ + b++;
	
	a === 4
	b === 6
	c === 8 
	

	a += 3 ---> a = a + 3
	
	score = score / 10;
	
	score /= 10;
	
	
	if()
	{}
	else if()
	{}
	else if()
	{}
	else 
	{}
		
	
	三目运算符 
	
	int max = a > b ? a : b;
	
	switch(day)
	{
		case 1:
			//执行的语句
			break; //跳出switch体
		default://以上所有case都不满足，执行default
			//执行语句
	}
	
	
	int 4  %d
	char 1 %c
	short 2 %d
	long 4 %ld
	float 4 %f
	double 8 %lf
	
	
	man ascii 
	
	字符就是特殊的整数
	
	'\0' ---> 0
	
	'0' ----> 48
	
	'a'-----> 97
	
	'A'-----> 65
	
	'2' = '0' + 2


1. 输入输出

	1.1 输入输出需要包含头文件
		//.h结尾的是头文件
	
		stdio.h   //std: 标准  i : input   o : output   .h 头文件

		#include <stdio.h>
		int main()
		{
		
		}
	
	1.2 输出函数： 字符函数和输出字符串函数 缺点：不能格式化输出
	
		putchar()    //输出一个字符，到屏幕上  ' '字符
 		puts()       //输出一个字符串到屏幕上, 自动加'\n' " " 表示字符串
		
		####代码举例
		
		#include <stdio.h>
		int main()
		{
			putchar('A');   //输出A到屏幕上
			putchar('?');   //输出?到屏幕上
			putchar('\n');   //输出\n到屏幕上
			puts("hello"); //输出hello到屏幕上 
			puts("nihao xiaoli");//输出 nihao xiaoli到屏幕上
		}

	1.3 格式化输出函数 printf()函数
	
		
		
		(1)可以输出 字符、字符串、整形变量、浮点型变量 
		
			char   %c
			int    %d
			float  %f
			double %lf
			long   %ld

			float  单精度浮点型   double 双精度浮点型

			如果以16进制输出 %x
			
		(2) 可以指定输出格式， 固定输出2个字符宽度，02 

			int hour = 23, min = 3, sec = 9;
			printf("%02d:%02d:02d\n",hour,min,sec); //23:03:09

		(3) 如果%f输出，默认保留小数点后6位，如果只保留2位， printf("%.2f", d);

			#include <stdio.h>
			int main()
			{
				int h = 2, m = 8, s = 5;
				int a = 48;
				printf("a is %d\n", a);
				printf("a is 0x%x\n", a);
				printf("%02d:%02d:%02d\n", h, m, s);	//2 表示输出占2位，0 表示如果不足2位，补0
									//如果不加0, 表示不足2位补空格
				float d = 3.146;
				printf("d is %.2f\n", d);		//.2f,表示保留2位小数，如果多于2位，四舍五入
			}


	1.4 格式化输入函数 scanf("%d", &b);  格式化输入
	
		char   %c
		int    %d
		float  %f
		double %lf
		long   %ld

		#include <stdio.h>
		int main()
		{
			int a;
			scanf("%d", &a);
			printf("a is %d\n", a);
		}

	1.5 字符输入函数 getchar()
	
		#include <stdio.h>
		int main()
		{
			int a = getchar();	//执行1次，得到1个字符，a里面保存的输入的字符对应的ascii的值
			printf("a is %c\n", a);
			getchar();//吸收回车符
			int b = getchar();
			printf("b is %c\n", b);
		}


#练习1 编写一个程序，要求输入一个ASCII码值，然后输出相应的字符。

	#或者输入一个字符，求出ASCII码值
	
	int a = getchar(); 'A'
	printf("%d\n",a); ==>65

	输入65 ---> 打印输出A
	输入97 ---> 打印输出a

	
	#include <stdio.h>
	int main()
	{
		int a;
		scanf("%d", &a);
		printf("a is %c\n", a);
	}



#练习2 编写程序，从键盘输入两个整数，分别计算出它们的商和余数，

#	输出时，商数要求保留2位小数，并对第三位进行四舍

	#include <stdio.h>
	int main()
	{
		int a, b, d;
		float c;
		scanf("%d%d", &a, &b);
		c = (float)a / (float)b;
		d = a % b;
		printf("c is %.2f, d is %d\n", c, d); 、
	
2 循环结构

	2.1 while 循环
		
	
	(1)
		问题： 求出 1+2+3+4+5+6+....+100的和

		方法： int a = 1 + 2 + 3 + 4 + 5 + 6.... //麻烦，如何用循环来解决呢？	
		###代码演示：求和
		#include <stdio.h>
		int main()
		{
			int i = 1; 
			int sum = 0;//用于累加求和
			while(i < 101)	//i < 101是条件，如果条件成立，就执行{ }, 里面的语句
			{			//{  }里面的语句执行完继续回到while进行判断，直到条件不成立
				sum += i; 
				i++; 
			}
	
			printf("sum is %d i is %d\n", sum, i);
		}
	
		////程序执行结束  sum is 5050 	i is 101 
		
		##练习3: 用while循环 输出从1-1000内能被3整除，但不能被5整除的数字。

		
		#include <stdio.h>

		int main(int argc, const char *argv[])
		{
			int i = 1;//循环变量初始化
			while(i <= 1000)//循环结束条件
			{
				if(i % 3 == 0 && i % 5 != 0)
				{
					printf("%d",i);
				}
				i++;//循环变量自加　自减
			}
			return 0;
		}


		(2)无限循环(死循环)
			
				//无限循环(永远执行，永远条件成立)
				while循环很容易写成无限循环(死循环)
				
				####代码演示 
				
				#include <stdio.h>
				
				int main()
				{
					while(1)
					{
						printf("hello world!!\n");//注意此处一定要加\n换行符
						sleep(1); //延时 1s
					}
					return 0;
				}
				/////按ctrl + c 结束程序
				

	2.2 for 循环 //通常用在循环次数已知的情况下


		(1)用for循环求和
		
			1+2+3+4+5+6+....+100    //循环此数就是100次
		
			##代码演示 
			
			#include <stdio.h>
			
			int main()
			{
				
				int i, sum = 0;
				for(i = 1; i < 101; i++)	// 共3句话，i=1 在for循环执行之前执行，通常执行初始化操作，只执行1次
				{				// i < 101, 在每次循环之前执行，通常是一个判断语句，如果条件成立，就执行 {  }
								// i++, 在每次循环执行完执行
					sum += i;
				}
				printf("sum is %d i is %d\n", sum, i);
				//打印输出sum is 5050 i is 101
			}

			##练习4: 用for循环完成 输出从1-1000内能被3整除，但不能被5整除的数字。
			
			#include <stdio.h>
			
			int main()
			{
				int i = 1;
				for(i = 1; i < 1001; i++)
				{
					if(i % 3 == 0 && i % 5 != 0)
					{
						printf("%d,", i);
					}
				}
			}

		//如果用for写一个死循环
		
		for(;;)
		{
			printf("hello wrold!!\n");
		}


		(2)for循环嵌套
		

			for(i = 0; i < 10; i++)
			{
				for(j = 0; j < 10; j++)
				{
					printf("hello world\n");
				}
				
			}

			请问打印输出多少次 "hello world\n" ? 
		
			上面循环 执行 10 * 10 次 //外循环 循环一次，内循环，跑一圈
			
	
		###练习5
		
		用for循环嵌套 实现输出如下图型, 要求1次只能输出一个 "#" printf("#");
		//外循环次数控制行数，内循环的次数控制列数
		
		#####
		#####
		#####
		
		#include <stdio.h>
		int main()
		{
			int i, j;
			for(i = 0; i < 3; i++)
			{
				//printf("#####\n");
				for(j = 0; j < 5; j++)
				{
					printf("#");
				}
				printf("\n");
			}
		}
			
		##练习6 
		
		用for循环嵌套 实现输出如下图型, 要求1次只能输出一个 "*" printf("*");
		

		*      i = 0   1
		**     i = 1   2
		***    i = 2   3
		****   i = 3   4
		*****  i = 4   5  
		
		#include <stdio.h>

		int main(int argc, const char *argv[])
		{
			int i,j;
			for(i = 0; i < 5; i++)
			{
				for(j = 0; j <= i; j++)
				{
					printf("*");
				}
				printf("\n");
			}
			return 0;
		}
		
		(3)break关键字 
		
			break 作用：结束switch体和循环体(for,while,do-while循环)
		
			###代码案例演示
			
			求和 1+2+3+4+5+6+....+100 ,如果只加到10?

			#include <stdio.h>
			int main()
			{
				int i, sum = 0;
				for(i = 1; i < 101; i++)	
				{
					if(i == 10)
					{
						break;	//结束整个循环，10没有参加到加法运算中
					}				
					sum += i; //一上面的i == 10的时候，执行break,循环结束，sum += i不会被执行，10没有被加入到sum中
				}
				
				printf("sum is %d i is %d\n", sum, i); //sum is 45   i is 10
			
			//break 在循环里面用来结束整个循环

			//10 不参加加法运算
			
		(4) continue 关键字 
			
			continue 关键字作用：结束本次循环 
			
			求和 1+2+3+4+5+6+....+100 ,如果不要将单个10加入进去 ?
		
			#include <stdio.h>
			int main()
			{
				int i, sum = 0;
				for(i = 1; i < 101; i++)	
				{
					if(i == 10)
					{
						continue; //用来结束本次循环
					}				
					sum += i;
				}
				
				printf("sum is %d i is %d\n", sum, i);//sum is 5040   i is 101
			}
		
		
		##练习7：编写程序实现如下功能：
		
				1+2+3+4+...+100, 能被5整除的除外
				
				#include <stdio.h>
				int main()
				{
					int i, sum = 0;
					for(i = 1; i < 101; i++)	
					{
						if(i % 5 == 0)
						{
							continue; //用来结束本次循环
						}				
						sum += i;
					}
					printf("sum is %d i is %d\n", sum, i);
				}


		
		##练习8：用while写一个死循环，实现用户输入一个数字后，立刻打印输出该数字，直到输入为0时为止，结束程序
			
			
			
		#include <stdio.h>

		int main(int argc, const char *argv[])
		{
			int num;
			while(1)
			{
				puts("Please input a number:");
				scanf("%d",&num);
				if(num == 0)
		//		if(!num)//假设num的值为0,代表假，　!0变成真,执行break
				{
					break;
				}
				printf("num is %d\n",num);
			}
			return 0;
		}	
			
	
			
		##练习9：打印输出100-999之间的所有水仙花数 
		
			水仙花数需要满足下面条件
			
			例如 153就是水仙花数 满足条件 153 == 1*1*1 + 5*5*5 + 3*3*3	
			
			
#include <stdio.h>
int main()
{
	//输入一个数，判断是不是水仙花数
	int i;//用来保存这个数
	int a,b,c;//分别代表百位，十位，个位
	for(i = 100; i < 1000; i++)
	{
		a = i / 100;  //153 / 100
		b = i / 10 % 10;// 153 / 10 == 15 15 % 10 == 5
		c = i % 10;// 153 % 10 === 3
		if(i == a*a*a + b*b*b + c*c*c)
		{
			printf("%d Yes!!\n",i);
		}
	}

}	
		
		
	
	2.3 do-while循环 
	
		do{
		...
		} while(条件);    循环

		重点：先执行do{  } 里面的语句，然后再进行判断， 只要条件成立，就继续执行

			 最少执行一次
		
		###代码演示 
		
		求和 1+2+3+4+5+6+....+100
		
		#include <stdio.h>
		int main()
		{
			int i;
			int sum = 0;
			i = 1;
			do
			{
				sum += i;   // 不管条件成不成立，先执行
				i++;
			}while(i < 101);
			printf("sum is %d\n", sum);
		}





作业：




1 编写一个程序，输出1-100的全部素数(质数)。
素数，除了1和自己，不能被任何数整除的数

2 3 5 7 11 13 17 19 ....

#include <stdio.h>
int main()
{
	//输入一个数，判断是不是质数
	int i;//用来保存这个数
	int j;//作为循环变量
	int flag  = 0;//标志位

	for(i = 2; i <= 100; i++)
	{
		flag = 0;
		for(j = 2; j < i; j++)
		{
			if(i % j == 0)//证明i，不是质数
			{
				flag = 1;//证明代表他不是质数
				break;//结束循环，break只能结束当前所在的循环体
			}
		}//方法一
		if(i == j)//说明他是自然结束，没有执行过break(循环结束后i等于j)，如果执行过break(循环结束后i不等于j)证明他不是质数，正因为没有执行过break,反而证明他是质数
		{
			printf("%d是质数\n",i);
		}
		//方法二
		/*
		if(flag == 0)//flag == 0代表是质数
		{
			printf("%d是质数\n",i);
		}
		*/
	}
	//循环结束的时候，j的值满足什么条件
	//j == i 循环结束，如果没有执行过break,证明他是质数
	
}



2. 输出：N层三角形阵,层数由用户输入
	其中N为正数，由用户输入5，输出满足下面规律的三角形阵
	    *
	   ***
	  *****
	 *******
    *********

for(i = 0; i < 5; i++)//控制行数
{
	//打印空格
	for(j = 0; j < 5-1-i ; j++)
	{
		printf(" ");
	}
	//打印星星
	for(j = 0; j < 2*i+1; j++)
	{
		printf("*");
	}
	printf("\n");//换行符
}


分析： i = 0 第一排1个*, 4 个空格
       i = 12* 第二排3个*, 3 个空格 
	   i = 2 第三排5个*, 2 个空格 
	   i = 3 第四排7个*, 1 个空格 
	   i = 4 第三排9个*, 0 个空格 
	   
#include <stdio.h>
int main()
{ 
	int i,j;
	int n;//代表函数
	printf("Please input line:\n");
	scanf("%d",&n);
	for(i = 0; i < n; i++)//控制行数
	{
		//打印空格
		for(j = 0; j < n-1-i ; j++)
		{
			printf(" ");
		}
		//打印星星
		for(j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");//换行符
	}
	return 0;
}

/////////////////////

gedit hello.c 

ctrl + q //退出选择save