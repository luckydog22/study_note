
作业参考代码： 
1.  计算 "4+8*2-3"
///////////////////////
#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	int *data;     // 指向一个位置，该位置用来存储数据。 
	int maxlen;    // 保存了元素个数。 data 指向的位置的元素个数。
	int top;
}sqstack_t;
// 创建空栈
sqstack_t *CreateEmptyStack(int len)
{
	sqstack_t *s = (sqstack_t *)malloc(sizeof(sqstack_t));
	s->data = malloc( sizeof(int)*len );
	s->maxlen = len;
	s->top = 0;
	return s;
}
// 清空栈 
void ClearStack(sqstack_t *s)
{
	s->top = 0;
}
// 判断栈是否空。如果空，返回真，否则返回假。 
int EmptyStack(sqstack_t *s)
{
	return (s->top == 0) ;
}
// 判断栈是否满。 如果满，返回真，否则返回假。 
int FullStack(sqstack_t *s)
{
	return (s->top == s->maxlen);
}
// 数据入栈。 数据保存在栈顶位置。 
int PushStack(sqstack_t *s, int value)
{
	if( FullStack(s) )
		return -1;
	s->data[s->top++] = value;
	return 0;
}
// 数据出栈。 数据从栈顶位置取出。
int PopStack(sqstack_t *s)
{
	if( EmptyStack(s) )
		return -1;

	return s->data[ -- s->top ];
}
// 获取栈顶元素
int GetTop(sqstack_t *s)
{
	if(EmptyStack(s))
		return -1;
	return s->data[s->top-1];
}
// 计算 
void calculate(sqstack_t *num_stack, sqstack_t *symbol_stack)
{
	int num2 = PopStack(num_stack);
	int num1 = PopStack(num_stack);
	int c = PopStack(symbol_stack);
	switch( c )
	{
	case '+': PushStack(num_stack, num1+num2); break;
	case '-': PushStack(num_stack, num1-num2); break;
	case '*': PushStack(num_stack, num1*num2); break;
	case '/': PushStack(num_stack, num1/num2); break;
	default : break;
	}
}
// 主逻辑 
int main()
{
	char string[] = "4+8*2-3";
	sqstack_t *num_stack = CreateEmptyStack(5);            // 创建空栈
	sqstack_t *symbol_stack = CreateEmptyStack(3);
	int i = 0;
	while( string[i] != '\0')    // 处理字符串
	{
		if( string[i]>='0' && string[i]<='9')     // 字符串中，两类数据：数值、符号。 
		{
			PushStack(num_stack, string[i]-'0');     //   当是数值时：数据入栈即可。
		}
		else    // 如果是符号  
		{
			if( EmptyStack(symbol_stack) )     // 两种情形： 符号栈是否为空。如果为空。则符号直接入栈即可。 
			{
				PushStack(symbol_stack,string[i]);
			}
			else                   // 如果不为空，则比较优先级    
			{
				int num = GetTop( symbol_stack );    //栈顶元素
				int a,b;
				if(num=='+' || num=='-')  a = 1;
				if(num=='*' || num=='/')  a = 2;
				if(string[i]=='+' || string[i]=='-') b = 1;
				if(string[i]=='*' || string[i]=='/') b = 2;
				if( a < b )         // 栈顶元素的优先级 和 当前处理的字符的优先级，作比较。 如果栈顶优先级低，那么符号入栈。
				{
					PushStack(symbol_stack,string[i]);
				}
				else           // 否则，运算。
				{
					calculate(num_stack,symbol_stack);
					continue;   //i--; 也可以。 
				}
			}
		}
		i++;
	}
	while( !EmptyStack(symbol_stack) )     // 只要符号栈不为空，就要一直做运算。 
		calculate(num_stack,symbol_stack);
	printf("The result is %d\n",PopStack(num_stack));     // 输出最终结果。 
	return 0;
}

2. 学生链表
//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
	char name[10];
	int age;
	int grade;
}student_t;
typedef struct node_t 
{
	student_t s;
	struct node_t *next;
}linknode_t,*linklist_t;
// 创建空链表
linklist_t CreateEmptyLinklist()
{
	linklist_t h = (linklist_t )malloc(sizeof(linknode_t));    // 申请空间
	h->next = NULL;         // 指针赋初值。数据域不赋值。
	return h;
}
// 判断链表是否空
int EmptyLinklist(linklist_t h)
{
	return (h->next == NULL);
}
// 遍历链表。 
void VisitLinklist(linklist_t h)
{
	while(h->next != NULL)
	{
		h = h->next;
		printf("%s  %d    %d\n", h->s.name, h->s.age, h->s.grade);
	}
	return ;
}
// 插入数据。 
int InsertLinklist_1(linklist_t h, student_t s)
{
	linklist_t new = (linklist_t )malloc(sizeof(linknode_t));     // 要插入的节点。 （步骤2：创建新节点）
	new->s = s;
	new->next = h->next;     //（步骤3：新节点赋值）

	h->next = new;          // 步骤4： 将新节点挂到链表中。 
	return 0;
}
//清空链表。 
void ClearLinklist(linklist_t h)
{
	linklist_t p;
	while(h->next != NULL)
	{
		p = h->next;
		h->next = p->next;
		free(p);
	}
}
// 主逻辑  
int main()
{
	linklist_t h = CreateEmptyLinklist();

	student_t s;
	while(1)
	{
		puts("Input name age grade:");
		scanf("%s%d%d",s.name, &s.age, &s.grade);
		if(s.age <= 18)
			break;
		InsertLinklist_1(h,s);
	}
	VisitLinklist(h);
	ClearLinklist(h);
	return 0;
}



////////////////////////
#include<stdio.h>
#include<stdlib.h>
#define N 2
typedef struct 
{
	char name[20];
	int age;
	int grade;
}student_t;
typedef struct node_t
{
	student_t s;
	struct node_t *next;
}linklist_t;
linklist_t *get_create()
{
	linklist_t *p=(linklist_t *)malloc(sizeof(linklist_t));
	p->next=NULL;
	return p;
}
void get_insert(linklist_t *h,student_t s)
{
	linklist_t *new=(linklist_t *)malloc(sizeof(linklist_t));
	new->s=s;
	new->next=h->next;

	h->next=new;
	h=new;
}
void get_print(linklist_t *h)
{
	while(h->next!=NULL)
	{
		h=h->next;
		printf("%s--%d--%d\n",h->s.name,h->s.age,h->s.grade);
	}
}
int main()
{
	linklist_t *h=get_create();
	student_t s;
	int i;
	linklist_t *new;
	for(i=0;i<N;i++)
	{
		scanf("%s%d%d",s.name,&s.age,&s.grade);
		get_insert(h,s);
	}
	get_print(h);
}

3. 合并链表 
////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int data_t;
typedef struct node_t 
{
	data_t data;
	struct node_t *next;
}linknode_t,*linklist_t;
// 创建空链表
linklist_t CreateEmptyLinklist()
{
	linklist_t h = (linklist_t )malloc(sizeof(linknode_t));    // 申请空间
	h->next = NULL;         // 指针赋初值。数据域不赋值。
	return h;
}
// 判断链表是否空
int EmptyLinklist(linklist_t h)
{
	return (h->next == NULL);
}
// 遍历链表。 
void VisitLinklist(linklist_t h)
{
	while(h->next != NULL)
	{
		h = h->next;
		printf("%d -- ", h->data);
	}
	printf("\n");
	return ;
}
// 按递增的次序插入数据。 
void InsertLinklist(linklist_t h, data_t x)
{
	while( h->next != NULL  && x > h->next->data)      // 如果 h 有 next 节点。 并且待插入数据大于下一个节点的数据。 则指针继续移动。 
		h = h->next;	       // 此循环的目的是：将指针移动到待插入位置的前一个节点。 
	
	linklist_t new = (linklist_t )malloc(sizeof(linknode_t));    // 创建新节点。 
	new->data = x;
	new->next = h->next;     // 新节点赋值。 

	h->next = new;        // 将新节点放在链表中。 
	return ;	
}
//清空链表。 
void ClearLinklist(linklist_t h)
{
	linklist_t p;
	while(h->next != NULL)
	{
		p = h->next;
		h->next = p->next;
		free(p);
	}
}
// 合并链表   
void Merge(linklist_t A,linklist_t B)
{
	linklist_t p;
	while(A->next != NULL && B->next != NULL)   // 当：都有 next 时，才能比较值。
	{
		if(A->next->data >= B->next->data)     //  如果满足条件，则B中的节点，插入即可。 
		{
			p = B->next;         // 第一步： p 指向 B 待出列的节点。 
			B->next = p->next;   // 第二步：链表 B 将节点 p 移除
			
			p->next = A->next;   // 第三步： p 节点做插入到链表 A 的准备。  
			A->next = p;         // 第四步： A 的下一个节点，改为 p 即可。 
		}
		A = A->next;     // A 指针向后移动， 为下次判断做准备。 
	}
	if(A->next == NULL)     // 如果链表A 结束，则将 B 中剩下的链表，挂接到链表 A 的后面即可。 
		A->next = B->next;
	return ;
}
// 测试函数
int main()
{
	linklist_t A = CreateEmptyLinklist();
	linklist_t B = CreateEmptyLinklist();      // 创建空链表   

	InsertLinklist(A,11);
	InsertLinklist(A,33);     // 构建链表 A
	InsertLinklist(A,44);
	InsertLinklist(A,77);
	InsertLinklist(A,99);
	VisitLinklist(A);
	InsertLinklist(B,22);
	InsertLinklist(B,55);      // 构建链表 B 
	InsertLinklist(B,66);
	InsertLinklist(B,88);
	VisitLinklist(B);

	Merge(A,B);                // 按升序合并链表  
	VisitLinklist(A);      // 遍历 
	ClearLinklist(A);	   // 清空  
	return 0;
}






新课：     查找 

1. 顺序查找 
适用场合： 数据无序时。或者数据量不大时。遍历，依次寻找  
//////////////////
#include <stdio.h>
int find_number(int *p,int n, int which )
{
	int i;
	for(i=0; i<n; i++)
	{
		if(p[i] == which)
			return i;
	}
	return -1;
}
int main()
{
	int a[] = {45,66,84,63,26,17,96,37,54,22,85,17,64,31,78,39,57,96};

	int input;
	scanf("%d",&input);
	int pos = find_number(a, sizeof(a)/sizeof(a[0]), input);
	if(pos < 0)
		printf("Not found!\n");
	else 
		printf("Pos :%d\n",pos+1);
	return 0;
}


2. 折半查找    
适用场合： 数据有序。 
///////////////////////
#include <stdio.h>
int find_by_half(int *p,int n, int which)
{
	int high = n-1, low = 0, mid;
	
	while(low <= high)
	{
		mid = (low + high)/2;        //找中间位置。 
		if( p[mid] == which )        // 与中间位置的值做判定。 
			return mid;

		else if(which > p[mid])
			low = mid+1;

		else 
			high = mid-1;
	}
	return -1;
}
int main()
{
	int a[] = {12,23,34,45,56,67,77,88,90,99,100};

	int input;
	scanf("%d",&input);
	int pos = find_by_half(a, sizeof(a)/sizeof(a[0]), input);
	if(pos < 0)
		printf("Not found!\n");
	else 
		printf("Pos :%d\n",pos+1);
	return 0;
}


3. 分块查找

适用场合： 块间有序。块内可以无序。 
块间（有序）： 折半、顺序。  
块内（无序）： 顺序。 

////////////////////
#include <stdio.h>
typedef struct  
{
	int k_max;
	int k_index;
}index_t;

int find_by_block(int *p,int n,index_t *s,int m, int which)
{
	int i,j,start,end;
	for(i=0; i<m; i++)              // 先在索引表中查找其大致位置。也就是在哪个块中。 
	{
		if(which <= s[i].k_max)
		{
			start = s[i].k_index;     // 然后寻找到该值所在原始表的一小块范围的起止位置。 
			if(i<m-1)
				end = s[i+1].k_index;
			else 
				end = n;
			for(j=start; j<end; j++)    // 再然后，在原始表中查找是否存在次数据。 
			{
				if(which == p[j])    // 如果找到，返回下标   
					return j;
			}
			break;   // 如果没有。无需再查找下一个位置块。 直接结束即可。 
		}
	}
	return -1;
}
int main()
{
	int a[] = {18,10,9,8,16,20,38,42,19,50,84,72,56,55,76,100,90,88,108};
	index_t s[4] = {{18,0},{50,5},{84,10},{108,15}};

	int input;
	scanf("%d",&input);
	int pos = find_by_block(a,sizeof(a)/sizeof(int),s,4,input);
	if(pos < 0)
		printf("Not found!\n");
	else 
		printf("Pos :%d\n",pos+1);
	return 0;
}


4. 散列查找    

（1）查找的时间复杂度为常量级。 不经过比较就得到要查找的数据
（2）最重要的两点： 
	a.如何构建哈希函数。 
	b.如何解决冲突。 

（3） 构建哈希函数的方法： 
	直接地址法
	平方取中法
	叠加法
	保留余数法
	随机函数法 

（4）解决冲突的办法： 
	开放地址法
	线性探查法 
	链地址法
	备用表法

直接地址法示例代码： 
//////////////////////
#include <stdio.h>
// 哈希规则
int hash_fun(int age)
{
	int key = age-1;
	return key;
}
// 按哈希规则存数据 
void save_by_hash(int *p,int age, int number)
{
	int key = hash_fun(age);
	p[key] = number;
	return ;
}
// 按哈希规则查找数据
int find_by_hash(int *p,int age)
{
	int key = hash_fun(age);
	return p[key];
}
// 测试函数
int main()
{
	int a[100] = {0};

	int age,number;
	while(1)
	{
		puts("input age and number:");
		scanf("%d%d",&age,&number);
		if(age <= 0)
			break;
		save_by_hash(a,age,number);
	}
	puts("Which ?");
	scanf("%d",&age);
	number = find_by_hash(a,age);
	printf("%d\n",number);
	return 0;
}


示例2： 
构建哈希函数的方法：保留余数法   
解决冲突的办法： 备用表 
///////////////////////////
#include <stdio.h>
int hash_fun(int number)
{
	int key = number%13;
	return key;
}
void save_by_hash(int *p,int *b,int number)
{
	static int i = 0;
	int key = hash_fun(number);
	if (p[key] == 0)
		p[key] = number;
	else 
	{
		b[i++] = number;
	}
	return ;
}
int find_by_hash(int *p,int *b,int number)
{
	int i;
	int key = hash_fun(number);
	if(number == p[key])
		printf("In a: %d\n",key);
	else 
	{
		for(i=0; i<5; i++)
		{
			if(b[i] == number)
				printf("In b: %d\n",i);
		}
	}
}
int main()
{
	int a[15] = {0};
	int b[5] = {0};
	int number;
	while(1)
	{
		puts("input number:");
		scanf("%d",&number);
		if(number <= 0)
			break;
		save_by_hash(a,b,number);
	}

	puts("Which ?");
	scanf("%d",&number);
	find_by_hash(a,b,number);
	return 0;
}

