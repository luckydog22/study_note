int *p;

int a[5] = {1,3,4,5};

p = a;//����&

a[i] === *(p+i) ==== p[i] ==== *(a+i) //ֵ���

a+i === p+i === &p[i] === &a[i] //��ַ��ͬ

p = p + i;
a = a + i;// ������Ϊa�ǳ����������p�Ǳ�������ֵ���ִ���


int main(int argc, const char *argv[])
{
	//ֵ��� *(p+i) === a[i] ==== p[i] === *(a+i)
	//��ַ��ͬ p+i === &a[i] === &p[i] === a+i
	int a[5] = {1,2,3,4,5};
	int *p = a;
	printf("%d %d %d %d %p %p %p %p\n",*(p+0),*(a+0),a[0],p[0],p+0,a+0,&a[0],&p[0]);
	printf("%d %d %d %d %p %p %p %p\n",*(p+1),*(a+1),a[1],p[1],p+1,a+1,&a[1],&p[1]);
	return 0;
}

1.ָ������ 

	1.1 ָ�����������

		+   -   ++  --  *(ȡ����)
		int a[5] = {1,2,3,4,5};
		int *p = a;		//����p = 0x00001100;
		p + 1;			//p + 1  ?  0x00001104;
		p + 2;   		//p + 2  ?  0x00001108
		p++; // p = p + 1
		a++; //??������Ϊa��ַ����

		char a[6] = "hello";
		char *p = a;		//����p = 0x00001100;
		p + 1;			    //p + 1  ?    0x00001101;

		int a[5];
		int b[5];
		int *p = a;
		int *q = b;

		p + q ?     //����Ϊ������ַ��Ӻ�������
		
		
		#include <stdio.h>
		
		int main(int argc, const char *argv[])
		{
			double a[5] = {1,2,3,4,100};
			double *p = a;
			double *q = &a[4];
			int n = q - p;//ָ���������õ������������,�����ǵ�ַ���Ĳ�ֵ
			printf("%p %p\n",p,q);//p��q��ַ�����32   32/8 --->4
			printf("n is %d\n",n); //��ӡn == 4
			return 0;
		}

		int a[5];

		int *p = &a[0];
		int *q = &a[3];

	1.2	ָ��Ĺ�ϵ����

		ָ��  ==   !=   >     <
		
		��1����ָ��֮��Ĺ�ϵ�����ʾ����ָ��ĵ�ַλ��֮��Ĺ�ϵ��ָ���ַ���ָ�����ָ���ַС��ָ�롣
		��2�����в�ͬ�������͵�ָ��֮��Ĺ�ϵ����û�����壬ָ��ͬ������������ݵ���ָ��֮�䣬��ϵ����Ҳû�����塣
		��3��ָ����һ����������֮��Ĺ�ϵ����û�����塣�����Ժ�����е��ڻ򲻵��ڵĹ�ϵ���㣬�ж�ָ���Ƿ�Ϊ��
		
		###������ʾ ָ���Ƿ�ָ��ͬһ����ַ
		
		#include <stdio.h>
		int main()
		{
			int a = 10;
			int b = 20;
			int *p = &a;
			int *q = &b;
			if(p == q)
			{
				printf("ָ����ͬһ����ַ\n");
			}
			//�޴�ӡ�������Ϊp��q����ĵ�ַ��ͬ��pָ�����a��qָ�����b����ַ��ͬ�޴�ӡ
		}   
		
		#include <stdio.h>
		void reverse(int *p, int n)
		{
			int temp;
			int *q = p+n-1;//qָ�������е����һ��Ԫ��
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
		
		##��ϰ1 дһ�����������������гɼ�С��60������,Ҫ�����鶨����main������
		int a[] = {90, 80, 70, 55, 63, 53, 28}; 
		
			#include <stdio.h>
			int low_60(int *p, int n)
			{
				int i, c = 0; //c��������
				for(i = 0; i < n; i++)
				{
					if(*(p + i) < 60)
					{
						c++;
					}
				}
				return c;
			}
			int main()
			{
				int a[] = {90, 80, 70, 50);
				int x  = low_60(a,sizeof(a)/sizeof(a[0]));
				printf("low 60 is %d\n", x);
			}		
			
		##��ϰ2 дһ������������һ���ַ�����ĳ����ĸ���ֵĴ���
		#include <stdio.h>

	int countLetter(char *s, char letter)//s�������ҵ��ַ�����letter �������ַ����ֵĴ���
	{
		//����һ
		/*
		int count = 0;
		int i = 0;
		while(s[i] != '\0')
		{
			if(s[i] == letter)
			{
				count++;
			}
			i++;
		}
		*/
		//������
		int count = 0;
		while(*s != '\0')
		{
			if(*s == letter)
			{
				count++;
			}
			s++;//ָ������ƶ���ָ����һ��Ԫ��
		}
		return count;
	}


	int main(int argc, const char *argv[])
	{
		char a[] = "hello world";
		int count = countLetter(a,'l');
		printf("count is %d\n",count);
		return 0;
	}
			
	##��ϰ3 ��дһ��������������湦�ܣ��ܽ�Hello World!   ת����Lipps Asvph!
		
			
	1.3 ��ָ��

		int a = 0;

		int *p;
		*p = 10;  	//���pδ��ʼ����ֱ�ӽ���*p���������������ʾ
		////Segmentation fault (core dumped)

		��ʱp ��Ұָ��(δָ��һ����Ч��ַ��ָ�룬 �ǳ�����)

		���p����ʱ����֪����ָ���ģ���ôp��ʼ��ΪNULL
		
		#include <stdio.h>

		// *(p+i) === a[i] ==== p[i] ==== *(a+i)
		// p+i === &a[i] ==== &p[i] ==== a+i


		int main(int argc, const char *argv[])
		{
			int *p = NULL;//��ʱ��ָ�����p����Ұָ��
			if(p == NULL)//�ж�ָ���Ƿ�Ϊ��
			{
				printf("p is NULL\n");
			}
			return 0;
		}

		#define NULL 0

	1.4 ֵ���ݺ͵�ַ���ݣ�*****��

		////�����ʵ����һ������������������
		//дһ��swap, ����������
		#include <stdio.h>
		void swap(int a, int b)		//a , b���β�
		{
			int t;
			t = a;
			a = b;
			b = t;
		}

		int main()
		{
			int x = 5, y = 9;
			swap(x, y);		//x y ��ʵ�Σ��ڵ���ʱ������ʵ��ֵ��ʼ���β�
			printf("x is %d, y is %d\n", x, y);	//x is 9, y is 5
		}

		/////��ô���������Ϳ��Բ��õ�ַ���ݣ� ��ַ���ݿ��Ըı�ʵ�ε�ֵ
		#include <stdio.h>
		void swap(int *a, int *b)		//a , b���β�
		{
			int t;
			t = *a;
			*a = *b;
			*b = t;
		}

		int main()
		{
			int x = 5, y = 9;
			swap(&x, &y);		
			printf("x is %d, y is %d\n", x, y);	//x is 9, y is 5
		}
		
		�����������ݣ������ַ�ʽ
		
		///ֵ���ݣ�ͨ���ı䲻�˲�����ֵ, ���ǰ�ʵ�ε�ֵ���ݸ��βΣ�Ȼ���β����㣬��ʵ��û���κι�ϵ

		///��ַ���ݣ����Ըı������ֵ, ������һ��ָ�����

		##��ϰ4
		
			��д����fun����n��ѧ���ĳɼ���ͳ�Ƴ�����ƽ���ֵ�ѧ���������ɺ�������ֵ���أ�
			ƽ���ִ�����β�*ptr_aver��ָ�Ĵ洢��Ԫ��(��ƽ�����ɲ�������),����ƽ���ֵ�����
			�ɷ���ֵ���ء�
			����ԭ��Ϊ��int fun( float *s, int n, float *ptr_aver );
			���磺������8��ѧ���ĳɼ�����
	
			80.5  60  72  90.5  98  51.5  88  64
			
			�����ƽ���ֵ�ѧ������Ϊ��4(ƽ����:75.5625)��
			
			#include <stdio.h>

			int fun( float *s, int n, float *ptr_aver )
			{
				//1.������ѧ���ĳɼ�
				int count = 0;//������ͳ������
				float sum = 0;
				int i;
				for(i = 0; i < n; i++)
				{
					scanf("%f",s+i);
					sum += s[i];
				//	scanf("%f",&s[i]);
				}
				//2.��ƽ��ֵ
				*ptr_aver = sum / n;//�õ���ƽ��ֵ
				//3.ͳ�Ƶ���ƽ��ֵ������
				for(i = 0; i < n; i++)
				{
					if(*(s+i) < *ptr_aver)
					{
						count++;
					}
				}
				return count;
			}

			int main(int argc, const char *argv[])
			{
				float a[100];//��������ѧ���ɼ�
				float avg;//��������ƽ��ֵ
				int count;
				count = fun(a,8,&avg);
				printf("����:%d\n avg is %.2f\n",count,avg);
				return 0;
			}

////���ۣ�

	һ������Ҫ��������ߴ���ֵ�����ַ�ʽ
	
	1. ����ֵ 
	
	2. ������ַ����
		
	1.5 ָ�������ռ�ڴ�ռ�Ĵ�С		
			
		int a;   //sizeof(a)   ?  4
		char a;   //sizeof(a)   ?  1
		double a;   //sizeof(a)   ?  8
		short a;   //sizeof(a)   ?  2
		float a;   //sizeof(a)   ?  4

		///sizeof �������ĳ������ռ�õ��ڴ�ռ��С��
		int *p;		
		char *q;	    

		sizeof(p)    ? 4  p��������ʲô? int *(����ָ��)        
		sizeof(*p)   ? 4   *p��������ʲô? int (����)      
		sizeof(q)    ? 4  q��������ʲô? char *(�ַ�ָ��)      
		sizeof(*q)   ? 1   *q��������ʲô��char (�ַ�) 

		//����: ����ʲôָ�룬��ռ��4�ֽ�
		
		int main(int argc, const char *argv[])
		{
			int *p;
			char *q;
			double *z;
			printf("sizeof(p) is %d\n",sizeof(p)); //4
			printf("sizeof(q) is %d\n",sizeof(q)); //4
			printf("sizeof(z) is %d\n",sizeof(z)); //4
			return 0;
		}
		
		
	1.6  �ַ����ȽϺ���
	
		//�ַ���������
		strcmp   //�ַ����Ƚ�

		#include <stdio.h>
		#include <string.h>
		int main()
		{
			int x;
			x = strcmp("abc", "abc");	//�ַ������ ����ֵ��0
			printf("x is %d\n", x);
			x = strcmp("abcd", "abc");	//�ַ��� "abcd" > "abc" ����ֵ��1
			printf("x is %d\n", x);
			x = strcmp("abcd", "bc");	//�ַ��� "abcd" < "bc"  ����ֵ��-1
			printf("x is %d\n", x);
		}
		
		int num = atoi("2345");
		
		##��ϰ5��дһ���������Ƚ������ַ�����
		
		 # �ַ���1 > �ַ���2 ����1���ַ���1 == �ַ���2������0�� �ַ���1 < �ַ���2������-1
		 # д�������ԣ���������strcmp����
		int my_strcmp(char *s1,char *s2)
		{
			
		}
		
		  "abc"  < "bbc"
		  "abc"  < "b"
		  "bc"  > "abc"
		  "abc"  = "abc"

			

2. ������ȫ�ֱ������ֲ�������

	2.1��������
	
		int a;		//int �������ͣ� a ������
		float b;	//float ��������  b ������

	2.2��������淶
	
		������������Ӣ����ĸ�����֣���_��ɣ������������ֿ�ͷ
		sum1   //ok
		sum    //ok

		1sum   //no
		sum?   //no

		��������ɶ��������� ���Բ���������ʽ
		linux���
			student_name
		windows���
			StudentName

	2.3�ֲ�����(�����ں����еı������ھֲ�����)
	
		#include <stdio.h>
		void fun()
		{
			int x = 100;
		}
		int main()
		{
			printf("x is %d\n", x);
		}
	
		hello.c:8:22: error: ��x�� undeclared 
		hello.c�ĵ�8���д���xδ����

		#include <stdio.h>
		void fun()	//��������
		{
			int x;
			printf("fun x is %d\n", x);
		}
		int main()
		{
			int x = 200;
			printf("main x is %d\n", x);
			fun();	//��������
		}

		�ֲ������ص�
		
		1) ������ͬ�����п�����ͬ������
		2) �ֲ�����ֻ��������ĺ�������Ч
		3) �����;ֲ�����Ҳ����ͬ��
		4) �ֲ��������û����ֵ����ôֵΪ ���ֵ
		

	2.4ȫ�ֱ���(�����ں�������ı�����ȫ�ֱ������ڳ�����κ�λ�ö����Է���)
	
		#include <stdio.h>
		int x;
		void fun()
		{
			int x;
			x = 100;
			printf("fun x is %d\n", x);
		}
		int main()
		{
			fun();
			printf("main x is %d\n", x);
		}

		1) ȫ�ֱ����ڳ�����κ�λ�ö�����ʹ��

		2) ֻҪ��һ���ط�����ȫ�ֱ����������ط�Ҳ��

		3) ȫ�ֱ������δ��ʼ�� Ĭ��ֵΪ        0

		4) ȫ�ֱ�������ͬ���� ��ȫ�ֱ������Ժ;ֲ�����ͬ��������ʹ�þֲ�����

	2.5 ���������������Ǹ��߱��������˺����ǳ�ʲô���ģ�
		
		�����Ķ��御�����ں������õ�ǰ�棬�����ȶ����ٵ���

		������������ں������õ����棬������Ҫ������һ��

		������������
		#include <stdio.h>
		int max(int a, int b);		//���������������Ǹ��߱༭����������ʲô��
		int main()
		{
			int x = max(3, 5);
		}
		int max(int a, int b)		//���������ã�
		{
			return a > b ? a : b;
		}

		1) void fun();    ///Ҫע�⣺��" ; "

		2) ��������������Ҫ������

		3) ����������һ���붨��һ��

		4) ������������������ͷ�ļ���


3.��ҵ

	8ֻ����Χ����һ��Ȧ��
	��˳ʱ�뷽���1��8��š�
	Ȼ���1�ź��ӿ�ʼ
	��˳ʱ�뷽���1��ʼ������
	����m�ĺ��ӳ��֣�
	�ٴӸճ��ֺ��ӵ���һ��λ�����¿�ʼ������
	����ظ���ֱ��ʣ��һ�����ӣ�
	�����Ǵ�����
	��Ʋ���д����ʵ�����¹��ܣ�
	��1��	Ҫ�����û����뱨����m��
	��2��	������ѡ�����ı�š�
