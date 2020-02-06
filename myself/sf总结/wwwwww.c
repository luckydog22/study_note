#include<stdio.h>
void get_syshu(int num1,int num2,int *p)
{
	int i,j,k,flag;
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
			for(k=0;k<(num2-num1);k++)
			{
				p[k]=i;
			}
		}
			p[i]=-1;
	}
}
int get_num(int num1,int num2,char c)
{
	int a;
	switch (c)
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
	}
	return a;
}
int main()
{
	int num1,num2;
	char ch;
	printf("shu ru\n");
	getchar();
	scanf("%d%d%c",&num1,&num2,&ch);
	printf("%d\n",get_num(num1,num2,ch));
	/*
	int a[100]={0};
	int num1,num2;
	int i=0;
	puts("请输入要求素数的区间");
	getchar();
	scanf("%d%d",&num1,&num2);
	get_syshu(num1,num2,a);
	while(a[i]!=-1)
	{
		printf("%d\n",a[i]);
	}
	*/
	return 0;
}