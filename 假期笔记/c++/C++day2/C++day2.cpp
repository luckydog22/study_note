
һ���������캯��
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

2���������캯���������������
��1����������Ҫ����һ���¶��� ������һ��ͬ��Ķ��������ʼ�� 
ʾ����
int main()
{
	Person a(19);
	cout<<"start"<<endl;
	Person b(a);//���ö���b �Ŀ������캯��
	Person c = a;//���ö���c�Ŀ������캯��
	cout<<"end"<<endl;
	b.show();
}
��2���������Ĳ���Ϊ��Ķ���ʱ
ʾ��1��
void farsight(Person p);

int main()
{
	Person a(19);
	cout<<"start"<<endl;
	farsight(a);//ʹ�ö���a��ʼ�������Ĳ���p��a��p�����������Ķ���
	cout<<"end"<<endl;
}

void farsight(Person p){}

ʾ��2��
void farsight(Person& p);

int main()
{
	Person a(19);
	cout<<"start"<<endl;
	farsight(a);//p��a�ı�����p��a��ͬһ������
	cout<<"end"<<endl;
}

void farsight(Person& p){}


��3�������ķ���ֵΪ�����
������صĶ����ں���������ᱻɾ������ô�Ὣ�������أ��������ã�����ʱ����
���ÿ������죻������صĶ����ں��������󲻻ᱻɾ������ô����ÿ������캯��������
һ�����󷵻ء�
ʾ����
Person farsight();

int main()
{
	farsight();
}

Person farsight()
{
	Person* p = new Person(19);
	cout<<"after new"<<endl;
	return *p;
}

��ϰ��
1��Student��
1.˽�г�Աscore��name
2.���캯������score��name
3.���к���setScore��score��ֵ
4.���к���show��ʾ�ɼ�������
2��Teacher��
1.Student* students[5]˽�����鱣��ѧ������
2.���й��캯������students���鸳ֵ
3.���к���randHappyBoy()�����ȡһ��ѧ��   Student* randHappyBoy();
4.���к���hehe()�������ȡ�����ѧ����Ϊ0�� void hehe(Student* hb);
5.���к���show()��ʾ���յ�����ѧ���ɼ�



3��˽�й��캯���Ϳ������캯��
ʾ��1��˽�й��캯�� ���ܴ�������
#include <iostream>

using namespace std;

class Person
{
private:
	Person()
	{}
public:
	Person(int a)
	{}
};

int main()
{
	Person p2;//������Ϊ�޲εĹ��캯��˽�л���
	Person p(1);
	return 0;
}
ʾ��2��˽�п������캯��  ���ܸ��ƶ���
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
		cout<<"����"<<endl;
	}
private:
	Person(const Person& other):age(other.age)
	{
		cout<<"��������"<<endl;
	}

	void show()
	{
		cout<<this->age<<endl;
	}
};
Person farsight();

int main()
{
	Person p(19);
	Person b = p;//���� ���ܸ��ƶ���
}

4�������ǳ����
ʾ��1��ǳ����  ���������ʱ�򣬲���ָ���Ա��ָ��Ķ�����п��������������ָ���Աָ�����ͬһ������
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Phone
{
private:
	string name;
public:
	Phone(string name):name(name){}
};

class Person
{
private:
	Phone* pPhone;
public:
	Person()
	{
		pPhone = new Phone("ŵ����plus");
	}
	Phone* getPhone()
	{
		return pPhone;
	}
};

int main()
{
	Person xiaoming;
	Person xiaoqiang(xiaoming);//Ĭ�Ͽ������죬ǳ����
	cout<<xiaoming.getPhone()<<endl;
	cout<<xiaoqiang.getPhone()<<endl;
}

ʾ��2�����  ��Ҫ�ڶ���Ŀ������캯���жԳ�Աָ����ָ��Ķ���Ҳ���п���

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Phone
{
private:
	string name;
public:
	Phone(string name):name(name){}
	string getName()
	{
		return name;
	}
};

class Person
{
private:
	Phone* pPhone;
public:
	Person()
	{
		pPhone = new Phone("ŵ����plus");
	}

	Person(const Person& other)
	{
		//��other��phone����һ���µ�phone����
		pPhone = new Phone(*other.pPhone);//����Աָ��ָ��Ķ�����и���
	}

	Phone* getPhone()
	{
		return pPhone;
	}
};

int main()
{
	Person* xiaoming = new Person();
	Person xiaoqiang(*xiaoming);
	cout<<xiaoming->getPhone()<<endl;
	cout<<xiaoqiang.getPhone()<<endl;
	cout<<xiaoming->getPhone()->getName()<<endl;
	cout<<xiaoqiang.getPhone()->getName()<<endl;
}

ע�⣺����ǳ�����Ͳ������

5�����Ա�ĳ�ʼ��˳���Ȱ��ճ�Ա����������˳���ʼ����Ա�����������ù��캯��

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout<<"A"<<endl;
	}
};

class B
{
public:
	B()
	{
		cout<<"B"<<endl;
	}
};

class C
{
public:
	C()
	{
		cout<<"C"<<endl;
	}
private:
	A a;
	B b;
};

int main()
{
	C c;
}

6��Ĭ�Ϲ��캯����Ĭ�Ͽ������캯��
1.Ĭ�Ϲ��캯������û����ʽ�Ķ��幹�캯��ʱ��ϵͳ���Զ�����һ��Ĭ�Ϲ��캯����
	û�в���Ҳû���߼���һ����ʽ�Ķ����˹��캯��������������Ĭ�Ϲ��캯����
ʾ����
#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age):age(age)
	{
	
	}
};

int main()
{
	Person* p = new Person();//û����ʽ���幹�캯��ʱ��ȷ����������Ĺ��캯��ʱ������
}

2.Ĭ�Ͽ������캯������û����ʽ�Ķ��忽�����캯��ʱ��ϵͳ���Զ�����һ��
	�������캯��������Ա���������ֵ��ǳ������������ʽ�Ķ��忽�����캯��
	ʱ��ϵͳ����������Ĭ�Ͽ������캯���Լ�Ĭ�Ϲ��캯����
#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age):age(age)
	{
	
	}
	int getAge()
	{
		return age;
	}
};

int main()
{
	Person* p = new Person(19);
	Person* p2 = new Person(*p);//����Ĭ�Ͽ������캯��
	cout<<p->getAge()<<endl;
	cout<<p2->getAge()<<endl;
}


������������
1������������һ������ĳ�Ա���� �����빹�캯���෴
���ܣ�������������������(�������ڵĺ����Ѿ��������) ϵͳ�Զ������������� ��������������"�����ƺ�"����
������û�з���ֵ ���ֱ���������ͬ�� û�в��� ����ǰ ~
�������������в��������ܱ�����
using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age):age(age)
	{
	
	}
	int getAge()
	{
		return age;
	}
	~Person()
	{
		cout<<"����"<<endl;
	}
};

int main()
{
	Person* p = new Person(19);
	delete p;
}

��ϰ��
���һ��Book�����ͼ������������߳�Ա ���У��������������ַ���ָ��
1.���캯��Ϊ���߼�����ָ�뿪�ٿռ䲢����������������߿�����������
		Book(char* name, char* author)
2.һ������������ɾ����������������
3.��Ա����print()�������



�ġ�������
1�����������������е�this�Ǳ�const���εģ��ڳ������г�Ա�������ܱ��޸�

#include <iostream>

using namespace std;

class Person
{
private:
	int age;
public:
	Person(int age):age(age){}

	void add() const//������
	{
		cout<<++age<<endl;
	}
};

int main()
{
	Person p(20);
	p.add();
}

2������������ 
const ���� ������(ʵ��)
���� const ������(ʵ��)

ע�ⳣ���󣺣�1������������ʼ�������幹�캯���� ��2��ֻ�ܵ��ó���Ա����
���ܣ�ϣ���������г�Ա��ֵ�����޸�
ע�⣺������ֻ�ܵ��ó���������ͨ�������ȵ�����ͨ���������û����ͨ���������ó�������
#include<iostream>
using namespace std;
class Person
{
private:
	string name;
	int age;
public:
	Person(string n,int age);
	void show();
	void show()const;//����"����"  ���������
};

Person::Person(string name,int age):name(name),age(age)
{

}

void Person::show()//����
{
	cout<<"����"<<name<<" ����"<<age<<endl;
}

void Person::show()const  //���Է��ʳ����� �������޸���ֵ
{
	cout<<"����const "<<name<<" ����"<<age<<endl;
}

int main()
{
		const Person a("��ɽ����",36);
		a.show();

		Person b("��ɽ��ض�����",43);
		b.show();//�ǳ�����Ĭ�ϵ������ɵĳ�Ա����
}

3��mutable��mutable���εĳ�Ա���������ڳ��������޸�
ʾ����
#include <iostream>

using namespace std;

class Person
{
private:
	string name;
	int age;
	mutable int a;
public:
	Person(int age,string name):age(age),name(name),a(10){}
	void show()
	{
		cout<<age<<" "<<name<<endl;
	}
	void show() const
	{
		a++;
		cout<<age<<"$$$"<<name<<" "<<a<<endl;
	}
};

int main()
{
	Person p(20, "С��");
	p.show();
	const Person p2(30, "Сǿ");
	p2.show();
}


�塢��Ԫ
��Ԫ���Է���������ѹ�ϵ�����е�˽�г�Ա 
��Ԫ����Ԫ��������Ԫ��
1����Ԫ����
����ͨ��������Ϊ��Ԫ����  friend + ��������
#include<iostream>
using namespace std;
class Time
{
friend void display(Time &t);//display���Է���Time���е�˽�г�Ա
public:
	Time(int,int,int);
private:
	int hour;
	int minute;
	int second;
	
};

Time::Time(int h,int m,int s):hour(h),minute(m),second(s)
{

}

void display(Time &t)
{
	cout<<t.hour<<endl;//
}
int main()
{
	Time t1(16,14,50);
	display(t1);
}


��ϰ��
1.�и�ѧ����student ������˽�г�Ա������ �ɼ� 
2.��main����student����5��Ԫ�ز���ʼ��
3.���һ��ȫ����Ԫ���� �Ƚ�����ѧ���ĳɼ��ĸߵ� compare
4.�����߷ֺ���ͷֵ�ѧ��




2����Ԫ��
friend + ������

ʾ����
#include <iostream>
#include <string>

using namespace std;

class Teacher;
class Student
{
friend class Teacher;
private:
	string name;
	int score;
public:
	Student(string name, int score):
		name(name),
		score(score)
	{}
};

class Teacher
{
public:
	void look(Student& s)
	{
		cout<<s.name<<" "<<s.score<<endl;
	}
};

int main()
{
	Teacher t;
	Student s("С��",19);
	t.look(s);
}

��Ԫ��
1����Ԫ�ǵ����  ��ѱ��˵����ѣ�����û���㵱����
2����Ԫ���ܴ���	 ���ѵ����Ѳ�������
3����Ԫ���ܼ̳�	 �ְֵ����Ѳ����Լ�������

��ϰ��
1.�и�ѧ����student ����˽�г�Ա������ �ɼ� ��  student ���캯���Գ�Ա��ֵ
2.���һ����Ԫ��teacher 
3.teacher���а���˽�г�Ա���� student s[5]  ���캯��������Ԫ�ظ�ֵ
4.teacher���ѧ�������������  ���г�Ա���� sort() ����
5.teacher������ɼ���Ӧ�ȼ� >=90 �� 80-89 ��  70-79�� 60-69����  <60������  ���к���show()



ע�⣺��Ԫ�ƻ���ķ�װ���ԣ����ã�
				
����c++���쳣����

�쳣��Ϊ3���֣����(try) �׳�(throw) ��׽(catch)
��ʽ��
try 
{
	��������
}
catch(�쳣��������� ������)
{
	�����쳣��������;
}
����1��
#include<iostream>
using namespace std;

int mydiv(int a,int b)
{
	if(b==0)
	{
		cout<<"throw....."<<endl;
		throw b;//�׳��쳣
	}
	return a/b;
}
int main()  
{
	int a=10;
	int b=0;

	try
	{
		int result = mydiv(10,0);
		cout<<result<<endl;
	}
	catch(int e)
	{
		cout<<"catch int "<<e<<endl;
	}
}

����2����׽���쳣
#include <iostream>

using namespace std;

class ExceptA
{
public:
	void show()
	{
		cout<<"�쳣A"<<endl;
	}
};

class ExceptB
{
public:
	void show()
	{
		cout<<"�쳣B"<<endl;
	}
};

int div(int a, int b)
{
	if(b == 0)
	{
		ExceptA e;
		throw e;
	}
	return a/b;
}

double div(double a, double b)
{
	if(b == 0)
	{
		ExceptB e;
		throw e;
	}
	return a/b;
}

int main()
{
	try
	{
		div(1.0, 0.0);//�����׳�ExceptB
		div(1, 0);//�����׳�ExceptA
	}
	catch(ExceptA e)
	{
		e.show();	
	}
	catch(ExceptB e)
	{
		e.show();
	}
	catch(...)//��׽ʣ����쳣
	{
		cout<<"other e"<<endl;	
	}
}

Ӧ���е��쳣���
int main()
{
	do
	{
		if()
		{
			cout<<"�쳣1"<<endl;
			break;
		}

		if()
		{
			cout<<"�쳣2"<<endl;
			break;
		}
	}while(false);	//do-while�Ĵ�����Ϊ�˸�break�ṩ���л���
	return 0;
}

��ϰ���������������� a��b��c (������)
���������ܳ� 
ֻ��a+b>c b+c>a a+c>b ���ܹ��������� �����쳣���� �Բ����������������� 
	���������Ϣ �������


�ߡ���������
inline���εĺ����������ǳ�Ա������������ȫ�ֺ�����
������������������������ڵ��ô�չ����ʡȥ��ȴ�������Ŀ�����ֻ�������߼��ǳ�
	�򵥵ĺ�����
���������������������ļ���ʵ�֡�

�ˡ�c++�о�̬��Ա
1����̬��Ա����
1.���������� ��̬��Ա����ֻ�洢һ�ݹ����ж���ʹ��
2.���������ⵥ����ʼ�� ����ֻ��ȫ�ֽ��� ���򲻻����ռ� ���뱨��
#include<iostream>
using namespace std;
class Stu
{
public:
	static int num;//������̬��Ա����
};

int Stu::num = 10;//Ĭ��ֵΪ0
//int Stu::num=89;//��ʼ��
int main()
{
	cout<<Stu::num<<endl;
	//����
	Stu s;
	cout<<s.num<<endl;
}

2����̬��Ա����
û��thisָ�룬���Ծ�̬��Ա�������ܷ��ʱ����еķǾ�̬��Ա����̬����ֻ��
	���þ�̬��Ա

#include<iostream>
using namespace std;
class Stu
{
public:
	int age;
	static int num;//������̬��Ա����
	static int get_num()
	{
		cout<<age<<endl;//���� age����ͨ��Ա�����������ھ�̬��Ա������ʹ��
		return num;//��̬��Ա��������ʹ�þ�̬��Ա����
	}
};

int Stu::num=89;
int main()
{
	cout<<Stu::get_num()<<endl;	
	//����
	Stu s;
	cout<<s.get_num()<<endl;
}

�š�����ģʽ 
������Ķ���Ҳ��ʵ��������ÿ������������һ��ʵ����
1��Ŀ�ģ�Ϊ�˱�֤���ʵ������ֻ��һ��
2��ʵ�ַ���
1.˽�й��캯���Ϳ������캯��   ��������ⲿ��������
2.��̬��Ա����������ָ��  ����ʵ����(new)����
3.��̬��ָ��     �ھ�̬��Ա������ʵ��ֻ����һ��������߼�




ʮ�����������
��������ص�Ŀ�ģ�Ϊ���ô��뿴������������
1������
1.���أ�����������¸����µĺ��壬������ڲ������������ͳ�Ա������һ����
2.���ط���������һ������������ĺ��� ����Ҫִ�б����ص������ʱ ϵͳ���Զ����øú���
3.�����������ʽ��
	�������� operator ���������(�β��б�)
4.��������صĲ������������������������������Ϳ����Զ���
5.�����������ֵ���������������
6.�����û���������������Ķ����ܽ���������Ĳ���

ע�⣺���Խ����������ض����ȫ�ֵģ�������ȫ�ֺ����У��������˽�г�Ա�����㣻�����б��б������������

ʾ��1��
#include<iostream>
using namespace std;
class Person
{
private:
	int age;
public:
	Person(int a)
	{
		age = a;
	}

	bool operator==(const Person &s);	//==����������������� һ����this һ���ǲ���
};

bool Person::operator==(const Person &s)
{
	//��������������У�this�����������ֵ
	if(this->age==s.age)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main()
{
	Person p1(20);//p1==p2
	Person p2(20);
	if(p1==p2)//p1.operator(p2)
	{
		cout<<"the age is equal!"<<endl;
	}
	else 
	{
		cout<<"not equal"<<endl;
	}
}

ʾ��2�������Զ���

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	int age;
	string name;
public:
	Person(int age, string name):age(age),name(name)
	{}

	bool operator==(const Person& p)
	{
		cout<<this<<endl;
		return this->age==p.age;
	}

	bool operator==(int a)
	{
		return age==a;
	}
};

int main()
{
	Person p1(1, "С��");
	Person p2(1, "Сǿ");
	cout>>p1;
	if(p1 == 20)
	{
		cout<<"hehe"<<endl;
	}
	return 0;
}

ʾ��3������ȫ�������

class Person
{
friend ostream& operator<<(ostream& c, const Person& p);
private:
    int age;
public:
    Person(int age):age(age){}
};

int main()
{
    Person p(10);
    cout<<p;
    return 0;
}
//����cout��<<  ����cin��>>ʱֻ��ʹ��ȫ������
//ȫ������  �����б��뺬��������
ostream& operator<<(ostream& c, const Person& p)
{
    c<<p.age;
    return c;
}


2����ֵ��������أ�C++���ÿ����Ĭ�����ظ�ֵ�������Ĭ�ϵ��߼��ǳ�Ա���������ֵ(ǳ����)

�������غ�Ĭ�ϸ�ֵ�������ͬ���͵Ĳ��������ܸ��ǵ�Ĭ�ϵĸ�ֵ�����

C++Ĭ�ϴ��ڵĺ���
Ĭ�Ϲ��캯��
Ĭ�Ͽ������캯��
Ĭ����������
Ĭ��=����  
Ĭ��&����

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(){}
	Person(string name):name(name)
	{}

	Person& operator=(string name)
	{
		this->name = name;
		return *this;
	}

	Person& operator=(int age)
	{
		this->age = age;
		return *this;
	}

	void show()
	{
		cout<<name<<" "<<age<<endl;
	}
};

int main()
{
	Person p1("С��");
	p1 = 19;
	p1 = "Сǿ";
	p1.show();
	Person p2 = p1;//�ȼ���Person p2(p1);  ���ÿ������캯�����͸�ֵ�����һ���ϵ��û��
}

3��++ -- ���������
Ĭ�������Ϊǰ׺��ʽ operator++()    ǰ׺

��׺��ʽ��Ҫ���һ��int���Ͳ��������������壬������������ǰ׺�ͺ�׺��ʽ  operator++(int a)  ��׺

ʾ����ǰ׺�ͺ�׺������
int main()
{
	int a = 10;
	//++a = 20;//ǰ׺��ʽ���ʽ�Ľ���Ǳ���a����
	a++ = 20;//������󣬺�׺��ʽ����ֵ��a��1֮ǰ��һ����ʱ�ı�����������Ϊ��ֵ
	cout<<a<<endl;
	return 0;
}

ʾ����
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Person
{
private:
	int age;
	string name;
public:
	Person(){}
	Person(int age, string name):age(age),name(name)
	{}

	Person& operator++()
	{
		age++;
		return *this;
	}

	Person operator++(int a)//����û���κ�ʵ�����壬�����Ǹ��߱���������һ����׺������
	{
		Person p = *this;
		age++;
		return p;
	}

	void show()
	{
		cout<<name<<" "<<age<<endl;
	}
};
int main()
{
	Person p(10, "С��");
	(++p).show();
	(p++).show();
	p.show();
	return 0;
}
��C++ primer��û��plus

