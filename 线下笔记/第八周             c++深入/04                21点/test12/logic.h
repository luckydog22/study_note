#ifndef LOGIC_H
#define LOGIC_H
#include "judge.h"
#include "player.h"
#include <vector>
using namespace std;


class Logic
{

 private:
    Judge judge;
    //保存玩家的容器
    vector<Player> playVec;


public:
    Logic();

    void run();

    //循环询问玩家 是否要牌
    void ask();

    //校验
    void check();

    //显示所有玩家 手中的牌
    void show();

    //游戏结束的条件
    bool isStop();

    //谁是赢家
    void winner();



    ~Logic();
};

#endif // LOGIC_H
