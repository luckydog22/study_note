��ϰ��
����ģ�� template<typename T, typename Q> ��������
������<int, float>()
��ģ��	template<typename T, typename Q> ������
����<int, string> ������				new ����<int, string>()

explicit�����ι��캯������ֹ��ʽת��
��ʽת���������캯������ֻ����һ��������ʱ�򣬿���ͨ��������ʼ������

-----------------------------------------------------------------------------------------------

��дC++�����ʱ��ᷢ��STL��һ������Ķ����������˴�������ʹ����ĸ����ʴ����ߣ������˳���Գ�ĸ�����
����һ��������������ᷢ��Ҫ���Լ�дһ���������У������������ʱ�򣬼�Ҫ��ʱ�仹Ҫ������ôȥά����
�����ָ�밡���ڴ湻�����ð����������⣬��û�п���������ȵ�һϵ�е������������ȥ��������ǱȽ�ͷ�۵ġ�
���������ĳ��ֽ������һ�����⣬������Щ���ݽṹ����װ����һ���ֻ࣬��Ҫ����ͷ�ļ������ǾͿ������ɵ�Ӧ�ã�
������ô���ӣ�����ָ��Ҳ����װ���˵������������������㣬�����Ի������������ǵı�̣����ڳ���Ա��˵����һ��������

 C++�е������������˳��洢�ṹ���͡������洢�ṹ����
 ǰ�߰���vector��list��deque�ȣ�
 ���߰���set��map��multiset��multimap�ȡ�
 ����Ҫ�洢��Ԫ�����ڱ�������Ϳ���ȷ��������ʹ���������洢�����򣬾���Ҫ�õ��������ˡ�

***********************************************************************************************
1.vector
    �����洢�ṹ��ÿ��Ԫ�����ڴ����������ģ�֧�ָ�Ч��������ʺ���β�˲���/ɾ��������������λ�õĲ���/ɾ������Ч�ʵ��£�
	�൱��һ�����飬���������������Ϊ���ڴ�ռ����չ��vector֧�ֲ�ָ��vector��С�Ĵ洢�������������չ��Ҫ����Ա�Լ�д��[2]
2.deque
    �����洢�ṹ������ÿ��Ԫ�����ڴ���Ҳ�������ģ�������vector����֮ͬ�����ڣ�deque�ṩ����������ṹ��
	��һ����ȫ������vector������ʵ����������һ��ά����������λ��ַ��������deque���˾���vector�����й����⣬��֧�ָ�Ч����/β�˲���/ɾ��������
    deque   ˫�˶��� 
    deque���ڹ����Ϻϲ���vector��list��
    �ŵ㣺 (1) ������ʷ��㣬��֧��[ ]������
           (2) ���ڲ�����Ľ��в����ɾ������
           (3) �������˽���push��pop
    ȱ�㣺ռ���ڴ��	
3.list
    �������洢�ṹ������˫����ṹ��ÿ��Ԫ��ά��һ��ǰ��ͺ���ָ�룬���֧��ǰ��/���������֧�ָ�Ч���������/ɾ��������
	���������Ч�ʵ��£���������Ҫ����ά��ָ�룬����Ҳ�Ƚϴ�
	���Բ����������ڴ��С����Ľ�����Ӻ�ɾ��������ʹ�õ��Ƿ��������ڴ�ռ���д洢��
   �ŵ㣺 (1) ��ʹ�������ڴ���ɶ�̬������
               (2) ���ڲ�����Ľ��в����ɾ������
               (3) �������˽���push��pop
   ȱ�㣺 (1) ���ܽ����ڲ���������ʣ�����֧��[ ]��������vector.at()
               (2) �����verctorռ���ڴ��
   ʹ������
             ��1���������Ҫ��Ч���漴��ȡ�������ں������ɾ����Ч�ʣ�ʹ��vector
             ��2���������Ҫ�����Ĳ����ɾ�����������������ȡ����Ӧʹ��list
             ��3���������Ҫ�����ȡ�����ҹ����������ݵĲ����ɾ������Ӧʹ��deque


�����⣺vector VS. list VS. deque��
    a������Ҫ������ʲ�������ѡ��vector��
    b�����Ѿ�֪����Ҫ�洢Ԫ�ص���Ŀ����ѡ��vector��
    c������Ҫ�������/ɾ���������������ˣ�����ѡ��list
    d��ֻ����Ҫ���׶˽��в���/ɾ��������ʱ�򣬻�Ҫ����������Ч�ʣ���ѡ��deque������ѡ��vector��
    e��������Ҫ�������/ɾ��������Ҫ������ʣ�����Ҫ��vector��list����������-deque��
    f����Ҫ�洢���Ǵ��͸��������ʱ��listҪ����vector����Ȼ��ʱ��Ҳ������vector���洢ָ������ָ�룬
       ͬ����ȡ�ýϸߵ�Ч�ʣ�����ָ���ά���ǳ����׳�����˲��Ƽ�ʹ�á�

������һ��list��vector������

��1��vectorΪ�洢�Ķ������һ�������ĵ�ַ�ռ䣬�������Ч�ʺܸߡ����ǲ����ɾ����Ҫ�ƶ����������ݣ�Ч�ʽϵ͡����䵱vector�д洢
�Ķ���ϴ󣬻��߹��캯�����ӣ����ڶ����е�Ԫ�ؽ��п�����ʱ���ִ�п������캯����
��2��list�еĶ�������ɢ�ģ����������Ҫ����������������Ч�ʱ�vector�͡�������list�в���Ԫ�أ���������β���룬Ч�ʺܸߣ�ֻ��Ҫ�ı�Ԫ�ص�ָ�롣

��3��vector�ǵ���ģ���list��˫��ģ�

��4�������е�iterator��ʹ�ú���ͷ��ˣ���������list��ͬ�����ĵ�������ʹ�ú󻹿��Լ����ã��������еģ�

������� deque��vector������

��1�����˶��ܹ����ٲ����ɾ��Ԫ�ء�vectorֻ����β�˽��С�

��2��deque��Ԫ�ش�ȡ�͵�������������΢��һЩ����Ϊdeque���ڲ��ṹ���һ����ӹ��̡�

��3�������������������ָ�룬������һ��ָ�롣����Ҫ�ڲ�ͬ������֮����ת��

��4����Ϊdequeʹ�ò�ֹһ���ڴ棨��vector����ʹ��һ�������ڴ棩������deque��max_size()���ܸ���

��5����֧�ֶ��������ڴ����ʱ���Ŀ��ơ�

ע�⣺�ڳ�����β���˵������ط������ɾ��Ԫ�أ������ᵼ��ָ��dequeԪ�ص��κ�pointers��references��iteratorsʧЧ��������deque���ڴ��ط�������vector����Ϊ���ڲ��ṹ��ʾ����Ҫ��������Ԫ�ء�

6��deque���ڴ����鲻�ٱ�ʹ��ʱ���ᱻ�ͷš�deque���ڴ��С�ǿ������ġ��������ǲ�����ô���Լ���ô����ʵ���汾���塣


�������壺��vector�洢�Զ��������ʱ���Զ�������������㡿
    a���пɹ����õ��޲ι��캯����Ĭ�ϵĻ��Զ���ģ���

    b���п��õĿ�����ֵ������Ĭ�ϵĻ��Զ���ģ�

����������������iterator��

     a��vector��deque�ĵ�����֧���������㣬list�ĵ�����ֻ�ܽ���++/--��������֧����ͨ���������㡣

     b .�����е�iterator��ʹ�ú���ͷ��ˣ���������list��ͬ�����ĵ�������ʹ�ú󻹿��Լ����ã��������еģ�
	

*****************************************************************************************

		/***********************

				�¿�

		*********************/
	
		
		
һ��STL����׼ģ���  standard  template  library
������˳��(����)����   �������� ��ֵ��key-value
���е���������������

1��˳��������ʹ�÷�ʽ����һ�£�ʵ��ԭ��һ�������ݶ����ݵĲ���ѡ���ʺϵ�����
vector ֧�ֿ����������  ����ԭ�� �Ƽ�  O��1��
list	֧�ֿ��ٲ���/ɾ��  ����ԭ��		O��N��
deque	˫�˶���

1.���ò���
ʾ��1�����ò���:�������� ͨ������push_back����
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
        v.push_back(rand()%100);
    }
    //������[]�������֧��ͨ��[]���ʶ�Ӧλ�õ�Ԫ��
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}

ʾ��2������Ԫ��  ������[]�������֧��ͨ��[]���ʶ�Ӧλ�õ�Ԫ��,���޸�ֵ

	int main()
{
    srand(time(0));
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(rand()%100);
    }
    
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
	cout<<endl;
	
	//�޸ĵ�0��λ�õ�ֵΪ521����������ط��ص�ֵ������
	
    v[0] = 521;
	
	//�����������ֵ���鿴�޸����
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}

��ϰ����100����������2��ֵ�����������У�������������3��ֵ����Ϊ0��������Ľ��

 for(int i = 0 ; i < 100;i++ )
   {
       if(i%2 == 0)
       v.push_back(i);
   }
   for(int i = 0 ; i <v.size();i++ )
   {
       if(v[i]%3 == 0)
       v[i] = 0;
   }
   
   

ʾ��3������������

C++�еĵ������Ƕ�ָ��ķ�װ���������ṩ�ض��ĺ����õ����߶�ָ�����
�ض��İ�ȫ�Ĳ���

1����ε��õ����� vector<int>::iterator iter  i
2����һ��Ԫ�ص�λ��ָ��ͨ������v.begin()���� i=0;
3���������������������һ����ЧԪ�ص�λ�� ͨ��v.end()����  i<10
4��*iter��ͨ��*�������ʵ�����ָ���Ԫ��

ע�⣺begin��������ͷԪ�� ��end������βԪ�أ�������Ч��Ԫ�ر�ʾ��������

ʾ����
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
   
     
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;//*�����ʵ�����ָ���Ԫ��
    }
    
    return 0;
}

��ϰ����100����������2����������Ϊ0��������Ľ��



//���䣺
v.insert();  //����ͷ�巨
(1)   (v.begin��20)  
(2)  ��v.begin,v.begin+3,v.begin+5��  //��˼�����������Ķ��� ���뵽v.begin֮ǰ
//����1��//������λ��
//��������//�����Ǵ�����Ԫ��  Ҳ�����Ǵ���������


//����������ɾ�����ۼ�

//���ҵ�����ɾ���������Ҫ�ж�
1������ͷ�ļ� #include <algorithm>
2�����ҷ���Ϊ��vector<int>::iterator iter = find(v.begin(), v.end(), 3);
3��ע�⣺find����ֻ��ɾ���ҵ��ĵ�һ��Ԫ��

ʾ��3.1������������ɾ��

ʾ����ɾ������ v.erase(iter);

ע�⣺��������ָ��Ķ���ɾ���󣬵���������Ч�ˣ�erase�����᷵��һ���µĵ�������
		ָ��ɾ��Ԫ�ص���һ��Ԫ��

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    
    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    
    //��������ָ��Ķ���ɾ���󣬵���������Ч�ˣ�erase�����᷵��һ���µĵ�������ָ��ɾ��Ԫ�ص���һ��Ԫ��
    for(vector<int>::iterator iter = v.begin();iter != v.end();)
    {
        if(*iter%2 == 0)
            iter = v.erase(iter);//ʹ���µĵ�������������  
		                         //erase����ֵ��ָ��ɾ���ڵ����һ���ڵ�ĵ�����
        else 
            iter++;
    }
    
    //begin��������ͷԪ�� ��end������βԪ�أ�������Ч��Ԫ�ر�ʾ��������
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;//*�����ʵ�����ָ���Ԫ��
    }
    
    return 0;
}

//��ϰ����100����������2��ֵ�����������У�������������3��ֵɾ����������Ľ�����õ���������


ʾ��3.2�����ҵ�����ɾ��

1������ͷ�ļ� #include <algorithm>
2�����ҷ���Ϊ��vector<int>::iterator iter = find(v.begin(), v.end(), 3);
3��ע�⣺find����ֻ��ɾ���ҵ��ĵ�һ��Ԫ��


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
    
    vector<int>::iterator iter = find(v.begin(), v.end(), 3);
    
    v.erase(iter);
    
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;
    }
    
    return 0;
}

˼�������������û��Ҫ���ҵ�Ԫ���أ�

�����жϣ�
int main()
{
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    
    vector<int>::iterator iter = find(v.begin(), v.end(), 3);
    
	�����жϣ�˵��û�ҵ���β֮ǰ���ҵ���ƥ���Ԫ�أ�
				����ҵ���endλ�ã�˵��������û��ƥ���Ԫ��
	if(iter != v.end())
	{
		v.erase(iter);
	}
       
    for(vector<int>::iterator iter = v.begin();iter != v.end();iter++)
    {
        cout<<*iter<<endl;
    }
    
    return 0;
}

3.3�����ҵ�����ɾ���Զ�������

ʾ����
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Person
{
 public:
    int age;
    string name;
    Person(int age,string name):age(age),name(name)
    {

    }
    bool operator==(const Person& o)
    {
        if(this->age == o.age && this->name == o.name)
            return true;
        else
            return false;
    }
    void show()
    {
        cout<<age<<"  "<<name<<endl;
    }

};

int main()
{
    vector<Person> v;
    v.push_back(Person(12,"aaa"));
    v.push_back(Person(13,"bbb"));
    v.push_back(Person(14,"ccc"));
    v.push_back(Person(15,"ddd"));

    vector<Person>::iterator iter = find(v.begin(),v.end(),Person(12,"aaa"));

    if(iter!= v.end())
        v.erase(iter);


    for(vector<Person>::iterator iter = v.begin();iter != v.end();iter++)
        iter->show();
    return 0;
}

��ϰ������ṹ��Node����Ա���� int num;char name;
					2)���캯������������ʼ��
					3����Ա���� show���������num��name
					
		��������vectorΪNode���ͣ�ѭ���������ݣ�numΪѭ������i��ֵ��
		nameΪ��ĸa~z
		������������û��Node(1,'e')���о�ɾ��
		�����������������������
		
		
		
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct teacher
{
    int age;
    char name;

    teacher(int age,char name):age(age),name(name)
    {


    }
    void show()
    {
        cout<<age<<"  ";
        cout<<name<<endl;
    }
    bool operator ==(const teacher& other)
    {
        if(this->age == other.age && this->name == other.name)
            return true;
        return false;
    }

};

int main()
{
    vector<teacher> v;
    for(       int i =0;i<26;i++  )
    {
        v.push_back(teacher(i,'a'+i));
    }

    for(   vector<teacher>::iterator iter = v.begin();iter!=v.end();iter++  )
    {
       iter->show();
    }
    cout<<endl;
     v.clear();
  //    vector<teacher>::iterator iter = find(v.begin(),v.end(),teacher(1,'b'));
   //   if(iter!=v.end())


      for(   vector<teacher>::iterator iter = v.begin();iter!=v.end();iter++  )
      {
         iter->show();
      }
}






2.��������
2.1.������������(���������еı�׼������) 
*iter ���ص�������ָ������� 
2.2.begin()��end()��Ա��֧������������ 
c.begin() ��c.end() ����һ����������ָ���һ�������һ������һ����Ա 
2.3.�����������Ԫ�� 
c.push_back(t) ֧���������� 
c.push_front(t) ֻ֧��list��deque���� 
c.insert(p,t)��c.insert(p,n,t)��c.insert(p,b,e) ֧����������
2.4.������С�Ĳ�����֧������������ 
c.size() ����c�е�Ԫ�ظ�������������Ϊc::size_type 
c.max_size() ����c���������ɵ�������������Ϊ��c::size_type 
c.empty() 
2.5.����Ԫ�� 
c.back() ��������c�е����һ��Ԫ�ص����� 
c.front() ��������c�еĵ�һ��Ԫ�ص������� 
c[n] �±���� ֻ������vector��deque ֻ�ܲ����Ѵ��ڵ�Ԫ�� 
c.at() �±���� ֻ������vector��deque ֻ�ܲ����Ѵ��ڵ�Ԫ��
2.6.ɾ������ 
c.erase(p) ɾ��������pָ���Ԫ�� 
c.erase(b,e) 
c.clear() ɾ������c�е�����Ԫ�� 
c.back();��ȡ���һ��Ԫ��
c.pop_back() ɾ������c�е����һ��Ԫ�� 
c.pop_front() ɾ������c�еĵ�һ��Ԫ�أ�ֻ������list��deque




2����������
1. pair<T1, T2>  pairҲ��һ��ģ�����͡���(key)ֵ(value)��
	�������ݳ�Ա�ǹ��еģ��ֱ�����Ϊfirst��second
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


map����map<key, value>  ͷ�ļ���#include <map>
	
2. map<key, value> ͨ�����������������ݣ��Լ�ֵ��key-value��ʽ�������  �����

2.1 ����Ͳ�ѯ����

ʾ��1����������
ע�⣺��������  ��������ظ���������ظ��޷�����	 


2.2 ����������
ʾ����

#include <iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    pair<string,int> p("11",12);
    pair<string,int> p1("22",123);
    pair<string,int> p2("33",122);

  //  cout<<p.first<<"         "<<p.second<<endl;

    map<string,int> m;
    m.insert(p);
    m.insert(p1);
    m.insert(p2);
    m.insert(pair<string,int>("kk99",25));

    for(map<string,int>::iterator iter = m.begin();iter!=m.end();iter++)
    {
        cout<<iter->first<<"  "<<iter->second<<endl;
    }
}


2.3 ���� ����ͨ��[]���в���
1.ʾ����
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	//������������ʽ
	m.insert(pair<string, int>("С��",18));
	//ͨ��[]��ʽ
	m["Сǿ"] = 20;

}
2.ʾ����count("С��")������count���Ҹ�key���ֵĴ���������ֵ������0����1 
0��ʾû�и�key��1��ʾ�ж�����������1

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

	map<string, int> m;
	//������������ʽ
	m.insert(pair<string, int>("С��",18));
	cout<<m.count("С��")<<endl;
	cout<<m.count("С��")<<endl;
}

ע�⣺�Ƿ���½�����     
			m["aaa"] = 6;//��
			cout<< m["bbb"]<<endl;//��
			cout<< m.count("bbb")<<endl;// 0  1

3.ʾ����find�����������в��ң�find���ظ�key�ĵ���������

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	
	map<string, int> m;
	//������������ʽ
	m.insert(pair<string, int>("С��",18));
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
	

2.4 ɾ��  ��m��ɾ��keyΪk��Ԫ��   m.erase(k)   



ʾ��2��ɾ��  ��m��ɾ��������pָ����Ԫ��  m.erase(p)  

#include <iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    pair<int,string>p1(2,"pp");
    pair<int,string>p2(5,"tt");

    map<int,string> m;
    m.insert(p1);
    m.insert(p2);

    m[9] = "www";

        for(map<int,string>::iterator iter = m.begin();iter!=m.end();iter++)
        {
            cout<<iter->first<<"  "<<iter->second<<endl;
        }
        cout<<"********************************"<<endl;

        //key delete
        m.erase(9);

        //iterator delete
        map<int,string>::iterator iter =m.find(2);
        if(iter!=m.end())
            m.erase(iter);

        for(map<int,string>::iterator iter = m.begin();iter!=m.end();iter++)
        {
            cout<<iter->first<<"  "<<iter->second<<endl;
        }

//    pair<string,int> p("11",12);
//    pair<string,int> p1("22",123);
//    pair<string,int> p2("33",122);

//    map<string,int> m;
//    m.insert(p);
//    m.insert(p1);
//    m.insert(p2);
//    m.insert(pair<string,int>("kk99",25));
//    m["pp"] = 20;
//    cout<<m["99"]<<endl;

//    for(map<string,int>::iterator iter = m.begin();iter!=m.end();iter++)
//    {
//        cout<<iter->first<<"  "<<iter->second<<endl;
//    }
}



********************�ۺ���ϰ��********************************
 #include <iostream>
#include<vector>
#include<algorithm>

#include<map>

using namespace std;

int main()
{
   //�������� pair
    pair<int,int> p(1,12);
    //��key:first  ֵvalue: second
  //  cout<<p.first<<"  "<<p.second<<endl;

    //����map����

    //�Դ������ܣ��� ��С˳�� ��ֵ������ string�����յ�һ������ȵ��ַ���С  int �ɴ�С
    //���ܲ����ֵ�ظ�������
    map<string,int> m;//vector<int>
    //�������� insert
    m.insert(pair<string,int>("С��",1));
    m.insert(pair<string,int>("b",2));
    m.insert(pair<string,int>("daisy",3));
    m.insert(pair<string,int>("tom",4));
    m.insert(pair<string,int>("jack",4));

    //���� ��ֵ
    m["tom"] = 20;


  //�����Ҫ���ҵļ�ֵ������ ��ô�ͻ��½�һ������ ��ֵ����������ҵļ�ֵ
    m["rose"] = 18;

    //��ѯ�������д��ڼ���������� count:����ֵ 0/1 0:������ 1������
    cout<<m.count("tom111")<<endl;

    //�����ֵtom111 ��Ӧ��value�Ƕ���
    cout<<m["tom111"]<<endl;

    //find()�������� find���ظ�key�ĵ��������� ע�⣺��map�����еĳ�Ա����
    map<string, int>::iterator iter = m.find("С��");
        if(iter != m.end())
        {
            // iter->first :��ֵ   iter->second�� value��ֵ
            cout<<iter->first<<" "<<iter->second<<endl;
        }
        else
        {
            cout<<"���޴���"<<endl;
        }


        //ɾ�� ����key�ķ�ʽ
         m.erase("rose");

        //ɾ�� ���յ�����ɾ��
      map<string,int>::iterator iter1 = m.find("tom");

      if(iter1 != m.end())
             m.erase(iter1);

     //����
      for(map<string,int>::iterator iter = m.begin();iter != m.end();iter++)
      {
          cout<<iter->first<<"  "<<iter->second<<endl;
      }


    return 0;
}

**********************************************************************8

2.5 �Զ���key����  ��Ҫ��������� <

ʾ����
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
    m.insert(pair<Person, int>("jack", 18));//m.insert(pair<Person, int>(Person("jack"), 18));
    m.insert(pair<Person, int>("rose", 1));
    m.insert(pair<Person, int>("tom", 2));
    m.insert(pair<Person, int>("jerry", 3));
    
    for(map<Person, int>::iterator iter = m.begin();iter != m.end();iter++)
    {
        cout<<iter->first.getName()<<" "<<iter->second<<endl;
    }
    
    return 0;
}



�ۺ���ϰ��21��
1��ʹ�õ���ģʽ�����˿��������� PokerManager
	1.˽�г�Աvector,���滨ɫ 
	2.˽�г�Աvector�������   vector<string> point;
	3.˽�г�Աmap�����ֵ map<string,int> score;
	4.������Ӧ��get����
	5.���캯���жԳ�Ա��ֵ
	
2�������˿���Poker ˽������ ��ɫ�����ҵȣ���������A 2 3 J Q�ȣ�����ֵ��21��ÿ�������ķ�ֵ��
	1.���캯�����뻨ɫ�͵�������ɫ������ С����
	2.���캯���и��ݵ����Զ������ֵ���ԣ��ɽ�14�ֵ����Լ���������ֵ����ֵ������ʽ��ŵ�map�� map[point]  score
	
3�����������Judge
	1.˽�г�Ա���������������˳���54����
	2.ϴ�ƣ����ѡȡ����λ�ã�������Ӧλ�õ��ƣ�void shuffle(vector<pocker>& pockersVec);
	3.���к���deal()���ƣ�ÿ����һ�δ��������һ��λ�÷���һ���� pocker deal()�� back(); pop_back();
		
4�����������Player
	1.˽�г�Աvector����������е���
	2.˽�г�Աname
	3.���к������㵱ǰ�����ܷ�ֵ getscore()
	4.���к�����ʾ���е��� show() 
	5.���к���addPoker()����һ��Poker�������vector������
	
5�����߼���Logic
	1.˽�г�ԱJudge����
	2.˽�г�Աvector���Player����
	3.���캯������˽�г�Աvector���Player����
	
	
	4.���к���run()������Ϸ��Ҫ�߼� while()
	4.1 ѯ��ÿ������Ƿ�Ҫ�ƣ�����Ҫ����ʧȥ�Ժ�ѯ�ʻ���
	4.2 Judeg����deal()һ���Ƹ�Ҫ�Ƶ����addPoker()
	4.3 У��Ҫ����ҵķ�ֵ�Ƿ񳬹�21�㣬��������ǰ���֣�ʧȥ�Ժ�ѯ�ʻ���
	4.4 ��ʾ�����������
	4.5	���û�п�ѯ�ʶ�����ֹͣ��Ϸ
	4.6 ѭ����4.1

