#include "player.h"
#include<iostream>

using namespace std;

Player::Player(string name):name(name)
{

    want = true;

}


//��ʾ�������е���
void Player::show()
{
    cout<<name<<" ";
    for(vector<Poker>::iterator iter = players.begin();iter != players.end(); iter++)
    {
        cout<< iter->toString()<<" ";
    }
    cout<<endl;

}

//�����з������� ���浽�Լ���������
void Player::addPoker(Poker p)
{
    players.push_back(p);
}

 //���������Ƶ��ܷ�ֵ��������21���бȽ��õ�
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

