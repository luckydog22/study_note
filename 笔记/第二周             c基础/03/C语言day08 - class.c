#��ϰ��

int a[5] = {1,2,3,4,5};
int *p = a;//int *p = &a[0];
int *q = &a[4];

q - p ==== ? 4 //�����������

*(p+i) ==== a[i] ==== p[i] ==== *(a+i)//ֵ

p+i === &a[i] === &p[i] === a+i 

p++;
a++;//������Ϊa�ǵ�ַ����

a += 2; //����

int *p;  0x00001100

p+1 ---�� 0x00001104 //����һ��int  4*1


double *q  0x00001100

q+2        0x00001110 //��������double 8*2
char *z 	0x00001100

z+1   		0x00001101

//////�κ����͵�ָ�������ռ�ڴ�ռ�Ĵ�С����4���ֽ�


ָ�������ָ�������������� p+q ���� 

int *p = NULL;//��һ��ָ���ʼ��Ϊ��ָ�� NULL ---��0

////////////////////////////////////////////////////////////////

ֵ���ݺ͵�ַ����

(1)ֵ����

void setA(int b)
{
	b = 100;
}

int main()
{
	int a = 0;
	setA(a);//ֵ���ݣ��޸ĵ��ǲ���b��ֵ����main�����е�aû�б��޸�
}
(2)��ַ���� 
void setA(int *p)
{
	*p = 100;
}

int main()
{
	int a = 0;
	setA(&a);//��ַ���ݣ��޸�a��ֵ
}
 
 
��ַ���ݲ��ܸı�ʵ�ε�ֵ

һ��������Ҫ�������ĵ����ߴ���ֵ���м��ַ���

(1)����ֵ 

(2)������ַ����

///////////////////////////////////
strcmp("abc","abc");  == 0

strcmp("ab","abc"); === -1

strcmp("ac","abcdef"); === 1


#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[1000] = { 0 };//�����������
	int all_num;//��������
	int start_num;//��ʼ����
	int kill_num;//��������ɱ������
	int rm_num;//��ɱ���ĺ��Ӷ�Ӧ�����е��±�
	printf("�������������:\n");
	scanf("%d",&all_num);
	printf("��������ʼ����:\n");
	scanf("%d",&start_num);
	printf("��������������Ϊɱ���ĺ���:\n");
	scanf("%d",&kill_num);
	int i,j;
	for(i = 0; i < all_num; i++)
	{
		a[i] = i+1;
	}
	rm_num = (start_num + kill_num - 2)%all_num;//�õ�������ɾ���ĺ����Ӧ������±�
	while(a[1] != 0)
	{
		printf("ɱ������%d\n",a[rm_num]);
		//ɾ��˼��:׷����ǰ�ƶ�һ��λ�ã�����
		for(i = rm_num; i < all_num; i++)
		{
			a[i] = a[i+1];
		}
		all_num--;//ɾ���󣬺��ӵ�����-1
		rm_num = (rm_num + kill_num - 1)%all_num; //ȷ����һ�α�ɾ���ĺ��Ӻ����Ӧ���±�
	}
	printf("������%d\n",a[0]);
	return 0;
}



1.�ṹ��   

	����
	ѧ��ͼ�����ϵͳ��
	��һЩ��������ͼ����Ϣ
	
		char name[20];
		int number;
		char writer[20];
		char date[20];

	��һЩ�������������(ѧ��)��Ϣ
	
		char name[20];
		int number;
		char class[20];
		char date[20];


	�ṹ�������
	Ϊ�˷���������ǿ��Խ���Щ������֯��һ�𣬹��ɽṹ��

	1.1 ��ζ���ṹ��(��һ�������ͣ���ͬ��int, char, float, double�������ýṹ�嶨�����)

		����һ��ѧ���ṹ��
		struct student		//struct �ṹ�嶨��ؼ��֣�student �ṹ����
		{
			int number;		//��Ա����
			char name[20];	//��Ա����
			int age;		//��Ա����
			int score;		//��Ա����
		};//ע��˴�һ��Ҫ��;��

	1.2 ��ζ���ṹ�����

		struct student s1;		//s1 �ǽṹ������� struct student ������
						//s1 �������ĳ��ѧ��
		(1)��γ�ʼ��
		
			struct student s1 = {1001, "xiaoli", 25, 90};

		(2)���ͨ���ṹ��������ʽṹ���Ա
		
			s1.age = 30; 	// "." Ϊ��Ա����������Է��ʽṹ���Ա�͸�ֵ

			ѧ���ṹ������
			
			#include <stdio.h>

			struct student		//struct �ṹ�嶨��ؼ��֣�student �ṹ����
			{
				int number;		//��Ա����
				char name[20];		//��Ա����
				int age;		//��Ա����
				int score;		//��Ա����
			};
			int main()
			{
				struct student s1 = {1001, "xiaoli", 25, 90};
				printf("name %s, number %d, age %d, score %d\n", 
						s1.name, s1.number, s1.age, s1.score);
			}

			������Ϣ�������������������������������
			s1.age = 30;
			s1.score = 90;
			s1.name = "xiaowang";		//����Ϊ���鲻�������帳ֵ
			strcpy(s1.name, "xiaowang");
			s1 = {1002, "xiaowang", 25, 90};	//���ṹ��ֻ�ж���ʱ�������帳ֵ,��֮ǰ��ѧ������һ��

			///����ṹ��ͬʱ�����������ʵ�ʺ���������
			struct student		
			{
				int number;		
				char name[20];		
				int age;		
				int score;		
			}s1, s2;
			
			##��ϰ1 
			
			����һ���ṹ��worker,�������Ա����������š����䡢����(float)
			������Ϣ�������
			#include <stdio.h>

			struct worker		
			{
				char name[20];		
				int number;		
				int age;		
				float salary;		
			};
			int main()
			{
				struct worker s1;
				scanf("%s%d%d%f", nas1.me, &s1.number, &s1.age, &s1.salary);
				printf("name %s, number %d, age %d, salary %f\n", 
						s1.name, s1.number, s1.age, s1.salary);
			}

	1.3ָ��ṹ���ָ��
	
		����ָ�������ָ��һ���ṹ�����
		�����ָ��������ʽṹ���Ա��
		s->age 
		s->name
		s->score

		struct student *p;
		struct student *s;

		#include <stdio.h>

		struct student		//struct �ṹ�嶨��ؼ��֣�student �ṹ����
		{
			int number;		//��Ա����
			char name[20];		//��Ա����
			int age;		//��Ա����
			int score;		//��Ա����
		};
		int main()
		{
			struct student s1 = {1001, "xiaoli", 25, 90};
			struct student *s = &s1;

			printf("name %s, number %d, age %d, score %d\n", 
					s->name, s->number, s->age, s->score);
		}

	1.4�ṹ�������������������
	
		����� ��ӡѧ����Ϣ д��һ�����������ǾͿ��Խ�ѧ���ṹ����Ϊ�������ݸ�������
		
		(1)ֵ����
		
		#include <stdio.h>
		struct student		//struct �ṹ�嶨��ؼ��֣�student �ṹ����
		{
			int number;		//��Ա����
			char name[20];		//��Ա����
			int age;		//��Ա����
			int score;		//��Ա����
		};
		void print_student(struct student s)
		{
			printf("name %s, number %d, age %d, score %d\n", 
					s.name, s.number, s.age, s.score);
		}

		int main()
		{
			struct student s1 = {1001, "xiaoli", 25, 90};
			print_student(s1);
		}

		(2)��ַ����
		
		#include <stdio.h>
		struct student		//struct �ṹ�嶨��ؼ��֣�student �ṹ����
		{
			int number;		//��Ա����
			char name[20];		//��Ա����
			int age;		//��Ա����
			int score;		//��Ա����
		};
		void print_student(struct student *s)
		{
			printf("name %s, number %d, age %d, score %d\n", 
					s->name, s->number, s->age, s->score);
		}

		int main()
		{
			struct student s1 = {1001, "xiaoli", 25, 90};
			print_student(&s1);
		}

	1.5 ���ݽṹ������
	
		������������ݽṹ�����������ʹ��ָ�룬�ô��ǽ�ʡ�ڴ�ռ�

		/////����ṹ������
		#include <stdio.h>
		struct student		//struct �ṹ�嶨��ؼ��֣�student �ṹ����
		{
			int number;		//��Ա����
			char name[20];		//��Ա����
			int age;		//��Ա����
			int score;		//��Ա����
		};
		int main()
		{
			struct student s[3] = {{1001, "xiaoli", 25, 90},{1002, "xiaowang", 26, 72},{1003, "xiaozhang", 27, 85}};
			int i;
			for(i = 0; i < 3; i++)
			{
				printf("name %s, number %d, age %d, score %d\n", 
					s[i].name, s[i].number, s[i].age, s[i].score);
			}
		}
		
		#include <stdio.h>
		struct student		//struct �ṹ�嶨��ؼ��֣�student �ṹ����
		{
			int number;		//��Ա����
			char name[20];		//��Ա����
			int age;		//��Ա����
			int score;		//��Ա����
		};
		void print_all(struct student *s, int n)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				printf("name %s, number %d, age %d, score %d\n", 
					s[i].name, s[i].number, s[i].age, s[i].score);	//(s + i)->name
			}
		}
		int main()
		{
			struct student s[3] = {{1001, "xiaoli", 25, 90},{1002, "xiaowang", 26, 72},{1003, "xiaozhang", 27, 85}};
			print_all(s, 3);
		}

/////////////////////

	��ϰ�ṹ��
	�ṹ����һ������(��int ��float�� char �ȼ۵�)
	�ṹ�����ɻ���������ϳ� ��

	�ṹ��ʹ�ò���
	1 ����ṹ��(����)
	struct student
	{
		char name[20];
		int number;
		int age;
		int score;
	};

	2 ����ṹ�����
	struct student s1 = {"xiaoli", 1001, 25, 90};

	struct student *s = &s1;

	struct student s[3] =  {{1001, "xiaoli", 25, 90},{1002, "xiaowang", 26, 72},{1003, "xiaozhang", 27, 85}};


	�ṹ���������Ĳ���(���õ�ַ����)


		##��ϰ3
	
		дһ������, �˺���������student���ͱ�����ֵ
		#include <stdio.h>
		struct student
		{
			char name[20];
			int number;
			int age;
			int score;
		};
		void set_student(struct student *s)
		{
			scanf("%s%d%d%d", s->name, &s->number, &s->age, &s->score);
		}
		void print_student(struct student *s)
		{
			printf("name %s, number %d, age %d, score %d\n", 
					s->name, s->number, s->age, s->score);
		}
		int main()
		{
			struct student s1;
			set_student(&s1);	//�ܸ�s1 ��ֵ
			print_student(&s1);	//�ܴ�ӡs1��ֵ
		}

		##��ϰ4
	
		��������Ľṹ�壬дһ������������n��student����ѯ�������� > 25��student��
		���������student�Ļ�����Ϣ������print_student������

		#include <stdio.h>
		struct student
		{
			int number;
			char name[20];
			int age;
			int score;
		};
		void print_student(struct student *s)
		{
			printf("name %s, number %d, age %d, score %d\n", 
					s->name, s->number, s->age, s->score);
		}
		void find_by_age(struct student *s, int n, int age)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				if(s[i].age > age)
				{
					print_student(&s[i]);
				}
			}
		}
		int main()
		{
			struct student s[3] =  {{1001, "xiaoli", 25, 90},{1002, "xiaowang", 26, 72},{1003, "xiaozhang", 27, 85}};
			find_by_age(s, 3, 25);
		}
		
		
		##��ϰ6

		��������Ľṹ�壬дһ������������n��student����ѯ������"xiaoli"��student������������(main)��������(main)����������Ϣ
		
		//////����һ ����ʱ�±�
		#include <stdio.h>
		#include <string.h>

		struct student
		{
			char name[20];
			int age;
			int score;
		};//һ��Ҫ��;��

		//����ѧ����Ϣ
		void set_all(struct student *p,int n)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				scanf("%s%d%d",p[i].name,&p[i].age,&(p+i)->score);
			}
		}
		//ͨ�����ֲ���ѧ��
		int find_by_name(struct student *p, int n,char *name)//name�����ѯ��ѧ��������
		{
			int i = 0;
			for(i = 0; i < n; i++)
			{
				if(strcmp(p[i].name,name) == 0)//�ж������ַ����Ƿ������strcmp
				{
					return i;
				}
			}
			return -1;//֤��û���ҵ�
		}


		int main(int argc, const char *argv[])
		{
			struct student s[3];
			//����ѧ����Ϣ
			set_all(s,3);
			int i = find_by_name(s,3,"xiaoli");
			if(i != -1)
			{
				printf("%s %d %d\n",s[i].name,s[i].age,s[i].score);
			}
			else
			{
				printf("û���ҵ�!!!\n");
			}
			return 0;
		}
		
/////������,���ص��ǽṹ��ָ�룬��ַ

#include <stdio.h>
#include <string.h>

struct student
{
	char name[20];
	int age;
	int score;
};//һ��Ҫ��;��

//����ѧ����Ϣ
void set_all(struct student *p,int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%s%d%d",p[i].name,&p[i].age,&(p+i)->score);
	}
}
//ͨ�����ֲ���ѧ��
 struct student *find_by_name(struct student *p, int n,char *name)//name�����ѯ��ѧ��������
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		if(strcmp(p[i].name,name) == 0)//�ж������ַ����Ƿ������strcmp
		{
			return &p[i];
		}
	}
	return NULL;//֤��û���ҵ�
}


int main(int argc, const char *argv[])
{
	struct student s[3];
	//����ѧ����Ϣ
	set_all(s,3);
	struct student * p = find_by_name(s,3,"xiaoli");
	if(p != NULL)
	{
		printf("%s %d %d\n",p->name,p->age,p->score);
	}
	else
	{
		printf("û���ҵ�!!!\n");
	}
	return 0;
}

	1.6�ṹ��ռ���ڴ�ռ��С
	
		struct student
		{
			int number;
			char name[20];
			int age;
			int score;
		};
		
		struct student s1;
		sizeof(struct student)  sizeof(s1)  ?    32

		struct student *s;     sizeof(s)  sizeof(struct studnet *)    ?    4

		struct A       //sizeof(struct A)?  
		{
			char c2;
			int a;
			double b;
			char c1;
		};

		sizeof(struct A)    ?    16
		

2�ڴ����

	2.1�����ڴ���䣬��Ϊ���ַ�ʽ
	
	(1)��̬����(�ڱ���ʱȷ���ڴ�Ĵ�С)
	
		int a;           //��a����4�ֽڿռ�
		
		char c[100];     //��c����100���ֽڿռ�


		��̬���䣬�ڱ���ʱ��ȷ�����ڴ�ռ�Ĵ�С

						  int n;
		�������� �������� char c[n];   //����Ԫ�ظ���һ����һ������

	(2)
		;
		��̬�ڴ����
		������ʱ��ȷ���ڴ�Ĵ�С

		char *p = malloc(100);	//malloc�Ƕ�̬�����ڴ溯��, 100�Ƿ�����ڴ��С,  
					//����ֵ������ڴ���׵�ַ����ֵ��p, ʹ��p���Է�������ڴ�

		int *p = malloc(100 * sizeof(int));   //

		struct student *p = malloc(100 * sizeof(struct student));

		������n��Ԫ�صĶ�̬���飬�����
		#include <stdio.h>
		#include <stdlib.h>
		int main()
		{
			int n, i;//n����n��ѧ��
			int *p;
			scanf("%d", &n);			//����nֵ
			p = malloc(n * sizeof(int));		//����n��int
			for(i = 0; i < n; i++)
			{
				p[i] = i;			//��n��int ��ֵ
			}
			for(i = 0; i < n; i++)
			{
				printf("%d\n", p[i]);		//��ӡn��int
			}
		}

		##��ϰ7
		ѧ������������ȷ������̬�����ڴ棬����ѧ���ɼ���
		Ȼ�����ѧ��ƽ���ɼ�
		
		
		#include <stdio.h>
		#include <stdlib.h>
		int main()
		{
			int n, i, sum = 0;
			int *p;
			printf("please input num: ");
			scanf("%d", &n);			//����nֵ
			p = malloc(n * sizeof(int));		//����n��int
			printf("please input score: ");
			for(i = 0; i < n; i++)
			{
				scanf("%d", &p[i]);		//����ɼ�		
			}
			for(i = 0; i < n; i++)
			{
				sum += p[i];			//���ܳɼ�
			}
			printf("avg is %d\n", sum / n);
		}

		ע�⣺
		
		(1)
		//malloc����ռ�����ֶ����룬�ֶ��ͷ�
		//��̬�ڴ���䣬�����Զ��ͷţ���Ҫ�ڳ������ͷ�
		free(p);    

		ͨ�� malloc �� freeҪ�ɶԳ���
		#include <stdio.h>
		#include <stdlib.h>
		int main()
		{
			int n, i, sum = 0;
			int *p;
			printf("please input num: ");
			scanf("%d", &n);			//����nֵ
			p = malloc(n * sizeof(int));		//����n��int
			printf("please input score: ");
			for(i = 0; i < n; i++)
			{
				scanf("%d", &p[i]);		//����ɼ�		
			}
			for(i = 0; i < n; i++)
			{
				sum += p[i];			//���ܳɼ�
			}
			printf("avg is %d\n", sum / n);
			free(p);	//�ͷ��ڴ�
		}

		(2)
		
		��̬�ڴ�������ʧ��

		�������ʧ�ܣ�malloc����ֵΪNULL,

		���ԣ������Ҫ���p�ǲ���NULL
		#include <stdio.h>
		#include <stdlib.h>
		int main()
		{
			int n, i, sum = 0;
			int *p;
			printf("please input num: ");
			scanf("%d", &n);			//����nֵ
			p = malloc(n * sizeof(int));		//����n��int
			if(p != NULL)//�����ΪNULL��˵������ռ�ɹ�
			{
				printf("please input score: ");
				for(i = 0; i < n; i++)
				{
					scanf("%d", &p[i]);		//����ɼ�		
				}
				for(i = 0; i < n; i++)
				{
					sum += p[i];			//���ܳɼ�
				}
				printf("avg is %d\n", sum / n);
				free(p);	//�ͷ��ڴ�
			}
		}



