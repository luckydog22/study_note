��ϰ��

//����ࣺ
	��virtual�����Ļ��� ʹ���ڼ̳м�ӹ�ͬ����ʱ ֻ�Թ�ͬ�Ļ����ʼ��һ��
	
//�麯����
	C++���麯����Ҫ�����ǡ�����ʱ��̬�����������ṩ�麯����ʵ�֣�Ϊ�����ṩĬ�ϵĺ���ʵ�֡����������д������麯��ʵ����������⻯��
	
//����ָ��ָ������������麯��ʵ�ֶ�̬��

	����* ָ�� = new ����();
	Shape* shape = new Rectangle();
	ʹ�����ַ�ʽ�������ָ�����ָ���Լ����������������
	���ʹ������ָ�뷽ʽ�������ø�����ͨ����������ú���ʱ��Ȼ�Ǹ���ķ����������ø�����麯�������ú���ʱ���õ���������д֮��ĺ�����

//��̬:
	  1.���������д������virtual������
	  2.�ø���ָ�������ָ������ÿ��Է�����������д�ķ�����Ϊ�˽��߼����ࣩ�����������д���
      3.������Ե���������д�ķ���
	  
1.���麯����
	1���ڻ�����û��ʵ�� 
	2���������������м���ʵ��   ��Ҫ������ʵ���亯������
	3���д��麯�������൱�ڽӿ� ����ֱ��ʵ����

2.��ʽ�� 
virtual ����ֵ���� ������(�β��б�) =0  //�����˺����Ǵ��麯��

3.�����ࣺ�������麯������  �����������������

4.����������������̳еģ����麯��������������д�ġ�

5.���崿�麯����Ŀ����Ϊ�˿���ͨ���������ָ��ȥ���������������д�ĺ�����


��������ж����麯���󣬱�����������һ���麯��������൱��һ�Ѻ���ָ�룩������ָ��ָ���������ʱ��ͨ�����ȥ��������������
��д�ĺ�����



����Ŀ1���ڼ̳�ʱ���̳з�ʽ����ʲôӰ�죿

����public�̳�ʱ��������̳е������г�Ա����Ȩ�޲���
����protected�̳�ʱ��������̳е���public��Ա��Ϊprotected�����಻��
����private�̳�ʱ�������༯�ɵ������г�Ա��Ϊprivate

����Ŀ2������������������

���ø���ָ��ָ���������ʱ���ͷŸ������ʱ�������������������������Զ��常�����������ʱ��Ҫ��virtual��ʹ���Ϊ����������


/*********************************************
			
			�¿�

**********************************************/


һ��ģ�� ��

���Խ����͵����������д���


1������ģ�壺 ֻ�����ں�������ͬ ����������ͬ ���Ͳ�ͬ�����
   ʹ�ã�����һ��ͨ�ú��� �亯������ֵ���ͺ��β����Ͳ������ƶ� ����һ����������
   
 *****  ע�⣺ģ���������ʵ�ֱ�����ͬһ���ļ��У�����ģ��ֻ��.h�ļ�
 
 ���䣺
 //////////////////
 ��Ϊģ���T���������������������ʧЧ��


 
int div(int a,int b)
{
	return a/b;
}
float div(float a,float b)
{
	return a/b;
}
int main()
{
	div<float>(3,2);
	
}

ʾ��1��
#include<iostream>
using namespace std;

template<typename T> 	//<>���Ͳ����б�  ���Ͳ���T�����ں���������λ�õ���������ʹ��
void show(T data)
{
	cout<<data<<endl;
}

int main()
{
	double d=1.23;
	int a=90;
	show<int>(a);//<>�д������Ͳ���
	show<double>(d);
}

���䣺
//////////////////
ʹ��ģ��ʱ����ƽ���ĵ��ã����� <����>

ʾ��2��
#include<iostream>
using namespace std;

template<typename T>
T show(T data)
{
	return data+90;
}

int main()
{
	double d=1.23;
	int a=90;
	cout<<show<int>(a)<<endl;
	cout<<show<double>(d)<<endl;
}

��ϰ�����������ĳ�������������ֵ���ؽ��

//������ģ�� �ؼ��֣�template  <typename T>�ǲ���������
template<typename T,typename U>
T div(T a, U b)
{

    return a/b;
}

int main()
{
    cout<<div<int,float>(10,3.5f)<<endl; //<>�д������Ͳ���

    return 0;
}



ʾ��2�������Ͳ���
#include <iostream>
#include <string>

using namespace std;

template<typename T,typename U>
T div(T a, T b, U c)
{
	cout<<c<<endl;
	return a/b;
}

int main()
{
	cout<<div<double, string>(10, 3, "hello farsight")<<endl;
}

2����ģ��

//����ģ�����͵ı�����һ�����new delete ��ֵ ���� +

ʾ����
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Person
{
public:
    Person(int age):age(age)
    {
        
    }
		void eat(T food)
		{
			cout<<food<<age<<endl;
		}
private:
    int age;
};

int main()
{
	Person<string> xiaoming(2);	
	xiaoming.eat("ţ��");
	
	Person<string>* p = new Person<string>(10);
  p->eat("����");
  delete p;
}

ע�⣺��ģ��û��cpp�ļ������еĺ���ʵ�ֶ�д��ͷ�ļ��У�����ģ�����Ͳ�����ֻ���Ǹ�ֵ�����ƺ�ȡ��ַ��

��ϰ����ɾ�Ĳ�

1.����ģ��������Link
2.˽���ڲ��ṹ��Node{T data, Node* pNext, Node* pFront}
3.˽�г�Աָ��pHead  pTail size 
4.���к���add(T data)��β�����Ԫ��



5.���к�������operator[] ���� ָ��λ�õ�����,������ͨ��[]�޸Ķ�Ӧλ�õ�����

T& operator[](int index)
{
	
}
cout<<link[2]<<endl;
link[2] = 12;

6.���к���erase(index)ɾ��indexλ�õ�Ԫ��

7.���к���erase(int start, T data)��startλ�ÿ�ʼ����ɾ��������data��Ԫ��

8.���к���size()��������ĳ���

#include <iostream>

using namespace std;

template<typename T>
class Link
{
 private:
    //���ṹ��
    struct Node
    {
        //ָ����һ�� ��һ������ָ��
        T data;
        Node* pNext;
        Node* pFront;
        //���캯��
        Node(){}
        Node(T data):data(data),pNext(NULL),pFront(NULL)
        {
        }

    };
  //ͷβָ��
    Node* pHead;
    Node* pTail;
    int mSize;
 public:
    Link()
    {
        //������ͷ���
        Node* p = new Node;
        //ͷβָ��ָ���ͷ���
        pHead = p;
        pTail = p;
        mSize = 0;
    }
    //����һ�����
    void add(T data)
    {
        Node* pNode = new Node(data);
        //1.βָ��ָ��Ľ���next  ָ���½��Ľ��
        pTail->pNext = pNode;
        //2.�½�����front ָ��β�ڵ�
        pNode->pFront = pTail;
        //3.βָ��ָ���½��Ľ��
        pTail = pNode;
        //4.����++
        mSize++;
    }

    //ɾ��һ�����
    void erase(int index)
    {
        //ѭ�� �ҵ�������λ��Ϊindex��������
    Node* pNode = pHead->pNext;
    for(int i =1; i< index; i++)
    {
        pNode = pNode->pNext;
    }
    if(pNode == pTail)
    {
       //ɾ����Ϊβ�ڵ�ʱ
        pTail = pTail->pFront;
        pTail->pNext = NULL;

    }else
    {
        //ɾ���м���ʱ
        pNode->pFront->pNext = pNode->pNext;
        pNode->pNext->pFront = pNode->pFront;
    }
    delete pNode;
    mSize--;
}
    //���������[]
    T& operator[](int index)
    {
        Node* pNode = pHead->pNext;
        for(int i = 1; i< index; i++ )
            pNode = pNode->pNext;
        return pNode->data;
    }
    //��startλ�ÿ�ʼ���ң�ɾ������Ϊdata�Ľ��
     void erase(int start, T data)
     {
         Node* pNode = pHead->pNext;
         for(int i =1; i<start; i++)
             pNode= pNode->pNext;
         for(int i = start; i< mSize; i++)
         {
             if(pNode->data == data)
             {
                 erase(i);
             }
             //else

                 pNode = pNode->pNext;

         }

      }

    int getSize()
    {
        return mSize;
    }

};


int main()
{
   Link<int> l;
   for(int i = 0 ; i < 10; i++)
       l.add(i);
   cout<<l.getSize()<<endl;

    //��ȡ��4��λ�õ�����
   cout<<"������λ�ã�"<<l[3]<<endl;

    cout<<"------------------"<<endl;

   //�޸ĵ�3��λ�õ����� ��ֵΪ100
    l[3] = 100;

   for(int i = 1 ; i< l.getSize();i++)
       cout<<l[i]<<endl;

    cout<<"------------------"<<endl;

   l.erase(1,5);

   for(int i = 1 ; i<l.getSize();i++)
       cout<<l[i]<<endl;

    return 0;
}




����explicit
explicit������ֹ�ɹ��캯���������ʽת����

1����ʽת���������õ���ʵ�������õĹ��캯�������˴��β����͵��������͵�һ����ʽת����

ʾ��1��
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    int age;
    string name;
public:
    Person()
    {
        cout<<"no arg"<<endl;
    }
    
    Person(int age):age(age)
    {
        cout<<"int arg"<<endl;
    }
    
    Person(const char* name):name(name)
    {
        cout<<"string arg"<<endl;
    }
	void show()
	{
		cout<<age<<endl;
	}
};

void fun(Person p)
{
	p.show();
}

int main()
{
    Person p = 10;   //Person p(10);  ��ʽת��
    Person p2 = "farsight";//Person p1("farsight");
	
	///////��Ժ�ӵĴ����fun����  �����������ã�fun(10); ������д��̫��  ���� �����������
    return 0;
}

ʾ��2��
#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
    int a ;
	string s;
public:
    Test(int a, string s):a(a)
    {
        cout<<a<<endl;
    }

};
int main()
{
    Test a = 10;//������ʽת��
    return 0;
}

ʾ��3��
#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
    int a = 10;
public:
    Test(int a, string s = "farsight"):a(a)
    {
        cout<<a<<endl;
    }

};
int main()
{
    Test a = 10;//��ʽת��
    return 0;
}

*******ͨ��һ���������ܵ��ù��캯����ʱ�򣬾��ܴٷ���ʽת��

2��explicit
ʾ����
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    int age;
    string name;
public:
    Person()
    {
        cout<<"no arg"<<endl;
    }
    
    explicit Person(int age):age(age)
    {
        cout<<"int arg"<<endl;
    }
    
    explicit Person(const char* name):name(name)
    {
        cout<<"string arg"<<endl;
    }
};

int main()
{
    Person p = 10;//Person p(10);
    Person p2 = "farsight";//Person p1("farsight");
    return 0;
}
explicit���ŵ��ǿ��Ա��ⲻ��ʱ�˵����ͱ任��ȱ���ޡ�
������Ϊexplicit�Ĺ��캯��ͨ������non-explicit�ֵܸ��ܻ�ӭ��
��Ϊ���ǽ�ֹ������ִ�з�Ԥ�ڣ�����Ҳ����������������ת����
������һ�������������캯����������ʽ����ת��������Ҫ��������Ϊexplicit��
