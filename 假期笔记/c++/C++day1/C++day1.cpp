һ��ָ��

1���������ܴ��ڵĿռ䣺
1.�ѣ��Զ�����������malloc-free   new-delete 
2.ջ��������ʼִ�д��������������{}�����ͷ�  
3.��̬�������һ������������

��̬�ռ��������ͷ�
c�� ���� malloc-free  #include<cstdlib>      malloc������ڴ�ռ���û�����͵�void* �����г�ʼ��
c++�� �ؼ��� new-delete 										 new������ڴ�ռ��������͵ģ��г�ʼ��
1.����
#include<iostream>
using namespace std;

int main()
{//�����͵ı����ж�����������int char float�ȵȽб���
	int *p = new int;//����һ������������Ŀռ� ���ؿռ���׵�ַ
	int* p2 = new int(100);//���ѿռ��int���ͱ�����ʼ����100
	*p = 123;

	cout<<"p:"<<p<<' '<<"*p:"<<*p<<endl;

	delete p;//p��Ұָ��
	p = NULL;//��Ұָ���ó�NULL��֤��ʹ��ʱһ�������
}

2.����
#include<iostream>
using namespace std;

int main()
{
	//��̬��������new ����[���鳤��] ���鳤�ȿ����Ǳ���
	int *p = new int[10];//����һ��洢�������ݵ�����ռ� ��СΪ10*sizeof(int) ���ظÿռ��׵�ַ��û�г�ʼ��
	int len = 20;
	int* p3 = new int[len];
	//int arr[len];//�������Ĵ����Ǵ���ģ���Ϊ�ⲻ�Ƕ�̬����������ֻ���ǳ���
	int *p2 = new int[10]();//��ʼ����0  ()�ڲ�������д���֣�ֻ�ܳ�ʼ����0
	for(int i=0;i<10;i++)
	{
		p[i] = i+1;
	}

	for(int i=0;i<10;i++)
	{
		cout<<p[i]<<' ';
	}

	delete[] p;//�ͷ�����ռ�
	p = NULL;
}

��������
#include <iostream>
using namespace std;

int arrLen = 10;
void expand(int*& arr);

int main()
{
	int* arr = new int[arrLen];

	int len;//���len����10�����涯̬����������Ͳ�������
	cin>>len;
	for(int i = 0;i < len;i++)
	{
		if(i == arrLen)//if����Ϊ�棬˵��ԭ���鲻�����ˣ���Ҫ����
		{
			expand(arr);
		}
		arr[i] = i;
	}

	for(int i = 0;i < len;i++)
	{
		cout<<arr[i]<<endl;
	}

	delete[] arr;
	return 0;
}

void expand(int*& arr1)
{
	int newLen = arrLen*2;//�µ����鳤��
	int* newArr = new int[newLen];//�����µ����飬������ԭ�����2��

	for(int i = 0;i < arrLen;i++)//��ԭ�����е����ݸ��Ƶ��µ�������
	{
		newArr[i] = arr1[i];
	}
	delete[] arr1;// ɾ��ԭ��������
	arr1 = newArr;//arr1�Ǻ����Ĳ�����arr1�ں����������Ӧ����ʧ��ѽ��
	//arr1�����ã���������main�����е�arr��expand�����ı���������������
	//��main�����е�arr��ֵ
	arrLen = newLen;
}

������ĳ���
ΪʲôҪʹ���ࣿ


����ɵ���ֱ����롷��
����¼,����,�ܽ�,����Ĺ��ߣ����۲�����֪ʶ,��ͼƬ�ĺ�ûͼƬ�ģ�
ӲƤ��,��װ����,�����,û����ģ���ǰ��,���,Ŀ¼,������
����������Ե���ʾ,���,�Ľ�,��ǿ�ͽ�����ͨ���Ӿ�ʵ��,��ʱҲ�ô���.��



1.������
class ����
{
public:
};
2.������ʵ������
3.�������Ա

ʾ��1��ջ�ռ䴴�����󲢵��ó�Ա����
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	//��Ա����֮�乲�ó�Ա����
	string name;//��Ա����  ����
	int age;	//��Ա����  ����

	void setName(string n)//��Ա����
	{
		name = n;
	}

	void setAge(int a)
	{
		age = a;
	}

	void print()
	{
		cout<<name<<" "<<age<<endl; 
	}
};
int main()
{
	//����.   ָ��->
	Student xiaoming;//ջ�ռ䴴��
	xiaoming.setName("С��");
	xiaoming.setAge(18);
	xiaoming.print();
}

ʾ��2���ѿռ䴴������

int main()
{
	Student* p = new Student;
	p->setName("С��");
	p->setAge(18);
	p->print();
	delete p;//��delete�ͻ��ڴ�й©
}


��ϰ������Dog�࣬�г�Ա����name���г�Ա����setName������
	sleep˯����eat�Է�
1.setName������name��ֵ
2.sleep���xxx˯����
3.eat���xxx���躰��ؼҳԷ���


��ϰ���Զ���һ����ʵ��ջ�ṹ���г�ջ��pop������ջ��push�����ܣ�
	��top�����ջ��Ԫ�أ����Դ�����������
1.��Ա����ָ��ָ������
2.��Ա������ʾ���鳤��
3.��Ա����pop()��push()��top()
4.��Ա������ʾջ�� int index
5.��Աinit����Ա��������ʼֵ��������Ҫʹ�ù��캯����


��ϰ������������class Link
1.����ڵ�ṹ��
struct Node
{
		int num;
		Node* pNext;
};
2.��Աָ��ָ������ͷpHead������βpTail
3.��Ա������ʾ������size
4.��Ա����add������β����������
5.��Ա����get���ָ��λ�õ�����



��������
1��(����)���أ�overload(��Ӣ���������ǹؼ���)
������Ϊ����������ɶ��Ե�
c++���������������ͬ�ĺ���(ͬһ������������������  һ�����)
Ҫ���β��б���벻ͬ���β����ͻ����βθ�����������ֵ��������ν
ע�⣺����β��б���ͬ ������ֵ��ͬ �ǲ���������
1.�βθ�����ͬ��ȫ�ֺ���������
#include<iostream>
using namespace std;

int fun(int a)
{
	return a*a;
}

int fun(int a,int b)
{
	return a*b;
}

int main()
{
	cout<<fun(10)<<endl;
	cout<<fun(20,40)<<endl;
}

2.���Ͳ�ͬ
ʾ����

#include <iostream>

using namespace std;

int dev(int num1, int num2)
{
	return num1/num2;
}

float dev(float num1, float num2)
{
	return num1/num2;
}

int main()
{
	cout<<dev(10, 3)<<endl;
	cout<<dev(10.0f, 3.0f)<<endl;
}

��ϰ�� ����һ���࣬�����ά�����Ա�����غ���print��
	�ֱ�ʵ�ֳ����ӡ����Ԫ�غ���һ����ʽ��ӡ����
1.print()Ԫ��֮��ʹ�ÿո�
2.print(char space)Ԫ��֮��ʹ��space


2������Ĭ�ϲ���
Ĭ�ϲ�������������ʱ �βδ�ʵ�εõ�ֵ 
���ݲ�����ʱ��һ���ǴӲ����еı���߿�ʼ����
���Ը��β�һ��Ĭ��ֵ �β�ֵ�Ͳ��ش�ʵ��ȡֵ��
ע�⣺�β��б�ֻ�ܴ��Ҳ࿪ʼ��Ĭ��ֵ 
ʾ��1��
#include<iostream>
using namespace std;

void func(int a=80,int b=90,int c=100)//ʵ�δ��� �βε�ֵΪ���ݹ�����ֵ ���ʵ�β����� ���βε�ֵΪĬ��ֵ
{
	cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
}
int main()
{
	func(10,20,30);
	func(10,20);
	func(10);
	func();
}


ʾ��2��
�������������ʱ����Ĭ��ֵ����ô��ʵ�ֵ�ʱ��Ͳ������Ĭ��ֵ
#include<iostream>
using namespace std;

void func(int year=2016);//��������ʱ ָ����Ĭ��ֵ2016 ��������ʱ ���Բ�ָ��ʵ��
int main()
{
	func();
}

void func(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
	{
		cout<<"leap year!"<<endl;
	}
	else 
	{
		cout<<"common year!"<<endl;
	}
}

ע�⣺����������Ĭ��ֵ��Ҫ�Ӻ���Ĳ�����ʼ����

�ġ�����Ȩ�� 
c++����class��c��struct ��չ���� 
c++��class��structֻ��һ���﷨����Ĭ�Ϸ���Ȩ�޲�һ��
classĬ����private��structĬ����public
ϰ�ߣ�c++�ж����߼����ʱ��ʹ��class�������������͵�ʱ��ʹ��struct��������ֲ���
	��ȫ��class��

1.����һ���� 
class ���� //c++����������������� 
{
	//����Ȩ��
	public:
		���е����ݺͺ���; ˭�����Է���
	private:
		˽�е����ݺͺ���; ֮������ڲ����Է���
	protected://�̳е�ʱ���ٽ�
		�ܱ��������ݺͺ���; ֮�������������Է���
};//����ӷֺ�

//���ݣ���Ա���� ��������Ա����  ��Ա�������Է���˽�б���
#include <iostream>

using namespace std;

class Person
{
private://˽������  ����ⲿ���ܷ���  ����ⲿ���������ⶨ��ĺ���
	int money;
	int house;
	int phone;
public:
	void setInfo(int m, int h, int p) //�����ĺ��� ����ⲿ���Է���
	{
		money = m;	//����ڲ������������˽������
		house = h;
		phone = p;
	}

	void show()
	{
		cout<<money<<" "<<house<<" "<<phone<<endl;
	}
};

int main()
{
	Person p;
	p.money = 10;//main�����������еĺ����������е�˽�г�Աû�з���Ȩ��
	p.setInfo(1,2,3);
	p.show();
	return 0;
}

��ϰ�������� ���������������� ���������Ԫ���е����ֵ����Сֵ��ƽ��ֵ
1.�����Ա����private���Σ�Ӧ����һ��ָ��
2.��Ա����input���������ֵ�����鳤��  ��̬���������ݵ�ǰ���߼�������
3.��Ա����max
4.��Ա����min
5.��Ա����agv

��ϰ������һ���࣬���ݳ�Ա��length,width,heigh 
��Ա�������¹��ܣ�
1.�ɼ������볤����ĳ����  input����������
2.���㳤�������
3.������������


�塢���캯��
Ŀ�ģ�Ϊ�˸������ʼ����������Ϊ�˳�ʼ����Ա������Ҳ����ִ��һЩ��ʼ�����߼���
���캯�����ڴ��������ʱ����Զ����õĺ��� 
��c++�������Ա���� ��Ҫ���ڴ�������ʱ ��ʼ������ Ϊ����ĳ�Ա������ֵ
(1)
ע�⣺
a�����ֱ�������ͬ�� �޷���ֵ �����в���
b������Ȩ��һ����public��û�й��캯���ķ���Ȩ�޾Ͳ��ܴ�������
c���û����ܵ��ù��캯�� ֻ��������󴴽�ʱ �Զ�����
class Person 
{
	public:
		Person()//���캯��
		{
			;
		}
};

ʾ��1��

#include<iostream>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:

	Person()
	{
		cout<<"i am constructor...."<<endl;	
	}
	void show()
	{
		cout<<"����"<<name<<"  ����"<<age<<endl;
	}
};

int main()
{
	Person x;
}

ʾ��2��
#include<iostream>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:

	Person()
	{
		//��ֵ:  �ȶ��壬��ֵ��  ���� int a; a = 10;
		//��ʼ��: ���������ʱ��ֵ�г�ʼ��  ����int a = 10;
		name="guanyu";//��Ա������ֵ   
		age = 0;//��Ա������ֵ
	}
	void show()
	{
		cout<<"����"<<name<<"  ����"<<age<<endl;
	}
};

int main()
{
	Person x;//x����ʱ �Զ����ù��캯�� ��ɳ�ʼ������
	x.show();
}

��ϰ�����㳤�����ܳ� ���캯��ʵ�ֳ���ֵ�����캯����������


5.���캯���ĳ�ʼ���б�
��ʼ���б��Ŀ���Ǹ���Ա������ʼ����
���캯����ð����ʽ������ʼ���б�
ע�⣺��ʼ��˳���ǰ��ճ�Ա������˳�򣬳�ʼ����Ա��˳��Ӧ�úͳ�Ա������˳�򱣳�һ�£�������ʹ�ó�Ա��ʼ��������Ա
��ʽ����Ա������(��ʼֵ)

#include <iostream>

using namespace std;

class Rect
{
private:
	int width;
	int height;
public:
	Rect(int width, int height):width(width),height(height)//�ڳ�ʼ���б��б���ʼ���ı����ǳ�Ա����
	{
	}

	int perimeter()
	{
		return width*2+height*2;
	}
};

int main()
{
	Rect* p = new Rect(10, 20);//���������ݸ����캯��
	cout<<p->perimeter()<<endl;
	Rect r(10, 20);
	cout<<r.perimeter()<<endl;
}

ʾ������ʼ��˳��
����������ʱ���ȳ�ʼ����Ա�������ٵ��ù��캯������Ա������������˳���ʼ����
���飺��ʼ���б��˳���������˳�򱣳�һ�¡�
��C++ primer��
#include <iostream>

using namespace std;

class A
{
public:
	A(int a)
	{
		cout<<"A"<<endl;
	}
};

class B
{
public:
	B(int a)
	{
		cout<<"B"<<endl;
	}
};

class C
{
private:
	A a;
	B b;
public:
	C():b(1),a(2)
	{
		cout<<"C"<<endl;
	}
};

int main()
{
	C c;//A B C
	return 0;
}
	

��ϰ��ʵ��һ��������F  ���ܣ�F f1(3,4) ��ʾ���:3/4 
1.���캯���������
2.��Ա����show��ʾ




��ϰ����������ʱ�� ��ʾ����ʱ�����һ��
1.�����Ա���� h m s
2.��Ա����go �ı�h m s ��ֵ
3.��Ա����show��ʾ��һ���ʱ��



6.��������
Ŀ�ģ���������������ֵ����ʼ��ʱ���봴��һ�������ֵĶ���
������ʽ��������(���캯���Ĳ���)����������ֻ��ջ�ռ䴴����

#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age):age(age)
	{
		cout<<"����"<<endl;
	}
private:
	int age;
};

void fun(Person p)
{
    
}

int main()
{
    fun(Person(10));
    //����
    Person p(10);
    fun(p);
��




��ϰ�������˿��࣬˽������color��point������54���ƴ��������� (���캯������)



����thisָ�룺��һ��ָ�룬ָ�������thisֻ��������ڲ�ʹ�ã�������ڲ�����
		��Ա����ʹ��this���õģ�����ʡ��
������ڲ����ó�Ա�����ͳ�Ա����������ʹ��this���ã����Կ���ʡ��this��ʡ��this
		��ʱ�����ʽʹ��this��д��this��ʱ�����ʽʹ��this
		
�ܽ᣺ֻ����ĳ�Ա��������ʹ��thisָ�룬�ĸ�������õĳ�Ա������thisָ���ָ��
	�ĸ�����
		
ʾ��1��
#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age)
	{
		this->age = age;//�������ֻ��Ϊ�˸�this�Ҵ��ڸ�
	}

	void show()
	{
		cout<<age<<endl;
	}
};

int main()
{
	Person p(19);
	p.show();
}

ʾ��2:

#include<iostream>
using namespace std;
class Person 
{
public:
	Person(string n,bool g=true);

	void setAge(int year);
	void show();
	void marry(Person &other);
private:
	string name;
	bool gender;
	int age;
	Person *lover;
};

Person::Person(string n,bool g)
{
			name=n;
			gender = g;
			age = 0;
			lover=NULL;
}

void Person::setAge(int year)
{
	this->age = year;
}

void Person::show()
{
	cout<<"��Һã�����"<<(gender?"˧��":"��Ů  ")<<name<<"������"<<age<<endl;
	cout<<"������:"<<lover->name<<endl;
}

void Person::marry(Person& other)
{
	this->lover = &other;
	other.lover = this;//this ָ�� ָ��ǰ����
	cout<<name<<"��"<<other.name<<"ϲ����Ե!"<<endl;

	cout<<this<<endl;
}

int main()
{
	Person b("�˳�",true);
	Person a("��ٳ",false);
	a.setAge(20);
	b.setAge(38);

	a.marry(b);
	a.show();
	//b.marry(a);
	b.show();
}

�ߡ��������캯��
1��������  ��������������(const �������� &������)  //���ƹ��캯��
ʹ��ͬ���͵�һ�������ʼ����һ�������ʱ����ÿ�������

#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age)
	{
		this->age = age;
	}

	Person(const Person& other):age(other.age)
	{
		cout<<"��������"<<endl;
	}

	void show()
	{
		cout<<this->age<<endl;
	}
};

int main()
{
	Person a(19);
	cout<<"start"<<endl;
	Person b(a);//���ö���b �Ŀ������캯��
	cout<<"end"<<endl;
	b.show();
}

