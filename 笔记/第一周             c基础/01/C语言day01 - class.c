1.1  C语言简介

	C语言是世界上最流行、使用最广泛的高级程序设计语言之一，广泛用于系统与应用软件的开发。
	
	具备很强的数据处理能力、高效、灵活、功能丰富、表达力强和较高的移植性等特点
	
----------------------------------------------------------------------------------------------------------------------------------------------------

1.2  编程语言(*)

	c、java、c++、C#、objective-c
	
	C:    嵌入式(设备开发)、系统及开发（速度快）
	
	java: android应用开发(微信、支付宝、美团)、web开发(电信收费系统、企业管理系统)
	
	C++:  导航系统、CAD、3DMAX（软件速度快）
	
	C#:   windows平台应用软件(容易学，但需求越来越少)objective-c 苹果电脑、苹果手机上的开发语言(从2015年开始，需求越来越少)
	
----------------------------------------------------------------------------------------------------------------------------------------------------

1.3  C语言开发环境(*)

	vmware: 虚拟机，能用软件虚拟出硬件(cpu、内存、网卡、声卡、usb....)
	
        	在此硬件基础上再安装一个新操作系统
			
	vmware：上可以安装windows, linux, unix(等操作系统)
	
	
	
----------------------------------------------------------------------------------------------------------------------------------------------------
//ls list缩写 查看当前目录中的文件内容

//蓝色 目录文件（文件夹子）

//白色 普通文本文件


//1. vim hello.c //vim是一个命令 是编辑器 用vim编辑器打开文件hello.c 如果文件不存在，创建并打开，如果文件存在，直接打开 ----》vim编辑器处于一般模式

//2. 输入i 屏幕的左下角出现 INSERT ，此时vim编辑器处于编辑模式

//3. esc ,此时INSERT消失，vim编辑器由编辑模式---》切换到一般模式

//4. space(空格键) 或 shift + ; 此时屏幕的左下角出现 : --->vim编辑器处于尾行模式（命令行模式）  :wq  ---> w 保存  q 退出

//5. gcc hello.c //gcc是一个编译器，生成的产物是绿色的 a.out 可执行文件

//6. 执行程序   ./a.out   ----> . 当前目录  /路径分隔符

1.4 打印输出 hello world
	
	##代码演示
	
	
	讲解hello.c
	#include <stdio.h>		//包含头文件，stdio.h--->一个头文件,扩展名.h
					//为什么要包含，printf 函数需要
	int main()			//main函数， c程序从main开始执行
	{				// { 一段代码的开始

		printf("hello world\n");//printf 打印输出， "  " 里面的内容会直接输出到终端  '\n' 换行符

		return 0;                  //  函数结束  并返回 一个值（和函数名 前面的类型相同）
	}				// } 一段代码的结束

		 
		

		
	////////////////////////////////////////////////		 
	#######  练习 1 输出 I am a student!
	////////////////////////////////////////////////
	
	#include <stdio.h>

	int main()
	{
		printf(" I am a student!!\n");
		return 0;
	}

	//新建一个文件，打印输出I am a student!
	
	vim student.c 


1.5 注释（通常用于两种情况）（**）


	(1)代码的解释部分
	
		// 

	(2)代码现在不需要的部分	
	
	
		/*

		*/ 代表注释掉一段代码		
	
		#include <stdio.h>

		//create by fengli

		int main()
		{
			printf(" I am a student!!\n");
			/*
			printf(" I am a student!!\n");
			printf(" I am a student!!\n");
			printf(" I am a student!!\n");
			printf(" I am a student!!\n");
			printf(" I am a student!!\n");
			printf(" I am a student!!\n");
			printf(" I am a student!!\n");
			printf(" I am a student!!\n");
			*/
			return 0;
		}

	
	#######  练习 2 输出
	
	
		  *
		 ***
		*****

#include <stdio.h>

int main(int argc, const char *argv[])
{
	//方法一
	printf("  *\n");
	printf(" ***\n");
	printf("*****\n");
	//方法二
	printf("  *\n ***\n*****\n");
	return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------

1.6 数据的存储与运算
	
	
	////c语言中可以定义变量
	整形变量
	int a;   //定义一个变量， 名为a, 类型是int(int 表示整型， 保存整数100 -1  0  1 -100 -100000)
	a = 100;
	a = -100;
	
	###代码演示变量的定义和使用
	
	变量定义及输出
	
	#include <stdio.h>
	int main()
	{
		int a; //定义一个整型变量a 
		a = 100;"a is %d\n" // = 赋值 
		printf(, a);	//第一个%d, 会用，后的第一个变量值替换
	}
	
	
	如果想保存小数(浮点型变量)
	
	
	float b;   //定义一个单精度浮点型变量，可以保存小数  
	
	//代码演示
	#include <stdio.h>
	int main()
	{
		float b = 1.02;//初始化
		printf("b is %f\n", b); //打印单精度浮点型变量用%f
	}

	#######  练习 3 

	定义一个整型变量x， 定义一个浮点型变量y，
 	将-1赋值给变量x，将3.14赋值给变量y，打印
 	再将1 赋值给变量x，将-3.14赋值给变量y,再打印	
	
	方法1：
	#include <stdio.h>
	int main()
	{
		int x = -1;		//定义时直接初始化
		float y = 3.14;
		printf("x is %d\n", x);
		printf("y is %f\n", y);
		//int x = 1;	//错， 变量不可以重复定义
		x = 1;
		y = -3.14;
		printf("x is %d\n", x);
		printf("y is %f\n", y);	
	}

	方法2：
	#include <stdio.h>
	int main()
	{
		int x = -1;		//定义时直接初始化
		float y = 3.14;
		printf("x is %d, y is %f\n", x, y);
		x = 1;
		y = -3.14;
		printf("x is %d, y is %f\n", x, y);
	}


	输入数据必须放到变量中，输入语句scanf函数
	
	int a;
	scanf("%d", &a);   /////   & 取地址符
	//代码演示-----
	
	#include <stdio.h>
	int main()
	{
		int a;
		scanf("%d", &a);
		printf("a is %d\n", a);
	}
	
	
	
	(1) 变量

	a. 在程序运行过程中其值可以改变的量。
	
	b. 程序中变量是用来存储数据的，可抽象理解为容器。
	
	c. 变量命名规则
	
	标识符：用来标识变量名、符号常量名。函数名 类型名 文件名等有效字符序列
	
		   1)标示符只能由字母 数字 下划线组成 且第一个字符不可以是数字
			   int 3a;//错误的  不能以数组为开头 
			   
			   int student_name;
			   int a3;
			   int a_b_3
			      
		   2)大小写敏感
		   
		   3)用户自定义的标示符尽量见名知义并且不能与关键字同名（关键字见图片）
		      例如 : print_star.c

			

	
		 

##注：定义变量时需先考虑变量用来存储什么类型的数据，即存储什么类型的数据，就定义什么类型的变量。
	
	
	
	数据类型			格式化输入输出类型和格式                占内存空间的大小
	
	char	字符型			%c										1字节
	short	短整型数据		%d										2字节
	int	    整型数据		%d										4字节
	long	长整型数据		%ld										4字节
	float	单精度浮点型（保存小数）%f								4字节
	double	双精度浮点型		%lf									8字节

---------------------------------------------------------------------------------------------------------------------------------------------------		
1.8  数制

 	十进制：   			逢十进一                0    1    2    3     4      
 	二进制：   			逢二进一                000  001  010  011    100
 	八进制(以0开头)：   逢八进一                016    007  010  ...    017    020
 	十六进制(以0x开头)：逢十六进一              0x7a    09  0a  0b  0c  0d  0e 0f  10

 	（***）二转八：      从右至左， 二进制的每三位算八进制的一位
 	（***）二转十六：    从右至左，  二进制的每四位算十六进制的一位。
 
 16 进制
0x11 ---> 17
0xA  ---> 10
0x20 ---> 32
8 进制
010 ----> 8
020 ----> 16
 
 
 7  ---->    
 
 
  
######//  练习4：求0xff 的10进制值，2进制值，   8 进制值



                   		255    11111111     377
			  				  
######//  练习5 : 求128  的2进制，   8 进制，   16 进制

						10000000        0200     0x80 

 
	 a. win+r   运行----> calc 进行验证
	 
	 
----------------------------------------------------------------------------------------------------------------------------------------------------
1.9 运算符

	1.9.1 算数运算符

	(1) +  加法运算符	int a = 3 + 5;  //a = 8;
	(2) -  减法运算符	int b = 3 - 5;  //b = -2;
	(3) *  乘法运算符	int c = 3 * 5;  //c = 15;
	(4) /  除法运算符	int d = 5 / 3;  //d = 1;       （***）
	(5) %  模运算符（求余运算）	int e = 5 % 3;  //e = 2;  （***）求余运算必须是两个整型数据
	
	int a = 3 + 5 * 2;	//a = 13;先乘除，再加减
	int a = (3 + 5) * 2;    //a = 16;
	
	######  练习6：输入三个数，求和，求平均值分别打印

	
	
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a,b,c;
	int sum,avg;
	scanf("%d%d%d",&a,&b,&c);
	sum = a + b + c;
	avg = sum / 3;
	printf("sum is %d\navg is %d\n",sum,avg);
	return 0;
}
	
	
	1.9.2 关系运算符

	(1) <	小于
	(2) <=	小于等于
	(3) >	大于
	(4) >=	大于等于	//(1)(2)(3)(4)优先级相同(高)
	(5) ==	等于
	(6) !=	不等于	//(5)(6)优先级相同(低)

	1.9.3 逻辑运算符

		(1)   && 逻辑与      // (a>b)&&(x>y)
		(2)   ||   逻辑或    // (a>b)||(x>y)
		(3)   !    逻辑非    //  ! (a > b) ###举例：if(!a)
	
	
----------------------------------------------------------------------------------------------------------------------------------------------------	
1.6  选择结构程序设计

	1.6.1  if 条件判断（进一步理解上面关系运算符和逻辑运算符）
	int a = 10;
	if(a == 0)	//a == 0 是条件，分为成立和不成立，如果条件成立，就执行 {   }里面的语句
	{
		//语句 
		printf("a is 0\n");
	}

	
-------代码演示-------
输入一数，判断是否为0


#include <stdio.h>

int main()
{
	int a;
	printf("Please input number:\n");
	scanf("%d",&a);
	if(a == 0)
	{
		printf("a is 0!\n");
	}
	else 
	{
		printf("a is not 0\n");
	}
	return 0;
}

/////讲解当if条件句{ }里只有一行语句时{ }可以省略不写

（1）if—else
if（条件）//如果if条件成立，执行if下面{ }里面的语句1
{
	语句1
}
esle //如果if条件不成立，执行else下面{ }里面的语句2
{
	语句2
}



####### 练习7：


	完成如下功能：
	1 显示: "please input a number:"
	2 用户输入
	3 判断用户输入的数是不是 > 90
	

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int num;
	printf("Please input a number:\n");
	scanf("%d",&num);
	if(num > 90)//当if或else满足条件后，执行的语句只有一条的时候{ }可以省略不写
		printf(" > 90!!\n");
	else
		printf(" <= 90!!\n");
	return 0;
}
	
	
	

(2)if语句嵌套

if（条件1） //如果条件1成立，执行if下面的{ }内的语句，进入后遇到下一个if条件判断
{
	if（条件2）//如果条件2成立，执行条件2下面的语句1
	{
		语句1							
	}
}



####### 练习8：

1 从键盘输入一个数, 判断这个数是不是偶数，如果是偶数，打印此数
  提示：a % 2
  
2 继续，如果是偶数，再判断这个数的一半是不是偶数


#include <stdio.h>

int main(int argc, const char *argv[])
{
	int num;
	printf("Please input a number:\n");
	scanf("%d",&num);
	if(num % 2 == 0)//满足条件证明他是偶数
	{
		printf("%d is even!\n",num);
		if(num/2%2 == 0) //if嵌套，如果是偶数，再判断一半是不是偶数
		{
			printf("%d is even!\n",num/2);
		}
		else
		{
			printf("%d is odd!\n",num/2);
		}
	}
	else
	{
		printf("%d is odd!\n",num);
	}
}


###作业


	1. 判断一个数是否满足条件：
	
		a) 是7的倍数
		b) 不是3的倍数
		如果满足，输出该数
		
		#include <stdio.h>

		int main(int argc, const char *argv[])
		{
			int num;
			scanf("%d",&num);
			if(num % 7 == 0 && num % 3 != 0)
			{
				printf("YES!!\n");
			}
			else
			{
				printf("NO!!\n");
			}
			return 0;
		}
		

		&&   逻辑与， 用在多个条件之间，用来判断多个条件是不是都满足
		判断 a 和 b 是不是都是0   一假即假，同真为真
		#include <stdio.h>

		int main(int argc, const char *argv[])
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(a == 0 && b == 0)  //两个条件同时成立为真
			{
				printf("OK!!\n");
			}
			else
			{
				printf("NO!!\n");
			}
			/*
			if(a == 0)
			{
				if(b == 0)
				{
					printf("满足条件!!\n");
				}
			}
			*/

			return 0;
		}
		
		
		逻辑或
		||   (用来判断多个条件是不是有一个满足)
		输入两个数，判断是不是有一个是0  //一真即真，同假为假
		
		
		#include <stdio.h>

		int main(int argc, const char *argv[])
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(a == 0 || b == 0)  //只要有一个条件成立，就为真
			{
				printf("OK!!\n");
			}
			else
			{
				printf("NO!!\n");
			}

			return 0;
		}
		
		
		!    逻辑非  如果原来为真，取非后变为假，如果原来为假，取非后变为真
		
		 ##### 在C语言中非零即为真

	
		int a = 5;
		int b = 3;
		if(!(a > b)) //a > b条件为真，但加上！后，变成假，所以没有打印输出
		{
			printf("a > b");
		}
		
		
	if(条件)   //( )内是条件，如果条件不成立 为假 0, 条件成立 真 1



	if(0)   //条件不成立， { } 里面永远不执行
	{

	

	if(1)   //条件成立， {  }里面永远执行
	{

	}
	
	
#include <stdio.h>

int main(int argc, const char *argv[])
{
	if(!0) //0代表假，取非!后条件成立，变为真，所以会打印 "########"
	{
		printf("########\n");
	}
	return 0;
}
	

		
	2. 输入一个数，判断是否在10-100之间, 如果是打印Yes，不是打印No	
		
		
		if(10 < a < 100)//错误
		{
			
		}
		
		
#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("%d\n",3 <= 5);
	int a;
	scanf("%d",&a);
	if(10 < a && a < 100)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No!\n");
	}
	return 0;
}
		
		
3. 某一时间的下一秒(笔试编程题)   20      输入三个数，代表小时 分钟 秒
								  59
								  59
								  
						下一秒    21:00:00


	要求，如果用户输入了错误的时间，退出  25点退出，  61秒退出
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int hour,min,sec;
	printf("请您输入小时 分钟 秒:\n");
	scanf("%d%d%d",&hour,&min,&sec);
	if(hour > 23 || min > 59 || sec > 59)
	{
		printf("input error!!\n");
	}
	else //说明输入的数据是合法数据
	{
		sec++;//先秒数＋１
		if(sec == 60)//将自己归０，进１，分钟+1
		{
			sec = 0;
			min++;
			if(min == 60)
			{
				min = 0;
				hour++;
				if(hour == 24)
				{
					hour = 0;
				}
			}
		}
		printf("%02d:%02d:%02d\n",hour,min,sec);
	}

	return 0;
}	
	