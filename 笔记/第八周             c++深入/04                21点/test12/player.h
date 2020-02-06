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
    //������з��Ƶ�����
    vector<Poker> players;
    bool want;
public:
    Player(string name);

    //�������������ܼܺ򵥣���ֵ����ȡֵ�� �����������뵽���������ʱ�򣬾͵�չ��
    inline string getName(){return name;}
    inline void setWant(bool want){this->want = want;}
    inline bool getWant(){return want;}

    //��ʾ�������е���
    void show();

    //�����з������� ���浽�Լ���������
    void addPoker(Poker p);

    //���������Ƶ��ܷ�ֵ��������21���бȽ��õ�
    int getScores();

    ~Player();
};

#endif // PLAYER_H
