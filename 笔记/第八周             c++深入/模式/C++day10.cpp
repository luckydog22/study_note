
一、常用设计模式


高内聚 低耦合 ： 本类中能解决的事  就尽量在本类中来解决，少用一些public的函数
  
开放 - 封闭原则  

		开放：功能以扩展 
		封闭：写好的模块 不易被修改 为了好维护
		
设计模式是优秀的编程思想

程序员有的时候是被自己累死的


1、单例模式——始终唯一

保证了一个类仅有一个实例，并提供了一个访问它的全局访问点

主要解决：一个全局使用的类频繁的创建于销毁

何时使用：想控制实例数目，节省系统资源的时候

关键： 构造函数和拷贝构造私有化

现实实例：两个人用一个账号取钱

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
    static Sun* getInstance();//创建Sun对象的函数  
    int fire();
    void setHot(int hot);
    int getHot();
private:
    Sun();
    Sun(const Sun& other);
	static Sun* instance; //在getInstance函数中完成唯一实例的逻辑，指向唯一的Sun对象
    int hot;
};

#endif // SUN_H


2、工厂模式——暗箱操作

为了创建对象，隐藏一些创建过程，


抽象工厂：返回值都是food基类，都是吃的，具体是啥咱也不知道

现实实例：小伙卖烤冷面： 小伙就相当于工厂


3、代理模式——以不变应万变

功能的扩张，
书写特点：一个类是另一个类的成员变量


现实实例：老王的家装修，安装净水器 

			通过抢票软件买回家的火车票
			
			

4、观察者模式——解耦合终极大法

解耦的，降低耦合性的作用


现实实例：家里网断了，你找到客服，这个客服就担当了观察者的身份，

			客服去给维修报修，维修的去处理。



