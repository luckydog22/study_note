#include<stdio.h>

struct worker
{
	char name[10];
	char Bnumber[10];
	int age;
	float money;
};

void get_insert(struct worker *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
  		scanf("%s%s%d%f",p[i].name,p[i].Bnumber,&p[i].age,&p[i].money);
	}
}
void get_Agelow25(struct worker *p,int n,int *a)
{
	int i;
	int j=0;
	for(i=0;i<n;i++)
	{
		if(p[i].age>25)
		{
			a[j]=i;
			j++;
		}
	}
}
int main()
{
	struct worker w1[100];
	struct worker *w=w1;
	int n;
	int i=0;
	int a[100];
	puts("please input ren shu.Next shu ru information");
	scanf("%d",&n);
	get_insert(w,n);
	get_Agelow25(w,n,a);
	puts("************************************");
	while(a[i]!=0)
	{
  		printf("%s\n%s\n%d\n%f\n",w1[a[i]].name,w1[a[i]].Bnumber,w1[a[i]].age,w1[a[i]].money);
		i++;
	}
	return 0;
}

xiaoli
//////方法一 返回时下标
		#include <stdio.h>
		#include <string.h>

		struct student
		{
			char name[20];
			int age;
			int score;
		};//一定要有;号

		//输入学生信息
		void set_all(struct student *p,int n)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				scanf("%s%d%d",p[i].name,&p[i].age,&(p+i)->score);
			}
		}
		//通过名字查找学生
		int find_by_name(struct student *p, int n,char *name)//name代表查询的学生的名字
		{
			int i = 0;
			for(i = 0; i < n; i++)
			{
				if(strcmp(p[i].name,name) == 0)//判断两个字符串是否相等用strcmp
				{
					return i;
				}
			}
			return -1;//证明没有找到
		}


		int main(int argc, const char *argv[])
		{
			struct student s[3];
			//输入学生信息
			set_all(s,3);
			int i = find_by_name(s,3,"xiaoli");
			if(i != -1)
			{
				printf("%s %d %d\n",s[i].name,s[i].age,s[i].score);
			}
			else
			{
				printf("没有找到!!!\n");
			}
			return 0;
		}
二进制下1的个数		