#include "poker.h"

Poker::Poker(string color, string point):color(color),point(point)
{
    //找一张牌对应的分值PokerManager::getInstance()->getScores() -->map容器
    //m[["point"] -->value值
   score = PokerManager::getInstance()->getScores()[point];
}

Poker::Poker(string color):color(color),point("")
{
     score = PokerManager::getInstance()->getScores()[point];
}

string Poker::toString()
{
    return color+point;
}

int Poker::getScore()
{
    return score;
}



