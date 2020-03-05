#ifndef MYARR_H
#define MYARR_H


class MyArr
{
private:
    int* arr;//指向动态创建的数组
    int arrLen;//动态数组的长度
public:
    void input(int* src, int len);
    int max();
    int min();
    int agv();
    ~MyArr();
};

#endif // MYARR_H
