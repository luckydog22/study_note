1.动态分配变相的实现了动态数组
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i, sum = 0;		
	int *p;
	printf("please input num: ");
	scanf("%d", &n);			//输入n值
	p = malloc(n * sizeof(int));		//分配n个int
	if(p != NULL)//如果不为NULL，说明申请空间成功
	{
		printf("please input score: ");
		for(i = 0; i < n; i++)
		{
				scanf("%d", &p[i]);		//输入成绩		
	    }
		for(i = 0; i < n; i++)
		{
			sum += p[i];			//求总成s绩
		}
		printf("avg is %d\n", sum / n);
		free(p);	//释放内存		
	}
}	



