##��ϰ����ά����������

int a[3][4]= {{1},{2,3},{45,6,8}};

//�����ά�����ʱ����������ʡ�ԣ�����һά�����Ԫ�ظ���


int a[][5] = {{1,2},{45,7}};

srand(time(0));//��ʼ���������
int num = rand();//�õ������


1. ����(ͨ���������ĳһ���ض��Ĺ��ܵ�һ�δ��룬����δ���ŵ�һ���γ�һ������)

	1.1 ϵͳ����(����ϵͳ������д���ˣ����ǻ���þ���)
	
		printf
		rand
		strlen
		atoi //�ܹ��������ַ���ת��Ϊ����

	1.2 �Զ��庯��(�Լ�д�ĺ���)

		����
		  *
		 ***
		*****
		  *
		 ***
		*****
		  *
		 ***
		*****
		  *
		 ***
		*****
		  *
		 ***
		*****
		
		#include <stdio.h>

		//�������ȶ��壬��ʹ��
		//��������
		void printStar()//void�����޷���ֵ�������ڲ���Ҫдreturn <���ʽ> printStar������ ()��ʾ����
		{//������
			int i,j;
			for(i = 0; i < 3; i++)//���ƺ���
			{
				//��ӡ�ո�
				for(j = 0; j < 3-1-i; j++)
				{
					printf(" ");
				}
				//��ӡ����
				for(j = 0; j < 2*i+1; j++)
				{
					printf("*");
				}
				printf("\n");
			}
			//����ִ�н��������ص��������ô�
		}

		int main(int argc, const char *argv[])
		{
			printStar();//��������,��Ҫ��;��,��ת�������Ķ��崦ȥִ��
			printStar();//��������
			printStar();//��������
			printStar();//��������
			return 0;
		}
	
		������ִ������ת����������ִ��������ת����

		��������ʲô�������ԣ�
		
		(1) ���������ֿ�ͷ 
		(2) ����'_', �������κ������ַ�
		(3) �����������������������ĺ���   
		(4) ����ж�����ʣ��������÷��ű�ʶ

		����һ�㶼Ҫ�ȶ��壬Ȼ���ٵ��ã�����д�ڵ����ߵ����棩

	1.3 ���κ����ͷ���ֵ
	
	
		int len = strlen(a)   //a �ǲ���

		������     ���ݸ�������һ��ֵ
		
		
#include <stdio.h>

//�������ȶ��壬��ʹ��
//��������
void printStar(int n)//void�����޷���ֵ�������ڲ���Ҫдreturn <���ʽ> printStar������ ()��ʾ����,int n�����������β��б�
{//������
	int i,j;
	for(i = 0; i < n; i++)//���ƺ���
	{
		//��ӡ�ո�
		for(j = 0; j < n-1-i; j++)
		{
			printf(" ");
		}
		//��ӡ����
		for(j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//����ִ�н��������ص��������ô�
}

int main(int argc, const char *argv[])
{
	int line;
	scanf("%d",&line);
	printStar(line);//��������,��ת�������Ķ��崦ȥִ��,(10)ʵ���б�,
	//�������õ�ʱ��ʵ�γ�ʼ���β�,�൱�ڽ�10��ֵ��---> �βε�n
	return 0;
}

		����
		��������֮��Ľϴ�ֵ
		
		3    5
		
		�� 1 ��ʹ�ò���
		
		#include <stdio.h>
		void max()
		{
			int a = 5, b = 9;
			if(a > b)
			{
				printf("max is %d\n", a);
			}
			else
			{
				printf("max is %d\n", b);
			}
		}
		int main()
		{
			max();
		}
		
		///������, �ĳ�ʹ�ò���
		
		
		��ƺ���min(x,y),��������double��ֵ�н�С����ֵ��ͬʱ��һ���򵥵�main���Ըú�����
			
		#include <stdio.h>
		int max(int a, int b)	//a, b�ǲ������ֽ��β�, max ǰ�� int ��ʾ������һ��int�ͷ���ֵ
		{
			if(a > b)
			{
				return a;	//return �����ֵ�����������(main),һ��ִ��return,��ǰ�����ӽ���
			}
			else
			{
				return b;
			}
		}
		int main()
		{
			max(5,9);
			int x = max(5, 9);	//5, 9 �ǲ�������ʵ�Σ���������ʱ������ʵ��ֵ����ʼ���β� 5 - > a,  9 - > b
			printf("max is %d\n", x);
		}
		//�����ǵ����ߴ��ݸ�������ֵ
		//����ֵ�Ǻ������ݸ������ߵ�ֵ

		����ʹ��ʱע�⣺
		1 ����ʱ�����������������붨��һ��
		2 ����ֵ���ͱ����붨��һ��

		����
		
		

		/////������������
		1
		1 1
		1 2 1
		1 3 3 1
		1 4 6 4 1
		//дһ������������������̶�����������Σ�����Ľ������ɲ������ݽ���



		##��ϰ1
		
		дһ����һ������n�η��ĺ���
			Ȼ����main�в���(��main����)
			
				
		#include <stdio.h>

		int num_n(int num, int n)// 2,3
		{
			int result = 1;
			int i;
			for(i = 0; i < n; i++)
			{
				result *= num;
			}
			return result;
		}

		int main(int argc, const char *argv[])
		{
			int a,b;
			printf("���������� n�η�:\n");
			scanf("%d%d",&a,&b);
			int num = num_n(a,b);
			printf("num is %d\n",num);
			return 0;
		}

		##��ϰ2
		
		дһ���������Ƚ���������Ȼ��������ֵ
		
		
		#include <stdio.h>

		int getMax(int a,int b,int c)
		{
			a = a > b ? a : b;
			a = a > c ? a : c;
			return a;
		}


		int main(int argc, const char *argv[])
		{
			printf("max is %d\n",getMax(1,2,3)); //����ֱ�Ӵ�ӡ��getMax(1,2,3)�൱�ڱ��ʽ
			int max = getMax(1,2,3);
			printf("max is %d\n",max);
			return 0;
		}
		
		##��ϰ3
		
		��ƺ���min(x,y),��������double��ֵ�н�С����ֵ��ͬʱ��һ���򵥵�main���Ը�

		#include <stdio.h>
		double min(double a, double b)
		{
			return a < b ? a : b;		//����ֱ��return ���ʽ
		}

		int main()
		{
			//����һ
			double get_min = min(3.14,2.34);
			printf("min is %lf\n",get_min);
			
			//������
			printf("min is %lf\n", min(3.14, 1.2));	
		}
	
	
	1.4 �����ܽ�
	
		(1)������, Ҫ�������������ĺ���
		
			����ͨ���Ƕ��˺�����һ��Ҫ�ñ����ܿ����Լ�д�Ĵ���

		(2)��������Ҫ��д(����д�����������ñ��˿���)
		
			set_student_name()

		(3)���������ֲ�ͬ���д��
		
			SetStudentName       windows��� (��һ������)
			set_student_name     linux  ��� (�����м��_)
			setStudentName       ios    ���


		(4)��������
		  get_max(int x, int y, int z,);   //������Ҫ̫�࣬��Ҫ����5��
										  //��������࣬Ӱ�����Ŀɶ���

		  ��������ʱ���������붨��ʱ��������Ҫһ��
		  get_max(30, 40, 50);    //��������ʱ��������Ҫ�붨���һ��

		  �������û�в���
		  void print_star(void)//()�ڵ�void�����޲�������˼


		(5)��������ֵ���п��ޣ�����з���ֵ����ô������һ��Ҫ��return 0;
		
		  int max(int a, int b)	
		  {
			return 1;
		  }
		  
		  //һ������ֻ�ܷ���һ��ֵ
		  void print_star();    //void��ʾ�����޷���ֵ��������return ��ʾ�����������������ֵ��void , return
			 ����ֻҪִ�е�return , �����ͽ���
			return > break > continue

		(6)�������ܾ�����һ
		  һ��������ܲ���һ����ô������Ҫ���

		(7)����������Ҫ̫��(����1ҳ����ʾ��)


2. ָ��
	
	2.1 ʲô��ָ��
	
		�ֳ�Ϊָ���������c���ԣ� c++, objective c ���еģ� ָ���ú��˷ǳ����㣬����ò��ã�Ҳ����ɲ��õĺ��
		
		�ڴ浥Ԫ��ַ(���) ����Ϊָ�루ָ�����ͨ��Ҳ��ָ�룩
		

		�ڴ�
		
		����ĳ��������ڴ���ִ�еģ�ÿ���ڴ涼��һ����ַ����ַ��32λ��4�ֽ�

		�������һ����������  a�ĵ�ַ������ָ�����
		int a = 10;
		int *p;		//����ָ�����, int *��һ������
		p = &a;


	2.2 ָ�붨��(��������һ����ַ�ı�������ָ�����)
	
	   1) ָ��Ҳ��һ������(���Ա�����Ϣ)
	   2) ָ�뱣�����һ����ַ
	   
		(1)����һ��ָ�����
		
			int *p;		//����ָ�����

		(2)ָ�븳ֵ
		
			p = &a;

		(3)���ͨ��ָ�����p���ʱ���a
		
			*p = 20;   //===> a = 20;


	2.3 �����ĸ�ֵ
	
		��c�������ȡ������ֵ�����ַ�ʽ
		
		 int a = 10;
		 
		(1)ֱ�Ӹ�ֵ��ֱ�Ӹ�ĳ��������ֵ
		
			 a = 20;
			 
		(2)��Ӹ�ֵ�� ��ȡ��ĳ�������ĵ�ַ��Ȼ���Ǹ���ַȥ��ֵ
			
			 int *p = &a;   <====>  int *p;  p = &a;
			 *p = 20;    //��Ϊ����1  ȡ��p��ֵ������a�ĵ�ַ   2  ���Ǹ���ַȥ��ֵ(20)

		������
		#include <stdio.h>
		int main()
		{
			int a = 10;
			int *p;		//* ָ�붨�������
			p = &a;
			printf("a %d, *p %d\n", a, *p); //��ʱ*p�е�*����ȡֵ����˼
			printf("p %p, &a %p\n", p, &a); //��ӡ��ַ��%p
			*p = 20;	//* ȡ�����������ͨ��ָ���������޸ı�����ֵ
			printf("a %d, *p %d\n", a, *p);
		}

		##��ϰ  
		//����һ�������ͱ���     x = 1.1
		//����һ��������ָ����� q
		//�Ѹ����ͱ���x��ַ��ֵ�� q
		//ͨ��q�ı�x��ֵ  3.14

		//��ӡx, *q
		#include <stdio.h>
		int main()
		{
			float x = 1.1;
			float *q;
			q = &x;
			*q = 3.14;
			printf("x %.2f, *q %.2f\n", x, *q);
		}

		###�ܽ᣺ ָ�����һ������(�������汣�����һ����ַ(int float double))
		###       ����ָ��������ǾͿ������õ�ַ��������ָ��ı���


	2.4 ָ�������ʼ��
	
		int a = 10;
		int *p = &a;		//����ָ�����ʱ��ֱ�ӳ�ʼ���� �൱��int *p;   p = &a;


	2.5 ָ�������
	
		��ô����ָ�������ָ��һ������
		int a[5] = {1,2,3,4,5};
		int *p;
		p = a;		//����&,  ��Ϊa�������������������׵�ַ
		*(p + 0)      <===> a[0];
		*(p + 1) <===> a[1];
		*(p + 2) <===> a[2];
		*(p + 3) <===> a[3];
		*(p + 4) <===> a[4];

		������ͨ��ָ���������
		
		ֱ�ӷ���
		#include <stdio.h>
		int main()
		{
			int a[5] = {1,2,3,4,5};
			int *p = a;
			printf("%d %d %d %d %d\n", *p, *(p + 1), *(p + 2), 
					*(p + 3), *(p + 4));	
		}
		
		ѭ����ʽ
		
		#include <stdio.h>
		int main()
		{
			int i;
			int a[5] = {1,2,3,4,5};
			int *p = a;
			for(i = 0; i < 5; i++)
			{
				printf("%d\n", *(p + i));
			}
		}


		##��ϰ4����ָ�룬��ѧ���ɼ��ͣ�ƽ��ֵ����ӡ��ѧ���ɼ��ŵ�һ��������
		
		int a[] = {90, 80, 70, 60, 75, 87, 89, 92};
	
		#include <stdio.h>
		int main()
		{
			int a[] = {90, 80, 70, 60, 75, 87, 89, 92};
			int i, sum = 0;
			int *p = a;
			for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
			{
				sum += *(p + i); 	//sum += a[i];
			}
			printf("sum is %d, avg is %d\n", sum, sum / 8);
		}
	
	2.6 ָ��ͺ���

		���Խ����鴫�ݸ�һ����������������鴫�ݸ�����,ͨ������������, ������ָ�����
		ʵ��һ����������ӡ����������Ԫ��
		int a[5]
		
		a ==== &a[0]
	
		####������ʾ 
		
		#include <stdio.h>
		
		void print_all(int *p, int n)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				printf("%d\n", *(p + i));
			}
		}
		int main()
		{
			int a[] = {90, 80, 70, 60, 75, 87, 89, 92};
			print_all(a, sizeof(a) / sizeof(a[0])); //�����ܴ�С/����Ԫ�صĴ�С === Ԫ�صĸ���
		}

	//����ʹ��ָ���������
	
	
		##��ϰ5��дһ��������5��ѧ����ƽ���ɼ�(�ں�������ѧ��ƽ���ɼ�, ���������д�ӡ)
		
		#include <stdio.h>
		
		int get_avg(int *p, int n)
		{
			int i, sum = 0;
			for(i = 0; i < n; i++)
			{
				sum += *(p + i);
			}
			return sum / n;
		}

		int main()
		{	
		
			int a[] = {90, 80, 70, 60, 75, 87, 89, 92};
			int x = get_avg(a, sizeof(a) / sizeof(a[0]));
			printf("avg is %d\n", x);
		}

		##��ϰ6��дһ����my_strlen����һ���ַ����ĳ��ȣ�Ȼ��д��main������
		
		
		#include <stdio.h>

		int my_strlen(char *p)
		{
			int i = 0; 
		//	while(*(p+i) != '\0')//*(p+i) ==== a[i] ===== p[i]
			while(p[i] != '\0')
			{
				i++;
			}
			return i;
		}


		int main(int argc, const char *argv[])
		{
			char a[] = "hello";
			int len = my_strlen(a);

			printf("len is %d\n",len);
			return 0;
		}
				
		
		##��ϰ7�� ��дһ����������������n��������˳����
		
			int a[] = {1,2,3,4,5,6,7,8};
			//a[0] ---- a[7]
			//a[1] ---- a[6]
			//a[2] ---- a[5]
			//a[3] ---- a[4]
			
			#include <stdio.h>

			void reverse(int *p, int n)
			{
				int i;
				int temp;
				for(i = 0; i < n/2; i++)
				{
					temp = *(p+i);
					*(p+i) = *(p+(n-1-i));
					*(p+(n-1-i)) = temp;
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
				int a[] = {1,2,3,4,5,6,7,8};
				printArray(a,sizeof(a)/sizeof(a[0]));
				reverse(a,sizeof(a)/sizeof(a[0]));//�������ã��Ѿ�ʵ������ת��
				printArray(a,sizeof(a)/sizeof(a[0]));
				return 0;
			}			
						
			
			
		
		##��ϰ8��/////������������
		
		1 0 0 0 0
		1 1 0 0 0
		1 2 1 0 0
		1 3 3 1 0
		1 4 6 4 1
		
		
		
	
	#include <stdio.h>

	void printYangHui(int n)
	{
		int a[1000][1000] = { 0 };
		int i,j;
		for(i = 0; i < n; i++)
		{
			a[i][0] = 1;//��ÿһ�еĵ�һ��Ԫ����Ϊ1
			for(j = 0; j <= i; j++)
			{
				if(j == 0 || i == 0)////����ǵ�һ�л��ߵ�һ�У���ִ������ļ��㹫ʽ,��i��j����0��ʱ��-1,���������Խ�磬û��-1����±�
				{
					printf("%3d ",a[i][j]);
					continue;//����ǵ�һ�л��ߵ�һ�У���ִ������ļ��㹫ʽ,��i��j����0��ʱ��-1,���������Խ�磬û��-1����±�
				}
				a[i][j] = a[i-1][j] + a[i-1][j-1];
				printf("%3d ",a[i][j]);
			}
			printf("\n");
		}
	}


	int main(int argc, const char *argv[])
	{
		printYangHui(7);
		return 0;
	}	
	
		
				
		##��ϰ9��
		
		дһ����������ӡ
			*
		   ***
		  *****
		 *******
		*********
		�������ɲ�������
		5 ��
		�ո�����ǵ�һ��  4�� �ڶ��� 3��     n - i - 1
		* ����    2 * i + 1
		
		
		#include <stdio.h>
		
		void print_star(int n)
		{
			int i = 0, j = 0;

			for(i = 0; i < n; i++)
			{
				for(j = 0; j < n - i - 1; j++)
				{
					printf(" ");   //�ȴ�ӡ�ո�
				}
				for(j = 0; j < 2 * i + 1; j++)
				{
					printf("*");   //��ӡ*
				}
				printf("\n");
			}
		}
		int main()
		{
			print_star(5);
		}





��ҵ��1 дһ���������ܽ�����������Ԫ�����,Ҫ���� p[i]��*(p+i)ʵ��

	int a[5] = {90, 80, 70, 60, 50};

	//��ת������



��ҵ��2 �ַ�������   mystrcpy(char *dst, char *src);

int main()
{
	char a[] = "hello"; //'\0' λ�ö�Ӧ���±�����ַ����ĳ���	
	char b[100] = { 0 };
	mystrcpy(b, a);
	///���b
}


#include <stdio.h>

void my_strcpy(char *dst, char *src)
{
	//����һ
	/*
	int i = 0;
	while(*(src+i) != '\0')
	{
		*(dst+i) = *(src+i);
		i++;
	}
	*(dst+i) = '\0';
	*/
	//������
	while(*dst++ = *src++);//��ȡֵ��ֵ���㣬��ָ���Լӣ�����ƶ�һ��λ�ã�ָ����һ���ַ�, ѭ���Ľ������������һ�ν�'\0'��ֵ��ѭ������
}


int main(int argc, const char *argv[])
{
	char a[100];
	char b[] = "hello world";
	puts(a);
	my_strcpy(a,b);
	printf("11111111111\n");
	printf("%s\n",a);
	return 0;
}

/////////////////////////////////////////////////////////////////

int main(int argc, const char *argv[])
{
	char a[100];
	char b[] = "hello world";
	int i = 0;
	int j = 0;
//	while(a[i]=b[i++]); 
	while(a[j++] = b[i++]);
	puts(a);
	return 0;
}

