day2��������
	1) ��֪�������ݣ� int data[vb	] = {97,43,21,56,71,33,41,17,28,42,90,88,83};
	  ����ʵ�֣������ݴӴ�С����



	2����֪�������ݣ� int data[] = {97,43,21,56,71,33,41,17,28,42,90,88,83};
	  ����ʵ�֣��ҳ����������ֵ�Ĵ��λ�ã������±�ֵ��
#include<stdio.h>
void get_big_small(int *p,int n)
{
	int i,j;
	int t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(p[j]<p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
}
void get_print(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",p[i]);
	}
}
int get_down_flag(int *p,int n)
{
	int i;
	int maxIndex=0;
	for(i=1;i<n;i++)
	{
		if(p[maxIndex]<p[i])
		{
			maxIndex=i;
		}
	}
	return maxIndex;
}
int main()
{

	/*�������
	int data[]={97,43,21,56,71,33,41,17,28,42,90,88,83};
	int n=sizeof(data)/sizeof(data[0]);
	get_big_small(data,n);
	get_print(data,n);
	*/
	/*���ֵ�±�
	int data[]={97,43,21,56,71,33,41,177,28,42,900,88,83};
	int n=sizeof(data)/sizeof(data[0]);
	int t=get_down_flag(data,n);
	printf("%d\n",t);
}

�����������ֵ���ͣ�����±�
˼�룺������һ������
Ĭ�ϣ������е�һ��Ԫ������±����
max=a[0];
if(max<a[i])
{
	max=a[i];
}
return max;

maxIndex=0;
if(p[maxIndex]<a[i])
{
	maxIndex=i;
}
return maxIndex;

a[i]>a[i+1] ���漰�����ֵʱ �����ã�ȱ�ݣ�ֻ��ʵ���������ֵıȽϣ�ȡ�ý����ÿ�������е����ֵ