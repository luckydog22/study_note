#复习：

int a[5] = {1,2,3,4,5};
int *p = a;//int *p = &a[0];
int *q = &a[4];

q - p ==== ? 4 //间隔的数据数

*(p+i) ==== a[i] ==== p[i] ==== *(a+i)//值

p+i === &a[i] === &p[i] === a+i 

p++;
a++;//错误，因为a是地址常量

a += 2; //错误

int *p;  0x00001100

p+1 ---》 0x00001104 //增加一个int  4*1


double *q  0x00001100

q+2        0x00001110 //增加两个double 8*2
char *z 	0x00001100

z+1   		0x00001101

//////任何类型的指针变量所占内存空间的大小都是4个字节


指针变量与指针变量相加无意义 p+q 错误 

int *p = NULL;//将一个指针初始化为空指针 NULL ---》0

////////////////////////////////////////////////////////////////

值传递和地址传递

(1)值传递

void setA(int b)
{
	b = 100;
}

int main()
{
	int a = 0;
	setA(a);//值传递，修改的是参数b的值，而main函数中的a没有被修改
}
(2)地址传递 
void setA(int *p)
{
	*p = 100;
}

int main()
{
	int a = 0;
	setA(&a);//地址传递，修改a的值
}
 
 
地址传递才能改变实参的值

一个函数想要给函数的调用者传递值，有几种方法

(1)返回值 

(2)参数地址传递

///////////////////////////////////
strcmp("abc","abc");  == 0

strcmp("ab","abc"); === -1

strcmp("ac","abcdef"); === 1


#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[1000] = { 0 };//用来保存猴子
	int all_num;//猴子总数
	int start_num;//起始号码
	int kill_num;//数到几被杀死号码
	int rm_num;//被杀死的猴子对应数组中的下标
	printf("请输入猴子总数:\n");
	scanf("%d",&all_num);
	printf("请输入起始号码:\n");
	scanf("%d",&start_num);
	printf("请输入数到几做为杀死的号码:\n");
	scanf("%d",&kill_num);
	int i,j;
	for(i = 0; i < all_num; i++)
	{
		a[i] = i+1;
	}
	rm_num = (start_num + kill_num - 2)%all_num;//得到即将被删除的号码对应数组的下标
	while(a[1] != 0)
	{
		printf("杀死猴子%d\n",a[rm_num]);
		//删除思想:追个向前移动一个位置，覆盖
		for(i = rm_num; i < all_num; i++)
		{
			a[i] = a[i+1];
		}
		all_num--;//删除后，猴子的总数-1
		rm_num = (rm_num + kill_num - 1)%all_num; //确定下一次被删除的猴子号码对应的下标
	}
	printf("猴王是%d\n",a[0]);
	return 0;
}



1.结构体   

	例子
	学生图书管理系统、
	有一些变量保存图书信息
	
		char name[20];
		int number;
		char writer[20];
		char date[20];

	有一些变量保存借阅者(学生)信息
	
		char name[20];
		int number;
		char class[20];
		char date[20];


	结构体的作用
	为了方便管理，我们可以将这些变量组织在一起，构成结构体

	1.1 如何定义结构体(是一个新类型，等同于int, char, float, double，可以用结构体定义变量)

		定义一个学生结构体
		struct student		//struct 结构体定义关键字，student 结构体名
		{
			int number;		//成员变量
			char name[20];	//成员变量
			int age;		//成员变量
			int score;		//成员变量
		};//注意此处一定要有;号

	1.2 如何定义结构体变量

		struct student s1;		//s1 是结构体变量， struct student 是类型
						//s1 代表具体某个学生
		(1)如何初始化
		
			struct student s1 = {1001, "xiaoli", 25, 90};

		(2)如何通过结构体变量访问结构体成员
		
			s1.age = 30; 	// "." 为成员运算符，可以访问结构体成员和赋值

			学生结构体例子
			
			#include <stdio.h>

			struct student		//struct 结构体定义关键字，student 结构体名
			{
				int number;		//成员变量
				char name[20];		//成员变量
				int age;		//成员变量
				int score;		//成员变量
			};
			int main()
			{
				struct student s1 = {1001, "xiaoli", 25, 90};
				printf("name %s, number %d, age %d, score %d\n", 
						s1.name, s1.number, s1.age, s1.score);
			}

			更改信息，可以像下面这样，但不允许整体改
			s1.age = 30;
			s1.score = 90;
			s1.name = "xiaowang";		//错，因为数组不可以整体赋值
			strcpy(s1.name, "xiaowang");
			s1 = {1002, "xiaowang", 25, 90};	//错，结构体只有定义时可以整体赋值,和之前所学的数组一样

			///定义结构体同时定义变量，但实际很少这样做
			struct student		
			{
				int number;		
				char name[20];		
				int age;		
				int score;		
			}s1, s2;
			
			##练习1 
			
			定义一个结构体worker,有下面成员，姓名、编号、年龄、工资(float)
			输入信息，并输出
			#include <stdio.h>

			struct worker		
			{
				char name[20];		
				int number;		
				int age;		
				float salary;		
			};
			int main()
			{
				struct worker s1;
				scanf("%s%d%d%f", nas1.me, &s1.number, &s1.age, &s1.salary);
				printf("name %s, number %d, age %d, salary %f\n", 
						s1.name, s1.number, s1.age, s1.salary);
			}

	1.3指向结构体的指针
	
		定义指针变量，指向一个结构体变量
		如果用指针变量访问结构体成员：
		s->age 
		s->name
		s->score

		struct student *p;
		struct student *s;

		#include <stdio.h>

		struct student		//struct 结构体定义关键字，student 结构体名
		{
			int number;		//成员变量
			char name[20];		//成员变量
			int age;		//成员变量
			int score;		//成员变量
		};
		int main()
		{
			struct student s1 = {1001, "xiaoli", 25, 90};
			struct student *s = &s1;

			printf("name %s, number %d, age %d, score %d\n", 
					s->name, s->number, s->age, s->score);
		}

	1.4结构体变量可以做函数参数
	
		如果将 打印学生信息 写成一个函数，我们就可以将学生结构体作为参数传递给函数，
		
		(1)值传递
		
		#include <stdio.h>
		struct student		//struct 结构体定义关键字，student 结构体名
		{
			int number;		//成员变量
			char name[20];		//成员变量
			int age;		//成员变量
			int score;		//成员变量
		};
		void print_student(struct student s)
		{
			printf("name %s, number %d, age %d, score %d\n", 
					s.name, s.number, s.age, s.score);
		}

		int main()
		{
			struct student s1 = {1001, "xiaoli", 25, 90};
			print_student(s1);
		}

		(2)地址传递
		
		#include <stdio.h>
		struct student		//struct 结构体定义关键字，student 结构体名
		{
			int number;		//成员变量
			char name[20];		//成员变量
			int age;		//成员变量
			int score;		//成员变量
		};
		void print_student(struct student *s)
		{
			printf("name %s, number %d, age %d, score %d\n", 
					s->name, s->number, s->age, s->score);
		}

		int main()
		{
			struct student s1 = {1001, "xiaoli", 25, 90};
			print_student(&s1);
		}

	1.5 传递结构体数组
	
		如果给函数传递结构体变量，尽量使用指针，好处是节省内存空间

		/////定义结构体数组
		#include <stdio.h>
		struct student		//struct 结构体定义关键字，student 结构体名
		{
			int number;		//成员变量
			char name[20];		//成员变量
			int age;		//成员变量
			int score;		//成员变量
		};
		int main()
		{
			struct student s[3] = {{1001, "xiaoli", 25, 90},{1002, "xiaowang", 26, 72},{1003, "xiaozhang", 27, 85}};
			int i;
			for(i = 0; i < 3; i++)
			{
				printf("name %s, number %d, age %d, score %d\n", 
					s[i].name, s[i].number, s[i].age, s[i].score);
			}
		}
		
		#include <stdio.h>
		struct student		//struct 结构体定义关键字，student 结构体名
		{
			int number;		//成员变量
			char name[20];		//成员变量
			int age;		//成员变量
			int score;		//成员变量
		};
		void print_all(struct student *s, int n)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				printf("name %s, number %d, age %d, score %d\n", 
					s[i].name, s[i].number, s[i].age, s[i].score);	//(s + i)->name
			}
		}
		int main()
		{
			struct student s[3] = {{1001, "xiaoli", 25, 90},{1002, "xiaowang", 26, 72},{1003, "xiaozhang", 27, 85}};
			print_all(s, 3);
		}

/////////////////////

	复习结构体
	结构体是一个类型(和int ，float， char 等价的)
	结构体是由基本类型组合成 的

	结构体使用步骤
	1 定义结构体(类型)
	struct student
	{
		char name[20];
		int number;
		int age;
		int score;
	};

	2 定义结构体变量
	struct student s1 = {"xiaoli", 1001, 25, 90};

	struct student *s = &s1;

	struct student s[3] =  {{1001, "xiaoli", 25, 90},{1002, "xiaowang", 26, 72},{1003, "xiaozhang", 27, 85}};


	结构体做函数的参数(采用地址传递)


		##练习3
	
		写一个函数, 此函数能设置student类型变量的值
		#include <stdio.h>
		struct student
		{
			char name[20];
			int number;
			int age;
			int score;
		};
		void set_student(struct student *s)
		{
			scanf("%s%d%d%d", s->name, &s->number, &s->age, &s->score);
		}
		void print_student(struct student *s)
		{
			printf("name %s, number %d, age %d, score %d\n", 
					s->name, s->number, s->age, s->score);
		}
		int main()
		{
			struct student s1;
			set_student(&s1);	//能给s1 赋值
			print_student(&s1);	//能打印s1的值
		}

		##练习4
	
		还用上面的结构体，写一个函数，传入n个student，查询其中年龄 > 25的student，
		并且输出该student的基本信息（调用print_student函数）

		#include <stdio.h>
		struct student
		{
			int number;
			char name[20];
			int age;
			int score;
		};
		void print_student(struct student *s)
		{
			printf("name %s, number %d, age %d, score %d\n", 
					s->name, s->number, s->age, s->score);
		}
		void find_by_age(struct student *s, int n, int age)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				if(s[i].age > age)
				{
					print_student(&s[i]);
				}
			}
		}
		int main()
		{
			struct student s[3] =  {{1001, "xiaoli", 25, 90},{1002, "xiaowang", 26, 72},{1003, "xiaozhang", 27, 85}};
			find_by_age(s, 3, 25);
		}
		
		
		##练习6

		还用上面的结构体，写一个函数，传入n个student，查询名字是"xiaoli"的student，传给调用者(main)，调用者(main)输出其基本信息
		
		//////方法一 返回时下标
		#include <stdio.h>
		#include <string.h>

		struct student
		{
			char name[20];
			int age;
			int score;
		};//一定要有;号

		//输入学生信息
		void set_all(struct student *p,int n)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				scanf("%s%d%d",p[i].name,&p[i].age,&(p+i)->score);
			}
		}
		//通过名字查找学生
		int find_by_name(struct student *p, int n,char *name)//name代表查询的学生的名字
		{
			int i = 0;
			for(i = 0; i < n; i++)
			{
				if(strcmp(p[i].name,name) == 0)//判断两个字符串是否相等用strcmp
				{
					return i;
				}
			}
			return -1;//证明没有找到
		}


		int main(int argc, const char *argv[])
		{
			struct student s[3];
			//输入学生信息
			set_all(s,3);
			int i = find_by_name(s,3,"xiaoli");
			if(i != -1)
			{
				printf("%s %d %d\n",s[i].name,s[i].age,s[i].score);
			}
			else
			{
				printf("没有找到!!!\n");
			}
			return 0;
		}
		
/////方法二,返回的是结构体指针，地址

#include <stdio.h>
#include <string.h>

struct student
{
	char name[20];
	int age;
	int score;
};//一定要有;号

//输入学生信息
void set_all(struct student *p,int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%s%d%d",p[i].name,&p[i].age,&(p+i)->score);
	}
}
//通过名字查找学生
 struct student *find_by_name(struct student *p, int n,char *name)//name代表查询的学生的名字
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		if(strcmp(p[i].name,name) == 0)//判断两个字符串是否相等用strcmp
		{
			return &p[i];
		}
	}
	return NULL;//证明没有找到
}


int main(int argc, const char *argv[])
{
	struct student s[3];
	//输入学生信息
	set_all(s,3);
	struct student * p = find_by_name(s,3,"xiaoli");
	if(p != NULL)
	{
		printf("%s %d %d\n",p->name,p->age,p->score);
	}
	else
	{
		printf("没有找到!!!\n");
	}
	return 0;
}

	1.6结构体占用内存空间大小
	
		struct student
		{
			int number;
			char name[20];
			int age;
			int score;
		};
		
		struct student s1;
		sizeof(struct student)  sizeof(s1)  ?    32

		struct student *s;     sizeof(s)  sizeof(struct studnet *)    ?    4

		struct A       //sizeof(struct A)?  
		{
			char c2;
			int a;
			double b;
			char c1;
		};

		sizeof(struct A)    ?    16
		

2内存管理

	2.1程序内存分配，分为两种方式
	
	(1)静态分配(在编译时确定内存的大小)
	
		int a;           //给a分配4字节空间
		
		char c[100];     //给c分配100个字节空间


		静态分配，在编译时就确定好内存空间的大小

						  int n;
		所以数组 不能这样 char c[n];   //数组元素个数一定是一个常量

	(2)
		;
		动态内存分配
		在运行时再确定内存的大小

		char *p = malloc(100);	//malloc是动态分配内存函数, 100是分配的内存大小,  
					//返回值分配的内存的首地址，赋值给p, 使用p可以访问这块内存

		int *p = malloc(100 * sizeof(int));   //

		struct student *p = malloc(100 * sizeof(struct student));

		定义有n个元素的动态数组，并输出
		#include <stdio.h>
		#include <stdlib.h>
		int main()
		{
			int n, i;//n代表n个学生
			int *p;
			scanf("%d", &n);			//输入n值
			p = malloc(n * sizeof(int));		//分配n个int
			for(i = 0; i < n; i++)
			{
				p[i] = i;			//对n个int 赋值
			}
			for(i = 0; i < n; i++)
			{
				printf("%d\n", p[i]);		//打印n个int
			}
		}

		##练习7
		学生人数由输入确定，动态分配内存，保存学生成绩，
		然后求出学生平均成绩
		
		
		#include <stdio.h>
		#include <stdlib.h>
		int main()
		{
			int n, i, sum = 0;
			int *p;
			printf("please input num: ");
			scanf("%d", &n);			//输入n值
			p = malloc(n * sizeof(int));		//分配n个int
			printf("please input score: ");
			for(i = 0; i < n; i++)
			{
				scanf("%d", &p[i]);		//输入成绩		
			}
			for(i = 0; i < n; i++)
			{
				sum += p[i];			//求总成绩
			}
			printf("avg is %d\n", sum / n);
		}

		注意：
		
		(1)
		//malloc申请空间必须手动申请，手动释放
		//动态内存分配，不会自动释放，需要在程序里释放
		free(p);    

		通常 malloc 和 free要成对出现
		#include <stdio.h>
		#include <stdlib.h>
		int main()
		{
			int n, i, sum = 0;
			int *p;
			printf("please input num: ");
			scanf("%d", &n);			//输入n值
			p = malloc(n * sizeof(int));		//分配n个int
			printf("please input score: ");
			for(i = 0; i < n; i++)
			{
				scanf("%d", &p[i]);		//输入成绩		
			}
			for(i = 0; i < n; i++)
			{
				sum += p[i];			//求总成绩
			}
			printf("avg is %d\n", sum / n);
			free(p);	//释放内存
		}

		(2)
		
		动态内存分配可能失败

		如果分配失败，malloc返回值为NULL,

		所以，分配后要检查p是不是NULL
		#include <stdio.h>
		#include <stdlib.h>
		int main()
		{
			int n, i, sum = 0;
			int *p;
			printf("please input num: ");
			scanf("%d", &n);			//输入n值
			p = malloc(n * sizeof(int));		//分配n个int
			if(p != NULL)//如果不为NULL，说明申请空间成功
			{
				printf("please input score: ");
				for(i = 0; i < n; i++)
				{
					scanf("%d", &p[i]);		//输入成绩		
				}
				for(i = 0; i < n; i++)
				{
					sum += p[i];			//求总成绩
				}
				printf("avg is %d\n", sum / n);
				free(p);	//释放内存
			}
		}



