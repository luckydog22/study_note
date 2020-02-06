#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<vector>
#include "poker.h"
using namespace std;

class Player
{
private:
    string name;
    //玩家手中放牌的容器
    vector<Poker> players;
    bool want;
public:
    Player(string name);

    //内联函数：功能很简单（赋值或者取值） 当编译器编译到这个函数的时候，就地展开
    inline string getName(){return name;}
    inline void setWant(bool want){this->want = want;}
    inline bool getWant(){return want;}

    //显示手中所有的牌
    void show();

    //将裁判发给的牌 保存到自己的容器中
    void addPoker(Poker p);

    //计算手中牌的总分值，用来和21进行比较用的
    int getScores();

    ~Player();
};

#endif // PLAYER_H
