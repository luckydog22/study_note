
一、复习 

1. 顺序表的结构：
typedef struct {
	int a[100];       // 用来保存有效数据
	int last;         // 用来保存有效数据的个数。 
}seqlist_t;

2. 特点： 
(1) 数据的存储密度大。          
(2) 数据在进行插入、删除等操作时，可能会出现数据成片移动的现象。 降低处理数据的效率。
(3) 存储数据时，指定某个位置比较方便。



//步骤
1：创建新节点

2.新节点初始化

3.挂在原链表上

4.指针移动


二、链表 

1. 链式结构    ：   数据域、指针域
typedef struct node_t 
{
	int data;             // 保存的当前的有效数据。 
	struct node_t *next;     // 指向下一个节点的指针。 
}linknode_t;


2. 单项链表

（1）示例
#include <stdio.h>
#include <stdlib.h>
typedef struct node_t        // 链式结构
{
	int data;
	struct node_t *next;        
}linknode_t;
//示例代码 
int main()
{
	linknode_t *h = (linknode_t *)malloc(sizeof(linknode_t));   // 1.申请一个新节点
	h->data = 11;
	h->next = NULL;       // 2.新节点赋值

	int i;
	linknode_t *new, *p = h;  // 两个指针：new:作用是用来指向新节点。 p 用来将新节点连接到链表中 。 
	for(i = 22; i<100; i+=11)     // 重复创建几个节点。 
	{
		new = (linknode_t *)malloc(sizeof(linknode_t));   // 1. 申请新节点。
		new->data = i;
		new->next = NULL;   // 2. 新节点赋初值 

		p->next = new;   // 3. 新节点挂接到链表上。 
		
		p = new;         // 4. 指针向下移动一个位置，为下次再挂接新节点做准备。 
	}
	p = h;      // 指针重新指向首位置。 
	while(p != NULL)     // 从首位置开始遍历链表。 
	{
		printf("%d  - ", p->data);     // 打印链表中的节点数据。 
		p = p->next;                  // 指针向后移动一个节点。 
	}
	return 0;
}

//自己代码

#include<stdio.h>
#include<stdlib.h>

//节点基本组成
typedef struct link_node    
{
    int data;
    struct link_node* next;
}link;

int main()
{
    //创建头节点
    link * h = (link *)malloc(sizeof(link));
    h->data = 20;
    h->next = NULL;

    int i;
    link *new,*p = h;
    for(i = 0;i < 20;i++)
    {
        //1.创建新节点
        new = (link*)malloc(sizeof(link));
        //2.新节点初始化
        new ->data = i;
        new ->next = NULL;
        //3.挂在链表上（先保存别人的，再自己上）
        p ->next = new;
        //4.指针移动
        p = p->next;
    }

    p = h;
    while (p != NULL )
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}

// 练习：请完成一个链表。 包含以下数据。并输出。 
"zhao","qian","sun","li","zhou","wu","zheng","wang"

//自己写的的额
#include<stdlib.h>
#include<stdio.h>

typedef struct link_node
{
    char *name;
    struct link_node* next;
}link;


int main()
{
    char* name1[] = {"zhao","qian","sun","li","zhou","wu","zheng","wang"};

    //创建头节点
    link* h = (link *)malloc( sizeof(link) );
    h->name = name1[0];
    h->next = NULL;

    //逐步加入节点
    int i;
    link* p = h,*new;
    for(i = 1;i< sizeof(name1)/sizeof(name1[0]);i++)
    {
        //1.创建新接点
        new = (link *)malloc(sizeof(link));
        //2.新节点初始化
        new ->name = name1[i];
        new ->next = NULL;
        //3.挂在链表上
        p->next = new;
        //4.指针偏移
        p = p->next;
    }

    //遍历链表
    p = h;
    while(p != NULL)
    {
        printf("%s\n",p->name);
        p = p->next;
    }
 
    return 0;
}


////// 老师的代码
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_t 
{
	char name[10];          // 定义的数组是为了保存字符串。也就是一个数据单元。 
	struct node_t *next;
}linknode_t;
int main()
{
	char *name[8] = {"zhao","qian","sun","li","zhou","wu","zheng","wang"};    // 指针数组
	
	linknode_t *h = (linknode_t *)malloc(sizeof(linknode_t));    // 空的头结点： 不保存有效数据的节点。作为链表的起始点。
	h->next = NULL;             // 仅将指针域赋初值即可。 

	int i;
	linknode_t *new, *p = h;
	for(i=0; i<8; i++)
	{
		new = (linknode_t *)malloc(sizeof(linknode_t));    // 分配空间分别保存每个值。 
		strcpy(new->name,name[i]);
		new->next = NULL;

		p->next = new;
		p = new;
	}
	p = h;
	while(p->next != NULL)     // 遍历。  条件是： p->next != NULL 
	{
		p = p->next;
		printf("%s  - ", p->name);
	}
	return 0;
}

（2） 关于空头结点的问题。    
a.   以上两个示例当中，第一个例子没有带空的头结点，第二个示例当中，带空的头结点。 
b.   一般，我们在处理单项链表时，多数都会选择带空的头结点这种写法。 

头结点的作用是：代表链表的稳定的起始位置。
				以保证后续插入、删除节点等操作不会对链表起始位置造成太大影响。
				（有一个稳定的起始点。并且，链表可以是空链表） 

3. 链表的基本运算 
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
		printf("%d  - ", h->data);
	}
}
// 求链表长度。 
int LengthLinklist(linklist_t h)
{
	int length = 0;
	while(h->next != NULL)
	{
		h = h->next;
		length ++;
	}
	return length;
}
// 按位置插入数据，成功返回0，失败返回-1. 
int InsertLinklist_1(linklist_t h, data_t data,int pos)
{
	if(pos<=0 || pos> LengthLinklist(h)+1 )    // 如果不是合理位置，容错处理掉。 
		return -1;
		
	while( --pos )
		h = h->next;    // 指针移动到待插入位置的前一个节点。   （步骤1：找位置。）

	linklist_t new = (linklist_t )malloc(sizeof(linknode_t));     // 要插入的节点。 （步骤2：创建新节点）
	new->data = data;
	new->next = h->next;     //（步骤3：新节点赋值）

	h->next = new;          // 步骤4： 将新节点挂到链表中。 
	return 0;
}
// 按递增的次序插入数据。 
void InsertLinklist_2(linklist_t h, data_t x)
{
	while( h->next != NULL  && x > h->next->data)      // 如果 h 有 next 节点。 并且待插入数据大于下一个节点的数据。 则指针继续移动。 
		h = h->next;	       // 此循环的目的是：将指针移动到待插入位置的前一个节点。 
	
	linklist_t new = (linklist_t )malloc(sizeof(linknode_t));    // 创建新节点。 
	new->data = x;
	new->next = h->next;     // 新节点赋值。 

	h->next = new;        // 将新节点放在链表中。 
	return ;	
}
// 删除某个位置的节点。 成功返回0，失败返回-1
int DeleteLinklist(linklist_t h, int pos)
{
	if(pos<=0 || pos>LengthLinklist(h) || EmptyLinklist(h))    // 判定位置是否合理，链表是否为空。 
		return -1;

	while(--pos)
		h = h->next;    // 移动指针到：待删除位置的前一个位置。 

	linklist_t p = h->next;   // 指针p 指向待删除节点。 
	h->next = p->next;        // p 将自己的下一个节点地址，交给上一个节点。
	free(p);                  // 释放掉 p 即可。
	return 0;
}
// 删除值为 value 的节点。  
void DeleteLinklist_2(linklist_t h, data_t value)
{
	while(h->next != NULL)     // 遍历查找即可。 
	{
		if(h->next->data == value)    // 如果有这个值。 
		{
			linklist_t p = h->next;    // p 指向待删除节点。
			h->next = p->next;  
			free(p);
		}
		else 
			h = h->next;    // 如果当前值不是要找的值，继续判断下一个。 
	}
	return ;	
}
// 查找是否有值为 data 的节点。如果有，返回编号。如果没有，返回-1. 
int SearchLinklist(linklist_t h, data_t data)
{
	int number = 0;
	while(h->next != NULL)
	{
		h = h->next;
		number++;
		if(h->data == data)
			return number;
	}
	return -1;
}
// 获取某个位置的值。成功返回0，失败返回-1
int GetLinklist(linklist_t h, int pos, data_t *d)
{
	if(pos<=0 || pos>LengthLinklist(h))    // 判定是否为合法位置。 
		return -1;

	while(pos--)
		h = h->next;     // 将指针移动到当前位置即可。 
	*d = h->data;       // 将找到的值，赋值给 “指针d所指的变量”
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
// 测试函数（调用上述函数，检测功能是否正常）
int main()
{
	linklist_t h = CreateEmptyLinklist();	  // 创建  
	
	InsertLinklist_1(h,11,1);
	InsertLinklist_1(h,2,1);
	InsertLinklist_1(h,13,3);       // 插入 
	InsertLinklist_1(h,90,4);
	InsertLinklist_2(h,22);

	VisitLinklist(h);               // 遍历  
	int n;
	GetLinklist(h,4,&n);		    // 获取  
	printf("%d\n",n);
	
	n = SearchLinklist(h,90);       // 查找  
	if(n == -1)
		printf("Not found!\n");
	else 
		printf("Number: %d\n",n);  
	ClearLinklist(h);                // 清空
	return 0;
}




三、作业 
//作业1. 链表节点中，存放的是学生信息。 可以由输入决定信息内容。保存信息并输出。 
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





//作业2： 两个有序表，形成一个新的有序表
// 完成功能： 创建空链表、求表长、遍历链表、插入、清空、实现合并、测试函数。
A  :  11   33    44    77    99 
B  ： 22   55    66    88
合并后 : 11 22 33 44 55 66 77 88 99






