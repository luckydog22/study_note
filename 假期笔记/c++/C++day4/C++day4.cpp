
һ��ģ�� ��
���Խ����͵����������д���

static_cast<>()
dynamic_cast<>()

ʾ����
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

1������ģ�壺ֻ�����ں�������ͬ ����������ͬ ���Ͳ�ͬ�����
ʹ�ã�����һ��ͨ�ú��� �亯������ֵ���ͺ��β����Ͳ������ƶ� ����һ����������
ע�⣺ģ���������ʵ�ֱ�����ͬһ���ļ��У�����ģ��ֻ��.h�ļ�

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
	show<int>(a);//<>�д������Ͳ��� �����е�����T��������int
	show<double>(d);//�����е�����T�������� double
}

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




ʾ��3�������Ͳ���
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
	Person<string> xiaoming(11);	
	xiaoming.eat("ţ��");
	Person<string>* p = new Person<string>(10);
  p->eat("����");
  delete p;
}

ע�⣺��ģ��û��cpp�ļ������еĺ���ʵ�ֶ�д��ͷ�ļ��У�����ģ�����Ͳ�����
	���ֻ�Ǹ�ֵ�����ƺ�ȡ��ַ��

��ϰ����ɾ�Ĳ�
1.����������Link
2.˽���ڲ��ṹ��Node{T data, Node* pNext, Node* pFront}
3.˽�г�Աָ��pHead  pTail
4.���к���add(T data)��β�����Ԫ��
5.���к�������[] ���� ָ��λ�õ�����,������ͨ��[]�޸Ķ�Ӧλ�õ�����
6.���к���erase(index)ɾ��indexλ�õ�Ԫ��
7.���к���erase(int start, T data)��startλ�ÿ�ʼ����ɾ��������data��Ԫ�أ�
		ɾ����������������Ԫ�ء�
8.���к���size()��������ĳ���


����explicit
explicit������ֹ�ɹ��캯���������ʽת����

1����ʽת���������õ���ʵ�������õĹ��캯�������˴��β����͵��������͵�
		һ����ʽת����
ע�⣺��ʽת���ھ��󲿷�������ǲ��õġ�


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
};

int main()
{
    Person p = 10;//Person p(10);  ��ʽת��
    Person p2 = "farsight";//Person p1("farsight");
    return 0;
}

ʾ��1.1
class Person
{
public:
    Person()
    {}
    Person(int a)
    {}
};

void fun(Person p)
{
    
}

int main()
{
    fun(1);//��ʽת����ʹ�ò���1 ������һ��Person����
��
ʾ��2��
#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
    int a = 10;
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
������һ�������ɣ��ο�C++ string�������캯����������ʽ����ת����
����Ҫ��������Ϊexplicit��


����STL����׼ģ���  standard  template  library
������˳��(����)����   �������� ��ֵ��key-value
���е���������������

1��˳��������ʹ�÷�ʽ����һ�£�ʵ��ԭ��һ�������ݶ����ݵĲ���ѡ���ʺϵ�����
vector ֧�ֿ����������  ����ԭ�� �Ƽ�  O��1��
list	 ֧�ֿ��ٲ���/ɾ��  ����ԭ��		O��N��
deque	 ˫�˶���  һ��һ�ε�����������

1.���ò���
ʾ��1�����ò���
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(rand()%100);//��β������
    }
    
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v[0] = 521;
    for(int i = 0;i < v.size();i++)//size()�������е����ݸ���
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
ʾ��2������������
������ʹ���ͱ���ÿ��ֻ�ܱ���1���߼�1������ֵ��0~10֮��
class A
{
private:
    int a;
public:
    A():a(0)
    {}    
    void operator++()
    {
        if(a == 10)
        {
            return;
        }
        a++;
    }   
    void operator--()
    {
        if(a == 0)
        {
            return;
        }
        a--;
    }
};

int main()
{
	A s;
	++s;
	--s;
	return 0;	
}

C++�еĵ������Ƕ�ָ��ķ�װ���������ṩ�ض��ĺ����õ����߶�ָ������ض��İ�ȫ�Ĳ���

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);//��β�����Ԫ��
    }
    //�����е�ֵΪż����Ԫ�ر��0
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        if(*iter%2 == 0)
            *iter = 0;
    }
    
    //begin��������ͷԪ�� ��end������βԪ�أ�������Ч��Ԫ�ر�ʾ��������
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;//*�����ʵ�����ָ���Ԫ��
    }
    
    return 0;
}

ʾ��3.1������������ɾ��
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> v;
    for(int i = 0;i < 100;i++)
    {
        v.push_back(i);
    }
    
    for(list<int>::iterator iter = v.begin();iter != v.end();)
    {
        if(*iter%2 == 0)
        {
            iter = v.erase(iter);//erase����ֵ��ָ��ɾ���ڵ����һ���ڵ�ĵ�����
        }
        else
        {
            iter++;
        }
    }
    
    for(list<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;
    }
    
    return 0;
}
ʾ��3.2�����ҵ�����ɾ��
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    														//ǰ�պ����䣺����begin�����㲻����end
    vector<int>::iterator iter = find(v.begin(), v.end(), 3);
    
    v.erase(iter);
    
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;
    }
    
    return 0;
}

3.3�����ҵ�����ɾ���Զ�������
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int num;
    char name;
    Node(int num, char name):num(num),name(name)
    {}
    
    bool operator==(const Node& other) const
    {
        if(num == other.num && name == other.name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void show()
    {
        cout<<num<<" "<<name<<endl;
    }
};

int main()
{   
    vector<Node> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(Node(i,'a'+i));
    }
    
    vector<Node>::iterator iter = find(v.begin(), v.end(), Node(30,'e'));
    
    if(iter != v.end())//û���ҵ�����end()
        v.erase(iter);
    
    for(vector<Node>::iterator iter = v.begin();iter != v.end();iter++)
    {
        iter->show();
    }
    
    return 0;
}
2.��������
2.1.������������(���������еı�׼������) 
*iter ���ص�������ָ������� 
iter->mem ��iter���н����� 
++iter ���� 
iter++ 
�C-iter �Լ� 
iter�C-
iter1==iter2 �Ƚ������������Ƿ���� 
iter1��=iter2 
iter +n��iter-n��iter1+=iter2��iter1-=iter2 
ע���κθı�������С�Ĳ������п���ʹ�õ�����ʧЧ
2.2.begin()��end()��Ա��֧������������ 
c.begin() ��c.end() ����һ����������ָ���һ�������һ������һ����Ա 
c.rbegin() ����һ�������������ָ������c�����һ��Ԫ�� 
c.rend() ����һ�������������ָ������c�ĵ�һ��Ԫ�ص�ǰ��һ��λ��
2.3.�����������Ԫ�� 
c.push_back(t) ֧���������� 
c.push_front(t) ֻ֧��list��deque���� 
c.insert(p,t)��c.insert(p,n,t)��c.insert(p,b,e) ֧����������
2.4.������С�Ĳ�����֧������������ 
c.size() ����c�е�Ԫ�ظ�������������Ϊc::size_type 
c.max_size() ����c���������ɵ�������������Ϊ��c::size_type 
c.empty() 
c.resize(n) �ı������Ĵ�С
2.5.����Ԫ�� 
c.back() ��������c�е����һ��Ԫ�ص����� 
c.front() ��������c�еĵ�һ��Ԫ�ص������� 
c[n] �±���� ֻ������vector��deque ֻ�ܲ����Ѵ��ڵ�Ԫ�� 
c.at[n] �±���� ֻ������vector��deque ֻ�ܲ����Ѵ��ڵ�Ԫ��
2.6.ɾ������ 
c.erase(p) ɾ��������pָ���Ԫ�� 
c.erase(b,e) 
c.clear() ɾ������c�е�����Ԫ�� 
c.pop_back() ɾ������c�е����һ��Ԫ�� 
c.pop_front() ɾ������c�еĵ�һ��Ԫ�أ�ֻ������list��deque
2.7.��ֵ��swap 
c1=c2 ɾ��c1�е�����Ԫ�أ��ٰ�c2�е�����Ԫ�ظ�ֵ��c1c 
c1.swap(c2) �������� 
c.assgin(b,e) ����c�е�Ԫ�أ�������������Χ�ڵ�Ԫ�ظ�ֵ��c 
c.assgin(n,t) ������c��������Ϊ�洢n��ֵΪt��Ԫ��

3.queue��stack��priority_queue 
��������������Ҫһ����������(vector list deque)����ͬ���������������������Ҳ��һ�� 
queue���Ƚ��ȳ������ݽṹ����Ҫ�ڶ�ͷ�Ͷ�βͬʱ����Ԫ�أ���������Թ�����������list��Ĭ�ϣ���deque�� 
stack���Ƚ���������ݽṹ��ֻ��Ҫ�ڶ�β����Ԫ�ؼ��ɣ���ɹ������������� 
priority_queue:�������ڲ���Ԫ��ʱ�������ȼ�����Ԫ�أ�����λ�ò��̶���
		������Ҫ����������ʵĹ��ܣ�����һ��ֻ������vector��deque�ϣ�
ʾ��1��
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    //vector<int> v;
    //stack<int, vector<int> > s(v);//ģ�����1 stack��ŵ��������� ģ�����2 stack���ڵ���������
    stack<int> s;//ʹ��Ĭ������
		//����ʵ��ԭ��ο���һ���ջ��ϰ������ϰ�еĶ�̬���黻��vector
    for(int i = 0;i < 10;i++)
    {
        s.push(i);
    }
    
    while(!s.empty())
    {
        cout<<s.top()<<endl;//���ջ��Ԫ�أ�����Ԫ�ز���ջ
        s.pop();//վ��Ԫ�س�ջ
    }
    return 0;
}
ʾ��2�����ȶ���
���ȶ����ֽж�
���������Ҽ�ֵ������ֵ����Сֵ��
C++�����ȶ����Ҽ���ֵ
#include <queue>

using namespace std;

class Person
{
public:
    Person(int age):age(age){}
    bool operator<(const Person& other) const
    {
        return age>other.age;
    }
    void show() const
    {
        cout<<age<<endl;
    }
private:
    int age;
};

int main()
{
    priority_queue<Person, vector<Person> > que;
    que.push(Person(12));
    que.push(Person(2));
    que.push(Person(66));
    que.push(Person(5));
    while(!que.empty())
    {
        que.top().show();
        que.pop();
    }
    return 0;
}

4.ջ����Ĳ��� 
s.empty() �ж�ջ�Ƿ�Ϊ�� 
s.size() ����ջ��Ԫ�ظ��� 
s.pop() ɾ��ջ��Ԫ�� 
s.top() ����ջ��Ԫ�أ����ǲ�ɾ�� 
s.push(item) ��ջ��ѹ���µ�Ԫ��
5.���к����ȼ����� 
q.empty()��q.size()��q.top()�� 
q.front()��q.back() ֻ�����ڶ��� 
q.top() ֻ���������ȼ�����


2����������
1. pair<T1, T2>  pairҲ��һ��ģ�����͡���(key)ֵ(value)��
	�������ݳ�Ա�ǹ��еģ��ֱ�����Ϊfirst��second
	��map�����У���firstΪkey����secondΪvelue
ʾ����

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	pair<string, int> p("hehe", 10);
	cout<<p.first<<" "<<p.second<<endl;
}
	
2. map<key, value> �����������Լ�ֵ��key-value��ʽ�������  �����
O��logN��
map�Ǵ��pair��������map�е�ÿ���ڵ㶼��һ��pair

������

���Ҷ�������ÿ���ڵ�������ӱ���С���Һ��ӱ�����

ƽ����Ҷ�����(AVL��)����������������Ȳ����1

�����������Ϊ������AVL���Ĳ���Ч�ʣ�����Ϊ������AVL���Ĳ���Ч�ʣ�����һ����ƽ���ԣ����ٲ�������ʱ����ת����
1.�����нڵ��ǳɺ�Ļ��ߺڵ�
2.���ڵ�һ���Ǻڵ�
3.������������ڵ�����һ��
4.�Ӹ���Ҷ�ӵ�����·���ڽڵ�������������

2.1 ����Ͳ�ѯ����
ʾ����
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	//map��������ͬ��
	m.insert(pair<string, int>("С��",18));//��������  ��������ظ���������ظ��޷�����
	m["Сǿ"] = 20;//�������ݣ����key�Ѿ����ھ��޸�����

	cout<<m["С��"]<<endl;
	cout<<m["Сǿ"]<<endl;
}

2.2 ����������
ʾ����

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	m.insert(pair<string, int>("С��",18));
	m["Сǿ"] = 20;
	
	for(map<string, int>::iterator iter = m.begin();iter != m.end();iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
}

2.3 ����
ʾ����
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	m.insert(pair<string, int>("С��",18));
	m["Сǿ"] = 20;
	
	cout<<m.count("С��")<<endl;//count���Ҹ�key���ֵĴ���������ֵ������0����1 0��ʾû�и�key��1��ʾ�ж�����������1
	cout<<m.count("С��")<<endl;

	map<string, int>::iterator iter = m.find("С��");//find���ظ�key�ĵ���������
	if(iter != m.end())
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
}

2.4 ɾ��
m.erase(k)   //��m��ɾ��keyΪk��Ԫ�ء�
m.erase(p)   //��m��ɾ��������pָ����Ԫ��

2.5 �Զ���key����
��������� <

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person
{
public:
    Person(const char* name):name(name)
    {
        
    }
    bool operator<(const Person& other) const
    {
        return name < other.name;
    }
    string getName() const
    {
        return name;
    }
private:
    string name;
};

int main()
{
    map<Person, int> m;
    m.insert(pair<Person, int>("jack", 18));
    m.insert(pair<Person, int>("rose", 1));
    m.insert(pair<Person, int>("tom", 2));
    m.insert(pair<Person, int>("jerry", 3));
    
    for(map<Person, int>::iterator iter = m.begin();iter != m.end();iter++)
    {
    		//������ jack  jerry  rose tom
        cout<<iter->first.getName()<<" "<<iter->second<<endl;
    }
    
    return 0;
}

2.6 �Զ�������������ӵ���������
#ifndef LINK
#define LINK

template<typename T>
class Link
{
private:
    struct Node
    {
        Node()
        {}
        Node(T data):
            data(data),
            pNext(NULL),
            pFront(NULL)
        {}
        T data;
        Node* pNext;
        Node* pFront;
    };
public:
    class iterator
    {
    friend class Link;
    private:
        Node* pNode;
    public:  
        bool operator!=(const iterator& other)
        {
            return pNode != other.pNode;
        }
        void operator++(int a)
        {
            pNode = pNode->pNext;
        }
        T* operator->()
        {
            return &(pNode->data);
        }
        T& operator*()
        {
            return pNode->data;
        }
    };
    iterator begin()
    {
        iterator i;
        i.pNode = pHead->pNext;
        return i;
    }
    
    iterator end()
    {
        iterator i;
        i.pNode = NULL;
        return i;
    }
    Link():mSize(0)
    {
        Node* pNode = new Node();
        pHead = pNode;
        pTail = pNode;
    }
    
    Link& add(T data)
    {
        Node* pNode = new Node(data);
        pTail->pNext = pNode;
        pNode->pFront = pTail;
        pTail = pNode;
        mSize++;
        return *this;
    }
    
    int size()
    {
        return mSize;
    }
    
    T& operator[](int index)
    {
        Node* pNode = find(index);
        return pNode->data;
    }
    
    Link& erase(int index)
    {
         Node* pNode = find(index);
         deleteNode(pNode);
         return *this;
    }
    
    Link& erase(int start, const T& data)
    {
        Node* pNode = find(start);
        for(int i = start;i < mSize;i++)
        {
            if(pNode->data == data)//����ʹ��ģ���ǲ���ѧ��
            {
                deleteNode(pNode);
                mSize--;
                break;
            }
            pNode = pNode->pNext;
        }
        return *this;
    }
private:
    Node* find(int index)
    {
        Node* pNode = pHead->pNext;
        for(int i = 0;i < index;i++)
        {
            pNode = pNode->pNext;
        }
        return pNode;
    }
    void deleteNode(Node* pNode)
    {
        if(pNode == pTail)
        {
            pTail = pTail->pFront;
            pTail->pNext = NULL;
            delete pNode;
        }
        else
        {
            pNode->pFront->pNext = pNode->pNext;
            pNode->pNext->pFront = pNode->pFront;
            delete pNode;
        }
    }
private:
    Node* pHead;
    Node* pTail;
    int mSize;
};

#endif // LINK

