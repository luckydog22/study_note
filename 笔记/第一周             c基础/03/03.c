1.类型转换 char short int long float double 由小变大自然转换  大变小强制转换 例如（int）b

2.输出函数
字符 ：putchar('')只能打印单个字符 ；
字符串：puts("")打印字符串 并且可以自动换行，
与格式化输出函数printf，区别就是不能%那样输出

printf("%d"，num)
puts("hello world");
putchar('a');

输入函数：
字符输入：getchar()//键盘输入一位字符

补充：以进制输出，例如%x 16进制输出 0xff  若大写x 则0xFF

3.b=3.149   printf("b is %.2f\n",b);
保留俩位小数，并且遵循四舍五入规则

4.getchar()功能
#include <stdio.h>
#define PI 3.14
int main()
{
	int a=getchar();
	printf("a is %d\n",a);
	getchar();//消掉Enter
	int b=getchar();
	printf("b is %d\n",b);
}
5.字符数字转换  类型转换有问题//已解决
6.for死循环  
for(;;)
{}

7.直接打印图形时(行列关系的算法)
(1)每行同形状，那就各自考虑就行
        #####
		#####
		#####
		
		#include <stdio.h>
		int main()
		{
			int i, j;
			for(i = 0; i < 3; i++)
			{
				//printf("#####\n");
				for(j = 0; j < 5; j++)
				{
					printf("#");
				}
				printf("\n");
			}
		}
每行不一样，那就要考虑行与列的关系
(2)
*
**
***
****· 
#include <stdio.h>

	int main(int argc, const char *argv[])
		{
			int i,j;
			for(i = 0; i < 5; i++)
			{
				for(j = 0; j <= i; j++)
				{
					printf("*");
				}
				printf("\n");
			}
			return 0;
		}	
(3)键入几出现几行的金字塔(找规律： i 空格 星星)
        *
	   ***
	  *****
	 *******
    *********


8.return; 在此处结束程序
9.c语言中 函数只能返回一个返回值
10.if(!num)    if(num == 0)  等价
11.出现undefined reference    gcc oo.c -lm 解决