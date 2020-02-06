day2：数组编程
	1) 已知存在数据， int data[vb	] = {97,43,21,56,71,33,41,17,28,42,90,88,83};
	  函数实现：把数据从大到小排序



	2）已知存在数据， int data[] = {97,43,21,56,71,33,41,17,28,42,90,88,83};
	  函数实现：找出数据中最大值的存放位置（数组下标值）
#include<stdio.h>
void get_big_small(int *p,int n)
{
	int i,j;
	int t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(p[j]<p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
}
void get_print(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",p[i]);
	}
}
int get_down_flag(int *p,int n)
{
	int i;
	int maxIndex=0;
	for(i=1;i<n;i++)
	{
		if(p[maxIndex]<p[i])
		{
			maxIndex=i;
		}
	}
	return maxIndex;
}
int main()
{

	/*降序输出
	int data[]={97,43,21,56,71,33,41,17,28,42,90,88,83};
	int n=sizeof(data)/sizeof(data[0]);
	get_big_small(data,n);
	get_print(data,n);
	*/
	/*最大值下标
	int data[]={97,43,21,56,71,33,41,177,28,42,900,88,83};
	int n=sizeof(data)/sizeof(data[0]);
	int t=get_down_flag(data,n);
	printf("%d\n",t);
}

求数组中最大值，和，最大下标
思想：引入另一个变量
默认：数组中第一个元素最大，下标最大
max=a[0];
if(max<a[i])
{
	max=a[i];
}
return max;

maxIndex=0;
if(p[maxIndex]<a[i])
{
	maxIndex=i;
}
return maxIndex;

a[i]>a[i+1] 在涉及到最大值时 不能用，缺陷：只能实现相邻数字的比较，取得结果是每俩个数中的最大值