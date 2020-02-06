day1：条件分支+循环编程

	1) 输出100-200之间的全部素数(素数：除了1和本身不能被任何其他数整除的数)

	2）函数实现计算表达式的值： 输入数据 例如：2+7  或者 4-3 或者 5*6 或者 8/2
#include<stdio.h>
void get_syshu(int num1,int num2,int *p)
{
	int i,j,flag;
	for(i=num1;i<num2;i++)
	{
		flag=1;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			*p=i;
			p++;
		}
		*p=-1;
	}
}
int get_num(int num1,int num2,char c)
{
	int a;
	switch(c)
	{
		case '+':
			a=num1+num2;
			break;
 	    case '-':
			a=num1-num2;
			break;
		case '*':
			a=num1*num2;
			break;
		case '/':
			a=num1/num2;
			break;
		default :
			printf("faluse input");
			break;
	}
	return a;
}
int main()
{
	/*
	int num1,num2;
	char ch;
	printf("shu ru\n");
	scanf("%d%d%c",&num1,&num2,&ch);
	printf("%d\n",get_num(num1,num2,ch));
	*/
	int a[100]={0};
	int num1,num2;
	int i=0;
	puts("请输入要求素数的区间");
	scanf("%d%d",&num1,&num2,a);
	get_syshu(num1,num2,a);
	while(a[i]!=-1)
	{
		printf("%d\n",a[i]);
		i++;
	}
	return 0;
}