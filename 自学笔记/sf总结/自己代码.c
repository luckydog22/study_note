#include<stdio.h>
/*
int get_shuixianhua(int a)
{
	int flag=0;
	int g,s,b;
	g=a%10;
	s=a/10%10;
	b=a/100;
	if(a==g*g*g+b*b*b+s*s*s)
	{
		flag=1;
	}
	return flag;
}
void get_sushu(int num1,int num2)
{
	int i;
	int j;
	for(i=num1;i<num2;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				break;
			}
		}
		if(i==j)
		{
			printf("%d\n",i);
		}
	}
}
void get_Next_second(int h,int m,int s)
{
	s++;
	if(s>59)
	{
		s=0;
		m++;
		if(m>59)
		{
			m=0;
			h++;
			if(h>23)
			{
				h=0;
			}
		}
	}
	printf("%02d:%02d:%02d\n",h,m,s);
}
*/
void get_Fibo(int n)
{
	int a[100]={1,1};
	int i;
	for(i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
int get_1(int n)
{
	int i=0;
	int count=0;
	while(n!=0)
	{
		if(n%2==1)
		{
			count++;
		}
		n=n/2;
		i++;
	}
	return count;
}
void get_maopao()
{
	int a[10]={11,25,23,4,5};
	int i,j,t;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
}
int get_12(int n)
{
	int i=0;
	int count=0;
	while(n!=0)
	{
		if(n&1)
		{
			count++;
		}
	  	n=	n>>1;
		i++;
	}
	return count;
} 
void get_remove(char *p)
{
	int i=0,j;
	while(p[i]!='\0')
	{
		if(p[i]=='a'||p[i]=='e'||p[i]=='e'||p[i]=='u'||p[i]=='i')
		{
			j=i;
			while(p[j]!='\0')
			{
				p[j]=p[j+1];
				j++;
			}
			i--;
		}
		i++;
	} 
}	
void get_1234(char *a)
{
	int i=0;
	int sum=0;
	while(a[i]!='\0')
	{
		sum=sum*10 + a[i]-'0';
		i++;
	}
	printf("%d\n",sum);
}
void get_string(char *a, char *b)
{
	int i,j;
	i=0;
	while(a[i]!='\0')
	{
		j=0;
		while(b[j]!='\0')
		{
			if(b[j]!=a[j+i])
			{
				break;
			}
			j++;
		}
			if(b[j]=='\0')
			{
				printf("cun zai");
			}
		i++;
	}

}
int main()
{
	char a[]="hellelevjvjgrj";
	char b[]="lel";
	get_string(a,b);
}



#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int *p;
	int i;
	scanf("%d",&n);
	p=malloc(n*4);
	if(p!=NULL)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
		}
		for(i=0;i<n;i++)
		{
			printf("%d\n",p[i]);
		}
		free(p); 
	}
	return 0;
}


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
	a[j]=-1;
}
int main()
{
	struct worker w1[100];
	struct worker *w=w1;
	int n;
	int i=0;
	int a[100] = {0};
	puts("please input ren shu.Next shu ru information");
	scanf("%d",&n);
	get_insert(w,n);
	get_Agelow25(w,n,a);
	puts("************************************");
	while(a[i]!=-1)
	{
  		printf("%s\n%s\n%d\n%f\n",w1[a[i]].name,w1[a[i]].Bnumber,w1[a[i]].age,w1[a[i]].money);
		i++;
	}
	return 0;
}
