#ifndef POKER_H
#define POKER_H
#include<string>
#include "pokermanager.h"
using namespace std;

//一张牌类
class Poker
{
private:
    string color;
    string point;
    int score;
public:
    //普通的牌
    Poker(string color, string point);
    //区分大小王
    Poker(string color);
    //输出 花色 点数
    string toString();
    //获取一张牌的分值
    int getScore();
};

#endif // POKER_H
