

��ϰ��

���ģʽ֮����ģʽ 

1.����ģʽ��������Ŀ��

���ã���֤��һ�������һ��ʵ�������ṩ��һ����������ȫ�ַ��ʵ�

Ŀ�ģ�Ϊ�˱�֤���ʵ������ֻ��һ��

��Ҫ�����һ��ȫ��ʹ�õ��� Ƶ���Ĵ���������

�ؼ��� ���캯���Ϳ�������˽�л�

2��ʵ�ַ���

	1.˽�й��캯���Ϳ������캯��   ��������ⲿ��������
	2.��̬��ָ��     �ھ�̬��Ա������ʵ��ֻ����һ��������߼�
	3.��̬��Ա����������ָ��  ����ʵ����(new)����


��������أ���������������������������������⣬����ֵ��������
int operator+(int a)
Person
{};
Person p;
Person p1;
p + p1;
���������ֵ���������

��ֵ��������أ�����Ĭ�ϵĸ�ֵ���������
p = p1;
Person p(p1);
person p2 = p1;

ȡ��ַ�����Ҳ����Ĭ�ϵ�
++ -- ����
ǰ׺��û�в���
��׺������һ��int���Ͳ���

�������ص������:5�� sizeof()  ?:  .  ::  .* ��Աָ�������

�̳�
class Person{};
class Student : public Person
{};
�̳�Ȩ�ޣ��Ӹ���̳еĳ�Ա�����е�������Ȩ��



����Ŀ1�����Ҫ����C++�е����������

����Ŀ2���������ǰ++�ͺ�++�������


����Ŀ3��������������������ʲô�����Ҫ����һ�£�

����Ŀ4��C++�ķ���Ȩ�޶���ʲô����������


����Ŀ5���ڼ̳�ʱ���̳з�ʽ����ʲôӰ�죿


/*****************************

		�¿�
		
******************************/


һ���麯��

c++�ж����Ա����ʱ ǰ�߼ӹؼ���virtual ������������麯��  virtual void eat();

�Ա����أ�overload ��ͬһ�����У���������ͬ�������б�ͬ������ֵ����ν��������

1����д�� override  �����ж���͸������麯��ͬ����
ͬ����ֵ���ͣ�ͬ�����б�ĺ���������д��
ʾ��1��   
#include <iostream>
#include <string>

using namespace std;

class A{
    public:
        void show(){
            cout << "A show()..." << endl;
        }
};
class B:public A{
    public:
        void show(){
                cout << "B show()..." << endl;

        }
};
int main(){
     A a;
     a.show();
     B b;
     b.show(); //���ȵ����Լ��ĺ���
	return 0;
}
	
2.�麯��������
c++�ж����Ա����ʱǰ�߼ӹؼ���virtual��������������麯����

virtual void eat(){
cout << �� eating ...�� << endl; 
}
��дʾ����
#include <iostream>
#include <string>

using namespace std;

class A{
    public:
      virtual void show(){
            cout << "A show()..." << endl;
        }
};
class B:public A{
    public:
        void show(){
                cout << "B show()..." << endl;
				}
};
int main(){
     A a;
     a.show();
     B b;
     b.show();
	return 0;
}
���䣺
////////////////////////////////////////////
�����п��Բ���д�����е��麯��������ǿ��Ҫ��
��ε�����д�ĺ���������ʹ�ã�����ָ��ָ���������

����Ŀ��C++��д�����ص�����


ʾ����
#include <iostream>
#include <string>

using namespace std;

class A{
    public:
       virtual   void show(){
            cout << "A show()..." << endl;
        }
};
class B:public A{
    public:
        void show(){
                cout << "B show()..." << endl;
        }
};
int main(){
    A  *p = new B;
    p->show();
    return 0;
}

3.����ָ��ָ������������麯��ʵ�ֶ�̬

����* ָ�� = new ����();
Shape* shape = new Rectangle();
ʹ�����ַ�ʽ�������ָ�����ָ���Լ����������������

���ʹ������ָ�뷽ʽ�������ø�����ͨ����������ú���ʱ��Ȼ�Ǹ���ķ�����
///*****//
�����ø�����麯�������ú���ʱ���õ���������д֮��ĺ�����

��̬: 1./���������д������virtual������
2./�ø���ָ�������ָ������ÿ��Է�����������д�ķ�����Ϊ�˽��߼����ࣩ�����������д���
       3./������Ե���������д�ķ���

**********�������͵�ָ�� ����ָ���������͵Ķ���*******��Ҫ 
1.��ͼ��ʾ
2. ˵������˳��  1��/��������û���麯��
				 2��/����У�ȥ����������û����д���о�ִ��������д�ķ�����
				 3��/�������û����д����ȥִ�и�����麯����

���䣺
///////////////////
һ���飬���ȫ��

���⣺
��������ڻ����б�����Ϊvirtual�����������������У�A��
A. �����麯��
B��ֻ�б���������ʱ�����麯��
C. ֻ�б���������Ϊvirtualʱ�����麯��
D�� �������麯��



��ϰ��
1.�������Developer�����麯��develop()
2.���������Manito�Ͳ�����SmallBird�̳�Developer����дdevelop()
3.���幫˾��Company  1)�����Ա������Ƹrecruit()�������һ�������߶��󣬷���ֵΪDeveloper*
					 2)����Company��ĳ�Ա����work(Developer* )������Developer��develop()
					 
5.main�д���Company���󣬵���recruit()���һ��Developer��Ȼ�����work()����Developer����



�������ؼ̳�

c++֧�ִӶ������������һ������
��ʽ��
class ������:�̳з�ʽ ������1,�̳з�ʽ ������2
{
	
};

ʾ����
1.Baby�࣬˽�г�Աname��age������sleep()��eat()
2.Student�࣬˽�г�Աscore������study()
3.Xiaoming��̳�Baby��Student��
  �鿴�����������
   
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



��ϰ�����һ��Բ��Circle(�뾶)��һ��������Table(�߶Ⱥ���ɫ)  �����һ��Բ����RoundTable 
	����ǰ���������� 
Ҫ�����һ��Բ���ĸ߶� ��ɫ  �����



���������

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
public:      //B  �б��붨�幹�캯���������д�ͻ���ø���Ĭ���޲ι��캯�����ͻᱨ��
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
		cout<<C::money<<endl;//D������������money��Ա����Ҫͨ������::����ָ����Ա
	}
};

int main()
{
	D d(1);//  A B A C D 
	d.show();
}

//
��ʼ����ʱ��������ȸ�����  

////////////////////����Ƶĺ����ǲ��������������ģ��й�ͬ�Ļ���A 
/////////////���԰��� ����� �������� 

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
	D(int money):A(money),B(money),C(money)//����ײ��������ĳ�ʼ���б��ж��������г�ʼ��
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


��ϰ�����һ�������Base   ������protected����: ����������     ��Ա����eat();
      �����������쵼��Leader ����:˽������ְ��duty�Ͳ���department            ��Ա����lead();
      ����Base������������ʦ��Engineer ������˽������ְ��major רҵprofessional  ��Ա����develop();
      Ȼ����Leader���Engineer�����������ι���ʦ��Boss



С��ϰ��

//����ࣺ

	��virtual�����Ļ��� ʹ���ڼ̳м�ӹ�ͬ����ʱ ֻ�Թ�ͬ�Ļ����ʼ��һ��
	
//�麯����

	C++���麯����Ҫ�����ǡ�����ʱ��̬�����������ṩ�麯����ʵ�֣�Ϊ�����ṩĬ�ϵĺ���ʵ�֡�
	���������д������麯��ʵ����������⻯��
	
//����ָ��ָ������������麯��ʵ�ֶ�̬��

	����* ָ�� = new ����();
	Shape* shape = new Rectangle();
	ʹ�����ַ�ʽ�������ָ�����ָ���Լ����������������
	���ʹ������ָ�뷽ʽ�������ø�����ͨ����������ú���ʱ��Ȼ�Ǹ���ķ����������ø�����麯�������ú���ʱ���õ���������д֮��ĺ�����

//��̬:

	  1.���������д������virtual������
	  2.�ø���ָ�������ָ������ÿ��Է�����������д�ķ�����Ϊ�˽��߼����ࣩ�����������д���
      3.������Ե���������д�ķ���
	     	   
�ġ����麯��

1.���麯����
	1���ڻ�����û��ʵ�� 
	2��/�������������м���ʵ��   ��Ҫ������ʵ���亯������
	3���д��麯�������൱�ڽӿ� ������ ����ֱ��ʵ����

2.��ʽ�� 
virtual ����ֵ���� ������(�β��б�) = 0 ; //�����˺����Ǵ��麯��

3.�����ࣺ�������麯������  �����������������
���䣺
////////////////
��������

4.������:�����������̳еģ����麯��������������д�ġ�

5.���崿�麯����Ŀ�� ��Ϊ�˿���ͨ���������ָ��ȥ���������������д�ĺ�����


��������ж����麯���󣬱�����������һ���麯����
������൱��һ�Ѻ���ָ�룩��
����ָ��ָ���������ʱ��ͨ�����ȥ����������������д�ĺ�����

ʾ��1��
#include <iostream>
#include <string>

using namespace std;

class Person//  1.person�ǲ���ʵ������ person* p = new person; �ᱨ�� 
{
protected:
	string name;
public:
	Person(string name):name(name)
	{}
	virtual void sleep() = 0;
};

class Xiaoming : public Person
{
public:
	Xiaoming(string name):Person(name)
	{}
	void sleep()// 2.���û����д����������ǲ���ʵ��������� Person* xm = new Xiaoming("С��");
	{
		cout<<"������"<<endl;
	}
};

int main()
{
	//3.����ָ��ָ���������  
	Person* xm = new Xiaoming("С��");
	xm->sleep();
}

//��ϰ��
����һ����������״Shape
���麯��������ܳ���int getPerimeter();
          �õ���״��string getType();
		  
		 ���������Σ�Triangle
			���ԣ��߳� a��b��c  
			
		����Բ�Σ�Circle
			���ԣ��뾶
			
		���������Σ�Square
		���ԣ��߳�a  
 


˼�������������ĵ���˳��
���������ĵ���˳��͹��캯���ĵ���˳�����෴��

ʾ��1����Ա�����͹��캯��   ��   ����ĳ�Ա�����͹��캯��  �Լ�   ����������˳��

���䣺�ص�
/////////////////////////////
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
    D d;
    return 0;
}

�ܽ᣺
	 1����Ա�����͹��캯����/�ȳ�Ա ����  
	 2������ĳ�Ա�����͹��캯���� �ȳ�Ա ���� 
	 3������������˳��ͬ�����˳���෴
	 
	
ʾ��2����̳еĸ�������ĳ�ʼ��˳��
 
 
#include <iostream>

using namespace std;

class A
{
public:
    A(int a)
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
    B(int a)
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
    C():A(1),B(1)
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


�ܽ᣺
���䣺
/////////////////////////////////////////

1./���۹��������������Լ̳�˳��Ϊ׼
2./��Ա������ֵʱ����������������˳�����ģ�
���ߣ����Ͳ����б��޹�


�塢����������

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
