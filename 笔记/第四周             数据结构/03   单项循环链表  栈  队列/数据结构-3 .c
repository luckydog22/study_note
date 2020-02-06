
复习：
 
1. 顺序表  
typedef struct  
{
	int a[100];
	int last;
}sqlist_t;

2. 链表
typedef struct node_t 
{
	int a;
	struct node_t *next;
}linknode_t, *linklist_t;

3. 单项循环链表     tail->next = h->next;

4. 双向链表
typedef struct node_t 
{
	int a;
	struct node_t *prev,*next;
}linknode_t, *linklist_t;

(1) 插入       // 新节点是new,待插入位置的前一个节点是 p 
new->prev = p; 
new->next = p->next;
p->next->prev = new; 
p->next = new;

(2) 删除     // 待删除节点为 new, 待删除的前一个节点为 p 
new->next->prev = p; 
p->next = new->next;
free(new);



新课 
一、 单项循环链表        应用实例：约瑟夫问题
////////////////////////
#include <stdio.h>
#include <stdlib.h>
typedef struct node_t 
{
	int number;
	struct node_t *next;
}linknode_t, *linklist_t;
int main()
{
	linklist_t h = (linklist_t )malloc(sizeof(linknode_t));    // 创建第一个节点 
	h->number = 1;  
	h->next = NULL; 

	int i,m = 4,n = 8,k = 3;//k是起始位置
	linklist_t new,p = h;
	for(i=2; i<=8; i++)       // 创建余下的节点。 
	{
		new = (linklist_t )malloc(sizeof(linknode_t));
		new->number = i;  
		new->next = NULL; 
		
		p->next = new;
		p = p->next;
	}
	p->next = h;    // 单项链表从此变为循环链表。 

	while(--k)
		h = h->next;    // 找到数数的起始位置。 

	while(h->next != h)    // 只要节点数多于一个就循环。 
	{
		i=m-1;       // 数数从 1 到 m 指针移动 m-1 次。 
		while(--i)
			h = h->next;  // h 要移动到待删除位置的前一个节点。 
		
		p = h->next;      // p 指向待删除节点。 
		h->next = p->next;
		printf("%d -- ",p->number);
		free(p);

		h = h->next;  // 为下一次数数做准备。 
	}
	printf("\nThe last number: %d\n",h->number);   // 最后一个节点。 
	free(h);
	return 0;
}

二、 栈 
定义： 栈是限制在一端进行插入和删除操作的线性表。  

栈顶： 允许操作的一端。 
栈底： 固定的一端。 
空栈： 没有保存有效数据的栈。  

特点： 后进先出（LIFO）

基本运算： 
//////////////////
#include <stdio.h>
#include <stdlib.h>
#define MAX 26
typedef struct 
{
	int data[MAX];
	int top;
}sqstack_t;
// 创建空栈
sqstack_t *CreateEmptyStack()
{
	sqstack_t *s = (sqstack_t *)malloc(sizeof(sqstack_t));
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
	return (s->top == MAX);
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
// 获取栈顶元素。
int GetTop(sqstack_t *s)
{
	if(EmptyStack(s))
		return -1;
	return s->data[s->top-1];
}
// 测试代码。 
int main()
{
	sqstack_t *s = CreateEmptyStack();	
	PushStack(s,1);
	PushStack(s,2);
	PushStack(s,3);
	PushStack(s,4);

	while( !EmptyStack(s) )   // 数据出栈，直到栈空为止。 
		printf("%d - ",PopStack(s));
	
	return 0;
}



///////////////
#include <stdio.h>
#include <stdlib.h>
#define N 30
typedef int data_t;
typedef struct 
{
	data_t data[N];
	data_t top;
}stack_t;
//create
stack_t *get_create()
{
	stack_t *s=(stack_t *)malloc(sizeof(stack_t));
	s->top=0;
	return s;
}
//empty
int get_empty(stack_t *s)
{
	return (s->top==0);
}
//full
int get_full(stack_t *s)
{
	return (s->top==N);
}
//insert
int get_push(stack_t *s,int value)
{
	if(!get_full(s))
	{
		s->data[s->top++]=value;
		return 1;
	}
	return -1;
}
//delete
int get_delete(stack_t *s)
{
	int i;
	if(!get_empty(s))
	{
		for(i=s->top-1;i>=0;i--)
		{
			printf("%d\n",s->data[i]);
		}
			return 1;
	}
	return -1;
}
//get top
int get_top(stack_t *s)
{
	if(!get_empty(s))
	return (s->data[s->top-1]);
}
int main()
{
	stack_t *s=get_create();
	get_push(s,20);
	get_push(s,21);
	get_push(s,22);
	get_push(s,23);
	printf("empty?%d\n",get_empty(s));
	printf("full?%d\n",get_full(s));
	printf("top?%d\n",get_top(s));
	
	get_delete(s);



}
// 练习： 请将 26 个字母入栈，再出栈。 
// 基本运算上面示例中有。不再重复。
int main()
{
	sqstack_t *s = CreateEmptyStack();
	int i;
	for(i=0; i<26; i++)
		PushStack(s,'a'+i);

	while( !EmptyStack(s) )   
		printf("%c - ",PopStack(s));
	
	return 0;
}





三、队列  
定义：  队列时限制在两端进行插入和删除操作的线性表。 

队头： 数据出队的一端。 
队尾： 数据入队的一端。 
空队： 没有有效数据的队列 是空队。  

特点： 先入先出。 

约定： 
1） front指向队头元素的前一个位置; rear指向队尾元素所在位置。
2） front指向队头元素的位置; rear指向队尾元素的下一个位置。
3） 在队列操作过程中，为了提高效率，以调整指针代替队列元素的移动，并将数组作为循环队列的操作空间。
4） 为区别空队和满队，满队元素个数比数组元素个数少一个。

基本运算： 
//////////////////
#include <stdio.h>
#include <stdlib.h>
#define MAX 9
typedef struct 
{
	int a[MAX];
	int front,rear;
}sequeue_t;
// 创建空队
sequeue_t *CreateEmptyQueue()
{
	sequeue_t *q = (sequeue_t *)malloc(sizeof(sequeue_t));
	q->front = q->rear = 0;
	return q; 
}
// 清空队列
void ClearQueue(sequeue_t *q)
{
	q->front = q->rear = 0;
}
// 判断队列是否空
int EmptyQueue(sequeue_t *q)
{
	return (q->front == q->rear)?1:0 ;
}
// 判断队列是否满。 
int FullQueue(sequeue_t *q)
{
	return (  (q->rear+1)%MAX == q->front );
}
// 数据入队。 
int EnterQueue(sequeue_t *q, int data)
{
	if( FullQueue(q) )
		return -1;

	q->a[q->rear] = data;
	q->rear = (q->rear+1)%MAX;     // 数据入队。移动的是队尾指针。
	return 0;
}
// 数据出队 
int DeleteQueue(sequeue_t *q)
{
	if( EmptyQueue(q) )
		return -1;

	int x = q->a[q->front];
	q->front = (q->front+1)%MAX;   // 数据出队移动的是队头指针。 
	return x;
}
// 测试函数
int main()
{
	sequeue_t *q = CreateEmptyQueue();
	EnterQueue(q,11);
	EnterQueue(q,21);
	EnterQueue(q,31);
	EnterQueue(q,41);
	EnterQueue(q,51);

	while( !EmptyQueue(q) )
		printf("%d - ",DeleteQueue(q));
	printf("\n");
	return 0;
}


// 作业1： 使用栈计算 “4+8*2-3”

042


///作业2. 链表节点中，存放的是学生信息。 可以由输入决定信息内容。保存信息并输出。 
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
}linknode_t;
//////////////////////////////046
#include<stdio.h>
#include<stdlib.h>
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
}linknode_t;
linknode_t *get_Create()
{
	linknode_t *p =(linknode_t *)malloc(sizeof(linknode_t));
	p->next = NULL;
	return p;
}
int get_empty(linknode_t *p)
{
	return (p ==NULL);
}
int main()
{
	int n;
	scanf("%d",&n);
	linknode_t *h = get_Create();
	int i;
	linknode_t *p;
	p = h;
	for(i = 0;i<n;i++)
	{
		linknode_t *new = (linknode_t *)malloc(sizeof(linknode_t));		
		scanf("%s%d%d",new->s.name,&new->s.age,&new->s.grade);
		new->next = NULL;
		p->next = new;

		p = p->next;
	}
	p = h->next;
	while(!get_empty(p))
	{
		printf("%s-- %d--%d\n",p->s.name,p->s.age,p->s.grade);
		p = p->next;
	}
}


//作业3： 两个有序表，形成一个新的有序表
// 完成功能： 创建空链表、求表长、遍历链表、插入、清空、实现合并、测试函数。
A  :  11   33    44    77    99 
B  ： 22   55    66    88
合并后 : 11 22 33 44 55 66 77 88 99

047
#include<stdio.h>
#include<stdlib.h>
#define N1 5
#define N2 4

typedef struct number1
{
	int data;
	struct number1 *next;

}number1_t;
typedef struct number2
{
	int data;
	struct number2 *next;

}number2_t;
typedef struct number3
{
	int data;
	struct number3 *next;

}number3_t;

number1_t *get_create1()
{
	number1_t *p = (number1_t *)malloc(sizeof(number1_t));
	p->next = NULL;
	return p;
}
number2_t *get_create2()
{
	number2_t *p = (number2_t *)malloc(sizeof(number2_t));
	p->next = NULL;
	return p;
}
number3_t *get_create3()
{
	number3_t *p = (number3_t *)malloc(sizeof(number3_t));
	p->next = NULL;
	return p;
}
int main()
{
	number1_t *h1 = get_create1();
	number2_t *h2 = get_create2();
	number3_t *h3 = get_create3();

	int i,j;
	number1_t *new1,*p1;
	number2_t *new2,*p2;
	number3_t *new3,*p3;
	p1 = h1;
	for(i=0;i<N1;i++)
	{
		new1 = (number1_t *)malloc(sizeof(number1_t));
		scanf("%d",&new1->data);
		new1->next = NULL;
		p1->next = new1;
		p1 = p1->next;
	}
	p2 = h2;
	for(i=0;i<N2;i++)
	{
		new2 = (number2_t *)malloc(sizeof(number2_t));
		scanf("%d",&new2->data);
		new2->next = NULL;
		p2->next = new2;
		p2 = p2->next;
	}
	p1 = h1;
	p2 = h2;
	p3 = h3;
	if(p1->next->data >p2->next->data)
	{
		p3->next = p2->next;
		p2 = p2->next;
	}
	else
	{
		p3->next = p1->next;
		p1 = p1->next;
	}
	
	while(p1 && p2)
	{
		if(p1->data < p2->data)
		{

			p3->next=p1;
			p1 =p1->next;
			p3 = p3->next;
		}
		else
		{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
	}
	if(p1==NULL)
	{
		p3->next = p2;
	}
	else
	{
		p3->next = p1;
	}
	p3 = h3->next;
	while(p3!=NULL)
	{
		printf("%d\n",p3->data);
		p3 =p3->next;
	}

}
