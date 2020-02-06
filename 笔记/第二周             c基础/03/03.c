1.scanf("");内部不要和"\n"
输入非地址量 必须加&

2.形参指针必须标明类型

3.malloc(整数)
动态分配(堆)
加头文件
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
int get_sum(int *p,int n)
{
	int i;
	int sum=0;
	p=malloc(n * sizeof(int));
	if(p!=NULL)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",p+i);
			sum=sum+*(p+i);
		}
		free(p);
		return sum;
	}

}
int main()
{
	int n;
	int *p;
	scanf("%d",&n);
	printf("%d\n",get_sum(p,n));
}

字符串是常量