��ϰ��

printf("hello world!!\n");

int a;//�������ͱ����������

a = 100;//��ֵ

int a = 100; //��ʼ��

printf("a is %d\n",a);//��ʽ�����

//��ʽ������ 

scanf("%d",&a);

���������  + - * / %

   5 / 2 ---> 5�����м���2  ����2 

######�ص㣺 �����Ҫ�����Ϊ����������������� %

> < >= <= == !=

if(����)//�������� Ϊ�棬��ִ��{ }��������
{
	���
}
else //���� ���if������������ִ��else����{ }�����
{
	���
}

�˽���������0��ͷ 

ʮ�����ƣ���0x��ͷ 

45   --�� 2     8  16  
		101101 055 2D
0x7C --��  2  	  8  10
		1111100 0174 124

һ���˽���λ����������������λ

һ��ʮ������λ�������ĸ�������λ

2.1.0 sizeof()�����
	
	sizeof(int)-----> 4
	
	1GB === 1024M
	
	1M === 1024KB
	
	1KB === 1024 byte
	
	1 byte == 8 bit
	
	

	sizeof()���ã������������ռ�ڴ�ռ�Ĵ�С(���ֽ�Ϊ��λ)��

	
	�������һ������������һ���Ǳ�����
	
	�����������͵�ֵ


	----�������-----//�κ��Լ���֤����

	����int, short, long, float,double���ͱ�����

	Ȼ���������ռ���ڴ�ռ��С����ӡ

	
	#include <stdio.h>

	int main()
	{
		int a = 100;
		float b = 100.4;
		char c;
		double d;
		long int e;
		short int f;
		printf("sizeof(int) is %d sizeof(a) is %d\n",sizeof(int),sizeof(a));
		printf("sizeof(double) is %d sizeof(d) is %d\n",sizeof(double),sizeof(d));
		printf("sizeof(char) is %d sizeof(c) is %d\n",sizeof(char),sizeof(c));
		printf("sizeof(long int) is %d sizeof(e) is %d\n",sizeof(long int),sizeof(e));
		printf("sizeof(short int) is %d sizeof(f) is %d\n",sizeof(short int),sizeof(f));
		return 0;
	}
	
	####������
	
	sizeof(int) is 4 sizeof(a) is 4
	sizeof(double) is 8 sizeof(d) is 8
	sizeof(char) is 1 sizeof(c) is 1
	sizeof(long int) is 4 sizeof(e) is 4
	sizeof(short int) is 2 sizeof(f) is 2


	���ۣ��������Ĵ�С��ȡ���ڱ��������ͣ��������ֵ���޹�ϵ��


	��������			��ʽ������������ͺ͸�ʽ                ռ�ڴ�ռ�Ĵ�С
		
		char	�ַ���			%c										1�ֽ�
		short	����������		%d										2�ֽ�
		int	    ��������		%d										4�ֽ�
		long	����������		%ld										4�ֽ�
		float	�����ȸ����ͣ�����С����%f								4�ֽ�
		double	˫���ȸ����ͣ�����С����%lf								8�ֽ�



2.1.1  ���ֺ��ַ�(**)

	�������ұ�׼ίԱ�ᣬ�涨��ÿһ���ַ�����һ����Ч����������ʾ��������־���ascii��

                                  		2����     16����     10����
######��ϰ1�� ����ascii���� '0'��    	0011 0000     0x30       48               
                     		'a'       	0110 0001     0x61       97
                    		 'A'      	0100 0001     0x41       65        
                    		 ' ' (SP) 	0010 0000     0x20       32   
                     		�س�(CR)   0000 1101     0x0D      13   
                     		esc       	0001 1011     0x1B       27

man ascii

c �������ַ��� ' ' ����ʾ��**��

���� 1��2��3��4
�ַ� '1' '2'  '3'  '4'  '#'
        'a' 'A'

'1' = '0' + 1;  48 + 1 == 49
'2' = '0' + 2;
'9' = '0' + 9;

'b' = 'a' + 1;
'c' = 'a' + 2;
.....

'A' = 'B' - 1; 
'C' = 'A' + 2;


##���������һ���ַ���


char  ���������ַ�

#include <stdio.h>
int main()
{
	char a = 'X';	//����һ���ַ��ͱ���a, ֵΪ'X'
	scanf("%c", &a);
	printf("a is %c\n", a);	// %c ��ʾ���һ���ַ�
}
-------------------------------------------------------------------------------------------------------------

'\0' ---> 0

'0'  ---> 48




######��ϰ2��
			����һ���ַ��������ж�
			1)����� Сд��ĸ ��ӡ��� is small letter!! 'a'  ---- 'z'
			2)����� ��д��ĸ ��ӡ��� is big letter!!  'A' ---- 'Z'
			3)����� ����    ��ӡ��� is number '0' ---- '9'
	
//����һ���ַ����ж��ǲ����ַ� 'a'


#include <stdio.h>
int main()
{
	char a;	//����һ���ַ��ͱ���a
	scanf("%c", &a);
	if(a >= '0' && a <= '9')
	{
		printf("a is digital\n");
	}
	else if(a >= 'a' && a <= 'z')
	{
		printf("a is small char\n");
	}
	else if(a >= 'A' && a <= 'Z')
	{
		printf("a is big char\n");
	}
}

//////////
if(����1)
{
	//���1  //��������1��ִ�����1
}
else if(����2)
{
	//���2  //����1������������2������ִ�����2
}
else if(����3) //����1������������2������������3������ ִ�����3 
{
	//���3
}
else //����1 2 3 ����������ִ�����4
{
	//���4
}

------------------------------------------------------------------------------------------------------------
2.1.3 �Լӡ��Լ�

(1)++  (���������)
	
	int a = 1;
	a++;   //ִ����a = 2
	int a = 1;
	++a;   //ִ����a = 2  

	int x = 4;
	int y;
	y = x++;  //ִ���꣬y = 4, x = 5
	//++�ڱ������棬 �����㣬��++,  (y = x;  x++)

	y = ++x;  //ִ���꣬y = 5, x = 5;
	//++�ڱ���ǰ�棬 ��++��������,  (x++; y = x)

--------������ʾ------------
#include<stdio.h>

int main()
{
	int x = 6,y = 7;
	int z;
	z = x++ + ++y;     
	printf("x = %d,y = %d,z = %d\n",x,y,z);
}

ִ�н����
x = 7,y = 8,z = 14  .

(2) -- (�Լ������ͬ��)

	a--; a = a-1;
	
	--a; a = a-1

###�߼�&& �� ||�Ķ�·����

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = -1;
	int b = 2;
	if(++a && ++b)//��ӡhello world������������������� ++a,a == 0,
	{//&&��һ�ټ��٣����������++bû�б�ִ��
		printf("hello world\n");
	}
	printf("a is %d\nb is %d\n",a,b);//��ӡa is 0 b is 2
	return 0;
}



#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 0;
	int b = 2;
	if(++a || ++b)//��ӡhello world��������������� ++a,a == 1,
	{//||��һ�漴�棬���������++bû�б�ִ��
		printf("hello world\n");
	}
	printf("a is %d\nb is %d\n",a,b);//��ӡa is 1 b is 2
	return 0;
}
-------------------------------------------------------------------------------------------------------------
2.1.4 ����������ʽ�� +=    -=   *=     /=    %=
	
	a += 1; a++;
	a += 3;     <=====>   a = a + 3;
	a -= 3;     <=====>   a = a - 3;
	a *= 3;     <=====>   a = a * 3;

	a += b;      <=====>   a = a + b;
	a += b + 3;  <=====>   a = a + (b + 3);

--------������ʾ------------
#include <stdio.h>
int main()
{
	int a = 5;
	int b = 2;
	a += 3;
	printf("a %d\n", a); // a 8
	a += b;
	printf("a %d\n", a); // a 10
}
-------------------------------------------------------------------------------------------------------------

#######��ϰ4������������, �Ƚ��������Ĵ�С����ӡ����������е����ֵ��
���磺   a = 8 , b = 5 , c = 3;
����Ļ���    ���ֵ��8 


//a������Զ�������ֵ
//����a�����ֵ 
//��a��b�Ƚϣ����b�󣬽�b��ֵ��a
//��a��c�Ƚϣ����c�󣬽�c��ֵ��a


#include <stdio.h>
int main()
{
	int a = 5, b = 6, c = 2;
	if(a < b)
	{
		a = b;
	}
	if(a < c)
	{
		a = c;
	}
	printf("max is %d\n",a);
	return 0;
}

2.1.5  ��Ŀ�����

   ?  :  ���ʽ          c������Ψһ����Ŀ�����
   
  ���ʽ1 �����ʽ2 �����ʽ3

 int min =  a < b ? a : b //  
  
  int a = 3;
  int b = 5;
  int max = a > b ? a : b;//���a > bΪ��,ֵΪ����ߵ�ֵ�� ���a> bΪ�٣�ֵΪ:�ұߵ�ֵ

�����жϱ��ʽ1����Ϊ�棬��ִ�б��ʽ2����Ϊ�٣���ִ�б��ʽ3
  
######��ϰ3�����������������ֵ����ĳ��� ? : ���ʽ��ʵ��

#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	a = a > b ? a : b;
	a = a > c ? a : c;
	printf("max = %d\n",a);
}

---------------------------------------------------------------------------------------------------------------------------
//C�����������ṹ 

1.˳��ṹ 

2.ѡ��ṹ 

3.ѭ���ṹ
	
2.2.1 ��if���ʵ�ֶ���֧ѡ��ṹ(����)

(1)if(����)
{
	���
}

(2)if-else 
if(����)
{
	���1
}
else 
{
	���2 
}
(3)ifǶ�� 

if()
{
	if()
	{
		
	}
}
(4)if - else if - else
if()
{
	
}
else if()
{
	
}
else if()
{
	
}
else
{
	
}


2.2.2 ��switch���ʵ�ֶ��֧ѡ��ṹ

	switch(���ʽ)	//switch������һ�������Ǹ������� ������int, char, short, long
	{
		case �������ʽ1:		//���ʽ��ֵ�ͳ������ʽ��ֵ���ʱ����ִ�д�case������䡣
				���1;
				break;
		case �������ʽ2:
				���2;
				break;	
			.
			.
		case �������ʽn:
				���n;
				break;
		default:			//Ĭ�Ϸ�֧������Ķ������㣬ִ��default������䡣
				���n+1		
	}

--------������ʾ------- ���û����룬���1����ӡmonday, �����2 ��ӡtuesday�� ���3��ӡwensday, ���4��ӡthursday


#include <stdio.h>

int main(int argc, const char *argv[])
{
	int day;
	printf("Please input day:\n");
	scanf("%d",&day);
	switch(day)//char shrt int int long 
	{//{ }֮�䱻��Ϊswitch�� 
		case 1:
			printf("����һ\n");
			break;//����switch��
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n");
			break;
		default://��������case ���⣬��ִ��default
			printf("�������ڡ�һ��������\n");
	}
	return 0;
}


######��ϰ7��

	��switch���ʵ��һ��С�ͼ����� 
	
	���磺����3 + 5 ��ӡ��� 8  '+' '-' '*' '\' 
	
	3+5
	8
	5-3
	2
	
	
	
		
	
#include <stdio.h>
int main()
{
	int a,c;
	char b;
	scanf("%d%d", &a, &c);
	getchar();			//����ʱ���ջس�����**��
	scanf("%c",&b);
	//��switch �ж� b,  '+'   '-'  '*'  '/'
	switch(b)
	{
	case '+':
		printf("%d\n", a + c);
		break;
	case '-':
		printf("%d\n", a - c);
		break;
	case '*':
		printf("%d\n", a * c);
		break;
	case '/':
		printf("%d\n", a / c);
		break;
	default:
		printf("error\n");
		break;
	}
}





2.2.3 ����ת����*��

	�˽������
	ת��ԭ�򣺴�С����  char --> short --> int --> long --> float --> double
	ǿ������ת��(**)

	///����ת��
	int a= 3;
	float b = 1.2;
	a + b ?  �����float  ������ͬ���ͽ������㣬Ҫ��������ת��

	ת��ԭ�򣺴�С����  char --> short --> int --> long --> float --> double

	#include <stdio.h>
	int main()
	{
		int a= 3;
		float b = 1.2;
		printf("%f\n", a + b);  //a ת��float���ͣ�����ת������ʽת�������߽�Ĭ��ת��
		//���ϣ����bת��int, Ȼ����� + ����
		printf("%d\n", a + (int)b);  //(int)b   ǿ������ת��
	}



2.2.4 ����(��ֵ�����Ը�)

100, 'A'
#define PI 3.14    //����һ���곣�� �� PI, ֵ3.14


1)  ��Բ�뾶Ϊr,��Բ�ܳ�,Բ�������scanf����뾶,���������,��д����. 
3.14 �ú�����ʾ

2 * PI * r
PI * r * r

#include <stdio.h>
#define PI 3.14
int main()
{
	float r, l, s;
	scanf("%f", &r);
	l = 2 * PI * r;
	s = PI * r * r;
	printf("l is %f, s is %f\n", l, s);
}

//�����ĺô�
1 �ܴﵽһ��ȫ�ĵ�Ŀ��
2 �����ӳ���Ŀɶ���



��ҵ��

1
����ѧ���ɼ�

	90-100 �ִ�ӡ A
	80-89  �ִ�ӡ B
	70-79  �ִ�ӡ C
	60-69  �ִ�ӡ D
	����������
		
		
�ֱ���if�����ж�   ��   sitch��֧   ���ַ���ʵ��



2. �ж��û���������Ƿ�Ϊ���ꣿ
	����һ��
	���겻��
	�İ������� 2000 yes 1900 no
	���� 1993 1900 2000 2004  ƽƽ����