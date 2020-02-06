#include "player.h"
#include<iostream>

using namespace std;

Player::Player(string name):name(name)
{

    want = true;

}


//显示手中所有的牌
void Player::show()
{
    cout<<name<<" ";
    for(vector<Poker>::iterator iter = players.begin();iter != players.end(); iter++)
    {
        cout<< iter->toString()<<" ";
    }
    cout<<endl;

}

//将裁判发给的牌 保存到自己的容器中
void Player::addPoker(Poker p)
{
    players.push_back(p);
}

 //计算手中牌的总分值，用来和21进行比较用的
int Player::getScores()
{
    int sum = 0;
    for(int i = 0 ; i < players.size(); i++)
        sum+=players[i].getScore();
    return sum;
}

Player::~Player()
{

}

