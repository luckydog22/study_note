#ifndef ONEINSTANCE_H
#define ONEINSTANCE_H


class OneInstance
{
public:
    static OneInstance* getInstance();//��̬��Ա������ʵ����Ψһһ������
    static void releaceInstance();//�ͷŶ���
private:
    OneInstance();//˽�л����캯���Ϳ������캯����Ŀ���ǲ�������ⲿʵ��������
    OneInstance(const OneInstance& other);
    static OneInstance* instance;//Э����̬��Ա�������ʵ����Ψһһ��������߼�
};

#endif // ONEINSTANCE_H
