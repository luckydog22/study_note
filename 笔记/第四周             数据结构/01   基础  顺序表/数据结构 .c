
数据结构课程安排  5天 

1 基础、顺序表 
2 链表  
3 栈、队列 
4 查找、排序   
5 树、图



************
1./算法设计： 逻辑结构
  算法实现    存储结构

基础知识： 

数据结构： 
逻辑结构： 线性结构、 树形结构、图形结构  
存储结构： 顺序存储、 链式存储、索引存储、散列存储
运算： 增加、删除、修改、查找、排序、分类

算法：
(1)时间复杂度。 
(2)空间复杂度。 
(3)移植性好、模块独立性强、容易调试。 

线性结构： 每个节点的前驱节点和后继节点最多只能有一个。 
树形结构： 树形结构的节点：前驱节点最多只能有一个。后继节点可以有多个。 
图形结构： 每个节点的前驱节点和后继节点都可以有多个。 

线性结构：顺序表、链表、顺序栈、链式栈、循环队列、链式队列



一、 引例

题目：现有如下数组：  int a[100] = {11,22,33,55,66,77,77,88,99};
编写程序，完成下述要求：
  要求1: 数组中少了44 这个元素，将这个数值添加到数组当中。
  要求2: 数组中多了一个77，将这个数值从数组中删除掉。 
  要求3: 有效数据（非0值）要连续存放。
/////////////////////
#include <stdio.h>
struct data
{
	int a[100];   // 保存数据的 100 个位置。
	int count;    // 保存有效数据的个数。
};
void insert_1(struct data *x,int data,int pos)  // 按位置插入数据。 
{
	int i;
	for(i=x->count; i>pos-1; i--)    // pos 位置后的所有数据依次向后移动。 
		x->a[i] = x->a[i-1];
	x->a[pos-1] = data;       // 插入数据
	x->count ++;              // 数据的有效个数 +1
	return ;
}
void delete_1(struct data *x,int value)   // 删除值为 value 的数据  
{
	int i,j;
	for(i=0; i < x->count; i++)     //从头到尾遍历一遍。 
	{
		if(x->a[i] == value)    // 如果相等，就删除
		{
			for(j=i; j<x->count; j++)  
				x->a[j] = x->a[j+1];   // 依次向前移动。
			x->count--;               // 数据被覆盖掉，所以有效数据个数 -1 
			i--;            // 被删除数据的位置，因为获得了新的值，所以需要重新判断。所以 i-- 用来抵消掉当前次的 i++.
		}
	}
}
void print_array(struct data *x)   // 打印数组 。 
{
	int i;
	for(i=0; i<x->count; i++)   // 数据个数、数据内容、都在结构体 x 中保存完整了。 
		printf("%5d",x->a[i]);
	printf("\n");
	return ;
}
int main()    // 测试函数。 
{
	struct data x = {{11,22,33,55,66,77,77,88,99},9};    // 数据初始化。 
	print_array(&x);

	insert_1(&x,44,4);
	print_array(&x);
	
	delete_1(&x,77);
	print_array(&x);
	return 0;
}



二、 typedef 的用法：       (类型重定义) 

（1） 普通类型重定义：     typedef  int  data_t;   
（2） 结构体类型重定义： 
typedef struct data 
{
	int a[100];
	int count;
}data_t;

struct data x;
data_t x;

typedef struct    //  将一个无名结构体重命名为  data_t 类型。 
{
	int a[100];
	int count;
}data_t;

（3）特殊类型重定义（了解）：     typedef  void (*p)(int);  
void (*p)(int);           // 此句是定义函数指针。 
typedef void(*p)(int);    // 加上 typedef 后，此指针被定义为 函数指针类型。 可以通过这种类型去定义变量。 



三、 顺序表的具体实现  
逻辑结构： 线性结构 
存储结构： 顺序存储  
//////////////////////
#include <stdio.h>
#include <stdlib.h>
#define MAX 16
typedef int data_t;
typedef struct
{
	data_t data[MAX];
	int last;
}seqlist_t;
// 创建空顺序表。
seqlist_t *CreateEmptyList()
{
	seqlist_t *p = (seqlist_t *)malloc( sizeof(seqlist_t) );   // 申请堆空间内存。 
	p->last = 0;      // 0 个有效数据。空表。 
	return p;         // 返回堆空间首地址。 
}
// 判断表是否空。如果真空，则返回真（1）. 如果不空，则返回0.
int EmptySqlist(seqlist_t *L)
{
	return (L->last == 0) ;
}
// 判断表是否满。 如果真满，则返回真（1）。如果不满，则返回0.
int FullSqlist(seqlist_t *L)
{
	return (L->last == MAX) ;
}
// 清空顺序表。 
void ClearSqlist(seqlist_t *L)
{
	L->last = 0;   // 有效数据个数，赋值为0
	return ;
}
// 求顺序表长度。 
int LengthSqlist(seqlist_t *L)
{
	return L->last;   // 返回有效数据个数即可。 
}
// 按位置插入数据。 
int InsertSqlist(seqlist_t *L,data_t x,int pos)
{
	if(pos<0 || pos>LengthSqlist(L) || FullSqlist(L) )  // 下标如果不在范围内，或者表已满。则插入数据失败。 
		return -1;
	int i;
	for(i=L->last; i>pos; i--)   
		L->data[i] = L->data[i-1];  // 表中元素后移。 
	L->data[pos] = x;    // 数据插入元素。 
	L->last++;           // 有效数据个数 +1.
	return 0;
}
// 遍历顺序表
void VisitSqlist(seqlist_t *L)
{
	int i;
	for(i=0; i < L->last; i++)
		printf("%5d",L->data[i]);
	printf("\n");
	return ;
}
// 删除指定位置的值。 
int DeleteSqlist(seqlist_t *L,int pos)
{
	if(pos<0 || pos >= LengthSqlist(L) || EmptySqlist(L))   // 如果位置不在范围，或者表为空，则删除失败。 
		return -1;
	int i;
	for(i=pos; i<L->last-1; i++)
		L->data[i] = L->data[i+1];    // 表中元素后移。
	L->data[L->last-1] = 0;         
	L->last--;                 // 有效数据个数 -1.
	return 0;
}
// 查找数据。 遍历查找即可。 
int SearchSqlist(seqlist_t *L,data_t value)
{
	int i;
	for(i=0; i<L->last; i++)
	{
		if(L->data[i] == value)   // 如果有，返回下标。 
			return i;
	}
	return -1;   
}
// 测试函数。 
int main()
{
	seqlist_t *L = CreateEmptyList();
	InsertSqlist(L,11,0);
	InsertSqlist(L,22,1);
	InsertSqlist(L,33,2);
	VisitSqlist(L);
	DeleteSqlist(L,2);
	VisitSqlist(L);
	printf("%d\n",SearchSqlist(L,22));
}
///////////////
自己代码
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct seqlist
{
	int data[MAX];
	int count;
}seqlist_t;
seqlist_t *get_create()
{
	seqlist_t *p=(seqlist_t *)malloc(sizeof(seqlist_t));
	p->count=0;
	return p;
}
int get_empty(seqlist_t *s)
{
	if(s->count==0) return 1;
	return 0;
}
int get_full(seqlist_t *s)
{
	if(s->count == MAX) return 1;
	return 0;
}
void get_clear(seqlist_t *s)
{
	printf("empty?%d\n",get_empty(s));
	s->count=0;
}
int get_length(seqlist_t *s)
{
	return s->count;
}
int get_insert(seqlist_t *s,int pos,int value)
{
	if(pos<0||pos>s->count||get_full(s))
	{
		return 0;
	}
	int i;
	for(i=s->count;i>pos;i--)
	{
		s->data[i]=s->data[i-1];
	}
	s->data[pos]=value;
	s->count++;
	return 1;
}
void get_print(seqlist_t *s)
{
	int i;
	for(i=0;i<s->count;i++)
	{
		printf("%d--",s->data[i]);
	}
}
int get_delete(seqlist_t *s,int pos)
{
	if(pos<0||pos>s->count-1||get_empty(s))
	{
		return 0;
	}
	int i;
	for(i=pos;i<s->count;i++)
	{
		s->data[i]=s->data[i+1];
	}
	s->count--;
	return 1;
}
int get_search(seqlist_t *s,int value)
{
	int i;
	for(i=0;i<s->count;i++)
	{
		if(s->data[i]==value)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	seqlist_t *s=get_create();
	int x=get_insert(s,0,2);
	x=get_insert(s,1,6);
	x=get_insert(s,2,9);
	x=get_insert(s,3,3);
	get_print(s);
	printf("\n");
	x=get_delete(s,2);
	get_print(s);
	printf("\n");
	
	printf("empty?%d\n",get_empty(s));
	printf("full?%d\n",get_full(s));
	printf("length%d\n",get_length(s));
	printf("search?%d\n",get_search(s,2));
	get_clear(s);
	printf("empty?%d\n",get_empty(s));
	
}

//  练习： 用顺序表保存 26 字母。做插入和删除操作。 
typedef struct 
{
	char a[30];
	int last;
};

s->count=10;
strcpy(s->data,"abcdefgh");

int x=get_insert(s,0,'a');
	x=get_insert(s,1,'b');


// 预习链表。 
// 思考：如果用以下结构，如何实现保存、插入、删除数据？
typedef struct node_t 
{
	int data;
	struct node_t *next;
}linknode_t;




