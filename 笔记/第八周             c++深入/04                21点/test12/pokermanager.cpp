#include "pokermanager.h"
#include<cstdio>
PokerManager* PokerManager::instance = NULL;

PokerManager::PokerManager(const PokerManager &o)
{

}

PokerManager::~PokerManager()
{


}

vector<string> &PokerManager::getColors()
{
    return colors;
}

vector<string> &PokerManager::getPoints()
{
    return points;
}

map<string, int> &PokerManager::getScores()
{
    return scores;
}

PokerManager::PokerManager()
{

    //∏≥≥ı÷µ
    colors.push_back("∫ÏÃ“");
    colors.push_back("∫⁄Ã“");
    colors.push_back("∑Ω∆¨");
    colors.push_back("≤›ª®");
    points.push_back("A");
    points.push_back("2");
    points.push_back("3");
    points.push_back("4");
    points.push_back("5");
    points.push_back("6");
    points.push_back("7");
    points.push_back("8");
    points.push_back("9");
    points.push_back("10");
    points.push_back("J");
    points.push_back("Q");
    points.push_back("K");
    scores["A"] = 1;
    scores["2"] = 2;
    scores["3"] = 3;
    scores["4"] = 4;
    scores["5"] = 5;
    scores["6"] = 6;
    scores["7"] = 7;
    scores["8"] = 8;
    scores["9"] = 9;
    scores["10"] = 10;
    scores["J"] = 1;
    scores["Q"] = 1;
    scores["K"] = 1;
    scores[""] = 1;

}

PokerManager* PokerManager::getInstance()
{
    if(instance == NULL)
    {
        instance = new PokerManager;
    }
    return instance;
}

