
һ���������ģʽ


���ھ� ����� �� �������ܽ������  �;����ڱ����������������һЩpublic�ĺ���
  
���� - ���ԭ��  

		���ţ���������չ 
		��գ�д�õ�ģ�� ���ױ��޸� Ϊ�˺�ά��
		
���ģʽ������ı��˼��

����Ա�е�ʱ���Ǳ��Լ�������


1������ģʽ����ʼ��Ψһ

��֤��һ�������һ��ʵ�������ṩ��һ����������ȫ�ַ��ʵ�

��Ҫ�����һ��ȫ��ʹ�õ���Ƶ���Ĵ���������

��ʱʹ�ã������ʵ����Ŀ����ʡϵͳ��Դ��ʱ��

�ؼ��� ���캯���Ϳ�������˽�л�

��ʵʵ������������һ���˺�ȡǮ

main.cpp

int main()
{
    Sun* s1=Sun::getInstance();
    Sun* s2=Sun::getInstance();
    Sun* s3=Sun::getInstance();
    s1->setHot(28);

    s2->fire();
    s3->fire();
    cout<<s3->getHot()<<endl;

    return 0;
}
---------------------------------
sun.cpp

#include "sun.h"

#include <cstdio>

Sun* Sun::instance = NULL;

Sun *Sun::getInstance()
{
    if(instance == NULL)
    {
        instance = new Sun();
        return instance;

    }
    return instance;
}

int Sun::fire()
{
    hot++;
}

void Sun::setHot(int hot)
{
    this->hot = hot;
}

int Sun::getHot()
{
    return hot;
}

Sun::Sun()
{

}

Sun::Sun(const Sun &other)
{

}

--------------------------------
sun.h

#ifndef SUN_H
#define SUN_H


class Sun
{
public:
    static Sun* getInstance();//����Sun����ĺ���  
    int fire();
    void setHot(int hot);
    int getHot();
private:
    Sun();
    Sun(const Sun& other);
	static Sun* instance; //��getInstance���������Ψһʵ�����߼���ָ��Ψһ��Sun����
    int hot;
};

#endif // SUN_H


2������ģʽ�����������

Ϊ�˴�����������һЩ�������̣�


���󹤳�������ֵ����food���࣬���ǳԵģ�������ɶ��Ҳ��֪��

��ʵʵ����С���������棺 С����൱�ڹ���


3������ģʽ�����Բ���Ӧ���

���ܵ����ţ�
��д�ص㣺һ��������һ����ĳ�Ա����


��ʵʵ���������ļ�װ�ޣ���װ��ˮ�� 

			ͨ����Ʊ�����ؼҵĻ�Ʊ
			
			

4���۲���ģʽ����������ռ���

����ģ���������Ե�����


��ʵʵ�������������ˣ����ҵ��ͷ�������ͷ��͵����˹۲��ߵ���ݣ�

			�ͷ�ȥ��ά�ޱ��ޣ�ά�޵�ȥ����



