#ifndef POKER_H
#define POKER_H
#include<string>
#include "pokermanager.h"
using namespace std;

//һ������
class Poker
{
private:
    string color;
    string point;
    int score;
public:
    //��ͨ����
    Poker(string color, string point);
    //���ִ�С��
    Poker(string color);
    //��� ��ɫ ����
    string toString();
    //��ȡһ���Ƶķ�ֵ
    int getScore();
};

#endif // POKER_H
