#include<stdio.h>
int main(int argc,const char *argv[])
{
	int a[3][2]={{1,2},{3,4},{5,6}};
	int (*p)[2]=a;
	int (*q)=a[0];
	int i,j;
	printf("%p\n",*(p+1));
	printf("%p\n",q+1);
	/*
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\n",p[i][j]);
		}
	}
	*/
	/*
	for(i=0;i<6;i++)
	{
		printf("%d\n",*(q+i));
	}
	*/
	
}


二维数组地址，在内存里 和一维数组类似  二维数组内部存了每一行的行地址   
#include<stdio.h>
int main()
{
	int a[2][3]={{1,2,3},{4,5,6}};
	int (*p)[3]=a;
	int i;
	for(i=0;i<6;i++)
	{
		printf("%d\n",*((*p)+i));
	}
}