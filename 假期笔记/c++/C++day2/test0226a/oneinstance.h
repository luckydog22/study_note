#ifndef ONEINSTANCE_H
#define ONEINSTANCE_H


class OneInstance
{
public:
    static OneInstance* getInstance();//静态成员函数来实例化唯一一个对象
    static void releaceInstance();//释放对象
private:
    OneInstance();//私有化构造函数和拷贝构造函数的目的是不让类的外部实例化对象
    OneInstance(const OneInstance& other);
    static OneInstance* instance;//协助静态成员函数完成实例化唯一一个对象的逻辑
};

#endif // ONEINSTANCE_H
