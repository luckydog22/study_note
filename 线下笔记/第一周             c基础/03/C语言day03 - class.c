��ϰ��

	&& //һ�ټ��٣�ͬ��Ϊ�� 
	
	|| //һ�漴�棬ͬ��Ϊ��
	
	�� //��--����  ��-����
	
	&& �� || ���ڶ�·����  
	
	&& ��· ---���õ�һ������Ϊ�� 
	
	|| ��· ---���õ�һ������Ϊ��
	
	++ --
	
	a++; //������ ��++
	
	++a;//��++�������� 
	
	int a = 3;
	int b = 5;
	int c = a++ + b++;
	
	a === 4
	b === 6
	c === 8 
	

	a += 3 ---> a = a + 3
	
	score = score / 10;
	
	score /= 10;
	
	
	if()
	{}
	else if()
	{}
	else if()
	{}
	else 
	{}
		
	
	��Ŀ����� 
	
	int max = a > b ? a : b;
	
	switch(day)
	{
		case 1:
			//ִ�е����
			break; //����switch��
		default://��������case�������㣬ִ��default
			//ִ�����
	}
	
	
	int 4  %d
	char 1 %c
	short 2 %d
	long 4 %ld
	float 4 %f
	double 8 %lf
	
	
	man ascii 
	
	�ַ��������������
	
	'\0' ---> 0
	
	'0' ----> 48
	
	'a'-----> 97
	
	'A'-----> 65
	
	'2' = '0' + 2


1. �������

	1.1 ���������Ҫ����ͷ�ļ�
		//.h��β����ͷ�ļ�
	
		stdio.h   //std: ��׼  i : input   o : output   .h ͷ�ļ�

		#include <stdio.h>
		int main()
		{
		
		}
	
	1.2 ��������� �ַ�����������ַ������� ȱ�㣺���ܸ�ʽ�����
	
		putchar()    //���һ���ַ�������Ļ��  ' '�ַ�
 		puts()       //���һ���ַ�������Ļ��, �Զ���'\n' " " ��ʾ�ַ���
		
		####�������
		
		#include <stdio.h>
		int main()
		{
			putchar('A');   //���A����Ļ��
			putchar('?');   //���?����Ļ��
			putchar('\n');   //���\n����Ļ��
			puts("hello"); //���hello����Ļ�� 
			puts("nihao xiaoli");//��� nihao xiaoli����Ļ��
		}

	1.3 ��ʽ��������� printf()����
	
		
		
		(1)������� �ַ����ַ��������α����������ͱ��� 
		
			char   %c
			int    %d
			float  %f
			double %lf
			long   %ld

			float  �����ȸ�����   double ˫���ȸ�����

			�����16������� %x
			
		(2) ����ָ�������ʽ�� �̶����2���ַ���ȣ�02 

			int hour = 23, min = 3, sec = 9;
			printf("%02d:%02d:02d\n",hour,min,sec); //23:03:09

		(3) ���%f�����Ĭ�ϱ���С�����6λ�����ֻ����2λ�� printf("%.2f", d);

			#include <stdio.h>
			int main()
			{
				int h = 2, m = 8, s = 5;
				int a = 48;
				printf("a is %d\n", a);
				printf("a is 0x%x\n", a);
				printf("%02d:%02d:%02d\n", h, m, s);	//2 ��ʾ���ռ2λ��0 ��ʾ�������2λ����0
									//�������0, ��ʾ����2λ���ո�
				float d = 3.146;
				printf("d is %.2f\n", d);		//.2f,��ʾ����2λС�����������2λ����������
			}


	1.4 ��ʽ�����뺯�� scanf("%d", &b);  ��ʽ������
	
		char   %c
		int    %d
		float  %f
		double %lf
		long   %ld

		#include <stdio.h>
		int main()
		{
			int a;
			scanf("%d", &a);
			printf("a is %d\n", a);
		}

	1.5 �ַ����뺯�� getchar()
	
		#include <stdio.h>
		int main()
		{
			int a = getchar();	//ִ��1�Σ��õ�1���ַ���a���汣���������ַ���Ӧ��ascii��ֵ
			printf("a is %c\n", a);
			getchar();//���ջس���
			int b = getchar();
			printf("b is %c\n", b);
		}


#��ϰ1 ��дһ������Ҫ������һ��ASCII��ֵ��Ȼ�������Ӧ���ַ���

	#��������һ���ַ������ASCII��ֵ
	
	int a = getchar(); 'A'
	printf("%d\n",a); ==>65

	����65 ---> ��ӡ���A
	����97 ---> ��ӡ���a

	
	#include <stdio.h>
	int main()
	{
		int a;
		scanf("%d", &a);
		printf("a is %c\n", a);
	}



#��ϰ2 ��д���򣬴Ӽ������������������ֱ��������ǵ��̺�������

#	���ʱ������Ҫ����2λС�������Ե���λ��������

	#include <stdio.h>
	int main()
	{
		int a, b, d;
		float c;
		scanf("%d%d", &a, &b);
		c = (float)a / (float)b;
		d = a % b;
		printf("c is %.2f, d is %d\n", c, d); ��
	
2 ѭ���ṹ

	2.1 while ѭ��
		
	
	(1)
		���⣺ ��� 1+2+3+4+5+6+....+100�ĺ�

		������ int a = 1 + 2 + 3 + 4 + 5 + 6.... //�鷳�������ѭ��������أ�	
		###������ʾ�����
		#include <stdio.h>
		int main()
		{
			int i = 1; 
			int sum = 0;//�����ۼ����
			while(i < 101)	//i < 101�����������������������ִ��{ }, ��������
			{			//{  }��������ִ��������ص�while�����жϣ�ֱ������������
				sum += i; 
				i++; 
			}
	
			printf("sum is %d i is %d\n", sum, i);
		}
	
		////����ִ�н���  sum is 5050 	i is 101 
		
		##��ϰ3: ��whileѭ�� �����1-1000���ܱ�3�����������ܱ�5���������֡�

		
		#include <stdio.h>

		int main(int argc, const char *argv[])
		{
			int i = 1;//ѭ��������ʼ��
			while(i <= 1000)//ѭ����������
			{
				if(i % 3 == 0 && i % 5 != 0)
				{
					printf("%d",i);
				}
				i++;//ѭ�������Լӡ��Լ�
			}
			return 0;
		}


		(2)����ѭ��(��ѭ��)
			
				//����ѭ��(��Զִ�У���Զ��������)
				whileѭ��������д������ѭ��(��ѭ��)
				
				####������ʾ 
				
				#include <stdio.h>
				
				int main()
				{
					while(1)
					{
						printf("hello world!!\n");//ע��˴�һ��Ҫ��\n���з�
						sleep(1); //��ʱ 1s
					}
					return 0;
				}
				/////��ctrl + c ��������
				

	2.2 for ѭ�� //ͨ������ѭ��������֪�������


		(1)��forѭ�����
		
			1+2+3+4+5+6+....+100    //ѭ����������100��
		
			##������ʾ 
			
			#include <stdio.h>
			
			int main()
			{
				
				int i, sum = 0;
				for(i = 1; i < 101; i++)	// ��3�仰��i=1 ��forѭ��ִ��֮ǰִ�У�ͨ��ִ�г�ʼ��������ִֻ��1��
				{				// i < 101, ��ÿ��ѭ��֮ǰִ�У�ͨ����һ���ж���䣬���������������ִ�� {  }
								// i++, ��ÿ��ѭ��ִ����ִ��
					sum += i;
				}
				printf("sum is %d i is %d\n", sum, i);
				//��ӡ���sum is 5050 i is 101
			}

			##��ϰ4: ��forѭ����� �����1-1000���ܱ�3�����������ܱ�5���������֡�
			
			#include <stdio.h>
			
			int main()
			{
				int i = 1;
				for(i = 1; i < 1001; i++)
				{
					if(i % 3 == 0 && i % 5 != 0)
					{
						printf("%d,", i);
					}
				}
			}

		//�����forдһ����ѭ��
		
		for(;;)
		{
			printf("hello wrold!!\n");
		}


		(2)forѭ��Ƕ��
		

			for(i = 0; i < 10; i++)
			{
				for(j = 0; j < 10; j++)
				{
					printf("hello world\n");
				}
				
			}

			���ʴ�ӡ������ٴ� "hello world\n" ? 
		
			����ѭ�� ִ�� 10 * 10 �� //��ѭ�� ѭ��һ�Σ���ѭ������һȦ
			
	
		###��ϰ5
		
		��forѭ��Ƕ�� ʵ���������ͼ��, Ҫ��1��ֻ�����һ�� "#" printf("#");
		//��ѭ������������������ѭ���Ĵ�����������
		
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
			
		##��ϰ6 
		
		��forѭ��Ƕ�� ʵ���������ͼ��, Ҫ��1��ֻ�����һ�� "*" printf("*");
		

		*      i = 0   1
		**     i = 1   2
		***    i = 2   3
		****   i = 3   4
		*****  i = 4   5  
		
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
		
		(3)break�ؼ��� 
		
			break ���ã�����switch���ѭ����(for,while,do-whileѭ��)
		
			###���밸����ʾ
			
			��� 1+2+3+4+5+6+....+100 ,���ֻ�ӵ�10?

			#include <stdio.h>
			int main()
			{
				int i, sum = 0;
				for(i = 1; i < 101; i++)	
				{
					if(i == 10)
					{
						break;	//��������ѭ����10û�вμӵ��ӷ�������
					}				
					sum += i; //һ�����i == 10��ʱ��ִ��break,ѭ��������sum += i���ᱻִ�У�10û�б����뵽sum��
				}
				
				printf("sum is %d i is %d\n", sum, i); //sum is 45   i is 10
			
			//break ��ѭ������������������ѭ��

			//10 ���μӼӷ�����
			
		(4) continue �ؼ��� 
			
			continue �ؼ������ã���������ѭ�� 
			
			��� 1+2+3+4+5+6+....+100 ,�����Ҫ������10�����ȥ ?
		
			#include <stdio.h>
			int main()
			{
				int i, sum = 0;
				for(i = 1; i < 101; i++)	
				{
					if(i == 10)
					{
						continue; //������������ѭ��
					}				
					sum += i;
				}
				
				printf("sum is %d i is %d\n", sum, i);//sum is 5040   i is 101
			}
		
		
		##��ϰ7����д����ʵ�����¹��ܣ�
		
				1+2+3+4+...+100, �ܱ�5�����ĳ���
				
				#include <stdio.h>
				int main()
				{
					int i, sum = 0;
					for(i = 1; i < 101; i++)	
					{
						if(i % 5 == 0)
						{
							continue; //������������ѭ��
						}				
						sum += i;
					}
					printf("sum is %d i is %d\n", sum, i);
				}


		
		##��ϰ8����whileдһ����ѭ����ʵ���û�����һ�����ֺ����̴�ӡ��������֣�ֱ������Ϊ0ʱΪֹ����������
			
			
			
		#include <stdio.h>

		int main(int argc, const char *argv[])
		{
			int num;
			while(1)
			{
				puts("Please input a number:");
				scanf("%d",&num);
				if(num == 0)
		//		if(!num)//����num��ֵΪ0,����٣���!0�����,ִ��break
				{
					break;
				}
				printf("num is %d\n",num);
			}
			return 0;
		}	
			
	
			
		##��ϰ9����ӡ���100-999֮�������ˮ�ɻ��� 
		
			ˮ�ɻ�����Ҫ������������
			
			���� 153����ˮ�ɻ��� �������� 153 == 1*1*1 + 5*5*5 + 3*3*3	
			
			
#include <stdio.h>
int main()
{
	//����һ�������ж��ǲ���ˮ�ɻ���
	int i;//�������������
	int a,b,c;//�ֱ�����λ��ʮλ����λ
	for(i = 100; i < 1000; i++)
	{
		a = i / 100;  //153 / 100
		b = i / 10 % 10;// 153 / 10 == 15 15 % 10 == 5
		c = i % 10;// 153 % 10 === 3
		if(i == a*a*a + b*b*b + c*c*c)
		{
			printf("%d Yes!!\n",i);
		}
	}

}	
		
		
	
	2.3 do-whileѭ�� 
	
		do{
		...
		} while(����);    ѭ��

		�ص㣺��ִ��do{  } �������䣬Ȼ���ٽ����жϣ� ֻҪ�����������ͼ���ִ��

			 ����ִ��һ��
		
		###������ʾ 
		
		��� 1+2+3+4+5+6+....+100
		
		#include <stdio.h>
		int main()
		{
			int i;
			int sum = 0;
			i = 1;
			do
			{
				sum += i;   // ���������ɲ���������ִ��
				i++;
			}while(i < 101);
			printf("sum is %d\n", sum);
		}





��ҵ��




1 ��дһ���������1-100��ȫ������(����)��
����������1���Լ������ܱ��κ�����������

2 3 5 7 11 13 17 19 ....

#include <stdio.h>
int main()
{
	//����һ�������ж��ǲ�������
	int i;//�������������
	int j;//��Ϊѭ������
	int flag  = 0;//��־λ

	for(i = 2; i <= 100; i++)
	{
		flag = 0;
		for(j = 2; j < i; j++)
		{
			if(i % j == 0)//֤��i����������
			{
				flag = 1;//֤����������������
				break;//����ѭ����breakֻ�ܽ�����ǰ���ڵ�ѭ����
			}
		}//����һ
		if(i == j)//˵��������Ȼ������û��ִ�й�break(ѭ��������i����j)�����ִ�й�break(ѭ��������i������j)֤������������������Ϊû��ִ�й�break,����֤����������
		{
			printf("%d������\n",i);
		}
		//������
		/*
		if(flag == 0)//flag == 0����������
		{
			printf("%d������\n",i);
		}
		*/
	}
	//ѭ��������ʱ��j��ֵ����ʲô����
	//j == i ѭ�����������û��ִ�й�break,֤����������
	
}



2. �����N����������,�������û�����
	����NΪ���������û�����5���������������ɵ���������
	    *
	   ***
	  *****
	 *******
    *********

for(i = 0; i < 5; i++)//��������
{
	//��ӡ�ո�
	for(j = 0; j < 5-1-i ; j++)
	{
		printf(" ");
	}
	//��ӡ����
	for(j = 0; j < 2*i+1; j++)
	{
		printf("*");
	}
	printf("\n");//���з�
}


������ i = 0 ��һ��1��*, 4 ���ո�
       i = 12* �ڶ���3��*, 3 ���ո� 
	   i = 2 ������5��*, 2 ���ո� 
	   i = 3 ������7��*, 1 ���ո� 
	   i = 4 ������9��*, 0 ���ո� 
	   
#include <stdio.h>
int main()
{ 
	int i,j;
	int n;//������
	printf("Please input line:\n");
	scanf("%d",&n);
	for(i = 0; i < n; i++)//��������
	{
		//��ӡ�ո�
		for(j = 0; j < n-1-i ; j++)
		{
			printf(" ");
		}
		//��ӡ����
		for(j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");//���з�
	}
	return 0;
}

/////////////////////

gedit hello.c 

ctrl + q //�˳�ѡ��save