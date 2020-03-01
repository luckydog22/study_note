复习：

printf("hello world!!\n");

int a;//定义整型变量，随机数

a = 100;//赋值

int a = 100; //初始化

printf("a is %d\n",a);//格式化输出

//格式化输入 

scanf("%d",&a);

算数运算符  + - * / %

   5 / 2 ---> 5里面有几个2  答案是2 

######重点： 运算符要求必须为两个整数的运算符是 %

> < >= <= == !=

if(条件)//条件成立 为真，才执行{ }里面的语句
{
	语句
}
else //否则 如果if条件不成立，执行else后面{ }的语句
{
	语句
}

八进制数：以0开头 

十六进制：以0x开头 

45   --》 2     8  16  
		101101 055 2D
0x7C --》  2  	  8  10
		1111100 0174 124

一个八进制位，等于三个二进制位

一个十六进制位，等于四个二进制位

2.1.0 sizeof()运算符
	
	sizeof(int)-----> 4
	
	1GB === 1024M
	
	1M === 1024KB
	
	1KB === 1024 byte
	
	1 byte == 8 bit
	
	

	sizeof()作用：求运算对象所占内存空间的大小(以字节为单位)。

	
	运算对象：一种是类型名，一种是变量名
	
	运算结果：整型的值


	----代码测试-----//课后自己验证演练

	定义int, short, long, float,double类型变量，

	然后求出变量占用内存空间大小并打印

	
	#include <stdio.h>

	int main()
	{
		int a = 100;
		float b = 100.4;
		char c;
		double d;
		long int e;
		short int f;
		printf("sizeof(int) is %d sizeof(a) is %d\n",sizeof(int),sizeof(a));
		printf("sizeof(double) is %d sizeof(d) is %d\n",sizeof(double),sizeof(d));
		printf("sizeof(char) is %d sizeof(c) is %d\n",sizeof(char),sizeof(c));
		printf("sizeof(long int) is %d sizeof(e) is %d\n",sizeof(long int),sizeof(e));
		printf("sizeof(short int) is %d sizeof(f) is %d\n",sizeof(short int),sizeof(f));
		return 0;
	}
	
	####输出结果
	
	sizeof(int) is 4 sizeof(a) is 4
	sizeof(double) is 8 sizeof(d) is 8
	sizeof(char) is 1 sizeof(c) is 1
	sizeof(long int) is 4 sizeof(e) is 4
	sizeof(short int) is 2 sizeof(f) is 2


	结论：运算结果的大小，取决于变量的类型，与变量的值毫无关系。


	数据类型			格式化输入输出类型和格式                占内存空间的大小
		
		char	字符型			%c										1字节
		short	短整型数据		%d										2字节
		int	    整型数据		%d										4字节
		long	长整型数据		%ld										4字节
		float	单精度浮点型（保存小数）%f								4字节
		double	双精度浮点型（保存小数）%lf								8字节



2.1.1  数字和字符(**)

	美国国家标准委员会，规定了每一个字符，由一个有效的数字来表示，这个数字就是ascii码

                                  		2进制     16进制     10进制
######练习1： 查找ascii表中 '0'的    	0011 0000     0x30       48               
                     		'a'       	0110 0001     0x61       97
                    		 'A'      	0100 0001     0x41       65        
                    		 ' ' (SP) 	0010 0000     0x20       32   
                     		回车(CR)   0000 1101     0x0D      13   
                     		esc       	0001 1011     0x1B       27

man ascii

c 语言中字符用 ' ' 来表示（**）

数字 1、2、3、4
字符 '1' '2'  '3'  '4'  '#'
        'a' 'A'

'1' = '0' + 1;  48 + 1 == 49
'2' = '0' + 2;
'9' = '0' + 9;

'b' = 'a' + 1;
'c' = 'a' + 2;
.....

'A' = 'B' - 1; 
'C' = 'A' + 2;


##如何来保存一个字符？


char  用来保存字符

#include <stdio.h>
int main()
{
	char a = 'X';	//定义一个字符型变量a, 值为'X'
	scanf("%c", &a);
	printf("a is %c\n", a);	// %c 表示输出一个字符
}
-------------------------------------------------------------------------------------------------------------

'\0' ---> 0

'0'  ---> 48




######练习2：
			输入一个字符，进行判断
			1)如果是 小写字母 打印输出 is small letter!! 'a'  ---- 'z'
			2)如果是 大写字母 打印输出 is big letter!!  'A' ---- 'Z'
			3)如果是 数字    打印输出 is number '0' ---- '9'
	
//输入一个字符，判断是不是字符 'a'


#include <stdio.h>
int main()
{
	char a;	//定义一个字符型变量a
	scanf("%c", &a);
	if(a >= '0' && a <= '9')
	{
		printf("a is digital\n");
	}
	else if(a >= 'a' && a <= 'z')
	{
		printf("a is small char\n");
	}
	else if(a >= 'A' && a <= 'Z')
	{
		printf("a is big char\n");
	}
}

//////////
if(条件1)
{
	//语句1  //满足条件1，执行语句1
}
else if(条件2)
{
	//语句2  //条件1不成立，条件2成立，执行语句2
}
else if(条件3) //条件1不成立，条件2不成立，条件3成立， 执行语句3 
{
	//语句3
}
else //条件1 2 3 都不成立，执行语句4
{
	//语句4
}

------------------------------------------------------------------------------------------------------------
2.1.3 自加、自减

(1)++  (自增运算符)
	
	int a = 1;
	a++;   //执行完a = 2
	int a = 1;
	++a;   //执行完a = 2  

	int x = 4;
	int y;
	y = x++;  //执行完，y = 4, x = 5
	//++在变量后面， 先运算，再++,  (y = x;  x++)

	y = ++x;  //执行完，y = 5, x = 5;
	//++在变量前面， 先++，再运算,  (x++; y = x)

--------代码演示------------
#include<stdio.h>

int main()
{
	int x = 6,y = 7;
	int z;
	z = x++ + ++y;     
	printf("x = %d,y = %d,z = %d\n",x,y,z);
}

执行结果：
x = 7,y = 8,z = 14  .

(2) -- (自减运算符同理)

	a--; a = a-1;
	
	--a; a = a-1

###逻辑&& 和 ||的短路运算

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = -1;
	int b = 2;
	if(++a && ++b)//打印hello world不会输出，条件不成立 ++a,a == 0,
	{//&&　一假即假，后面的条件++b没有被执行
		printf("hello world\n");
	}
	printf("a is %d\nb is %d\n",a,b);//打印a is 0 b is 2
	return 0;
}



#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 0;
	int b = 2;
	if(++a || ++b)//打印hello world会输出，条件成立 ++a,a == 1,
	{//||　一真即真，后面的条件++b没有被执行
		printf("hello world\n");
	}
	printf("a is %d\nb is %d\n",a,b);//打印a is 1 b is 2
	return 0;
}
-------------------------------------------------------------------------------------------------------------
2.1.4 算数运算表达式： +=    -=   *=     /=    %=
	
	a += 1; a++;
	a += 3;     <=====>   a = a + 3;
	a -= 3;     <=====>   a = a - 3;
	a *= 3;     <=====>   a = a * 3;

	a += b;      <=====>   a = a + b;
	a += b + 3;  <=====>   a = a + (b + 3);

--------代码演示------------
#include <stdio.h>
int main()
{
	int a = 5;
	int b = 2;
	a += 3;
	printf("a %d\n", a); // a 8
	a += b;
	printf("a %d\n", a); // a 10
}
-------------------------------------------------------------------------------------------------------------

#######练习4：输入三个数, 比较三个数的大小，打印输出三个数中的最大值。
比如：   a = 8 , b = 5 , c = 3;
则屏幕输出    最大值是8 


//a里面永远保存最大值
//假设a是最大值 
//用a和b比较，如果b大，将b赋值给a
//用a和c比较，如果c大，将c赋值给a


#include <stdio.h>
int main()
{
	int a = 5, b = 6, c = 2;
	if(a < b)
	{
		a = b;
	}
	if(a < c)
	{
		a = c;
	}
	printf("max is %d\n",a);
	return 0;
}

2.1.5  三目运算符

   ?  :  表达式          c语言中唯一的三目运算符
   
  表达式1 ？表达式2 ：表达式3

 int min =  a < b ? a : b //  
  
  int a = 3;
  int b = 5;
  int max = a > b ? a : b;//如果a > b为真,值为：左边的值， 如果a> b为假，值为:右边的值

首先判断表达式1，若为真，则执行表达式2，若为假，则执行表达式3
  
######练习3：输入三个数求最大值程序改成用 ? : 表达式来实现

#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	a = a > b ? a : b;
	a = a > c ? a : c;
	printf("max = %d\n",a);
}

---------------------------------------------------------------------------------------------------------------------------
//C语言三大程序结构 

1.顺序结构 

2.选择结构 

3.循环结构
	
2.2.1 用if语句实现二分支选择结构(四种)

(1)if(条件)
{
	语句
}

(2)if-else 
if(条件)
{
	语句1
}
else 
{
	语句2 
}
(3)if嵌套 

if()
{
	if()
	{
		
	}
}
(4)if - else if - else
if()
{
	
}
else if()
{
	
}
else if()
{
	
}
else
{
	
}


2.2.2 用switch语句实现多分支选择结构

	switch(表达式)	//switch（）内一定不能是浮点数， 可以是int, char, short, long
	{
		case 常量表达式1:		//表达式的值和常量表达式的值相等时，就执行此case后面语句。
				语句1;
				break;
		case 常量表达式2:
				语句2;
				break;	
			.
			.
		case 常量表达式n:
				语句n;
				break;
		default:			//默认分支，上面的都不满足，执行default后面语句。
				语句n+1		
	}

--------代码演示------- 由用户输入，如果1，打印monday, 如果是2 打印tuesday， 如果3打印wensday, 如果4打印thursday


#include <stdio.h>

int main(int argc, const char *argv[])
{
	int day;
	printf("Please input day:\n");
	scanf("%d",&day);
	switch(day)//char shrt int int long 
	{//{ }之间被称为switch体 
		case 1:
			printf("星期一\n");
			break;//跳出switch体
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		default://除了上面case 以外，就执行default
			printf("不是星期　一　二　三\n");
	}
	return 0;
}


######练习7：

	用switch语句实现一个小型计算器 
	
	例如：输入3 + 5 打印输出 8  '+' '-' '*' '\' 
	
	3+5
	8
	5-3
	2
	
	
	
		
	
#include <stdio.h>
int main()
{
	int a,c;
	char b;
	scanf("%d%d", &a, &c);
	getchar();			//输入时吸收回车符（**）
	scanf("%c",&b);
	//用switch 判断 b,  '+'   '-'  '*'  '/'
	switch(b)
	{
	case '+':
		printf("%d\n", a + c);
		break;
	case '-':
		printf("%d\n", a - c);
		break;
	case '*':
		printf("%d\n", a * c);
		break;
	case '/':
		printf("%d\n", a / c);
		break;
	default:
		printf("error\n");
		break;
	}
}





2.2.3 类型转换（*）

	了解见附件
	转换原则：从小到大  char --> short --> int --> long --> float --> double
	强制类型转换(**)

	///类型转换
	int a= 3;
	float b = 1.2;
	a + b ?  结果是float  两个不同类型进行运算，要进行类型转换

	转换原则：从小到大  char --> short --> int --> long --> float --> double

	#include <stdio.h>
	int main()
	{
		int a= 3;
		float b = 1.2;
		printf("%f\n", a + b);  //a 转成float类型，此种转换叫隐式转换，或者叫默认转换
		//如果希望，b转成int, 然后进行 + 运算
		printf("%d\n", a + (int)b);  //(int)b   强制类型转换
	}



2.2.4 常量(其值不可以改)

100, 'A'
#define PI 3.14    //定义一个宏常量 名 PI, 值3.14


1)  设圆半径为r,求圆周长,圆面积。用scanf输入半径,输出计算结果,请写程序. 
3.14 用宏来表示

2 * PI * r
PI * r * r

#include <stdio.h>
#define PI 3.14
int main()
{
	float r, l, s;
	scanf("%f", &r);
	l = 2 * PI * r;
	s = PI * r * r;
	printf("l is %f, s is %f\n", l, s);
}

//定义宏的好处
1 能达到一改全改的目的
2 能增加程序的可读性



作业：

1
输入学生成绩

	90-100 分打印 A
	80-89  分打印 B
	70-79  分打印 C
	60-69  分打印 D
	其他不及格
		
		
分别用if条件判断   和   sitch分支   两种方法实现



2. 判断用户输入的年是否为闰年？
	四年一润
	百年不润
	四百年又润 2000 yes 1900 no
	例如 1993 1900 2000 2004  平平润润