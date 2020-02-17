#复习：

do
{
	//循环体执行的语句
}while(条件);//注意一定要有;

do-while循环至少循环一次，先执行循环体，后进行条件判断

一维数组 

int a[5]; //sizeof(a) ===> 20
a[5] = {1,2,3,4,5};//错误

//完全初始化

int a[5] = {1,2,3,4,5};

//部分初始化
int a[5] = {1,3};//后面没赋值的位置被0填充

//省略元素个数，自动计算

int a[] = {12,3};

//数组是有固定长度的 

///////////////////////////
int a = 5;

a = 5;


int n;
scanf("%d",&n);
int a[n]; //错误 [常量]

float b[5];
char c[5]; //sizeof(c) ===> 5

1.数组名就是数组在内存当中存储的首地址

2.数组在内存当中存储，是连续的 

3.数组的起始下标是0，终止下标元素个数N-1个

////冒泡排序 


int a[10] = { 0 };
for(i = 0; i < 10-1; i++)
{
	for(j = 0; j < 10-1-i; j++)
	{
		if(a[j] > a[j+1])
		{
			temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
			//
			a[j] = a[j] - a[j+1];//a[j]保存二者的差值
			a[j+1] = a[j+1] + a[j];//a[j+1] + 差值  == a[j]
			a[j] = a[j+1] - a[j];// - 差值
		}
	}

}
////////////
字符 '' 

字符串 " " 

字符串常量

char a[100] = "hello";//sizeof(a) ---> 100 因为数组的长度为100
char b[] = "hello"; //sizeof(b) ---> 6 字符串以'\0'结尾
char c[] = {'h','e','l','l','o'}; //sizeof(c)---> 5

字符串处理函数

//求字符串的长度函数
char a[] = "hello";

printf("len is %d\n",strlen(a)); //---->5 求字符串的长度不包含'\0'

//字符串拷贝函数

char a[100];
char b[100] = "hello"; //{'h','e','l','l','o','\0','\0','\0','\0'......}；
				

strcpy(a,b);//将b拷贝a中，注意 a一定要足够大

//字符串连接函数

char a[100] = "world";
char b[] = "hello"

strcat(a,b);// 将b连接到a的后面

///////////////////////////////////////

int i = 0;
char a[] = "hello";
while(a[i] != '\0' )
{
	
	continue;//会造成死循环，因为结束本次循环 i++不执行
	i++;//没有被执行
	
}



1. 二维数组(存储矩阵)
	
	1.1 二维数组举例 
	
		0  1  2  3
		
	0	1  2  3  4
	1	5  6  7  8
	2	9 10 11 12

		上面的数有3行4列，  可以用二维数组来保存
		
		int a[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
		
		a[0][0]   -->   1    //第一行第一列
		a[0][1]   -->   2    //第一行第二列
		a[0][2]   -->   3
		a[1][0]   -->   5    //第二行第一列
		a[3][4]     //第四行第五列， 不存在

		//数组用循环赋值


	1.2 如何输出二维数组所有元素
		
		##代码演示
		
		#include <stdio.h>
		int main()
		{
			int a[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
			int i, j;
			for(i = 0; i < 3; i++)//0 1 2
			{ 
				for(j = 0; j < 4; j++)// 0 1 2 3
				{
					printf("%3d ", a[i][j]);
				}
				printf("\n");//换行
			}
		}

		##练习1 
		
			输入一个数，查询该数在二维数组当中是否存在该数，如果存在计算有多少个这样的数
			
			int a[3][4] = {{1,2,3,4}, {5,6,7,3}, {9,3,11,12}};
		
		
		#include <stdio.h>

		int main()
		{
			int num;//用来保存输入的数
			int count = 0;//用来保存出现的次数,计数器
			int a[3][4] = {{1,2,3,4},{4,5,6,7},{8,9,10,11}};
			int i,j;
			scanf("%d",&num);
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 4; j++)
				{
					if(num == a[i][j])
					{
						//次数+1
						count++;
					}
				}
			}
			printf("%d出现的次数是%d\n",num,count);
			return 0;
		}
		

		##练习2 求两个矩阵之和放在第三个矩阵中 (3行4列)，第三个矩阵也是三行四列

		int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
		int b[3][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3}};
		int c[3][4];

		#include <stdio.h>
		int main()
		{
			int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
			int b[3][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3}};
			int c[3][4];
			int i, j;
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 4; j++)
				{
					c[i][j] = a[i][j] + b[i][j];
					printf("%3d ", c[i][j]);
				}
				printf("\n");
			}
		}
		
		##练习3. 输出杨辉三角形 输出10阶即可
		
		1  0  0  0  0  0  0
		1  1  0  0  0  0  0 
		1  2  1  0  0  0  0
		1  3  3  1  0  0  0
		1  4  6  4  1  0  0
		1  5  10 10 5  1  0
		1  6  15 20 15 6  1
		
		a[i][j] = a[i-1][j] + a[i-1][j-1];
		
		i = 1    1
		i = 2    2
		i = 3    3
		*
		**
		***
		****
		*****
		******

		#include <stdio.h>

		int main()
		{
			//1.让第一列全为１，其他位置全为0
			int a[7][7] = {{1},{1},{1},{1},{1},{1},{1}};//部分初始化
			int i,j;
			//2.按照规律，得到杨辉三角形
			for(i = 1; i < 7; i++)
			{
				for(j = 1; j <= i; j++)
				{
					a[i][j] = a[i-1][j] + a[i-1][j-1];
				}
			}
			//3.打印输出杨辉三角形
			for(i = 0; i < 7; i++)
			{
				for(j = 0; j < 7; j++)
				{
					if(a[i][j] != 0)
					{
							printf("%3d ",a[i][j]);
					}
				}
				printf("\n");
			}

			return 0;
		}








		

	1.3 二维数组的初始化
	
		一维数组
		
		int a[5] = {1,2};
		
		(1)完全初始化
		
		int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
		
		(2)部分初始化 (没赋初值，默认为0)
		
		int a[3][4] = {{1,2},{5},{9,10,11}};
		1 2 0 0 //把一个一维数组看成一个元素
		5 0 0 0
		9 10 11 0
		
		a[0][0] --> 1
		a[0][1] --> 2
		a[0][2] --> 0
		a[1][0] --> 5
		a[1][1] --> 0
		
		(3)默认初始化(行数可以省略，但列数不可以省略)
		int a[3][] = { 0 };//错误的，二维数组的列数不可以省略
		int a[][4] = {{1,2},{5},{9,10,11}};
		int a[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};


		##练习3. 输出杨辉三角形 输出10阶即可
		
		1  0  0  0  0  0  0
		1  1  0  0  0  0  0 
		1  2  1  0  0  0  0
		1  3  3  1  0  0  0
		1  4  6  4  1  0  0
		1  5  10 10 5  1  0
		1  6  15 20 15 6  1
		
		a[i][j] = a[i-1][j] + a[i-1][j-1];
		
		
		
		
		
		#include <stdio.h>
		int main()
		{
			int a[10][10] = {{1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}};
			int i, j;
			for(i = 1; i < 10; i++)
			{	
				for(j = 1; j < 10; j++)
				{
					a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
				}
			}
			for(i = 0; i < 10; i++)
			{	
				for(j = 0; j < 10; j++)
				{
					if(a[i][j] != 0)
					{
						printf("%5d", a[i][j]);
					}
				}
				printf("\n");
			}
		}


2. 随机数 

	2.1 如何产生随机数
		
		####代码演示 
		
		#include <stdio.h>
		int main()
		{
			while(1)
			{
				int a = rand() % 35 + 1; //rand 能产生一个随机数
				printf("a is %d\n", a);
				getchar();		//等待按任意键
			}
		}

		上面的程序并不是真的随机数

		#include <stdio.h>
		int main()
		{
			int a;
			scanf("%d", &a);
			srand(a);	//srand 能给rand函数产生一个随机种子，rand用此种子生成新随机数
			while(1)
			{
				a = rand() % 35 + 1; //rand 能产生一个随机数
				printf("a is %d\n", a);
				getchar();		//等待按任意键
			}
		}
		//随机种子应该是一个预想不到的值
		#include <stdio.h>
		int main()
		{
			while(1)
			{
				int t = time(NULL);	//从1970-1-1 0:0:0 到现在经过的秒值
				printf("t is %d\n", t);
				getchar();		//等待按任意键
			}
		}

		#include <stdio.h>
		int main()
		{
			int t = time(NULL);
			srand(t);	//srand 能给rand函数产生一个随机种子，rand用此种子生成新随机数
			while(1)
			{
				int a = rand() % 35 + 1; //rand 能产生一个随机数
				printf("a is %d\n", a);
				getchar();		//等待按任意键
			}
		}


	2.2 随机生成一个1 - 10的数，让对方猜5次，如果猜对了，提示"congratulations !!"

		如果猜错了，提示"bigger" 或 "smaller"

	#include <stdio.h>
	int main()
	{
		int a, b, i;
		srand(time(NULL));
		a = rand() % 10 + 1;
		for(i = 0; i < 5; i++)
		{
			printf("please input number:");
			scanf("%d", &b);
			if(b == a)
			{
				printf("congratulations !!\n");
				break;
			}
			else if(b > a)
			{
				printf("bigger\n");
			}
			else
			{
				printf("smaller\n");
			}
		}
	}
	
	
	
	2.3 中国福利彩票35选7
	
		随机生成1-35内不重复的7个数字
		然后让用户选择自己的一组号码
		中奖规则：猜中
		
		7个500万
		6个100万
		5个1万
		4个5000
		3个500
		0，1，2个没中奖
		
	//1. 生成7个中奖号码 int lotteryNum[7]//注意生成7个中奖号码，有可能重复, 中奖号检测去重
	//2. 输入7个数，买彩票 int myMum[7];
	//3. 统计中奖个数
	//4. 打印输出中奖信息
	
	
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int lotteryNum[7];//用来保存随机产生的中奖号码
	int myNum[7];//用来保存自己购买的中奖号码
	int i,j;
	int count = 0;//用来统计中奖号码个数
	srand(time(NULL));//初始化随机种子
	//1.随机产生７个中奖号码
	for(i = 0; i < 7; i++)
	{
		lotteryNum[i] = rand() % 35 + 1;
		//对当前号码与之前生成的每一个号码进行比较，判断是否出现重复
		for(j = 0; j < i; j++)
		{//lotteryNum[i]代表刚产生的随机数
			if(lotteryNum[i] == lotteryNum[j])//说明出现重复
			{
				i--;//在当前位置，再次重新生成
				break;
			}
		}
	}
	//2.输入７个购买的号码
	for(i = 0 ; i < 7; i++)
	{
		printf("请您输入第%d个中奖号码\n",i+1);
		scanf("%d",&myNum[i]);
	}
	//3.统计中奖个数
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 7; j++)
		{
			if(lotteryNum[i] == myNum[j])
			{
				count++;
			}
		}
	}
	//4.打印中奖信息
	switch(count)
	{
		case 7:
			printf("500W!!\n");
			break;
		case 6:
			printf("100W!!\n");
			break;
		case 5:
			printf("50W!!\n");
			break;
		case 4:
			printf("5W!!\n");
			break;
		case 3:
			printf("5000!!\n");
			break;
		default:
			printf("重在参与！！\n");

	}
	////此循环用于调试程序，提高中奖率
	for(i = 0; i < 7; i++)
	{
		printf("%d ",lotteryNum[i]);
	}
	printf("\n");
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

作业1：

	小型计算器 用 if-else if-else做

	int a;   //第一个数
	char b;  //符号
	int c;   //第二个数        
	scanf("%d%c%d", &a, &b, &c);  //100+200   //100->a   + -> b 200->c
	if(b == '+')
	{
		
	} 

作业2：

	编写一个程序，输出100~199的全部素数。
	
	for(i = 100; i < 200; i++)
	{
		for(j = 2; j < i; j++)
		{
			if(i % j == 0)//说明不是质数
			{
				break;//执行过break，循环结束 i != j
			}
		}
		//判断是否是自然结束
		if(i == j)//说明为自然结束,没有执行过break,说明为质数
		{
			printf("%d\n",i);
		}
	}


作业3：

	实现字符串拷贝
	char a[100] = { 0 };
	char b[] = "hello";

	不用strcpy(),实现将b中的字符拷贝到a中
	
	字符串处理函数:
	int i = 0;
	while(b[i] != '\0')
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';//注意此处一定要将'\0'复制过去
	
	////////////////////////////////////////////////

		int len = strlen(a)//求字符串长度 ,不包括'\0'
		strcpy(a,b);//将b拷贝到a中 
		strcat(a,b);//将b连接到a的后面

作业4：输入一个字符串，转换为数字 1234

	//	"1234" --> int 1234
	//	'4' - '0' = 4
	//	'0' '1' '2' ... '9'
	int sum = 0
	sum = sum * 10 + ('1'-'0'); // 1
	sum = sum * 10 + ('2'-'0'); // 12
	sum = sum * 10 + ('3'-'0'); // 123
	sum = sum * 10 + ('4'-'0'); // 1234
	
	1 = 0 * 10 + 1
	12 = 1 * 10 + 2
	123 = 12 * 10 + 3
	1234 = 123 * 10 + 4
	
#include <stdio.h>
int main(int argc, const char *argv[])
{
	char a[] = "2345";
	int num = atoi(a);//将数字字符串转换成整数
	printf("num is %d\n",num);
	return 0;
}	
	
	
#include <stdio.h>
int main(int argc, const char *argv[])
{
	char a[100] = { 0 };
	int sum = 0;
	int i = 0;
	printf("请输入一个数字字符串:\n");
	gets(a);
	//scanf("%s",a);//不加&
	while(a[i] != '\0')
	{
		sum = sum * 10 + (a[i]-'0');
		i++;
	}
	printf("num is %d\n",sum);
	return 0;
}

作业5：判断一个字符串中是否存在某个子串
	//  string1 "ftgfdajkfdaskldajkmli"
	//	string2 "dajk"
#include <stdio.h>

int main()
{	
	char a[] = "ftgfdajkfdaskldajkmli";
	char b[] = "dajk"; // 
	int i = 0;
	int j;
	while(a[i] != '\0')
	{
		j = 0;
		while(b[j] != '\0')
		{
			if(b[j] != a[j+i])
			{
				break;//说明遇到了不相等的字符
			}
			j++;
		}
		//如果内循环是自然结束，结束时b[j] == '\0'
		if(b[j] == '\0')//证明没有遇见过不相等的字符，直到遇见'\0'结束,包含子字符串
		{
			printf("存在！！\n");
		}
		i++;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////

#####
#####
#####

int i = 0;
int j = 0;
while(i < 3)
{
	//错误，只会打印五个# ，应该在此处 j = 0;
	while(j < 5)
	{ 
		printf("#");
		j++;
	}
	printf("\n");
	i++;
}


for(i = 0; i < 3; i++)
{
	for(j = 0; j < 5; j++)
	{
		printf("#");
	}
}


