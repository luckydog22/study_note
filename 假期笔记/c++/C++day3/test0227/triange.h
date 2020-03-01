#ifndef TRIANGE_H
#define TRIANGE_H


class Triange
{
private:
    int a;
    int b;
    int c;
public:
    Triange(int a, int b, int c);
    int operator+(const Triange& other);
};

#endif // TRIANGE_H
