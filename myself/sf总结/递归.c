#include<stdio.h>
#define N(x)  (x)%2==0
int Fibo(int x)
{
	if(x==1 || x==2)
	{
		return 1;
	}
		int res=Fibo(x-1)+Fibo(x-2);
		return res;
}
int jie(int x)
{
	if(x==1)
	{
		return 1;
	}
	int res= x+jie(x-1);
	return res;
}
int main(int argc,const char *argv[])
{
	printf("%d\n",N(11111));
	
} 