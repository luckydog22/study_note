#ifndef MYARR_H
#define MYARR_H


class MyArr
{
private:
    int* arr;//ָ��̬����������
    int arrLen;//��̬����ĳ���
public:
    void input(int* src, int len);
    int max();
    int min();
    int agv();
    ~MyArr();
};

#endif // MYARR_H
