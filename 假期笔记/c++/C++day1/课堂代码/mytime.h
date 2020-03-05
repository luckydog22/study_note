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
    void go();//时间进行1秒
    void show();//显示时间
};

#endif // MYTIME_H
