һ�����������

4���������ص������  ?:   sizeof()   .   ::    .*��Աָ�������

��Աָ�������ʾ����

ʾ��1��
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	int age;
	string name;
public:
	Person(){}
	Person(int age, string name):age(age),name(name)
	{}

	void show()
	{
		cout<<name<<" "<<age<<endl;
	}
};

int main()
{
	int Person::* p;//��Աָ�룬��Աָ�벻�Ǽ�ָ��ĳ������ĳ�Ա����
	//��Աָ�벻һ��ָ���ĸ�����ĳ�Ա����
	p = &Person::age;//pָ��Person���age��Ա��������ָ���Ա���ѣ�����
	//֪����ָ���ĸ������

	Person p1(20, "���ʹ");
	Person p2(30, "С����");

	cout<<p1.*p<<endl;//����.*��Աָ��   ���ö���ĳ�Ա
	cout<<p2.*p<<endl;
	return 0;
}
ʾ��2��

#include <iostream>
using namespace std;

class Person
{
public:
	int age;
public:
	Person(int age):age(age){}
	void show()
	{
		cout<<age<<endl;
	}
};

int main()
{
	Person xiaoming(10);
	Person xiaohong(20);
	//ps�ǳ�Ա����ָ�룬ֻ��ָ��Person��ĳ�Ա����
	void(Person::*ps)() = &Person::show;//��ʱ����ȷ��ָ������ĸ������show����
	(xiaoming.*ps)();//ִ��xiaoming�����show����
	(xiaohong.*ps)();//ִ��xiaoihong�����show����
	//��Աָ�������һ�����������ĺ�����Ϊ�ص�����
	//��������ʱ�򣬲�֪Ҫ����������Ҫ�����ú����Ķ���
	xiaoming.show();
	xiaohong.show();

	return 0;
}


��ϰ�����һ����������Triange ���������������߳���˽�����ݳ�Ա
����һ�����������'+'  ��ʵ���������������ܳ�֮��  
ע�⣺���������ζ������


��ϰ�����һ��ѧ���� �������������ųɼ�(C++ C linux) 
	�������������'+=' ������ѧ���ɼ��ĺͻ��ܵ�һ��ѧ��������


��ϰ����Time������������������������++
1.˽�г�Աh m s
2.���غ�׺++ ��ʱ������һ��
3.show������ʾʱ��

�Ҹ棺��ҪΪ���������������������������������ֻ��Ϊ�˴��뿴�������Ӽ��

������̳� 
��װ���̳кͶ�̬���������������
�̳п������������������ã��̳�Ҳ��ʵ�ֶ�̬�ı�Ҫ�﷨

1������ ������  ���� ����
class ������:�̳з�ʽ ������1���̳з�ʽ ������2���̳з�ʽ ������3....
{
	��������ӵĳ�Ա;	
}

ʾ��1��
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string name;
public:
	void show()
	{
		cout<<name<<endl;
	}
};

class Xiaoming : public Person
{
public:
	Xiaoming(string name)
	{
		//��Ա����name�ǴӸ���Person�̳й����ģ�����name�ĸ����еķ���Ȩ����protected
		//��������Xiaoming��name�з���Ȩ�ޡ�
		//����̳и��࣬��̳и��������еĳ�Ա������˽�еĳ�Ա��ֻ��û��
		//��˽�г�Ա�ķ���Ȩ�޶���.
		this->name = name;
	}
};

int main()
{
	Xiaoming xm("С��");
	xm.show();
}

ʾ��2������ĳ�ʼ���б��п���ͨ������Ĺ��캯������ʼ������ĳ�Ա��
	���û����ʽ�ĵ��ø��๹�캯������Ĭ�ϵ��ø����޲εĹ��캯����
	���������û���޲ι��캯��������ĳ�ʼ���б��б�����ʽ�ĵ��ø�����εĹ��캯��
#include<iostream>
using namespace std;
class Person
{
protected:
	string name;
	bool gender;
public:
		void eat(const char*food)
		{
			cout<<name<<"��"<<food<<endl;
		}
		void sleep()
		{
			cout<<name<<" sleep"<<endl;
		}
		void show()
		{
			cout<<"��Һ� ����"<<(gender?"˧��":"��Ů")<<name<<" ��������ʶ��!"<<endl;
		}
		Person(const char *na,bool g):name(na),gender(g)
		{
			cout<<"person create"<<endl;
		}
};

class Teacher:public Person 
{
private:
	string course;
public:
		Teacher(const char*na,bool g,string c):Person(na,g),course(c)//na��g�ᴫ�ݸ�����Ĺ��캯��
		{
			cout<<"teacher create"<<endl;
		}
		void teach(const char *c)
		{
			cout<<name<<"��ʦ"<<"��"<<"�γ�"<<course<<endl;
		}

		void show()//�����д�˸���ĳ�Ա �������Ը���ͬ���ĳ�Ա ���������չ
		{
			cout<<"����"<<course<<"��ʦ"<<name<<" comeon(����)!"<<endl;
		}
};

int main()
{

	//Person a("���",true);
	Teacher t("doudou",false,"c++");
	
	t.eat("����");
	t.show();
	t.Person::show();//����ʹ�ø����show
} 

��ϰ����д���� 
���һ��������Vehicle ���������ݳ�Ա�����ָ���wheels,����weight 
С����car��������������� �������ݳ�Ա:������passenger_load 
������Truck��������������� ������ ������passenger_load  ������pay_load
ÿ���඼��������ݵ��������show��ʾ���еĳ�Ա


2���̳з�ʽӰ��:

public�̳�   ����̳к�ķ���Ȩ�޲���
protected�̳�  ����̳к󣬸����е�public���protected����������
private�̳�	����̳к󣬸����е�public��protected���private����������

ʾ����
#include <iostream>
#include <string>

using namespace std;

class A
{
public:
	int a;
	A(int a):a(a){}
	
	void show()
	{
		cout<<a<<endl;
	}
};

class B : protected A
{
public:
	B(int a):A(a){}
};

int main()
{
	B b(10);
	b.show();//�������  show��B����protected�ķ���Ȩ��
}

��ϰ��
�����һ��Point�� ������x��y(����)  --����
��Point��������һ��Circle�� �������ݳ�Աr(�뾶)
Circle�ඨ�庯���������
��Circle��Ϊֱ�ӻ���������һ��Cylinder��Բ���壩�� �����ӳ�Աh(��)
Cylinder��Բ���壩�ඨ�庯���������


��ϰ��
����һ����Animal
���ԣ����� ��ɫ ������
д���췽���������Ը�ֵ
ÿ������˽��Ȩ�ޣ�����ͨ��get��set������ֵ
������eat()��move()�޲�������

����һ������Sheep
����У�roar()

����һ������Tiger
����run()

����������
���������Ȱ�ɫɽ�򣬵�����ط���
���������Ȱ�ɫ��������������ط���



�����麯��
�麯����Ŀ������д
��д��Ŀ���Ƕ�̬

c++�ж����Ա����ʱ ǰ�߼ӹؼ���virtual ������������麯��  virtual void eat();


�Ա����أ�overload ��ͬһ�����л�����ȫ�ֵĺ�������������ͬ�������б�ͬ��
	����ֵ����ν�������ء��ڼ̳��и���������в��������ع�ϵ
1����д��override ����̳и��࣬�����ж����麯����
	�����ж���͸������麯��ͬ����ͬ����ֵ���ͣ�ͬ�����б�ĺ���������д��
	��д������Ӳ���virtual�����ԣ���������д��ĺ�����Ȼ���麯��
ʾ����
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	//�麯�������������д
	virtual void eat()
	{
		cout<<"Person eat"<<endl;
	}
};

class Student : public Person
{
public:
	//��д����ġ�eat����
	void eat()//�����е��ǲ����麯���� ���麯��
	{
		cout<<"student eat"<<endl;
	}
};

��̬: ���������д������virtual�������ø���ָ�������ָ������ÿ��Է�����
		������д�ĺ�����ͨ������ͬ���͵Ķ�����д�����ʵ�ָ����߼��Ĵ��ݡ�

1.�����ָ������ÿ���ָ���������
2.�����ָ������ÿ��Ե�����������д�ĺ���

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	//�麯�������������д
	virtual void eat()
	{
		cout<<"Person eat"<<endl;
	}

	void sleep()
	{
		cout<<"Person sleep"<<endl;
	}
};

class Student : public Person
{
public:
	//��д����ġ�eat����
	void eat()
	{
		cout<<"student eat"<<endl;
	}

	void sleep()
	//sleep����������д�ĺ�������Ϊ�����е�sleep�����麯����sleepֻ��һ��
	//�͸����������ĺ�������W
	{
		cout<<"student sleep"<<endl;
	}
};

int main()
{
	Student xiaoming;
	Person& p1 = xiaoming;//��������ָ���������
	p1.eat();//�������������д��eat����
	p1.sleep();//��Ϊ������sleepû�ж�����麯��������û����д�����Ե��ø����sleep

	Person* p2 = &xiaoming;//ָ����÷�ͬ����
	p2->eat();
	p2->sleep();
}

��ϰ��
1.�������Developer�����麯��develop()
2.���������Manito�Ͳ�����SmallBird�̳�Developer����дdevelop()
3.���幫˾��Company�������Ա������Ƹrecruit()�������һ�������߶��󣬷���ֵΪDeveloper*
4.����Company��ĳ�Ա����work(Developer* )������Developer��develop()
5.main�д���Company���󣬵���recruit()���һ��Developer��Ȼ�����work()����Developer����





�ġ����ؼ̳�
c++֧�ִӶ������������һ������
��ʽ��
class ������:�̳з�ʽ ������1,�̳з�ʽ ������2
{
	
};

ʾ����
1.Baby�࣬˽�г�Աname��age������sleep()��eat()
2.Student�࣬˽�г�Աscore������study()
3.Xiaoming��̳�Baby��Student��

#include <iostream>
#include <string>

using namespace std;

class Baby
{
private:
	string name;
	int age;
public:
	Baby(string name, int age):
		name(name),
		age(age)
	{
		cout<<"baby create"<<endl;
	}
	virtual void sleep()
	{
		cout<<"baby "<<name<<" sleep"<<endl;
	}
	virtual void eat()
	{
		cout<<"baby "<<name<<" eat"<<endl;
	}
};


class Student
{
private:
	int score;
public:
	Student(int score):score(score)
	{
		cout<<"student create"<<endl;
	}
	virtual void study()
	{
		cout<<"good good study"<<endl;
	}
};

class Xiaoming : public Baby, public Student
{
public:
	//��ʼ�������˳��Ӧ�úͼ̳е�˳�򱣳�һ��
	//��ʼ����Ա������˳��Ӧ�úͳ�Ա����������˳�򱣳�һ��
	Xiaoming(string name, int age, int score):
		Baby(name, age),
		Student(score)
	{
		cout<<"xiaoming create"<<endl;
	}
	void eat()
	{
		cout<<"�Բ���"<<endl;
	}
	void sleep()
	{
		cout<<"˯����"<<endl;
	}
	void study()
	{
		cout<<"ѧ����ȥ"<<endl;
	}
};

int main()
{
	Xiaoming* xm = new Xiaoming("С��",18,1);
	Baby* bb = xm;
	Student* s = xm;

	bb->eat();
	bb->sleep();
	//bb->study();//����ָ�벻�ܵ��ø�����û�������ĳ�Ա
	
	//s->eat();
	//s->sleep();
	s->study();
}

˼�������������ĵ���˳��
���������ĵ���˳��͹��캯���ĵ���˳�����෴��
ʾ��1����Ա�����͹��캯���͸���ĳ�Ա�����͹��캯���Լ�����������˳��
#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout<<"A create"<<endl;
    }
    
    ~A()
    {
        cout<<"A delete"<<endl;
    }
};

class B
{
private:
    A a;
public:
    B()
    {
        cout<<"B create"<<endl;
    }
    
    ~B()
    {
        cout<<"B delete"<<endl;
    }
};

class C
{
public:
    C()
    {
        cout<<"C create"<<endl;
    }
    ~C()
    {
        cout<<"C delete"<<endl;
    }
};

class D : public B
{
private:
    C c;
public:
    D()
    {
        cout<<"D create"<<endl;
    }
    ~D()
    {
        cout<<"D delete"<<endl;
    }
};

int main()
{
	//�ȳ�ʼ�����࣬�ٳ�ʼ�����ࣻ������ڲ��ȳ�ʼ����Ա�������ٵ��ù��캯����
    D d;
    return 0;
}

ʾ��2����̳еĸ�������ĳ�ʼ��˳��
#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout<<"A create"<<endl;
    }
    
    ~A()
    {
        cout<<"A delete"<<endl;
    }
};

class B
{
public:
    B()
    {
        cout<<"B create"<<endl;
    }
    
    ~B()
    {
        cout<<"B delete"<<endl;
    }
};

class C : public B, public A
{
public:
    C()
    {
        cout<<"C create"<<endl;
    }
    ~C()
    {
        cout<<"C delete"<<endl;
    }
};

int main()
{
    C c;
    return 0;
}



��ϰ�����һ��Բ��Circle(�뾶)��һ��������Table(�߶Ⱥ���ɫ)  
	�����һ��Բ����RoundTable ����ǰ���������� 
Ҫ�����һ��Բ���ĸ߶� �������ɫ




�塢�����
��virtual�����Ļ��� ʹ���ڼ̳м�ӹ�ͬ����ʱ ֻ�Թ�ͬ�Ļ����ʼ��һ��
��ʽ��class ��������:virtual �̳з�ʽ ������
���ּ̳г�����̳�
ֻ����������ʱ�����������

ʾ��1��
#include <iostream>
#include <string>

using namespace std;

class A
{
protected:
	int money;
public:
	A(int money):money(money)
	{
		cout<<"a create"<<endl;
	}
};

class B : public A
{
public:
	B(int money):A(money)
	{
		cout<<"b create"<<endl;
	}
};

class C : public A
{
public:
	C(int money):A(money)
	{
		cout<<"c create"<<endl;
	}
};

class D : public B, public C
{
public:
	D(int money):B(money-1),C(money+1)
	{
		cout<<"d create"<<endl;
	}

	void show()
	{
		cout<<money<<endl;//D������������money��Ա����Ҫͨ������::����ָ����Ա
	}
};

int main()
{
	D d(1);
	d.show();
}

��̳к������������Ĳ����Ƶ��߼��������ǲ��������Ҫ��̳е�����ġ�

ʾ��2����D����ֻ��һ��money  ʹ����̳У��ǹ����Ļ���ֻ����ʼ��һ��

#include <iostream>
#include <string>

using namespace std;

class A
{
protected:
	int money;
public:
	A()
	{
		cout<<"a create"<<endl;
	}
};

class B : virtual public A
{
public:
	B()
	{
		cout<<"b create"<<endl;
	}
};

class C : virtual public A
{
public:
	C()
	{
		cout<<"c create"<<endl;
	}
};

class D : public B, public C
{
public:
	D(int money)
	{
		cout<<"d create"<<endl;
	}

	void show()
	{
		cout<<money<<endl;
	}
};

int main()
{
	D d(1);
	d.show();
}

ʾ��3���������Ҫ����ײ��������ĳ�ʼ���б�����������г�ʼ��

#include <iostream>
#include <string>

using namespace std;

class A
{
protected:
	int money;
public:
	A(int money):money(money)
	{
		cout<<"a create"<<endl;
	}
};

class B : virtual public A
{
public:
	B(int money):A(money)
	{
		cout<<"b create"<<endl;
	}
};

class C : virtual public A
{
public:
	C(int money):A(money)
	{
		cout<<"c create"<<endl;
	}
};

class D : public B, public C
{
public:
	D(int money):A(money),B(money+1),C(money-1)
	//����ײ��������ĳ�ʼ���б��ж��������г�ʼ��
	{
		cout<<"d create"<<endl;
	}

	void show()
	{
		cout<<money<<endl;
	}
};

int main()
{
	D d(1);
	d.show();
}

��ϰ�����һ�������Base ������protected�������������估 ��Ա����eat()
�����������쵼��Leader ����˽������ְ��Ͳ��ż� ����lead()
����Base������������ʦ��Engineer ����˽������ְ�� רҵ�� ����develop()
Ȼ����Leader���Engineer�����������ι���ʦ��Boss




�������麯��
���麯����Ŀ�ģ������е�û���߼��ĺ�������Ҫʵ��
���麯�����ڻ�����û��ʵ�� �������������м���ʵ��  
�д��麯�������൱�ڽӿ� ����ֱ��ʵ����
��Ҫ������ʵ���亯������
��ʽ�� 
virtual ����ֵ���� ������(�β��б�)=0  //�����˺���ʱ���麯��
���麯�����ܱ�ʵ�֣�ֻ�ܱ���д

�����ࣺ�������麯������  �����������������

����������������̳еģ����麯��������������д�ġ�
���崿�麯����Ŀ����Ϊ�˿���ͨ���������ָ��ȥ���������������д�ĺ�����

��������ж����麯���󣬱�����������һ���麯��������൱��һ�Ѻ���ָ�룩��
����ָ��ָ���������ʱ��ͨ�����ȥ��������������
��д�ĺ������������������﷨��û�пɲ����Ŀռ䡣

ʾ��1��
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string name;
public:
	Person(string name):name(name)
	{}
	virtual void sleep()=0;//��Ϊ���˴��麯��������Person�ǳ����࣬����ʵ��������
};

class Xiaoming : public Person
{
public:
	Xiaoming(string name):Person(name)
	{}
	void sleep()
	{
		cout<<"������"<<endl;
	}
};

int main()
{
	Person* xm = new Xiaoming("С��");
	xm->sleep();
}

��ϰ������һ����������״Shape
���麯��������ܳ���int getPerimeter();
          �õ���״��string getType();
���������Σ�Triangle
   ���ԣ��߳� a��b��c   
����Բ�Σ�Circle
   ���ԣ��뾶
���������Σ�Square
  ���ԣ��߳�a  
 

���Ա���ʲôҲ�ɲ��ˣ����Ե�ʹ�����벻�����ԵĻ���
����Ϸ����(����)---->cocos2dx(����)----->lua js c++(ѡ��һ������֧�ֵ�����)

�ߡ�����������
ʹ�ø���ָ��ָ��������󣬲�ͨ������ָ��ɾ���������ʱ��
	�޷����������������������Ҫ��������������������������

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal()
	{
		cout<<"Animal create"<<endl;
	}

	virtual ~Animal()
	{
		cout<<"Animal delete"<<endl;
	}
};

class Tiger : public Animal
{
public:
	Tiger()
	{
		cout<<"Tiger create"<<endl;
	}
	~Tiger()
	{
		cout<<"Tiger delete"<<endl;
	}
};

int main()
{
	Animal* p = new Tiger();

	delete p;
}


��ϰ��
���ĳС�͹�˾����Ա����ϵͳ

��1����

��Employee�ࣺ
��Ա������˽�У������id������name���Ա�gender����������birthday��ְλposition�ͻ�������basicSalary��
��������ʹ���Զ����Date�����ڣ��ࣻ
������캯����ȱʡ(�޲�)���캯�����������Ĺ��캯������Ĭ�ϲ����Ĺ��캯����
���к������㹤��virtual float getSalary()


��Date�ࣺ
��Ա��������year����month����date
��Ա������SetYear(int year)��SetMonth(int month)��SetDay(int day)��GetYear()��GetMonth()��GetDay()��
������캯����ȱʡ���캯�����������Ĺ��캯������Ĭ�ϲ����Ĺ��캯����

����Employee����������Ա��Salasman�࣬Salasman��������������ݳ�Ա�����۶�sales����ɱ���commrate��

����Salasman�����������۾���Salamanager�ࡣSalasmanager����������ݳ�Ա��ְ����jobSalary��

��2���¹��ʼ���취��
һ��Ա����н=��������
����Ա����н=��������+���۶�*�����  
���۾�����н=��������+ְ����+���۶�*�����

��3�������������£��轫���¹���ת��Ϊ��ͬ�ĳ�Ա������

�ٸ�����Ա��Ϣ��¼�루�����������ʵȣ���

�ڸ�����Ա��Ϣ����ʾ�������¹��ʣ���name ����

���ö������鱣�����������Ա����

�ܿ����޸���Ա�Ļ�����Ϣ���磺������ְλ�ȣ�

�ݿ���ͨ����Ż�����������Ա��ѯ��

�ˡ�ģ�� ��
���Խ����͵����������д���

static_cast<>()
dynamic_cast<>()
// ���������͵�ָ��ת�����������͵�ָ�룬
//ʹ��dynamic_castת��ָ�����ͣ������б������麯��

ʾ����
class Employee
{
public:
	virtual void work(){}
};

class Salasman : public Employee
{
public:
	void work(){}
};

Employee* e = new Employee();
Salasman* s = dynamic_cast<Salasman*>(e);
if(s == NULL)
{
    cout<<"ת��ʧ��"<<endl;
}
else
{
    cout<<"�ɹ�"<<endl;
}




