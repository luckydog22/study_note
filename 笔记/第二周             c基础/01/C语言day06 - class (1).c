##复习：二维数组和随机数

int a[3][4]= {{1},{2,3},{45,6,8}};

//定义二维数组的时候，列数不能省略，代表一维数组的元素个数


int a[][5] = {{1,2},{45,7}};

srand(time(0));//初始化随机种子
int num = rand();//得到随机数


1. 函数(通常用来完成某一个特定的功能的一段代码，把这段代码放到一起，形成一个函数)

	1.1 系统函数(操作系统给我们写好了，我们会调用就行)
	
		printf
		rand
		strlen
		atoi //能够将数字字符串转换为整数

	1.2 自定义函数(自己写的函数)

		举例
		  *
		 ***
		*****
		  *
		 ***
		*****
		  *
		 ***
		*****
		  *
		 ***
		*****
		  *
		 ***
		*****
		
		#include <stdio.h>

		//函数：先定义，后使用
		//函数定义
		void printStar()//void代表无返回值，函数内不需要写return <表达式> printStar函数名 ()表示函数
		{//函数体
			int i,j;
			for(i = 0; i < 3; i++)//控制函数
			{
				//打印空格
				for(j = 0; j < 3-1-i; j++)
				{
					printf(" ");
				}
				//打印星星
				for(j = 0; j < 2*i+1; j++)
				{
					printf("*");
				}
				printf("\n");
			}
			//函数执行结束后，跳回到函数调用处
		}

		int main(int argc, const char *argv[])
		{
			printStar();//函数调用,需要加;号,跳转到函数的定义处去执行
			printStar();//函数调用
			printStar();//函数调用
			printStar();//函数调用
			return 0;
		}
	
		函数的执行是跳转到函数处，执行完再跳转回来

		函数名：什么名都可以，
		
		(1) 不能以数字开头 
		(2) 除了'_', 不能有任何其他字符
		(3) 函数名尽量清晰表达出函数的含义   
		(4) 如果有多个单词，尽量能用符号标识

		函数一般都要先定义，然后再调用（函数写在调用者的上面）

	1.3 带参函数和返回值
	
	
		int len = strlen(a)   //a 是参数

		参数？     传递给函数的一个值
		
		
#include <stdio.h>

//函数：先定义，后使用
//函数定义
void printStar(int n)//void代表无返回值，函数内不需要写return <表达式> printStar函数名 ()表示函数,int n函数参数，形参列表
{//函数体
	int i,j;
	for(i = 0; i < n; i++)//控制函数
	{
		//打印空格
		for(j = 0; j < n-1-i; j++)
		{
			printf(" ");
		}
		//打印星星
		for(j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//函数执行结束后，跳回到函数调用处
}

int main(int argc, const char *argv[])
{
	int line;
	scanf("%d",&line);
	printStar(line);//函数调用,跳转到函数的定义处去执行,(10)实参列表,
	//函数调用的时候，实参初始化形参,相当于将10赋值给---> 形参的n
	return 0;
}

		举例
		求两个数之间的较大值
		
		3    5
		
		例 1 不使用参数
		
		#include <stdio.h>
		void max()
		{
			int a = 5, b = 9;
			if(a > b)
			{
				printf("max is %d\n", a);
			}
			else
			{
				printf("max is %d\n", b);
			}
		}
		int main()
		{
			max();
		}
		
		///这样做, 改成使用参数
		
		
		设计函数min(x,y),返回两个double数值中较小的数值，同时用一个简单的main测试该函数。
			
		#include <stdio.h>
		int max(int a, int b)	//a, b是参数，又叫形参, max 前面 int 表示函数有一个int型返回值
		{
			if(a > b)
			{
				return a;	//return 后面的值，会给调用者(main),一旦执行return,当前函数接结束
			}
			else
			{
				return b;
			}
		}
		int main()
		{
			max(5,9);
			int x = max(5, 9);	//5, 9 是参数，叫实参，函数调用时，会用实参值，初始化形参 5 - > a,  9 - > b
			printf("max is %d\n", x);
		}
		//参数是调用者传递给函数的值
		//返回值是函数传递给调用者的值

		函数使用时注意：
		1 调用时函数参数个数必须与定义一致
		2 返回值类型必须与定义一致

		举例
		
		

		/////输出杨辉三角型
		1
		1 1
		1 2 1
		1 3 3 1
		1 4 6 4 1
		//写一个函数，输出阶数不固定的杨辉三角形，输出的阶数，由参数传递进来



		##练习1
		
		写一个求一个数的n次方的函数
			然后在main中测试(在main调用)
			
				
		#include <stdio.h>

		int num_n(int num, int n)// 2,3
		{
			int result = 1;
			int i;
			for(i = 0; i < n; i++)
			{
				result *= num;
			}
			return result;
		}

		int main(int argc, const char *argv[])
		{
			int a,b;
			printf("请您输入数 n次方:\n");
			scanf("%d%d",&a,&b);
			int num = num_n(a,b);
			printf("num is %d\n",num);
			return 0;
		}

		##练习2
		
		写一个函数，比较三个数，然后求出最大值
		
		
		#include <stdio.h>

		int getMax(int a,int b,int c)
		{
			a = a > b ? a : b;
			a = a > c ? a : c;
			return a;
		}


		int main(int argc, const char *argv[])
		{
			printf("max is %d\n",getMax(1,2,3)); //可以直接打印，getMax(1,2,3)相当于表达式
			int max = getMax(1,2,3);
			printf("max is %d\n",max);
			return 0;
		}
		
		##练习3
		
		设计函数min(x,y),返回两个double数值中较小的数值，同时用一个简单的main测试该

		#include <stdio.h>
		double min(double a, double b)
		{
			return a < b ? a : b;		//可以直接return 表达式
		}

		int main()
		{
			//方法一
			double get_min = min(3.14,2.34);
			printf("min is %lf\n",get_min);
			
			//方法二
			printf("min is %lf\n", min(3.14, 1.2));	
		}
	
	
	1.4 函数总结
	
		(1)函数名, 要清晰表达出函数的含义
		
			代码通常是多人合作，一定要让别人能看懂自己写的代码

		(2)函数名不要简写(程序写出来尽量能让别人看懂)
		
			set_student_name()

		(3)函数名两种不同风格写法
		
			SetStudentName       windows风格 (第一个单词)
			set_student_name     linux  风格 (单词中间加_)
			setStudentName       ios    风格


		(4)函数参数
		  get_max(int x, int y, int z,);   //尽量不要太多，不要多于5个
										  //如果参数多，影响程序的可读性

		  函数调用时参数个数与定义时参数个数要一致
		  get_max(30, 40, 50);    //参数调用时参数个数要与定义的一致

		  如果函数没有参数
		  void print_star(void)//()内的void代表无参数的意思


		(5)函数返回值可有可无，如果有返回值，那么函数里一定要有return 0;
		
		  int max(int a, int b)	
		  {
			return 1;
		  }
		  
		  //一个函数只能返回一个值
		  void print_star();    //void表示函数无返回值，函数中return 表示函数结束，如果返回值是void , return
			 函数只要执行到return , 函数就结束
			return > break > continue

		(6)函数功能尽量单一
		  一般如果功能不单一，那么函数就要拆分

		(7)函数行数不要太多(尽量1页能显示下)


2. 指针
	
	2.1 什么是指针
	
		又称为指针变量，是c语言， c++, objective c 特有的， 指针用好了非常方便，如果用不好，也会造成不好的后果
		
		内存单元地址(编号) 被称为指针（指针变量通常也叫指针）
		

		内存
		
		计算的程序都是在内存中执行的，每个内存都有一个地址，地址是32位，4字节

		如果定义一个变量保存  a的地址，就用指针变量
		int a = 10;
		int *p;		//定义指针变量, int *是一个整体
		p = &a;


	2.2 指针定义(用来保存一个地址的变量，叫指针变量)
	
	   1) 指针也是一个变量(可以保存信息)
	   2) 指针保存的是一个地址
	   
		(1)定义一个指针变量
		
			int *p;		//定义指针变量

		(2)指针赋值
		
			p = &a;

		(3)如何通过指针变量p访问变量a
		
			*p = 20;   //===> a = 20;


	2.3 变量的赋值
	
		在c语言里，获取变量的值有两种方式
		
		 int a = 10;
		 
		(1)直接赋值，直接给某个变量赋值
		
			 a = 20;
			 
		(2)间接赋值， 先取出某个变量的地址，然后到那个地址去赋值
			
			 int *p = &a;   <====>  int *p;  p = &a;
			 *p = 20;    //分为两步1  取出p的值，就是a的地址   2  到那个地址去赋值(20)

		举例：
		#include <stdio.h>
		int main()
		{
			int a = 10;
			int *p;		//* 指针定义运算符
			p = &a;
			printf("a %d, *p %d\n", a, *p); //此时*p中的*代表取值的意思
			printf("p %p, &a %p\n", p, &a); //打印地址用%p
			*p = 20;	//* 取内容运算符，通过指针变量间接修改变量的值
			printf("a %d, *p %d\n", a, *p);
		}

		##练习  
		//定义一个浮点型变量     x = 1.1
		//定义一个浮点型指针变量 q
		//把浮点型变量x地址赋值给 q
		//通过q改变x的值  3.14

		//打印x, *q
		#include <stdio.h>
		int main()
		{
			float x = 1.1;
			float *q;
			q = &x;
			*q = 3.14;
			printf("x %.2f, *q %.2f\n", x, *q);
		}

		###总结： 指针就是一个变量(变量里面保存的是一个地址(int float double))
		###       有了指针变量我们就可以利用地址来访问它指向的变量


	2.4 指针变量初始化
	
		int a = 10;
		int *p = &a;		//定义指针变量时，直接初始化， 相当于int *p;   p = &a;


	2.5 指针和数组
	
		怎么定义指针变量，指向一个数组
		int a[5] = {1,2,3,4,5};
		int *p;
		p = a;		//不加&,  因为a是数组名，就是数组首地址
		*(p + 0)      <===> a[0];
		*(p + 1) <===> a[1];
		*(p + 2) <===> a[2];
		*(p + 3) <===> a[3];
		*(p + 4) <===> a[4];

		举例子通过指针访问数组
		
		直接访问
		#include <stdio.h>
		int main()
		{
			int a[5] = {1,2,3,4,5};
			int *p = a;
			printf("%d %d %d %d %d\n", *p, *(p + 1), *(p + 2), 
					*(p + 3), *(p + 4));	
		}
		
		循环方式
		
		#include <stdio.h>
		int main()
		{
			int i;
			int a[5] = {1,2,3,4,5};
			int *p = a;
			for(i = 0; i < 5; i++)
			{
				printf("%d\n", *(p + i));
			}
		}


		##练习4：用指针，求学生成绩和，平均值并打印，学生成绩放到一个数组中
		
		int a[] = {90, 80, 70, 60, 75, 87, 89, 92};
	
		#include <stdio.h>
		int main()
		{
			int a[] = {90, 80, 70, 60, 75, 87, 89, 92};
			int i, sum = 0;
			int *p = a;
			for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
			{
				sum += *(p + i); 	//sum += a[i];
			}
			printf("sum is %d, avg is %d\n", sum, sum / 8);
		}
	
	2.6 指针和函数

		可以将数组传递给一个函数，如果将数组传递给函数,通常传递数组名, 函数用指针接收
		实现一个函数，打印数组中所有元素
		int a[5]
		
		a ==== &a[0]
	
		####代码演示 
		
		#include <stdio.h>
		
		void print_all(int *p, int n)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				printf("%d\n", *(p + i));
			}
		}
		int main()
		{
			int a[] = {90, 80, 70, 60, 75, 87, 89, 92};
			print_all(a, sizeof(a) / sizeof(a[0])); //数组总大小/单个元素的大小 === 元素的个数
		}

	//函数使用指针接收数组
	
	
		##练习5：写一个函数求5个学生的平均成绩(在函数中求学生平均成绩, 在主程序中打印)
		
		#include <stdio.h>
		
		int get_avg(int *p, int n)
		{
			int i, sum = 0;
			for(i = 0; i < n; i++)
			{
				sum += *(p + i);
			}
			return sum / n;
		}

		int main()
		{	
		
			int a[] = {90, 80, 70, 60, 75, 87, 89, 92};
			int x = get_avg(a, sizeof(a) / sizeof(a[0]));
			printf("avg is %d\n", x);
		}

		##练习6：写一函数my_strlen，求一个字符串的长度，然后写个main函数测
		
		
		#include <stdio.h>

		int my_strlen(char *p)
		{
			int i = 0; 
		//	while(*(p+i) != '\0')//*(p+i) ==== a[i] ===== p[i]
			while(p[i] != '\0')
			{
				i++;
			}
			return i;
		}


		int main(int argc, const char *argv[])
		{
			char a[] = "hello";
			int len = my_strlen(a);

			printf("len is %d\n",len);
			return 0;
		}
				
		
		##练习7： 编写一个函数，将数组中n个数按反顺序存放
		
			int a[] = {1,2,3,4,5,6,7,8};
			//a[0] ---- a[7]
			//a[1] ---- a[6]
			//a[2] ---- a[5]
			//a[3] ---- a[4]
			
			#include <stdio.h>

			void reverse(int *p, int n)
			{
				int i;
				int temp;
				for(i = 0; i < n/2; i++)
				{
					temp = *(p+i);
					*(p+i) = *(p+(n-1-i));
					*(p+(n-1-i)) = temp;
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
				int a[] = {1,2,3,4,5,6,7,8};
				printArray(a,sizeof(a)/sizeof(a[0]));
				reverse(a,sizeof(a)/sizeof(a[0]));//函数调用，已经实现数组转置
				printArray(a,sizeof(a)/sizeof(a[0]));
				return 0;
			}			
						
			
			
		
		##练习8：/////输出杨辉三角型
		
		1 0 0 0 0
		1 1 0 0 0
		1 2 1 0 0
		1 3 3 1 0
		1 4 6 4 1
		
		
		
	
	#include <stdio.h>

	void printYangHui(int n)
	{
		int a[1000][1000] = { 0 };
		int i,j;
		for(i = 0; i < n; i++)
		{
			a[i][0] = 1;//将每一行的第一个元素置为1
			for(j = 0; j <= i; j++)
			{
				if(j == 0 || i == 0)////如果是第一行或者第一列，不执行下面的计算公式,当i或j等于0的时候-1,会出现数组越界，没有-1这个下标
				{
					printf("%3d ",a[i][j]);
					continue;//如果是第一行或者第一列，不执行下面的计算公式,当i或j等于0的时候-1,会出现数组越界，没有-1这个下标
				}
				a[i][j] = a[i-1][j] + a[i-1][j-1];
				printf("%3d ",a[i][j]);
			}
			printf("\n");
		}
	}


	int main(int argc, const char *argv[])
	{
		printYangHui(7);
		return 0;
	}	
	
		
				
		##练习9：
		
		写一个函数，打印
			*
		   ***
		  *****
		 *******
		*********
		阶数可由参数传递
		5 阶
		空格个数是第一次  4， 第二次 3，     n - i - 1
		* 个数    2 * i + 1
		
		
		#include <stdio.h>
		
		void print_star(int n)
		{
			int i = 0, j = 0;

			for(i = 0; i < n; i++)
			{
				for(j = 0; j < n - i - 1; j++)
				{
					printf(" ");   //先打印空格
				}
				for(j = 0; j < 2 * i + 1; j++)
				{
					printf("*");   //打印*
				}
				printf("\n");
			}
		}
		int main()
		{
			print_star(5);
		}





作业：1 写一个函数，能将数组里所有元素输出,要求用 p[i]和*(p+i)实现

	int a[5] = {90, 80, 70, 60, 50};

	//见转置数组



作业：2 字符串拷贝   mystrcpy(char *dst, char *src);

int main()
{
	char a[] = "hello"; //'\0' 位置对应的下标就是字符串的长度	
	char b[100] = { 0 };
	mystrcpy(b, a);
	///输出b
}


#include <stdio.h>

void my_strcpy(char *dst, char *src)
{
	//方法一
	/*
	int i = 0;
	while(*(src+i) != '\0')
	{
		*(dst+i) = *(src+i);
		i++;
	}
	*(dst+i) = '\0';
	*/
	//方法二
	while(*dst++ = *src++);//先取值赋值运算，再指针自加，向后移动一个位置，指向下一个字符, 循环的结束条件是最后一次将'\0'赋值后，循环结束
}


int main(int argc, const char *argv[])
{
	char a[100];
	char b[] = "hello world";
	puts(a);
	my_strcpy(a,b);
	printf("11111111111\n");
	printf("%s\n",a);
	return 0;
}

/////////////////////////////////////////////////////////////////

int main(int argc, const char *argv[])
{
	char a[100];
	char b[] = "hello world";
	int i = 0;
	int j = 0;
//	while(a[i]=b[i++]); 
	while(a[j++] = b[i++]);
	puts(a);
	return 0;
}

