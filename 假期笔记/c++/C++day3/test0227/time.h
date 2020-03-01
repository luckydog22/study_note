#ifndef TIME_H
#define TIME_H


class Time
{
private:
    int h;
    int m;
    int s;
public:
    Time(int h, int m, int s);
    Time operator++(int a);
    void show();
};

#endif // TIME_H
