#include "poker.h"

Poker::Poker(string color, string point):color(color),point(point)
{
    //��һ���ƶ�Ӧ�ķ�ֵPokerManager::getInstance()->getScores() -->map����
    //m[["point"] -->valueֵ
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



