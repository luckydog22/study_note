1.gedit  名字.c   ctrl q   实现代码复制粘贴

2.错误示例
int a[50];
a[]={.........};
要想分开写 只能：
 int a[50];
 a[0]=1;
 a[2]=2;
 ..........//可以部分输入
 a[]后面必须接东西
 
 3.有疑惑  没想明白//已解决
#include <stdio.h>
int main()
{
	int a[10];
	int i;
	int sum=0;
	float avg;
	int k;
	for(k=0;k<10;k++)
	{
		scanf("%d",&a[k]);//
		sum=sum+a[k];
	}
	/*
	for(i=0;i<10;i
	{
		sum=sum + a[i];
	}
	*/
	avg=sum/10.0;
	printf("sum is %d\navg is %f\n",sum,avg);
}

4.图形问题需要再考虑考虑//已解决
终究还是找规律
行数与空格星星的关系  详情day3

5.冒泡排序法//通
俩个for循环 外层长度减一   内层减一减外层  一个if交换 大于越来越大(交换时下标用内层)
大于越来越大，小于越来越小
#include <stdio.h>
int main()
{ 
	int i,j,t;
	int arr[]={55,32,68,31,72,98,21};
	for(i=0;i<7-1;i++)
	{
		for(j=0;j<7-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				t =arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	for(i=0;i<7;i++)
	{
		printf(" %d",arr[i]);
	}
	for(i=6;i>=0;i--)
	{
		printf(" %d",arr[i]);
	}
}
6.交换
(1)t
(2)
a=a-b
b=b+a
a=b-a
(3)异或

7.输入数字排序有问题
错误示例
#include <stdio.h>
int main()
{
	int i;
	int arr[10];
	int max=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>arr[i+1])
		{
			max=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=max;//这样俩俩交换只能得到每个俩俩之间的最大值，判断大小不能用前后项比较
			
		}
	}
	printf("%d\n",max);
}
改正：
算法思想：
假定第一个数永远最大为max，与后面的相比较若有大于该值的，则将更大者赋值给max，
这样就可以保证max里永远是最大值

边输入边判断
#include <stdio.h>
int main()
{
	int a[10];
	int i;
	int max,min;//用来保存最大值和最小值
	int flag = 1;
	//输入10个数
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);
		if(flag)
		{
			max = a[0];
			min = a[0];
			flag = 0;
		}
			max = max < a[i] ? a[i] : max;//永远让max中保存最大值
			min = min > a[i] ? a[i] : min;
     	}
	printf("%d\n%d\n",max,min);
}

8.字符串以 '\0'(代表数字0)结尾

9.数组键盘输入（scanf）不用加&   数组名代表数组的首地址
gets()//周末归类 11.14写

10.衡量字符串长度 用while
字符串长度 等于'\0'对应的下标


11.算法思想：
同步进行  分布进行
(1)分布进行
#include<stdio.h>
int main()
{
	char b[100];
 	char a[]="hello";
	int i=0;
	while(a[i] !='\0')
	{
		i++;
	}
	printf("%d\n",i);
	for(;i>=0;i--)
	{
		b[i]=a[i];
	}
	printf("%s",b);
	return 0;
}
(2)同步进行
#include <stdio.h>
int main()
		{
			int i = 0;
			char a[] = "hello";
			char b[100];
			while(a[i] != '\0')//a[i] == '\0'的是时候循环结束，说明'\0'没有拷贝给b数组
			{
				b[i] = a[i];
				i++;
			}
			b[i] = '\0'; //注意此处一定要将'\0'复制过去
			printf("b is %s\n", b);
		}


12.sizeof 判读占空间多少


问题
1.数组长度：实际长度为准  注意：字符数组，算实际长度不包括'\0'
sizeof()衡量的是 开辟内存空间大小

2.结束位是否打出:不打出




 