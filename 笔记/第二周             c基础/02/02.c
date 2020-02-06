1. *p=&a[0]   *p=a

2.字符串copy  while(*p++=*q++);

3.a[i]   a++;错误      2=2+1；
值相等   *(p+i) p[i]  a[i]  *(a+i) *
地址相等 p+i a+i &p[i] &a[i]

4.地址传递 改变实参的值

5.函数给调用者传递值：返回值    参数地址传递

6.strcmp("a","b")字符串比较函数前大是1 相等0 后大-1  

7.不给初始值 全局变量默认为0  局部变量默认随机值

8.利用地址实现逆序输出
	#include <stdio.h>
		void reverse(int *p, int n)
		{
			int temp;
			int *q = p+n-1;//q指向数组中的最后一个元素
			while(p < q)
			{
				temp = *p;
				*p = *q;
				*q = temp;
				p++;
				q--;
			}
		}
		void printArray(int *p,int n)
			{
				int i;
				for(i = 0; i < n; i++)
				{
					printf("%d ",p[i]);
				}
				printf("\n");
			}
		
		int main()
		{
			int a[5] = {1,2,3,4,5};
			printArray(a,5);
			reverse(a,5);
			printArray(a,5);
			return 0;
		}
		
		
		
		
		