 
复习：     
查找  
顺序查找：      数据无序、数据量不太大时使用。  
折半查找：      数据有序、
分块查找：      快间有序、块内可以无序。
哈希查找：      用什么样的方式去存，就用同样的方式去找。   (1) 如何构建哈希规则     (2)如何解决冲突

(1) 如何构建哈希规则 （将待存的数据 与 其 存储地址建立联系 ）
直接地址法 
平方取中法  
叠加法   
质数除余法  --->  11  x=0.75  L=15  p=13  
随机地址法     

(2)如何解决冲突
开放地址法、 
线性探查法、二次探查法、 
链地址法                                  struct *p[15];    p[10] = &节点  。 
备用表法




新课：    

一、排序： 
分类：   内排序和外排序  

内排序中： 五类 
插入排序    直接插入排序、折半插入排序、 链表插入排序（按照递增的次序插入数据）
交换排序    冒泡排序、快速排序  
选择排序    
归并排序
基数排序   

*快速排序示例代码： 
//////////////////////
#include <stdio.h>
void quik_sort(int *p,int start,int end)
{
	if(start >= end)     // 递归结束条件。
		return ;
	int i = start,j = end;    // i,j 代表可移动下标。 
	int x = p[start];         // 基准值。 

	while( i<j )     // 两个下标向中间趋近。 相等时，即止。
	{
		while(p[j] >= x && i<j)
			j--;
		if(i<j)
		{
			p[i] = p[j];
			i++;
		}
		while(p[i] <= x && i<j)
			i++;
		if(i<j)
		{
			p[j] = p[i];
			j--;
		}
	}
	p[i] = x;     // 基准值找到了存放位置。 
	quik_sort(p,start,i-1);     // 左侧使用快排
	quik_sort(p,i+1,end);       // 右侧使用快排
	return ;
}
int main()
{
	int a[] = {12,56,33,76,47,97,70,47,37,82,46};    // 原始数组
	quik_sort(a,0,10);       // 快排 

	int i;
	for(i=0; i<11; i++)
		printf("%d -- ",a[i]);     // 排序结果  
	printf("\n");
	return 0;
}

选择排序： 
////////////////
#include<stdio.h>
void get_choose(int *p,int n)
{
	int i,j,t,index;
	for(i=0;i<n-1;i++)
	{
		index = i;
		for( j=i+1;j<n;j++)
		{
			if(p[j]< p[index])
			{
				index = j;
			}
		}
		if(index != i )
		{
			t = p[i];
			p[i] = p[index];
			p[index] = t;
		}
	}
}
void get_printf(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d--",a[i]);
	}
}
int main()
{
	int a[]={1,0,9,7,3,2,6,4};
	get_choose(a,sizeof(a)/sizeof(int));
	get_printf(a,sizeof(a)/sizeof(int));
}

二、  树 
1. 一些基本概念  
树： 树（Tree）是n（n≥0）个节点的有限集合T，它满足两个条件 ：
		(1) 有且仅有一个特定的称为根（Root）的节点；
		(2) 其余的节点可以分为m（m≥0）个互不相交的有限集合T1、T2、……、Tm，
		其中每一个集合又是一棵树，并称为其根的子树（Subtree）
森林：
度：    节点的度：节点的子树的个数。   树的度：树中节点的最大度数就是树的度。 

深度（高度）：节点的层数等于父节点的层数加一，根节点的层数定义为一。

树中节点层数的最大值称为该树的高度或深度

叶节点： 度数为 0 的节点。 叶节点没有后继节点。 
根节点： 根节点没有前驱节点。 

树的逻辑关系： 树中节点的前驱节点，至多只能有一个。后继节点可以有零个或者多个。 

二叉树：  二叉树（Binary Tree）是n（n≥0）个节点的有限集合，它或者是空集（n＝0），
		或者是由一个根节点以及两棵互不相交的、分别称为左子树和右子树的二叉树组成。
		二叉树严格区分左右。 

满二叉树：  具有k层的二叉树，如果节点的个数为 2k-1 个（2的k次方减1个）。
那么这棵树称之为满二叉树。
完全二叉树：满足两个条件的二叉树。
(1)只有最下面两层有度数不为2的节点。 
(2)最下面一层的节点，都集中在左边的若干位置上。 


*2. 二叉树的存储  

1) 顺序存储：   
有n个节点的完全二叉树可以用有 n+1 个元素的数组进行顺序存储，
节点号和数组下标一一对应，下标为零的元素不用。利用以上特性，可以从下标获得节点的逻辑关系。
不完全二叉树通过添加虚节点构成完全二叉树，然后用数组存储，这要浪费一些存储空间。

2) 链式存储：  
typedef char data_t;
typedef struct node_t
{
	data_t data;
	struct node_t *lchild, *rchild;
}bittree_t;


*3. 二叉树的遍历   
由于二叉树的递归性质，在遍历二叉树时，可以使用递归的方式。  
先序遍历：  根左右  
中序遍历：  左根右 
后序遍历：  左右根 

// 示例代码： 
#include <stdio.h>
#include <stdlib.h>
typedef struct node_t 
{
	char data;
	struct node_t *lchild,*rchild;
}bitree_t;
// 先序遍历  
void pre_order(bitree_t *root)
{
	if(root == NULL)      // 因为是递归函数，所以结束条件不要忘记！！！
		return ;
	printf("%c ",root->data);
	pre_order(root->lchild);
	pre_order(root->rchild);
	return ;
}
// 中序遍历  
void in_order(bitree_t *root)
{
	if(root == NULL)
		return ;
	in_order(root->lchild);
	printf("%c ",root->data);
	in_order(root->rchild);
	return ;
}
// 后序遍历   
void post_order(bitree_t *root)
{
	if(root == NULL)
		return ;
	post_order(root->lchild);
	post_order(root->rchild);
	printf("%c ",root->data);
	return ;
}
// 测试函数  
int main()
{
	bitree_t A = {'A',NULL,NULL};
	bitree_t B = {'B',NULL,NULL};
	bitree_t C = {'C',NULL,NULL};
	bitree_t D = {'D',NULL,NULL};
	bitree_t E = {'E',NULL,NULL};
	bitree_t F = {'F',NULL,NULL};
	bitree_t G = {'G',NULL,NULL};

	A.lchild = &B;
	B.lchild = &C;
	B.rchild = &D;
	D.lchild = &E;
	D.rchild = &F;
	E.rchild = &G;

	pre_order(&A);
	putchar('\n');
	
	in_order(&A);
	putchar('\n');

	post_order(&A);
	putchar('\n');
	return 0;
}


*4. 根据遍历顺序，画出二叉树  


先序： A B C D E F G H K 
中序： B A E D G F H K C  


5. 赫夫曼树

// 作业： 创建一棵二叉树，分别实现先序、中序、后序遍历。 
#include<stdio.h>
typedef struct tree
{
	char data;
	struct tree *lchild,*rchild;
}bitree_t;
void get_pre(bitree_t *root)
{
	if(root==NULL) return;
	printf("%c-",root->data);
	get_pre(root->lchild);
	get_pre(root->rchild);
}
void get_mid(bitree_t *root)
{
	if(root==NULL) return ;
	get_mid(root->lchild);
	printf("%c-",root->data);
	get_mid(root->rchild);
}
void get_behind(bitree_t *root)
{
	if(root==NULL) return;
	get_behind(root->lchild);
	get_behind(root->rchild);
	printf("%c-",root->data);
}
int main()
{
	bitree_t A = {'a',NULL,NULL};
	bitree_t B = {'b',NULL,NULL};
	bitree_t C = {'c',NULL,NULL};
	bitree_t D = {'d',NULL,NULL};
	bitree_t E = {'e',NULL,NULL};

	A.lchild = &B;
	A.rchild = &C;
	C.lchild = &D;
	D.lchild = &E;

	get_mid(&A);
	printf("\n");
	get_pre(&A);
	printf("\n");
	get_behind(&A);
	printf("\n");
}

//作业： 一个字符串中可能包含a-z中的多个字符，字符也可能重复，例如char a[] = "dfafdafdafdfdffefdf";
写一个程序，对于给定一个这样的字符串，求出字符串中出现次数最多的那个字母以及出现的次数
（若次数最多的字母有多个，则全部求出）。方式任选
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char ch;
	int count1;
	struct node  *next;
}node_t;
int main()
{
	char a[] =" fffff";
	int i,j;
	int n=sizeof(a)/sizeof(char)-1;
	int count;
	int flag=0;
	node_t *h = (node_t *)malloc(sizeof(node_t));
	h->next = NULL;
	node_t *p = h;
	node_t *new;

	for(i=0;i<n;i++)
	{
		count=1;
		if(flag)
		{
			if(a[i]=='0')
			{
				continue;
			}
		}
		for(j=1+i;j<n;j++)
		{
			if(a[i]==a[j])
			{	
				count++;

				a[j]='0';
				
			}
		}
		new=(node_t *)malloc(sizeof(node_t));
		new->ch = a[i];
		new->count1 = count;
		new->next = p->next;

		p->next = new;

		p = new;
		flag=1;

	}
	p = h;
	p = p->next;
	char zm = p->ch ;
	int cs = p->count1;
	while(p!=NULL)
	{
		if(cs<p->count1)
		{
			zm = p->ch;
			cs = p->count1;
		}
		p=p->next;
	}
	printf("zi mu:%c\nci shu:%d\n",zm,cs);
}

