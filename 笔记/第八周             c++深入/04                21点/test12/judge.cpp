#include "judge.h"
#include "pokermanager.h"
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Judge::Judge()
{
    //初始化随机种子
    srand(time(0));

    //生成一副牌 花色的容器 点数的容器
    vector<string> colors = PokerManager::getInstance()->getColors();
    vector<string> points = PokerManager::getInstance()->getPoints();

    for(int i = 0 ; i < colors.size(); i++)
    {
        for(int j = 0 ; j < points.size(); j++)
        {
            pokerVec.push_back(Poker(colors[i],points[j]));
        }
    }
    pokerVec.push_back(Poker("大王"));
    pokerVec.push_back(Poker("小王"));

    for(int i = 0 ; i < pokerVec.size(); i++)
        cout<<pokerVec[i].toString()<<" ";
    cout<<endl;

    //洗牌
    shuffle(pokerVec);
}

Judge::~Judge()
{

}
//洗牌函数 随机抽取两个位置 并交换 循环五十次
 void Judge::shuffle(vector<Poker>& pokerVec)
 {
     for(int i = 0 ; i < 50; i++)
     {
        int a = rand()%pokerVec.size();
        int b = rand()%pokerVec.size();
        Poker  temp = pokerVec[a];
        pokerVec[a] = pokerVec[b];
        pokerVec[b] = temp;
     }
     for(int i = 0 ; i < pokerVec.size(); i++)
         cout<<pokerVec[i].toString()<<" ";
     cout<<endl;



 }
 //发牌函数 返回容器中的最后一张牌
 Poker Judge::deal()
 {
       //获取到最后一张，返回
    Poker p =pokerVec.back();
     //把这张牌从容器中移除
    pokerVec.pop_back();
        return p;
 }

