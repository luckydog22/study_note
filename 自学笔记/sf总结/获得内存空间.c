8.编写函数，实现功能： 获取一块内存空间保存数据
(1)通过二级指针修改一级指针的地址
(2)通过返回一级指针的地址，
注意点，
指针初始化为NULL，判空一下，手动释放

#include<stdio.h>
#include<stdlib.h>
void get_place(int **p,int x)
{
	*p=(int *)malloc (sizeof(int) * x);
}
int main()
{
	
	int *q=NULL;
	get_place(&q,10);
	if(q!=NULL)
	{
		q[1]=4;
		printf("1\n");
		printf("%d\n",q[1]);
		free(q);
	}
} 

#include<stdio.h>
#include<stdlib.h>
int  *get_place(int x)
{
	int *p=(int *)malloc (sizeof(int) * x);
	return p;
}
int main()
{
	int *q=NULL;
	q=get_place(&q,10);

	if(q!=NULL)
	{
		q[1]=4;
		printf("1\n");
		printf("%d\n",q[1]);
		free(q);
	}

} 