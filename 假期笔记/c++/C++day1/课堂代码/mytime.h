#ifndef MYTIME_H
#define MYTIME_H


class MyTime
{
private:
    int h;
    int m;
    int s;
public:
    MyTime(int h, int m, int s);
    void go();//ʱ�����1��
    void show();//��ʾʱ��
};

#endif // MYTIME_H
